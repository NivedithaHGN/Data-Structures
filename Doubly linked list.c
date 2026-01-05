#include<stdio.h>
#include<stdlib.h>

struct node{
int info;
struct node *lptr;
struct node *rptr};

typedef struct node *NODE;

void display(NODE first);
NODE insert_front(NODE first);
NODE insert_rear(NODE first);
NODE delete_front(NODE first);
NODE delete_rear(NODE first);

void main()
{
    NODE first = NULL;
    int choice;
    while(1)
    {
        printf("\n---Doubly Linked List---\n");
        printf("\n1.Insert Front\n2.Insert Rear\n3.Delete Front\n4.Delete Rear\n5.Dislay\n");
        printf("\nEnter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:first =insert_front(first);
            break;

            case 2:first =insert_rear(first);
            break;

            case 3:first =delete_front(first);
            break;

            case 4:first =delete_rear(first);
            break;

            case 5:display(first);
            break;

            case 6:exit(0);

            default:printf("\nInvalid!!!");
            break;
        }
    }
}

NODE insert_front(NODE first)
{
    NODE new_node= (NODE)malloc(sizeof(struct node));

    if (new_node==NULL)
    {
        printf("INSUFFICIENT MEMORY!!");
        return first;
    }

    printf("Enter data:");
    scanf("%d",&new_node->info);
    new_node->rptr =NULL;
    new_node->lptr =NULL;

    if (first==NULL)
    {
        first = new_node;
        printf("Inserted\n");
        return first;
    }

    NODE cur = first;
    first->lptr = new_node;
    new_node->rptr = cur;
    first = new_node;
    printf("Inserted\n");
    return first;
}

NODE insert_rear(NODE first)
{
    NODE new_node= (NODE)malloc(sizeof(struct node));

    if (new_node==NULL)
    {
        printf("INSUFFICIENT MEMORY!!");
        return first;
    }

    printf("Enter data:");
    scanf("%d",&new_node->info);
    new_node->rptr =NULL;
    new_node->lptr =NULL;

    if (first==NULL)//Empty List
    {
        first = new_node;
        printf("Inserted\n");
        return first;
    }

    NODE cur = first;
    while(cur->rptr!=NULL)
    {
        cur=cur->rptr;
    }

    cur->rptr = new_node;
    new_node->lptr = cur;
    printf("Inserted\n");
    return first;
}

NODE delete_front(NODE first)
{
    if (first==NULL)
    {
        printf("Empty LIST!!\n");
        return NULL;
    }
    if(first->rptr==NULL)
    {
        free(first);
        printf("Deleted\n");
        return NULL;
    }

    NODE cur = first;
    first = first->rptr;
    first->lptr = NULL;
    free(cur);
    printf("Deleted\n");
    return first;
}

NODE delete_rear(NODE first)
{
     if (first==NULL)
    {
        printf("Empty LIST!!\n");
        return NULL;
    }
    if (first->rptr == NULL)
    {
        free(first);
        return NULL; // list becomes empty
    }

    NODE cur = first;
    NODE prev = NULL;
    while(cur->rptr!=NULL)
    {
        prev= cur;
        cur=cur->rptr;
    }
    prev->rptr = NULL;
    free(cur);
    printf("Deleted\n");
    return first;
}

void display(NODE first)
{
    if (first==NULL)
    {
        printf("Empty LIST!!\n");
        return;
    }

    printf("\n---List Elements---\n");
    NODE cur = first;
    while(cur->rptr!=NULL)
    {
        printf("%d",cur->info);
        cur=cur->rptr;
    }
    printf("\n%d\n",cur->info);
}




