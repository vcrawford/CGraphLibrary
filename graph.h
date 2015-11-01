struct graph {
   int id;
   edgeArray* edges;
   nodeArray* nodes;
   bool dir;
};

graph* buildGraph(int, bool);
void printGraph(graph*);
void addNode(graph*, node*);
void addEdge(graph*, edge*);

#define graph struct graph
#include "graph.c"
