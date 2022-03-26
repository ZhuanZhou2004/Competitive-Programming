#include<bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int ans[]={1,1,4,5,1,4,1,9,1,9,8,1};
int n,m;

#define ll long long

ll gg(){
  ll g=rng()%1000000000ll;
  g*=rng()%1000000000ll;
  return g%9982444353ll+1;
}
int main(){
  freopen("card6.in","w",stdout);
  printf("%d %d\n",n=1000,m=100);
  for(int i=0;i<n;i++)printf("%lld ",rng()%500+1);
  puts("");
  for(int i=0;i<m;i++)printf("%lld ",gg());
  puts("");
}
