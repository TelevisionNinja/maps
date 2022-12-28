#include <graph.hpp>
#include <queue>

struct EdgeKeyComparison {
    constexpr bool operator()(const Edge &a, const Edge &b) const noexcept {
        return a.w > b.w;
    }
};

std::vector<int> searchShortestPath(Graph &G, int start, int destination) {
    // use heap to optimize the minimum searching
    //      Insert: heap.push(Edge(u, -1, distance));
    //      Get Minimum: top = heap.top(); u = top.u; distance = top.w;
    //      Remove top: heap.pop(); (this function usually goes after the get minimum method)

    // heap version
    std::priority_queue< Edge, std::vector<Edge>, EdgeKeyComparison > heap;
    int parentArr[G.n];

    // fill parent array with default values
    for (int v = 0; v < G.n; v++) { // V is a set of vertices of G
        parentArr[v] = -1;
    }

    // distance[start] = 0
    heap.push(Edge(-1, start, 0));

    while (!heap.empty()) {
        // Get the minimum
        Edge top = heap.top(); // u = u in V and v is not visitied where u has the minimum distance
        int parent = top.u;
        int u = top.v;
        int distance = top.w;

        // Break if u is a destination
        if (u == destination) {
            // fill in the parent array
            parentArr[u] = parent;
            break;
        }

        // Remove top
        heap.pop();

        // detect visited vertices
        if (!G.isVisited(u)) {
            // fill in the parent array
            parentArr[u] = parent;

            // visited[u] = true
            G.setVisited(u);

            // for each vertex v in the adjacency list of u
            for (int j = 0; j < G.e[u].size(); j++) {
                Edge e = G.e[u][j];

                if (!G.isVisited(e.v)) {
                    // Insert
                    heap.push(Edge(u, e.v, e.w + distance));
                    // distance[v] = distance[u] + w(u, v) and parent[v] = u
                }                
            }
        }
    }

    std::vector<int> Path;
    int u = destination;

    while (u != -1) {
        // Path = { u } union Path
        Path.insert(Path.begin(), u);
        u = parentArr[u];
    }

    return Path;
}
