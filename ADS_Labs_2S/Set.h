#pragma once
#include <iostream>

struct Tree {

};

class Set {

public:
	void Print() const;
	bool Insert(int key);
	bool Find(int key) const;
	bool Erase(int key);
};