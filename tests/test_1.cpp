#include "../code/Graph.cpp"

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
    
    // Test remove_node and remove_edge
    bool remove_D = remove_node(test_1, "D");
    if (remove_D) {
        cout << "Node D has been removed successfully." << endl;
    }
    bool remove_A_to_C = remove_edge(test_1, "A", "C");
    if (remove_A_to_C) {
        cout << "Edge A_to_C has been removed successfully." << endl;
    }

    cout << "*** Test remove_node and remove_edge ***" << endl;
    print_graph(test_1);
    
    return 0;
}