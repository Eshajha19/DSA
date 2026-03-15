class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
         string s="";
	 vector<vector<int>>a(str1.length()+1,vector<int>(str2.length()+1,0));
        for(int i=0;i<str1.length();i++){
            a[i][0]=0;
        }
        for(int j=0;j<str2.length();j++){
            a[0][j]=0;
        }
        for(int i=1;i<=str1.length();i++){
            for(int j=1;j<=str2.length();j++){
                if(str1[i-1]==str2[j-1]){
                    a[i][j]=1+a[i-1][j-1]; 
                }
                else{
                    a[i][j]=max(a[i-1][j],a[i][j-1]);
                }
            }
        }
        int i=str1.length();
        int j=str2.length();
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                i--;
                j--;
                s=s+str1[i];
            }
            else if(a[i][j-1]<a[i-1][j]){
                s.push_back(str1[i-1]);
                i--;
            }
            else{
                s.push_back(str2[j-1]);
                j--;
            }
        }
        while(i>0){
            s.push_back(str1[i-1]);
            i--;
        }
        while(j>0){
            s.push_back(str2[j-1]);
            j--;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};
