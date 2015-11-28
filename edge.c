
GraphEdge* buildGraphEdge(int id, int weight, GraphNode* tail, GraphNode* head) {

   GraphEdge* edge = (GraphEdge*) malloc(sizeof(GraphEdge));
   edge->weight = weight;
   edge->tail = tail;
   edge->head = head;
   edge->id = id;
   return edge;
}

GraphEdgeArray* buildEdgeArray() {
   
   GraphEdgeArray* edgeArray = (GraphEdgeArray*) malloc(sizeof(GraphEdgeArray));
   edgeArray->length = 0;
   edgeArray->maxlength = MAXARRAY;
   edgeArray->edges = (GraphEdge*) malloc(MAXARRAY*sizeof(GraphEdge));
   return edgeArray;
}

void addEdgeToArray(GraphEdgeArray* edgeArray, GraphEdge* edge) {

   if (edgeArray->length >= edgeArray->maxlength) {
      GraphEdge* edges = (GraphEdge*) malloc(2*edgeArray->maxlength*sizeof(GraphEdge));
      copyEdges(edgeArray->length, edgeArray->edges, edges);
      free(edgeArray->edges);
      edgeArray->edges = edges;
      edgeArray->maxlength*=2;
   }

   edgeArray->edges[edgeArray->length] = *edge;
   edgeArray->length++;
}

void copyEdges(int length, GraphEdge* copyFrom, GraphEdge* copyTo) {
   int i;
   for (i = 0; i < length; i++) {
      copyTo[i] = copyFrom[i];
   }
}

