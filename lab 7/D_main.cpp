#include <iostream>
#include <string.h>
#include "hemshead.h"
using namespace std;

//This program is to remove the character left to a '+' using stack ADT
string pop_plus(string);

int main()
{
    string input;
    cout << "Enter input string : ";
    cin >> input;
    cout << pop_plus(input);
}

string pop_plus(string input)
{
    Stack stack;
    string output;
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] != '+')
        {
            stack.push(input[i]);
        }
        else
        {
            stack.pop();
        }
    }
    while (stack.peek() != '\0')
    {
        output += stack.pop();
    }
    int num = output.length();
    for (int i = 0; i < num / 2; i++)
    {
        char temp = output[i];
        output[i] = output[num - i - 1];
        output[num - i - 1] = temp;
    }
    return output;
}
// Time Complexity = O(n)