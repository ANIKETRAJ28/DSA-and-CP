#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/push-dominoes/description/

class Solution
{
public:
  string pushDominoes(string s)
  {
    int n = s.size();
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == 'R')
      {
        st.push(i);
      }
      else if (s[i] == 'L')
      {
        while (!st.empty())
        {
          if (s[st.top()] == '.')
          {
            s[st.top()] = 'L';
            st.pop();
          }
          else
            break;
        }
        while (!st.empty())
          st.pop();
      }
      else
      {
        if (!st.empty() && s[st.top()] == 'R')
        {
          int j = i;
          while (j < n && s[j] == '.')
          {
            s[j] = 'R';
            j++;
          }
          if (j != n && s[j] == 'L')
          {
            int mid = i + (j - i) / 2;
            if ((j - i) % 2)
            {
              s[mid] = '.';
              mid++;
            }
            while (mid <= j)
            {
              s[mid] = 'L';
              mid++;
            }
          }
        }
        else
        {
          st.push(i);
        }
      }
    }
    return s;
  }
};

int main()
{

  return 0;
}