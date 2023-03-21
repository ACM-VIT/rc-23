#include <iostream>

using namespace std;

int main() {
  double a, m, n, x;
  cin >> a >> m >> n;

  while (n == 1) {
    cout << "The third input cannot be equal to 1. Please enter a different value: ";
    cin >> n;
  }

  x = ((m*n)-a-m)/(1-n);
  cout << x;	
  
  /*
   x, x+a
   x+a+m = n*(x+m)
   x = ((m*n)-a-m)/(1-n)
  */

  return 0;
}
