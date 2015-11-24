
node* buildNode(int id, int weight) {
   node* newnode = (node*) malloc(sizeof(node));
   newnode->weight = weight;
   newnode->id = id;
   newnode->edges = buildEdgeArray();
   return newnode;
}

void addEdgeForNode(node* myNode, edge* myEdge) {
   addEdge(myNode->edges, myEdge);
}

nodeArray* buildNodeArray() {
   
   nodeArray* newNodes = (nodeArray*)malloc(sizeof(nodeArray));
   newNodes->length = 0;
   newNodes->maxlength = MAXARRAY;
   newNodes->nodes = (node*)malloc(MAXARRAY*sizeof(node));
   return newNodes;
}

void addNode(nodeArray* nodes, node* newnode) {

   if (nodes->length >= nodes->maxlength) {
      node* newNodes = (node*)malloc(2*nodes->maxlength*sizeof(node));
      copyNodes(nodes->length, nodes->nodes, newNodes);
      free(nodes->nodes);
      nodes->nodes = newNodes;
      nodes->maxlength*=2;
   }

   nodes->nodes[nodes->length] = *newnode;
   nodes->length++;
}

void copyNodes(int length, node* copyFrom, node* copyTo) {

   int i;
   for (i = 0; i < length; i++) {
      copyTo[i] = copyFrom[i];
   }

}
