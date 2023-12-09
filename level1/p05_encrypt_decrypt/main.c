#include <stdio.h>
#include <string.h>
int n;
void encrypt_1(char input[n],int key)
{
    for (int i=0;i<strlen(input);i++)
        input[i]=input[i]+key;
}
void decrypt_1(char input[n],int key)
{
    for (int i=0;i<strlen(input);i++)
        input[i]=input[i]-key;
}
int main(){
    char input[1000];
    int key;
    int judging;
    printf("Please input the sentence you wanna encrypt or decrypt:\n");
    gets(input);
    printf("Please input your key:\n");
    scanf_s("%d",&key);
    printf("Mode decide:1.Encrypt 2.Decrypt\n");
    scanf_s("%d",&judging);
    if (judging==1)
        encrypt_1(input,key);
    else
        decrypt_1(input,key);
    printf("%1000s",input);
    return 0;
}
/* ASCII码直接替换 */