class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>a(text1.length()+1,vector<int>(text2.length()+1,0));
        for(int i=0;i<text1.length();i++){
            a[i][0]=0;
        }
        for(int j=0;j<text2.length();j++){
            a[0][j]=0;
        }
        for(int i=1;i<=text1.length();i++){
            for(int j=1;j<=text2.length();j++){
                if(text1[i-1]==text2[j-1]){
                    a[i][j]=1+a[i-1][j-1];
                }
                else{
                    a[i][j]=max(a[i-1][j],a[i][j-1]);
                }
            }
        }
        return a[text1.length()][text2.length()]; 
    }
};
