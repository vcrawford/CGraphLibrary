
Graph* readGraph(char* filename) {

   char line[MAXARRAY];
   char* lineNoSpace;
   int dir;
   int wt;
   int graphID;
   int nodeCount;
   int nodeID = 0;
   int edgeID = 0;
   int headID;
   int tailID;
   GraphNode* head;
   GraphNode* tail;
   Graph* graph;
   GraphNode* node;
   GraphEdge* edge;

   FILE* graphfile = fopen(filename, "r");
   while (fgets(line, 100, graphfile) != NULL) {
      
      lineNoSpace = trimFrontWhiteSpace(line);

      if (sscanf(lineNoSpace, "<graph id=%d dir=%d>", &graphID, &dir) == 2) {
          graph = buildGraph(graphID, (bool) dir);
      }
      else if (sscanf(lineNoSpace, "<node weight=%d/>", &wt) == 1) {
          node = buildGraphNode(nodeID, wt);
          nodeID++;
          addNodeToGraph(graph, node);
      }
      else if (sscanf(lineNoSpace, "<edge weight=%d head=%d tail=%d/>", 
         &wt, &headID, &tailID) == 3) {

         head = getNodeFromID(graph, headID);
         tail = getNodeFromID(graph, tailID);

         edge = buildGraphEdge(edgeID, wt, head, tail);
         edgeID++;
         addEdgeToGraph(graph, edge);
         addEdgeForNode(head, edge);
         addEdgeForNode(tail, edge);
      }

   }

   return graph;
}

char* trimFrontWhiteSpace(char* str) {
   while (*str == ' ') {
      str++;
   }
   return str;
}
