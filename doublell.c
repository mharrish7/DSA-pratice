#include<stdio.h>
#include<stdlib.h>



struct node{
    int data;
    struct node* next;
    struct node* prev;
};




struct node* Head = NULL;


void insert(int data, int pos){
    if(Head == NULL){
        struct node* new ;
        new = (struct node*)malloc(sizeof(struct node));
        new->data = data;
        new->next = NULL;
        new->prev = NULL;
        Head = new;
    }
    else{
        if(pos == 0){
        struct node* new ;
        new = (struct node*)malloc(sizeof(struct node));
        new->data = data;
        new->next = Head;
        new->prev = NULL;
        Head->prev = new;
        Head = new;
        }
        else{
            struct node* current = Head;
            pos--;
            while(current->next != NULL && pos > 0){
                current = current->next;
                pos--;
            }
            if(current->next == NULL){
                struct node* new ;
                new = (struct node*)malloc(sizeof(struct node));
                new->data = data;
                new->next = NULL;
                new->prev = current;
                current->next = new;

            }
            else{

            
            printf("ssdsd %d ",current->data);
            struct node* new ;
            new = (struct node*)malloc(sizeof(struct node));
            new->data = data;
            new->next = current->next;
            new->prev = current;
            current->next->prev = new;
            current->next = new;
            }

        }
    }
}


void printall(){
    struct node* current = Head;
            while(current != NULL){
                printf("-%d-" , current->data);
                current = current->next;
            }

}

int delete(int pos){
    if(Head == NULL){
        printf("underflow");
        return -1;
    }
    
    if(Head->next == NULL){
        free(Head);
        Head = NULL;
    }
    else if(pos == 0){
        struct node * current = Head;
        Head = Head->next;
        Head->prev = NULL;
        free(current);
    }
    else{
        struct node* current = Head;
            while(current->next != NULL && pos > 0){
                current = current->next;
                pos--;
            }
            printf("%d",pos);
            printf("%d", current->data);
            if(current->next == NULL){
                current->prev->next = NULL;
                free(current);
            }
            else{
                current->prev->next = current->next;
                current->next->prev = current->prev;
                free(current);
            }
    }
}

void main(){
    int c;
    printf("Enter the choice");
    scanf("%d",&c);
    while(1){
        if(c==1){
        int data,pos;
        printf("Enter the data to be inserted");
        scanf("%d",&data);
        printf("Enter the position to insert");
        scanf("%d",&pos);
        insert(data , pos);
        }
        else if(c==2){
            printall();

        }
        else if(c==3){
        int pos;
        printf("Enter the position to delete");
        scanf("%d",&pos);
        delete(pos);
        }
        printf("Enter the choice");
        scanf("%d",&c);
    }
}