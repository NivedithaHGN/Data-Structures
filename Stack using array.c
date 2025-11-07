  #include<stdio.h>
  #define size 5

  void push();
  void pop();
  void display();

  int stack[size],top=-1;

  void main()
  {
           int value,choice;

           while (1)
           {
                    printf("\nMENU\n");
                    printf("1.Push\n 2.Pop\n 3.Display\n 4.Exit\n");
                    printf("Enter your choice:");
                    scanf("%d",&choice);

                    switch(choice)
                    {
                             case 1 :printf("Value to insert:");
                             scanf("%d",&value);
                             push(value);
                             break;
                             case 2:pop();
                             break;
                             case 3:display();
                             break;
                             case 4:exit(0);
                             default:printf("Wrong Selection,Try again");
                    }
           }
  }

  void push(int value)
  {
           if (top ==(size-1))
           {
                    printf("Stack is full\n");
           }
           else
           {
                    top++;
                    stack[top]=value;
                    printf("Insertion Success\n");
           }
  }
  void pop()
  {
           if (top ==(-1))
         {
                  printf("Stack is empty\n");
         }
           else
         {
                  printf("Deleted:%d",stack[top]);
                  top--;
         }
  }
  void display()
  {
           if (top==-1)
           {
                    printf("stack is empty\n");
           }
           else
           {
                    int i;
                    printf("Stack elements\n");
                    for (i=top;i>=0;i--)
                           printf("%d\n",stack[i]);
           }
  }
