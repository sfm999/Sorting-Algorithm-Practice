// Sorting Algorithm Practice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "lib.h"


#define STRINGIFY(x) #x

#define FUNCTION_NAME(function) \
    ([]() -> const char* { \
        return STRINGIFY(function); \
    })()

double recordFunctionExecutionTime(std::array<int, SIZE>& myArr, const char* name);

void initData(std::array<int, SIZE> &myArr1, std::array<int, SIZE> &myArr2, std::array<int, SIZE> &myArr3, std::array<int, SIZE> &myArr4, std::array<int, SIZE> &myArr5);
void getData(std::array<int, SIZE>& myArr);

int main()
{
    std::array<int, SIZE> myArr1;
    std::array<int, SIZE> myArr2;
    std::array<int, SIZE> myArr3;
    std::array<int, SIZE> myArr4;
    std::array<int, SIZE> myArr5;

    initData(myArr1, myArr2, myArr3, myArr4, myArr5);

    double totalTime = 0.00;
    for (int i = 0; i < 100; i++)
    {
        totalTime += recordFunctionExecutionTime(myArr1, "bubbleSort");
    }

    printf("Total time taken to execute bubbleSort %d times on %d elements: % .4f\n", 100, SIZE, totalTime);
    printf("Average time taken: %.4f\n", (double)totalTime / 100.0);
    std::cout << std::endl;
 

    totalTime = 0.00;
    for (int i = 0; i < 100; i++)
    {
        totalTime += recordFunctionExecutionTime(myArr1, "insertionSort");
    }

    printf("Total time taken to execute insertionSort %d times on %d elements: % .4f\n", 100, SIZE, totalTime);
    printf("Average time taken: %.4f\n", (double)totalTime / 100.0);
    std::cout << std::endl;


    totalTime = 0.00;
    for (int i = 0; i < 100; i++)
    {
        totalTime += recordFunctionExecutionTime(myArr1, "mergeSort");
    }

    printf("Total time taken to execute mergeSort %d times on %d elements: % .4f\n", 100, SIZE, totalTime);
    printf("Average time taken: %.4f\n", (double)totalTime / 100.0);
    std::cout << std::endl;

    totalTime = 0.00;
    for (int i = 0; i < 100; i++)
    {
        totalTime += recordFunctionExecutionTime(myArr1, "mergeSortWithInsertion");
    }

    printf("Total time taken to execute mergeSort2 %d times on %d elements: % .4f\n", 100, SIZE, totalTime);
    printf("Average time taken: %.4f\n", (double)totalTime / 100.0);
    std::cout << std::endl;
    

}

void getData(std::array<int, SIZE>& myArr)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    int const min = 1, max = 10000;

    std::uniform_int_distribution<int> dist(min, max);

    for (int i = 0; i < SIZE; i++)
        myArr[i] = dist(gen);
}


void initData(std::array<int, SIZE> &myArr1, std::array<int, SIZE> &myArr2, std::array<int, SIZE> &myArr3, std::array<int, SIZE> &myArr4, std::array<int, SIZE> &myArr5)
{
    getData(myArr1);
    getData(myArr2);
    getData(myArr3);
    getData(myArr4);
    getData(myArr5);
}



double recordFunctionExecutionTime(std::array<int, SIZE>& myArr, const char* name)
{
    // Record start time
    auto start = std::chrono::high_resolution_clock::now();

    // Call correct function.
    if (strcmp(name, "bubbleSort") == 0)
        bubbleSort(myArr, false);

    else if (strcmp(name, "insertionSort") == 0)
        insertionSort(myArr, 0, myArr.size() - 1);

    else if (strcmp(name, "mergeSort") == 0)
        mergeSort(myArr, 0, myArr.size() - 1);

    else if (strcmp(name, "mergeSortWithInsertion") == 0)
        mergeSortWithInsertion(myArr, 0, myArr.size() - 1);
    
    // Record end time
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    // Multiplied by 100 to have some meaningful number output
    return elapsed_seconds.count() * 100;
}

