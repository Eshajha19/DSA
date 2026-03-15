class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>>c(s.length()+1,vector<int>(s.length()+1,0));
        for(int i=0;i<=s.length();i++){
            c[i][0]=0;
        }
        for(int j=0;j<=s.length();j++){
            c[0][j]=0;
        }
        string r=s;
        reverse(r.begin(),r.end());
        for(int i=1;i<=s.length();i++){
            for(int j=1;j<=r.length();j++){
                if(s[i-1]==r[j-1])
                  c[i][j]=1+c[i-1][j-1];
                else
                  c[i][j]=max(c[i-1][j],c[i][j-1]);
            }
        }
        return c[s.length()][s.length()];
    }
};
