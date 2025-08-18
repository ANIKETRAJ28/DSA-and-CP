#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/open-the-lock/description

class Solution
{
public:
    int openLock(vector<string> &deadends, string target)
    {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        queue<pair<string, int>> qu;
        unordered_set<string> visited;
        if (dead.find("0000") == dead.end())
            qu.push({"0000", 0});
        visited.insert("0000");
        while (!qu.empty())
        {
            auto el = qu.front();
            qu.pop();
            string curr = el.first;
            int move = el.second;
            if (curr == target)
                return move;
            move++;
            for (int i = 0; i < 4; i++)
            {
                // increment
                string incr_str = curr.substr(0, i) + to_string((curr[i] - '0' + 1) % 10) + curr.substr(i + 1);
                if (dead.find(incr_str) == dead.end() && visited.find(incr_str) == visited.end())
                {
                    qu.push({incr_str, move});
                    visited.insert(incr_str);
                }
                // decerement
                string decr_str = curr.substr(0, i) + to_string((curr[i] - '0' - 1 + 10) % 10) + curr.substr(i + 1);
                if (dead.find(decr_str) == dead.end() && visited.find(decr_str) == visited.end())
                {
                    qu.push({decr_str, move});
                    visited.insert(decr_str);
                }
            }
        }
        return -1;
    }
};

class Solution
{
public:
    void insert(string &s, unordered_set<string> &st, unordered_set<string> &visited, queue<string> &qu)
    {
        for (int i = 0; i < 4; i++)
        {
            char ch = s[i];
            char inc = ch == '9' ? '0' : ch + 1;
            char dec = ch == '0' ? '9' : ch - 1;
            s[i] = inc;
            if (st.find(s) == st.end() && visited.find(s) == visited.end())
            {
                qu.push(s);
                visited.insert(s);
            }
            s[i] = dec;
            if (st.find(s) == st.end() && visited.find(s) == visited.end())
            {
                qu.push(s);
                visited.insert(s);
            }
            s[i] = ch;
        }
    }
    int openLock(vector<string> &deadends, string target)
    {
        string temp = "0000";
        unordered_set<string> st(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        queue<string> qu;

        if (st.find(temp) != st.end())
            return -1;

        int level = 0;
        qu.push(temp);
        visited.insert(temp);

        while (!qu.empty())
        {
            int n = qu.size();
            while (n--)
            {
                string s = qu.front();
                qu.pop();
                if (s == target)
                    return level;
                insert(s, st, visited, qu);
            }
            level++;
        }
        return -1;
    }
};

int main()
{

    return 0;
}