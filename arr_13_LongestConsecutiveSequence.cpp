#include <bits/stdc++.h>
using namespace std;

bool linearSerach(vector<int> arr, int num){
	for(auto it:arr){
		if(it == num){
			return true;
		}
	}

	return false;
}
int brute_longestConsecutiveSequence(vector<int> &arr){
	if(arr.size() == 0) return 0;
	int longest = 1;

	for(int i = 0; i < arr.size(); i++){
		int x = arr[i];
		int cnt = 1;


		while(linearSerach(arr,x+1) == true){
			x = x + 1;
			cnt++;
		}
		longest = max(longest,cnt);
	}


	return longest;
}

int better_longestConsecutiveSequence(vector<int> &arr){
	if(arr.size() == 0) return 0;

	sort(arr.begin(),arr.end());

	int longest = 1; 
	int smallest = INT_MIN;
	int cnt = 0;

	for(int i = 0; i < arr.size(); i++){
		if(arr[i] - 1 == smallest){
			cnt++;
			smallest = arr[i];
		}	
		else if(arr[i] != smallest){
			cnt = 1;
			smallest = arr[i];
		}
		longest = max(longest,cnt);
	}

	return longest;
}

int optimal_longestConsecutiveSequence(vector<int> arr){
	if(arr.size() == 0) return 0;

	unordered_set<int> st;

	int longest = 1;

	for(auto val:arr){
		st.insert(val);
	}

	for(auto it:st){
		if(st.find(it - 1) == st.end()){
			int cnt = 1;
			int small = it;

			while(st.find(small+1) != st.end()){
				small = small + 1;
				cnt++;
			}

			longest = max(longest,cnt);
		}
	}

	return longest;
}


int main(){
	int n;
	cin>>n;

	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}


	cout<<"Longest consecutive sequence using brute is: "<<brute_longestConsecutiveSequence(arr)<<endl;
	cout<<"Longest consecutive sequence using better is: "<<better_longestConsecutiveSequence(arr)<<endl;
	cout<<"Longest consecutive sequence using optimal is: "<<optimal_longestConsecutiveSequence(arr)<<endl;

	return 0;
}