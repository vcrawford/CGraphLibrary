
GraphNode* buildGraphNode(int id, int weight) {
   GraphNode* node = (GraphNode*) malloc(sizeof(GraphNode));
   node->weight = weight;
   node->id = id;
   node->edgeArray = buildEdgeArray();
   return node;
}

void addEdgeForNode(GraphNode* node, GraphEdge* edge) {
   addEdgeToArray(node->edgeArray, edge);
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
