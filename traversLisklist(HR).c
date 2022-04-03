#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct node{
    int data;
    struct node *next;
};
struct node *start=NULL;
struct node *createList(struct node *, int);
void display(struct node *);
int main(){
    int num, i;
    scanf("%d", &num);
    start=createList(start, num);
    display(start);
    return 0;
}
void display(struct node *start){
    struct node *ptr;
    ptr=start;
    while(ptr->next!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
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
