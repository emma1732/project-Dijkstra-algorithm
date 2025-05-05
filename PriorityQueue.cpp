#include "PriorityQueue.h"

using namespace std;

unsigned int djb2(string key) {
    unsigned int hash = 5381;
    for (size_t i = 0; i < key.length(); i++) {
        char c = key[i];
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}

Node* create_node(string location) {
    Node* new_node = new Node;
    new_node->location = location;
    new_node->hash_id = djb2(location);
    new_node->distance = INFINITY;
    new_node->predecessor = NULL;
    new_node->visited = false;
    return new_node;
}

Edge* create_edge(Node* start_node, Node* end_node) {
    Edge* new_edge = new Edge;
    new_edge->start_node = start_node;
    new_edge->end_node = end_node;
    new_edge->time = 0;
    new_edge->cost = 0;
    return new_edge;
}

Edge* create_edge(Node* start_node, Node* end_node, double time, double cost) {
    Edge* new_edge = new Edge;
    new_edge->start_node = start_node;
    new_edge->end_node = end_node;
    new_edge->time = time;
    new_edge->cost = cost;
    return new_edge;
}

pqueue* create_pqueue() {
    pqueue* new_queue = new pqueue;
    new_queue->size = 0;
    new_queue->capacity = INITIAL_CAPACITY;
    return new_queue;
}

void enqueue_node(pqueue*& queue, Node* node) {
    queue->heap_array[queue->size] = node;
    queue->size++;
    int node_index = queue->size - 1;
    while (node_index > 0) {
        int parent_index = (node_index - 1) / 2;
        if (queue->heap_array[node_index]->distance >= queue->heap_array[parent_index]->distance) {
            return;
        }
        Node* temp = queue->heap_array[parent_index];
        queue->heap_array[parent_index] = queue->heap_array[node_index];
        queue->heap_array[node_index] = temp;
        node_index = parent_index;
    }
}

Node* dequeue_node(pqueue*& queue) {
    if (queue->size == 0) {
        return NULL;
    }
    Node* ret = queue->heap_array[0];
    queue->heap_array[0] = queue->heap_array[queue->size-1];
    queue->size--;
    int node_index = 0;
    int child_index = node_index * 2 + 1;
    while (child_index < queue->size) {
        double min_distance = queue->heap_array[node_index]->distance;
        int min_index = node_index;
        for (int i = 0; i < 2 && i+child_index < queue->size; i++) {
            if (queue->heap_array[i+child_index]->distance < min_distance) {
                min_distance = queue->heap_array[i+child_index]->distance;
                min_index = i+child_index;
            }
        }
        if (min_index == node_index) {
            break;
        }
        Node* temp = queue->heap_array[node_index];
        queue->heap_array[node_index] = queue->heap_array[min_index];
        queue->heap_array[min_index] = temp;
        node_index = min_index;
        child_index = node_index * 2 + 1;
    }
    return ret;
}

void reorder_node(pqueue*& queue, Node* node) {
    int node_index = -1;
    for (int i = 0; i < queue->size; i++) {
        if (queue->heap_array[i] == node) {
            node_index = i;
            break;
        }
    }
    while (node_index > 0) {
        int parent_index = (node_index - 1) / 2;
        if (queue->heap_array[node_index]->distance >= queue->heap_array[parent_index]->distance) {
            return;
        }
        Node* temp = queue->heap_array[parent_index];
        queue->heap_array[parent_index] = queue->heap_array[node_index];
        queue->heap_array[node_index] = temp;
        node_index = parent_index;
    }
}