#include <bits/stdc++.h>
using namespace std;

//T.C~O(N3)
//S.C~O(1)
int brute_subarrayWithXOR(vector<int> &arr, int k){

	int cnt = 0;
	for(int i = 0; i < arr.size(); i++){
		for(int j = i; j < arr.size(); j++){
			int XOR = 0;

			for(int l = i; l <= j; l++){
				XOR ^= arr[l];
			}

			if(XOR == k){
				cnt++;
			}
		}
	}

	return cnt;
}

//T.C~O(N2)
//S.C~O(1)
int better_subarrayWithXOR(vector<int> &arr, int k){

	int cnt = 0;
	for(int i = 0; i < arr.size(); i++){
		int XOR = 0;
		for(int j = i; j < arr.size(); j++){
			XOR ^= arr[j];

			if(XOR == k){
				cnt++;
			}
		}
	}

	return cnt;
}

//T.C~O(N)
//S.C~O(N)
int optimal_subarrayWithXOR(vector<int> &arr, int k){
	int XOR = 0;
	map<int,int> mpp;

	mpp[XOR]++;//{0,1}
	int cnt = 0;
	for(int i = 0; i < arr.size(); i++){
		XOR ^= arr[i];

		int x = XOR ^ k;

		cnt += mpp[x];

		mpp[XOR]++;
	}

	return cnt;
}

int main(){

	int n;
	cin>> n;

	vector<int> arr(n);
	for(auto &it:arr){
		cin>>it;
	}

	int k;
	cin>> k;

	cout<<"Subarray count with XOR using brute is: "<<brute_subarrayWithXOR(arr,k)<<endl;
	cout<<"Subarray count with XOR using brute is: "<<better_subarrayWithXOR(arr,k)<<endl;
	cout<<"Subarray count with XOR using brute is: "<<optimal_subarrayWithXOR(arr,k)<<endl;
	return 0;
}