#include <iostream>
#include <chrono>
#include <exception>
#include "Set.h"

using namespace std;

struct steady_clock;

int main()
{
	Set r;
	r.Insert(1);
	r.Insert(6);
	r.Insert(7);
	r.Insert(5);
	r.Insert(-6);
	//r.Insert(10);
	//r.Insert(20);
	//r.Insert(3);
	r.Print();
	cout << endl << "==================" << endl;
	cout << r.Find(1000) << endl;
	cout << r.Find(6) << endl;
	cout << "==================" << endl;
	r.Erase(7);
	r.Erase(15);
	r.Print();

	//Set r;
	//std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	//std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	//for (int i = 0; i < 10; i++)
	//{
	//	begin = std::chrono::steady_clock::now();
	//	for (int j = 1; j < 100000; j++)
	//	{
	//		r.Insert(i * 100000 + j);
	//	}
	//	end = std::chrono::steady_clock::now();
	//	std::cout << "Diff(ms) = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;
	//}
	//std::cout « "Diff(mcs) = " « std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() « std::endl;
	//std::cout « "Diff(ns) = " « std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() « std::endl;
	return 0;
}