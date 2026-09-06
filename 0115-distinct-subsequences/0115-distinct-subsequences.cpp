class Solution {
public:
    int numDistinct(string s, string t) {
        int n = t.size();

        vector<long long> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < s.size(); i++) {
            for (int j = n; j >= 1; j--) {
                if (s[i] == t[j - 1]) {
                    dp[j] = min((long long)INT_MAX,
                                dp[j] + dp[j - 1]);
                }
            }
        }

        return (int)dp[n];
    }
};