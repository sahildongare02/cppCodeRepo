#include <bits/stdc++.h>
using namespace std;

void reverseArr(int i, int arr[], int n){
	if(i >= n/2) return;

	swap(arr[i],arr[n - i - 1]);
	reverseArr(i+1,arr,n);
}

bool checkPalindrome(string &s, int i){
	if(i >= s.size()/2) return true;

	if(s[i] != s[s.size()-i-1]) return false;

	return checkPalindrome(s,i+1);
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0; i < n; i++) cin>>arr[i];

	reverseArr(0,arr,n);

	cout<<"After reverse : ";

	for(int i = 0; i < n; i++) cout<<arr[i]<<" ";	

	cout<<endl;

	string s;
	cin>>s;
	if(checkPalindrome(s,0)){
		cout<<"Given string is palindrome"<<endl;
	}else{
		cout<<"Given string is not palindrome"<<endl;
	}	
}