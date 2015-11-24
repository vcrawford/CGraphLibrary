
graph* readGraph(char* filename) {

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
   node* head;
   node* tail;
   graph* myGraph;
   node* myNode;
   edge* myEdge;

   FILE* graphfile = fopen(filename, "r");
   while (fgets(line, 100, graphfile) != NULL) {
      
      lineNoSpace = trimFrontWhiteSpace(line);

      if (sscanf(lineNoSpace, "<graph id=%d dir=%d>", &graphID, &dir) == 2) {
          myGraph = buildGraph(graphID, (bool) dir);
      }
      else if (sscanf(lineNoSpace, "<node weight=%d/>", &wt) == 1) {
          myNode = buildNode(nodeID, wt);
          nodeID++;
          addNode(myGraph, myNode);
      }
      else if (sscanf(lineNoSpace, "<edge weight=%d head=%d tail=%d/>", 
         &wt, &headID, &tailID) == 3) {

         head = getNode(myGraph, headID);
         tail = getNode(myGraph, tailID);

         myEdge = buildEdge(edgeID, wt, head, tail);
         edgeID++;
         addEdge(myGraph, myEdge);
         addEdgeForNode(head, myEdge);
         addEdgeForNode(tail, myEdge);
      }

   }

   return myGraph;
}

char* trimFrontWhiteSpace(char* str) {
   while (*str == ' ') {
      str++;
   }
   return str;
}
