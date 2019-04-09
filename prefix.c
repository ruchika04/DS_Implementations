#include <stdio.h>
#include <stdlib.h>
#include<string.h>
char stack[20];
char prefix[20];
char news[20];
int top = -1;
void push(char x)
{
    stack[++top] = x;
}
char *reverse(char s[])
{
    int l=strlen(s);
    int i;

    int j;
    j=0;
    for(i=l-1;i>=0;i--)
    {
        if(s[i]=='(')
        {
            news[j++]=')';
        }
        else
            if(s[i]==')')
        {
            news[j++]='(';
        }
        else
        {


         news[j++]=s[i];
        }

    }
    news[j]='\0';
    printf("\n Reverse String : %s",news);
    return news;
}
char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 2;
    if(x == '*' || x == '/')
        return 1;
}

main()
{
    char exp[20];
    char *e, x;
    printf("Enter the expression :: \n");
    scanf("%s",&exp);
    e = reverse(exp);
    int prefix_c=0;
    while(*e != '\0')
    {
        if(isalnum(*e))
            prefix[prefix_c++]=*e;//printf("%c",*e);
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while((x = pop()) != '(')
                prefix[prefix_c++]=x;//printf("%c", x);
        }
        else
        {
            while(priority(stack[top]) >= priority(*e))
                prefix[prefix_c++]=pop();//printf("%c",pop());
            push(*e);
        }
        e++;
    }
    while(top != -1)
    {
        prefix[prefix_c++]=pop();//printf("%c",pop());
    }
    char *prefix_new;
    prefix_new=reverse(prefix);
    printf("\n Prefix =  %s",prefix_new);
}
