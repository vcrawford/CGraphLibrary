
/**Give a weight and pointers to the two nodes it connects
   and get in return a pointer to an edge*/
edge* buildEdge(int id, int weight, node* tail, node* head) {
   edge* newedge = (edge*) malloc(sizeof(edge));
   newedge->weight = weight;
   newedge->tail = tail;
   newedge->head = head;
   newedge->id = id;
   return newedge;
}

/**Build an edge array, return pointer to it*/
edgeArray* buildEdgeArray() {
   
   edgeArray* newEdges = (edgeArray*)malloc(sizeof(edgeArray));
   newEdges->length = 0;
   newEdges->maxlength = MAXARRAY;
   newEdges->edges = (edge*)malloc(MAXARRAY*sizeof(edge));
   return newEdges;
}

/**Add edge to edge array, increasing its size if needed*/
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

/**copy length elements of an array of edges to another array*/
void copyEdges(int length, edge* copyFrom, edge* copyTo) {

   int i;
   for (i = 0; i < length; i++) {
      copyTo[i] = copyFrom[i];
   }

}

void printEdges(edgeArray* edges) {
   int i;
   for (i=0; i<edges->length; i++) {
      printEdge(&edges->edges[i]);
      if (i != (edges->length-1)) {
         printf(", ");
      }
   }
}

void printEdge(edge* myedge) {
   printf("<%d,%d>", myedge->tail->id, myedge->head->id);
}
