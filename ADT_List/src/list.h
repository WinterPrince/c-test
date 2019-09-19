#pragma once
#ifndef LIST_H_
#define LIST_H_
#include<stdbool.h>
#define TSIZE 45
#include<stdio.h>

/*定义一个链表的头文件，用来涵盖链表这个抽象数据类型(ADT)的属性和操作*/

/*定义链表的数据属性*/
struct film {
	char title[TSIZE];
	int ratings;
};
typedef struct film Item;
typedef struct node {
	Item item;
	struct node *next;
}Node;
typedef Node * List;    //定义一个指向Node节点的指针

/*定义数据类型(链表)的操作*/

/*操作:初始化一个链表
  前提条件：指针指向一个链表
  后置条件：链表初始化后为空*/

void InitializeList(List *);

/*操作：确定一个链表是否为空
  前提： 指向一个初始化链表
  后置条件：返回一个逻辑值*/

bool ListisEmpty(List *);

/*操作：确定一个链表是否已满
  前提：指向一个初始化链表
  后置：返回一个逻辑值*/

bool ListisFull(List *);

/*操作：确定链表中的项数
  前提：指向一个初始化链表
  后置：返回一个整数类型值*/

unsigned int ListItemCount(const List *);

/*在链表末尾添加项*/

bool AddItem(Item, List *);//这里形参使用Item 而不使用Node

/*遍历链表 处理链表中的项
 前提：pfun为一个函数，接受一个Item类型参数，无返回值
 后置：pfun函数作用于每一个项一次*/

void Traverse(const List *, void(*)(Item));

/*释放链表已分配的内存
  前提：指向初始化的指针
  后置：链表置为空*/

void Release(List *);


#endif


