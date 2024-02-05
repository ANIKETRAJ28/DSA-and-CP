#include <bits/stdc++.h>

using namespace std;

// https://www.hackerrank.com/challenges/recursive-digit-sum/problem?isFullScreen=true

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'superDigit' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING n
 *  2. INTEGER k
 */

int ans = 0;

void f(long long int sum) {
    // base case
    if(sum/10 == 0) {
        ans = sum;
        return;
    }
    
    long long int sum1 = 0;
    while(sum > 0) {
        sum1 += sum%10;
        sum/= 10;
    }
    
    f(sum1);
}

int superDigit(string n, int k) {
    // base case
    if(n.size() == 1) return n[0]-0;
    
    long long int sum = 0;
    
    for(int i = 0 ; i < n.size() ; i++) {
        char c = n[i];
        sum += (c-'0');
    }
    sum *= k;
    cout<<sum;
    f(sum);
    return  ans;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    string n = first_multiple_input[0];

    int k = stoi(first_multiple_input[1]);

    int result = superDigit(n, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
