#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *start=NULL;
struct node *create_ll(struct node*);
struct node *display(struct node*);
struct node *beg_insert(struct node*);
struct node *end_insert(struct node*);
struct node *aft_insert(struct node*);
struct node *bef_insert(struct node*);
struct node *beg_delete(struct node*);
struct node *end_delete(struct node*);
struct node *node_delete(struct node*);
struct node *aft_delete(struct node*);
struct node *list_delete(struct node*);
struct node *sort_list(struct node*);
//************************************************************************************
int main(){
    int option;
    do{
        printf("\n\n---- MAIN MENU ----");
        printf("\n1: To create a list.");
        printf("\n2: To display the list.");
        printf("\n3: To insert at begining.");
        printf("\n4: To insert at end of the list.");
        printf("\n5: To insert after a given node.");
        printf("\n6: To insert before a given node.");
        printf("\n7: To delete the beginning node.");
        printf("\n8: To delete the last node.");
        printf("\n9: To delete the perticular node.");
        printf("\n10 : To delete after the pointed node.");
        printf("\n11 : To delete the entier list.");
        printf("\n12 : To sort the list.");
        printf("\n13 : To exit.");
        printf("\n Enter your option : ");
        scanf("%d", &option);
        switch(option){
            case 1: start=create_ll(start);
            printf("\n list is created.");
            break;
            case 2: start=display(start);
            break;
            case 3: start=beg_insert(start);
            printf("\n your first node is updated.");
            break;
            case 4: start=end_insert(start) ;
            printf("\n your last node is updated.");
            break;
            case 5: start=aft_insert(start);
            printf("\n your list is updated.");
            break;
            case 6:start=bef_insert(start);
            printf("\n your list is updated.");
            break;
            case 7: start=beg_delete(start);
            printf("\n beginning node is deleted.");
            break;
           case 8: start=end_delete(start);
            printf("\n end node is deleted.");
            break;
            case 9: start=node_delete(start);
            printf("\n pointed node is deleted.");
            break;
            case 10: start=aft_delete(start);
            printf("\n pointed node is deleted.");
            break;
            case 11: start=list_delete(start);
            printf("\n Entier list is deleted.");
            break;
            case 12: start=sort_list(start);
            printf("\n The list is sorted.");
            break;
            case 13: exit(1);
        }
    }while(option!=13);
    return 0;
}
/*------------------------------   LETS CREATE THE LIST  -------------------------------*/
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
/*-------------------------DISPLAY THE LIST THAT WAS CREATED--------------------------*/
struct node *display(struct node *start){
    struct node *ptr;
    ptr=start;
    printf("\n The list is : \n");
    while(ptr!=NULL){
        printf("\t%d", ptr->data);
        ptr=ptr->next;
    }
    return start;
}
/*-----------------------------INSERT THE NODE AT BEGINNING-----------------------------*/
struct node *beg_insert(struct node *start){
    struct node *first_node;
    int num;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    first_node=(struct node*)malloc(sizeof(struct node));
    first_node->data=num;
    first_node->next=start;
    start=first_node;
    return start;
}
/*-----------------------------INSERT THE NODE AT END---------------------------------*/
struct node *end_insert(struct node *start){
    int num;
    struct node *end_node, *ptr;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    end_node=(struct node*)malloc(sizeof(struct node));
    end_node->data=num;
    end_node->next=NULL;
    ptr=start;
    while(ptr->next!=NULL)
        ptr=ptr->next;
    ptr->next=end_node;
    return start;
}
/*---------------------INSERT THE NODE AFTER THE POINTED NODE ------------------------*/
struct node *aft_insert(struct node *start){
    int num, data;
    struct node *ptr, *new_node;
    printf("\n aftr which node you want to\n insert your data : ");
    scanf("%d", &num);
    printf("\n Enter your data : ");
    scanf("%d", &data);
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    ptr=start;
    while(ptr->data!=num)
        ptr=ptr->next;
    new_node->next=ptr->next;
    ptr->next=new_node;
    return start;
}
/*----------------------INSERT THE NODE BEFORE THE POINTED NODE-------------------------*/
struct node *bef_insert(struct node *start){
    struct node *new_node, *ptr, *prePtr;
    int num, data;
    printf("\n before which node\n you want to insert your data : ");
    scanf("%d", &num);
    printf("\n Enter youe data : ");
    scanf("%d", &data);
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    ptr=start;
    prePtr=ptr;
    while(ptr->data!=num){
        prePtr=ptr;
        ptr=ptr->next;
    }
    prePtr->next=new_node;
    new_node->next=ptr;
    return start;
}
/*---------------------------DELETE THE NODE AT BEGANNING-------------------------------*/
struct node *beg_delete(struct node *start){
    struct node *ptr;
    ptr=start;
    start=start->next;
    free(ptr);
    return start;
}
/*---------------------------------DELETE THE END NODE--------------------------------*/
struct node *end_delete(struct node *start){
    struct node *ptr, *prePtr;
    ptr=start;
    prePtr=ptr;
    while(ptr->next!=NULL){
        prePtr=ptr;
        ptr=ptr->next;
    }
    prePtr->next=NULL;
    free(ptr);
    return start;
}
/*--------------------------------DELETE THE POINTED NODE-------------------------------*/
struct node *node_delete(struct node *start){
    int num;
    struct node *ptr, *prePtr;
    printf("\n enter the data to delete : ");
    scanf("%d", &num);
    ptr=start;
    prePtr=ptr;
    while(ptr->data!=num){
        prePtr=ptr;
        ptr=ptr->next;
    }
    prePtr->next=ptr->next;
    free(ptr);
    return start;
}
/*-------------------------delete after perticular node-------------------------------*/
struct node *aft_delete(struct node *start){
    int num;
    struct node *ptr, *pstPtr;
    printf("\n put the value, to delete the after node : ");
    scanf("%d", &num);
    ptr=start;
    while(ptr->data!=num)
       ptr=ptr->next;
    pstPtr=ptr->next;
    ptr->next=pstPtr->next;
    free(pstPtr);
    return start;
}/*---------------------DELETE THE ENTIER LIST------------------------*/
struct node *list_delete(struct node *start){
    struct node *ptr, *ptr2, *prePtr;
    //ptr=start;
    ptr2=start;
    //prePtr=ptr;
    while(ptr2->next!=NULL){
        ptr=start;
        while(ptr->next!=NULL){
        prePtr=ptr;
        ptr=ptr->next;
        }
        prePtr->next=NULL;
        printf("\t%d",ptr->data);
        free(ptr);
        ptr2=start;
    }
    if(start->next==NULL){
        printf("\t%d", start->data);
        free(start);
    }
    return start;
}
/*-----------------------------SOTR THE LIST---------------------------------*/
struct node *sort_list(struct node *start){
    struct node *ptr1, *ptr2;
    int temp;
    ptr1=start;
    while(ptr1->next!=NULL){
        ptr2=ptr1->next;
        while(ptr2!=NULL){
            if(ptr1->data>ptr2->data){
                temp=ptr1->data;
                ptr1->data=ptr2->data;
                ptr2->data=temp;
            }
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }
    return start;
}