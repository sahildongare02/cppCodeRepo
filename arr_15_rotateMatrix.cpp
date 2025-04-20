#include <bits/stdc++.h>
using namespace std;


//T.C -> O(n*m)
//S.C ->O(n*m)
vector<vector<int>> brute_rotateMatrix(vector<vector<int>> &matrix,int n, int m){
	vector<vector<int>> ans(n,vector<int>(m));

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			ans[j][n-i-1] = matrix[i][j];
		}
	}

	return ans;
}

vector<vector<int>> optimal_rotateMatrix(vector<vector<int>> &matrix){
	int n = matrix.size();

	for(int i = 0; i < n - 1; i++){
		for(int j = i +1; j < n; j++){
			swap(matrix[i][j],matrix[j][i]);
		}
	}

	for(int i = 0; i < n; i++){
		reverse(matrix[i].begin(),matrix[i].end());
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

	vector<vector<int>> ans=optimal_rotateMatrix(matrix);

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}

	
	return 0;
}