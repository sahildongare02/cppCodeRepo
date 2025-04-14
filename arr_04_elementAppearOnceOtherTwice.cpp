#include <bits/stdc++.h>
using namespace std;

//T.C = O(N*N)
//S.C = O(1)
int brute_noAppearOnce(vector<int> &arr, int n){
	for(int i = 0; i < n; i++){
		int num = arr[i];
		int cnt = 0;

		for(int j = 0; j < n; j++){
			if(arr[j] == num){
				cnt++;
			}
		}

		if(cnt == 1) return num;
	}

	return -1;
}

int better1_noAppearOnce_UsingHash(vector<int> &arr, int n){
	int maxi = arr[0];
	for(int i = 1; i < n; i++){
		maxi = max(arr[i],maxi);
	}

	vector<int> hash(maxi,0);

	for(int i = 0; i < n; i++){
		hash[arr[i]]++;
	}

	for(int i = 0; i < n; i++){
		if(hash[arr[i]] == 1){
			return arr[i];
		}
	}

	return -1;
}

int better2_noAppearOnce_UsingMap(vector<int> &arr, int n){
	map<int, int> mpp;

	for(int i = 0; i < n; i++){
		mpp[arr[i]]++;
	}

	for(auto it:mpp){
		if(it.second == 1){
			return it.first;
		}
	}

	return -1;
}

int optimal_noAppearOnce_UsingXOR(vector<int> &arr, int n){
	int XOR = 0;

	for(int i = 0; i < n; i++){
		XOR ^= arr[i];
	}

	return XOR;
}

int main(){
	int n;
	cin>>n;

	vector<int> arr(n);

	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}

	cout <<"The no which appears once using Brute is: "<<brute_noAppearOnce(arr,n)<<endl;
	cout <<"The no which appears once using Better1 Hash is: "<<better1_noAppearOnce_UsingHash(arr,n)<<endl;
	cout <<"The no which appears once using Better2 Map is: "<<better2_noAppearOnce_UsingMap(arr,n)<<endl;
	cout <<"The no which appears once using Optimal XOR is: "<<optimal_noAppearOnce_UsingXOR(arr,n)<<endl;
}