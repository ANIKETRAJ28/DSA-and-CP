#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/lexicographical-numbers/description/

class Solution {
public:
    vector<int> ans;
    void numbers(int n, int target) {
        // base case
        if(n > target) return;

        if(n <= target and n != 0) ans.push_back(n);
        if(n == 0)
            for(int i = 1 ; i <= 9 ; i++) numbers(n*10+i, target);
        else 
            for(int i = 0 ; i <= 9 ; i++) numbers(n*10+i, target);
    }
    vector<int> lexicalOrder(int n) {
        numbers(0, n);
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> ans;
//     void numbers(int n, int target) {
//         // base case
//         if(n > target) return;

//         ans.push_back(n);
        
//         for(int i = 0 ; i <= 9 ; i++) {
//             numbers(n*10+i, target);
//         }
//     }
//     vector<int> lexicalOrder(int n) {
//         for(int i = 1 ; i < 10 ; i++) {
//             numbers(i, n);
//         }
//         return ans;
//     }
// };

int main() {
    
    return 0;
}