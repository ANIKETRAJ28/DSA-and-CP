#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

void lexographical(int n, int t)
{
  if (t > n)
    return;
  cout << t << "\n";
  for (int i = 0; i <= 9; i++)
  {
    lexographical(n, t * 10 + i);
  }
}

int main()
{
  int n;
  cin >> n;
  int digit = n;
  int lastDigit = 0;
  while (n != 0)
  {
    lastDigit = n % 10;
    n /= 10;
  }
  for (int i = 1; i <= lastDigit; i++)
  {
    lexographical(digit, i);
  }
  return 0;
}