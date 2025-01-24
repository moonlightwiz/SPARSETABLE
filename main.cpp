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
vector<long long int>factorial;
vector<long long int>invfactorial;

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin>>n;
    factorial.resize(1e6+1);
    invfactorial.resize(1e6+1);
    factorial[0]=1;
    for(int i=1;i<=1e6;i++)
    {
        factorial[i]=((factorial[i-1]%mod)*(i%mod))%mod;
    }
//    for(int i=0;i<11;i++)
//    {
//        cout<<factorial[i]<<" ";
//    }
    //cout<<"\n";
    invfactorial[0]=1;
    for(int i=1;i<=1e6;i++)
    {
        long long temp=1;
        long long curr=factorial[i];
        for(int j=0;j<32;j++)
        {
            if((1<<j)&(mod-2))
            {
                temp*=curr;
                temp%=mod;
            }
            curr*=curr;
            curr%=mod;
        }
        invfactorial[i]=temp;
    }
    
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    
    bool counter=0;
    long long temp=0;
    for(int i=2;i<=n;i++)
    {
        cout<<temp<<" ";
        if(counter)
        {
            temp-=((factorial[n]%mod)*(invfactorial[i]%mod))%mod;
        }
        else{
            temp+=((factorial[n]%mod)*(invfactorial[i]%mod))%mod;
        }
        temp%=mod;
        counter=!counter;
    }
    cout<<temp<<" ";
    
    return 0;
}
