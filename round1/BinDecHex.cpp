#include <iostream>
#include <string>
#include <bitset>

using namespace std;

void solve(string binary1)
{
    
	int decimal1 = stoi(binary1,nullptr,2);
    
	string hexString = to_string(decimal1);

	int decimalValue = stoi(hexString, nullptr, 16);

	string binaryString = bitset<32>(decimalValue).to_string();

	binaryString.erase(0, min(binaryString.find_first_not_of('0'), binaryString.size() - 1));

	cout <<binaryString << endl;

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
        	string a;
        	std::cin >> a;
        	if (!std::cin || a.length() < 1 || a.length() > 16)
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