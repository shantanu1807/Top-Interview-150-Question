class Solution {
public:
    int mySqrt(int x) {
        int l=1;
        int r = x;
        int ans = 0;
        while(l<=r){
          long long  int mid = l+(r-l)/2;
            long long mid_sqr = mid*mid;

            if(mid_sqr>x){
                r = mid-1;
            }
            else {
                ans = mid;
                l = mid+1;
            }
        }
        return ans;
    }
};