#include <iostream>
#include <string>
#include <unordered_map>
#include <exception>
#include <vector>
#include <algorithm>

using namespace std;
 
unordered_map<char, int> elements = {
    {'H', 1},
    {'B', 11},
    {'C', 12},
    {'N', 14},
    {'O', 16},
    {'F', 19},
    {'P', 31},
    {'S', 32},
    {'K', 39},
    {'I', 127},
    {'Y', 89},
    {'V', 51}
};
 
int calculate_molar_mass(string compound) {
    // Separate the compound into its elements and count of elements
    unordered_map<string, int> elements_info;
    int i = 0;
    while (i < compound.length()) {
        string element = "";
        string count = "";
        while (i < compound.length() && isalpha(compound[i])) {
            element += compound[i];
            i++;
        }
        while (i < compound.length() && isdigit(compound[i])) {
            count += compound[i];
            i++;
        }
        if (elements.find(element[0]) == elements.end()) {
            throw invalid_argument("Invalid Input");
        }
        elements_info[element] = (count != "") ? stoi(count) : 1;
    }
 
    // Calculate the molar mass using the elements_info and elements dictionary
    int molar_mass = 0;
    for (auto element_count : elements_info) {
        if (elements.find(element_count.first[0]) == elements.end()) {
            throw invalid_argument("Invalid Input");
        }
        molar_mass += elements[element_count.first[0]] * element_count.second;
    }
 
    return molar_mass;
}
 
void get_total_molar_mass(string compound1, string compound2) {
    try {
        int m1 = calculate_molar_mass(compound1);
        int m2 = calculate_molar_mass(compound2);
        cout << m1 + m2 << endl;
    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }
}
 
int main() {
    try {
        int t;
        cin >> t;
        if (!cin) {
            throw runtime_error("Invalid input. Please check the question description.");
        }
        while (t--) {
            string compound1, compound2;
            cin >> compound1 >> compound2;
            if (!cin) {
                throw runtime_error("Invalid input. Please check the question description.");
            }
            get_total_molar_mass(compound1, compound2);
        }
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }
    return 0;
}