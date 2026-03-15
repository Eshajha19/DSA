class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>>a(s.length()+1,vector<int>(t.length()+1,0));
        for(int i=0;i<=s.length();i++){
            a[i][0]=0;
        }
        for(int j=0;j<=t.length();j++){
            a[0][j]=0;
        }
        for(int i=1;i<=s.length();i++){
            for(int j=1;j<t.length();j++){
                if(s[i-1]==t[j-1])
                  a[i][j]=1+a[i-1][j-1];
                else
                  a[i][j]=max(a[i-1][j],a[i][j-1]);
            }
        }
        string b="";
        int i=s.length();
        int j=t.length();
        while(i>0 && j>0){
            if(s[i-1]==t[j-1]){
                b=b+s[i-1];
                i--;
                j--;
            }
            else if(a[i-1][j]>a[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
        reverse(b.begin(),b.end());
        cout<<b;
        if(s==b)
          return true;
        else
          return false;
    }
};
