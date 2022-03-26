#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define pb push_back
#define SZ(x) (int(x.size()))

vector<pii>edge;
int n=10000;

int main(){
  freopen("data.in","w",stdout);
  int head=0,tail=1;
  for(int num=1;num+(num==1)<=n;num<<=1){
    n-=num+(num==1);
    for(int i=1;i<=num+(num==1);i++){
      edge.pb({1,++tail});
    }
    edge.pb(edge[head++]);
  }
  fprintf(stderr,"tail=%d,SZ=%d\n",tail,SZ(edge));
  n=tail;
  printf("%d %d\n",n,SZ(edge));
  for(auto v:edge){
    printf("%d %d\n",v.first,v.second);
  }
  return 0;
}
