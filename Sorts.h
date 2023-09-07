//
//  main.cpp
//  p4
//
//  Created by Byan Alkas & Amal Mohamed on 6/14/22.
//

#ifndef Sorts_h
#define Sorts_h
#include <stdio.h>
#include <vector>
#include <iostream>


using namespace std;


template <typename Comparable>

class Sorts {

public:

    void quicksort(vector<Comparable> &a)
       {
       quicksort(a, 0, a.size() - 1);

    }
    /**
 * Return median of left, center, and right.
 * Order these and hide the pivot.
 */
static const Comparable &median3(vector<Comparable> &a, int left, int right)
{
    int center = (left + right) / 2;
    if (a[center] < a[left])
        swap(a[left], a[center]);
    if (a[right] < a[left])
        swap(a[left], a[right]);
    if (a[right] < a[center])
        swap(a[center], a[right]);
    // Place pivot at position right - 1
    swap(a[center], a[right - 1]);
    return a[right - 1];
}
    
    static int insertionSort (vector<Comparable>& a, int left, int right){
                //will be called by quicksortWithCutoff and/or insertionSort
        return quicksortWithCutoff(a, left, left - 1, right - 1);
        
    }
        
    static int insertionSort(vector<Comparable>& a){
        int comparisonCount = 0;
        int j;
        for (int p = 1; p < a.size(); p++){
            Comparable tmp = a[p];
            for(j = p; j > 0 && tmp < a[j - 1]; j--){
                a[j] = a[j - 1];
                comparisonCount++;
            }
            if (j > 0){
                comparisonCount++;
            }
            a[j] = tmp;
    }
        return comparisonCount;
    }

    static int quicksortWithoutCutoff(vector<Comparable>& a){
       return quicksortWithoutCutoff(a, 0, a.size() - 1);
    }

    
static int quicksortWithoutCutoff (vector <Comparable> & a, int left, int right){
    int comparisonCount = 0;
    // check if the vector has the size 0 or 1..
    if (left >= right){
    return comparisonCount;
    }
    Comparable pivot = median3(a, left, right);
        comparisonCount += 3;
    if (left + 3 > right){
    return comparisonCount;
    }
    // begin partitioning..
    int i = left, j = right - 1;
    for (;;){
    while (a[++i] < pivot){
        comparisonCount++;
    }
        comparisonCount++;

    while (pivot < a[--j]) {
        comparisonCount++;
    }
        comparisonCount++;
    if (i < j)
        swap(a[i], a [j]);
    else
    break;
    }
swap(a[i], a[right - 1]); // restore pivot..
comparisonCount += quicksortWithoutCutoff(a, left, i - 1); // sort small elements ..
    comparisonCount += quicksortWithoutCutoff(a, i + 1, right);
    return comparisonCount;
    }

    static int quicksortWithCutoff(vector <Comparable>& a, int cutoff) {
           return quicksortWithCutoff(a, 0, a.size() - 1, cutoff);
       }
    
    
static int quicksortWithCutoff (vector <Comparable> & a, int left, int right, int cutoff){
        int comparisonCount = 0;
    Comparable pivot = median3(a, left, right);
            comparisonCount += 3;
    if (left + cutoff <= right){
        comparisonCount ++;
            // begin partitioning..
            int i = left, j = right - 1;
            for (;;){
            while (a[++i] < pivot){
                comparisonCount++;
            }
                comparisonCount++;
            while (pivot < a[--j]) {
               comparisonCount++;
             }
            comparisonCount++;
         if (i < j)
                swap(a[i], a [j]);
            else
            break;
            }
            swap(a[i], a[right - 1]); // restore pivot..
            comparisonCount += quicksortWithCutoff(a, left, i - 1, cutoff); // sort small elements ..
            comparisonCount += quicksortWithCutoff(a, i + 1, right, cutoff);
        }
    
    return comparisonCount;
    }

    // A function to generate a random
    // permutation of vector a

    //Fisher–Yates shuffle Algorithm:
    //The idea is to start from the last element, swap it with a randomly selected element
    //from the whole array(including last).Now consider the array from 0 to n - 2 (size reduced by 1),
    //and repeat the process till we hit the first element.

    void nextRandomPermutation (vector<int> & a)
    {
        // Start from the last element and swap
        // one by one. We don't need to run for
        // the first element that's why i > 0
        for (int i = a.size()  - 1; i > 0; i--)
        {
            // Pick a random index from 0 to i
            int j = rand() % (i + 1);

            // Swap a[i] with the element
            // at random index
            swap(a[i], a[j]);
        }
    }

    
};

#endif /* Sorts_h */
