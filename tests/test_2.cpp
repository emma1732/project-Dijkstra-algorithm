#include "../code/Graph.cpp"

using namespace std;

int main() {
    
    Graph* test_2 = new Graph;
    
    Edge* E_to_F = add_edge(test_2, "E", "F", 0, 4);
    Edge* E_to_H = add_edge(test_2, "E", "H", 0, 1);
    Edge* F_to_G = add_edge(test_2, "F", "G", 0, 11);
    Edge* F_to_J = add_edge(test_2, "F", "J", 0, 3);
    Edge* G_to_K = add_edge(test_2, "G", "K", 0, 5);
    Edge* H_to_F = add_edge(test_2, "H", "F", 0, 2);
    Edge* J_to_G = add_edge(test_2, "J", "G", 0, 7);
    Edge* J_to_K = add_edge(test_2, "J", "K", 0, 14);
    Edge* K_to_J = add_edge(test_2, "K", "J", 0, 8);
    
    // Test Dijkstra_lowest_cost with start location E
    Dijkstra_lowest_cost(test_2, "E");

    cout << "*** Test Dijkstra_lowest_cost with start location E ***" << endl;
    print_graph(test_2);
    
    return 0;
}