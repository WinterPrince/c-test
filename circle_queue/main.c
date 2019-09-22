#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#define MAXSIZE 1000
typedef struct {
	int front;
	int rear;
	int queue_size;
	int Queue[MAXSIZE];  //int * Queue;
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k)
{
	MyCircularQueue queue;
	//queue.Queue = (int *)malloc(k * sizeof(int));
	printf("����ɹ�");
	if (queue.Queue==NULL)
		exit(EXIT_FAILURE);
	queue.front = queue.rear = 0;    //��ʼ��ͷָ���βָ���Ϊ0��
	queue.queue_size = k;
	//printf("front=%d", queue.rear);
	return &queue;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
	int insert_index = (obj->rear + 1) % (obj->queue_size);  /*��һ����λ������������������front��rear���1.����һ�ַ�����ʹ�ñ�־λflag,flagΪ1��
     ��rear=front��Ϊ����flagΪ0����rear=front��Ϊ�գ���֮���*/
	if (insert_index == obj->front)   //���rear��front�м����һ��λ��
		return false;
	//printf("obj->Queue[obj->rear]=%d", obj->rear);
	obj->Queue[obj->rear] = value;  //��ֵ
	obj->rear = insert_index;  //rear������һ��λ��
	return true;

}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
	if (obj->front == obj->rear)   //front��rear�غϱ��������ѿ�
		return false;

	int delete_value = obj->Queue[obj->front];
	obj->front = (obj->front + 1) % (obj->queue_size);   //front ����һ��λ��
	return true;

}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj)
{
	return obj->Queue[obj->front];


}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj)
{
	return obj->Queue[((obj->rear - 1) + obj->queue_size) % obj->queue_size]; //ȡ��ѭ�����е����һ��Ԫ�أ�Ϊ��ֹrear==0ʱrear-1Խ�磬
	//����϶��г��Ȳ�ȡ��                   

}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
	if (obj->front == obj->rear)   //front��rear�غϱ��������ѿ�
		return true;
	return false;

}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj)
{
	int insert_index = (obj->rear + 1) % (obj->queue_size);  //��һ����λ������������������front��rear���1.

	if (insert_index == obj->front)   //���rear��front�м����һ��λ��
		return true;
	return false;

}

void myCircularQueueFree(MyCircularQueue* obj)
{
	free(obj->Queue);
}

int main(void)
{


	MyCircularQueue* obj = myCircularQueueCreate(10);
	bool param_1 = myCircularQueueEnQueue(obj, 1);
	bool param_11 = myCircularQueueEnQueue(obj, 2);
	bool param_12 = myCircularQueueEnQueue(obj, 3);

	bool param_2 = myCircularQueueDeQueue(obj);

	int param_3 = myCircularQueueFront(obj);

	int param_4 = myCircularQueueRear(obj);

	bool param_5 = myCircularQueueIsEmpty(obj);

	bool param_6 = myCircularQueueIsFull(obj);
	printf("p1=%d,p2=%d,p3=%d,p4=%d,p5=%d", param_1, param_11, param_12, param_2, param_3);
	myCircularQueueFree(obj);
	return 0;
}