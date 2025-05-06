#ifndef PRIORITYQUEUE_H__
#define PRIORITYQUEUE_H__

#include <memory>
#include <string>
#include <unordered_set>
#include <cmath>

using namespace std;

#define INITIAL_CAPACITY 100

struct Edge;   // Forward declaration

struct Node {
    string location;   // Airport/railway station + A (for arrival)
                       // Airport/railway station + D (for departure)
    unsigned int hash_id;   // Hash code used as an identifier
    double distance;   // Tracking a vertex's distance for Dijkstra's algorithm
    Node* predecessor;   // Tracking a vertex's predecessor for Dijkstra's algorithm
    bool visited;   // Check if a vertex is visited for Dijkstra's algorithm
    unordered_set<Edge*> edges;   // An unordered set of all outgoing Edges
    bool operator==(const Node& other) const {
        return hash_id == other.hash_id;
    }
};

// All edges are directed and weighted
struct Edge {
    Node* start_node;
    Node* end_node;
    double time;   // Travel time
    double cost;   // Travel cost
    bool operator==(const Edge& other) const {
        return start_node->hash_id == other.start_node->hash_id && end_node->hash_id == other.end_node->hash_id;
    }
};

struct pqueue {
    Node* heap_array [INITIAL_CAPACITY];
    int size;
    int capacity;
};

// djb2 is used to create a hash code, hash_id, for each node.
unsigned int djb2(string key);

// create_node initializes a Node with the given location data.
// distance is set to infinity, and predecessor is set to NULL.
Node* create_node(string location);

// create_edge initializes an Edge with time and cost set to zero.
Edge* create_edge(Node* start_node, Node* end_node);

// create_edge also initializes an Edge with the given time and cost data.
// Function overloading
Edge* create_edge(Node* start_node, Node* end_node, double time, double cost);

// create_pqueue initializes a priority queue of Nodes with a heap array of capacity 100.
pqueue* create_pqueue();

// enqueue_node inserts the Node to the queue with its distance as the priority value.
void enqueue_node(pqueue*& queue, Node* node);

// dequeue_node removes the first Node with the shortest distance from the queue.
Node* dequeue_node(pqueue*& queue);

// reorder_node percolates the Node up to the proper position in the min-heap 
// after its distance/priority being replaced with a smaller value.
void reorder_node(pqueue*& queue, Node* node);

#endif