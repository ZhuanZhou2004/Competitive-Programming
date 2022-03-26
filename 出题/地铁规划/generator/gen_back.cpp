#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define pb push_back
#define SZ(x) (int(x.size()))

mt19937 rng(time(NULL));
vector<pii>edge;
int nn,n=100000;

int main(){
  freopen("back5.in","w",stdout);
  nn=n;
  int head=0,tail=1;
  for(int num=1;num+(num==1)<=n;num<<=1){
    n-=num+(num==1);
    for(int i=1;i<=num+(num==1);i++){
      edge.pb({1,++tail});
    }
    edge.pb(edge[head++]);
  }
  fprintf(stderr,"tail=%d,SZ=%d\n",tail,SZ(edge));
  head++,head++;
  for(int i=tail+1;i<=nn;i++){
    edge.pb(edge[head++]);
  }
  n=nn;
  while(SZ(edge)<200000){
    int u=rng()%n+1,v=rng()%n+1;
    while(u==v)u=rng()%n+1,v=rng()%n+1;
    edge.pb({u,v});
  }
  printf("%d %d\n",n,SZ(edge));
  for(auto v:edge){
    printf("%d %d\n",v.first,v.second);
  }
  return 0;
}
