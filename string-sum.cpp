#include <iostream>
#include <cstring>
using namespace std;

int getAscii(char ch)
{
    int ascii = int(ch);
    return ascii;
}

int encrypt_string(string str)
{
    int key = str.length();

    string encrypted_string = "";

    for (int i = 0; i < str.length(); i++)
    {
        string encrypted = "";
        char ch = str[i];
        if (isalpha(ch))
        {
            char shifted_char = char((getAscii(ch) - key - 65) % 26 + 65);
            encrypted += tolower(shifted_char);
        }

        else
        {
            encrypted += ch;
        }

        key -= 1;

        cout << encrypted;
    }

    int ascii_sum =0;

    for (int i = 0; i < encrypted_string.length(); i++)
    {
        ascii_sum += getAscii(encrypted_string[i]);
    }

    return ascii_sum;
}

int main()
{

    cout << "Enter the string to input : ";
    string str;
    cin >> str;

    int encrypted_sum = encrypt_string(str);

    cout<<"The encrypted string's sum of ASCII codes is : "<<encrypted_sum<<endl;

    return 0;
}