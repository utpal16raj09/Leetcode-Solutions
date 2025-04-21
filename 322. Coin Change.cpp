class Solution {
public:
    int solve(vector<int>& coins, int amount, vector<int>& dp) {
        if (amount == 0) return 0;
        if (amount < 0) return 1e9;
        if (dp[amount] != -1) return dp[amount];

        int mini = 1e9;
        for (int i = 0; i < coins.size(); i++) {
            int res = solve(coins, amount - coins[i], dp);
            if (res != 1e9) {
                mini = min(mini, res + 1);
            }
        }

        return dp[amount] = mini;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        int ans = solve(coins, amount, dp);
        if(ans == 1e9)
            return -1;
        else
            return ans;
    }
};
