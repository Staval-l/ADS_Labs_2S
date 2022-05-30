#pragma once

#include <iostream>
#include <vector>
#include <list>
//#include <exception>
//#include <queue>
//#include <map>

using namespace std;

template<typename TVertex, typename TEdge>
class Graph {

    struct Edge {
        TEdge data;
        TVertex dest;

        Edge(const TEdge& new_data, const TVertex& destination) : data(new_data), dest(destination) {}

        Edge(const Edge& rhs) {
            data = rhs.data;
            dest = rhs.dest;
        }
    };

    struct Vertex {
        TVertex data;
        list<Edge> edges;
        bool colour;

        Vertex(const TVertex& data) : data(data), colour(false) {}

        Vertex(const Vertex& rhs) {
            data = rhs.data;
            edges = rhs.edges;
            colour = rhs.colour;
        }
    };

    vector<Vertex> example;

public:
    
};