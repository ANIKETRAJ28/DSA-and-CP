/**
Say you have an array prices for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Input Format
First Line,contains an interger n i.e. size of the array. Second Line contains n space separated integers, each indicating the price of given stock on that day.

Constraints
1 <= prices.length <= 10 ^ 4 0 <= prices[i] <= 10 ^ 4

Output Format
It returns the maximum profit that can attained from the given prices array.

Sample Input 0
8
1300 1231 940 1615 1839 1195 20 467
Sample Output 0
1346

Sample Input 1
3
536 677 68
Sample Output 1
141
 */

#include<bits/stdc++.h>
using namespace std;

int profits(vector<int> &prices) {
    int profit = 0;
    int minP = INT_MAX, maxP = INT_MIN;
    for(int i = 0 ; i < prices.size() ; i++) {
        if(prices[i] < minP && maxP == INT_MIN) minP = prices[i];
        else {
            if(prices[i] > maxP) maxP = prices[i];
            else {
                profit += maxP - minP;
                minP = prices[i];
                maxP = INT_MIN;
            }
            
        }
    }
    if(maxP != INT_MIN) profit += maxP - minP;
    return profit;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin>>n;
    vector<int> prices(n);
    for(int i = 0 ; i < n ; i++) cin>>prices[i];
    cout<<profits(prices);
    return 0;
}