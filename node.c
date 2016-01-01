
GraphNode* buildGraphNode(int id, int weight) {
   GraphNode* node = (GraphNode*) malloc(sizeof(GraphNode));
   node->weight = weight;
   node->id = id;
   node->edgeArray = buildEdgeArray();
   return node;
}

void addEdgeForNode(GraphNode* node, GraphEdge* edge) {
   //printf("Adding edge <%d,%d> to node %d. The edge array should now have length %d.\n", edge->tail->id, edge->head->id, node->id, node->edgeArray->length + 1);
   //printf("one!\n");
   addEdgeToArray(node->edgeArray, edge);
   //printf("two!\n");
}

GraphNodeArray* buildNodeArray() {
   GraphNodeArray* nodeArray = (GraphNodeArray*) malloc(sizeof(GraphNodeArray));
   nodeArray->length = 0;
   nodeArray->maxlength = MAXARRAY;
   nodeArray->nodes = (GraphNode*) malloc(MAXARRAY*sizeof(GraphNode));
   return nodeArray;
}

void addNodeToArray(GraphNodeArray* nodeArray, GraphNode* node) {

   if (nodeArray->length >= nodeArray->maxlength) {
      GraphNode* nodes = (GraphNode*) malloc(2*nodeArray->maxlength*sizeof(GraphNode));
      copyNodes(nodeArray->length, nodeArray->nodes, nodes);
      free(nodeArray->nodes);
      nodeArray->nodes = nodes;
      nodeArray->maxlength*=2;
   }

   nodeArray->nodes[nodeArray->length] = *node;
   nodeArray->length++;
}

void copyNodes(int length, GraphNode* copyFrom, GraphNode* copyTo) {

   int i;
   for (i = 0; i < length; i++) {
      copyTo[i] = copyFrom[i];
   }

}

/**
 * Remove the first element from a nodeArray, and return a pointer to it
 * Like dequeueing a queue, assuming that new elements are being added to the end
 */
GraphNode* removeFirstElement(GraphNodeArray* nodeArray) {

   //here is the first element
   GraphNode* node = nodeArray->nodes;
   //have the array now start at the second node
   nodeArray->nodes = nodeArray->nodes + 1;
   //one less element then
   nodeArray->length--;

   return node;
}

/**
 * Remove the last element from a nodeArray, and return a pointer to it
 * Like popping a stack, assuming new elements are being added to the end.
 */
GraphNode* removeLastElement(GraphNodeArray* nodeArray) {

   //here is the last node
   GraphNode* node = nodeArray->nodes + nodeArray->length - 1;
   //one less node then
   nodeArray->length--;

   return node;
}

