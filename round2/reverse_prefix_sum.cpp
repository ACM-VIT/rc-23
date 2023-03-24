#include <iostream>

int solve(int n){
	int s[n];
	for(int i=0;i<n;i++){
		std::cin>>s[i];
	}
	int a[n];
	for(int i=0;i<n;i++){
		int temp = s[i];
		for(int j=0;j<i;j++){
			temp = temp - a[j];
		}
		a[i] = temp;
	}
	for(int i=0;i<n;i++){
		std::cout<<a[i]<<" ";
	}
	std::cout<<"\n";
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
        	long long n;
        	std::cin >> n ;
        	if (!std::cin || n < 1 || n > 10000)
            	throw -2;
        	solve(n);
    	}
	}
	catch (...)
	{
    	std::cout << "Invalid input. Please check the question description.\n";
	}
	return 0;
}
