#include<iostream>
using namespace std;
string lcs(string s1,string s2,int x,int y){
    int dp[x+1][y+1];
    for(int i=0;i<=x;i++){
        for(int j=0;j<=y;j++){
            if(i==0 || j==0)dp[i][j]=0;
            else if(s1[i-1]==s2[j-1])dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    //return dp[x][y];
    string result="";
    int i=x,j=y;
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            result=s1[i-1]+result;
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])i--;
        else j--;
    }
    return result;
}
int main(){
    string s1="absdsc";
    string s2="acdsc";
    int x=s1.length();
    int y=s2.length();
    cout<<"the longest common sequence "<<lcs(s1,s2,x,y);
    return 0;
}