#include <bits/stdc++.h>
using namespace std;

//T.C -> O(logN base2)
//S.C -> O(1)
int iterative_BinarySearch(vector<int> &arr, int target){
	int low = 0;
	int high = arr.size() - 1;

	while(low <= high){
		int mid = (high + low) / 2;

		if(arr[mid] == target) return mid;
		else if(target > arr[mid]) low = mid + 1;
		else high = mid - 1;
	}

	return -1;
}

//T.C -> O(logN base2)
//S.C -> O(1)
int recursive_BinarySearch(vector<int> &arr,int low,int high, int target){
	if(low > high) return -1;

	int mid = (high + low) / 2;

	if(arr[mid] == target) return mid;
	else if(target > arr[mid]) return recursive_BinarySearch(arr,mid+1,high,target);
	else return recursive_BinarySearch(arr,low,mid - 1,target);
}

int searchBinary(vector<int> &arr, int target){
	int high = arr.size() - 1;
	return recursive_BinarySearch(arr,0,high,target);
}

int main(){
	int n,target;
	cin>>n>>target;

	vector<int> arr(n);

	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}

	cout<<"Binary Seach of target: "<<target<<" is using iterative binary Search: "<<searchBinary(arr,target);

	return 0;
}