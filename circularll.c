#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* Head;


int delete(int pos){
    if(Head == NULL){
        printf("underflow");
        return -1;

    }
    if(Head->next == Head){
        free(Head);
        Head = NULL;
        printf("sdsd");
    }
    else{
        if(pos == -1){
        struct node* current = Head ->next;
        while(current->next->next != Head){
            current = current->next;
        }
        struct node* temp = current->next;
        current->next = current->next->next;
        printf("%d %d",current->next->data, current->next->next->data);
        printf("temp %d" , temp->data);
        free(temp);

        }
        else if(pos == 0){
        struct node* current = Head ->next;
        while(current->next != Head){
            current = current->next;
        }
        Head = Head->next;
        current->next = Head;
        }
        else{
        struct node* current = Head ->next;
        pos--;
        while(current->next != Head && pos > 1){
            current = current->next;
            pos--;
        } 
        struct node* temp;
        temp = current->next;
        current->next = current->next->next;
        free(temp);
        }
    }
}

void insert(int data , int pos){
    if(Head == NULL){
        struct node * new;
        new = (struct node*)malloc(sizeof(struct node));
        new->data = data;
        new->next = new;
        Head = new;
    }
    else{
        if(pos == -1){
        struct node* current = Head ->next;
        while(current->next != Head){
            current = current->next;
        }
        struct node * new;
        new = (struct node*)malloc(sizeof(struct node));
        new->data = data;
        new->next = Head;
        current->next = new;
        }
        else if(pos == 0){
        struct node* current = Head ->next;
        while(current->next != Head){
            current = current->next;
        }
        struct node * new;
        new = (struct node*)malloc(sizeof(struct node));
        new->data = data;
        new->next = Head;
        current->next = new;
        Head = new;
        }
        else{
        struct node* current = Head ->next;
        pos--;
        while(current->next != Head && pos > 0){
            current = current->next;
            pos--;
        } 
        struct node * new;
        new = (struct node*)malloc(sizeof(struct node));
        new->data = data;
        new->next = current->next;
        current->next = new;
        }
    }
}

int printall(){
    if(Head == NULL){
        printf("EMPTY \n");
        return -1;
    }
    printf("%d" , Head->data);
    struct node* current = Head->next;
    while(current != Head){
        printf("-%d " , current->data);
        current = current->next;
    }
    printf("\n");
    return 0;

}

void main(){
    Head = (struct node*)malloc(sizeof(struct node));
    Head = NULL;
    
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