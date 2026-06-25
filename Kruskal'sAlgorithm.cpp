#include <bits/stdc++.h>
using namespace std;

// Structure to represent a single connection in the network
class GraphEdge
{
public:
    int source, destination, weight; // Endpoints of the edge and its associated cost
};

const int MAX_NODES = 1000;          // Upper bound for the total number of vertices
int parent_node[MAX_NODES];          // Tracking array for Disjoint Set Union roots
vector<GraphEdge> all_edges;         // Collection containing the complete graph layout
vector<GraphEdge> min_spanning_tree; // Collection containing the final tree structure

// Prepares the disjoint-set tracking structure for processing
void initialize_disjoint_set(int total_vertices)
{
    for (int i = 1; i <= total_vertices; i++)
    {
        parent_node[i] = i; // Every vertex initially belongs to its own unique group
    }
}

// Recursively tracks down the ultimate root representative of a element's group
int find_representative(int element)
{
    if (parent_node[element] == element)
        return element; // Discovered the root of this sub-tree

    // Path compression optimizing future lookups by flattening the structure
    return parent_node[element] = find_representative(parent_node[element]);
}

// Combines two separate sub-groups if they are not already linked
bool merge_components(int first_vertex, int second_vertex)
{
    first_vertex = find_representative(first_vertex);
    second_vertex = find_representative(second_vertex);

    if (first_vertex == second_vertex)
        return false; // Already structurally connected; linking would create a cycle

    parent_node[first_vertex] = second_vertex; // Attach one subtree root directly to the other
    return true;                               // Successfully integrated the groups
}

// Populates graph structure data from the standard input stream
void input_graph_data(int &vertex_count, int &edge_count)
{
    cin >> vertex_count >> edge_count;
    all_edges.resize(edge_count);

    for (int i = 0; i < edge_count; i++)
    {
        cin >> all_edges[i].source >> all_edges[i].destination >> all_edges[i].weight;
    }
}

// Outputs the final calculated structure and its cumulative cost
void display_mst_results(int total_cost)
{
    cout << "MST total weight: " << total_cost << '\n';
    cout << "Edges in MST:\n";
    for (const auto &edge : min_spanning_tree)
    {
        cout << edge.source << " -- " << edge.destination << " (weight " << edge.weight << ")\n";
    }
}

// Comparison criteria to order connections based on their cost factor
bool compare_by_weight(const GraphEdge &first, const GraphEdge &second)
{
    return first.weight < second.weight; // Prioritizes cheaper paths over more expensive ones
}

// Primary execution logic for Kruskal's greedy strategy
int compute_kruskal_mst(int vertex_count)
{
    // Organize all graph edges from lowest weight to highest weight
    sort(all_edges.begin(), all_edges.end(), compare_by_weight);

    initialize_disjoint_set(vertex_count);

    int accumulated_weight = 0;
    min_spanning_tree.clear();

    // Evaluate each sorted edge systematically
    for (const GraphEdge &edge : all_edges)
    {
        // Attempt to join the two endpoints
        if (merge_components(edge.source, edge.destination))
        {
            accumulated_weight += edge.weight; // Factor in the weight to the overall cost
            min_spanning_tree.push_back(edge); // Add this validated path to our final graph tree
        }
    }
    return accumulated_weight;
}

int main()
{
    // Optimizes standard I/O streams performance for competitive tasks
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int total_vertices, total_edges;
    input_graph_data(total_vertices, total_edges);

    int total_cost = compute_kruskal_mst(total_vertices);
    display_mst_results(total_cost);

    return 0;
}