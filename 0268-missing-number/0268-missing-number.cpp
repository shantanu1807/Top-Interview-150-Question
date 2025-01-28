// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//            int n = nums.size();
//     int ans = n; // Assume the missing number is n initially

//     for (int i = 0; i < n; i++) {
//         ans ^= i ^ nums[i]; // Use XOR to find the missing number
//     }
    
//     return ans; // Return the missing number
//     }
// };


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        //case 1
        if(nums[0] != 0)return 0;
        //case 2 
        if(nums[n-1] != n)return n;
        for(int i =1;i<nums.size();i++){
            if(nums[i] != i){
            //case 3
            return i;
            }
        }
        return 0;
    }
};
