#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <queue>
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

    int Get_ID(const TVertex& target) const 
    {
        for (int i = 0; i < example.size(); ++i) 
        {
            if (example[i].data == target)
                return i;
        }
        return -1;
    }

    void Add_Vertex(const TVertex& source) 
    {
        if (Get_ID(source) == -1) 
        {
            example.push_back(Vertex(source));
        }
        else 
            throw "This city has already been built";
    }

    void Add_Edge(const TVertex& source, const TVertex& destination, const TEdge& new_edge) 
    {
        int id_source = Get_ID(source);
        int id_destination = Get_ID(destination);
        if ((id_source == -1) || (id_destination == -1)) 
            throw "This road has already been built";
        example[id_source].edges.push_back(Edge(new_edge, destination));
    }

    void Delete_Vertex(const TVertex& target) 
    {
        int id_vertex = Get_ID(target);
        if (id_vertex == -1) throw "There is no such city";
        for (auto it_vertex = example.begin(); it_vertex != example.end(); ) 
        {
            if (it_vertex->data == target) 
            {
                it_vertex = example.erase(it_vertex);
            }
            else 
            {
                for (auto it_edge = (*it_vertex).edges.begin();
                    it_edge != (*it_vertex).edges.end(); ) 
                {
                    if (it_edge->dest == target) it_edge = (*it_vertex).edges.erase(it_edge);
                    else ++it_edge;
                }
                ++it_vertex;
            }
        }
    }

    void Delete_Edge(const TVertex& source, const TVertex& destination) 
    {
        int id_source = Get_ID(source);
        int id_destination = Get_ID(destination);
        if ((id_source == -1) || (id_destination == -1)) 
            throw "This is no such road";
        for (auto it = example[id_source].edges.begin(); it != example[id_source].edges.end(); ) 
        {
            if (it->dest == destination) 
            {
                example[id_source].edges.erase(it);
                break;
            }
            else ++it;
        }
    }

    void Print() 
    {
        for (size_t i = 0; i < example.size(); ++i) 
        {
            cout << "City: " << endl;
            cout << example[i].data << endl;
            cout << "Roads from this city:" << endl;
            if (example[i].edges.begin() == example[i].edges.end()) 
            {
                cout << "No roads" << endl;
            }
            for (auto elem : example[i].edges) 
            {
                cout << "   " << "Destination: " << elem.dest << " ===> " << "Length: " << elem.data << " km" << endl;
            }
            cout << endl;
        }
    }

    void BFS(const TVertex& from) 
    {
        if (Get_ID(from) == -1) 
            throw "There is no such city";
        for (auto elem : example) 
        {
            elem.colour = false;
        }
        queue<Vertex> q;
        Vertex s = example[Get_ID(from)];
        q.push(s);
        s.colour = true;
        while (!q.empty()) 
        {
            Vertex u = q.front();
            q.pop();
            for (auto elem : u.edges) 
            {
                Vertex& v = example[Get_ID(elem.dest)];
                if (v.colour == false) 
                {
                    v.colour = true;
                    q.push(v);
                }
            }
            cout << u.data << endl;
        }
    }

    void Dijkstra(const TVertex& src, const TVertex& dst)
    {

    }

};