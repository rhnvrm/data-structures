#include<stdio.h>
#include<string.h>
enum{False,True};
#define add 1
#define sub 1
#define mul 2
#define div 2
#define exp 3
int top =0;
void push(char[],char);
char pop(char[]);
int stack_empty();
int main()
{
	char s[100];
	void i2p(char[]);
	printf("Enter the Infix expression: ");
	scanf("%s",s);
	printf("nThe Postfix expression is: ");
	i2p(s);
	return 0;
}
int get_type(char symbol)
{
	switch(symbol)
	{
		case '(':
			return 1;
		case ')':
			return 2;
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
			return 4;
		default:
			return 3;
	}
}

int get_precedence(char symbol)
{
	switch(symbol)
	{
		case '+':
			return add;
		case '-':
			return sub;
		case '*':
			return mul;
		case'/':
			return div;
		case'^':
			return exp;
		case '(':
			return 0;
		default:
			return -1;
	}
}

void i2p(char infix[])
{

	int i=0,p=0,len,type,prec;
	char next,stack[20],postfix[20];
	int get_type(char);
	int get_precedence(char);
	len=strlen(infix);

	while(i<len)
	{
		type=get_type(infix[i]);
		switch(type)
		{
			case 1:
				push(stack,infix[i]);
				break;
			case 2:
				while((next=pop(stack))!='(')
					postfix[p++]=next;
				break;
			case 3:
				postfix[p++]=infix[i];
				break;
			case 4:
				prec=get_precedence(infix[i]); 
				while(stack_empty()==False)
				{
					if(prec<=get_precedence(stack[top-1]))
						postfix[p++]=pop(stack);
					else
						break;
				}
				push(stack,infix[i]);
				break;
		}
		i++;
	}
	while(stack_empty()==False)
		postfix[p++]=pop(stack);
	postfix[p]='\0';
	printf("%s\n",postfix);
}

void push(char stack[],char data)
{
	stack[top]=data;
	top++;
} 

char pop(char stack[])
{
	char data;
	top--;
	data=stack[top];
	return data;
}

int stack_empty()
{
	if(top==0)
		return True;
	else
		return False;
}
