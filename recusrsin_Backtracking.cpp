#include<bits/stdc++.h>
using namespace std;

void recusionPrint1toN(int i,int n)
{
	if(i > n) return;

	cout<<i<<" ";
	recusionPrint1toN(i+1,n); 
}

void recusionPrintNto1(int i, int n){

	if(i<1) return;

	cout<<i<<" ";
	
	recusionPrintNto1(i - 1, n);

}

void recursion_BacktrackingNto1(int n){
	if(n<1) return;

	cout<<n<<" ";
	recursion_BacktrackingNto1(n - 1);
}

void recursion_Backtracking1ToN(int n){
	if(n<1) return;

	recursion_Backtracking1ToN(n - 1);
	cout<<n<<" ";
}

int functional_RecusrionSum(int n){
	if(n == 0) return 0;

	return n + functional_RecusrionSum(n - 1);
}

int recursive_Factorial(int n){
	if(n == 0) return 1;

	return n * recursive_Factorial(n-1);
}

int main(){
	int n;

	cin >> n;

	recusionPrint1toN(1,n);

	cout<<endl;

	recusionPrintNto1(n,n);
	cout<<endl;

	recursion_Backtracking1ToN(n);

	cout<<endl;
	recursion_BacktrackingNto1(n);

	cout<<endl;

	cout<<"Sum of n "<<n<<" is : "<<functional_RecusrionSum(n)<<endl;

	cout<<"Factorial of n "<<n<<" is : "<<recursive_Factorial(n)<<endl;

	return 0;
}