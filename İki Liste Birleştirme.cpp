#include<stdio.h>
#include<stdlib.h>
//Ýki listeyi Birleþtirme
struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* mergeLists(struct Node* head1, struct Node* head2) {
    struct Node* ptr1;
    struct Node* ptr2;
    ptr1 = head1;
    ptr2 = head2;
    while(ptr1->next != NULL)
        ptr1 = ptr1->next;
    ptr1->next = ptr2;
    return head1;
}

void printList(struct Node* head) {
    struct Node* ptr = head;
    while(ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    struct Node* head1 = createNode(1);
    head1->next = createNode(2);
    head1->next->next = createNode(3);
    printf("List 1: ");
    printList(head1);
    struct Node* head2 = createNode(4);
    head2->next = createNode(5);
    head2->next->next = createNode(6);
    printf("List 2: ");
    printList(head2);
    head1 = mergeLists(head1, head2);
    printf("Merged List: ");
    printList(head1);
    return 0;
}

