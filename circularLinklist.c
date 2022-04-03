#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *start=NULL;
struct node *create_cll(struct node*);
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
            case 1: start=create_cll(start);
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
}//------------------------delete the entier list-------------------------------
struct node *listDelete(struct node *start){
    struct node *ptr;
    ptr=start;
    while(ptr->next!=start)
        start=endDelete(start);
    free(start);
    return start;
}
//-----------delete the node, which exist after the pointed node---------------
struct node *aftDelete(struct node *start){
    struct node *pstptr, *ptr;
    int num;
    printf("\nEnter the data : ");
    scanf("%d", &num);
    ptr=start;
    while(ptr->data!=num)
        ptr=ptr->next;
    pstptr=ptr->next;
    ptr->next=pstptr->next;
    free(pstptr);
    return start;
}//------------------------delete a node from the end----------------------------
struct node *endDelete(struct node *start){
    struct node *pptr, *ptr;
    ptr=start;
    pptr=ptr;
    while(ptr->next!=start){
        pptr=ptr;
        ptr=ptr->next;
    }
    pptr->next=start;
    free(ptr);
    return start;
}//------------------------delete a node from the begining--------------------------
struct node *begDelete(struct node *start){
    struct node *new_start, *ptr;
    new_start=start->next;
    ptr=start;
    while(ptr->next!=start)
        ptr=ptr->next;
    ptr->next=new_start;
    free(start);
    start=new_start;
    return start;
}//----------------------------insert node at end---------------------------------
struct node *endInsert(struct node *start){
    struct node *new_node, *ptr;
    int num;
    printf("\nEnter the data :");
    scanf("%d", &num);
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=num;
    ptr=start;
    while(ptr->next!=start)
        ptr=ptr->next;
    ptr->next=new_node;
    new_node->next=start;
    return start;
}//-----------------------------insert node at beginning----------------------------
struct node *begInsert(struct node *start){
    struct node *new_node, *ptr;
    int num;
    printf("\nEnter the data : ");
    scanf("%d", &num);
    new_node=(struct node *)malloc(sizeof(struct node *));
    new_node->data=num;
    ptr=start;
    while(ptr->next!=start)
        ptr=ptr->next;
    new_node->next=start;
    start=new_node;
    ptr->next=start;
    return start;
}//-------------------------------display the list---------------------------------
struct node *display(struct node *start){
    struct node *ptr;
    ptr=start;
    while(ptr->next!=start){
        printf("\t%d", ptr->data);
        ptr=ptr->next;
    }
    printf("\t%d", ptr->data);
    return start;
}//-------------------------------creart the list-------------------------------------
struct node *create_cll(struct node *start){
    struct node *new_node, *ptr;
    int num;
    printf("\nEnter your data\n(put -1 to stop) : ");
    scanf("%d", &num);
    ptr=start;
    while(num!=-1){
        new_node=(struct node*)malloc(sizeof(struct node));       // Dynamic memory allocation
        new_node->data=num;
        if(start==NULL){
            new_node->next=new_node;        // This line recognise circular form :)
            start=new_node;
        }
        else{
            ptr=start;
            while(ptr->next!=start)
                ptr=ptr->next;
            ptr->next=new_node;
            new_node->next=start;
        }
        printf("\nEnter the data : ");
        scanf("%d", &num);
    }
    return start;
}