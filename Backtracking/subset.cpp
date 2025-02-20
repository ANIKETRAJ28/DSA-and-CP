#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

void subset(string &s, string &ans, int i)
{
  int n = s.size();
  if (i == n)
  {
    cout << "[";
    for (int i = 0; i < ans.size(); i++)
      cout << ans[i];
    cout << "]\n";
    return;
  }
  // not include
  subset(s, ans, i + 1);
  // include
  ans += s[i];
  subset(s, ans, i + 1);
  ans.pop_back();
}

int main()
{
  string input = "ABC";
  string ans = "";
  subset(input, ans, 0);
  return 0;
}