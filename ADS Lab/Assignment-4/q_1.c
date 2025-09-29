#include<stdio.h>
typedef struct
{
    float img;
    float real;
}Complex;

void swap(Complex *a, Complex *b){
    Complex temp = *a;
    *a = *b;
    *b = temp;
}

void print(Complex c){
    printf("%.2f + %.2fi\n", c.real, c.img);
}

int main(){
    Complex num1, num2;

    // Input complex numbers
    printf("Enter the real and imaginary parts of the first complex number:\n");
    scanf("%f %f", &num1.real, &num1.img);

    printf("Enter the real and imaginary parts of the second complex number:\n");
    scanf("%f %f", &num2.real, &num2.img);
    
    print(num1);
    print(num2);

    swap(&num1,&num2);

    printf("\nAfter swapping:\n");
    print(num1);
    print(num2);

    return 0;
}