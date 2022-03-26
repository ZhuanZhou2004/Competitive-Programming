#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define pb push_back
#define SZ(x) (int(x.size()))

mt19937 rng(time(NULL));
vector<pii>edge;
int n=100000;
int B=350;

int main(){
  freopen("sqrt10.in","w",stdout);
  int head=0,tail=1;
  for(int i=1;i<=B;i++)edge.pb({1,++tail});
  edge.pb(edge[head++]);
  while(tail+B<=n){
    for(int i=1;i<=B;i++){
      edge.pb({1,++tail});
    }
    edge.pb(edge[head++]);
  }
  fprintf(stderr,"tail=%d\n",tail);
  printf("%d %d\n",tail,SZ(edge));
  for(auto v:edge){
    printf("%d %d\n",v.first,v.second);
  }
}
