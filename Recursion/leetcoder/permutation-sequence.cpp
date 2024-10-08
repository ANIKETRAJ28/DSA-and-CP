#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/permutation-sequence/description/

class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> num;
        for(int i = 1 ; i < n ; i++) {
            num.push_back(i);
            fact *= i;
        }
        num.push_back(n);
        k -= 1;
        // starting from 0th index, so k = k-1 because 1 permutatuion back
        // ans for n fact is factorial(n-1) because for n, the repetitions will be factorial(n-1)
        // because for n, there will be factorial(n-1) numbers where n can be placed at first 
        string ans = "";
        while(num.size()) {
            ans += to_string(num[k/fact]);
            num.erase(num.begin()+k/fact);
            if(!num.size()) break;
            k %= fact;
            fact /= num.size();
        }
        return ans;
    }
};

int main() {
    
    return 0;
}