#include "list.h"
#define SMAX 45
#include <stdlib.h>
#include<string.h>
//利用接口List来编程


/*使用接口来编写程序*/
char *s_gets(char *, int);  //输入函数声明
void showmovies(Item);
int main(void)
{
	List movies;     
	Item temp;

	InitializeList(&movies);  //初始化一个链表
	
	if (ListisFull(&movies))
	{
		fprintf(stderr, "没有可用空间,再见");
		exit(EXIT_FAILURE);
	}
	puts("请输入一个电影名称");
	while (s_gets(temp.title,SMAX) && temp.title[0] != '\0')
	{
		puts("请输入你对这个电影的评分,范围为0-10");
		while (scanf("%u", &temp.ratings) != 1)
		{
			puts("您的输入有误，请重新输入");
			while (getchar() != '\n')
				continue;
		}
		while (temp.ratings > 10)
		{
			puts("您输入的范围有误，请输入一个0-10之间的整数");
			while (scanf("%u", &temp.ratings) != 1)
			{
				puts("您的输入有误，请重新输入");
				while (getchar() != '\n')
					continue;
			}
		}
		while (getchar() != '\n')    //清空缓冲区中因输入整数后按下的Enter键形成的换行符 防止对s_gets函数造成影响
			continue;
		if (ListisFull(&movies))
		{
			puts("链表已经满了");
			break;
		}
		if (AddItem(temp, &movies) == false)
		{
			puts("在末尾添加项失败");
			break;
		}
		puts("请输入下一个电影名称，空行代表放弃");
	}

	/*显示链表*/
	if (ListisEmpty(&movies))
	{
		fprintf(stderr, "链表为空，无法显示");
	}
	else
	{
		Traverse(&movies, showmovies);
	}
	printf("你已经输入了%d项电影\n", ListItemCount(&movies));

	/*清空链表，释放内存*/
	Release(&movies);
	puts("再见");

	getchar();
	getchar();
	return 0;
}



void showmovies(Item item)
{
	printf("电影名:%s 评分:%u\n", item.title, item.ratings);
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
