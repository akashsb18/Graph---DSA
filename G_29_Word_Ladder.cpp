#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    string beginWord = "hit", endWord = "cog";

    queue<pair<string, int>> q;
    unordered_set<string> s(wordList.begin(), wordList.end());
    q.push({beginWord, 1});

    int steps = 0;

    while (!q.empty())
    {
        string word = q.front().first;
        steps = q.front().second;
        q.pop();
        if (word == endWord)
        {
            cout << steps;
            break;
        }
        for (int i = 0; i < word.length(); i++)
        {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (s.find(word) != s.end())
                {
                    s.erase(word);
                    q.push({word, steps + 1});
                }
            }
            word[i] = original;
        }
    }

    cout << 0;

    return 0;
}