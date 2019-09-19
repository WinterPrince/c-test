#include "list.h"
#include <stdlib.h>
#include <string.h>

/*接口操作函数的定义(接口的实现)*/
void InitializeList(List *p)  //初始化链表函数
{
	*p = NULL;
}
bool ListisEmpty(List *p) //链表是否为空
{
	if (*p)
	{
		return false;
	}
	else
		return true;
}

bool ListisFull(List *p)  //链表是否已满
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

unsigned int ListItemCount( const List *p)   //定义链表的项数
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
	strcpy(add->item.title, item.title);   //复制电影名称
	add->item.ratings = item.ratings;  //复制评分
	add->next = NULL;
	if (!current)
		*p = add;
	else
	{
		while (current)   //确定位置
		{
			pre = current;
			current = current->next;
		}
		pre->next = add;
	}
	return true;
}

void Traverse(const List *p, void(*pfun)(Item item))  //遍历链表，并将pfun函数作用于每一个项上
{
	Node *current = *p;
    
	while (current)
	{
		(*pfun)(current->item);
		current = current->next;
	}
}

void Release(List *p)   //释放链表
{
	Node *pt;

	while (*p)
	{
		pt = (*p)->next;
		free(*p);
		*p = pt;
	}
}