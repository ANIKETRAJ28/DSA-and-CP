#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

int f(int chocoWrapper, int wrapper) {
    return chocoWrapper < wrapper ? 0 : chocoWrapper/wrapper + f(chocoWrapper/wrapper+(chocoWrapper%wrapper), wrapper);
}

int main() {
    int money = 15, price = 1, wrap = 3;
    cout<<money/price+f(money/price, wrap);
    return 0;
}