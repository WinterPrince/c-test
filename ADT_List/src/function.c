#include "list.h"
#include <stdlib.h>
#include <string.h>

/*�ӿڲ��������Ķ���(�ӿڵ�ʵ��)*/
void InitializeList(List *p)  //��ʼ��������
{
	*p = NULL;
}
bool ListisEmpty(List *p) //�����Ƿ�Ϊ��
{
	if (*p)
	{
		return false;
	}
	else
		return true;
}

bool ListisFull(List *p)  //�����Ƿ�����
{
	Node *pt;
	bool full;

	pt = (Node *)malloc(sizeof(Node) * 1);
	if (pt)
	{
		full = false;
	}
	else
		full = true;

	free(pt);
	return full;
}

unsigned int ListItemCount( const List *p)   //�������������
{
	Node *pt = *p;
	unsigned int count = 0;

	while (pt)
	{
		count++;
		pt = pt->next;
	}

	return count;
}

bool AddItem(Item item, List *p)
{
	Node *pre = *p;
	Node *current = *p;
	Node *add = (Node *)malloc(sizeof(Node) * 1);

	if (!add)
	{
		return false;
	}
	strcpy(add->item.title, item.title);   //���Ƶ�Ӱ����
	add->item.ratings = item.ratings;  //��������
	add->next = NULL;
	if (!current)
		*p = add;
	else
	{
		while (current)   //ȷ��λ��
		{
			pre = current;
			current = current->next;
		}
		pre->next = add;
	}
	return true;
}

void Traverse(const List *p, void(*pfun)(Item item))  //������������pfun����������ÿһ������
{
	Node *current = *p;
    
	while (current)
	{
		(*pfun)(current->item);
		current = current->next;
	}
}

void Release(List *p)   //�ͷ�����
{
	Node *pt;

	while (*p)
	{
		pt = (*p)->next;
		free(*p);
		*p = pt;
	}
}