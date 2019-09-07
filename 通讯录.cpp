#include<stdio.h>
#include<stdlib.h>
#include <string.h> //strcmp();

//���峣�������ڱ��ִ����Ӧ����
#define INSERT 1
#define QUERY 2
#define UPDATE 3
#define DELETE 4
#define QUIT 5

//ͬѧ����Ϣ�ṹ��
typedef struct
{
	char name[20];
	char sex[10];
	char address[50];
	char phone[20];
	//������λ
	char workfor[20];
}TX;

//��¼ͬѧ¼�����飬���100����
TX txl[100];

//�����ͬѧ¼�е�����
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
	//����ѡ��
	int choice;
	
	while(1)
	{
		//1.��ʾ�˵�����
		showMenu();
		
		//2.��ȡ�û�ѡ��
		choice=getChoice();
		
        //3.����ѡ��ִ����Ӧ�Ĺ���
        doChoice(choice);

        //��ͣ,���û������,�����������
        printf("\n�����������");
        system("pause>nul");
	}
	return 0;
}

void showMenu()
{
	//����DOS����cls����
	system("cls");
	
	printf("************************ͬѧͨѶ¼��Ϣ����ϵͳ*************************\n");
	printf("\t\t\t1.���ͬѧ��Ϣ\n");
	printf("\t\t\t2.����ͬѧ��Ϣ\n");
	printf("\t\t\t3.�޸�ͬѧ��Ϣ\n");
	printf("\t\t\t4.ɾ��ͬѧ��Ϣ\n");
	printf("\t\t\t5.�˳�ϵͳ\n");
	printf("***********************************************************************\n");
	printf("���������ѡ��(1-4):");
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
	printf("������ͬѧ��Ϣ��\n");
	printf("����:");
	scanf("%s",&txl[last].name);
	printf("�Ա�:");
	scanf("%s",&txl[last].sex);
	printf("��ַ:");
	scanf("%s",&txl[last].address);
	printf("�绰:");
	scanf("%s",&txl[last].phone);
	printf("����:");
	scanf("%s",&txl[last].workfor);
	last++;
	printf("ͬѧ¼����%d����\n",last);

}

void doQuery()
{
	char n[20];
	printf("������Ҫ���ҵ����֣�");
	scanf("%s",&n);
	
	find(n);
	
}

void doUpdate()
{
	char n[20];
	int i;
	printf("������Ҫ�޸ĵ��˵����֣�");
	scanf("%s",&n);
	i=find(n);
	
	printf("\n�������޸ĺ����Ϣ��\n");
	printf("����:");
	scanf("%s",&txl[i].name);
	printf("�Ա�:");
	scanf("%s",&txl[i].sex);
	printf("��ַ:");
	scanf("%s",&txl[i].address);
	printf("�绰:");
	scanf("%s",&txl[i].phone);
	printf("����:");
	scanf("%s",&txl[i].workfor);

	printf("\n�޸ĺ����Ϣ���£�\n");
	printf("����:%s\n",txl[i].name);
	printf("�Ա�:%s\n",txl[i].sex);
	printf("��ַ:%s\n",txl[i].address);
	printf("�绰:%s\n",txl[i].phone);
	printf("����:%s\n",txl[i].workfor);
}



void doDelete()
{
	char n[20];
	int i;
	printf("������Ҫɾ�����˵����֣�");
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
	printf("ɾ���ɹ���");
}

int find(char n[])
{
	int i=0;
	for(;i<last;i++)
	if(strcmp(txl[i].name,n)==0)break;

	if(i==last)
	{
		printf("��Ǹ����λͬѧ�����ڣ�");
		return 0;
 	}

 	printf("��Ϣ���£�\n");
	printf("����:%s\n",txl[i].name);
	printf("�Ա�:%s\n",txl[i].sex);
	printf("��ַ:%s\n",txl[i].address);
	printf("�绰:%s\n",txl[i].phone);
	printf("����:%s\n",txl[i].workfor);

	return i;
}


void doQuit()
{
 	printf("��ӭ�´�ʹ�ñ�ϵͳ��");
 	exit(0);
}













	
