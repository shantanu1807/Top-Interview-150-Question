// class Solution {
// public:
//     int findKthPositive(vector<int>& arr, int k) {
//         int count =0;
//         int ans =0;
//         int  i =0;
//       int start = 1;
//       while(count<k){
//         if(i<arr.size() && arr[i] == start){
//             i++;
//         }
//         else {
//             count++;
//             if(count == k){
//                 ans =  start;
//             }
//         }
//         start++;
//       }
//       return ans;
//     }
// };

class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int n = nums.size();
        int  l=0;
        int r = n-1;
        int  mid = -1;
        while(l<=r){
            int mid = l+(r-l)/2;
            int kitna_missing_hai_till_mid = nums[mid] - (mid+1);
            if(kitna_missing_hai_till_mid<k){
                l = mid+1;
            }
            else{
                r= mid-1;
            }
        }
      return l+k;
    }
};