#include<stdio.h>
#include<stdlib.h>
#include <string.h> //strcmp();

//定义常量，便于辨别执行相应功能
#define INSERT 1
#define QUERY 2
#define UPDATE 3
#define DELETE 4
#define QUIT 5

//同学的信息结构体
typedef struct
{
	char name[20];
	char sex[10];
	char address[50];
	char phone[20];
	//工作单位
	char workfor[20];
}TX;

//记录同学录的数组，最多100个人
TX txl[100];

//现如今同学录中的人数
int last=0;
void showMenu();
void doChoice(int);
int getChoice();
void doInsert();
int find(char[]);
void doQuery();
void doUpdate();
void doDelete();
void doQuit();



int main(int argc, char *argv[])
{
	//定义选择
	int choice;
	
	while(1)
	{
		//1.显示菜单功能
		showMenu();
		
		//2.获取用户选择
		choice=getChoice();
		
        //3.根据选择执行相应的功能
        doChoice(choice);

        //暂停,让用户看清楚,按任意键结束
        printf("\n按任意键结束");
        system("pause>nul");
	}
	return 0;
}

void showMenu()
{
	//调用DOS命令cls清屏
	system("cls");
	
	printf("************************同学通讯录信息管理系统*************************\n");
	printf("\t\t\t1.添加同学信息\n");
	printf("\t\t\t2.查找同学信息\n");
	printf("\t\t\t3.修改同学信息\n");
	printf("\t\t\t4.删除同学信息\n");
	printf("\t\t\t5.退出系统\n");
	printf("***********************************************************************\n");
	printf("请输入你的选择(1-4):");
}

int getChoice()
{
	int ch;
	scanf("%d",&ch);
	return ch;
}

void doChoice(int choice)
{
	switch(choice)
	{
		case INSERT:
			doInsert();
			break;
		case QUERY:
			doQuery();
			break;
		case UPDATE:
			doUpdate();
			break;
		case DELETE:
			doDelete();
			break;
		case QUIT:
			doQuit();
	}
}


void doInsert()
{
	printf("请输入同学信息：\n");
	printf("姓名:");
	scanf("%s",&txl[last].name);
	printf("性别:");
	scanf("%s",&txl[last].sex);
	printf("地址:");
	scanf("%s",&txl[last].address);
	printf("电话:");
	scanf("%s",&txl[last].phone);
	printf("工作:");
	scanf("%s",&txl[last].workfor);
	last++;
	printf("同学录中有%d个人\n",last);

}

void doQuery()
{
	char n[20];
	printf("请输入要查找的名字：");
	scanf("%s",&n);
	
	find(n);
	
}

void doUpdate()
{
	char n[20];
	int i;
	printf("请输入要修改的人的名字：");
	scanf("%s",&n);
	i=find(n);
	
	printf("\n请输入修改后的信息：\n");
	printf("姓名:");
	scanf("%s",&txl[i].name);
	printf("性别:");
	scanf("%s",&txl[i].sex);
	printf("地址:");
	scanf("%s",&txl[i].address);
	printf("电话:");
	scanf("%s",&txl[i].phone);
	printf("工作:");
	scanf("%s",&txl[i].workfor);

	printf("\n修改后的信息如下：\n");
	printf("姓名:%s\n",txl[i].name);
	printf("性别:%s\n",txl[i].sex);
	printf("地址:%s\n",txl[i].address);
	printf("电话:%s\n",txl[i].phone);
	printf("工作:%s\n",txl[i].workfor);
}



void doDelete()
{
	char n[20];
	int i;
	printf("请输入要删除的人的名字：");
	scanf("%s",&n);
	i=find(n);
	
	for(int j=i;j<last;j++)
	{
		strcpy(txl[j].name,txl[j+1].name);
		strcpy(txl[j].sex,txl[j+1].sex);
		strcpy(txl[j].phone,txl[j+1].phone);
		strcpy(txl[j].address,txl[j+1].address);
		strcpy(txl[j].workfor,txl[j+1].workfor);
	}
	printf("删除成功！");
}

int find(char n[])
{
	int i=0;
	for(;i<last;i++)
	if(strcmp(txl[i].name,n)==0)break;

	if(i==last)
	{
		printf("抱歉，这位同学不存在！");
		return 0;
 	}

 	printf("信息如下：\n");
	printf("姓名:%s\n",txl[i].name);
	printf("性别:%s\n",txl[i].sex);
	printf("地址:%s\n",txl[i].address);
	printf("电话:%s\n",txl[i].phone);
	printf("工作:%s\n",txl[i].workfor);

	return i;
}


void doQuit()
{
 	printf("欢迎下次使用本系统！");
 	exit(0);
}













	
