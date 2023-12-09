#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include <ctype.h>

struct info{
    char name[100];
    int amount;
};
struct node{
    struct info Good;
    struct node* next;
};
int transform(char a[100]){
    int i;
    int output_num;
    for(i=0;!isspace(a[i]);i++);
    output_num = atoi(a + i + 1);
    return output_num;
}
struct node* createLinkedList(struct info list[100],int* size) {
    FILE *stream;
    stream = fopen("data.txt","r");
    int c,i = 0;
    *size = 0;
    char temp[100][108];
    while ((c = fgetc(stream)) != EOF) {
        if (c == '\n') {
            (*size)++;
            i = 0;
            continue;
        }
        temp[*size][i] = c;
        i++;
    }
    for(i = 0;i < 100;i++){
        list[i].amount = transform(temp[i]);
        for(int j=0;!isspace(temp[i][j]) && temp[i][j] != 0;j++){
            list[i].name[j] = temp[i][j];
        }
    }//从文件读取数据
    struct node* head = NULL;
    struct node* tail = NULL;
    for (int k = 0; k < *size; k++) {
        struct node* p = (struct node*)malloc(sizeof(struct node));
        for(int l = 0;l < 100;l++)
            p->Good.name[l] = (list + k)->name[l];
        p->Good.amount = (list + k)->amount;
        p->next = NULL;
        if (head == NULL) {
            head = p;
            tail = p;
        } else {
            tail->next = p;
            tail = p;
        }
    }
    return head;
}//初始化函数
int search(struct node *head, const char *input_name, const int *size) {
    int i = 0,j = 0;
    struct node* current = head;
    for (i;i < *size;i++){
        for (j;j < 100;j++){
            if (input_name[j] == 0)
                return i;
            if (input_name[j] != current->Good.name[j])
                break;
        }
        current = current->next;
    }
    return -1;
}
//搜索函数
void listdisplay(struct node* head){
    struct node* current = head;
    current = current->next;
    while(current != NULL){
        printf("Good:   %s    Amount:   %d   \n",current->Good.name,current->Good.amount);
        current = current->next;
    }
}
//显示函数
void enter(const struct info *inpution,struct node*head,int *size){
    int k = search(head,inpution->name,size);
    if (k > 0){
        struct node* current = head;
        for (int j = 0; j < k; j++)
            current  = current->next;
        current->Good.amount = current->Good.amount + inpution->amount;
        current = head;
        FILE *stream;
        stream = fopen("data.txt", "w");
        fprintf(stream,"%s","");
        for (int i = 0;i < *size;i++) {
            stream = fopen("data.txt", "at");
            char enter = '\n';
            fprintf(stream, "%s %d%c", current->Good.name, current->Good.amount, enter);
            fclose(stream);
            current = current->next;
        }
    }
    else {
        FILE *stream;
        stream = fopen("data.txt", "at");

        char enter = '\n';
        fprintf(stream, "%s %d%c", inpution->name, inpution->amount, enter);
        fclose(stream);
        (*size)++;
    }
}
//输入函数
void out(const struct info *inpution,struct node*head,int *size){
    int k = search(head,inpution->name,size);
    struct node* current = head;
    struct node* prev = NULL;
    struct node* next =NULL;
    for (int j = 0; j < k; j++){
        prev = current;
        current = current->next;
        next = current->next;
    }
    prev->next = next;
    (*size)--;
    current = head;
    FILE *stream;
    stream = fopen("data.txt", "w");
    fprintf(stream,"%s","");
    for (int i = 0;i < *size;i++) {
        stream = fopen("data.txt", "at");
        char enter = '\n';
        fprintf(stream, "%s %d%c", current->Good.name, current->Good.amount, enter);
        fclose(stream);
        current = current->next;
    }
}
//移除函数
int main(){
    struct info list[100];
    struct info inpution;
    int size = 0;
    struct node* head = createLinkedList(list,&size);
    int input;
    while(1){
        system("cls");
        printf("Please choose the needed operation:\n1.Display the goods list\n2.Enter new goods data\n3.Remove goods data\n4.Shut down\n");
        scanf_s("%d", &input);
        system("cls");
        if (input == 1) {
            listdisplay(head);
            system("pause");
            printf("Press any button to go out");
            getchar();
            continue;
        }
        else if (input == 2) {
            printf("Please input the goods' name and amount you wanna add(Divided by ' '):\n");
            scanf("%s",&inpution.name);
            scanf("%d",&inpution.amount);
            enter(&inpution,head,&size);
            head = createLinkedList(list,&size);
            printf("Data has been added.Press any button to continue");
            system("pause");
            continue;
        }
        else if (input == 3) {
            printf("Please input the goods' name you wanna remove:\n");;
            scanf("%s",&inpution.name);
            out(&inpution,head,&size);
            printf("Data has been removed.Press any button to continue");
            system("pause");
            continue;
        }
        else if (input == 4) {
            free(head);
            system("cls");
            return 0;
        }
    }
}
