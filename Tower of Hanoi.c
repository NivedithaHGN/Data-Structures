#include<stdio.h>
void main()
{
    int n;
    printf("Enter no. of disks:");
    scanf("%d",&n);
    printf("Sequences are: A,B,C\n");
    tower(n,'A','B','C' );
}
void tower(int n,char from, char aux, char to)
{
    if (n==1)
    {
        printf("move 1 from %c to %c\n",from,to);
        return;
    }
    tower(n-1,from,to,aux);
    printf("Move %d from %c to %c\n",n,from,to);
    tower(n-1,aux,from,to);
}
