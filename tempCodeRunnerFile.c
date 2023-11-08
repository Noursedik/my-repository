#include <stdio.h>
#define size 10
int main(){
    int index1=0, index2=size-1;
    int array[10];
    for(int i=0;i<10;i++){
        if((i%2)!=0){
            array[index1]=i;
            index1++;
        }
        else{
            array[index2]=i;
            index2--;
        }
    }
     for (int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }
return 1;
}