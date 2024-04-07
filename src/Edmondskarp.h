#ifndef DA_PROJ1_EDMONDSKARP_H
#define DA_PROJ1_EDMONDSKARP_H

#include "../data_structures/Graph.h"


/**
 * @brief Test the given vertex 'w' and visit it if conditions are met.
 * @param q Reference to the queue of vertices.
 * @param e Pointer to the edge.
 * @param w Pointer to the vertex.
 * @param residual Residual capacity.
 * @complexity O(1).
 */
inline void testAndVisit(std::queue< Vertex<string>*> &q, Edge<string> *e, Vertex<string> *w, double residual) {
// Check if the vertex 'w' is not visited and there is residual capacity
    if (! w->isVisited() && residual > 0) {
// Mark 'w' as visited, set the path through which it was reached, and enqueue it
        w->setVisited(true);
        w->setPath(e);
        q.push(w);
    }
}

/**
 * @brief Find an augmenting path using Breadth-First Search.
 * @param g Reference to the graph.
 * @param s Pointer to the source vertex.
 * @param t Pointer to the target vertex.
 * @return True if an augmenting path is found, false otherwise.
 * @complexity O(V + E) where V equals the number of vertexes and E the number of edges in the graph.
 */
inline bool findAugmentingPath(Graph<string>& g, Vertex<string> *s, Vertex<string> *t) {
// Mark all vertices as not visited
    for(auto v : g.getVertexSet()) {
        v->setVisited(false);
    }
// Mark the source vertex as visited and enqueue it
    s->setVisited(true);
    std::queue<Vertex<string> *> q;
    q.push(s);
// BFS to find an augmenting path
    while( ! q.empty() && ! t->isVisited()) {
        auto v = q.front();
        q.pop();
// Process outgoing edges
        for(auto e: v->getAdj()) {
            testAndVisit(q, e, e->getDest(), e->getWeight() - e->getFlow());
        }
// Process incoming edges
        for(auto e: v->getIncoming()) {
            testAndVisit(q, e, e->getOrig(), e->getFlow());
        }
    }
// Return true if a path to the target is found, false otherwise
    return t->isVisited();
}

/**
 * @brief Find the minimum residual capacity along the path.
 * @param s Pointer to the source vertex.
 * @param t Pointer to the target vertex.
 * @return Minimum residual capacity.
 * @complexity O(V) where V equals the number of vertexes in the graph.
 */
inline double findMinResidualAlongPath(Vertex<string> *s, Vertex<string> *t) {
    double f = INF;
// Traverse the augmenting path to find the minimum residual capacity
    for (auto v = t; v != s; ) {
        auto e = v->getPath();
        if (e->getDest() == v) {
            f = std::min(f, e->getWeight() - e->getFlow());
            v = e->getOrig();
        }
        else {
            f = std::min(f, e->getFlow());
            v = e->getDest();
        }
    }
// Return the minimum residual capacity
    return f;
}

/**
 * @brief Augment flow along the augmenting path with the given flow value.
 * @param s Pointer to the source vertex.
 * @param t Pointer to the target vertex.
 * @param f Flow value.
 * @complexity O(V) where V equals the number of vertexes in the graph.
 */
inline void augmentFlowAlongPath(Vertex<string> *s, Vertex<string> *t, double f) {
// Traverse the augmenting path and update the flow values accordingly
    for (auto v = t; v != s; ) {
        auto e = v->getPath();
        double flow = e->getFlow();
        if (e->getDest() == v) {
            e->setFlow(flow + f);
            v = e->getOrig();
        }
        else {
            e->setFlow(flow - f);
            v = e->getDest();
        }
    }
}

/**
 * @brief Implementation of the Edmonds-Karp algorithm for finding maximum flow in a graph.
 * @param g Reference to the graph.
 * @param source Source vertex identifier.
 * @param target Target vertex identifier.
 * @complexity O(V * E^2) where V equals the number of vertexes and E the number of edges in the graph.
 */
inline void edmondsKarp(Graph<string>& g, const string& source, const string& target) {
// Find source and target vertices in the graph
    Vertex<string>* s = g.findVertex(source);
    Vertex<string>* t = g.findVertex(target);
// Validate source and target vertices
    if (s == nullptr || t == nullptr || s == t)
        throw std::logic_error("Invalid source and/or target vertex");
// Initialize flow on all edges to 0
    for (auto v : g.getVertexSet()) {
        for (auto e: v->getAdj()) {
            e->setFlow(0);
        }
    }
// While there is an augmenting path, augment the flow along the path
    while( findAugmentingPath(g, s, t) ) {
        double f = findMinResidualAlongPath(s, t);
        augmentFlowAlongPath(s, t, f);
    }
}

#endif //DA_PROJ1_EDMONDSKARP_H
