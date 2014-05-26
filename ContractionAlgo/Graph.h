struct node{
  int vertex;
  struct node *next;
};

typedef struct node * nodePtr;
typedef struct node  Node;

struct list{
  nodePtr head;
  int length;
};

typedef struct list * listPtr;
typedef struct list List;

struct graph{
  int num_vertices;
  listPtr listarr;
};

typedef struct graph * graphPtr;
typedef struct graph Graph;

inline void err_exit(char *msg){
  printf("[Fatal Error]:%s \nExiting....\n",msg);
  exit(1);
}
