#define _CRT_SECURE_NO_WARNINGS 1
//实现函数的功能
#include"Contact.h"

void InitContact(struct Contact *ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;//设置通讯录最初只有0个元素
}
void AddContact(struct Contact* ps)
{
	if (ps->size == MAX)
	{
		printf("通讯录已满，无法添加\n");
	}
	else
	{
		printf("请输入名字:");
		scanf("%s", ps->data[ps->size].name);
		printf("请输入年龄:");
		scanf("%d", &(ps->data[ps->size].age));
		printf("请输入性别:");
		scanf("%s", ps->data[ps->size].sex);
		printf("请输入电话:");
		scanf("%s", ps->data[ps->size].tele);
		printf("请输入地址:");
		scanf("%s", ps->data[ps->size].addr);

		ps->size++;
		printf("添加成功\n");
	}
}

void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
		for (; i < ps->size; i++)
		{
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
}

static int Find_By_Name(struct Contact* ps, char* name)
{
	int i = 0;
	for (; i < ps->size; i++)
    {
		if (0 == strcmp(ps->data[i].name, name))
		{
			return i;
		 }
    }
	return -1;
}
void DelContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请选择要删除人的名片:>");
	scanf("%s", name);
	//查找要删除的人在什么位置
	int pos = Find_By_Name(ps, name);
	if (pos==-1)
	{
		printf("不存在此用户\n");
	}
	//2.删除
	else
	{
		int j = 0;
		for (j=pos; j < ps->size-1; j ++ )
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("删除成功\n");
	}
	
}

void SearchContact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要查找人的名字:");
	scanf("%s", name);
	int pos = Find_By_Name(ps, name);
	if (pos == -1)
	{
		printf("此用户不存在\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				ps->data[pos].name,
				ps->data[pos].age,
				ps->data[pos].sex,
				ps->data[pos].tele,
				ps->data[pos].addr);
	}
}

void MidfiyContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要修改人的名字:");
	scanf("%s", name);
	int pos = Find_By_Name(ps, name);
	if (pos == -1)
	{
		printf("此用户不存在\n");
	}
	else
	{
		printf("请输入名字:");
		scanf("%s", ps->data[pos].name);
		printf("请输入年龄:");
		scanf("%d", &(ps->data[pos].age));
		printf("请输入性别:");
		scanf("%s", ps->data[pos].sex);
		printf("请输入电话:");
		scanf("%s", ps->data[pos].tele);
		printf("请输入地址:");
		scanf("%s", ps->data[pos].addr);

		printf("修改完成\n");
	}
}

void SortContact(struct Contact* ps)
{

}