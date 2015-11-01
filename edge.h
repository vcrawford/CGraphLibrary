#define edge struct edge
#define edgeArray struct edgeArray

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

edge* buildEdge(int, int, node*, node*);
void copyEdges(int, edge*, edge*);
void addEdge(edgeArray*, edge*);
edgeArray* buildEdgeArray();
void printEdges(edgeArray*);
void printEdge(edge*);

#include "edge.c"
