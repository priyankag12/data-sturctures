#include <stdio.h>

void quicksort(int list[], int low, int high){
    int pivot, i,j,temp;
    if(low<high){
        pivot = high;
        i = low;
        j = high;
        while(i<j){
            while(list[i] <= list[pivot] && i <= high ){
                i++;
            }
            while(list[j] > list[pivot] && j >= low){
                j--;
            }
            if (i<j){
                temp = list[i];
                list[i]=list[j];
                list[j]=temp;
            }
        }
        temp = list[j];
        list[j]=list[pivot];
        list[pivot]=temp;
        quicksort(list,low,j-1);
        quicksort(list,j+1,high);
    }
}
int main(){
    int list[100];
    int size,i;

    printf("Enter the size of array: \n");
    scanf("%d",&size);

    printf("Enter the elements: \n");
    for(i=0;i<size;i++){
        scanf("%d",&list[i]);
    }

    quicksort(list,0,size-1);

    printf("After quick sort: \n");
    for(i=0;i<size;i++){
        printf("%d",list[i]);
    }
    printf("\n");
    
    return 0;
}
