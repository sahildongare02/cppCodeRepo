#include <bits/stdc++.h>
using namespace std;

void markRow(vector<vector<int>> &matrix,int i,int m){
	for(int j = 0; j < m; j++){
		if(matrix[i][j] != 0){
			matrix[i][j] = -1;
		}
	}
}

void markCol(vector<vector<int>> &matrix,int j,int n){
	for(int i = 0; i < n; i++){
		if(matrix[i][j] != 0){
			matrix[i][j] = -1;
		}
	}
}

vector<vector<int>> brute_setMartixZero(vector<vector<int>> &matrix,int n, int m){

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(matrix[i][j] == 0){
				markRow(matrix,i,m);
				markCol(matrix,j,n);
			}
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(matrix[i][j] == -1){
				matrix[i][j] = 0;
			}
		}
	}

	return matrix;
}

vector<vector<int>> better_setMartixZero(vector<vector<int>> &matrix, int n, int m){
	vector<int> rows(n,0);
	vector<int> cols(m,0);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(matrix[i][j] == 0){
				rows[i] = 1;
				cols[j] = 1;
			}
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(rows[i] || cols[j] ){
				matrix[i][j] = 0;
			}
		}
	}

	return matrix;
}

vector<vector<int>> optimal_setMartixZero(vector<vector<int>> &matrix, int n, int m){
	int col0 = 1;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(matrix[i][j] == 0) {
				matrix[i][0] = 0;

				if(j != 0){
					matrix[0][j] = 0;
				}
				else{
					col0 = 0;
				}
			}
		}
	}

	for(int i = 1; i < n; i++){
		for(int j = 1; j < m; j++){
			if(matrix[i][j] != 0 ){
				if(matrix[i][0] == 0 || matrix[0][j] == 0){
					matrix[i][j] = 0; 
				}
			}
		}
	}

	if(matrix[0][0] == 0){
		for(int j = 0; j < m; j++){
			matrix[0][j] = 0;
		}
	}

	if(col0 == 0){
		for(int i = 0; i < n; i++){
			matrix[i][0] = 0;
		}
	}

	return matrix;
}

int main(){
	int rows,cols;
	cin>>rows>>cols;

	vector<vector<int>> matrix(rows,vector<int>(cols));
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			cin>>matrix[i][j];
		}
	}

	vector<vector<int>> ans=optimal_setMartixZero(matrix,rows,cols);

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}

	
	return 0;
}