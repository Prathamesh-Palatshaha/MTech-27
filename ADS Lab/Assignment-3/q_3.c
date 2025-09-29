#include<stdio.h>
void reverse(int *arr, int i, int j){
    while (i<=j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
    
}
int main(){
    int arr [] = {1,2,3,4,5};
    int k = 2;
    int n = sizeof(arr)/sizeof(arr[0]);
    int diff = n-k;
    reverse(arr,0, diff-1);
    reverse(arr,diff,n-1);
    reverse(arr,0,n-1);
    for(int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}