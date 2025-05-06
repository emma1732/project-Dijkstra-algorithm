#ifndef GRAPH_H__
#define GRAPH_H__

#include <memory>
#include <iostream>
#include "PriorityQueue.cpp"

using namespace std;

struct Graph {
    unordered_set<Node*> nodes;   // An unordered set of all the Nodes
};

// get_node finds the Node given the location in the unordered set of Nodes.
// Return NULL if not found.
Node* get_node(Graph*& graph, string location);

// get_edge finds the Edge given the start and end locations in the graph.
// Return NULL if not found.
Edge* get_edge(Graph*& graph, string start_location, string end_location);

// reset_time changes the time data of an Edge.
void reset_time(Edge*& edge, double time);

// reset_cost changes the cost data of an Edge.
void reset_cost(Edge*& edge, double cost);

// add_node returns a new Node created and added to the graph 
// if no Node with the given location exists.
// Otherwise, it returns the existing Node with the given location.
Node* add_node(Graph*& graph, string location);

// remove_node removes the Node with the given location and all its outgoing and incoming edges.
// Return false if the Node with the given location does not exist in the graph.
bool remove_node(Graph*& graph, string location);

// add_edge returns a new Edge created and added to the graph 
// if no Edge with the given start and end locations exists.
// Otherwise, it returns the existing Edge with its time and cost data updated.
Edge* add_edge(Graph*& graph, string start_location, string end_location, double time, double cost);

// remove_edge removes the Edge with the given start and end locations 
// from its start_node's unordered set of edges.
// Return false if the Edge with the given start and end locations does not exist in the graph.
bool remove_edge(Graph*& graph, string start_location, string end_location);

// print_graph outputs data of each Node and its outgoing edges.
void print_graph(Graph*& graph);

// Dijkstra_shortest_time finds the path with the shortest travel time 
// from the start location to all other locations in the graph.
void Dijkstra_shortest_time(Graph*& graph, string start_location);

// Dijkstra_lowest_cost finds the path with the lowest travel cost 
// from the start location to all other locations in the graph.
void Dijkstra_lowest_cost(Graph*& graph, string start_location);

// find_shortest_time returns the path with the shortest travel time 
// from the start location to the end location if it exists.
// Otherwise, it returns there is no path from the start location to the end location.
string find_shortest_time(Graph*& graph, string start_location, string end_location);

// find_lowest_cost returns the path with the lowest travel cost 
// from the start location to the end location if it exists.
// Otherwise, it returns there is no path from the start location to the end location.
string find_lowest_cost(Graph*& graph, string start_location, string end_location);

#endif