#include<bits/stdc++.h>
using namespace std;

vector<int> union_UsingSet(vector<int> &n, vector<int> &m){

	set<int> st;

	for(int i = 0; i < n.size();i++){
		st.insert(n[i]);
	}

	for(int j = 0; j < m.size();j++){
		st.insert(m[j]);
	}

	vector<int> unionArr(st.size());
	int i = 0;
	for(auto it:st){
		unionArr[i++] = it;
	}

	return unionArr;
}

vector<int> union_UsingMap(vector<int> &n, vector<int> &m){

	map<int, int> mpp;

	for(int i = 0; i < n.size();i++){
		mpp[n[i]]++;
	}

	for(int i = 0; i < m.size();i++){
		mpp[m[i]]++;
	}

	vector<int> unionArr;
	for(auto it:mpp){
		unionArr.push_back(it.first);
	}

	return unionArr;
}


vector<int> union_UsingTwoPointerOptimal(vector<int> &n, vector<int> &m){
	int n1 = n.size();
	int n2 = m.size();
	int i = 0;
	int j = 0;

	vector<int> unionArr;

	while(i<n1 && j<n2){
		if(n[i]<=m[j]){
			if(unionArr.size() == 0 || unionArr.back() != n[i]){
				unionArr.push_back(n[i]);
			}
			i++;
		}
		else{
			if(unionArr.size() == 0 || unionArr.back() != m[j]){
				unionArr.push_back(m[j]);
			}
			j++;
		}
	}

	while(i<n1){
		if(unionArr.size() == 0 || unionArr.back() != n[i]){
				unionArr.push_back(n[i]);
		}
		i++;
	}

	while(j<n2){
		if(unionArr.size() == 0 || unionArr.back() != m[j]){
				unionArr.push_back(m[j]);
		}
		j++;
	}

	return unionArr;
}

vector<int> intersectionOfArr(vector<int> &n, vector<int> &m){

	vector<int> intersectionArr;

	vector<int> vis(m.size(),0);

	for(int i = 0; i < n.size(); i++){
		for(int j = 0; j < m.size(); j++){
			if(n[i] == m[j] && vis[j] == 0){
				intersectionArr.push_back(n[i]);
				vis[j] = 1;
				break;
			}

			if(m[j] > n[i]) break;
		}
	}

	return intersectionArr;
}

vector<int> intersectionOfArr_Optimal(vector<int> &A, vector<int> &B){
	int n = A.size();
	int m = B.size();

	int i = 0;
	int j = 0;

	vector<int> intersectionArr;

	while(i < n && j < m){
		if(A[i] < B[j]){
			i++;
		}
		else if(B[j] < A[i]){
			j++;
		}
		else{
			intersectionArr.push_back(A[i]);
			i++;
			j++;
		}
	}

	return intersectionArr;
}


int main(){

	int n;
	cin>>n;

	vector<int> arr1(n);
	for(int i = 0; i < n; i++){
		cin>>arr1[i];
	}

	int m;
	cin>>m;

	vector<int> arr2(m);
	for(int i = 0; i < m; i++){
		cin>>arr2[i];
	}

	vector<int> result = union_UsingTwoPointerOptimal(arr1,arr2);

	cout<<"Union of 2 Arrays is: ";

	for(int i=0; i < result.size();i++){
		cout<<result[i]<<" ";
	}
	cout<<endl;

	vector<int> result1 = intersectionOfArr_Optimal(arr1,arr2);

	cout<<"Intersection of 2 Arrays is: ";

	for(int i=0; i < result1.size();i++){
		cout<<result1[i]<<" ";
	}

}