// C++ Program to solve the 'Remove Prefix' problem
#include <iostream>
#include <vector>
using namespace std;

int solve();

int main()
{
    int tests;
    printf("Enter number of testcases : ");
    scanf("%d", &tests);
    if (tests == 0)
    {
        return 0;
    }

    vector<int> output(tests);
    for (int i = 0; i < tests; i++)
    {
        output[i] = solve();
    }

    printf("\nOUTPUT : \n");
    for (int i = 0; i < tests; i++)
    {
        printf("%d\n", output[i]);
    }
    return 0;
}

// Function which finds the minimum number of elements that should be removed
// Time complexity = O(n)
int solve()
{
    int num;
    printf("Enter length of sequence : ");
    scanf("%d", &num);
    vector<int> arr(num);
    vector<int> freq(num + 1, 0);

    for (int i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
        freq[arr[i]]++;
    }

    int ans = 0;
    for (int i = 0; i < num; i++)
    {
        if (freq[arr[i]] > 1)
        {
            freq[arr[i]]--;
            ans = i + 1;
        }
    }
    return ans;
}
