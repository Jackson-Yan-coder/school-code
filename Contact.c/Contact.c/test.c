#define _CRT_SECURE_NO_WARNINGS 1
///����

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
	//����ͨѶ¼
	struct Contact con;//���1000���˵���Ϣ
	//��ʼ��ͨѶ¼
	InitContact(&con);

	int input = 0;
	do
	{
		menu();
		printf("��ѡ��\n");
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
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while(input);
	return 0;
}