
#include <iostream>

template <typename T>
class Node {
public:
    T value;
    Node<T>* next;

    Node(T value) : value(value), next(nullptr) {}
};

template <typename T>
class LinkedList {

public:
    Node<T>* head;

    LinkedList() : head(nullptr) {}

    // Function to add a new element to the front of the list
    void pushFront(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
    }

    // Function to print the elements in the list
    void print() {
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Destructor to free memory
    ~LinkedList() {
        Node<T>* current = head;
        while (head != nullptr) {
            Node<T>* next = head->next;
            delete head;
            head = next;
        }
    }

};

template <typename T>
T* merge(T*, T*);

template <typename T>
void mergeList(T*&, T*&, int, int, T*&);

template<typename T>
void mergeList(Node<T>*&, Node<T>*&);

int main()

{
    // This section tests the array sorting function.
    int size1 = 4;
    int size2 = 6;
    int* arr1 = new int[size1] {5, 6, 7, 8};
    int* arr2 = new int[size2] { 2, 3, 4, 7, 10, 11 };
    int* arr3 = new int[size1 + size2];
    mergeList(arr1, arr2, size1, size2, arr3);
    int size3 = size1 + size2;
    for (int i = 0; i < size3; i++) {
        std::cout << arr3[i] << std::endl;
    }
    delete[] arr3;

    //This section will test the linked list sorting function.

    LinkedList<int> firstList;
    LinkedList<int> secondList;
    firstList.pushFront(5);
    firstList.pushFront(3);
    firstList.pushFront(1);
    secondList.pushFront(6);
    secondList.pushFront(4);
    secondList.pushFront(2);
    mergeList(firstList.head, secondList.head);

    firstList.print();

};



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


template <typename T>
void mergeList(Node<T>*& firstList, Node<T>*& secondList) {
    Node<T>* newHead = nullptr;

    //Check if either list is empty and return appropriately

    if (firstList == nullptr) {
        firstList = secondList;
        secondList = nullptr;
        return;
    }
    if (secondList == nullptr) {
        return;
    }

    //setup a new head for the merged list.

    if (firstList->value > secondList->value) {
        newHead = secondList;
        secondList = secondList->next;
    }
    else {
        //If both initial nodes have equal values, firstList is the start.
        newHead = firstList;
        firstList = firstList->next;
    }

    //Setup an end pointer for the merged list to keep track while adding nodes.

    Node<T>* endPtr = newHead;

    //Iterate over both linked lists until one of them is empty.

    while ((secondList != nullptr) && (firstList != nullptr)) {
        Node<T>* swap = nullptr;
        if (firstList->value <= secondList->value) {
            swap = firstList;
            firstList = firstList->next;
        }
        else {
            swap = secondList;
            secondList = secondList->next;
        }
        endPtr->next = swap;
        endPtr = swap;
    }

    //Add any remaining nodes from the list that isn't empty.

    if (firstList != nullptr) {
        endPtr->next = firstList;
    }
    else if (secondList != nullptr) {
        endPtr->next = secondList;
    }

    firstList = newHead;
    secondList = nullptr;
};