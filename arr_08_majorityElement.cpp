#include <bits/stdc++.h>
using namespace std;

int brute_majorityElement(vector<int> arr){

	for(int i = 0; i < arr.size(); i++){
		int cnt = 0;

		for(int j = 0; j < arr.size(); j++){
			if(arr[j] == arr[i]){
				cnt++;
			}
		}

		if(cnt > arr.size()/2){
			return arr[i];
		}
	}

	return -1;
}

int better_majorityElementUsingHash(vector<int> &arr){
	map<int, int> mpp;

	for(int i = 0; i < arr.size(); i++){
		mpp[arr[i]]++;
	}

	for(auto it: mpp){
		if(it.second > arr.size()/2){
			return it.first;
		}
	}

	return -1;
}

int optimal_majorityElementUsingMooreVotingAlgo(vector<int> &arr){

	int cnt = 0;
	int el;

	for(int i = 0; i < arr.size(); i++){
		if(cnt == 0){
			cnt = 1;
			el = arr[i];
		}

		else if(arr[i] == el){
			cnt++;
		}
		else{
			cnt--;
		}
	}

	int cnt1 = 0;

	for(int i = 0; i < arr.size(); i++){
		if(arr[i] == el) cnt1++;
	}

	if(cnt1 > arr.size()/2){
		return el;
	}

	return -1;
}

int main(){
	int n;

	cin>>n;

	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}

	cout<<"Majority Element using brute is: "<<brute_majorityElement(arr)<<endl;
	cout<<"Majority Element using better HashMap is: "<<better_majorityElementUsingHash(arr)<<endl;
	cout<<"Majority Element using optimal Moore's Voting Algorithm is: "<<optimal_majorityElementUsingMooreVotingAlgo(arr)<<endl;
	
}