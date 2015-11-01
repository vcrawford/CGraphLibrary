
void readGraph() {

   char line[SMALLARRAY];
   char* lineNoSpace;
   int id;
   int dir;
   int wt;
   graph* myGraph;
   node* myNode;
   NodeTreeNode* root = NULL;

   FILE* graphfile = fopen("graph.txt", "r");
   while (fgets(line, 100, graphfile) != NULL) {
      
      lineNoSpace = trimFrontWhiteSpace(line);

      if (sscanf(lineNoSpace, "<graph id=%d dir=%d>", &id, &dir) == 2) {
          myGraph = buildGraph(id, (bool) dir);
          printf("A graph with id %d and dir %d was created\n", id, dir);
      }
      else if (sscanf(lineNoSpace, "<node id=%d weight=%d/>", &id, &wt) == 2) {
          myNode = buildNode(id, wt);
          if (root == NULL) {
             root = buildNodeTreeNode(myNode);
          }
          else {
             addToNodeTree(myNode, root);
          }
          printf("A node with id %d and weight %d was created\n", id, wt);
      }

   }

   printf("\nNode tree: ");
   printNodeTree(root); 
}

char* trimFrontWhiteSpace(char* str) {
   while (*str == ' ') {
      str++;
   }
   return str;
}
