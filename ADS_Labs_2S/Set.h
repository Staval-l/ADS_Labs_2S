#pragma once
#include <iostream>

struct Tree {
	int key;
	Tree* left;
	Tree* right;
	unsigned height;
};

class Set {
	Tree* root;
public:
	Set();
	~Set();
	void Print() const;
	bool Insert(int key);
	bool Find(int key) const;
	bool Erase(int key);
};