#define MAXARRAY 100
#define GraphNode struct GraphNode
#define GraphNodeArray struct GraphNodeArray
#define GraphEdge struct GraphEdge
#define GraphEdgeArray struct GraphEdgeArray
#define Graph struct Graph

GraphNode {
   int id;
   int weight;
   GraphEdgeArray* edgeArray;
};

GraphNodeArray {
   GraphNode* nodes;
   int length;
   int maxlength;
};

GraphEdge {
   int id;
   int weight;
   GraphNode* tail;
   GraphNode* head;
};

GraphEdgeArray {
   GraphEdge* edges;
   int length;
   int maxlength;
};

Graph {
   int id;
   GraphEdgeArray* edgeArray;
   GraphNodeArray* nodeArray;
   bool dir;
};

Graph* readGraph(char*);
char* trimFrontWhiteSpace(char*);

Graph* buildGraph(int, bool);
void printGraph(Graph*);
void addNodeToGraph(Graph*, GraphNode*);
void addEdgeToGraph(Graph*, GraphEdge*);

GraphNode* getNodeFromID(Graph*, int);
GraphEdge* buildGraphEdge(int, int, GraphNode*, GraphNode*);
void copyEdges(int, GraphEdge*, GraphEdge*);
void addEdgeToArray(GraphEdgeArray*, GraphEdge*);
GraphEdgeArray* buildEdgeArray();

GraphNode* buildGraphNode(int, int);
void copyNodes(int, GraphNode*, GraphNode*);
void addNodeToArray(GraphNodeArray*, GraphNode*);
GraphNodeArray* buildNodeArray();
void addEdgeForNode(GraphNode*, GraphEdge*);

#include "node.c"
#include "edge.c"
#include "graph.c"
#include "readgraph.c"
