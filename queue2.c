#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int que[MAX];
int rear=-1,front=-1;
void insert();
void delet();
void display();

int main()
{
    int choice;
    while (1)
    {
        printf("\nMENU\n");
        printf("1:Insert\n2:Delete\n3:Display\n4:Quit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:insert();
                   break;

            case 2:delet();
                   break;

            case 3:display();
                   break;

            case 4:exit(1);
            default:printf("Wrong choice\n");
        }
    }
}

void insert()
{
    int q;
    if (rear==MAX-1)
        printf("Queue overflow\n");
    else
    {
        if (front==-1)
            front=0;
        printf("Insert element in queue:");
        scanf("%d",&q);

        rear=rear+1;
        que[rear]=q;
    }
}

void delet()
{
    if (front==-1||front>rear)
    {
        printf("Queue underflow\n");
        return;
    }
    else
    {
        printf("Deleted element is %d\n",que[front]);
        front=front+1;
    }

}

void display()
{
    int i;
    if (front==-1||front>rear)
        printf("Queue is empty\n");
    else
    {
        printf("Queue is :\n");
        for(i=front;i<=rear;i++)
            printf("%d ",que[i]);
        printf("\n");
    }
}
