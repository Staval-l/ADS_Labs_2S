#include <iostream>
#include <vector>

using namespace std;

struct Stats {
	size_t copy_count = 0;
	size_t compare_count = 0;
};

Stats Bubble_Sort(vector<int> &value)
{
	Stats res;
	for (size_t i = 0; i < value.size() - 1; i++)
	{
		for (size_t j = 0; j < value.size() - 1 - i; j++)
		{
			res.compare_count++;
			if (value[j] > value[j + 1])
			{
				int tmp = value[j];
				value[j] = value[j + 1];
				value[j + 1] = tmp;
				res.copy_count++;
			}
		}
	}
	cout << "Compare count: " << res.compare_count << endl;
	cout << "Copy count: " << res.copy_count << endl;
	return res;
}

int main()
{
	Stats s;
	vector<int> v1 = { 17,1,9,8,5,4,1,5,26,88, 7 };
	for (auto i = v1.begin(); i != v1.end(); ++i)
	{
		cout << *i << " ";
	}
	cout << endl;
	s = Bubble_Sort(v1);
	for (auto i = v1.begin(); i != v1.end(); ++i)
	{
		cout << *i << " ";
	}
	cout << endl;
	return 0;
}