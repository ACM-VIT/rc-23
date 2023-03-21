#include <iostream>
#include <cmath>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        int pieces = (pow(n, 2) + n + 2) / 2;
        std::cout<< pieces << std::endl;
    }
    return 0;
}
