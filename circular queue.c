#include<stdio.h>
#define size 3
int c_queue[size];
int front = -1;
int rear =-1;

void main()
{
    int choice, object;

    while(1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice)
    {
        case 1:printf("Enter the item to be inserted:\n");
        scanf("%d",&object);
        enqueue(object);
        break;

        case 2:dequeue();
        break;

        case 3:display();
        break;

        case 4:exit(0);

        default :printf("Invalid!!!");
    }
    }
}

int isFull()
{
    if (front == (rear+1)%size)
        return 1;
    return 0;
}

int isEmpty()
{
    if (front == -1)
        return 1;
    return 0;
}

void enqueue(int object)
{
    if(isFull())
        printf("Queue is Full!!!\n");
    else
    {
        if (front==-1) front=0;
        rear = (rear+1)%size;
        c_queue[rear]=object;
        printf("Inserted->%d\n",object);
    }
}

void dequeue()
{
    if(isEmpty())
        printf("Queue is Empty!!!\n");
    else
    {
        int element = c_queue[front];
        if(front==rear){front=-1;rear =-1;}
        else
        {
            front = (front+1)%size;
        }
        printf("Deleted - > %d\n",element);
    }
}

void display()
{
    if(isEmpty())
        printf("Queue is Empty!!!\n");
    else
    {
        int i;
        for (i = front;i!= rear;i=(i+1)%size)
        {
            printf("%d",c_queue[i]);
        }
        printf("\n%d",c_queue[i]);
        printf("\nRear -> %d\n",rear);
    }
}
