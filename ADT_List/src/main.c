#include "list.h"
#define SMAX 45
#include <stdlib.h>
#include<string.h>
//���ýӿ�List�����


/*ʹ�ýӿ�����д����*/
char *s_gets(char *, int);  //���뺯������
void showmovies(Item);
int main(void)
{
	List movies;     
	Item temp;

	InitializeList(&movies);  //��ʼ��һ������
	
	if (ListisFull(&movies))
	{
		fprintf(stderr, "û�п��ÿռ�,�ټ�");
		exit(EXIT_FAILURE);
	}
	puts("������һ����Ӱ����");
	while (s_gets(temp.title,SMAX) && temp.title[0] != '\0')
	{
		puts("��������������Ӱ������,��ΧΪ0-10");
		while (scanf("%u", &temp.ratings) != 1)
		{
			puts("����������������������");
			while (getchar() != '\n')
				continue;
		}
		while (temp.ratings > 10)
		{
			puts("������ķ�Χ����������һ��0-10֮�������");
			while (scanf("%u", &temp.ratings) != 1)
			{
				puts("����������������������");
				while (getchar() != '\n')
					continue;
			}
		}
		while (getchar() != '\n')    //��ջ��������������������µ�Enter���γɵĻ��з� ��ֹ��s_gets�������Ӱ��
			continue;
		if (ListisFull(&movies))
		{
			puts("�����Ѿ�����");
			break;
		}
		if (AddItem(temp, &movies) == false)
		{
			puts("��ĩβ�����ʧ��");
			break;
		}
		puts("��������һ����Ӱ���ƣ����д������");
	}

	/*��ʾ����*/
	if (ListisEmpty(&movies))
	{
		fprintf(stderr, "����Ϊ�գ��޷���ʾ");
	}
	else
	{
		Traverse(&movies, showmovies);
	}
	printf("���Ѿ�������%d���Ӱ\n", ListItemCount(&movies));

	/*��������ͷ��ڴ�*/
	Release(&movies);
	puts("�ټ�");

	getchar();
	getchar();
	return 0;
}



void showmovies(Item item)
{
	printf("��Ӱ��:%s ����:%u\n", item.title, item.ratings);
}

char *s_gets(char *st, int n)
{
	char * ch;
	int i = 0;

	ch = fgets(st, n, stdin);
	if (ch)
	{
		while (st[i] != '\0'&&st[i] != '\n')
			i++;
		if (st[i] == '\n')
			st[i] = '\0';
		else
		{
			while (getchar() != '\n')
				continue;
		}
	}

	return ch;
}
