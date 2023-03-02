/*
 CS201 HW02
 Barış Tan Ünal
 22003617
 07.12.2021
*/

#include <iostream>
#include <ctime>

using namespace std;


int linearSearch( const int arr1[], const int arr2[], int arr1Size, int arr2Size ) {

    int iter1;

    for( int iter2 = 0; iter2 < arr2Size; iter2++ ) {
        for( iter1 = 0; iter1 < arr1Size; iter1++ ) {
            // If the number is present, stop traversing.
            if( arr1[ iter1 ] == arr2[ iter2 ] ) {
                break;
            }
        }
        if( iter1 == arr1Size ) {
            return 0;
        }
    }
    return 1;
}


int binary( int arr[], int low, int high, int x ) {

    if ( high >= low ) {
        int mid = low + (high - low) / 2;

        // Check if the mid value is unique.
        if ((mid == 0 || x > arr[mid - 1]) && (arr[mid] == x))
            return mid;
        else if (x > arr[mid])
            return binary( arr, (mid + 1), high, x );
        else
            return binary( arr, low, (mid - 1), x );
    }
    return -1;
}


int binarySearch( int arr1[], int arr2[], int m, int n) {
    int i = 0;

    for (i = 0; i < n; i++) {
        if ( binary( arr1, 0, m - 1, arr2[i]) == -1 )
            return 0;
    }

    // If the algorithm reaches here, then all elements are present.
    return 1;
}


int frequencyTable( const int arr1[], const int arr2[], int size1, int size2 ) {

    int biggestValue = arr1[ 0 ];

    // Choose the maximum value of the array.
    for ( int i = 0; i < size1; i++ ) {
        if (arr1[ i ] > biggestValue) {
            biggestValue = arr1[ i ];
        }
    }

    // Create a new array with the same size of array1 with all 0's.
    int* arrNew = new int[ biggestValue ];

    for ( int i = 0; i < biggestValue - 1; i++ ) {
        arrNew[i] = 0;
    }

    for ( int i = 0; i < size1; i++ ) {
        arrNew[ arr1[i] - 1 ]++;
    }

    for ( int i = 0; i < size2; i++ ) {
        arrNew[ arr2[ i ] - 1 ]--;
        if ( arrNew[arr2[i] - 1 ] < 0 ) {
            return 0;
        }
    }

    return 1;
}


int main() {

    // Initializing array sizes.
    int n = 1000000;
    int m = 1000;

    int sampleSize = 100;

    // Creating arrays 1 & 2.
    int* arr1 = new int[ n ]; // n
    int* arr2 = new int[ m ]; // m

    int arrSize1 = n;
    int arrSize2 = m;

    // Array 1 consists sorted numbers from 1 to n.
    for ( int i = 0; i < n; i++ ) {
        arr1[ i ] = i + 1;
    }

    // Array 2 consists random numbers.
    srand( time(NULL) );
    for( int i = 0; i < arrSize2; i++ ) {
        arr2[ i ] = rand() % n;
        for( int j = 0; j < i; j++ ) {
            if( arr2[ i ] == arr2[ j ] ) {
                i--;
                break;
            }
        }
    }

        // LINEAR SEARCH - ALGORITHM 1:

    double duration1;
    double averageDuration1 = 0;

    for( int i = 0; i < sampleSize; i++ ){

        cout << endl;
        clock_t startTime1 = clock();

        if( linearSearch(arr1, arr2, arrSize1, arrSize2 )) {
            cout << "Subset " << endl;
        } else {
            cout << "Not a subset" << endl;
        }

        duration1 = 1000 * double( clock() - startTime1 ) / CLOCKS_PER_SEC;
        cout << "Algorithm 1 execution time: " << duration1 << " ms." << endl;

        averageDuration1 = averageDuration1 + duration1;

    }

    averageDuration1 = averageDuration1 / sampleSize;


        // BINARY SEARCH - ALGORITHM 2:

    sampleSize = sampleSize * 50; // because alg2&3 are much faster.

    double duration2;
    double averageDuration2 = 0;

    for( int i = 0; i < sampleSize; i++ ){

        cout << endl;
        clock_t startTime2 = clock();

        if( binarySearch(arr1, arr2, arrSize1, arrSize2 )) {
            cout << "Subset" << endl;
        } else {
            cout << "Not a subset" << endl;
        }

        duration2 = 1000 * double( clock() - startTime2 ) / CLOCKS_PER_SEC;
        cout << "Algorithm 2 execution time: " << duration2 << " ms." << endl;

        averageDuration2 = averageDuration2 + duration2;

    }

    averageDuration2 = averageDuration2 / sampleSize;



        // FREQUENCY TABLE - ALGORITHM 3:

    double duration3;
    double averageDuration3 = 0;

    for( int i = 0; i < sampleSize; i++ ){

        cout << endl;
        clock_t startTime3 = clock();

        if( frequencyTable( arr1, arr2, arrSize1, arrSize2 )) {
            cout << "Subset" << endl;
        } else {
            cout << "Not a subset" << endl;
        }

        duration3 = 1000 * double( clock() - startTime3 ) / CLOCKS_PER_SEC;
        cout << "Algorithm 3 execution time: " << duration3 << " ms." << endl;

        averageDuration3 = averageDuration3 + duration3;
    }

    averageDuration3 = averageDuration3 / sampleSize;

    cout << endl;
    cout << "AVERAGE 1: " << averageDuration1 << endl;
    cout << "AVERAGE 2: " << averageDuration2 << endl;
    cout << "AVERAGE 3: " << averageDuration3 << endl;
    cout << "...after " << sampleSize << " executions" << endl;

    delete arr1;
    delete arr2;

    return 0;
}