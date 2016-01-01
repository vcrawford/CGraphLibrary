
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
          //printf("Built graph %d\n", graph->id);
      }
      else if (sscanf(lineNoSpace, "<node weight=%d/>", &wt) == 1) {
          node = buildGraphNode(nodeID, wt);
          nodeID++;
          addNodeToGraph(graph, node);
          //printf("Added node %d\n", node->id);
      }
      else if (sscanf(lineNoSpace, "<edge weight=%d tail=%d head=%d/>", 
         &wt, &tailID, &headID) == 3) {

         head = getNodeFromID(graph, headID);
         tail = getNodeFromID(graph, tailID);

         edge = buildGraphEdge(edgeID, wt, tail, head);
         //printf("Built edge <%d,%d>\n", tail->id, head->id);
         edgeID++;
         addEdgeToGraph(graph, edge);
         printf("Adding edge <%d,%d> to node %d\n", edge->tail->id, edge->head->id, tail->id);
         //printf("one!\n");
         addEdgeForNode(tail, edge);
         //printf("two!\n");
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
