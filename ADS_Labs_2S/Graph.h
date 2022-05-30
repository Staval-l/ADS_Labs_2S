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

    int Get_ID(const TVertex& target) const {
        for (int i = 0; i < example.size(); ++i) {
            if (example[i].data == target)
                return i;
        }
        return -1;
    }

    void Add_Vertex(const TVertex& source) {
        if (Get_ID(source) == -1) {
            example.push_back(Vertex(source));
        }
        else throw exception();
    }

    void Add_Edge(const TVertex& source, const TVertex& destination, const TEdge& new_edge) {
        int id_source = Get_ID(source);
        int id_destination = Get_ID(destination);
        if ((id_source == -1) || (id_destination == -1)) throw exception();
        example[id_source].edges.push_back(Edge(new_edge, destination));
    }

    void Delete_Vertex(const TVertex& target) {
        int id_vertex = Get_ID(target);
        if (id_vertex == -1) throw exception();
        for (auto it_vertex = example.begin(); it_vertex != example.end(); ) {
            if (it_vertex->data == target) {
                it_vertex = example.erase(it_vertex);
            }
            else {
                for (auto it_edge = (*it_vertex).edges.begin();
                    it_edge != (*it_vertex).edges.end(); ) {
                    if (it_edge->dest == target) it_edge = (*it_vertex).edges.erase(it_edge);
                    else ++it_edge;
                }
                ++it_vertex;
            }
        }
    }

    void Delete_Edge(const TVertex& source, const TVertex& destination) {
        int id_source = Get_ID(source);
        int id_destination = Get_ID(destination);
        if ((id_source == -1) || (id_destination == -1)) throw exception();
        for (auto it = example[id_source].edges.begin(); it != example[id_source].edges.end(); ) {
            if (it->dest == destination) {
                example[id_source].edges.erase(it);
                break;
            }
            else ++it;
        }
    }

};