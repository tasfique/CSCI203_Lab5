//Name-Tasfique Enam
//Student ID- 5886429
//LabTask5

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

string fileName;
int num;
ifstream ifs;

void mergeSort(int arrayStorage[], int l, int r);
void merge(int arrayStorage[], int l, int m, int r);
void printArray(int A[], int size);
void printArray2(int A[]);
void stepDisplay();

int main() {
    bool check = true;
    int arrayStorage [7];
    int i;

    do {
        cout << "Enter the name of the File with .txt Extention " << endl;
        cin >> fileName;

         if(fileName != "document.txt") {
            cout << "File name is Invalid! " << endl;
         } else {
            ifs.open("document.txt");

            if (ifs.is_open()) {
                cout<<"The File have been successfully opened." << endl;
                //ifs>>num1;
            } else {
                cout << "File failed to Open " << endl;
                check = false;
            }
         }
    } while (fileName != "document.txt" || check == false);

        for(i=0; i<10; i++) {
            ifs >> num;
            arrayStorage[i] = num;

            if(arrayStorage[i] < 0 ) { //validation for number not being positive.
                cout << "In the Array the number " << arrayStorage[i] << " is not Positive." << endl;
                exit(0); ///check
            }
        }

    /*do {


    } while (arrayStorage[i] < 0);*/

    int arr_size = sizeof(arrayStorage)/sizeof(arrayStorage[0]);

    printf("Given array is \n");
    printArray(arrayStorage, arr_size);
    cout << " " << endl;

    mergeSort(arrayStorage, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(arrayStorage, arr_size);
    cout << " " << endl;

    return 0;
}

void merge(int arrayStorage[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2]; //temporary arrays

    for (i = 0; i < n1; i++) {
        L[i] = arrayStorage[l + i];
    }

    for (j = 0; j < n2; j++) {
        R[j] = arrayStorage[m + 1+ j];
    }


    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arrayStorage[k] = L[i];
            i++;
        }

        else
        {
            arrayStorage[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arrayStorage[k] = L[i];
        i++;
        k++;

    }

    while (j < n2)
    {
        arrayStorage[k] = R[j];
        j++;
        k++;
    }

    ///the display of the steps that is happening.

    printArray2(arrayStorage);


}

void mergeSort(int arrayStorage[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h

        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arrayStorage, l, m);

        mergeSort(arrayStorage, m+1, r);


        merge(arrayStorage, l, m, r);


    }
}

void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void stepDisplay() {
    for (int i=0; i<7; i++) {
        cout << " Step " << i;
    }
}

void printArray2(int A[])
{
    int i;
    int j;

    for (i=0; i < 7; i++) {
        cout << "  " << A[i] << " ";
    }

    printf("\n");
}


