#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

void find(vector<int> &arr, int k) {
    int n = arr.size();
    int i = 0, j = 0;
    int max_sum = 0, sum = 0;
    for(j ; j < k ; j++) sum += arr[j];
    int strt = i, end = j-1;
    max_sum = sum;
    while(j < n) {
        sum -= arr[i];
        sum += arr[j];
        if(sum > max_sum) {
            max_sum = sum;
            strt = i+1;
            end = j;
        }
        i++;
        j++;
    }
    cout<<strt<<" "<<end<<" "<<max_sum;
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++) cin>>arr[i];
    int k;
    cin>>k;
    find(arr, k);
    return 0;
}