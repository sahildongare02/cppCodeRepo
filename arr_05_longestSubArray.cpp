#include <bits/stdc++.h>
using namespace std;

//T.C -> O(N)
//S.C -> O(1)
int brute1_lenLongestSubArray(vector<int> &arr, long long k){
	int n = arr.size();
	int len = 0;

	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			int sum = 0;
			for(int m = i; m <= j;m++){
				sum += arr[m];
			}		
			if(sum == k) {
				len = max(len, j - i + 1);
			}
		}
	}

	return len;
}

//T.C -> O(N*logN)
//S.C -> O(N )
int better_lenLongestSubArray(vector<int> &arr, long long k){

	map<long long, int> preSumMap;

	long long sum = 0;
	int maxLen = 0;

	for(int i = 0; i < arr.size(); i++){
		sum += arr[i];
		if(sum == k){
			maxLen = max(maxLen,i+1);
		}

		long long rem = sum - k;
		if(preSumMap.find(rem) != preSumMap.end()){
			int len = i - preSumMap[rem];
			maxLen = max(maxLen,len);
		}
		if(preSumMap.find(sum) == preSumMap.end()){
			preSumMap[sum] = i;
		}
	}
	return maxLen;
}

int optimal_lenLongestSubArray2Pointer(vector<int> &arr, long long k){
	int left = 0, right = 0;
	long long sum = arr[0];

	int maxLen = 0;
	int n = arr.size();

	while(right < n){
		while(left <= right && sum > k){
			sum -= arr[left];
			left++;
		}

		if(sum == k){
			maxLen = max(maxLen, right - left + 1);
		}
		right++;

		if(right < n) {
			sum += arr[right];
		}
	}

	return maxLen; 
}


int main(){
	int n;
	cin>>n;

	int k;
	cin>>k;

	vector<int> arr(n);

	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}

	

	cout <<"longest subArray using brute is: "<<brute1_lenLongestSubArray(arr,k)<<endl;
	cout <<"longest subArray using better is: "<<better_lenLongestSubArray(arr,k)<<endl;
	cout <<"longest subArray using optimal is: "<<optimal_lenLongestSubArray2Pointer(arr,k)<<endl;

	return 0;
}