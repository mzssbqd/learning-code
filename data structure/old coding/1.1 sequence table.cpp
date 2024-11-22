#include<iostream>
#include<time.h>
using namespace std;
typedef struct Vector
{
public:
	int size, count;//size:顺序表长度 count:顺序表所含元素
	int* data;//一个完整的存储区
}vector;
//1.顺序表的初始化操作
Vector* init_vector(int n)
{
	Vector* p = (Vector*)malloc(sizeof(Vector));
	p->size = n;
	p->count = 0;
	p->data = (int*)malloc(sizeof(int) * n);
	return p;
}

void clear(Vector* v)
{
	if (v == NULL) return;
	free(v->data);
	free(v);
	return;
}

//2.顺序表的插入操作
int expand(Vector* v)
{
	if (v == NULL)return 0;
	printf("expand from %d to %d",v->size,v->size*2);
	int* temp = (int*)realloc(v->data, sizeof(int) * v->size * 2);
	if (temp == NULL) return 0;
	v->data = temp;
	v->size *= 2;
	return 1;
}
int insert(Vector* v, int pos, int val)//v:传入顺序表 pos:在哪个地方插入 val:插入的数据
{
	if (pos < 0 || pos > v->count) return 0;
	if (v->size == v->count && !expand(v)) return 0;
	for (int i = v->count; i >= pos; i--)
	{
		v->data[i + 1] = v->data[i];
	}
	v->data[pos] = val;
	v->count++;
	return 1;
}

//3.顺序表的删除操作
int erase(Vector* v, int pos)
{
	if (pos < 0 || pos > v->count) return 0;
	for (int i = pos; i <= v->count; i++)
	{
		v->data[pos] = v->data[pos + 1];
	}
	v->count--;
	return 1;
}


//输出顺序表
void output_vector(Vector *v)
{
	int len = 0;
	for (int i = 0; i < v->size; i++)
	{
		len += printf("%3d", i);

	}
	printf("\n");
	for (int i = 0; i < len; i++)printf("-");
	printf("\n");
	for (int i = 0; i < v->count; i++)
	{
		printf("%3d", v->data[i]);
	}
	printf("\n\n\n");
	return;
}
int main()
{
	//测试顺序表
	srand(time(0));
	#define MAX_OP 20
	Vector* v = init_vector(2);

	for (int i = 0; i < MAX_OP; i++)
	{
		int op = rand() % 4, pos, val;
		switch (op)
		{
		case 0:
		case 1:
		case 2:
			pos = rand() % (v->count + 2);
			val = rand() % 100;
			printf("insert %d at %d to vector = %d \n", val, pos, insert(v, pos, val));
			break;
		case 3:
			pos = rand() % (v->count + 2);
			printf("erase item at %d in vector = %d\n", pos, erase(v, pos));
			break;
		}
		output_vector(v);
	}
	clear(v);
	return 0;
}