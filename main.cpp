#include "Graph.cpp"

using namespace std;

int main() {
/*
    Graph* test_1 = new Graph;

    // Test add_node and add_edge
    Node* A = add_node(test_1, "A");
    Node* B = add_node(test_1, "B");
    Node* C = add_node(test_1, "C");
    Node* D = add_node(test_1, "D");
    Node* D_duplicate = add_node(test_1, "D");   // Duplicates are not allowed

    Edge* A_to_B = add_edge(test_1, "A", "B", 7, 0);
    Edge* A_to_C = add_edge(test_1, "A", "C", 2, 0);
    Edge* B_to_C = add_edge(test_1, "B", "C", 9, 0);
    Edge* C_to_B = add_edge(test_1, "C", "B", 4, 0);
    Edge* C_to_D = add_edge(test_1, "C", "D", 1, 0);
    Edge* D_to_B = add_edge(test_1, "D", "B", 5, 0);
    Edge* D_to_B_duplicate = add_edge(test_1, "D", "B", 5, 0);   // Duplicates are not allowed

    cout << "*** Test add_node and add_edge ***" << endl;
    print_graph(test_1);

    // Test reset_time and reset_cost
    reset_time(A_to_B, 12);
    reset_cost(A_to_B, 17);

    cout << "*** Test reset_time and reset_cost ***" << endl;
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
    
    // Test Dijkstra_shortest_time with start location A
    Dijkstra_shortest_time(test_1, "A");

    cout << "*** Test Dijkstra_shortest_time with start location A ***" << endl;
    print_graph(test_1);

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

    Graph* test_3 = new Graph;

    Edge* L_to_M = add_edge(test_3, "L", "M", 9, 9);
    Edge* L_to_Q = add_edge(test_3, "L", "Q", 3, 3);
    Edge* N_to_L = add_edge(test_3, "N", "L", 2, 2);
    Edge* Q_to_M = add_edge(test_3, "Q", "M", 1, 1);
    Edge* P_to_M = add_edge(test_3, "P", "M", 15, 15);
    Edge* P_to_Q = add_edge(test_3, "P", "Q", 7, 7);
    
    // Test find_shortest_time with start location N and end location M
    cout << "*** Test find_shortest_time with start location N and end location M ***" << endl;
    cout << find_shortest_time(test_3, "N", "M") << endl;

    // Test find_lowest_cost with start location N and end location P
    cout << "*** Test find_lowest_cost with start location N and end location P ***" << endl;
    cout << find_lowest_cost(test_3, "N", "P") << endl;
*/
    Graph* test_4 = new Graph;

    Edge* GR_to_SE = add_edge(test_4, "Grand Rapids", "Seattle", 7.5, 176);
    Edge* GR_to_DE = add_edge(test_4, "Grand Rapids", "Detroit", 1, 149);
    Edge* GR_to_LA = add_edge(test_4, "Grand Rapids", "Los Angeles", 6.5, 176);
    Edge* SE_to_SH = add_edge(test_4, "Seattle", "Shanghai", 13, 960);
    Edge* DE_to_SH = add_edge(test_4, "Detroit", "Shanghai", 15, 1685);
    Edge* LA_to_BJ = add_edge(test_4, "Los Angeles", "Beijing", 14, 1169);
    Edge* SH_to_SY = add_edge(test_4, "Shanghai", "Shenyang", 2.5, 203);
    Edge* BJ_to_SY = add_edge(test_4, "Beijing", "Shenyang", 3.5, 75);

    // Find the path with the shortest time from Grand Rapids to Shenyang
    cout << find_shortest_time(test_4, "Grand Rapids", "Shenyang") << endl;

    // Find the path with the lowest cost from Grand Rapids to Shenyang
    cout << find_lowest_cost(test_4, "Grand Rapids", "Shenyang") << endl;

    return 0;
}