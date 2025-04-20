#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> brute_4Sum(vector<int> &arr, int target) {
	int n = arr.size();
	set<vector<int>> st;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				for(int l = k + 1; l < n; l++){
					long long sum = arr[i] + arr[j];
					sum += arr[k];
					sum += arr[l];
					if (sum == target) {
						vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
						sort(temp.begin(), temp.end());
						st.insert(temp);
					}
				}
			}
		}
	}

	vector<vector<int>> ans(st.begin(), st.end());

	return ans;
}


vector<vector<int>> better_4Sum(vector<int> &arr, int target) {
	int n = arr.size();
	set<vector<int>> st;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			set<int> hashSet;
			for(int k = j + 1; k < n; k++){
				long long sum = arr[i] + arr[j];
				sum += arr[k];

				int fourth = target - sum;

				if(hashSet.find(fourth) != hashSet.end()){
					vector<int> temp = {arr[i],arr[j],arr[k],fourth};
					sort(temp.begin(),temp.end());

					st.insert(temp);
				}
				hashSet.insert(arr[k]);
			}
		}
	}

	vector<vector<int>> ans(st.begin(), st.end());

	return ans;

}

vector<vector<int>> optimal_4Sum(vector<int> &nums, int target){
	int n = nums.size();

	sort(nums.begin(), nums.end());

	vector<vector<int>> ans;

	for(int i = 0; i < n; i++){
		if(i > 0 && nums[i] == nums[i - 1]) continue;
		for(int j = i + 1; j < n; j++){
			if(j > i + 1 && nums[j] == nums[j - 1]) continue;

			int k = j + 1;
			int l = n - 1;

			while(k < l){
				long long sum = nums[i] + nums[j];
				sum += nums[k];
				sum += nums[l];

				if(sum == target){
					ans.push_back({nums[i],nums[j],nums[k],nums[l]});
					k++;
					l--;

					while(k < l && nums[k] == nums[k - 1]) k++;
					while(k < l && nums[l] == nums[l + 1]) l++; 
				}
				else if(sum < target){
					k++;
				}
				else{
					l--;
				}
			}
		}
	}

	return ans;
}

void printAns(const vector<vector<int>> &ans) {
	for (const auto &row : ans) {
		for (auto x : row) {
			cout << x << " ";
		}
		cout << "\n";
	}
}


int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (auto &it : arr) {
		cin >> it;
	}

	int target;
	cin >> target;
	auto ans = optimal_4Sum(arr, target);
	printAns(ans);
	return 0;
}