#include <stdio.h>
#include <stdlib.h>
//using namespace std;
struct node{
    int data;
    struct node *next;
};
struct node *start=NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *revers_ll(struct node *);
int main(){
    int option;
    do{
        printf("\n\n-----MAIN MENU-----");
        printf("\n1: to create a list.");
        printf("\n2: to display the list.");
        printf("\n3: reverse the list.");
        printf("\n4: to exit.");
        printf("\n Enter your option : ");
        scanf("%d", &option);
        switch(option){
            case 1: start=create_ll(start);
            printf("\nA list is created..");
            break;
            case 2: start=display(start);
            printf("\nWell that's the list..");
            break;
            case 3: start=revers_ll(start);
            printf("\nList is reversed..");
            break;
            case 4: exit(1);
        }
    }while(option!=4);
    return 0;
}
struct node *revers_ll(struct node *start){
    struct node *pre, *curr, *nxt;
    pre=NULL;
    curr=start;
    while(curr!=NULL){
        nxt=curr->next;
        curr->next=pre;
        pre=curr;
        curr=nxt;
    }
    return pre;
}
struct node *display(struct node *start){
    struct node *ptr;
    ptr=start;
    while(ptr!=NULL/*ptr->next!=NULL*/){
        printf("\t%d", ptr->data);
        ptr=ptr->next;
    }
    //printf("\t%d", ptr->data);
    return start;
}
struct node *create_ll(struct node *start){
    struct node *new_node, *ptr;
    int num;
    printf("\n enter the data\n (press -1 to end) : ");
    scanf("%d", &num);
    while(num!=-1){
        new_node=(struct node*)malloc(sizeof(struct node));
        new_node->data=num;
        if(start==NULL){
            new_node->next=NULL;
            start=new_node;
        }
        else{
            ptr=start;
            while(ptr->next!=NULL)
                ptr=ptr->next;
            ptr->next=new_node;
            new_node->next=NULL;
        }
        printf("\n Enter the data : ");
        scanf("%d", &num);
    }
    return start;
}