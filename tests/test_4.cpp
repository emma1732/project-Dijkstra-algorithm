#include "../code/Graph.cpp"

using namespace std;

int main() {
    
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