class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int count =0;
        int  i =0;
      int start = 1;
      while(count<k){
        if(i<arr.size() && arr[i] == start){
            i++;
        }
        else {
            count++;
            if(count == k){
                return start;
            }
        }
        start++;
      }
      return -1;
    }
};