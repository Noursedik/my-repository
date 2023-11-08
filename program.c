/*Question 1*/
/*Itertive solution*/
/*Pre-processor directives*/
#include <stdio.h>
#define size 10
/*function prototypes*/
void shuffle_elements(int array[],int length);
void recursiveShuffle(int arr[], int left, int right);
void swap(int arr[], int i, int j);
int main(){
    /*Declaring 2 empty arrays*/
    int array[size];
    int array2[size];
    /*Filling the second array*/
    for(int i=0;i<size;i++){
        array2[i]=i;
    }
    /*Calling the functions*/
    shuffle_elements(array,size);
   recursiveShuffle(array2,0,size-1);
   /*printing the recursively shuffled array*/
   printf("\n");
   printf("Shuffled Array: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", array2[i]);
    }
return 1;
}
void shuffle_elements(int array[],int length){
    int index1=0, index2=size-1;//declaring those 2 variables to know the position from the left and right on the array
    for(int i=0;i<length;i++){
        if((i%2)!=0){// checking if the number is odd
            array[index1]=i;//if yes add it to the array at this index which will be in the left side in the array 
            index1++;//incriment index by 1 to go to the next position in the array
        }
        else{//if the number i even
            array[index2]=i;//add this number to the array in position index 2 whixh is to the right side in the array
            index2--;//decriment the index 2 to go to the previous position
        }
    }
     for (int i = 0; i < length; i++) {//printig the shuffled array
        printf("%d ", array[i]);
    }
}
/*Recursive solution*/
//a swaping function to swap the elements positions int the array
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void recursiveShuffle(int arr[], int left, int right) {
    if (left >= right) {//basic case
        return;
    }

    int mid = left + (right - left) / 2;//getting the middle index of the array
    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] % 2 == 1) {//checking for odd numbers from first element to the middle element 
            i++;
        } else if (arr[j] % 2 == 0) {//checking for even numbers from middle element +1 to last element
            j++;
        } else {
            //if an even number was found in the first half or an odd number was found in the second half they will be swaped
            swap(arr, i, j);
            i++;
            j++;
        }
    }

    recursiveShuffle(arr, left, mid);//recalling the function to check from left to middle
    recursiveShuffle(arr, mid + 1, right);//recalling the function to check from middle +1 to right 
    return;
}
/*Question 2*/
