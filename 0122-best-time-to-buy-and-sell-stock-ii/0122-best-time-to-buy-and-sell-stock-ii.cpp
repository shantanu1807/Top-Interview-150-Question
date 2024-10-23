// class Solution {
// public:
//      int solve(int ind, int buy, vector<int>&price,vector<vector<int>>&dp){
//         if(ind==price.size()){
//             return 0;
//         }
//         int profit=0;
//         if(dp[ind][buy]!= -1){
//             return dp[ind][buy];
//         }
//         if(buy){
//             int buykaro = -price[ind]+solve(ind+1,0 ,price, dp);
//             int skipkaro = 0+ solve(ind+1, 1, price,dp);
//             profit = max(buykaro,skipkaro);
//         }
//         else{
//             int sellkaro = price[ind]+solve(ind+1, 1, price ,dp);
//             int skipkaro = 0+solve(ind+1,0, price,dp);

//             profit = max(sellkaro, skipkaro);
//         }
//         return dp[ind][buy] = profit;

//      }

//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//        vector<vector<int>>dp(n,vector<int>(2,-1));

//         return solve(0,1, prices,dp);
//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int profit = 0;

        for(int i =1; i<prices.size(); i++){
            if((prices[i] - buy) > 0){
                profit += prices[i] - buy;
            }
            buy = prices[i];
        }
        return profit;
    }
};