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

vector<int> Merge(vector<int>& v1, vector<int>& v2, Stats& stat)
{
	vector<int> ret(v1.size() + v2.size()); 
	size_t i = 0; 
	size_t j = 0; 
	size_t k = 0; 
	while (k != v1.size() + v2.size())
	{
		if (i == v1.size())
		{
			ret[k] = v2[j];
			j++;
			k++;
			stat.copy_count++;
			continue;
		}
		if (j == v2.size())
		{
			ret[k] = v1[i];
			i++;
			k++;
			stat.copy_count++;
			continue;
		}
		if (v1[i] < v2[j])
		{
			ret[k] = v1[i];
			i++;
		}
		else
		{
			ret[k] = v2[j];
			j++;

		}
		stat.copy_count++;
		stat.compare_count++;
		k++;
	}
	return ret;
}

Stats Naturial_Two_Way_Merge_Sort(vector<int>& value, Stats stat)
{
	if (value.size() == 1) return stat;
	vector<int> tmp(value.size());
	bool count = true; 
	size_t l_old = 0; 
	size_t r_old = value.size() - 1;
	size_t l_new = 0; 
	size_t r_new = value.size() - 1;
	while (l_old < r_old)
	{
		vector<int> tmp_1;
		vector<int> tmp_2;
		while ((value[l_old] <= value[l_old + 1]) && (l_old < r_old) && (l_old < value.size()))
		{
			tmp_1.push_back(value[l_old]);
			l_old++;
			stat.compare_count++;
		}
		tmp_1.push_back(value[l_old]);
		l_old++;
		while ((value[r_old] <= value[r_old - 1]) && (l_old < r_old) && (r_old >= 0))
		{
			tmp_2.push_back(value[r_old]);
			r_old--;
			stat.compare_count++;
		}
		if (l_old <= r_old)
		{
			tmp_2.push_back(value[r_old]);
			r_old--;
		}
		vector<int> tmp_0;
		tmp_0 = Merge(tmp_1, tmp_2, stat);
		if (count)
		{
			for (size_t i = 0; i < tmp_0.size(); l_new++)
			{
				tmp[l_new] = tmp_0[i];
				i++;
				stat.copy_count++;
			}
			l_new = l_new + tmp_0.size();
			count = false;
		}
		else 
		{
			for (size_t i = 0; i < tmp_0.size(); r_new--)
			{
				tmp[r_new] = tmp_0[i];
				i++;
				stat.copy_count++;
			}
			r_new = r_new - tmp_0.size();
			count = true;
		}
		if (tmp_0.size() == value.size())
		{
			value = tmp;
			stat.copy_count += tmp.size();
			return stat;
		}
	}
	if (l_old != value.size())
	{
		stat = Naturial_Two_Way_Merge_Sort(tmp, stat);
	}
	value = tmp;
	stat.copy_count += tmp.size();
	return stat;
}

int main()
{
	srand(time(NULL));
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
	cout << endl << endl;

	vector<int> v3(3);
	for (auto i = v3.begin(); i != v3.end(); ++i)
	{
		cin >> *i;
	}
	/*for (auto i = v3.begin(); i != v3.end(); ++i)
	{
		*i = rand() % 100;
	}*/
	for (auto i = v3.begin(); i != v3.end(); ++i)
	{
		cout << *i << " ";
	}
	cout << "\n";
	Stats null;
	s = Naturial_Two_Way_Merge_Sort(v3, null);
	cout << "Number of comparisons: " << s.compare_count << endl;
	cout << "Number of copies: " << s.copy_count << endl;
	for (auto i = v3.begin(); i != v3.end(); ++i)
	{
		std::cout << *i << " ";
	}
	cout << "\n";
	return 0;
}