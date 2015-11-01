
graph* buildGraph(int id, bool dir) {
   graph* newgraph = (graph*)(malloc(sizeof(graph)));
   newgraph->id = id;
   newgraph->dir = dir;
   return newgraph;
}

void addNode(graph* mygraph, node* mynode) {

   if (mygraph->nodes == NULL) {
      mygraph->nodes = buildNodeArray();
   }

   addNode(mygraph->nodes, mynode);
}

void addEdge(graph* mygraph, edge* myedge) {

   if (mygraph->edges == NULL) {
      mygraph->edges = buildEdgeArray();
   }

   addEdge(mygraph->edges, myedge);
}

void printGraph(graph* mygraph) {
   int i;

   printf("Graph %d:\n", mygraph->id);
   printf(" Nodes: ");
   for (i = 0; i < mygraph->nodes->length; i++) {
      printf("<%d> ", (mygraph->nodes->nodes + i)->id);
   }
   printf("\n");

   printf(" Edges: ");
   for (i = 0; i < mygraph->edges->length; i++) {
      printf("<%d,%d> ", (mygraph->edges->edges + i)->tail->id, (mygraph->edges->edges + i)->head->id);
   }

   printf("\n");
}
