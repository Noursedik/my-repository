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