#include<iostream>
using namespace std;
string scs(string s1,string s2,int x,int y){
    int dp[x+1][y+1];
    for(int i=0;i<=x;i++){
        for(int j=0;j<=y;j++){
            if(!i)dp[i][j]=j;
            else if(!j)dp[i][j]=i;
            else if(s1[x-1]==s2[y-1])dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
        }
    }
    string result="";
    int i=x,j=y;
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            result=s1[i-1]+result;
            i--;j--;
        }
        else if(dp[i-1][j]<dp[i][j-1]){
            result=s1[i-1]+result;
            i--;
        }
        else{
            result=s2[j-1]+result;
            j--;
        }
    }
    while(i>0){
        result=s1[i-1]+result;
        i--;
    }
    while(j>0){
        result=s2[j-1]+result;
        j--;
    }
    return result;
}
int main(){
    string s1="absdsc";
    string s2="acdsc";
    int x=s1.length();
    int y=s2.length();
    cout<<"the shortest common string "<<scs(s1,s2,x,y);
    return 0;
}