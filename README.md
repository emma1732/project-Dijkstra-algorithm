# Travel Planning with Graph and Dijkstra's Algorithm
## What the project does
The project is developed to find the path with the shortest travel time and/or the lowest travel cost during travel planning using Dijkstra's shortest path algorithm.
## How the project is implemented
### Graph implementation with adjacency sets
The graph data structure is implemented with three structures, including Node, Edge, and Graph. The only member of the Graph structure is an unordered_set of Nodes. Each Node keeps an unordered_set of outgoing Edges. Considering the application of this project, all Edges are directed and weighted. The Edge structure has two members, time and cost, for two types of edge weights. The reasons for choosing unorder_sets as containers to store Nodes and Edges include fast insertion/deletion and duplicate removal. To ensure that all Nodes in a Graph are unique, a hash code computed by the djb2() hash function is assigned to each Node's hash_id member. The hash_id prevents duplicate Nodes or Edges from adding to the unorder_set. One way to add a layover to the graph is to create an Edge with location+A (A for arrival) as the start_node and location+D (D for departure) as the end_node. The cost of a layover Edge can be zero or any extra spending on things like food. Below are the Node, Edge, and Graph structures.
```
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
```
```
struct Edge {
    Node* start_node;
    Node* end_node;
    double time;   // Travel time
    double cost;   // Travel cost
    bool operator==(const Edge& other) const {
        return start_node->hash_id == other.start_node->hash_id && end_node->hash_id == other.end_node->hash_id;
    }
};
```
```
struct Graph {
    unordered_set<Node*> nodes;   // An unordered set of all the Nodes
};
```
### Dijkstra's algorithm implementation with min-heap
## How the project is tested
## How the project is used
