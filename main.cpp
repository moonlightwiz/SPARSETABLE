#include <iostream>
#include<map>
#include<set>
#include<unordered_set>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<iterator>
#include<climits>

using namespace std;

long long mod=1e9 +7;

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>v(n+1);
        vector<vector<int>>adj(n+1);
        for(int i=1;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            v[a]++;
            v[b]++;
        }
        int maxi=1;
        for(int i=2;i<=n;i++)
        {
            if(v[i]>v[maxi])
            {
                maxi=i;
            }
        }
        int curr=v[maxi];
        cout<<"maxi 1 : "<<maxi<<endl;
        cout<<"curr after 1 round : "<<curr<<"\n";
        for(auto i:adj[maxi])
        {
            v[i]--;
        }
        
        int maxi2=-1;
        for(int i=1;i<maxi;i++)
        {
            if(maxi2==-1)
            {
                maxi2=i;
            }
            else{
                if(v[i]>v[maxi2])
                {
                    maxi2=i;
                }
            }
        }
        for(int i=maxi+1;i<=n;i++)
        {
            if(maxi2==-1)
            {
                maxi2=i;
            }
            else{
                if(v[i]>v[maxi2])
                {
                    maxi2=i;
                }
            }
        }
        
        //cout<<"maxi 2 : "<<maxi2<<"\n";
        //cout<<"v[maxi2] : "<<v[maxi2]<<"\n";
        if(v[maxi2]==0)
        {
            curr--;
        }
        else{
            curr+=v[maxi2];
            curr--;
        }
        cout<<curr<<"\n";
    }
    
    return 0;
}
