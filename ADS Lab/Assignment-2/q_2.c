#include<stdio.h>
#include<stdlib.h>

// Comparator function for float values
// const void *a == generic datatype (kisi bhi DT ke liye valid hai)
int compareFloats(const void *a, const void *b) {
    // var a is passed as void * so we will cast it to float and then dereference using *
    float fa = *(const float *)a;  
    float fb = *(const float *)b;
    if (fa < fb) return -1;
    else if (fa > fb) return 1;
    else return 0;
}


int main(){
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    float tempMax = -9999999;
    float *arr = (float *)malloc(n*sizeof(float));
    printf("Enter %d nums\n",n);
    for(int i = 0; i < n;++i){
        float t;
        scanf("%f",&t);
        arr[i] = t;
        if (t > tempMax) tempMax = t;
    }
    // Sort the array using qsort
    qsort(arr, n, sizeof(float), compareFloats);

    printf("Maximum temperature is = %.2f\n", tempMax);
    printf("Maximum temperature is = %.2f\n", arr[n-1]);
    free(arr);
    return 0;
}