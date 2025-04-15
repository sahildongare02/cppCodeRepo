#include <bits/stdc++.h>
using namespace std;

int buyAndSell(vector<int> &arr){
	int mini = arr[0];
	int profit = 0;

	for(int i = 1; i < arr.size(); i++){
		int maxProfit = arr[i] - mini;
		profit = max(profit,maxProfit);
		mini = min(mini,arr[i]);
	}

	return profit;
}

int main(){
	int n;
	cin >> n;

	vector<int> arr(n);

	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	cout<<"Maximum profit: "<<buyAndSell(arr)<<endl;
}