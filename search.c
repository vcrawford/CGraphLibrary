static void addToSearchData(SearchDataArray*, SearchData*);
static SearchDataArray* createSearchDataArray(int);
static SearchDataArray* initSearchData(Graph*);
static void searchNeighbors(SearchDataArray*, GraphNodeArray*, GraphNode*);
static void printPathString(SearchDataArray*, int);

SearchDataArray* breadthFirstSearch(Graph* graph, GraphNode* start) {

   //create an array that holds search data
   //The data is in order of node id (so we can just add the id of the node and get that
   //node's search data)!
   SearchDataArray* searchdata = initSearchData(graph);
   //The queue for which node to search neighbors of next
   GraphNodeArray* queue = buildNodeArray();
   //Hold a pointer to the node we're visiting (we'll go through many)
   GraphNode* node;

   //The search data for the start node
   SearchData* startdata = searchdata->data + start->id;
   startdata->distance = 0;
   printf("Starting with node %d\n", start->id);
   //Add it the the search neighbors queue
   addNodeToArray(queue, start);

   //Keep searching nodes in queue
   //Note that things are added to the queue in searchNeighbors()
   while (queue->length > 0) {
      node = removeFirstElement(queue);
      printf("Searching node %d\n", node->id);
      searchNeighbors(searchdata, queue, node);
   }

   return searchdata;
}

static void searchNeighbors(SearchDataArray* searchdata, GraphNodeArray* queue, GraphNode* node) {

   int i;
   //Get the search data pointer for the node whose neighbors we're searching
   SearchData* nodedata = searchdata->data + node->id;
   //This is what we will hold a pointer to the neighbor's data in
   SearchData* neighbordata;
   //Here's where we'll hold the neighbor pointer
   GraphNode* neighbor;

   //Go through each of the node's edges (only edges that have this node as the head)
   for (i = 0; i < node->edgeArray->length; i++) {

      //That edge should go to a neighbor
      neighbor = (node->edgeArray->edges + i)->head;
      printf("Checking neighbor %d\n", neighbor->id);

      //The neighbor's search data (should be NULL if unvisited so far)
      neighbordata = searchdata->data + neighbor->id;

      printf("Neighbor %d currently has distance %d\n", neighbor->id, neighbordata->distance); 
      //Check whether this is the shortest distance so far
      if ((neighbordata->distance == -1) || (neighbordata->distance > (nodedata->distance + 1))) {
         //The original node is the parent
         neighbordata->parent = node;
         //The distance of the parent plus 1
         neighbordata->distance = nodedata->distance + 1;
         //Add this node to the queue so its neighbors will be searched
         printf("Node %d has distance %d and parent %d\n", neighbor->id, neighbordata->distance, neighbordata->parent->id);
         printf("Adding node %d to the neighbor queue\n", neighbor->id);
         addNodeToArray(queue, neighbor);
      }
   }
} 

/**For each vertex in the graph, make a SearchData with default null values*/
static SearchDataArray* initSearchData(Graph* graph) {

   int i;
   int nodeCount = graph->nodeArray->length; 
   SearchDataArray* dataArray = createSearchDataArray(nodeCount);

   for (i = 0; i < nodeCount; i++) {
      SearchData* data = (SearchData*) malloc(sizeof(SearchData));
      data->parent = NULL;
      data->node = graph->nodeArray->nodes + i;
      printf("Created search data for node %d\n", data->node->id);
      data->distance = -1;
      addToSearchData(dataArray, data);
   }

   return dataArray;
}

static SearchDataArray* createSearchDataArray(int maxsize) {

   SearchDataArray* dataArray = (SearchDataArray*) malloc(sizeof(SearchDataArray));
   dataArray->length = 0;
   dataArray->data = (SearchData*) malloc(maxsize*sizeof(SearchData));
   return dataArray;
}

static void addToSearchData(SearchDataArray* dataArray, SearchData* data) {

   dataArray->data[dataArray->length] = *data;
   dataArray->length++;
}

void printSearchData(SearchDataArray* dataArray) {

   int i;

   printf("\n");
   for (i = 0; i < dataArray->length; i++) {
      printf("vertex %d with distance %d\n", i, (dataArray->data + i)->distance);
      printPathString(dataArray, i);
      printf("\n"); 
   }
}

static void printPathString(SearchDataArray* dataArray, int id) {

   if ((dataArray->data + id)->parent != NULL) {
      printPathString(dataArray, (dataArray->data + id)->parent->id);
      printf("->%d", id);
   }
   else {
      printf("%d", id);
   }
}



