 #include<stdio.h>
 #include<stdlib.h>
 #include<stdbool.h>

 struct Node{
    int val;
    struct Node* next;
 };

bool isEmpty(struct Node** head,struct Node** tail){
    if(*head==NULL && *tail==NULL)
        return true;
    return false;
}

void Enqueue(int val,struct Node** head,struct Node** tail){
    struct Node* new_node=malloc(sizeof(struct Node));
    new_node->val=val;
    new_node->next=NULL;
    if(isEmpty(head,tail)){
        *head=new_node;
        *tail=new_node;
        return;
    }
    (*tail)->next=new_node;
    (*tail)=(*tail)->next;
}

void Dequeue(struct Node** head,struct Node** tail){
    if(isEmpty(head,tail)){
        return;
    }
    struct Node* temp=*head;
    (*head)=(*head)->next;
    if(*head==NULL){
        *tail=NULL;
    }
    free(temp);
}

int front(struct Node** head,struct Node** tail){
    if(isEmpty(head,tail))
        exit(1);
    printf("%d\n",(*head)->val);
    return (*head)->val;
}

 int main(){
    struct Node* head=NULL;
    struct Node* tail=NULL;

    Enqueue(5,&head,&tail);
    front(&head,&tail);
    Enqueue(4,&head,&tail);
    front(&head,&tail);
    Dequeue(&head,&tail);
    front(&head,&tail);
 }