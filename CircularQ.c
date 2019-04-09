#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 5
int circular_queue[MAX]; // defining the queue
int front=-1;
int rear=-1;
void enqueue(void); //function declaration
void dequeue(void);
void display(void);
void enqueue()      //function definition
{
    int data;
    printf("\n Enter your Data :");
    scanf("%d",&data);
    if((rear+1)%MAX==front)
   {

       printf("\n Queue Full !!");
   }
   else
   {

       if(front==-1)
       {

           front=0;
           rear=0;
           circular_queue[rear]=data;
       }
       else if(rear==MAX-1)
       {

           rear=0;
           circular_queue[rear]=data;
       }
       else
       {

           rear++;
           circular_queue[rear]=data;
       }
   }

}
void dequeue()
{
   int data;
    if(front==-1)
    {

        printf("\n Queue Empty");

    }
    else
    {


        data= circular_queue[front];
        if(front==rear)
        {

            front=-1;
            rear=-1;
        }
        else if(front==MAX-1)
        {
            front=0;
        }
        else
        {
            front++;
        }
        printf("\n %d is deleted !!",data);
    }

}
void display()
{

    if(front==-1)
    {
        printf("\n Queue Empty !!");
    }
    else{

        if(front>rear)
        {
            int i;
            for(i=front;i<MAX;i++)
            {
               printf("\n%d",circular_queue[i]);
            }
            front=0;
            for(i=front;i<=rear;i++)
             {
               printf("\n%d",circular_queue[i]);
            }

        }
        else{
            int  i;
            for(i=front;i<=rear;i++)
            {
                printf("\n%d",circular_queue[i]);
            }

        }
    }
}
int main()
{
    char ch='y';
    int choice;
    do
    {
        printf("\nQueue Operations :");
        printf("\n 1. EnQueue \n 2. DeQueue \n 3. Display \n 4 . Exit ");
        printf("\n Enter Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4:exit(0); break;
        }
        getchar();
        printf("\n Want to Do more ? : (y/n) ");

        scanf("%c",&ch);

    }while(ch=='y');
}
