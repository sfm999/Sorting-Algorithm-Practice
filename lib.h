#pragma once

#include <iostream>
#include <array>
#include <string>
#include <chrono>
#include <random>

#define SIZE 3000


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
					SORTING FUNCTIONS
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


bool bubbleSort(std::array<int, SIZE>&, bool);

void insertionSort(std::array<int, SIZE>&, int const, int const);

void mergeSort(std::array<int, SIZE>&, int const, int const);
void mergeSortWithInsertion(std::array<int, SIZE>&, int const, int const);
void merge(std::array<int, SIZE>&, int const, int const, int const);

void quickSort(std::array<int, SIZE>&, int const, int const);
int partition(std::array<int, SIZE>&, int const, int const);



/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
					HELPER FUNCTIONS
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

// Swap two values in an array. See implementation in `imp.cpp` for more info
void swap(std::array<int, SIZE>&, int, int);

// Simply takes an array & a prefix string to print before printing the array.
void printArr(std::string prefixMsg, std::array<int, SIZE>);

