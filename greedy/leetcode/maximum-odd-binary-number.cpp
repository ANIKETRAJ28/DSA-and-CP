#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/maximum-odd-binary-number/description

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        if(s.size() == 1) return s;
        sort(s.begin(), s.end(), greater<int> ());
        int n = s.size();
        int idx = -1;
        for(int i = n-2 ; i >= 0 ; i--) {
            if(s[i] == '1') {
                idx = i;
                break;
            }
        }
        swap(s[idx], s[n-1]);
        return s;
    }
};

int main() {
    
    return 0;
}