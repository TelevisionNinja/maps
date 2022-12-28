#include <graph.hpp> 
#include <sort.hpp> 
#include <disjoint_set.hpp>
#include <queue>

struct EdgeKeyComparison {
    constexpr bool operator()(const Edge &a, const Edge &b) const noexcept {
        return a.w > b.w;
    }
};

std::vector<Edge> constructMSTPrim(Graph G) {
    std::vector<Edge> edges = G.exportEdges(); // Graph's edges

    // use heap to optimize the minimum searching
    //      Insert: heap.push(Edge(u, -1, distance));
    //      Get Minimum: top = heap.top(); u = top.u; distance = top.w;
    //      Remove top: heap.pop(); (this function usually goes after the get minimum method)

    // heap version
    std::priority_queue< Edge, std::vector<Edge>, EdgeKeyComparison > heap;
    std::vector<Edge> MST;

    // T = { 0 }
    G.setVisited(0);

    for (int v = 0; v < G.n; v++) { // V is a set of vertices of G
        // if G has an edge (0, v)
        bool found = false;

        for (int j = 0; j < G.e[0].size(); j++) {
            Edge searchingEdge = G.e[0][j];

            if (searchingEdge.v == v) {
                // Insert
                heap.push(Edge(0, v, searchingEdge.w));
                // distance[v] = w(0, v) and parent[v] = 0
                found = true;
                break;
            }
        }

        if (!found) {
            // Insert
            heap.push(Edge(-1, v, std::numeric_limits<int>::max()));
            // distance[v] = infinity and parent[v] = -1
        }
    }

    while (!heap.empty()) {
        // Get the minimum
        Edge top = heap.top(); // u = u in V \ T where u has the minimum distance
        int parent = top.u;
        int u = top.v;
        int distance = top.w;

        // Remove top
        heap.pop();

        // detect visited vertices
        if (!G.isVisited(u)) {
            // detect disjoint vertex
            if (parent == -1) {
                parent = u;
                distance = 0;
            }

            // MST = MST union {(parent[u], u, w(u, parent[u]))}
            MST.push_back(Edge(parent, u, distance));

            // T = T union {u}
            G.setVisited(u);

            // for each vertex v in V \ T
            for (int j = 0; j < G.e[u].size(); j++) {
                Edge searchingEdge = G.e[u][j];
                int v = searchingEdge.v;
                
                // if G has an edge (u, v) and w(u, v) < distance[v]
                if (!G.isVisited(v)) {
                    // Insert
                    heap.push(Edge(u, v, searchingEdge.w));
                    // distance[v] = w(u, v) and parent[v] = u
                }
            }
        }
    }

    return MST;
}
