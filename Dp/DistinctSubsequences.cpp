class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<unsigned long long>>a(s.length()+1,vector<unsigned long long>(t.length()+1,0));
        for(int i=0;i<=s.length();i++){
            a[i][0]=1;// empty t
        }
        for(int j=1;j<=t.length();j++){
            a[0][j]=0;  //non empty t from empty s
        }
        for(int i=1;i<=s.length();i++){
            for(int j=1;j<=t.length();j++){
                if(s[i-1]==t[j-1]){
                    a[i][j]=a[i-1][j-1]+a[i-1][j];
                }
                else{
                    a[i][j]=a[i-1][j];
                }
            }
        }
        return a[s.length()][t.length()];
    }
};
