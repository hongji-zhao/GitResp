#include "main.h"

void InsertNode(struct Node **head, int value)
{
	struct Node *previous;
	struct Node *current;
	struct Node *new;

	current = *head;
	previous = NULL;
	while (current != NULL && current->value < value)
	{
		previous = current;
		current = current->next;
	}
	new = (struct Node *)malloc(sizeof(struct Node));
	if (new == NULL)
	{
		printf("内存分配失败!\n");
		exit(1);
	}

	new->value = value;
	new->next = current;

	if (previous == NULL)
	{
		*head = new;	
	}
	else
	{
		previous->next = new;
	}
}

void PrintfNode(struct Node *head)
{
	struct Node *current;

	current = head;
	while (current != NULL)
	{
		printf("%d ", current->value);
		current = current->next;
	}
	putchar('\n');
	
}

void DelateNode(struct Node **head, int value)
{
	struct Node *previous;
	struct Node *current;

	previous = NULL;
	current = *head;

	while (current != NULL && current->value != value)
	{
		previous = current;
		current = current->next;/* code */
	}
	if (current == NULL)
	{
		printf("找不到要删除的节点\n");
		return;
	}
	else
	{
		if (previous == NULL)
		{
			*head = current->next;
		}
		else
		{
			previous->next = current->next;
		}
		free(current);
	}
}
int main(void)
{
	struct Node *head = NULL;
	int input;
	while (1)
	{
		printf("请输入一个整数(输入-1表示结束)");
		scanf("%d", &input);
		if (input == -1)
		{
			break;
		}
		InsertNode(&head, input);
		PrintfNode(head);
	}

	while (1)
	{
		printf("请输入一个要删除的整数(输入-1表示结束)");
		scanf("%d", &input);
		if (input == -1)
		{
			break;
		}
		DelateNode(&head, input);
		PrintfNode(head);
	}
		
	printf("\n");
    system("pause");
    return 0;
}
