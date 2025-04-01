#include<bits/stdc++.h>
using namespace std;

void swap_1(int &num1, int &num2){
	int temp = num2;
	num2 = num1;
	num1 = temp;
}

void bubble_sort(int arr[], int n){

	for(int i = n - 1; i >= 1; i--){

		for(int j = 0; j <= i - 1; j++){
			if(arr[j]> arr[j+1]){
				swap_1(arr[j],arr[j+1]);
			}
		}
	}
}

void selection_sort(int arr[], int n){

	for(int i = 0; i <= n-2; i++){
		int mini = i;

		for(int j = i; j <= n-1; j++){
			if(arr[j] < arr[mini]){
				mini = j;
			}
			swap_1(arr[i],arr[mini]);
			// int temp = arr[i];
			// arr[i] = arr[mini];
			// arr[mini] = temp; 
		}
	}
}

void insertion_sort(int arr[], int n){

	for(int i = 0 ; i < n; i++){
		int j = i;

		while(j>0 && (arr[j-1]>arr[j])){
			swap_1(arr[j-1],arr[j]);
			j--;
		}
	}
}

int main(){

	int n;
	cin>>n;

	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];

	//selection_sort(arr,n);	

	//bubble_sort(arr,n);

	insertion_sort(arr,n);	

	for(int i = 0 ; i < n; i++) cout<<arr[i]<<" ";	
}