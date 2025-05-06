#include "Graph.h"

using namespace std;

Node* get_node(Graph*& graph, string location) {
    unsigned int cur_hash_id = djb2(location);
    for (Node* x : graph->nodes) {
        if (x->hash_id == cur_hash_id) {
            return x;
        }
    }
    return NULL;
}

Edge* get_edge(Graph*& graph, string start_location, string end_location) {
    unsigned int start_hash_id = djb2(start_location);
    unsigned int end_hash_id = djb2(end_location);
    for (Node* x : graph->nodes) {
        if (x->hash_id == start_hash_id) {
            for (Edge* y : x->edges) {
                if (y->end_node->hash_id == end_hash_id) {
                    return y;
                }
            }
        }
    }
    return NULL;
}

void reset_time(Edge*& edge, double time) {
    edge->time = time;
}

void reset_cost(Edge*& edge, double cost) {
    edge->cost = cost;
}

Node* add_node(Graph*& graph, string location) {
    Node* cur_node = get_node(graph, location);
    if (cur_node == NULL) {
        Node* new_node = create_node(location);
        graph->nodes.insert(new_node);
        return new_node;
    }
    return cur_node;
}

bool remove_node(Graph*& graph, string location) {
    Node* cur_node = get_node(graph, location);
    if (cur_node != NULL) {
        // Remove all incoming edges
        for (Node* x : graph->nodes) {
            for (auto it = x->edges.begin(); it != x->edges.end(); ) {
                Edge* cur_edge = *it;
                if (cur_edge->end_node->location == location) {
                    it = x->edges.erase(it);
                    delete cur_edge;
                }
                else {
                    ++it;
                }
            }
        }
        // Remove the Node and all outgoing edges
        graph->nodes.erase(cur_node);
        delete cur_node;
        return true;
    }
    return false;
}

Edge* add_edge(Graph*& graph, string start_location, string end_location, double time, double cost) {
    Edge* cur_edge = get_edge(graph, start_location, end_location);
    if (cur_edge == NULL) {
        Node* start_node = add_node(graph, start_location);
        Node* end_node = add_node(graph, end_location);
        Edge* new_edge = create_edge(start_node, end_node, time, cost);
        start_node->edges.insert(new_edge);
        return new_edge;
    }
    else {
        cur_edge->time = time;
        cur_edge->cost = cost;
        return cur_edge;
    }
}

bool remove_edge(Graph*& graph, string start_location, string end_location) {
    Edge* cur_edge = get_edge(graph, start_location, end_location);
    if (cur_edge != NULL) {
        cur_edge->start_node->edges.erase(cur_edge);
        delete cur_edge;
        return true;
    }
    return false;
}

void print_graph(Graph*& graph) {
    for (Node* x : graph->nodes) {
        cout << "location: " << x->location << endl;
        cout << "hash_id: " << x->hash_id << endl;
        cout << "distance: " << x->distance << endl;
        string pre_location = x->predecessor != NULL ? x->predecessor->location : "NULL";
        cout << "predecessor: " << pre_location << endl;
        cout << "visited: " << x->visited << endl;
        for (Edge* y : x->edges) {
            cout << "edge: from " << y->start_node->location << " to " << y->end_node->location << " with ";
            cout << "time (" << y->time << ") and cost (" << y->cost << ")" << endl;
        }
    }
}

void Dijkstra_shortest_time(Graph*& graph, string start_location) {
    Node* start_node = get_node(graph, start_location);
    if (start_node == NULL) {
        return;
    }
    pqueue* queue = create_pqueue();
    for (Node* x : graph->nodes) {
        x->distance = INFINITY;
        x->predecessor = NULL;
        x->visited = false;
        enqueue_node(queue, x);
    }
    start_node->distance = 0;
    reorder_node(queue, start_node);
    while (queue->size > 0) {
        Node* cur_node = dequeue_node(queue);
        cur_node->visited = true;
        for (Edge* y : cur_node->edges) {
            double new_distance = cur_node->distance + y->time;
            if (new_distance < y->end_node->distance) {
                y->end_node->distance = new_distance;
                if (!y->end_node->visited) {
                    reorder_node(queue, y->end_node);
                }
                y->end_node->predecessor = cur_node;
            }
        }
    }
}

void Dijkstra_lowest_cost(Graph*& graph, string start_location) {
    Node* start_node = get_node(graph, start_location);
    if (start_node == NULL) {
        return;
    }
    pqueue* queue = create_pqueue();
    for (Node* x : graph->nodes) {
        x->distance = INFINITY;
        x->predecessor = NULL;
        x->visited = false;
        enqueue_node(queue, x);
    }
    start_node->distance = 0;
    reorder_node(queue, start_node);
    while (queue->size > 0) {
        Node* cur_node = dequeue_node(queue);
        cur_node->visited = true;
        for (Edge* y : cur_node->edges) {
            double new_distance = cur_node->distance + y->cost;
            if (new_distance < y->end_node->distance) {
                y->end_node->distance = new_distance;
                if (!y->end_node->visited) {
                    reorder_node(queue, y->end_node);
                }
                y->end_node->predecessor = cur_node;
            }
        }
    }
}

string find_shortest_time(Graph*& graph, string start_location, string end_location) {
    Dijkstra_shortest_time(graph, start_location);
    Node* end_node = get_node(graph, end_location);
    string ret = "";
    if (end_node->predecessor == NULL) {
        ret = "There is no path from " + start_location + " to " + end_location + ".";
    }
    else {
        ret = end_location;
        Node* cur_node = end_node;
        while (cur_node->location != start_location) {
            ret = cur_node->predecessor->location + " -> " + ret;
            cur_node = cur_node->predecessor;
        }
        ret = "The path with the shortest time is " + ret + " with time being " + to_string(end_node->distance) + ".";
    }
    return ret;
}

string find_lowest_cost(Graph*& graph, string start_location, string end_location) {
    Dijkstra_lowest_cost(graph, start_location);
    Node* end_node = get_node(graph, end_location);
    string ret = "";
    if (end_node->predecessor == NULL) {
        ret = "There is no path from " + start_location + " to " + end_location + ".";
    }
    else {
        ret = end_location;
        Node* cur_node = end_node;
        while (cur_node->location != start_location) {
            ret = cur_node->predecessor->location + " -> " + ret;
            cur_node = cur_node->predecessor;
        }
        ret = "The path with the lowest cost is " + ret + " with cost being " + to_string(end_node->distance) + ".";
    }
    return ret;
}