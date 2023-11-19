#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
// bool comp(vector<int>v, vector<int>v2)
// {
//     if(v[0]>v2[0]) return false;
//     else if(v[0]==v2[0]){
//         if(v[1]==v2[1]){
//             if(v[2]==v2[2]){
//                 return v[3]>v2[3];
//             }
//             return v[2]>v2[2];
//         }
//         return v[1]>v2[1];
//     }
//     return true;
// }
signed main(){
    cout<<"no. of processes : ";
    int n;cin>>n;
    vector<vector<int>>v;
    int mn=INT_MAX;
    int mx=INT_MIN;
    cout<<"enter arival and brust time for all processes : "<<endl;
    for(int i=0;i<n;i++){
        vector<int>v1;
        int a,b;cin>>a>>b;
        v1.push_back(a);
        v1.push_back(b);
        v.push_back(v1);
        mn=min(mn,a);
        mx=max(mx,a);
    }
    // cout<<mn<<" "<<mx<<endl;
    int r=mn;
    vector<vector<int>>ms;
    for(int i=0;i<n;i++){
        if(v[i][0]==mn){
            vector<int>m;
            m.push_back(v[i][1]);
            m.push_back(v[i][0]);
            m.push_back(i);
            ms.push_back(m);
        }
    }
    vector<int>ct;
    vector<int>g;
    for(int i=0;i<n;i++) ct.push_back(0);
    while(true){
        if(ms.size()==0  and r>mx) break;
        if(ms.size()==0) r++;
        else{
            sort(ms.begin(),ms.end());
            ms[0][0]-=1;
            g.push_back(ms[0][2]);
            r++;
            if(ms[0][0]==0){
                ct[ms[0][2]]=r;
                ms.erase(ms.begin());
            }
            // else{
                
            // }
            for(int i=0;i<n;i++){
                if(v[i][0]==r){
                    vector<int>m1;
                    m1.push_back(v[i][1]);
                    m1.push_back(v[i][0]);
                    m1.push_back(i);
                    ms.push_back(m1);
                }
            }
        }

    }
    cout<<endl;
    cout<<"gaint chart is : ";
    for(auto i : g) cout<<"p"<<i+1<<" ";
    cout<<endl;
    cout<<endl;
    cout<<endl;
    vector<int>tat;
    for(int i=0;i<n;i++){
        tat.push_back(ct[i]-v[i][0]);
    }
    vector<int>wt;
    for(int i=0;i<n;i++){
        wt.push_back(tat[i]-v[i][1]);
    }
    for(int i=0;i<n;i++){
        v[i].push_back(ct[i]);
        v[i].push_back(tat[i]);
        v[i].push_back(wt[i]);
    }
    cout<<"id      "<<"at      "<<"bt      "<<"ct      "<<"tat      "<<"wt    "<<endl;
    for(int i=0;i<n;i++){
        cout<<i+1<<"       ";
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<"       ";
        }
        cout<<endl;
    }
    return 0;
}