class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector<long long int> dp(n, 0);
        dp[0] = nums[0];

        for(int i = 1; i < n; i++)
        {
            long long int incl = nums[i];
            if(i > 1) incl = dp[i - 2] + nums[i];

            long long int excl = dp[i - 1];

            dp[i] = max(incl, excl);
        }
        return dp[n - 1];
    }
};
