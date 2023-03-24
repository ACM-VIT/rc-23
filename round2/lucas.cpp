/**
 * Calculate Lucas number at given index
 */

#include <iostream>

int lucas(int n) {
    if (n == 0) return 2;
    if (n == 1) return 1;
    return lucas(n - 1) + lucas(n - 2);
}

int main() {
    int n;
    std::cin >> n;
    std::cout <<  n << lucas(n) << "\n";
    return 0;
}
