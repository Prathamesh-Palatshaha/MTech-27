#include<stdio.h>

int Sum(int arr[], int len ){
    if (len == 0) return 0;
    return arr[len-1] + Sum(arr,len-1);
}
int main(){
    
    int sales [] = {1,2,3,4,5};
    int sum = 0;
    int len = sizeof(sales)/sizeof(sales[0]);
    for(int i = 0; i <len;i++){
        sum+=sales[i];
    }

    printf("Sum of sales = %d\n",sum);

    int sum_ = Sum(sales,len);
    printf("Sum of array elements = %d\n", sum_);
    return 0;
}