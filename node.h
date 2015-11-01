#define node struct node
#define nodeArray struct nodeArray
#define NodeTree struct NodeTree
#define NodeTreeNode struct NodeTreeNode

node {
   int id;
   int weight;
};

nodeArray {
   node* nodes;
   int length;
   int maxlength;
};

NodeTree {
   node* root;
};

NodeTreeNode {
   node* meNode;
   NodeTreeNode* leftChild;
   NodeTreeNode* rightChild;
};

node* buildNode(int, int);
void copyNodes(int, node*, node*);
void addNode(nodeArray*, node*);
nodeArray* buildNodeArray();
void printNodes(nodeArray*);
void printNode(node*);
NodeTreeNode* buildNodeTreeNode(node*);
bool addToNodeTree(node*, NodeTreeNode*);
void printNodeTree(NodeTreeNode*);

#include "node.c"
