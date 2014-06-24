#include<iostream>
#include<vector>
#include<cstring>
#include<cstdlib>

using namespace std;

bool *explored;
vector<int> *v;

bool dfs(int, int);

int main(){
  int n, m, src, dest;
  cin>>n; cin>>m;

  v=(vector<int> *)malloc(sizeof(vector<int>)*n);
  explored=(bool *)malloc(sizeof(int)*n);
  
  memset(explored, false, sizeof(explored));
  
  for(int i=0; i<m; i++){
    cin>>src; cin>>dest;
    v[src-1].push_back(dest);
  }

  cin>>src; cin>>dest;

  explored[src-1]= true;

  dfs(src, dest);
  cout<<explored[dest-1]<<"\n";

  return 0;
}
  
bool dfs(int src, int dest){
  for(int i=0; i<v[src-1].size(); i++){
    int ncurr=v[src-1][i];
   
    if(ncurr==dest){
      explored[dest-1]=true;
      break;
    }
    
    if(!explored[ncurr-1]){
      explored[ncurr-1]=true;
      dfs(ncurr, dest);
    }
  }
}
