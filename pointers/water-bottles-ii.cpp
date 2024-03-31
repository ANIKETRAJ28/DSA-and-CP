#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/water-bottles-ii/description/

class Solution {
public:
    int maxBottlesDrunk(int FB, int EX) {
        int EB = 0, DB = 0;
        while(FB > 0) {
            int NB = 0;
            DB += FB;
            EB += FB;
            while(EX <= EB) {
                EB -= EX;
                NB++;
                EX++;
            }
            FB = NB;
        }
        return DB;
    }
};

int main() {
    
    return 0;
}