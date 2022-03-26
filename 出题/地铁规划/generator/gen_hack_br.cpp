#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define pb push_back
#define SZ(x) (int(x.size()))

vector<pii>edge;
int n=1000000;
int BOUND=200000;

int main(){
  freopen("data.in","w",stdout);
  int hd=2,las=1;
  for(int i=1;i<=BOUND;i++){
    edge.pb({1,++las});
  }
  edge.pb({1,++hd});
  int lef=n-BOUND,jumps=0;
  for(int num=2;num<=lef;num<<=1){
    ++jumps;
    lef-=num;
    for(int i=1;i<=num;i++){
      edge.pb({1,++las});
    }
    edge.pb({1,++hd});
  }
  fprintf(stderr,"las=%d,jumps=%d\n",las,jumps);
  n=las;
  printf("%d %d\n",n,SZ(edge));
  for(auto v:edge){
    printf("%d %d\n",v.first,v.second);
  }
  return 0;
}
