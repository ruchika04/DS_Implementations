#include <stdio.h>

void towers(int, char, char, char);
int main()
{
    int num;
    printf("Enter no. of disks : ");
    scanf("%d", &num);
    printf("moves involved in the Tower of Hanoi are :\n");
    towers(num, 'A', 'B', 'C');
    return 0;
}
void towers(int num, char source, char to, char aux)
{
    if (num == 1)
    {
        printf("\n Move disk 1 from peg %c to peg %c", source, to);
        return;
    }
    towers(num - 1, source, aux, to);
    printf("\n Move disk %d from peg %c to peg %c", num, source, to);
    towers(num - 1, aux, to, source);
}
