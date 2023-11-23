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
#include <stdio.h>
#include <stdlib.h>

//Function to read the image pixel values from a text PGM file
 void readPGM(char* filename, int** image, int* width, int* height,int*max_value) {
  
   char comments[256];
   
   FILE* file = fopen("Rain_tree.pgm", "r");//opening the file and checking if it opened
     if (&file == NULL) {
      printf("Error opening file!");
         return;
     }

     //Read the PGM file header
     char format[3];
     fscanf(file, "%s", format);
    if (format[0] != 'P' || format[1] != '2') {// reading the file header and making sure it is a pgm
        printf("Invalid PGM file format!");//reading the comments fromthe file
        return;
    }

     //Read the image comments
    fscanf(file, "%s", comments);
    while (comments[0]=='#'){
        fgets(comments,255,file);

    }
    fscanf(file, "%d %d", width, height);//reading the 2 values that represent the width and the height
    fscanf(file, "%d", max_value);//reading the value that represent the pixel maximum number
    
    *image = (int*)malloc((*width) * (*height) * sizeof(int));//allocating a memory space to read the pixel values
    for (int i = 0; i < (*width) * (*height); i++) {
        fscanf(file, "%d", &(*image)[i]);//reading all the pixel values from the file
    }
   

    fclose(file);
}

// Function to write the image pixel values to a text PGM file
void writePGM(char* filename, int* image, int width, int height,int max_value) {
    FILE* file = fopen(filename, "w");//opening the file and checking if it opened
    if (file == NULL) {
        printf("Error opening file!");
        return;
    }

    fprintf(file,"P2\n");
    fprintf(file,"%d %d\n",width,height);
    fprintf(file,"%d\n",max_value);

    // Write the pixel values
    for (int i = 0; i < width * height; i++) {//writing the pixel values into the new file
        fprintf(file, "%d ", *(image+i));
    }

    fclose(file);
}

// Function to perform histogram equalisation on the image
void histogramEqualisation(int* image, int width, int height,int max_value) {
    // Calculate the histogram
    int histogram[256] = {0};
    for (int i = 0; i < width * height; i++) {
        histogram[*(image+i)]++;
    }

    // Calculate the cumulative distribution function (CDF)
    int cdf[256] = {0};
    cdf[0] = histogram[0];
    for (int i = 1; i < (max_value+1); i++) {
        cdf[i] = cdf[i - 1] + histogram[i];
    }

    // Perform histogram equalisation
    int totalPixels = width * height;
    for (int i = 0; i < width * height; i++) {
        image[i] = (cdf[(*(image+i))] * max_value) / totalPixels;
    }
}

int main() {
    char* inputFile = "Rain_Tree.pgm";
    char* outputFileText = "Rain_Tree_equalized_text.txt";

    int width, height,max_value;
    int* image;

    // Read the input image
    readPGM(inputFile,&image,&width,&height,&max_value);

    // Perform histogram equalisation
    histogramEqualisation(image, width, height,max_value);

    // Write the equalized image to text PGM file
    writePGM(outputFileText, image, width, height,max_value);

    // Free the allocated memory
    free(image);
     return 0;
}

/*Question 3*/
#include<iostream>
#include<iomanip>
#include <cstdlib> 
using namespace std;

template< typename T >
T update_scale(T &m1, T &m2, T m3=10);

void print_real( float number, int fieldspace, int precision);

int main(void){
float  a, b;
cout<<" Please input two real numbers";
cin>>a>>b;	

print_real(a,7,3);
print_real(b,7,3);
// call the function update_scale with ONLY the actual parameters a  and b
update_scale(a,b);
print_real(a,7,3);
print_real(b,7,3);
	
}

/* complete the body of the function */
void print_real( float number, int fieldspace, int precision){
    cout<<fixed<<setw(fieldspace)<<setprecision(precision)<<number<<endl;

}

// add the function defintion (header+body) of the template function update_scale
template< typename T >
T update_scale(T &m1, T &m2, T m3){
    T originalm1=m1;
    T originalm2=m2;
    m1=(originalm1+originalm2)*m3;
    m2=(originalm1-originalm2)*m3;
}