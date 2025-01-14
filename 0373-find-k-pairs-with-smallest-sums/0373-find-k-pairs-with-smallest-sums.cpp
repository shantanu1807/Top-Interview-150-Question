class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        priority_queue<P, vector<P>, greater<P>> pq; //min-heap
        
        set<pair<int, int>> visited;
        visited.insert({0, 0});
        
        int sum = nums1[0] + nums2[0];
        
        pq.push({sum, {0, 0}});
        
        vector<vector<int>> result;
        while(k-- && !pq.empty()) {
            
            auto temp = pq.top(); 
            pq.pop();
            
            int i = temp.second.first;
            int j = temp.second.second;
            result.push_back({nums1[i], nums2[j]});
            
            //Push (i, j+1) if possible
             if (j + 1 < n && visited.find({i, j + 1}) == visited.end()) {
                pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
                visited.insert({i, j + 1});
            }

            //Push (i+1, j) if possible
            if (i + 1 < m && visited.find({i + 1, j}) == visited.end()) {
                pq.push({nums1[i + 1] + nums2[j], {i + 1, j}});
                visited.insert({i + 1, j});
            }
            
        }
        
        return result;
    }
};


// class Solution {
// public:
// vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
// vector<vector<int>> ans;
// priority_queue<pair<int, pair<int, int>>> pq; // max-heap to store the k smallest pairs
//     for (int i = 0; i < nums1.size(); i++) {
//         for (int j = 0; j < nums2.size(); j++) {
//             int sum = nums1[i] + nums2[j];

//             // If the priority queue size is less than k, add the pair
//             if (pq.size() < k)
//                 pq.push({sum, {nums1[i], nums2[j]}});
//             else if (sum < pq.top().first) {
//                 // If the current sum is smaller than the largest sum in the priority queue,
//                 // remove the largest sum and add the current sum
//                 pq.pop();
//                 pq.push({sum, {nums1[i], nums2[j]}});
//             } else if (sum > pq.top().first) {
//                 // If the current sum is larger than the largest sum in the priority queue,
//                 // break the inner loop since sums will only increase from this point onwards
//                 break;
//             }
//         }
//     }

//     // Retrieve the k smallest pairs from the priority queue and store them in the answer vector
//     while (!pq.empty()) {
//         ans.push_back({pq.top().second.first, pq.top().second.second});
//         pq.pop();
//     }

//     return ans;
// }
// };