#include<iostream>
#include<stdio.h>

using namespace std;


void hinoi(int n, int a, int b, int c){
    if(n == 1){
        printf("%d %d\n", a ,b );
    }
    else{
        hinoi(n-1, a, c, b);
        printf("%d %d\n", a, c);
        hinoi(n-1, c, a, b);
    }
}




int main(){
    int n=3,a=1,b=2,c=3;
    hinoi(n,a,b,c);
    
    return 0;
}
