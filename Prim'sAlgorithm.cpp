#include <bits/stdc++.h>
using namespace std;

using Connection = pair<int, int>; // Represents {weight, neighbor_node} or {neighbor_node, weight}

// Constructs the graph using an adjacency list from standard input
vector<vector<Connection>> createNetwork(int total_nodes, int total_edges)
{
    vector<vector<Connection>> adjacency_list(total_nodes);
    for (int i = 0; i < total_edges; i++)
    {
        int node_a, node_b, edge_weight;
        cin >> node_a >> node_b >> edge_weight;
        adjacency_list[node_a].push_back({node_b, edge_weight});
        adjacency_list[node_b].push_back({node_a, edge_weight});
    }
    return adjacency_list;
}

// Displays the calculated Minimum Spanning Tree and its total cost
void displayMST(const vector<int> &previous_node, const vector<int> &min_edge_cost)
{
    int grand_total_cost = 0;
    for (int i = 1; i < (int)previous_node.size(); i++)
    {
        cout << previous_node[i] << " - " << i << " : " << min_edge_cost[i] << '\n';
        grand_total_cost += min_edge_cost[i];
    }
    cout << "Total weight = " << grand_total_cost << '\n';
}

// Executes Prim's Algorithm to determine the Minimum Spanning Tree
void computePrimMST(int total_nodes, vector<vector<Connection>> &graph_network, vector<int> &previous_node, vector<int> &min_edge_cost)
{
    vector<bool> visited_nodes(total_nodes, false);
    priority_queue<Connection, vector<Connection>, greater<Connection>> active_edges; // Min-heap storing {cost, target_node}

    min_edge_cost[0] = 0;
    active_edges.push({0, 0});

    while (!active_edges.empty())
    {
        int current_node = active_edges.top().second;
        active_edges.pop();

        if (visited_nodes[current_node])
            continue;
        visited_nodes[current_node] = true;

        for (auto [neighbor, weight] : graph_network[current_node])
        {
            if (!visited_nodes[neighbor] && weight < min_edge_cost[neighbor])
            {
                min_edge_cost[neighbor] = weight;
                previous_node[neighbor] = current_node;
                active_edges.push({min_edge_cost[neighbor], neighbor});
            }
        }
    }
}

int main()
{
    int nodes_count, edges_count;
    cin >> nodes_count >> edges_count;

    vector<vector<Connection>> graph_network = createNetwork(nodes_count, edges_count);
    vector<int> previous_node(nodes_count, -1), min_edge_cost(nodes_count, INT_MAX);

    computePrimMST(nodes_count, graph_network, previous_node, min_edge_cost);
    displayMST(previous_node, min_edge_cost);

    return 0;
}