#include <graph.hpp> 
#include <sort.hpp> 
#include <disjoint_set.hpp>

std::vector<Edge> constructMSTKruskal(Graph G) {
    std::vector<Edge> edges = G.exportEdges(); // Graph's edges

    // Use Disjoint Set to check wheter two vertices are on the same set
    // Usage: Check djs.isOnSameSet(u, v); Check is u and v is on the same set or not
    //              djs.join(u, v); Join sets of u and v into the same set

    DisjointSet djs(G.n);

    // Sort list of edges in the increasing order of edge's weight
    sort(edges, 0, edges.size());

    std::vector<Edge> MST;

    // for each edge e in sorted list of edges
    for (int i = 0; i < edges.size(); i++) {
        Edge e = edges[i];

        // if u and v of e is not connected on T
        if (!djs.isOnSameSet(e.u, e.v)) {// Check is u and v is on the same set or not
            // MST = MST union {(u, v, w(u, v)}
            MST.push_back(e);

            // T = T union {u, v}
            djs.join(e.u, e.v); // Join sets of u and v into the same set
        }
    }

    return MST;
}
