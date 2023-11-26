#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N= 1e5+10;
int parent[N], sz[N];
void make(int v){
    parent[v]=v;
    sz[v]=1;
}
int find(int v){
    if(parent[v]==v) return parent[v];
    return parent[v]=find(parent[v]);
}
void Union(int a, int b){
    a=find(a);
    b=find(b);
    if(a!=b){
        if(sz[a]<sz[b]) swap(a,b);
        parent[b]=a;
        sz[a]+=sz[b];
    }
}
void prasad()
{
    int n; cin>>n;
    vector<pair<int,int>>cities(n+1);
    for(int i=1;i<=n;i++){
        cin>>cities[i].first>>cities[i].second;
    }
    vector<int>c(n+1),k(n+1);
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n;i++) cin>>k[i];
    vector<pair<int,pair<int,int>>>edges;
    for(int i=1;i<=n;i++){
        edges.push_back({c[i],{0,i}});
    }
    for(int i=1;i<=n;i++){
        for(int j=(i+1);j<=n;j++){
            int dist=(abs(cities[i].first-cities[j].first) + abs(cities[i].second-cities[j].second));
            long long cost= dist*1LL*(k[i]+k[j]);
            edges.push_back({cost,{i,j}});
        }
    }
    sort(edges.begin(),edges.end());
    for(int i=1;i<=n;i++) make(i);
    long long total_cost=0;
    vector<int>power_stations;
    vector<pair<int,int>>connections;
    for(auto &edge: edges){
        int wt= edge.first;
        int u= edge.second.first;
        int v= edge.second.second;
        if(find(u)==find(v)) continue;
        Union(u,v);
        total_cost+=wt;
        if(u==0 or v==0){
            power_stations.push_back(max(u,v));
        }
        else {
            connections.push_back({u,v});
        }
    }
    cout<<total_cost<<endl;
}

signed main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   int t = 1;
//    cin >> t;
   while (t--)
   {
      prasad();
   }
   return 0;
}
