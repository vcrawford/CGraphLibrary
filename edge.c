
edge* buildEdge(int id, int weight, node* tail, node* head) {
   edge* newedge = (edge*) malloc(sizeof(edge));
   newedge->weight = weight;
   newedge->tail = tail;
   newedge->head = head;
   newedge->id = id;
   return newedge;
}

edgeArray* buildEdgeArray() {
   
   edgeArray* newEdges = (edgeArray*)malloc(sizeof(edgeArray));
   newEdges->length = 0;
   newEdges->maxlength = MAXARRAY;
   newEdges->edges = (edge*)malloc(MAXARRAY*sizeof(edge));
   return newEdges;
}

void addEdge(edgeArray* edges, edge* newedge) {

   if (edges->length >= edges->maxlength) {
      edge* newEdges = (edge*)malloc(2*edges->maxlength*sizeof(edge));
      copyEdges(edges->length, edges->edges, newEdges);
      free(edges->edges);
      edges->edges = newEdges;
      edges->maxlength*=2;
   }

   edges->edges[edges->length] = *newedge;
   edges->length++;
}

void copyEdges(int length, edge* copyFrom, edge* copyTo) {

   int i;
   for (i = 0; i < length; i++) {
      copyTo[i] = copyFrom[i];
   }

}

