#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/word-break-ii/description/

// ! TC = O(2^n*k) SC = O(n)

class Solution
{
public:
    vector<string> ans;
    bool check(vector<string> &wordDict, string str)
    {
        for (int i = 0; i < wordDict.size(); i++)
        {
            if (str == wordDict[i])
                return true;
        }
        return false;
    }

    void f(string &s, vector<string> &wordDict, string &str, int idx)
    {
        // base case
        if (idx == s.size())
        {
            ans.push_back(str);
            return;
        }

        for (int i = idx; i < s.size(); i++)
        {
            if (check(wordDict, s.substr(idx, i - idx + 1)))
            {

                // check for the spaces between words
                if (str.empty())
                {
                    str += s.substr(idx, i - idx + 1);
                }
                else
                    str = str + ' ' + s.substr(idx, i - idx + 1);

                // reccursive call
                f(s, wordDict, str, i + 1);

                // backtracking and removing the added string
                int j = str.size() - 1;
                while (str != "")
                {
                    if (str[str.size() - 1] == ' ')
                    {
                        str.pop_back();
                        break;
                    }
                    str.pop_back();
                }
            }
        }
    }

    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        string str = "";
        f(s, wordDict, str, 0);
        return ans;
    }
};

class Solution
{
public:
    void totalWords(vector<string> &words, string &s, string &ans, vector<string> &wordDict, int i)
    {
        int n = s.size();
        int m = wordDict.size();
        if (i == n)
        {
            words.push_back(ans);
            return;
        }
        for (int l = 0; l < m; l++)
        {
            if (n - i >= wordDict[l].size() && s.substr(i, wordDict[l].size()) == wordDict[l])
            {
                ans.size() == 0 ? ans += wordDict[l] : ans += ' ' + wordDict[l];
                totalWords(words, s, ans, wordDict, i + wordDict[l].size());
                while (ans != "" && ans[ans.size() - 1] != ' ')
                {
                    ans.pop_back();
                }
                if (ans != "")
                    ans.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        vector<string> words;
        string ans = "";
        totalWords(words, s, ans, wordDict, 0);
        return words;
    }
};

int main()
{

    return 0;
}