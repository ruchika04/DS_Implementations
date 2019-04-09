//insert at end, delete the data, search , traverse beg, traverse end,sort
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{

    int data;
    struct node *prev;
    struct node *next;
}node;
node *start=NULL;
node *get_node()
{
    node *temp=(node*)malloc(sizeof(node));
    temp->prev=NULL;
    temp->next=NULL;
}
void traverse_beg()
{

    printf("\n Traversing from Beginning - \n");
    node *temp=start;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
void traverse_end()
{

    printf("\n Traversing from End - \n");
    node *temp=start;
    while(temp->next!=NULL&&temp!=NULL)
        temp=temp->next;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->prev;
    }
}
void insert_at_end()
{
    node *new_node= get_node();
   printf("\n Enter data : ");
   scanf("%d",&new_node->data);
   if(start==NULL)
   {
       start=new_node;
   }
   else
   {
       node *temp= start;
       while(temp->next!=NULL)
       {
           temp=temp->next;
       }
       temp->next=new_node;
       new_node->prev=temp;
   }
   printf("\n Node Inserted !!");


}
int search_data(int data)
{
    node *temp=start;
    int c=-1;
    while(temp!=NULL)
    {
        if(temp->data==data)
        {
            c++;
            return c;
        }
        c++;
        temp=temp->next;
    }
    if(temp==NULL)
    return -1;

}
void delete_data()
{
    int d;
    printf("\n Enter Data to be deleted : ");
    scanf("%d",&d);
    if(search_data(d)!=-1)
    {
         node *temp=start;
         while(temp->data!=d)
         {
             temp=temp->next;
         }
         if(temp->next==NULL&&temp->prev==NULL)
         {
             printf("\n Last node deleted %d ",temp->data);
             start=NULL;
             free(temp);

         }
         else
            if(temp->prev==NULL&&temp->next!=NULL)
         {
               printf("\n  node deleted %d ",temp->data);
             start=temp->next;
             start->prev=NULL;
             free(temp);

         }
         else
            if(temp->next==NULL)
         {   printf("\n  node deleted %d ",temp->data);
             temp->prev->next=NULL;
             free(temp);
         }
         else
         {

          printf("\n  node deleted %d ",temp->data);
         node *temp2=temp->next;
         temp2->prev=temp->prev;
         temp->prev->next=temp2;
         free(temp);
         }
    }
    else
    {

        printf("\n Data Not Found !!!");
    }
}
void sort_list()
{
    struct node *temp,*temp2;
    temp=start;
    temp2=start;
    while(temp!=NULL)
    {
        while(temp2->next!=NULL)
        {

            if(temp2->data>temp2->next->data)
            {
                int d= temp2->data;
                temp2->data= temp2->next->data;
                temp2->next->data= d;

            }
            temp2= temp2->next;
        }
        temp= temp->next;
        temp2=start;
    }
    printf("\n List Sorted !!!");
}
int main()
{
    int c;
    while(1)
    {


    printf("\n Doubly Linked List ");
    printf("\n 1. Insert \n 2. Delete \n 3. Traverse Beg \n 4. Traverse End \n 5. Sort \n 6. Search \n 7.Exit");
    printf("\n Enter Your Choice : ");
    scanf("%d",&c);
    switch(c)
    {
        case 1:insert_at_end(); break;
        case 2: delete_data();break;
        case 3: traverse_beg();break;
        case 4:traverse_end();break;
        case 5:sort_list();break;
        case 6:
     {

                int d; printf("\n Enter Data to be searched :");scanf("%d",&d);
                int c=search_data(d);
                if(c==-1)
                    printf("\n Data Not Found !!");
                else
                    printf("\n Data Found at Position =   %d",c);
        break;
     }
        case 7:exit(0);break;
    }
    }
}
