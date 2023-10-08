

#include <iostream>

template <typename T>
void mergeList(T*& array1, T*& array2, int size1, int size2, T*& array3) 
{
    int i = 0;
    int j = 0;
    int k = 0;

    while ((i < size1) && (j < size2)) {
        if (array1[i] >= array2[j]) {
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

//This function combines two linked lists and stores the result in firstList.
template <typename T>
void mergeList(LinkedList<T>& firstList, LinkedList<T>& secondList) {
    Node<T>* newHead = nullptr;

    //Check if either list is empty and return appropriately

    if (firstList.head == nullptr) {
        firstList.head = secondList.head;
        secondList.head = nullptr;
        return;
    }
    if (secondList.head == nullptr) {
        return;
    }

    //setup a new head for the merged list.

    if (firstList->head.value > secondList->head.value) {
        newHead = secondList.head;
        secondList.head = secondList->head.next;
    }
    else {
        //If both initial nodes have equal values, firstList is the start.
        newHead = firstList.head;
        firstList.head = firstList->head.next;
    }

    //Setup an end pointer for the merged list to keep track while adding nodes.

    Node<T>* endPtr = newHead;

    //Iterate over both linked lists until one of them is empty.

    while ((secondList->head != nullptr) && (firstList->head != nullptr)) {
        Node<T>* swap = nullptr;
        if (firstList->head.value <= secondList->head.value) {
            swap = firstList->head;
            firstList.head = firstList->head.next;
        }
        else {
            swap = secondList.head;
            secondList.head = secondList->head.next;
        }
        endPtr->next = swap;
        endPtr = swap;
    }

    //Add any remaining nodes from the list that isn't empty.

    if (firstList->head != nullptr) {
        endPtr->next = firstList.head;
    }
    else if (secondList->head != nullptr) {
        endPtr->next = secondList.head;
    }

    firstList.head = newHead;
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