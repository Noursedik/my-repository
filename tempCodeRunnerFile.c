/*Question 1*/
/*Pre-Processor Directives*/
#include <stdio.h>
#include <stdbool.h>
#include<math.h>
#define SIZE 24
#define nRows 8
#define nCols 3
/*Functions Prototypes*/
void set_array(int arr [], int length);
void rem_align(int arr[],int length, int pos);
void insert_align(int arr[],int length, int pos, int value);
void reshape(int arr[],int length,int arr2d[nRows][nCols]);
void print_trans_matrix(int arr2d[nRows][nCols]);
bool found_duplicate(int arr[],int length);
void flip_array(int arr[], int length,int outputarray[]);

/*Main function to test the user defined functions*/
int main(){
/*declaring arrays and variables that will help to test the functions*/
int arr1[SIZE];
int duplicate_found;
int arr2d[nRows][nCols];
set_array(arr1,SIZE); //testing set_array function 
rem_align(arr1,SIZE,2); //testing rem_align function 
insert_align(arr1,SIZE,2,80); //testing insert_align function 
reshape(arr1,SIZE,arr2d); //testing reshape function 
print_trans_matrix(arr2d); //testing print_trans_matrix function 
duplicate_found=found_duplicate(arr1,SIZE); //testing found_duplicate function
printf("%d\n",duplicate_found); //printig if a duplicate in the array is found or not
int outputarray[SIZE];
flip_array(arr1,SIZE,outputarray);////testing flip_array function
return 0;
}


/*sets the value of each array element to its index in the array*/
void set_array(int arr [], int length){
    printf("Seting the array Values:\n");
    for(int i=0;i<length;i++){
            arr[i]=i;
            printf("%d ",arr[i]);
    }
    printf("\n");
    return;
}
/* removes the array element at index pos by moving its following array elements one index up in the array*/
void rem_align(int arr[],int length, int pos){
    printf("Removing the element at position %d \n",pos);
    int i;
    if(pos>length-1||pos<0){
            printf("The position entered is not within the size of the array\n");
            return;
        }
    for(i=pos;i<length;i++){
        if(i==length-1){
            arr[i]=arr[length-1];
        }
        else {
            arr[i] = arr[i + 1];
        }
    }
    for(i=0;i<length;i++){
        printf("%d\n",arr[i]);
    }
    return;
}
/* inserts the prameter value at the array 
index pos while moving down by one positon the original array elements from index pos onwards,*/
void insert_align(int arr[], int length, int pos, int value) {
    printf("Inserting value %d at position %d \n",value,pos);
    int i;
    if (pos < 0 || pos >= length) {
        printf("The position entered is not within the size of the array\n");
        return;
    }
    for ( i = length - 1; i > pos; --i) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    for(i=0;i<length;i++){
        printf("%d\n",arr[i]);
    }
    return;
}
/* copy the elements of the 1-D array arr into arr2d, row by row.*/
void reshape(int arr[],int length,int arr2d[nRows][nCols]){
    printf("Converting the 1D array to a 2D array\n");
    int i,j,index=0;
    if(length!=(nRows*nCols)){ //checks if the number of elememts in the 2D array will fit in the size of the 1D array
        printf("The length of the 1D array is not equal to the multiplication of the\nnumber of rows and columns of the 2D array ");
        return;
    }
    else{
        for(i=0;i<nRows;i++){
            for(j=0;j<nCols;j++){
                arr2d[i][j]=arr[index];
                index++;
            }
        }
    }
   for(i=0;i<nRows;i++){
       printf("row %d:",i);
        for(j=0;j<nCols;j++){
            printf("%d ",arr2d[i][j]);
        }
    printf("\n");
   }
    return;
}
/*print the values of arr2d column by column; each column in a new line.*/
void print_trans_matrix(int arr2d[nRows][nCols]){
    printf("Printing the 2D array column by column\n");
    int i,j;
    for(j=0;j<nCols;j++){
        printf("column %d:",j);
            for(i=0;i<nRows;i++){
                printf("%d ",arr2d[i][j]);
                
            }
        printf("\n");
    }
    return;
}
/*returns true if there is at least a duplicate values in arr; otherwise returns false*/
bool found_duplicate(int arr[],int length){
    printf("Checking if duplicates are found\nif yes return 1, if no return 0\n");
    int i,j;
    for(i=0;i<length;i++){
        for(j=i+1;j<length;j++){
            if(arr[i]==arr[j]){
                return true;
            }
        }
    }
    return false;
}
/*returns true if there is at least a duplicate values in arr; otherwise returns false*/
void flip_array(int arr[], int length,int outputarray[]){
    printf("Flipping the 1D array\n");
  int index=0;
  for(int i=(length-1);i>=0;i--){
      outputarray[index]=arr[i];
      index++;
  }
  for(int i=0;i<SIZE;i++){
    printf("%d\n",outputarray[i]);
}
  return;
}
     

