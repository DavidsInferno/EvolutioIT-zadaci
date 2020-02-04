#include<iostream>
using namespace std;

int hittingTheTarget(int niz[], int arraySize, int target);


int main()
{
	int* numbers = NULL;
	int arraySize = 0;
	int target = 0;

	cout << "Size of the array: ";
	cin >> arraySize;
	numbers = new int[arraySize];


	cout << "\nWhat numbers do you want in your array: ";
	for (int i = 0;i < arraySize;i++) {
		cin >> numbers[i];
	}

	cout << "Target number: ";
	cin >> target;	

	cout << "\nLeast ammount of steps: "<<hittingTheTarget(numbers, arraySize, target);	
	return 0;
}



int hittingTheTarget(int niz[], int arraySize, int target)
{
	if (target == 0)
		return 0;

	int res = INT_MAX;

	for (int i = 0; i < arraySize; i++)
	{
		if (niz[i] <= target)
		{
			int sub_res = hittingTheTarget(niz, arraySize, target - niz[i]);

			if (sub_res != INT_MAX && sub_res + 1 < res)
				res = sub_res + 1;
		}
	}

	if (res == INT_MAX) {
		return -1;
	}
	else
		return res;
}
