#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> brute_3Sum(vector<int> &arr, int n) {

	set<vector<int>> st;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				if (arr[i] + arr[j] + arr[k] == 0) {
					vector<int> temp = {arr[i], arr[j], arr[k]};
					sort(temp.begin(), temp.end());
					st.insert(temp);
				}
			}
		}
	}

	vector<vector<int>> ans(st.begin(), st.end());

	return ans;
}

vector<vector<int>> better_3Sum(vector<int> &arr, int n) {

	set<vector<int>> st;

	for (int i = 0; i < n; i++) {
		set<int> hashSet;
		for (int j = i + 1; j < n; j++) {
			int third = - (arr[i] + arr[j]);

			if (hashSet.find(third) != hashSet.end()) {
				vector<int> temp = {arr[i], arr[j], third};
				sort(temp.begin(), temp.end());

				st.insert(temp);
			}

			hashSet.insert(arr[j]);
		}
	}

	vector<vector<int>> ans(st.begin(), st.end());

	return ans;

}


vector<vector<int>> optimal_3Sum(vector<int> &arr, int n) {

	vector<vector<int>> ans;

	sort(arr.begin(), arr.end());

	for (int i = 0; i < n; i++) {

		if (i > 0 && arr[i] == arr[i - 1]) continue;

		int left = i + 1;
		int right = n - 1;

		while (left < right) {
			int sum = arr[i] + arr[left] + arr[right];

			if (sum < 0) {
				left++;
			}
			else if (sum > 0) {
				right--;
			}
			else {
				vector<int> temp = {arr[i], arr[left], arr[right]};

				ans.push_back(temp);
				left++;
				right--;

				while (left < right && arr[left] == arr[left - 1]) left++;
				while (left < right  && arr[right] == arr[right + 1 ]) right--;
			}
		}
	}

	return ans;

}


vector<vector<int>> optimal1_3Sum(vector<int> &arr, int n) {

	vector<vector<int>> ans;

	sort(arr.begin(), arr.end());

	for (int i = 0; i < n; i++) {

		if (i > 0 && arr[i] == arr[i - 1]) continue;

		int left = i + 1;
		int right = n - 1;

		while (left < right) {
			int sum = arr[i] + arr[left] + arr[right];

			if(sum == 0){

				ans.push_back({arr[i], arr[left], arr[right]});

				left++;
				right--;
				while (left < right && arr[left] == arr[left - 1]) left++;
				while (left < right  && arr[right] == arr[right + 1 ]) right--;

			
			}
			else if (sum < 0) {
				left++;
			}
			else{
				right--;
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
	auto ans = optimal1_3Sum(arr, n);
	printAns(ans);
	return 0;
}