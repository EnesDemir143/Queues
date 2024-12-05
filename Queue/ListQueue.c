#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#define MAX_SIZE 100
int queue[MAX_SIZE];
int front=-1,rear=-1;

bool isEmpty(){
    if(rear==-1 && front==-1)
        return true;
    return false;

}

void Enqueue(int val){
    if((rear+1)%MAX_SIZE==front)
        return;
    if(isEmpty()){
        rear=0;
        front=0;
    }else{
        rear=(rear+1)%MAX_SIZE;
    }
    queue[rear]=val;
}

void Dequeue(){
    if(isEmpty()){
        return;
    }
    else if(rear==front){
        rear=-1;
        front=-1;
        return;
    }
    front = (front + 1) % MAX_SIZE;
}

void Front(){
    if((rear+1)%MAX_SIZE==front)
        return;
    printf("%d\n",queue[front]);
}

int main(){
    Enqueue(5);
    Front();
    Enqueue(4);
    Front();
    Dequeue();
    Front();

}