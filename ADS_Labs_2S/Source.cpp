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

Stats Shell_Sort(vector<int>& value)
{
	Stats res;
	for (size_t i = value.size() / 2; i > 0; i /= 2)
	{
		for (size_t j = i; j < value.size(); ++j)
		{
			res.compare_count++;
			for (int t = j - i; t >= 0 && value[t] > value[t + i]; t -= i)
			{
				int tmp = value[t];
				value[t] = value[t + i];
				value[t + i] = tmp;
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
	vector<int> v1 = { 17,1,9,8,5,4,1,5,26,88,7 };
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
	cout << endl << endl;
	vector<int> v2 = { 17,1,9,8,5,4,1,5,26,88,7 };
	for (auto i = v2.begin(); i != v2.end(); ++i)
	{
		cout << *i << " ";
	}
	cout << endl;
	s = Shell_Sort(v2);
	for (auto i = v2.begin(); i != v2.end(); ++i)
	{
		cout << *i << " ";
	}
	cout << endl;
	return 0;
}