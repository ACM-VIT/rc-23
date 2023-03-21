#include <iostream>

void solve(int time1,int time2)
{
	int hour1 = time1 / 10000;    	 
	int minute1 = (time1 / 100) % 100;
	int second1 = time1 % 100; 	 

	int hour2 = time2 / 10000;    	 
	int minute2 = (time2 / 100) % 100;
	int second2 = time2 % 100;    	 

	int total_seconds1 = hour1 * 3600 + minute1 * 60 + second1;
	int total_seconds2 = hour2 * 3600 + minute2 * 60 + second2;

	int time_difference = total_seconds2 - total_seconds1;

	std::cout << time_difference << std::endl;

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
        	long long a,b;
        	std::cin >> a >> b;
        	if (!std::cin || a / 10000 < 0 || a / 10000 > 24 || ((a / 100) % 100) < 0 || ((a / 100) % 100) > 59 || a%100<0 || a%100>59 )
            	throw -2;
        	if (!std::cin || b / 10000 < 0 || b / 10000 > 24 || ((b / 100) % 100) < 0 || ((b / 100) % 100) > 59 || b % 100 < 0 || b % 100 > 59)
            	throw -2;
        	solve(a,b);
    	}
	}
	catch (...)
	{
    	std::cout << "Invalid input. Please check the question description.\n";
	}
	return 0;
}
