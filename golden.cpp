#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

#define phi 1.618033988749894

void solveMyProblem(istream &cin, ostream &cout) {
    // declare variables here
    int n1, n2;
    vector<int> num1(n1);
    // take inputs here
    cin >> n1;
    for (int i = 0; i < n1; i++)
    {   
        int inp;
        cin >> inp;
        num1[i];
    }
    cin >> n2;
    vector<int> num2(n2);
    for (int i = 0; i < n2; i++)
    {
        int inp;
        cin >> inp;
        num2[i];
    }

    // solve here
    unsigned long long difference = 1000000000000000;
    double ratio = 0, distance = 0, a = 0, b = 0;
    int i = 0, j = 0;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            double ratio;
            ratio = (double) num1[i] / (double) num2[j];
            double distance = 0;
            distance = abs(ratio - phi);
            if (distance < difference)
            {
                difference = distance;
                double a = (int)num1[i];
                double b = (int)num2[j];
            }
        }  
    }
    cout << a << "/" << b << ":" << difference << endl; 
}

int main() {
    FastIO;
    istream &in(cin);
    ostream &out(cout);
    try{
        long long t = 1;
        cin >> t;
        for (long long test = 1; test <= t; test++) {
            solveMyProblem(in, out);
        }
    }
    catch (exception &e) {
        cout << "Incorrect formats. Check question description." << endl;
    }
    return 0;
}
