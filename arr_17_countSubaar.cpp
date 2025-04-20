#include <bits/stdc++.h>
using namespace std;

int brute_countSubArray(vector<int> &arr, int k){

	int cnt = 0;
	for(int i = 0; i < arr.size(); i++){
		for(int j = i; j < arr.size(); j++){
			int sum = 0;

			for(int m = i; m <= j; m++){
				sum += arr[m];
			}

			if(sum == k){
				cnt++;
			}
		}
	}

	return cnt;
}

int better_countSubArray(vector<int> &arr, int k){

	int cnt = 0;
	for(int i = 0; i < arr.size(); i++){
		int sum = 0;
		for(int j = i; j < arr.size(); j++){
			sum += arr[j];

			if(sum == k){
				cnt++;
			}
		}
	}

	return cnt;
}

int optimal_countSubArr(vector<int> &arr, int k){
	unordered_map<int,int> mpp;

	int preSum = 0, cnt = 0;

	mpp[0] = 1;

	for(int i = 0; i < arr.size(); i++){
		preSum += arr[i];

		int remove = preSum - k;

		if(mpp.find(remove) != mpp.end()){
			cnt += mpp[remove];
		}

		mpp[preSum] += 1;
	}

	return cnt;
}

int main(){
	int n;
	cin>>n;

	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}

	int k;
	cin>>k;

	cout<<"No of subarrays are using brute is: "<<brute_countSubArray(arr, k)<<endl;
	cout<<"No of subarrays are using better is: "<<better_countSubArray(arr, k)<<endl;
	cout<<"No of subarrays are using optimal preSum is: "<<optimal_countSubArr(arr, k)<<endl;
} 