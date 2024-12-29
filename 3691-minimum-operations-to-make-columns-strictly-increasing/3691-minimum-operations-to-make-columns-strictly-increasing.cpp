class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
      int m = grid.size();
    int n = grid[0].size();
    int operations = 0;

    // Iterate through each column
    for (int j = 0; j < n; ++j) {
        for (int i = 1; i < m; ++i) {
            // If the current element is not greater than the previous one
            if (grid[i][j] <= grid[i - 1][j]) {
                // Calculate the number of increments needed
                int increment = grid[i - 1][j] - grid[i][j] + 1;
                operations += increment;
                // Update the current element
                grid[i][j] += increment;
            }
        }
    }

    return operations;  
    }
};