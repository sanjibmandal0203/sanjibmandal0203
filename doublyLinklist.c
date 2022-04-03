#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *start=NULL;
struct node *create_dl(struct node *start);
struct node *display(struct node *start);
struct node *bni(struct node *start);
struct node *ei(struct node *start);
struct node *ai(struct node *start);
struct node *bfi(struct node *start);
struct node *bnd(struct node *start);
struct node *ed(struct node *start);
struct node *ad(struct node *start);
struct node *bfd(struct node *start);
struct node *ld(struct node *start);

int main(){
    int option;
    do{
        printf("\n\n-----MAIN MENU-----");
        printf("\n1: create a list.");
        printf("\n2: display the list.");
        printf("\n3: insert at beginning.");
        printf("\n4: insert at end.");
        printf("\n5: insert after the pointed node.");
        printf("\n6: insert before the pointed node.");
        printf("\n7: delete from the beginning.");
        printf("\n8: delete from the end.");
        printf("\n9: delete the after node to pointer.");
        printf("\n10: delete the before node to pointre.");
        printf("\n11: delete the entire list.");
        printf("\n12: exit.");
        printf("\n choose option : ");
        scanf("%d", &option);
        switch(option){
            case 1: start=create_dl(start);
            printf("\nA list is created..");
            break;
            case 2: start=display(start);
            printf("\nThat's the list..");
            break;
            case 3: start=bni(start);
            printf("\nbeginning inserted..");
            break;
            case 4: start=ei(start);
            printf("\nend inserted..");
            break;
            case 5: start=ai(start);
            printf("\nafter inserted..");
            break;
            case 6: start=bfi(start);
            printf("\nbefor inserted..");
            break;
            case 7: start=bnd(start);
            printf("\nbeginning deleted..");
            break;
            case 8: start=ed(start);
            printf("\nend deleted..");
            break;
            case 9: start=ad(start);
            printf("\nafter deleted..");
            break;
            case 10: start=bfd(start);
            printf("\nbefore deleted..");
            break;
            case 11: start=ld(start);
            printf("\nlist deleted..");
            break;
            case 12: exit(1);
        }
    }while(option!=12);
    return 0;
}//---------------------delete the entier list ----------------------
struct node *ld(struct node *start){
    //struct node *p;
    while(start!=NULL){
        start=bnd(start);
    }
    return start;
}
//---------------------before node deleted-------------------------
struct node *bfd(struct node *start){
    struct node *p, *tmp;
    int num;
    printf("\nput the node value : ");
    scanf("%d", &num);
    p=start;
    while(p->data!=num)
        p=p->next;
    tmp=p->prev;
    p->prev=tmp->prev;
    tmp->prev->next=p;
    free(tmp);
    return start;
}
//---------------------after node deleted--------------------------
struct node *ad(struct node *start){
    struct node *p, *tmp;
    int num;
    printf("\npoint the node : ");
    scanf("%d", &num);
    p=start;
    while(p->data!=num)
        p=p->next;
    tmp=p->next;
    tmp->next->prev=p;
    p->next=tmp->next;
    free(tmp);
    return start;
}
//----------------------end nodde delete---------------------------
struct node *ed(struct node *start){
    struct node *p;
    p=start;
    while(p->next!=NULL)
        p=p->next;
    p->prev->next=NULL;
    free(p);
    return start;
}
//------------------beginning node delete--------------------------
struct node *bnd(struct node *start){
    struct node *p;
    p=start;
    p=p->next;
    free(start);
    p->prev=NULL;
    start=p;
    return start;
}
//-----------------insert before the pointed node------------------
struct node *bfi(struct node *start){
    struct node *nn, *p;
    int val, num;
    printf("\nput the pointed node value : ");
    scanf("%d", &val);
    printf("Enter the data : ");
    scanf("%d", &num);
    nn=(struct node *)malloc(sizeof(struct node ));
    nn->data=num;
    p=start;
    while(p->data!=val)
        p=p->next;
    nn->prev=p->prev;
    p->prev->next=nn;
    nn->next=p;
    p->prev=nn;
    return start;
}
//---------------insert after the pointed node--------------------
struct node *ai(struct node *start){
    struct node *nn, *ptr;
    int num, val;
    printf("\nput the pointed node value : ");
    scanf("%d", &val);
    printf("\nEnter the data : ");
    scanf("%d", &num);
    nn=(struct node *)malloc(sizeof(struct node *));
    nn->data=num;
    ptr=start;
    while(ptr->data!=val)
        ptr=ptr->next;
    nn->prev=ptr;
    nn->next=ptr->next;
    nn->next->prev=nn;          // A unique line :)
    ptr->next=nn;        
    return start;
}
//--------------------insert a node at end---------------------------
struct node *ei(struct node *start){
    struct node *nn, *ptr;
    int num;
    printf("\nEnter the the data : ");
    scanf("%d", &num);
    nn=(struct node *)malloc(sizeof(struct node ));
    nn->data=num;
    ptr=start;
    while(ptr->next!=NULL)
        ptr=ptr->next;
    nn->prev=ptr;
    ptr->next=nn;
    nn->next=NULL;
    return start;
}
//----------------------insert a node at beginning-------------------
struct node *bni(struct node *start){
    struct node *new_node, *ptr;
    int num;
    printf("\nenter your data : ");
    scanf("%d", &num);
    new_node=(struct node *)malloc(sizeof(struct node ));
    new_node->data=num;
    new_node->prev=NULL;
    new_node->next=start;
    start=new_node;
    return start;
}
//-----------------------display the list----------------------------
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
//--------------------------create a list-------------------------------
struct node *create_dl(struct node *start){
    struct node *new_node, *ptr;
    int num;
    printf("\nEnter the data\n(put -1 to stop) : ");
    scanf("%d", &num);
    while(num!=-1){
        new_node=(struct node *)malloc(sizeof(struct node));
        new_node->data=num;
        if(start==NULL){
            new_node->prev=NULL;
            new_node->next=NULL;
            start=new_node;
        }
        else{
            ptr=start;
            while(ptr->next!=NULL)
                ptr=ptr->next;
            ptr->next=new_node;
            new_node->next=NULL;
            new_node->prev=ptr;
        }
        printf("\n Enter the data : ");
        scanf("%d", &num);
    }
    return start;
}