/*
    Author: Sai Sreekar
    Difficulty: Medium-Hard
    Test Case Description:
    First line contains an integer T (between 1 and 150) which stands for the number of testcases.
    Each test case consists of two lines. The first line contains a single integer n  — the length of the string s.
    The second line contains the string s of length n consisting of lowercase English letters.
*/

/*
    Logic:
    Find a string with minimum number of operations in which all characters that are present in it appear the same number of times. If there are multiple solutions, print any.


    Sample Input:
    4
    5
    hello
    10
    saisreekar
    5
    eevee
    6
    appall


    Sample Output:
    1
    1
    1
    0

    In the first test case “hello” all characters domt have same frequency. So it has to be modified in minimum number of operations. The best way is to change ‘l’ to any other character other than ‘h’, ‘e’, ‘o’.One of the possible solutions is “hezlo”. minimum operation is 1
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

#define ll long long
#define MAX_CHAR 26

void getBalancedString()
{

    int n;
    cin >> n;

    int result = INT_MAX;
    int idx = -1;
    int freqMap[MAX_CHAR] = {};
    string str = "";
    priority_queue<pair<int, int> > priorityQueue;
    int hashMapArray[MAX_CHAR] = {};

    for (int i = 0; i < n; i++)
    {
        char charInput;
        cin >> charInput;
        str += charInput;
        freqMap[(int)(charInput - 'a')]++;
    }

    for (int i = 0; i < MAX_CHAR; i++)
    {
        int count = i + 1;

        if (n % count != 0)
        {
            continue;
        }

        int z = n / count;

        priority_queue<int> priorityQueue;
        for (int i = 0; i < MAX_CHAR; i++)
        {
            priorityQueue.push(freqMap[i]);
        }

        int pos = 0;
        while (count--)
        {
            int charArray = priorityQueue.top();
            priorityQueue.pop();
            pos += max(0, z - charArray);
        }

        if (result > pos)
        {
            result = pos;
            idx = i + 1;
        }
    }

    for (int i = 0; i < MAX_CHAR; i++)
    {
        priorityQueue.push(make_pair(freqMap[i], i));
        hashMapArray[i] = INT_MAX;
    }

    int z = n / idx;

    while (idx--)
    {
        int pqSecond = priorityQueue.top().second;
        int pqFirst = priorityQueue.top().first;
        priorityQueue.pop();
        hashMapArray[pqSecond] = pqFirst - z;
    }

    char charArray[n];
    for (int i = 0; i < n; i++)
    {
        int pqSecond = (int)(str[i] - 'a');
        if (hashMapArray[pqSecond] == INT_MAX)
        {
            for (int j = 0; j < MAX_CHAR; j++)
            {
                if (hashMapArray[j] < 0)
                {
                    hashMapArray[j]++;
                    charArray[i] = char(j + (int)('a'));
                    break;
                }
            }
        }
        else if (hashMapArray[pqSecond] > 0)
        {
            hashMapArray[pqSecond]--;
            for (int j = 0; j < MAX_CHAR; j++)
            {
                if (hashMapArray[j] < 0)
                {
                    hashMapArray[j]++;
                    charArray[i] = char(j + (int)('a'));
                    break;
                }
            }
        }
        else
        {
            charArray[i] = char(pqSecond + (int)('a'));
        }
    }

    cout << result << "\n";
    // for (int i = 0; i < n; i++)
    // {
    //     cout << charArray[i];
    // }

    // cout << "\n";
}

int main()
{
    try {
        int testCases;
        cin >> testCases;
        while (testCases--)
        {
            getBalancedString();
        }
        return 0;
    }
    catch (...)
    {
        cout << "Invalid input. Please check the question description.\n";
    }
}
