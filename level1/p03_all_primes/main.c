#include <stdio.h>
#include <time.h>
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
    int start,end;
    start = clock();
    for (int n = 2; n <= 1000; n++)
    {
        if (isPrime(n))
            printf("%d \n", n);
    }
    end = clock();
    printf("time=%lf\n",(double)(end-start)/CLOCKS_PER_SEC);
    return 0;
}