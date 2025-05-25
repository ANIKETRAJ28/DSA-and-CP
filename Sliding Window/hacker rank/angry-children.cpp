#include <bits/stdc++.h>

using namespace std;

// https://www.hackerrank.com/challenges/angry-children/problem

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'maxMin' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY arr
 */

int maxMin(int k, vector<int> arr)
{
  int n = arr.size();
  sort(arr.begin(), arr.end());
  int i = 0, j = k - 1;
  int ans = INT_MAX;
  while (j < n)
  {
    ans = min(ans, arr[j++] - arr[i++]);
  }
  return ans;
}

int main()
{
  ofstream fout(getenv("OUTPUT_PATH"));

  string n_temp;
  getline(cin, n_temp);

  int n = stoi(ltrim(rtrim(n_temp)));

  string k_temp;
  getline(cin, k_temp);

  int k = stoi(ltrim(rtrim(k_temp)));

  vector<int> arr(n);

  for (int i = 0; i < n; i++)
  {
    string arr_item_temp;
    getline(cin, arr_item_temp);

    int arr_item = stoi(ltrim(rtrim(arr_item_temp)));

    arr[i] = arr_item;
  }

  int result = maxMin(k, arr);

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
