#include "lib.h"


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                    SORTING Function(s) Implementation(s)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

bool bubbleSort(std::array<int, SIZE>& myArr, bool swap_flag = false)
{
    for (int i = 1; i < myArr.size(); i++) {
        if (myArr[i - 1] > myArr[i]) {
            swap(myArr, i - 1, i);
            swap_flag = true;
        }
    }

    // Final pass check. If this is false, we have a sorted array
    if (swap_flag)
        bubbleSort(myArr, false);

    return true;
}

void insertionSort(std::array<int, SIZE>& myArr, int const left, int const right)
{
    for (int i = left; i <= right; i++)
    {
        int min = INT_MAX;
        int index;
        for (int j = i + 1; j <= right; j++)
        {
            if (myArr[j] <= min)
            {
                min = myArr[j];
                index = j;
            }
        }
        if (min < myArr[i]) {
            swap(myArr, i, index);
        }
    }
    return;
}



void mergeSort(std::array<int, SIZE> &myArr, int const left, int const right)
{
    // Sorted?
    if (left >= right)
        return;

   
    auto mid = left + (right - left) / 2;
    mergeSort(myArr, left, mid);
    mergeSort(myArr, mid + 1, right);
    merge(myArr, left, mid, right);
    
}

void mergeSortWithInsertion(std::array<int, SIZE>& myArr, int const left, int const right)
{

    if (right - left <= 43)
    {
        insertionSort(myArr, left, right);
    }
    else {
        auto mid = left + (right - left) / 2;
        mergeSortWithInsertion(myArr, left, mid);
        mergeSortWithInsertion(myArr, mid + 1, right);
        merge(myArr, left, mid, right);
    }
}

void merge(std::array<int, SIZE> &myArr, int const left, int const mid, int const right)
{
    // Declare left and right sub-arr sizes
    auto const subArr1 = mid - left + 1;
    auto const subArr2 = right - mid;

    // Declare and initialise temp arrays to hold left and right sub arrays
    auto * leftArr = new int[subArr1],
        * rightArr = new int[subArr2];

    // Populate the leftArray
    for (int i = 0; i < subArr1; i++)
        leftArr[i] = myArr[left + i];

    // Populate the rightArray
    for (int j = 0; j < subArr2; j++)
        rightArr[j] = myArr[mid + 1 + j];

    // Declare index counters for subArrs and mergedArr
    auto indexOfSubArr1  = 0,
         indexOfSubArr2  = 0;
    int  indexOfMergeArr = left;

    // Test each respective value against the opposing array to determine if <= to
    // Add lesser to merged arr then increment the sub arr ctr and the merged arr ctr
    while (indexOfSubArr1 < subArr1 && indexOfSubArr2 < subArr2)
    {
        if (leftArr[indexOfSubArr1] <= rightArr[indexOfSubArr2])
        {
            myArr[indexOfMergeArr] = leftArr[indexOfSubArr1];
            indexOfSubArr1++;
        }
        else {
            myArr[indexOfMergeArr] = rightArr[indexOfSubArr2];
            indexOfSubArr2++;
        }
        indexOfMergeArr++;
    }

    // Copy remaining elements of left into array, if any
    while (indexOfSubArr1 < subArr1)
    {
        myArr[indexOfMergeArr] = leftArr[indexOfSubArr1];
        indexOfSubArr1++;
        indexOfMergeArr++;
    }

    // Copy remaining elements of right into array, if any
    while (indexOfSubArr2 < subArr2)
    {
        myArr[indexOfMergeArr] = rightArr[indexOfSubArr2];
        indexOfSubArr2++;
        indexOfMergeArr++;
    }

    // Clean up by freeing the memory we assigned for left and right arr
    delete[] leftArr;
    delete[] rightArr;
}

void quickSort(std::array<int, SIZE>& myArr, int const low, int const high)
{
    if (low < high)
    {
        int pivot = partition(myArr, low, high);
        quickSort(myArr, low, pivot - 1); // Before pivot
        quickSort(myArr, pivot + 1, high); // After pivot
    }

}

int partition(std::array<int, SIZE>& myArr, int const low, int const high)
{
    // Element to be placed at right position
    int pivot = myArr[high];

    // Index of smaller element and indicates
    // the right position of pivot found so far
    int i = low - 1;

    for (int j = low; j <= high; j++)
    {
        if (myArr[j] < pivot)
        {
            i++;
            swap(myArr, i, j);
        }
    }
    swap(myArr, i + 1, high);

    return i + 1;
}


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                    HELPER Function Implementations
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


// Takes an array and two indexes, then swaps the values at the indexes
// Returns a bool which is useful in sorting algorithms such as 'Bubble Sort'
void swap(std::array<int, SIZE>& myArr, int lhs, int rhs)
{
    int temp = myArr[lhs];
    myArr[lhs] = myArr[rhs];
    myArr[rhs] = temp;
}

void printArr(std::string prefixMsg, std::array<int, SIZE> myArr)
{
    std::cout << prefixMsg << std::endl;
    for (int i = 0; i < myArr.size(); i++)
    {
        std::cout << " " << myArr[i];
    }
    std::cout << std::endl;
}