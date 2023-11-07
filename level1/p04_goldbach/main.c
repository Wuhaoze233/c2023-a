#include <stdio.h>
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
    {
        for (int n = 2; n <= 100; n = n + 2)
        {
            int a;
            for (a = 1; a < n/2; a++)
                if (((isPrime(a))&&(isPrime(n-a))) == 1){
                    printf("%d = %d + %d \n",n,a,n-a);
                    break;
                }

        }
    }
    return 0;
}