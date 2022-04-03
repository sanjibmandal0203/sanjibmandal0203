#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *start=NULL;
struct node *create_cll(struct node*);
struct node *display(struct node*);
int main(){
    int option;
    do{
        printf("\n\n-----MAIN MENU-----");
        printf("\n1: to create a list.");
        printf("\n2: to display the list.");
        printf("\n3: to exit.");
        printf("\n Enter your option : ");
        scanf("%d", &option);
        switch(option){
            case 1: start=create_cll(start);
            printf("\nA list is created..");
            break;
            case 2: start=display(start);
            printf("\nWell that's the list..");
            break;
            case 3: exit(1);
        }
    }while(option!=3);
    return 0;
}
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
struct node *display(struct node *start){
    struct node *ptr;
    ptr=start;
    while(ptr->next!=start){
        printf("\t%d", ptr->data);
        ptr=ptr->next;
    }
    printf("\t%d", ptr->data);
    return start;
}