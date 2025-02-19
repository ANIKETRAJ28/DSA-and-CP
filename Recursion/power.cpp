#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

int power(int a, int b)
{
  if (b == 0)
    return 1;
  int pow = power(a, b / 2);
  pow *= pow;
  if (b % 2)
    pow *= a;
  return pow;
}

int main()
{
  cout << power(2, 5) << "\n";
  return 0;
}