#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solveMyProblem(istream &cin, ostream &cout) {
    double phi = 1.618033988749894;
    try{
        // declare variables here
        int n1, n2;
        // take inputs here
        cin >> n1;
        if (n1 < 3 || n1 > 15 || !std::cin)
        {
            throw -1;
        }
        int num1[n1];
        for (int i = 0; i < n1; i++)
        {   
            int inp;
            cin >> inp;            
            if (inp < 1 || inp > 100000 || !std::cin){
                throw -1;
            }
            num1[i];
        }
        cin >> n2;
        if (n2 < 3 || n2 > 15 || !std::cin)
        {
            throw -1;
        }
        int num2[n2];
        for (int i = 0; i < n2; i++)
        {
            int inp;
            cin >> inp;
            if (inp < 1 || inp > 100000 || !std::cin){
                throw -1;
            }
            num2[i];
        }
        // solve here
        float difference;
        int a,b;
        for (int i = 0; i < n1; i++)
        {   
            float ratio1 = 0, ratio2 = 0;
            int distance = 0;
            for (int j = 0; j < n2; j++)
            {
                ratio1 = num1[i] / (float) num2[j];
                ratio2 = num2[j] / (float) num1[i];
                distance = min(abs(ratio1 - phi), abs(ratio2 - phi));
                if (distance <= difference)
                {
                    difference = distance;
                    a = num1[i];
                    b = num2[j];
                }
                // cout << a << "," << b << endl;
            }  
        }
        cout << a << "/" << b << ":" << difference << endl; 
    }
    catch (int e)
    {
        cout << "Input out of range." << endl;
    }
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
