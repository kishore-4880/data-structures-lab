//Program to solve word game

#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<int> solve();

int main()
{
    int tests;
    printf("Enter number of testcases : ");
    scanf("%d", &tests);
    if (tests == 0)
    {
        return 0;
    }
    vector<vector<int>> output(tests);
    for (int i = 0; i < tests; i++)
    {
        output[i] = solve();
    }
    printf("OUTPUT : \n");
    for (int i = 0; i < tests; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d  ", output[i][j]);
        }
        printf("\n");
    }
    return 0;
}

// Function to solve and return scores
vector<int> solve()
{
    int num;
    printf("Enter number of words : ");
    scanf("%d", &num);
    char inp[101];
    vector<vector<string>> words(3, vector<string>(num));
    unordered_map<string, int> wordcount;

    for (int i = 0; i < 3; i++)
    {
        printf("Player %d : \n", i + 1);
        for (int j = 0; j < num; j++)
        {
            scanf("%s", inp);
            words[i][j] = string(inp);
            wordcount[words[i][j]]++;
        }
    }

    vector<int> scores(3, 0);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < num; j++)
        {
            string word = words[i][j];
            if (wordcount[word] == 1)
            {
                scores[i] += 3;
            }
            else if (wordcount[word] == 2)
            {
                scores[i] += 1;
            }
        }
    }
    return scores;
}
