#include <bits/stdc++.h>

using namespace std;

// https://www.hackerrank.com/challenges/candies/problem

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'candies' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY arr
 */

long candies(int n, vector<int> arr)
{
  int cnt = 1;
  long ans = 1;
  int prv = arr[0];
  for (int i = 1; i < n; i++)
  {
    if (arr[i] <= prv)
    {
      cnt = 1;
      int x = arr[i];
      while (i < n && arr[i] <= x)
      {
        cnt++;
        i++;
      }
      ans += cnt * (cnt + 1 / 2);
      cnt = 1;
      i--;
    }
    else
    {
      cnt++;
      ans += cnt;
    }
    prv = arr[i];
  }
  return ans;
}

int main()
{
  ofstream fout(getenv("OUTPUT_PATH"));

  string n_temp;
  getline(cin, n_temp);

  int n = stoi(ltrim(rtrim(n_temp)));

  vector<int> arr(n);

  for (int i = 0; i < n; i++)
  {
    string arr_item_temp;
    getline(cin, arr_item_temp);

    int arr_item = stoi(ltrim(rtrim(arr_item_temp)));

    arr[i] = arr_item;
  }

  long result = candies(n, arr);

  fout << result << "\n";

  fout.close();

  return 0;
}

string ltrim(const string &str)
{
  string s(str);

  s.erase(
      s.begin(),
      find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

  return s;
}

string rtrim(const string &str)
{
  string s(str);

  s.erase(
      find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
      s.end());

  return s;
}
