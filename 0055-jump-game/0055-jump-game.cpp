class Solution {
public:
  int t[10001];
   bool solve(int ind, int n, vector<int>&nums){
    if(ind==n-1){
        return true;
    }
    if(t[ind]!=-1){
        return t[ind];
    }

    for(int i=1; i<=nums[ind]; i++){
        if (solve(ind+i, n, nums)==true){
            return t[ind]= true;
        }
    }
    return t[ind]= false;
   }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        memset(t,-1,sizeof(t));
        return solve(0,n,nums);
    }
};