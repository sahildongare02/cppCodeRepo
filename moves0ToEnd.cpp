#include <bits/stdc++.h>
using namespace std;

/*
TC -> O(2N)
SC -> O(x) worst case -> O(N)
*/
void movesZeroToEnd(vector<int> &arr){
	vector<int> temp;

	for(int i = 0; i < arr.size(); i++){
		if(arr[i] != 0){
			temp.push_back(arr[i]);
		}
	}

	for(int i = 0; i < temp.size(); i++){
		arr[i] = temp[i];
	}

	for(int i = temp.size(); i < arr.size(); i++){
		arr[i] = 0;
	}
}

//without using temp arr & optimal Soln
/*
TC -> O(N)
SC -> O(1)
*/
void movesZeroToEnd(vector<int> &arr){
	int j = -1;
	for(int i = 0; i < arr.size();i++){
		if(arr[i] == 0){
			j = i;
			break;
		}
	}

	for(int i = j + 1;i < arr.size(); i++){
		if(arr[i] != 0){
			swap(arr[i],arr[j]);
			j++;
		}
	}
}

int main(){
	int n;
	cin>>n;

	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}

	movesZeroToEnd(arr);

	for(int i = 0; i < n; i++){
		cout<<arr[i]<<" ";
	}
}