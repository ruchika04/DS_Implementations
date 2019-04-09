
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
    struct node *next;
    int data;
};
struct node *start=NULL;

void insert_at_end()
{
    int data;
    printf("\n Enter the data you want to insert  : ");
    scanf("%d",&data);
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
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
    printf("\n Node inserted at end !!");
}
void insert_at_beg()
{
     int data;
    printf("\n Enter the data you want to insert  : ");
    scanf("%d",&data);
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->next=NULL;
    new_node->data=data;
    new_node->next=start;
    start=new_node;
        printf("\n Node inserted at beg !!");
}
void display()
{
    struct node *temp=start;
    while(temp!=NULL)
    {
        printf("\n %d",temp->data);
        temp= temp->next;
    }
}
int length_of_list()
{
    struct node* temp= start;
    int c;
    c=0;
    while(temp!=NULL)
    {
       c++;
       temp=temp->next;
    }
    return c;
}
void insert_at_position()
{
    int data;
    int pos; int p;
    printf(" \n Enter the data :");
    scanf("%d",&data);
    printf("\n Enter the position : ");
    scanf("%d",&pos);
    if(pos>length_of_list())
    {
        printf("\n Out of Bound !!");
        return;
    }
    p=pos;
     struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->next=NULL;
    new_node->data=data;
    struct node * temp;
    temp= start;
    pos--;
    while(pos>1 && temp!=NULL)
    {
        temp=temp->next;
        pos--;
    }
    new_node->next= temp->next;
    temp->next=new_node;
    printf("\n Data inserted at Pos %d",p);

}
void insert_before_given_data()
{
   int data;
    int val; int p;
    printf(" \n Enter the data :");
    scanf("%d",&data);
    printf("\n Enter the data before which you want to insert : ");
    scanf("%d",&val);
    p=val;
     struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->next=NULL;
    new_node->data=data;
    struct node * temp;
    struct node * preptr;
    temp= start;
    preptr=NULL;
    while(temp!=NULL)
    {
        if(temp->data==val)
        {
            break;
        }
        else{
                preptr=temp;
            temp=temp->next;

        }

    }
    if(temp!=NULL)
    {
        if(preptr==NULL)
        {
            new_node->next=temp;
            start=new_node;
        }
        else
        {

            new_node->next=temp;
            preptr->next=new_node;
        }
    }
    else{
        printf("\n Node not found with given data !!");
    }
    printf("\n Node inserted before %d ",val);
}
void insert_after_given_data()
{   int val,val2;
    printf("\nenter value to the node");
    scanf("%d",&val);
    printf("\nenter the data after which you want to insert : ");
    scanf("%d",&val2);
    struct node *new_node,*ptr;
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=val;
    ptr=start;
    while(ptr!=NULL)
    {
        if(ptr->data==val2)
        {
            break;
        }
        else
        {
            ptr=ptr->next;
        }


    }
    if(ptr!=NULL)
    {
      new_node->next= ptr->next;
      ptr->next=new_node;
    }
    else{
        printf("\n Node not found with given data !!");
    }
    printf("\n Node inserted after %d ",val2);

}
void delete_beg()
{
    if(start==NULL)
    {
        printf("\n List Empty !!!");
    }
    else
    {
        struct node *temp = start;
        start= start->next;
        printf("\n %d Node deleted from beginning !!",temp->data);
        free(temp);

    }

}
void delete_end()
{

    if(start==NULL)
    {
        printf("\n List Empty !");
    }
    else
    {

        struct node *temp= start;
        if(temp->next==NULL)
        {
            start=NULL;
            printf("\n %d Node deleted from end !!",temp->data);
            free(temp);
        }
        else
        {
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
           struct node *temp2= temp->next;
           temp->next= NULL;

           printf("\n %d Node delete from end !!",temp2->data);
           free(temp2);

        }
    }
}
void delete_data()
{
  if(start==NULL)
  {

      printf("\n List Empty !!");
  }
  else
  {
      int d;
      printf("\n Enter the data which you want to delete :");
      scanf("%d",&d);
      struct node *temp,*preptr;
      temp= start;
      preptr=NULL;
      while(temp->data!=d)
      {
          preptr=temp;
          temp=temp->next;
      }
      if(preptr==NULL)
      {
          start=start->next;
          printf("\n %d data is deleted !!",temp->data);
          free(temp);
      }
      else
      {
         preptr->next= temp->next;
         printf("\n %d data is deleted !!",temp->data);
          free(temp);
      }
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
        printf("\n \t *** Linked List Operations ***");
        printf("\n 1. Insert At Beg \n 2. Insert at End \n 3. Insert at position \n 4. Insert Before Given Data");
        printf("\n 5. Insert After given Data \n 6. Delete Beg \n 7. Delete End \n 8. Delete Data \n 9. Display \n 10. Sort List");
        printf("\n 11. Exit \n   Enter Your Choice : ");
        scanf("%d",&c);
        switch(c)
        {
            case 1: insert_at_beg(); break;
            case 2: insert_at_end(); break;
            case 3: insert_at_position(); break;
            case 4: insert_before_given_data(); break;
            case 5: insert_after_given_data(); break;
            case 6: delete_beg(); break;
            case 7: delete_end(); break;
            case 8: delete_data(); break;
            case 9: display(); break;
            case 10: sort_list(); break;
            case 11: exit(0); break;
        }

    }

}
