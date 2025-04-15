#include <bits/stdc++.h>
using namespace std;

int brute_MaximumSubarraySum(vector<int> &arr){
	int maxi = INT_MIN;

	for(int i = 0; i < arr.size();i++){
		for(int j = i; j < arr.size();j++){
			int sum = 0;

			for(int k = i; k <=j; k++){
				sum += arr[k];
			}

			maxi = max(maxi,sum);
		}
	}

	return maxi;
}

int brute_MaximumSubarraySumOtimized(vector<int> &arr){
	int maxi = INT_MIN;

	for(int i = 0; i < arr.size();i++){
		int sum = 0;
		for(int j = i; j < arr.size();j++){
			sum += arr[j];
			maxi = max(maxi,sum);
		}
	}

	return maxi;
}

int opitmal_MaximumSubarraySum(vector<int> &arr){
	int maxi = INT_MIN;
	int sum = 0;

	for(int i = 0; i < arr.size(); i++){
		sum += arr[i];

		if(sum > maxi){
			maxi = sum;
		}

		if(sum < 0){
			sum = 0;
		}
	}

	return maxi;
}

int main(){
	int n;
	cin>>n;

	vector<int> arr(n);

	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}

	cout<<"Sum of maximum subarray using brute is: "<<brute_MaximumSubarraySum(arr)<<endl;
	cout<<"Sum of maximum subarray using brute optimized is: "<<brute_MaximumSubarraySumOtimized(arr)<<endl;
	cout<<"Sum of maximum subarray using optimal is: "<<opitmal_MaximumSubarraySum(arr)<<endl;
}