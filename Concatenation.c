#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node *NODE;

NODE Insert_FirstRear(NODE First);
NODE Insert_SecondRear(NODE Second);
void Display(NODE First,NODE Second);
NODE concat(NODE First, NODE Second);

void main()
{
    NODE First=NULL, Second=NULL;
    int choice;
    while(1){
            printf("\n1.First->Insert Rear\n2.Second->Insert Rear\n3.Concatenation\n4.Display\n5.Exit");
            printf("\n\nEnter your choice:");
            scanf("%d",&choice);

            switch(choice)
            {
                case 1:Insert_FirstRear(First);
                break;

                case 2:Insert_SecondRear(Second);
                break;

                case 3:concat(First,Second);
                break;

                case 4:Display(First,Second);
                break;

                case 5:exit(0);
            }
}
}

NODE Insert_FirstRear(NODE First)
{
    NODE newnode = malloc(sizeof(struct node));
    NODE cur=First;

    if(newnode==NULL)
        printf("Insufficient Memory\n"); return;

    printf("Enter element to be inserted:");
    scanf("%d",&newnode->data);

    while(cur->next!=NULL)
    {
        cur=cur->next;
    }
    cur->next = newnode;
}

NODE Insert_SecondRear(NODE Second)
{
    NODE cur=Second;
    NODE newnode = (NODE)malloc(sizeof(struct node));

    if(newnode==NULL)
        printf("Insufficient Memory\n"); return Second;

    printf("Enter element to be inserted:");
    scanf("%d",&newnode->data);

    while(cur->next!=NULL)
    {
        cur=cur->next;
    }
    cur->next = newnode;
}

void Display(NODE First,NODE Second)
{
    NODE temp1=First, temp2=Second;

    if(temp1 == NULL)
    {
        printf("First->empty list\n");
    }

    else
    {
        printf("First list elements:\n");
        while(temp1->next!=NULL)
        {
            printf("%d",temp1->data);
            temp1=temp1->next;
        }
        printf("%d",temp1->data);
    }

    if(temp2 == NULL)
        printf("Second->Empty list");
    else
    {
        printf("Second list elements:");
        while(temp2->next!=NULL)
        {
            printf("%d",temp2->data);
            temp2=temp2->next;
        }
        printf("%d",temp1->data);
    }
}

NODE concat(NODE First, NODE Second)
{
    if (First == NULL && Second == NULL) {
        printf("Both lists are empty\n");
        return NULL;
    }
    else if (First == NULL) {
        return Second;
    }
    else if (Second == NULL) {
        return First;
    }
    else {
        NODE cur = First;
        while (cur->next != NULL)
            cur = cur->next;
        cur->next = Second;
        return First;
    }
}

