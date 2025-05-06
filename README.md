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
To implement Dijkstra's shortest path algorithm, three members, including distance, predecessor, and visited, are added to the Node structure. Besides keeping track of a Node's distance and predecessor, a priority queue is needed to find the Node with the smallest distance in each iteration. After learning that the priority_queue provided in C++ would not let a Node be reprioritized after a change in its distance/priority, I decided to build a min-heap to support the implementation of Dijkstra's algorithm. One of the most important functions of this min-heap is reorder_node(), which percolates a Node up to the proper position in the min-heap. Since a Node's distance can only be replaced with a smaller value in Dijkstra's algorithm, I do not need to take percolating a Node down with a larger distance/priority into consideration. Therefore, the min-heap implemented in this project is customized to meet the needs of Dijkstra's algorithm only. Below is the reorder_node() function.
```
// reorder_node percolates the Node up to the proper position in the min-heap 
// after its distance/priority is replaced with a smaller value.
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
```
## How the project is tested
To ensure my program is running properly, I used four tests. All four graphs used in the tests can be found in the tests folder. The first three graphs are from the zyBooks section 16.9. The distance and predecessor data of each Node after running Dijkstra's algorithm are provided in these graphs, which can be compared against the data output by the print_graph() function. The fourth graph is self-designed based on some information crudely gathered online. It is included to show how the project works. Each test has a .cpp file in the tests folder which can be compiled with g++ -o <target_name> <file_name> and run with ./<target_name>.
## How the project is used
To build a graph, use the add_edge() function.
To find the fastest path, use the find_shortest_time() function.
To find the cheapest path, use the find_lowest cost() function.
Below are their function declarations.
```
// add_edge returns a new Edge created and added to the graph 
// if no Edge with the given start and end locations exists.
// Otherwise, it returns the existing Edge with its time and cost data updated.
Edge* add_edge(Graph*& graph, string start_location, string end_location, double time, double cost);

// find_shortest_time returns the path with the shortest travel time 
// from the start location to the end location if it exists.
// Otherwise, it returns there is no path from the start location to the end location.
string find_shortest_time(Graph*& graph, string start_location, string end_location);

// find_lowest_cost returns the path with the lowest travel cost 
// from the start location to the end location if it exists.
// Otherwise, it returns there is no path from the start location to the end location.
string find_lowest_cost(Graph*& graph, string start_location, string end_location);
```