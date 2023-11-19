#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
signed main(){
    cout<<"enter the number of process : ";
    int n;cin>>n;
    cout<<"quantam is : ";
    int q; cin>>q;
    vector<vector<int>>v;
    int mn=INT_MAX;
    int mx=INT_MIN;
    vector<int>dm;
    
    for(int i=0;i<n;i++){
        vector<int>v1;
        cout<<"enter the arival and brust time for  process "<<i+1<<" : ";
        int a;cin>>a;
        int b;cin>>b;
        v1.push_back(a);
        v1.push_back(b);
        dm.push_back(b);
        mn=min(mn,a);
        v.push_back(v1);
        mx=max(mx,a);
    }
    int r=mn;
    vector<int>red;
    
    for(int i=0;i<n;i++){
        if(v[i][0]==mn) red.push_back(i);
    }
    // cout<<red[0]<<endl;
    vector<int>ct;
    for(int i=0;i<n;i++){
        ct.push_back(0);
    }
    // for(auto i : red) cout<<i<<" ";
    vector<int>g;
    while(true){
        if(red.size()==0 and r>mx) break;
        if(red.size()==0){
            r+=q;
            for(int i=0;i<n;i++){
                if(v[i][0]>r-q and v[i][0]<=r) red.push_back(i);
            }
        } 
        else{
        int p=red[0];
        if(v[p][1]-q>0){
            v[p][1]-=q;
            // cout<<r<<" ";
            r+=q;
            // cout<<r<<endl;
            for(int i=0;i<n;i++){
                if(v[i][0]>r-q and v[i][0]<=r){
                    red.push_back(i);
                }
            }
            red.push_back(p);
            g.push_back(p);
            red.erase(red.begin());
        }
        else{
            
            // cout<<r<<" r ";
            r+=v[p][1];
            v[p][1]=0;
            // cout<<r<<endl;
            for(int i=0;i<n;i++){
                if(v[i][0]>r-v[p][1] and v[i][0]<=r){
                    red.push_back(i);
                }
            }
            ct[p]=r;
            g.push_back(p);
            red.erase(red.begin());
        }
        }
       
    }
    cout<<endl;
    cout<<"gaint chart is : ";
     for(auto x :g) cout<<"p"<<x+1<<" ";
        cout<<endl;
        cout<<endl;
    vector<int>tat;
    for(int i=0;i<n;i++){
        tat.push_back(ct[i]-v[i][0]);
    }
    vector<int>wt;
    for(int i=0;i<n;i++){
        wt.push_back(tat[i]-dm[i]);
    }
    for(int i=0;i<n;i++){
        v[i][1]=dm[i];
        v[i].push_back(ct[i]);
        v[i].push_back(tat[i]);
        v[i].push_back(wt[i]);
    }
    cout<<"id       "<<"at       "<<"bt       "<<"ct       "<<"tat      "<<"wt    "<<endl;
    for(int i=0;i<n;i++){
        cout<<i+1<<"         ";
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<"        ";
        }
        cout<<endl;
    }
    // cout<<"complition time is : ";
    // for(auto i : ct) cout<<i<<" ";
    // cout<<endl;
    // cout<<"Turn around time is : ";
    // for(auto i : tat) cout<<i<<" ";
    // cout<<endl;
    // cout<<"waiting time is : ";
    // for(auto i : wt) cout<<i<<" ";
    return 0;
}

