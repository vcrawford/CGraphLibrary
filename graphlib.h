#define MAXARRAY 1000
#include<stdlib.h>
#define node struct node
#define nodeArray struct nodeArray
#define edge struct edge
#define edgeArray struct edgeArray
#define graph struct graph

node {
   int id;
   int weight;
   edgeArray* edges;
};

nodeArray {
   node* nodes;
   int length;
   int maxlength;
};

edge {
   int id;
   int weight;
   node* tail;
   node* head;
};

edgeArray {
   edge* edges;
   int length;
   int maxlength;
};

graph {
   int id;
   edgeArray* edges;
   nodeArray* nodes;
   bool dir;
};

graph* readGraph(char*);
char* trimFrontWhiteSpace(char*);

graph* buildGraph(int, bool);
void printGraph(graph*);
void addNode(graph*, node*);
void addEdge(graph*, edge*);

node* getNode(graph*, int);
edge* buildEdge(int, int, node*, node*);
void copyEdges(int, edge*, edge*);
void addEdge(edgeArray*, edge*);
edgeArray* buildEdgeArray();

node* buildNode(int, int);
void copyNodes(int, node*, node*);
void addNode(nodeArray*, node*);
nodeArray* buildNodeArray();
void addEdgeForNode(node*, edge*);

#include "node.c"
#include "edge.c"
#include "graph.c"
#include "readgraph.c"
