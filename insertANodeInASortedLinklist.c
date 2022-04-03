// Insert a node in a sorted linklist
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *start=NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insertNode(struct node *);
int main(){
    int option;
    do{
        printf("\n\n----MAIN MENU----");
        printf("\n1: create list(sorted list incremented order).");
        printf("\n2: display list.");
        printf("\n3: insert node.");
        printf("\nEnter your option : ");
        scanf("%d", &option);
        switch(option){
            case 1: start=create_ll(start);
            printf("\nlist is created!");
            break;
            case 2: start=display(start);
            printf("\nthat's the list!");
            break;
            case 3: start=insertNode(start);
            printf("\nlist is updated!");
            break;
        }
    }while(option!=4);
    return 0;
}
struct node *insertNode(struct node *start){
    struct node *newNode, *ptr, *ptr1, *preptr;
    int num;
    printf("\nEnter the data : ");
    scanf("%d", &num);
    newNode=(struct node *)malloc(sizeof(struct node));
    newNode->data=num;
    if(start->data>newNode->data){
        newNode->next=start;
        start=newNode;
    }
    else{
        ptr=start;
        while(ptr->next!=NULL)
            ptr=ptr->next;
        if(ptr->data<newNode->data){
            ptr->next=newNode;
            newNode->next=NULL;
        }
        else{
            ptr1=start;
            preptr=ptr1;
            while(ptr1->data<newNode->data)
        }
    }
    return start;
}
struct node *display(struct node *start){
    struct node *ptr;
    ptr=start;
    while(ptr!=NULL){
        printf("\t%d", ptr->data);
        ptr=ptr->next;
    }
    return start;
}
struct node *create_ll(struct node *start){
    struct node *newNode, *ptr;
    int num;
    printf("\nEntr your data : ");
    scanf("%d", &num);
    while(num!=-1){
        newNode=(struct node *)malloc(sizeof(struct node));
        newNode->data=num;
        if(start==NULL){
            newNode->next=NULL;
            start=newNode;
        }
        else{
            ptr=start;
            while(ptr->next!=NULL)
                ptr=ptr->next;
            ptr->next=newNode;
            newNode->next=NULL;
        }
        printf("\nEnter your data : ");
        scanf("%d", &num);
    }
    return start;
}