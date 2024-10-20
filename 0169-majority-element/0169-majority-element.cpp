class Solution {
public:
    int majorityElement(vector<int>& nums) {
          int n = nums.size();
    int cnt = n / 2;
    int ans = 0;
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++) {
        mp[nums[i]]++;
    }

    for (auto x : mp) {
        if (x.second > cnt) {
            ans = x.first; 
           
            break; 
        }
    }

    return ans;
    }
};