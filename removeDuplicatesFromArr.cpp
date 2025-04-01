#include <bits/stdc++.h>
using namespace std;


//brute force
/*
int removeDuplicates(vector<int> &arr, int n){

	set<int> s;

	for(int x: arr){
		s.insert(x);
	}

	// for(int x: s){
	// 	cout<<x<<" ";
	// }

	int value =s.size();

	return value;
}
*/

//optimal - 2 pointer approcah

int removeDuplicates(vector<int> &arr, int n){

	int i = 0;

	for(int j = 1; j < n; j++){
		if(arr[j] != arr[i]){
			arr[i+1] = arr[j];
			i++;
		}
	}

	return i+1;
}


int main(){

	int n;
	cin>>n;

	vector<int> arr(n);

	for(int i = 0; i < n; i++) cin>>arr[i];

	cout<<"No of unique elements: "<<removeDuplicates(arr,n)<<endl;;	
}