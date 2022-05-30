#include <iostream>
#include <vector>
#include <string>
#include "Graph.h"

using namespace std;

int main()
{
	Graph<std::string, double> elem;
    elem.Add_Vertex("Samara");
    elem.Add_Vertex("Saint-Peterburg");
    elem.Add_Vertex("Moscow");
    elem.Add_Vertex("Minsk");
    elem.Add_Vertex("Kiev");
    elem.Add_Vertex("Omsk");
    elem.Add_Vertex("Vladivostok");
    elem.Add_Edge("Samara", "Saint-Peterburg", 1740);
    elem.Add_Edge("Moscow", "Saint-Peterburg", 780);
    elem.Add_Edge("Samara", "Moscow", 1055);
    elem.Add_Edge("Moscow", "Minsk", 1378);
    elem.Add_Edge("Minsk", "Saint-Peterburg", 1100);
    elem.Add_Edge("Minsk", "Kiev", 655);
    elem.Add_Edge("Vladivostok", "Omsk", 5000);
    elem.Add_Edge("Saint-Peterburg", "Vladivostok", 11987);

    elem.Print();

    cout << "===========================" << endl;
    elem.Delete_Edge("Samara", "Saint-Peterburg");
    elem.Print();

	return 0;
}