#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

void f(int n, string s)
{
  if (n == 0)
  {
    cout << s << "\n";
    return;
  }
  f(n - 1, s + '0');
  if (s[s.size() - 1] == '0')
    f(n - 1, s + '1');
}

int main()
{
  int n = 4;
  f(n - 1, "0");
  f(n - 1, "1");
  return 0;
}