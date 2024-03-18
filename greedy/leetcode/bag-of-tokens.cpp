#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/bag-of-tokens/description

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        int i = 0, j = n-1;
        int score = 0;
        int ans = 0;
        while(i <= j) {
            if(power >= tokens[i]) {
                power -= tokens[i++];
                ans = max(ans, ++score);
            }
            else if(score > 0) {
                power+= tokens[j--];
                score--;
            }
            else break;
        }
        return ans;
    }
};

int main() {
    
    return 0;
}