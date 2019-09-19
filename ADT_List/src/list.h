#pragma once
#ifndef LIST_H_
#define LIST_H_
#include<stdbool.h>
#define TSIZE 45
#include<stdio.h>

/*����һ�������ͷ�ļ������������������������������(ADT)�����ԺͲ���*/

/*�����������������*/
struct film {
	char title[TSIZE];
	int ratings;
};
typedef struct film Item;
typedef struct node {
	Item item;
	struct node *next;
}Node;
typedef Node * List;    //����һ��ָ��Node�ڵ��ָ��

/*������������(����)�Ĳ���*/

/*����:��ʼ��һ������
  ǰ��������ָ��ָ��һ������
  ���������������ʼ����Ϊ��*/

void InitializeList(List *);

/*������ȷ��һ�������Ƿ�Ϊ��
  ǰ�᣺ ָ��һ����ʼ������
  ��������������һ���߼�ֵ*/

bool ListisEmpty(List *);

/*������ȷ��һ�������Ƿ�����
  ǰ�᣺ָ��һ����ʼ������
  ���ã�����һ���߼�ֵ*/

bool ListisFull(List *);

/*������ȷ�������е�����
  ǰ�᣺ָ��һ����ʼ������
  ���ã�����һ����������ֵ*/

unsigned int ListItemCount(const List *);

/*������ĩβ�����*/

bool AddItem(Item, List *);//�����β�ʹ��Item ����ʹ��Node

/*�������� ���������е���
 ǰ�᣺pfunΪһ������������һ��Item���Ͳ������޷���ֵ
 ���ã�pfun����������ÿһ����һ��*/

void Traverse(const List *, void(*)(Item));

/*�ͷ������ѷ�����ڴ�
  ǰ�᣺ָ���ʼ����ָ��
  ���ã�������Ϊ��*/

void Release(List *);


#endif


