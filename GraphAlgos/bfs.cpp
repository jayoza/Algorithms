#include<iostream>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;
bool * explored;
vector<int> * v;

int main(){
  int n, m, src, dest, len;
  FILE *fp;
  
  /*n=no. of vertices , m=no. of edges */
  cin>>n; cin>>m;
  
  v=new vector<int> [n];
  explored=new bool [n];
  
  /*declare a queue datastructure for bfs */
  queue<int> q;
  
  memset(explored, false, sizeof(explored)); //initialize everything as unexplored
  
  /*store graph as adjacency list */
  for(int i=0; i<m ;i++){
    cin>>src; cin>>dest;
    v[src-1].push_back(dest);
  }
  
  cin>>src; cin>>dest;
  
  /*breadth first search algorithm*/
  q.push(src);
  explored[src-1]=true;

  while(!q.empty()){
    int curr=q.front();
    if(curr==dest){
      break;
    }
    q.pop();
    int sz=v[curr-1].size();

    for(int i=0; i<sz; i++){
      if(!explored[v[curr-1][i]]){
	int ncurr=v[curr-1][i];
	explored[ncurr-1]=true;
	q.push(ncurr);
      }
    }
  }
  
  if((explored[dest-1]))
    cout<<"Yes they are connected \n";
  else cout<<"No they are not connected \n";
   
  return 0;
}
  
  
  
