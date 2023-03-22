#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdexcept>

using namespace std;

void inventory_sequence(int terms) {
    int num = 0;
    vector<int> alst {0};
    unordered_map<int, int> inventory {{0, 1}};

    for (int n = 2; n <= terms; n++) {
        int c = inventory[num];
        num = (c == 0) ? 0 : num + 1;
        alst.push_back(c);
        inventory[c]++;
        if (num == 0) {
            for (auto i : alst) {
                cout << i << " ";
            }
            cout << endl;
            alst.clear();
        }
    }
    for (auto i : alst) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int terms;
        cin >> terms;
        try {
            if (terms > 10000) {
                throw invalid_argument("Number of terms should not exceed 10000.");
            }
            inventory_sequence(terms);
        }
        catch (const invalid_argument& e) {
            cerr << "Invalid argument: " << e.what() << endl;
        }
    }
    return 0;
}
