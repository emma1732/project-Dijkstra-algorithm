#include "Graph.cpp"

using namespace std;

int main() {

    Graph* test_1 = new Graph;
    
    Edge* A_to_B = add_edge(test_1, "A", "B", 7, 0);
    Edge* A_to_C = add_edge(test_1, "A", "C", 2, 0);
    Edge* B_to_C = add_edge(test_1, "B", "C", 9, 0);
    Edge* C_to_B = add_edge(test_1, "C", "B", 4, 0);
    Edge* C_to_D = add_edge(test_1, "C", "D", 1, 0);
    Edge* D_to_B = add_edge(test_1, "D", "B", 5, 0);
    
    // Test Dijkstra_shortest_time with start location A
    Dijkstra_shortest_time(test_1, "A");

    cout << "*** Test Dijkstra_shortest_time with start location A ***" << endl;
    print_graph(test_1);
    
    return 0;
}