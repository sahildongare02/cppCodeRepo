#include <bits/stdc++.h>
using namespace std;

int linearSearch(vector<int> &arr, int k){

	for(int i = 0; i < arr.size(); i++){
		if(arr[i] == k){
			return i;
		}
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

	int k;
	cin>>k;

	cout<<"The element found at index: "<<linearSearch(arr, k);
}