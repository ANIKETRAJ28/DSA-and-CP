#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/online-stock-span/description/

class StockSpanner
{
public:
  stack<pair<int, int>> st;
  StockSpanner()
  {
  }

  int next(int price)
  {
    int ans = 1;
    while (!st.empty() && price >= st.top().first)
    {
      ans += st.top().second;
      st.pop();
    }
    st.push({price, ans});
    return ans;
  }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

int main()
{

  return 0;
}