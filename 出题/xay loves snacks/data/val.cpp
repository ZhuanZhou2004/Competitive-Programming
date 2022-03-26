#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;
int n,m,seed;
int main(int argc,char *argv[]){
  registerValidation();
  n=inf.readInt(50,10000000,"n");
  inf.readSpace();
  m=inf.readInt(2,100000000,"m");
  inf.readSpace();
  seed=inf.readInt(0,(1<<30)-1+(1<<30),"seed");
  inf.readEoln();
  inf.readEof();
  return 0;
}
