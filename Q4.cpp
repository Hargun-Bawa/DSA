#include <iostream>
using namespace std;

Template<typename T>
void sort(T[], int);

int main()
{
	int test[8] = {6,2,7,18,9,75,1,61};

	sort(test, 8);
	for(int i = 0; i < 8; i++)
	{
		cout << test[i] << " ";
	}
}
Template<typename T>
void sort(T list[], int size)
{
	/// temporary array of T 
	T* temp = new T[size];
	int smaller = 0;
	/// was trying to do something clever where if an array
	/// had a smallest element found, it would no longer be compared
	/// to the rest of the array
	int smallest = 0;
	for(int i = 0; i < size; i++)
	{
		/// value being tested
		T tester = list[i];
		///reiterate through the loop to compare values
		///and find smallest
		for(int g = 0; g < size; g++)
		{
			if(list[g] < tester)
			{
				smaller += 1;
			}
		}
		if (smaller == smallest){
			smallest +=1;
		}
		temp[smaller] = tester;
		smaller = 0;
	}
	for(int i =0; i < 8; i++)
	{
		list[i] =temp[i];
	}
}

	/*bool check = false;
	 * while(!check)
	 * {
	 * 	for(int i = 
	 */

