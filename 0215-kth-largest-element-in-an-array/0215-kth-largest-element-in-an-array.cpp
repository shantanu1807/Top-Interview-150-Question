class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int,vector<int>,greater<int>>minheap;
      // priority_queue<int>maxheap;
        for(int num: nums){
            minheap.push(num);
            if(minheap.size()>k){
                minheap.pop();
            }
        }
        return minheap.top();
    }
};