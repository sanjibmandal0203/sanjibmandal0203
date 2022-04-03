#include <stdio.h>
#include <stdlib.h>
//using namespace std;
struct node{
    int data;
    struct node *next;
};
struct node *start=NULL;
struct node *createList(struct node *, int);
struct node *deleteAtPosition(struct node *, int);
void display(struct node *);
int main(){
    int num, pos;
    scanf("%d", &num);
    start=createList(start, num);
    scanf("%d", &pos);
    start=deleteAtPosition(start, pos);
    display(start);
    return 0;
}
struct node *deleteAtPosition(struct node *start, int pos){
    struct node *ptr, *hold;
    int i=1;
    if(pos==0){
        hold=start;
        start=start->next;
        free(hold);
        return start;
    }
    ptr=start;
    while(i<pos){
        ptr=ptr->next;
        i++;
    }
    hold=ptr->next;
    ptr->next=hold->next;
    free(hold);
    return start;
}
void display(struct node *start){
    struct node *ptr;
    ptr=start;
    while(ptr->next!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("%d", ptr->data);
}
struct node *createList(struct node *start, int num){
    struct node *ptr, *newNode;
    int i=1, val;
    while(i<=num){
        newNode=(struct node *)malloc(sizeof(struct node));
        scanf("%d", &val);
        newNode->data=val;
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
        i=i+1;
    }
    return start;
}
