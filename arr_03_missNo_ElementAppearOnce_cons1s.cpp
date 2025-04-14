#include<bits/stdc++.h>
using namespace std;

int missingNo_bruteForce(vector<int> &arr, int N){

	for(int i = 1; i <= N; i++){
		int flag = 0;

		for(int j = 0; j < arr.size(); j++){
			if(arr[j] == i){
				flag = 1;
				break;
			}
		}

		if(flag == 0){
			return i;
		}
	}

	return -1;
}

int missingNo_Hash(vector<int> &arr, int N){
	//vector<int> hash(N+1) = {0};
	vector<int> hash(N+1,0);

	for(int i = 0 ; i < arr.size() ;i++){
		hash[arr[i]] = 1;
	}

	for(int i = 1; i <= N;i++){
		if(hash[i] == 0){
			return i;
		}
	}

	return -1;
}

int missingNo_Sum(vector<int> &arr, int N){
	int totalSum = N*(N+1) / 2;

	int arrSum = 0;

	for(int i = 0; i < arr.size(); i++){
		arrSum+=arr[i];
	}

	return(totalSum - arrSum);
}

int missingNo_XOR(vector<int> &arr, int N){
	int XOR1 = 0;

	int XOR2 = 0;

	for(int i = 0; i < N - 1; i++){
		XOR2 = XOR2 ^ arr[i];

		XOR1 = XOR1 ^ (i+1);
	}

	XOR1 = XOR1 ^ N;

	return( XOR1 ^ XOR2);
}

int consecutiveOnes(vector<int> &arr){
	int maxi = 0;

	int cnt = 0;
	for(int i = 0; i < arr.size(); i++){
		if(arr[i] == 1){
			cnt++;
			maxi = max(maxi,cnt);
		}
		else{
			cnt = 0;
		}
	}

	return maxi;
}


int main(){

	int n;
	cin>>n;

	vector<int> arr(n - 1);
	for(int i = 0; i < n - 1; i++){
		cin>>arr[i];
	}

	int m;
	cin>>m;

	vector<int> nums(m);
	for(int i = 0; i < m; i++){
		cin>>nums[i];
	}

	cout<<"missingNo_bruteForce : "<<missingNo_bruteForce(arr,n)<<endl;

	cout<<"missingNo_Hash : "<<missingNo_Hash(arr,n)<<endl;

	cout<<"missingNo_Sum : "<<missingNo_Sum(arr,n)<<endl;

	cout<<"missingNo_XOR : "<<missingNo_XOR(arr,n)<<endl;

	cout<<"consecutiveOnes : "<<consecutiveOnes(nums)<<endl;

}