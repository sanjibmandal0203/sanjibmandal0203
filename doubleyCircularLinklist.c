#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *start=NULL;
struct node *create_cdll(struct node*);
struct node *display(struct node*);
struct node *begInsert(struct node*);
struct node *endInsert(struct node*);
struct node *begDelete(struct node*);
struct node *endDelete(struct node*);
struct node *aftDelete(struct node*);
struct node *listDelete(struct node*);
int main(){
    int option;
    do{
        printf("\n\n-----MAIN MENU-----");
        printf("\n1: to create a list.");
        printf("\n2: to display the list.");
        printf("\n3: to add a node at the beginning.");
        printf("\n4: to add a node at the end.");
        printf("\n5: to delete a node form the beginning.");
        printf("\n6: to delete a node from the end.");
        printf("\n7: to delete a node after a given node.");
        printf("\n8: to delete the entier list.");
        printf("\n9: to exit.");
        printf("\n Enter your option : ");
        scanf("%d", &option);
        switch(option){
            case 1: start=create_cdll(start);
            printf("\nA list is created..");
            break;
            case 2: start=display(start);
            printf("\nWell that's the list..");
            break;
            case 3: start=begInsert(start);
            printf("\nA new node is added at the beginning..");
            break;
            case 4: start=endInsert(start);
            printf("\nA new node is added at the end..");
            break;
            case 5: start=begDelete(start);
            printf("\nThe beginning node is deleted..");
            break;
            case 6: start=endDelete(start);
            printf("\nThe end node is deleted..");
            break;
            case 7: start=aftDelete(start);
            printf("\nThe node is deleted, which\nexist after the pointed node..");
            break;
            case 8: start=listDelete(start);
            printf("\nThe entire list is deleted..");
            break;
            case 9: exit(1);
        }
    }while(option!=9);
    return 0;
}//---------------------delete the entier list------------------------
struct node *listDelete(struct node *start){
    struct node *ptr;
    ptr=start;
    while(ptr->next!=start){
        start=begDelete(start);
    }
    free(start);
    return start;
}
//-------------------delete the after node of pointed node------------------
struct node *aftDelete(struct node *start){
    struct node *ptr, *tmp;
    int num;
    printf("\nEnter the node : ");
    scanf("%d", &num);
    ptr=start;
    while(ptr->data!=num)
        ptr=ptr->next;
    tmp=ptr->next;
    ptr->next=tmp->next;
    tmp->next->prev=ptr;
    free(tmp);
    return start;
}//--------------------------end delete------------------------------
struct node *endDelete(struct node *start){
    struct node *ptr, *tmp;
    ptr=start;
    while(ptr->next!=start)
        ptr=ptr->next;
    start->prev=ptr->prev;
    ptr->prev->next=start;
    free(ptr);
    return start;
}//--------------------------beginning delete---------------------------
struct node *begDelete(struct node *start){
    struct node *ptr, *tmp;
    ptr=start;
    while(ptr->next!=start)
        ptr=ptr->next;
    tmp=start->next;
    ptr->next=tmp;
    tmp->prev=NULL;
    free(start);
    start=tmp;
    return start;
}//----------------------------end insert--------------------------------
struct node *endInsert(struct node *start){
    struct node *newNode, *ptr;
    int num;
    printf("\nEnter the data : ");
    scanf("%d", &num);
    newNode=(struct node *)malloc(sizeof(struct node));
    newNode->data=num;
    ptr=start;
    while(ptr->next!=start)
        ptr=ptr->next;
    ptr->next=newNode;
    newNode->prev=ptr;
    newNode->next=start;
    return start;
}//--------------------------beginning insert-----------------------------
struct node *begInsert(struct node *start){
    struct node *newNode, *ptr;
    int num;
    printf("\nEnter the data : ");
    scanf("%d", &num);
    newNode=(struct node *)malloc(sizeof(struct node));
    newNode->data=num;
    ptr=start;
    while(ptr->next!=start)
        ptr=ptr->next;
    start->prev=newNode;
    newNode->prev=ptr;
    newNode->next=start;
    start=newNode;
    ptr->next=start;
    return start;
}
//--------------------------display the list------------------------------
struct node *display(struct node *start){
    struct node *ptr;
    ptr=start;
    while(ptr->next!=start){
        printf("\t%d", ptr->data);
        ptr=ptr->next;
    }
    printf("\t%d",ptr->data);
    return start;
}//-----------------------------create list--------------------------------
struct node *create_cdll(struct node *start){
    struct node *newNode, *ptr;
    int num;
    printf("\nEnter the data\n(to stop put -1) : ");
    scanf("%d", &num);
    while(num!=-1){
        newNode=(struct node *)malloc(sizeof(struct node));
        newNode->data=num;
        if(start==NULL){
            newNode->prev=NULL;
            newNode->next=newNode;
            start=newNode;
        }
        else{
            ptr=start;
            while(ptr->next!=start)
                ptr=ptr->next;
            ptr->next=newNode;
            newNode->next=start;
            newNode->prev=ptr;
            start->prev=newNode;
        }
        printf("\nEnter the data : ");
        scanf("%d", &num);
    }
    return start;
}