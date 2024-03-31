#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/harshad-number/description/

class Solution {
public:
    int digits(int n) {
        int num = 0;
        while(n) {
            num += n%10;
            n/=10;
        }
        return num;
    }
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int n = digits(x);
        return x%n == 0 ? n : -1;
    }
};

int main() {
    
    return 0;
}