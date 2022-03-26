#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define pb push_back
#define SZ(x) (int(x.size()))

mt19937 rng(time(NULL));
vector<pii>edge;
int id[100005],n=100000-1;

int main(){
  
  for(int T=11;T<=30;T++){
    char in[100];
    sprintf(in,"twice%d.in",T);
    freopen(in,"w",stdout);
//    int who=rng()%n+1;
    int qwq=T-9,who=n*qwq/(qwq+1);
    int head=0;edge.clear();
    for(int i=1;i<=who;i++)edge.pb({rng()%i+1,i+1});
    for(int i=1;SZ(edge)<200000;i++)edge.pb(edge[head++]);
  //  for(int i=1;i<=n/10000;i++){
  //    int k1=rng()%SZ(edge),k2=rng()%SZ(edge);
  //    swap(edge[k1],edge[k2]);
  //  }
  //  for(int i=1;i<=n/1000;i++){
  //    int k1=rng()%SZ(edge);
  //    int u=rng()%(n+1)+1;
  //    while(u==edge[k1].first){
  //      u=rng()%(n+1)+1;
  //    }
  ////    cerr<<k1<<' '<<u<<'\n';
  //    edge[k1].first=u;
  //  }
    printf("%d %d 3000000\n",n+1,SZ(edge));
    for(int i=1;i<=n+1;i++)id[i]=i;
    shuffle(id+1,id+n+2,rng);
    for(auto &v:edge){
      if(rng()&1)swap(v.first,v.second);
      printf("%d %d\n",id[v.first],id[v.second]);
    }
    fclose(stdout);
    char out[100];
    sprintf(out,"twice%d.out",T);
    freopen(out,"w",stdout);
    puts("Accepted");
    fclose(stdout);
  }
  return 0;
}
