
Graph* buildGraph(int id, bool dir) {
   Graph* graph = (Graph*) (malloc(sizeof(Graph)));
   graph->id = id;
   graph->dir = dir;
   graph->nodeArray = buildNodeArray();
   graph->edgeArray = buildEdgeArray();
   return graph;
}

void addNodeToGraph(Graph* graph, GraphNode* node) {
   addNodeToArray(graph->nodeArray, node);
}

void addEdgeToGraph(Graph* graph, GraphEdge* edge) {
   addEdgeToArray(graph->edgeArray, edge);
}

GraphNode* getNodeFromID(Graph* graph, int id) {
   return graph->nodeArray->nodes + id; 
}

void printGraph(Graph* graph) {
   int i, j;
   GraphNode* node;
   GraphEdge* edge;

   printf("\nGraph %d:\n", graph->id);
   printf(" Nodes: ");
   for (i = 0; i < graph->nodeArray->length; i++) {
      printf("<%d> ", (graph->nodeArray->nodes + i)->id);
   }
   printf("\n");

   printf(" Edges: ");
   for (i = 0; i < graph->edgeArray->length; i++) {
      printf("<%d,%d> ", (graph->edgeArray->edges + i)->tail->id, (graph->edgeArray->edges + i)->head->id);
   }

   printf("\n\nNodes to Edges:\n");
   for (i = 0; i < graph->nodeArray->length; i++) {
      node = graph->nodeArray->nodes + i;
      printf(" <%d>: ", node->id);
      for (j = 0; j < node->edgeArray->length; j++) {
         edge = node->edgeArray->edges + j;
         printf("<%d,%d> ", edge->tail->id, edge->head->id);
      }
      printf("\n");
   }

   printf("\n");
}
