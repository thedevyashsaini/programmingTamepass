#include<stdio.h>

// void fn(int a, int b );
void fn(int a, int b){
    int t = a;
    a = b;
    b = t;
    printf("x=%d and y =%d\n", a, b);
}

// void ffn(int *a, int *b );
void ffn(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
    printf("x=%d and y =%d\n", *a, *b);
}

int main(){
    int x =5;
    int y =8;
    printf("\n\nx=%d and y =%d \n after swaping \n",x,y);

    // int t=x;x=y;y=t;

    fn(x,y);
    ffn(&x,&y);
    fn(x,y);

    printf("x=%d,y=%d\n\n",x,y);

    return 0;
}