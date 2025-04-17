#include <bits/stdc++.h>
using namespace std;

vector<int> brute_rearrageElements(vector<int> &arr){
	vector<int> neg,pos;

	for(int i = 0; i < arr.size(); i++){
		if(arr[i] < 0){
			neg.push_back(arr[i]);
		}
		else{
			pos.push_back(arr[i]);
		}
	}

	for(int i = 0; i < neg.size();i++){
		arr[2*i] = pos[i];
		arr[2*i+1] = neg[i];
	}

	return arr;
}

vector<int> optimal_rearrangeElements(vector<int> &arr){
	int n = arr.size();

	vector<int> ans(n,0);
	int posIdx = 0, negIdx = 1;

	for(int i = 0; i < arr.size(); i++){
		if(arr[i] < 0){
			ans[negIdx] = arr[i];
			negIdx += 2;
		}
		else{
			ans[posIdx] = arr[i];
			posIdx += 2; 
		}
	}

	return ans;
}

vector<int> optimal_rearrangeElementsSizeIsDiff(vector<int> &arr){
	vector<int> neg,pos;
	int n = arr.size();

	for(int i = 0; i < n; i++){
		if(arr[i] > 0){
			pos.push_back(arr[i]);
		}
		else{
			neg.push_back(arr[i]);
		}
	}

	if(pos.size() > neg.size()){
		for(int i = 0; i < neg.size(); i++){
			arr[2*i] = pos[i];
			arr[2*i+1] = neg[i];
		}

		int index = neg.size() * 2;
		for(int i = neg.size(); i < pos.size(); i++){
			arr[index] = pos[i];
			index++;
		}
	}else{
		for(int i = 0; i < pos.size(); i++){
			arr[2*i] = pos[i];
			arr[2*i+1] = neg[i];
		}

		int index = pos.size() * 2;
		for(int i = pos.size(); i < neg.size(); i++){
			arr[index] = neg[i];
			index++;
		}
	}
	return arr;
}
int main(){
	int n;
	cin>>n;

	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}

	vector<int> ans = optimal_rearrangeElementsSizeIsDiff(arr);

	cout<<"After arranging array as expected: "<<endl;

	for(int i = 0; i < n; i++){
		cout<<ans[i]<<" ";
	}
}