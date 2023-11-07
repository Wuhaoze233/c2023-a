#include<stdio.h>
int isPrime(int n)
{
    if (n<=1)
        return 0;
    else
        for (int i=2;i*i<=n;i++)
            if (n%i==0)
                return 0;
    return 1;
}
int main()
{
    int n;
    printf("Please input your figure:");
    scanf("%d",&n);
    if (isPrime(n))
        printf("It's a Prime.");
    else
        printf("It's not a Prime.");
    return 0;
}
