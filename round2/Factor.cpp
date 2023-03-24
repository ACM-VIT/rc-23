#include <iostream>

using namespace std;

void solve(int n)
{
	int sum = 0;

	for (int i = 2; i <= n; i += 2)
	{
    	if (n % i == 0)
    	{
        	sum += i;
    	}
	}
	cout << sum << endl;

}
int main()
{
	try
	{
    	int test;
    	std::cin >> test;
    	if (!std::cin || test < 1 || test > 150)
        	throw -1;
    	for (int t = 0; t < test; t++)
    	{
        	long long a;
        	std::cin >> a ;
        	if (!std::cin || a < 1 || a > 10000)
            	throw -2;
        	solve(a);
    	}
	}
	catch (...)
	{
    	std::cout << "Invalid input. Please check the question description.\n";
	}
	return 0;
}
