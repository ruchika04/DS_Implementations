#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,j,a[3][3];
    printf("enter the elements of the matrix\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("\n Row Major Order\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",a[i][j]);

        }
         printf("\n");

    }
    printf("\n Column Major Order\n");
    for(j=0;j<3;j++)
    {
        for(i=0;i<3;i++)
        {
            printf("%d ",a[i][j]);

        }
        printf("\n");
    }
    return 0;

}
