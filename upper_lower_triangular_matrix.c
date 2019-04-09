#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,j,max1,max2,m[3][3],n[3][3];
    printf("\n Enter upper triangular matrix :\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(j>=i)
            {
                printf("\n Enter the element a[%d][%d] : ",i,j);
                scanf("%d",&m[i][j]);
            }
            else{
                m[i][j]=0;
            }
        }
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",m[i][j]);

        }
        printf("\n");
    }
    printf("\n Enter lower triangular matrix : \n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(i>=j)
            {
                printf("Enter the element a[%d][%d] : ",i,j);
                scanf("%d",&n[i][j]);
            }
            else{
                n[i][j]=0;
            }
        }
    }
     for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",n[i][j]);

        }
        printf("\n");
    }
     for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {   if(m[i][j]>max1)
                max1=m[i][j];
            if(n[i][j]>max2)
                max2=n[i][j];
        }
    }
}
