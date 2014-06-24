#include<iostream>
#include<cstring>
#include<cstdlib>
#include<vector>

using namespace std;

vector<int> *v;
int *order,  count;
bool *explored;

void dfs(int);

int main(){
  int n, m, src, dest;
  cin>>n; cin>>m;

  count=n;
  v=(vector<int> *)malloc(sizeof(vector<int>)*n);
  order=(int *)malloc(sizeof(int)*n);
  explored=(bool *)malloc(sizeof(bool)*n);

  /*marked every vertex as unexplored*/
  memset(explored, false, sizeof(explored));
  
  /*stored graph as adjacency list*/
  for(int i=0; i<m; i++){
    cin>>src; cin>>dest;
    v[src-1].push_back(dest);
  
  }

  /*dfs_loop */
  for(int i=0; i<n; i++){
    if(!explored[i]){
      explored[i]=true;
      dfs(i);
    }
  }

  for(int i=0; i<n; i++){
    cout<<order[i]<<" ";
  }
  cout<<"\n";
  
  return 0;
}

/*depth first search routine */
void dfs(int n){
  for(int i=0; i<v[n].size(); i++){
    int ncurr=v[n][i];
    if(!explored[ncurr-1]){
      explored[ncurr-1]=true;
      dfs(ncurr-1);
    }
  }
  /*computing order of each vertex */
  order[n]=count--;
}
