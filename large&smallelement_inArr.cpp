#include <bits/stdc++.h>
using namespace std;

int largest(vector<int> &arr){
	int largest = arr[0];

	for(int i = 1; i < arr.size(); i++){
		if(arr[i] > largest){
			largest = arr[i];
		}
	}

	return largest;
}

int smallest(vector<int> &arr){
	int smallest = arr[0];

	for(int i = 1; i < arr.size(); i++){
		if(arr[i] < smallest){
			smallest = arr[i];
		}
	}

	return smallest;
}

int sSmallest(vector<int> &arr){
	int smallest = arr[0];
	int sSmallest = INT_MAX;

	for(int i = 0; i < arr.size(); i++ ){
		if(arr[i] < smallest){
			sSmallest = smallest;
			smallest = arr[i];
		}
		else if(arr[i] > smallest && arr[i] < sSmallest ){
			sSmallest = arr[i];
		}
	}

	return sSmallest;
}

int sLargest(vector<int> &arr){
	int largest = arr[0];
	int sLargest = -1;

	for(int i = 0; i < arr.size(); i++ ){
		if(arr[i] > largest){
			sLargest = largest;
			largest = arr[i];
		}
		else if(arr[i] < largest && arr[i] > sLargest ){
			sLargest = arr[i];
		}
	}

	return sLargest;
}

int main(){
	int n;
	cin>>n;

	vector<int> arr(n);

	for(int i = 0; i < n; i++) cin>>arr[i];

	cout<<"largest element of Array is: "<<largest(arr)<<endl;

	cout<<"largest element of Array is: "<<sLargest(arr)<<endl;

	cout<<"largest element of Array is: "<<smallest(arr)<<endl;

	cout<<"largest element of Array is: "<<sSmallest(arr)<<endl;		

	return 0;
}