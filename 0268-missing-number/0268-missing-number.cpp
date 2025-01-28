class Solution {
public:
    int missingNumber(vector<int>& nums) {
           int n = nums.size();
    int ans = n; // Assume the missing number is n initially

    for (int i = 0; i < n; i++) {
        ans ^= i ^ nums[i]; // Use XOR to find the missing number
    }
    
    return ans; // Return the missing number
    }
};