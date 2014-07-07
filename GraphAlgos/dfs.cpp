#include<iostream>
#include<vector>
#include<cstring>
#include<cstdlib>

using namespace std;

bool *explored;
vector<int> *v;

void dfs(int, int);

int main(){
  int n, m, src, dest;
  cin>>n; cin>>m;

  v=new vector<int> [n];
  explored=new bool [n];
  
  memset(explored, false, sizeof(explored));
  
  for(int i=0; i<m; i++){
    cin>>src; cin>>dest;
    v[src-1].push_back(dest);
  }

  cin>>src; cin>>dest;

  explored[src-1]= true;

  dfs(src, dest);
  if(explored[dest-1]) cout<<"Yes they are connected \n";
  else cout<<"No they are not connectes\n";

  return 0;
}
  
void dfs(int src, int dest){
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
