
/**Give a weight, return a pointer to a node*/
node* buildNode(int id, int weight) {
   node* newnode = (node*) malloc(sizeof(node));
   newnode->weight = weight;
   newnode->id = id;
   return newnode;
}

/**Build an node array, return pointer to it*/
nodeArray* buildNodeArray() {
   
   nodeArray* newNodes = (nodeArray*)malloc(sizeof(nodeArray));
   newNodes->length = 0;
   newNodes->maxlength = MAXARRAY;
   newNodes->nodes = (node*)malloc(MAXARRAY*sizeof(node));
   return newNodes;
}

/**Add node to node array, increasing its size if needed*/
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

/**copy length elements of an array of node to another array*/
void copyNodes(int length, node* copyFrom, node* copyTo) {

   int i;
   for (i = 0; i < length; i++) {
      copyTo[i] = copyFrom[i];
   }

}

NodeTreeNode* buildNodeTreeNode(node* mynode) {
   NodeTreeNode* newTreeNode = (NodeTreeNode*) malloc(sizeof(NodeTreeNode));
   newTreeNode->meNode = mynode;
   return newTreeNode;
}

bool addToNodeTree(node* newnode, NodeTreeNode* root) {

   if (root->meNode->id > newnode->id) {
      if (root->leftChild != NULL) {
         addToNodeTree(newnode, root->leftChild);
      }
      else {
         root->leftChild = buildNodeTreeNode(newnode);
         return true;
      }
   }
   else if (root->meNode->id < newnode->id) {
      if (root->rightChild != NULL) {
         addToNodeTree(newnode, root->rightChild);
      }
      else {
         root->rightChild = buildNodeTreeNode(newnode);
         return true;
      }
   }
   else {
      //This node is already on the tree
      return false;
   }
}

void printNodeTree(NodeTreeNode* root) {

   if (root->leftChild != NULL) {
      printNodeTree(root->leftChild);
   }

   printf("%d, ", root->meNode->id);

   if (root->rightChild != NULL) {
      printNodeTree(root->rightChild);
   }
  
}

void printNodes(nodeArray* nodes) {
   int i;
   for (i=0; i<nodes->length; i++) {
      printNode(&nodes->nodes[i]);
      if (i != (nodes->length-1)) {
         printf(", ");
      }
   }
}

void printNode(node* mynode) {
   printf("<%d>", mynode->id);
}
