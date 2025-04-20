#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> generateNthRowOfPascalTriangle(int row) {
        vector<int> ansRow;
        long long ans = 1;
        ansRow.push_back(ans);

        for (int col = 1; col < row; col++) {
            ans = ans * (row - col);
            ans = ans / col;
            ansRow.push_back(ans);
        }

        return ansRow;
    }

    vector<vector<int>> pascalTriangle(int n) {
        vector<vector<int>> ans;

        for (int i = 1; i <= n; i++) {
            ans.push_back(generateNthRowOfPascalTriangle(i));
        }

        return ans;
    }
};

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
    Solution ob;
    auto ans = ob.pascalTriangle(n);
    printAns(ans);
    return 0;
}
