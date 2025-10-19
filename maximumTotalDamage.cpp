class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int, long long> mp;
        for (int x : power) mp[x] += x;

        vector<int> val;
        for (auto &p : mp) val.push_back(p.first);

        int n = val.size();
        vector<long long> dp(n, 0);
        dp[0] = mp[val[0]];

        for (int i = 1; i < n; i++) {
            long long take = mp[val[i]];
            int j = i - 1;
            while (j >= 0 && val[i] - val[j] < 3) j--;
            if (j >= 0) take += dp[j];
            dp[i] = max(dp[i - 1], take);
        }
        return dp[n - 1];
    }
};
