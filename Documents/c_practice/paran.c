#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	char data;
	struct node * next;
}link;

link * head;

void push(char c)
{
	link * temp = malloc(sizeof(link));
	temp->data = c;
	temp->next = head;
	head  = temp;
}

void pop()
{
	if(head == NULL)return;
	link * temp = head;
	head = temp->next;
	free(temp);
}

void print()
{
	link * temp = head;
	if(temp == NULL)return;
	while(temp != NULL)
	{
		printf("%c", temp->data);
		temp = temp->next;
	}
}

char top()
{
	char val = head->data;
	return val;
}

int main()
{
	head = NULL;
	char c = 'a';
	int flag = 0;
	while(c != '!')
	{
		scanf("%c", &c);
		if(c == 91 || c == 123 || c == 40)
		{
			push(c);
		}
		else if(head != NULL)
		{
			if(c == ']' && head->data == '[')
			{ 
				pop();
			}
			else if(c == '}' && head->data == '{')
			{	
				pop();
			}
			else if(c == ')' && head->data == '(')
			{	
				pop();			
			}
		}
		else if(head == NULL && (c == 93 || c == 125 || c == 41))
		{
			flag = 1;
		}
	}
	print();
	printf("\n");
	if(head == NULL && flag == 0)
	{
		printf("Balanced!\n");
	}
	else
	{
		printf("Unbalaned :(\n");
	}
}