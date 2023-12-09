#include <stdio.h>
#include <time.h>
int count;
void move(char A,char C,int n);
void hanoi(char A,char B,char C,int n);
int main(){
    int clock_begin,clock_end;
    int  n = 0;
    count = 0;
    char A = 'A',B = 'B',C = 'C';
    printf("Number of dishes:\n");
    scanf("%d",&n);
    clock_begin = clock();
    hanoi(A,B,C,n);
    clock_end = clock();
    printf("Sum is %d\n",count);
    printf("Total calculative time is %ds.",(clock_end-clock_begin)/CLOCKS_PER_SEC);
    return 0;
}
void hanoi(char A,char B,char C,int n){
    if(n==1)
        move(A,C,n);
    else
    {
        hanoi(A,C,B,n-1);
        move(A,C,n);
        hanoi(B,A,C,n-1);
    }
}
void move(char A,char C,int n){
    printf("dish no.%d from %c --> %c\n",n,A,C);
    count++;
}