#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_tree_depth(vector<int>& tree, int node) {
    if (node < tree.size()) {
        int left_child = 2 * node + 1;
        int right_child = 2 * node + 2;
        int left_depth = get_tree_depth(tree, left_child);
        int right_depth = get_tree_depth(tree, right_child);
        return max(left_depth, right_depth) + 1;
    } else {
        return 0;
    }
}

int get_burn_time(vector<int>& tree) {
    int depth = get_tree_depth(tree, 0);
    return depth;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> tree(n);
        for (int j = 0; j < n; j++) {
            cin >> tree[j];
        }
        int burn_time = get_burn_time(tree);
        cout << burn_time << endl;
    }
    return 0;
}