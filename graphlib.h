#define MAXARRAY 100
#define GraphNode struct GraphNode
#define GraphNodeArray struct GraphNodeArray
#define GraphEdge struct GraphEdge
#define GraphEdgeArray struct GraphEdgeArray
#define Graph struct Graph
#define SearchData struct SearchData
#define SearchDataArray struct SearchDataArray

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

/**Search data, intended to be be for a GraphNode*/
SearchData {
   GraphNode* parent;
   GraphNode* node;
   int distance;
};

/**should hold SearchData in the order of vertex id*/
SearchDataArray {
   SearchData* data;
   int length;
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
GraphNode* removeFirstElement(GraphNodeArray*);
GraphNode* removeLastElement(GraphNodeArray*);

SearchDataArray* breadthFirstSearch(Graph*, GraphNode*);
void printSearchData(SearchDataArray*);

#include "node.c"
#include "edge.c"
#include "graph.c"
#include "search.c"
#include "readgraph.c"
