class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();    // Number of rows
        int n = matrix[0].size(); // Number of columns
        int col0 = 1;  // Track if first column should be zero

        // Step 1: Mark rows and columns that should be zero
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) col0 = 0;  // Track first column separately
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    // Mark ith row
                    matrix[i][0] = 0;
                    // Mark jth col
                    matrix[0][j] = 0;
                }
            }
        }

        // Step 2: Use markers to update matrix (ignoring first row/column)
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Now solve for 0th row and 0th column that was marked

        // Step 3: Handle first row separately
        if (matrix[0][0] == 0) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }

        // Step 4: Handle first column separately
        if (col0 == 0) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};