#include <bits/stdc++.h>
using namespace std;
//lower case
/*
int main(){
	string s;
	cin>>s;

	int hash[26] = {0};
	for(int i = 0; i < s.size(); i++){
		 hash[s[i] - 'a']++;
	}

	int q;
	cin>>q;

	while(q--){
		char ch;
		cin>>ch;

		cout<<hash[ch - 'a']<<endl;
	}
}
*/
int main(){
	string s;
	cin>>s;

	int hash[256] = {0};
	for(int i = 0; i<s.size(); i++){
		hash[s[i]]++;
	}

	int q;
	cin>>q;

	while(q--){
		char ch;
		cin>>ch;
		cout<<hash[ch]<<endl;
	}
}