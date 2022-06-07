#include <iostream>
#include <string>
#include "Graph.h"

using namespace std;

int main() 
{
	Graph<Vertex, Edge> G;
	G.AddVertex(Vertex("London", 15));
	G.AddVertex(Vertex("Paris", 13));
	G.AddVertex(Vertex("Berlin", 10));
	G.AddVertex(Vertex("Madrid", 8));
	G.AddVertex(Vertex("Praha", 5));
	G.AddVertex(Vertex("Kiev", 7));
	G.AddVertex(Vertex("Riga", 4));
	G.AddVertex(Vertex("Amsterdam", 6));
	/*G.Print();
	G.DeleteVertex(Vertex("London", 15));
	G.Print();*/
	G.AddEdge(Vertex("London", 15), Vertex("Paris", 13), Edge("Paris", 100));
	G.AddEdge(Vertex("London", 15), Vertex("Berlin", 10), Edge("Berlin", 33));
	G.AddEdge(Vertex("London", 15), Vertex("Riga", 4), Edge("Riga", 27));
	G.AddEdge(Vertex("Paris", 13), Vertex("Praha", 5), Edge("Praha", 16));
	G.AddEdge(Vertex("Paris", 13), Vertex("Kiev", 7), Edge("Kiev", 9));
	G.AddEdge(Vertex("Madrid", 8), Vertex("London", 15), Edge("London", 11));
	G.AddEdge(Vertex("Madrid", 8), Vertex("Riga", 4), Edge("Riga", 49));
	G.AddEdge(Vertex("Madrid", 8), Vertex("Kiev", 7), Edge("Kiev", 78));
	G.AddEdge(Vertex("Praha", 5), Vertex("Paris", 13), Edge("Paris", 5));
	G.AddEdge(Vertex("Praha", 5), Vertex("Berlin", 10), Edge("Berlin", 81));
	G.AddEdge(Vertex("Praha", 5), Vertex("Kiev", 7), Edge("Kiev", 1));
	G.AddEdge(Vertex("Kiev", 7), Vertex("Berlin", 10), Edge("Berlin", 21));
	G.AddEdge(Vertex("Kiev", 7), Vertex("London", 15), Edge("London", 37));
	G.AddEdge(Vertex("Berlin", 10), Vertex("Riga", 4), Edge("Riga", 21));
	G.AddEdge(Vertex("Berlin", 10), Vertex("Madrid", 8), Edge("Madrid", 20));
	G.AddEdge(Vertex("Amsterdam", 6), Vertex("London", 15), Edge("London", 115));
	G.AddEdge(Vertex("Amsterdam", 6), Vertex("Berlin", 10), Edge("Berlin", 63));
	G.AddEdge(Vertex("Amsterdam", 6), Vertex("Madrid", 8), Edge("Madrid", 21));
	G.AddEdge(Vertex("Riga", 4), Vertex("London", 15), Edge("London", 125));
	G.AddEdge(Vertex("Riga", 4), Vertex("Amsterdam", 6), Edge("Amsterdam", 50));
	G.Print();
	/*G.DeleteEdge(Vertex("Praha", 5), Vertex("Kiev", 7));
	G.Print();*/
	try
	{
		G.BFS(Vertex("London", 15));
	}
	catch (const char* err)
	{
		cout << err << endl;
	}
	vector<Vertex> path = G.Dijkstra(Vertex("Riga", 4), Vertex("London", 15));
	return 0;
}