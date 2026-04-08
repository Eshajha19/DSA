// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;
void update(int i, int l, int r, int st, int end, int val,
            vector<int>& segment, vector<int>& lazy) {
    if(lazy[i]!=0){
        segment[i]+=(r-l+1)*lazy[i];
        if(l!=r){
        lazy[2*i+1]+=val;
        lazy[2*i+2]+=val;
        }
        lazy[i]=0;
    }
    if(end<l || r<st)
        return ;
    if(st<=l && end>=r){
        segment[i]+=(r-l+1)*val;
        if(l!=r){
        lazy[2*i+1]+=val;
        lazy[2*i+2]+=val;
        }
        return ;
    }
    int mid=(r+l)/2;
    
    update(2*i+1,l,mid,st,end,val,segment,lazy);
    update(2*i+2,mid+1,r,st,end,val,segment,lazy);
    
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
    vector<int>lazy(4*n);
    buildsegment(0,0,n-1,segment,a);
    for(int i=0;i<4*n;i++){
        cout<<segment[i]<<" ";
    }
    update(0, 0, n-1, 2, 5, 3, segment, lazy);
    cout<<"\n";
    for(int i=0;i<4*n;i++){
        cout<<segment[i]<<" ";
    }
    cout<<endl;
    update(0, 0, n-1, 0, 2, 1, segment, lazy);
    for(int i=0;i<4*n;i++){
        cout<<segment[i]<<" ";
    }
}
