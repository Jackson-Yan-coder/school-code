#define _CRT_SECURE_NO_WARNINGS 1
///测试

#include"Contact.h"

void menu()
{
	printf("*******************************\n");
	printf("*** 1.add          2.del    ***\n");
	printf("*** 3.search       4.midfiy ***\n");
	printf("*** 5.show         6.sort   ***\n");
	printf("*** 0.exit                  ***\n");
	printf("*******************************\n");
}
int main()
{
	//创建通讯录
	struct Contact con;//存放1000个人的信息
	//初始化通讯录
	InitContact(&con);

	int input = 0;
	do
	{
		menu();
		printf("请选择：\n");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MIDFIY:
			MidfiyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case EXIT:
			printf("退出通讯录\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while(input);
	return 0;
}