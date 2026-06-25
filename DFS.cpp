#include <bits/stdc++.h>
using namespace std;

// Array of vectors to represent the graph using an adjacency list
vector<int> graph[1005]; 

// Array to track visited vertices to prevent infinite loops/re-processing
bool isVisited[1005];         

void depthFirstSearch(int currentNode)
{
    // Print the node currently being processed
    cout << currentNode << " "; 

    // Mark the current node as visited
    isVisited[currentNode] = true; 

    // Traverse all adjacent neighbors of the current node
    for (auto neighbor : graph[currentNode]) 
    {
        // If the neighbor has not been visited yet, explore it recursively
        if (isVisited[neighbor] == false) 
        {
            depthFirstSearch(neighbor); 
        }
    }
}

int main()
{
    int totalNodes, totalEdges;      
    cin >> totalNodes >> totalEdges; 

    // Read and construct the graph from the given edges
    for (int i = 0; i < totalEdges; i++) 
    {
        int u, v;      
        cin >> u >> v; 

        // Add an edge from u to v, and from v to u (undirected graph)
        graph[u].push_back(v); 
        graph[v].push_back(u); 
    }

    // Initialize all nodes as unvisited before starting the traversal
    memset(isVisited, false, sizeof(isVisited)); 

    // Execute DFS traversal starting from the root/source node (0)
    depthFirstSearch(0); 

    return 0;
}
