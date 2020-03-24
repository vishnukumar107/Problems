#include<iostream>
#include<unordered_set>
using namespace std;
void findminimum(string str,int cnt,int start,int &mincnt,unordered_set<string> &starr){
    if(start==str.length()){
        mincnt=min(cnt,mincnt);
        return;
    }
    for(int len=1;len<=(str.length()-start);len++){
        string substring=str.substr(start,len);
        if(starr.find(substring)!=starr.end())
            findminimum(str,cnt+1,start+len,mincnt,starr);
    }
}
int minimumspaces(string str,string arr[],int n){
    unordered_set<string> starr;
    int mincnt=INT_MAX;
    for(int i=0;i<n;i++){
        starr.insert(arr[i]);
    }
    findminimum(str,-1,0,mincnt,starr);
    return mincnt;
}
int main(){
    string str="12345";
    string arr[]={"12","123","4","5","2345","1"};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<minimumspaces(str,arr,size);
    return 0;
}