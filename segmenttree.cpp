// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;
int query(int st,int end,int l,int r,int i,vector<int>&segment){
    if(l>end || r<st)
      return 0;
    if(st<=l && l>=r)
      return segment[i];
    int mid=l+(r-l)/2;
    return query(st,end,l,mid,2*i+1,segment)+query(st,end,mid+1,r,2*i+2,segment);
}
void updatesegment(int i,int idx,int val,int l,int r,vector<int>&segment){
    if(l==r){
        segment[i]=val;
        return;
    }
    int mid=(r+l)/2;
    if(idx<=mid){
        updatesegment(2*i+1,idx,val,l,mid,segment);
    }
    else{
        updatesegment(2*i+2,idx,val,mid+1,r,segment);
    }
    segment[i]=segment[2*i+1]+segment[2*i+2];
}
void buildsegment(int i,int l,int r,vector<int>&segment,vector<int>&arr){
    if(l==r){
        segment[i]=arr[l];
        return ;
    }
    int mid=(l+r)/2;
    buildsegment(2*i+1,l,mid,segment,arr);
    buildsegment(2*i+2,mid+1,r,segment,arr);
    segment[i]=segment[2*i+1]+segment[2*i+2];
}
int main() {
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        int b;
        cin>>b;
        a[i]=b;
    }
    vector<int>segment(4*n);
    buildsegment(0,0,n-1,segment,a);
    for(int i=0;i<4*n;i++){
        cout<<segment[i]<<" ";
    }
    updatesegment(0,3,8,0,n-1,segment);
    cout<<"\n";
    for(int i=0;i<4*n;i++){
        cout<<segment[i]<<" ";
    }
    int m=query(1,4,0,n-1,0,segment);
    cout<<"endl"<<m;
}
