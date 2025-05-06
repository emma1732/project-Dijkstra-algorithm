#include "../code/Graph.cpp"

using namespace std;

int main() {
    
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
    
    return 0;
}