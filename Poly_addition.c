 //polynomial Addition
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
node *first_list=NULL;
node *second_list=NULL;
node *sum_list=NULL;
node  * insert_at_end(node *start,int data)
{

    node *new_node = (node*)malloc(sizeof(node));
    new_node->next=NULL;
    new_node->data=data;
    if(start==NULL)
    {
       start= new_node;
    }
    else
    {
        struct node *temp= start;
        while(temp->next!=NULL)
        {

            temp=temp->next;
        }
        temp->next=new_node;
    }
 return start;
}
void display(node *start)
{
    node *temp=start;
    int c;
    c=0;
    printf("\n");
    while(temp!=NULL)
    {
       if(temp->data!=0)
       {
           printf(" %dx^%d +",temp->data,c);

       }


       c++;
       temp=temp->next;
    }

}
int main()
{
    int pow1,pow2;
    printf("\n Enter highest power of first poly :");
    scanf("%d",&pow1);
    printf("\n Enter highest power of second poly :");
    scanf("%d",&pow2);
    int max_pow;
    if(pow1>pow2)
        max_pow=pow1;
    else
        max_pow= pow2;
    int i;
    int cof1,cof2;
    for(i=0;i<=max_pow;i++)
    {
        printf("\n Enter Coefficient of Power %d for first and second list : ",i);
        scanf("%d%d",&cof1,&cof2);
        first_list = insert_at_end(first_list,cof1);
        second_list= insert_at_end(second_list,cof2);

    }
   //sum
   node *temp1,*temp2;
   temp1= first_list;
   temp2= second_list;
   for(i=0;i<=max_pow;i++)
   {
       int d;
       d= temp1->data+ temp2->data;
       sum_list=insert_at_end(sum_list,d);
       temp1=temp1->next;
       temp2= temp2->next;
   }
   printf("\n Displaying Coefficients of first List :");
   display(first_list);
   printf("\n Displaying Coefficients of second List :");
   display(second_list);
   printf("\n Displaying Coefficients of final List :");

   display(sum_list);

}
