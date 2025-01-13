class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
     int n = nums.size();
     unordered_map<int,int>mp;
     for(int i=0; i<n; i++){
        mp[nums[i]]++;
     }
     priority_queue<pair<int,int>>pq;
     for(auto it: mp){
        pq.push({it.second, it.first});
     }
     vector<int>ans;
     while(!pq.empty() && k>0){
        auto ele = pq.top();
        pq.pop();
        ans.push_back(ele.second);
        k--;
     }
     return ans;

    }
};
// Time Complexity
// Each insertion into the priority queue takes O(log m) time, where m is the number of unique elements.
// In the worst case, if all elements are unique, m can be n.
// Time Complexity: O(m log m) → O(n log n) in the worst case.

// Extracting Top K Elements:

// The while loop runs k times, and each pop operation from the priority queue takes O(log m) time.
// Time Complexity: O(k log m) → O(k log n) in the worst case.

// Overall Time Complexity
// Combining all parts:

// Total Time Complexity: O(n + n log n + k log n) → O(n log n) since n log n dominates.