#include <iostream>
using namespace std;

///  I changed all of the template functions to int values for testing purposes
/// the algorithms all work and are as efficient as I can make them without actually
/// deep dive researching sorting and searching algorithms.

Template<typename T>
void insert(T sortedList[], int n, T value);
// This function inserts the "value" in the "sortedList" including "n" values sorted in ascending order; the list must be remained sorted at the end of the execution of the function. It is assumed that the list has enough room for the new value.
Template<typename T>
void remove(T sortedList[], int &n, T value); 
// Assuming that the "sortedList" is a list of "n" values sorted in ascending order, this function removes the "value" from the list (if exists); the list must be remained sorted at the end of the execution of the function.
Template<typename T>
void remove1(T unorderedSeq[], int &n, T value); 
// Assuming that the "unorderedSeq" is an unordered sequence of "n" distinct values, this function rem

int main() {
	//insert(ta,  9, 11);
	//int ta[10] ={ 3, 5, 6, 7, 9, 11, 13, 16, 17,  0 };
	int ta1[10] ={ 13, 35, 6, 7, 9, 1, 11, 2, 17,  0 };
	remove1(ta1, 10, 11);
	return 0;
}
Template<typename T>
void insert(T sortedList[], int n, T value)
{
	/// x  is the tracker for binary sort
	int x = n / 2;
	/// g and r are both temporary holders for T objects, could be pointers
	T g;
	T r;
	bool check = false;
	while (!check) {
		
		/// the following 2 if blocks check to see if the value to be inserted is 
		/// greater or less than the current value for x
		/// and increasing/decreasing the value of x until it collapses onto the correct value
		/// 
		/// O(log(n)
		/// 
		if (value < sortedList[x]) {
			if (value > sortedList[x - 1])
			{
				g = sortedList[x];
				sortedList[x] = value;
				check = true;
			}
			else
				x -= (x / 2);
		}
		else if (value > sortedList[x])
		{
			if (value < sortedList[x + 1])
			{
				g = sortedList[x];
				sortedList[x] = value;
				check = true;
			}
			else
				x += (x / 2);
	}
	/// for all the values greater than the value to be inserted use the 
	/// temporary variables g and r to shuffle them by one 
	/// 
	/// O(n)
	/// Theres probably a faster way to do this
	/// 
	for (int l = x + 1; l < n + 1; l++)
	{
		r = sortedList[l];
		sortedList[l] = g;
		g = r;
	}

	}
};

template<typename T>
void insert(T sortedList[], int n, T value){
    int low = 0;
    int high = n;
    int mid = 0;
    bool flag = false;
//I mixed binary search with bubble swap
    while (high >= low && !flag) {
        mid = (low + high) / 2;
        if (value < sortedList[mid])
            high = mid - 1;
        else if (value == sortedList[mid]){
	    mid++;
            flag = true;
//if the value is already in the list we can insert it right after it
        }
        else
            low = mid + 1;
    }
//after finding out where it should go, we can shuffle what we need to down then insert at the "mid" idex
    for(int i = n; i > mid; i--){
        swap(sortedList[i],sortedList[i - 1]);
    }
    sortedList[mid] = value;
// time complexity: W(n) = O(n) .. B(n) = O(log(n))
}



Template<typename T>
void remove(T sortedList[], int &n, T value)
{
	/// Usint binary search again
	int x = n / 2;
	bool check = false;
	/// O (log n)
	while (sortedList[x] != value ) {

		if (sortedList[x] < value) {
			x += x / 2;
		}
		else if (sortedList[x] > value)
		{
			x -= x / 2;
		}
	}
    /// reindexing the values larger than n 
	///
	/// O(n)
	for(int i = x; i < n-1; i++){
		sortedList[i] = sortedList[i + 1];
	}
};

template<typename T>
void remove(T sortedList[], int& n, T value){
    int low = 0;
    int high = n;
    int mid = 0;
    bool flag = false;
// I'm just using the same algorithm for the insert ftn
    while (high >= low && !flag) {
        mid = (low + high) / 2;
        if (value < sortedList[mid])
            high = mid - 1;
        else if (value == sortedList[mid]){
//Here I immediately start swapping then I terminate the while loop with setting the flag to true
            for(int i = mid + 1; i < n; i++)
                swap(sortedList[i],sortedList[i - 1]);
            n--;
            flag = true;
        }
        else
            low = mid + 1;
// If the item isn't in the list then nothing happens
    }
// Time complexity: W(n) = O(n) .. B(n) = O(log(n))
}



Template<typename T>
void remove1(T unorderedSeq[], int &n, T value)
{
	/// I couldnt think of any way to do this faster than linear 
	/// 
	/// O(n)
	for (int i = 0; i < n; i++)
	{
		cout << unorderedSeq[i];
		if (unorderedSeq[i] == value) {
			for (int g = i; g < n; g++)
			{
				unorderedSeq[g] = unorderedSeq[g + 1];

			}
			cout << endl;
			for (int m = 0; m < n-1; m++) {
				cout << unorderedSeq[m] << " ";
			}
			i = n;
		}
	}

}
