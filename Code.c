#include<stdio.h>
#include<string.h>
char stack[200];
int top = -1;
void push(char a)
{
stack[++top] = a;
}
char pop()
{
if(top == -1)
return -1;
else
return stack[top--];
}
int priority(char b)
{
if(b == '(')
return 0;
if(b == '+' || b == '-')
return 1;
if(b == '*' || b == '/')
return 2;
return 0;
}
int main()
{
char exp[100];
char *c, d;
printf("PROGRAM TO CHANGE INFIX EXPRESSION TO POSTFIX EXPRESSION \n");
printf("Enter THE INFIX EXPRESSION = ");
scanf("%s",exp);
printf("THE POSTFIX EXPRESSION = ");
c = exp;
while(*c != '\0')
{
if(isalnum(*c))
printf("%c ",*c);
else if(*c == '(')
push(*c);
else if(*c == ')')
{
while((d = pop()) != '(')
printf("%c ", d);
}
else
{
while(priority(stack[top]) >= priority(*c))
printf("%c ",pop());
push(*c);
}
c++;
}
while(top != -1)
{
printf("%c ",pop());
}return 0;
}
