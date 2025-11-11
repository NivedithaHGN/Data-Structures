#include<stdio.h>
#define size 5

int queue[size];
int rear =0, front =0;

int main()
{
    int choice1,choice2,value;
    char ch;
    do{
        printf("1.Input-restricted deque\n2.Output-restricted deque\n");
        printf("\n Enter your choice:");
        scanf("%d",&choice1);
        switch(choice1)
        {
            case 1:printf("1.Insert\n2.Delete at rear\n3.Delete at front\n4.Display\n");

            do{
                printf("\nEnter your choice:");
                scanf("%d",&choice2);

                switch(choice2)
                {
                    case 1:enqueuerear();
                    display();
                    break;

                    case 2:value=dequeuerear();
                    printf("\nThe value deleted is %d",value);
                    display();
                    break;

                    case 3:value=dequeuefront();
                    printf("\nThe value deleted is %d",value);
                    display();
                    break;

                    case 4:display();
                    break;

                    default : printf("\nWrong selection!!!\n");
                }
                printf("\n|n Do you want to perform another operation Y/N:");
                scanf("%c",&ch);
            }while(ch=='y'||ch=='Y');
            break;

            case 2:printf("1.Insert at rear\n2.Insert at front\n3.Delete\n4.Display\n");
            do
            {
                printf("\nEnter your choice:");
                scanf("%d",&choice2);

                switch(choice2)
                {
                    case 1:enqueuerear();
                    display();
                    break;

                    case 2:enqueuefront();
                    display();
                    break;

                    case 3:value=dequeuefront();
                    printf("\nThe value deleted is %d",value);
                    display();
                    break;

                    case 4:display();
                    break;

                    default : printf("\nWrong selection!!!\n");
                }
                printf("\n\n Do you want to perform another operation Y/N:");
                scanf("%c",&ch);
            }while(ch=='y'||ch=='Y');
            break;
        }
        printf("\n\n Do you want to perform another operation Y/N:");
        scanf("%c",&ch);
    }while(ch=='y'||ch=='Y');
}

void enqueuerear()
{
    int value;
    char ch;
    if (front==size/2)
    {
        printf("\nQueue is Full");
        return;
    }
    do
    {
        printf("\nEnter the value to be inserted:");
        scanf("%d",&value);
        queue[front]=value;
        front++;
        printf("do you want to continue insertion Y/N:");
        ch = getch();
    } while(ch=='y'||ch=='Y');
}

void enqueuefront()
{
    int value;
    char ch;
    if(front==size/2)
    {
        printf("\nQueue is Full");
        return;
    }
    do{
        printf("\nEnter the element to be inserted:");
        scanf("%d",&value);
        rear--;
        queue[rear]=value;
        printf("do you want to continue insertion Y/N:");
        ch = getch();
    } while(ch=='y'||ch=='Y');
}

int dequeuerear()
{
    int deleted;
    if(front==rear)
    {
        printf("\nQueue is Empty");
        return 0;
    }
    front--;
    deleted = queue[front];
    return deleted;
}

int dequeuefront()
{
    int deleted;
    if(front==rear)
    {
        printf("\nQueue is Empty");
        return 0;
    }
    deleted = queue[rear];
    rear++;
    return deleted;
}

void display()
{
    int i;
    if(front==rear)
    {
        printf("\nQueue is empty");
    }
    else{
        printf("\nThe Queue elements are:");
        for (i=rear;i<front;i++)
            printf("%d",queue[i]);
    }
}



