#include <iostream>
#include "Set.h"

using namespace std;

Tree* Set::_Insert(Tree* root, int key)
{

}

Tree* Set::_Erase_elem(Tree* root, int key)
{

}

void Set::_Delete_tree(Tree* root)
{

}

void Set::_Print(Tree* root, int step) const
{

}

unsigned Set::_Height(Tree* root)
{

}

void Set::_Fix_height(Tree* root)
{

}

int Set::_Balance_factor(Tree* root)
{

}

Tree* Set::_Balance(Tree* root)
{

}

Tree* Set::_Rotate_left(Tree* root)
{

}

Tree* Set::_Rotate_right(Tree* root)
{

}

Set::Set()
{
	root = nullptr;
}

Set::~Set()
{
	_Delete_tree(root);
	root = nullptr;
}

void Set::Print() const
{
	if(root)
	{
		_Print(root, 0);
	}
	else
	{
		cout << "Tree is empty";
	}
}

bool Set::Insert(int key)
{
	root = _Insert(root, key);
	return true;
}

bool Set::Find(int key) const
{
	if (!root) 
	{ 
		cout << "Tree is empty";
		return false; 
	}
	Tree* temp = root;
	while (temp != nullptr)
	{
		if (key < temp->key)
		{
			temp = temp->left;
		}
		else if (key > temp->key)
		{
			temp = temp->right;
		}
		else if (key == temp->key)
		{
			return true;
		}
		else
		{
			throw "The element doesn't exist";
		}
	}
}

bool Set::Erase(int key)
{
	root = _Erase_elem(root, key);
	return true;
}