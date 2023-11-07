#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
};

// 创建单向链表
struct Node* createLinkedList(int *arr, int size) {
    struct Node* head = NULL;
    struct Node* tail = NULL;
    for (int i = 0; i < size; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->value = arr[i];
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

// 遍历链表并打印节点的值
void traverseLinkedList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }

    printf("\n");
}

// 反序链表
struct Node* reverseLinkedList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

// 查找值为5的节点
int findNode(struct Node* head, int target) {
    struct Node* current = head;
    int index = 0;

    while (current != NULL) {
        if (current->value == target) {
            return index;
        }

        current = current->next;
        index++;
    }

    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    struct Node* head = createLinkedList(arr, size);

    printf("Original Linked List: ");
    traverseLinkedList(head);

    head = reverseLinkedList(head);

    printf("Reversed Linked List: ");
    traverseLinkedList(head);

    int firstIndex = findNode(head, 5);
    printf("First occurrence of 5 at index: %d\n", firstIndex);

    int secondIndex = findNode(head, 5);
    printf("Second occurrence of 5 at index: %d\n", secondIndex);

    return 0;
}