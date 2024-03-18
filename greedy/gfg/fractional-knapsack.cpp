#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

struct Item {
    int value;
    int weight;
};

class Solution {
    public:
    //Function to get the maximum total value in the knapsack.
    
    static bool cmp(pair<int, int> &p1, pair<int, int> &p2) {
        // pair<int, int> 1st -> value, 2nd -> weight
        double profit1 = (p1.first*1.0)/ (p1.second*1.0);
        double profit2 = (p2.first*1.0)/ (p2.second*1.0);
        return profit1 > profit2;
    }
    
    double fractionalKnapsack(int W, Item arr[], int n) {
        // Your code here
        vector<pair<int, int>> netProfit(n);
        for(int i = 0 ; i < n ; i++) {
            netProfit[i].first = arr[i].value;
            netProfit[i].second = arr[i].weight;
        }
        sort(netProfit.begin(), netProfit.end(), cmp);
        double ans = 0.0;
        for(int i = 0 ; i < n ; i++) {
            if(W == 0) return ans;
            if(W >= netProfit[i].second) {
                ans += (netProfit[i].first)*1.0;
                W -= netProfit[i].second;
            } else {
                ans += ((netProfit[i].first*1.0)/(netProfit[i].second*1.0)*W);
                return ans;
            }
        }
    }
        
};

int main() {
    int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(6)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}