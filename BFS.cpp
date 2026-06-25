#include <bits/stdc++.h>
using namespace std;

// Global structures to represent the network
vector<int> graphNetwork[1005]; 
bool hasBeenVisited[1005];      

void executeBFS(int startNode)
{
    queue<int> discoveryQueue;      
    discoveryQueue.push(startNode);   
    hasBeenVisited[startNode] = true; 

    while (!discoveryQueue.empty()) 
    {
        int currentNode = discoveryQueue.front(); 
        discoveryQueue.pop();                    

        cout << currentNode << " "; 

        // Traverse all neighboring connections of the current node
        for (int neighborNode : graphNetwork[currentNode]) 
        {
            if (!hasBeenVisited[neighborNode]) 
            {
                discoveryQueue.push(neighborNode);   
                hasBeenVisited[neighborNode] = true; 
            }
        }
    }
}

int main()
{
    int totalNodes, totalEdges;      
    cin >> totalNodes >> totalEdges; 

    // Construct the graph by processing each edge input
    for (int i = 0; i < totalEdges; i++) 
    {
        int u, v;      
        cin >> u >> v; 

        // Map the bidirectional relationship between the two endpoints
        graphNetwork[u].push_back(v); 
        graphNetwork[v].push_back(u); 
    }

    // Reset the tracking array to ensure a fresh traversal state
    memset(hasBeenVisited, false, sizeof(hasBeenVisited)); 

    // Initiate the breadth-first search starting at node 0
    executeBFS(0); 

    return 0;
}
