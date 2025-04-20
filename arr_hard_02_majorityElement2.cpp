
#include <bits/stdc++.h>
using namespace std;

vector<int> brute_findMajority2(vector<int> &nums) {
    vector<int> ans;

    for(int i = 0; i < nums.size(); i++) {
        if(find(ans.begin(), ans.end(), nums[i]) == ans.end()) {
            int cnt = 0;

            for(int j = 0; j < nums.size(); j++) {
                if(nums[j] == nums[i]) {
                    cnt++;
                }
            }

            if(cnt > nums.size() / 3) {
                ans.push_back(nums[i]);
            }
        }

        if(ans.size() == 2) break; 
    }

    return ans;
}

vector<int> better_findMajority2(vector<int> &nums){

    unordered_map<int,int> mpp;
    vector<int> ans;

    int mini = nums.size() / 3;

    for(int i = 0; i < nums.size(); i++){
        mpp[nums[i]]++;

        if(mpp[nums[i]] > mini){
            ans.push_back(nums[i]);
        }
    }

    return ans;
}


vector<int> optimal_findMajority2(vector<int>& nums) {
    int cnt1 = 0, cnt2 = 0;
    int el1 = INT_MIN;
    int el2 = INT_MIN;

    for (int i = 0; i < nums.size(); i++) {
        if (cnt1 == 0 && nums[i] != el2) {
            cnt1 = 1;
            el1 = nums[i];
        }
        else if (cnt2 == 0 && nums[i] != el1) {
            cnt2 = 1;
            el2 = nums[i];
        }
        else if (el1 == nums[i]) {cnt1++;}
        else if (el2 == nums[i]) {cnt2++;}
        else {
            cnt1--;
            cnt2--;
        }
    }
    vector<int> ls;
    cnt1 = 0, cnt2 = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (el1 == nums[i]) cnt1++;
        if (el2 == nums[i]) cnt2++;
    }

    int mini = (int)(nums.size() / 3) + 1;

    if (cnt1 >= mini) {
        ls.push_back(el1);
    }

    if (cnt2 >= mini) {
        ls.push_back(el2);
    }

    sort(ls.begin(), ls.end());

    return ls;
}



int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    vector<int> result = better_findMajority2(arr);

    cout<<"Majority elements which are n/3 are:"<<endl;
    for(auto it: result){
        cout<<it<<" ";
    }

    return 0;
} 