#include<stdio.h>

int main(){

    int arr [] = {3,2,2,1,4,5,5};
    int first = arr[0], second;

    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]);i++){
        if (arr[i] > first){
            second = first;
            first = arr[i];
        }
        else if ((arr[i] > second) && (arr[i]!=first)) second = arr[i];
    }

    printf("Second largest Element is: %d", second);

    return 0;
}