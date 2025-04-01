#include<bits/stdc++.h>
using namespace std;

/*
void rotateArrBy1Place(vector<int> &arr, int n){

	int temp = arr[0];
	for(int i = 1; i < n; i++){
		arr[i-1] = arr[i];
	}

	arr[n-1] = temp;

	for(int i = 0; i < n; i++) cout<<arr[i]<<" ";
}
*/


//brute force approcah
/*
void rotateArrByKPlaces(vector<int> &arr, int n, int k){

	k = k % n;
	vector<int> temp;

	for(int i = 0; i < k; i++){
		temp.push_back(arr[i]);
	}

	for(int i = k; i < n; i++){
		arr[i-k] = arr[i];
	}

	for(int i = n - k; i < n; i++){
		arr[i] = temp[i - (n-k)];
	}

	for(int i = 0; i < n; i++) cout<<arr[i]<<" ";

}
*/

void rotateArrByKPlaces(vector<int> &arr, int n, int k){
	k = k % n;

	reverse(arr.begin(), arr.begin()+k);
	reverse(arr.begin()+k,arr.end());
	reverse(arr.begin(),arr.end());

	for(int i = 0; i < n; i++) cout<<arr[i]<<" ";
}

int main(){

	int n;

	cin>>n;

	vector<int> arr(n);

	for(int i = 0; i < n; i++) cin>>arr[i];

	int k;
	cin>>k;	


	//rotateArrBy1Place(arr,n);	

	rotateArrByKPlaces(arr,n,k);
}