#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/largest-odd-number-in-string/description/

class Solution {
public:
    string largestOddNumber(string num) {
        while(num != ""){
            if((num[num.size()-1] - '0') %2 != 0) return num;
            num.pop_back();
        }
        return num;
    }
};

int main(){
    
    return 0;
}