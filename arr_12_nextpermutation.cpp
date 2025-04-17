#include <bits/stdc++.h>
using namespace std;

vector<int> optimal_nextPermuation(vector<int> &arr){
	int n = arr.size();
	int index = -1;

	for(int i = n - 2; i >= 0; i--){
		if(arr[i] < arr[i+1]){
			index = i;
			break;
		}
	}

	if(index == -1){
		reverse(arr.begin(),arr.end());
	}

	for(int i = n - 1; i >= index; i--){
		if(arr[i] > arr[index]){
			swap(arr[i],arr[index]);
			break;
		}
	}

	reverse(arr.begin()+index+1,arr.end());

	return arr;
}

int main(){
	int n;
	cin>>n;

	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}

	vector<int> ans = optimal_nextPermuation(arr);

	cout<<"After arranging array as expected: "<<endl;

	for(int i = 0; i < n; i++){
		cout<<ans[i]<<" ";
	}
}