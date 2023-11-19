#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"


signed main(){
    vector<vector<int>>v;
    cout<<"enter the no. of process : ";
    int n;cin>>n;
    int mn=INT_MAX;
    int mx=INT_MIN;
    cout<<"enter the arival ,burst time and priority : "<<endl;
    for(int i=0;i<n;i++){
        vector<int>v1;
        // a is arival time
        //b is brust time
        // p is priority time
        int a,b,p;cin>>a>>b>>p;
        v1.push_back(a);
        
        v1.push_back(b);
        v1.push_back(p);
        
        // v1.push_back(i);
        v.push_back(v1);
        mn=min(mn,a);
        mx=max(mx,a);
    }
    vector<vector<int>>ms;
    vector<int>ct;
    for(int i=0;i<n;i++) ct.push_back(0);
    for(int i=0;i<n;i++){
        vector<int>m;
        ct.push_back(0);
        if(v[i][0]==0){
            m.push_back(-1*v[i][2]);
            m.push_back(v[i][0]);
            m.push_back(i);
            ms.push_back(m);
        }
    }
    vector<int>red;
    // multiset<int>ms;
    int r=0; // current time
    // vector<int>g;
    while(true){
        if(red.size()==n){
            break;
        }
        if(ms.size()==0){
            r++;
            for(int i=0;i<n;i++){
                if(v[i][0]==r){
                    vector<int>m1;
                    m1.push_back(-1*v[i][2]);
                    m1.push_back(v[i][0]);
                    m1.push_back(i);
                    ms.push_back(m1);
                };
            }
        }
        else{
            sort(ms.begin(),ms.end());
            int in=ms[0][2];
            int br=v[in][1];
            ct[in]=r+br;
            red.push_back(in);
            r=r+br;
            for(int i=0;i<n;i++){
                if(v[i][0]>r-br and v[i][0]<=r){
                    vector<int>m1;
                    m1.push_back(-1*v[i][2]);
                    m1.push_back(v[i][0]);
                    m1.push_back(i);
                    ms.push_back(m1);
                }
            }
            ms.erase(ms.begin());
        }    
    }
    cout<<endl;
    cout<<"Gaint chart is : ";
    for(int i=0;i<n;i++){
        cout<<"p"<<red[i]+1<<" ";
    }
    cout<<endl;
    cout<<endl;
    // cout<<"complition time is : ";
    // for(int i=0;i<n;i++){
    //     cout<<ct[i]+1<<" ";
    // }
    // cout<<endl;
    vector<int>tat;
    for(int i=0;i<n;i++){
        tat.push_back(ct[i]-v[i][0]);
    }
    // cout<<"turn around time is : ";
    // for(auto i : tat) cout<<i<<" ";
    // cout<<endl;
    vector<int>wt;
    for(int i=0;i<n;i++){
        wt.push_back(tat[i]-v[i][1]);
    }
    // cout<<"waiting time is : ";
    // for(auto i : wt) cout<<i<<" ";
    // cout<<endl;
    for(int i=0;i<n;i++){
        v[i].push_back(ct[i]);
        v[i].push_back(tat[i]);
        v[i].push_back(wt[i]);
    }
    cout<<"id      "<<"at       "<<"bt       "<<"ct       "<<"tat      "<<"wt   "<<endl;
    for(int i=0;i<n;i++){
        cout<<i+1<<"       ";
        for(int j=0;j<5;j++) cout<<v[i][j]<<"        ";
        cout<<endl;

        
    }
    return 0;
}

