
graph* buildGraph(int id, bool dir) {
   graph* newgraph = (graph*)(malloc(sizeof(graph)));
   newgraph->id = id;
   newgraph->dir = dir;
   newgraph->nodes = buildNodeArray();
   newgraph->edges = buildEdgeArray();
   return newgraph;
}

void addNode(graph* mygraph, node* mynode) {

   addNode(mygraph->nodes, mynode);
}

void addEdge(graph* mygraph, edge* myedge) {

   addEdge(mygraph->edges, myedge);
}

node* getNode(graph* myGraph, int id) {
   return myGraph->nodes->nodes + id; 
}

void printGraph(graph* mygraph) {
   int i, j;
   node* myNode;
   edge* myEdge;

   printf("\nGraph %d:\n", mygraph->id);
   printf(" Nodes: ");
   for (i = 0; i < mygraph->nodes->length; i++) {
      printf("<%d> ", (mygraph->nodes->nodes + i)->id);
   }
   printf("\n");

   printf(" Edges: ");
   for (i = 0; i < mygraph->edges->length; i++) {
      printf("<%d,%d> ", (mygraph->edges->edges + i)->tail->id, (mygraph->edges->edges + i)->head->id);
   }

   printf("\n\nNodes to Edges:\n");
   for (i = 0; i < mygraph->nodes->length; i++) {
      myNode = mygraph->nodes->nodes + i;
      printf(" <%d>: ", myNode->id);
      for (j = 0; j < myNode->edges->length; j++) {
         myEdge = myNode->edges->edges + j;
         printf("<%d,%d> ", myEdge->tail->id, myEdge->head->id);
      }
      printf("\n");
   }

   printf("\n");
}
