class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        set<int>st;
        int mn = INT_MAX;
        for(int i=0; i<nums2.size(); i++){
            st.insert(nums2[i]);
        }

        for(int j=0; j<nums1.size(); j++){
           auto it = st.find(nums1[j]);
           
           if(it != st.end()){
            mn = min(mn, nums1[j]);          
             }
        }
        if(mn == INT_MAX){
            return -1;
        }
        return mn;
    }
};