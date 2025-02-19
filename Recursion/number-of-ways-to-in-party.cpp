#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

/*
There are n persons, who want to go to a party. There is a costraint that any person can go alone or can go in a pair. Find the number of ways in which n persons can go to the party.
*/

int totalWays(int n)
{
  if (n == 0 || n == 1 || n == 2)
    return n;
  return (n - 1) * totalWays(n - 2) + totalWays(n - 1);
}

int main()
{
  cout << totalWays(4) << "\n";
  return 0;
}