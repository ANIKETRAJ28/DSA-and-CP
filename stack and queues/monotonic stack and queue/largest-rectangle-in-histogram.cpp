#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/largest-rectangle-in-histogram/description/

class Solution
{
public:
  int largestRectangleArea(vector<int> &heights)
  {
    int n = heights.size();
    vector<int> ps(n), ns(n);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
      while (!st.empty() && heights[i] <= heights[st.top()])
        st.pop();
      ps[i] = st.empty() ? -1 : st.top();
      st.push(i);
    }
    while (!st.empty())
      st.pop();
    for (int i = n - 1; i >= 0; i--)
    {
      while (!st.empty() && heights[i] <= heights[st.top()])
        st.pop();
      ns[i] = st.empty() ? n : st.top();
      st.push(i);
    }
    int area = 0;
    for (int i = 0; i < n; i++)
    {
      int breadth = ns[i] - ps[i] - 1;
      area = max(area, breadth * heights[i]);
    }
    return area;
  }
};

int main()
{

  return 0;
}