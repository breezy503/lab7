#include <stdio.h>

void printArray(int arr[],int arr2[], int length, int count)
{
    printf("%d", count);
    for (int i=0; i < length; i++)  
        printf("%d: %d\n", arr[i], arr2[i]);
}

void bubbleSort(int array[], int length)
{
    int temp;
    int arrayt[length];
    int arraySwap[] = {0,0,0,0,0,0,0,0,0};
    int count = 0;

    for (int k =0; k < 9; k++){
        arrayt[k] = array[k];
    }

    for (int i =0; i < length-1; i++){
        for (int j = 0; j< length -i -1; j++){
            if (arrayt[j] > arrayt[j+1]){
                temp = arrayt[j];
                arrayt[j] = arrayt[j+1];
                arrayt[j+1]= temp;
                arraySwap[j]++;
                arraySwap[j + 1]++;
                count++;
            }
        }
    }
    printArray(arrayt, arraySwap, length, count);
}

void selectionSort(int array[], int length)
{
    int arrayt[length];
    int arraySwap[] = {0,0,0,0,0,0,0,0,0};
    int i, j, temp, min;
    int count = 0;

    for (int k =0; k < 9; k++){
        arrayt[k] = array[k];
    }
    
    for (i =0; i < length; i++){
        min =i;
        for ( j=i+1; j< length; j++){
            if (arrayt[j] < arrayt[min])
                min = j;
        }
        if(min != i){
            temp = arrayt[i];
            arrayt[i] = arrayt[min];
            arrayt[min] = temp;
            arraySwap[min]++;
            arraySwap[i]++;
            count +=2;
        }
        
    }
    arraySwap[i] += count;
    count = 0;
    printArray(arrayt, arraySwap, length, count);
}


int main()
{
    int array1 [] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2 [] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int length = sizeof(array1)/ sizeof(array1[0]);
    int swapArr[length];

       
    printf("Array 1 Bubble Sort:\n");
    printf("Total Swaps:");
    bubbleSort(array1, length); 
    
    printf("\nArray 2 Bubble Sort:\n");
    printf("Total Swaps:");
    bubbleSort(array2, length);

    printf("\nArray 1 Selection Sort:\n");
    printf("Total Swaps:");
    selectionSort(array1, length);

    printf("\nArray 2 Selection Sort:\n");
    printf("Total Swaps:");
    selectionSort(array2, length);
}