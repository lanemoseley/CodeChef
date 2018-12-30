#include <iostream>

using namespace std;

int main()
{
	int cases, rows, num, i, j, count, val;
	int **arr;

	cin >> cases;
	while (cases--)
	{
		cin >> num;

		rows = 2 * num - 1;

		// creating 2d array
		arr = new (nothrow) int *[rows];
		if (arr == nullptr)
		{
			delete[] arr;
			return 0;
		}

		for (i = 0; i < rows; ++i)
		{
			arr[i] = new (nothrow) int[num];
			if (arr[i] == nullptr)
			{
				for (j = 0; j < i; ++j)
					delete[] arr[j];

				delete[] arr;

				return 0;
			}
		}

		// initializing array with zeroes
		for (i = 0; i < rows; ++i)
		{
			for (j = 0; j < num; ++j)
			{
				arr[i][j] = 0;
			}
		}

		// filling array
		count = 1;
		val = 1;
		for (i = 0; i < num; ++i)
		{
			for (j = 0; j < num && j < count; ++j)
			{
				arr[i][j] = val;
				++val;
			}
			++count;
		}

		count = num - 1;
		int shift = 1;
		for (i = num; i < rows; ++i)
		{
			for (j = 0; j < num && j < count; ++j)
			{
				arr[i][shift + j] = val;
				++val;
			}
			--count;
			++shift;
		}

		// printing to standards
		count = 0;
		for (j = 0; j < num; ++j)
		{
			for (i = 0; i < rows; ++i)
			{
				if (arr[i][j] != 0)
				{
					cout << arr[i][j];
					if (count == num - 1)
					{
						cout << endl;
						count = 0;
					}
					else
					{
						cout << " ";
						++count;
					}
				}
			}
		}
	}


	return 0;
}