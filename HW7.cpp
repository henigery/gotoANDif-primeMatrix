/*
  Author: Ryan Henige
  Date: April 22, 2019
  Class: CPS 450
  Description: 
                This program creates a 20 x 20 matrix that is randomly filled 
  with a range of 500. It then searches the matrix for prime numbers, adds
  them to a special array. Searches array for duplicates, tells what they are,
  then deletes them from the array. Finally to print the new uniqueArray

  Difficulties:
                For this project we were only allowed to use goto and if, without
    else. At first I struggled figuring out how to create the loops I needed with 
    the goto but I ended up figuring it out. It deffinetly was easier after I had
    the right mindset on it. It deffinetly would have been easier to use for loops.
    I do not look forward to using goto's again  :)
*/


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
using namespace std;

// Variable for row/col of matrix
const int x = 20;
const int y = 20;
int matrix[x][y];

// The two array
int prime[200];
int uniquePrimes[200];

// Total count for array
int totalPrime;

// Create a rng matrix
void createMatrix(int matrix[x][y], int r, int c)
{
    
    int x = 0;
    int y = 0;
    srand(time(NULL));
 create:

    if (x < r)
    {
    creater:
        if (y < c)
        {
            matrix[x][y] = rand() % 501;
            y++;
            goto creater;
        }
        x++;
        y = 0;
        goto create;
    }
}

//Determines if prime
bool checkPrime(int p)
{
    int d = 2;

 prime:
    if (p < 2)
    {
        return false;
    }

    if (d < p)
    {
        if (0 == p % d)
        {
            return false;
        }
        d++;
        goto prime;
    }
    return true;
}

// Add prime num to array
int addPrime(int matrix[x][y], int arr[], int r, int c)
{

    int x = 0;
    int y = 0;
    int i = 1;

 prime:

    if (x < r)
    {
    primer:
        if (y < c)
        {
            if (checkPrime(matrix[x][y]) == true)
            {
                arr[i] = (matrix[x][y]);
                i++;
                totalPrime++;
            }
            y++;

            goto primer;
        }
        x++;
        y = 0;

        goto prime;
    }
    cout << "There are " << totalPrime << " prime numbers";
    //TEST
    //cout << arr[5];
    return 0;
}

//swap function to call on for bubblesort
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Sort the array of primes using bubble
void bubbleSort(int arr[], int size)
{
    cout << "The array Sorted: ";
    int i = 0, j = 0;
    bool swapped;

 sort:
    if (i < size)
    {
        swapped =false;
     sortr:
        if (j < size - i)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
         j++;
         goto sortr;  
        }
     i++;
     j = 0;
     goto sort;
    }
}

//Remove duplicates and adds them to 1-D array called unique primes
void removeDuplicates(int arr[], int size, int arr2[])
{
    int dups[100];
    int count = 0;
    int i = 0;
    cout << "[";
 dup:
    if (i < size)
    {
        // Counts the number of duplicates, updates unique prime total
        if (arr[i] == arr[i + 1])
        {
            count++;
            dups[i] = (arr[i + 1]);
            cout << dups[i] << " " ;
        }
        // Adds non-duplicates to new array
        if (arr[i] != arr[i + 1])
        {
            arr2[i] = (arr[i + 1]);  
        }
        i++;
        goto dup;
    }
    cout << "]";
    cout << "\nNumber of Duplicates: " << count;


}

// Display the matrix/array's
void printMatrix(int matrix[x][y], int r, int c)
{
    // Print using goto
    int x = 0;
    int y = 0;
 print:
    if (x < r)
    {
     printr:
        if (y < c)
        {
            cout << matrix[x][y] << ' ';
            y++;
            goto printr;
        }
        x++;
        y = 0;
        cout << endl;
        goto print;
    }
}

// Universal print array function that will print 10 ints a line 
// and deletes the empty space
void printArray(int arr[], int size)
{
    // Print using goto
    int i = 1;
    cout << "\n[";
 print:
    if (i <= size)
    {
        if(arr[i] != 0){
         cout << arr[i] << ' ';
            if(i %10 == 0){
                 cout<< "\n";
        }
        }
        i++;
        goto print;
        
    }
    cout << "]";
}

// The main method calls all the functions and gives parameters
int main()
{
    cout << "Original Matrix: \n";

    cout << "-----------------\n";
    createMatrix(matrix, x, y);
    printMatrix(matrix, x, y);

    cout << "-----------------\n";
    addPrime(matrix, prime, x, y);
    printArray(prime, totalPrime);

    cout << "\n-----------------\n";
    bubbleSort(prime, totalPrime);
    printArray(prime, totalPrime);

    cout << "\n-----------------\n";
    removeDuplicates(prime, totalPrime, uniquePrimes);

    cout << "\n-----------------\n";
    cout << "Array's --->\n";
    cout << "Primes: ";
    printArray(prime, totalPrime);

    cout << "\n\nUnique Primes: ";
    bubbleSort(uniquePrimes, totalPrime);
    printArray(uniquePrimes, totalPrime);

    return 0;
}