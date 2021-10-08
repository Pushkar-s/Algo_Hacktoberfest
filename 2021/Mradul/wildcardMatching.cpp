class Solution {
public:
    bool isMatch(string s, string p) {
        
        
//        vector<bool> dp(s.size()+1, vector<bool> (p.size()+1));
        
        bool dp[2001][2001];
        
        for(int i = 0; i<s.size()+1; i++)
        {
            for(int j = 0; j<p.size()+1; j++)
            {
                if(i==0 or j==0)
                {
                    if(i==j)
                        dp[i][j] = true;
                    else if(j==0)
                        dp[i][j] = false;
                    else {
                        if(p[j-1]=='*')
                            dp[i][j] = dp[i][j-1];
                        else dp[i][j] = false;
                    }
                }
                else 
                {
                    if(s[i-1]==p[j-1] or p[j-1]=='?')
                        dp[i][j] = dp[i-1][j-1];
                    else if(p[j-1]=='*')
                        dp[i][j] = dp[i-1][j] or dp[i][j-1];
                    else 
                    {
                        dp[i][j] = false;
                    }
                }
            }
        }
        return dp[s.size()][p.size()];
            
    }
};
