class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>>a(s.length()+1,vector<bool>(p.length()+1,false));
        a[0][0]=true;
        for(int j = 1; j <= p.length(); j++) {
            if(p[j-1] == '*')
        a[0][j] = a[0][j-1];
        }
        for(int i=1;i<=s.length();i++){
            for(int j=1;j<=p.length();j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?')
                  a[i][j]=a[i-1][j-1];
                else if(p[j-1]=='*')
                  a[i][j]=a[i-1][j] || a[i][j-1];
            }
        }
        return a[s.length()][p.length()];
    }
};
