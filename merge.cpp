

#include <iostream>

template <typename T>
void mergeList(T*& array1, T*& array2, int size1, int size2, T*& array3) 
{
    int i = 0;
    int j = 0;
    int k = 0;

    while ((i < size1) && (j < size2)) {
        if (array1[i] > array2[j]) {
            array3[k++] = array2[j++];
        }
        else {
            array3[k++] = array1[i++];
        }
    }
    while (i < size1) {
        array3[k++] = array1[i++];
    }
    while (j < size2) {
        array3[k++] = array2[j++];
    }
};

int main()
{ 
    int size1 = 4;
    int size2 = 6;
    int * arr1 = new int[size1] {5,6,7,8};
    int * arr2 = new int[size2] { 2,3,4,7,10,11 };
    int * arr3 = new int[size1 + size2];
    mergeList(arr1, arr2, size1, size2, arr3);
    int size3 = size1 + size2;
    for (int i = 0; i < size3; i++) {
        std::cout << arr3[i] << std::endl;
    }
    delete[] arr3;
}