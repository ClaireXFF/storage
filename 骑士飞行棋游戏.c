/**
 * ��Ŀ���ƣ���ʿ��������Ϸ���ڶ��ε��������������Ϸ
 * �������ڣ�2011��5��16��
 * ��    �ߣ�BBC
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int map[100];                                         //��ս��ͼ
int luckyTurn[] = {6, 23, 40, 55, 69, 83};            // ��������
int landMine[] = {5, 13, 17, 33, 38, 50, 64, 80, 94}; // ����λ��
int pause[] = {9, 27, 60, 93};                        // ��ͣ
int timeTunnel[] = {20, 25, 45, 63, 72, 88, 90};      // ʱ�����
char graph[10]; 
int playerPos1; // ��ս�����1�ĵ�ǰλ��
int playerPos2; // ��ս�����2�ĵ�ǰλ��
char goAndStop[2][3];   // �߻�ͣ��ʶ����
char playerName[2][20];

      
/**
 * ���ɵ�ͼ: �ؿ�����Ϊ��1���������� 2������ 3: ��ͣ 4��ʱ����� 0����ͨ
 */
void createMap()
{
    int i = 0; 

    // �ڶ�ս��ͼ��������������
    for (i = 0; i < sizeof(luckyTurn) / sizeof(int); i++)
    {
        map[luckyTurn[i]] = 1; 
    }

    // �ڶ�ս��ͼ�����õ���
    for(i = 0; i < sizeof(landMine)/sizeof(int); i++){
        map[landMine[i]] = 2; 
    }

    // �ڶ�ս��ͼ��������ͣ
    for (i = 0; i < sizeof(pause) / sizeof(int); i++)
    {
        map[pause[i]] = 3; 
    }

    // �ڶ�ս��ͼ������ʱ�����
    for (i = 0; i < sizeof(timeTunnel) / sizeof(int); i++)
    {
        map[timeTunnel[i]] = 4; 
    }
}

/**
 * ��ʼ����Ϸ��һ��
 */
void init()
{   
    createMap();  // ���ɵ�ͼ
    playerPos1 = 0;   // �������1��ʼλ��
    playerPos2 = 0;   // �������2��ʼλ��
    strcpy(goAndStop[0], "on");  // ��¼���1��һ���߻�ͣ
    strcpy(goAndStop[1], "on");  // �������2��һ���߻�ͣ
}


/**
 * ��ʾ��ͼ�ؿ���Ӧ��ͼ��
 * ������� i ��ͼ��ǰλ�õĹؿ�����
 * ������� index ��ǰ��ͼλ�ñ��
 * ������� playerPos1 ���1�ĵ�ǰλ��
 * ������� playerPos2 ���2�ĵ�ǰλ��
 * ����ֵ ��ͼ��ǰλ�õĶ�ӦͼƬ
 */
char *getGraph(int i, int index, int playerPos1, int playerPos2)
{
    if (index == playerPos1 && index == playerPos2)
    {
        strcpy(graph, "@@");
    }
    else if (index == playerPos1)
    {    
        // graph = "��";
        strcpy(graph, "��");
    }
    else if (index == playerPos2)
    {
        // graph = "��";
        strcpy(graph, "��");
    }
    else
    {
        switch (i)
        {
            case 1:   // ��������
                strcpy(graph, "��");
                break;
            case 2:   // ����
                strcpy(graph, "��");
                break;
            case 3:   // ��ͣ
                strcpy(graph, "��");
                break;
            case 4:   // ʱ�����
                strcpy(graph, "��");
                break;
            default:
                strcpy(graph, "��");
            break;
        }
    }
    return graph;
}
    
/**
 * �����ͼ�������У���1��3�У�
 * ������� start �������ʼ���ڵ�ͼ�ϵ�λ��
 * ������� end ����Ľ������ڵ�ͼ�ϵ�λ��
 * ������� playerPos1 ���1�ĵ�ǰλ��
 * ������� playerPos2 ���2�ĵ�ǰλ��
 */
void showLine1(int start, int end, int playerPos1, int playerPos2)
{     
    int i;

    for (i = start; i < end; i++)
    {
        printf("%s", getGraph(map[i], i, playerPos1, playerPos2));
    }
}
    
/**
 * �����ͼ��ż���У���2�У�
 * ������� start �������ʼ���ڵ�ͼ�ϵ�λ��
 * ������� end ����Ľ������ڵ�ͼ�ϵ�λ��
 * ������� playerPos1 ���1�ĵ�ǰλ��
 * ������� playerPos2 ���2�ĵ�ǰλ��
 */
void showLine2(int start, int end, int playerPos1, int playerPos2)
{    
    int i;

    for (i = end - 1; i >= start; i--)
    {    
        printf("%s", getGraph(map[i], i, playerPos1, playerPos2));
    }
}
    
/**
 * �����ͼ��������
 * ������� start �������ʼ���ڵ�ͼ�ϵ�λ��
 * ������� end ����Ľ������ڵ�ͼ�ϵ�λ��
 * ������� playerPos1 ���1�ĵ�ǰλ��
 * ������� playerPos2 ���2�ĵ�ǰλ��
 */
void showRLine(int start, int end, int playerPos1, int playerPos2)
{
    int i, j;

    for (i = start; i< end; i++)
    {
        for (j = 30; j > 0; j--)
        {  // ���30���ո�
            printf("  ");
        }
        printf("%s", getGraph(map[i], i, playerPos1, playerPos2));
        printf("\n");
    }
}
    
/**
 * �����ͼ��������
 * ������� start �������ʼ���ڵ�ͼ�ϵ�λ��
 * ������� end ����Ľ������ڵ�ͼ�ϵ�λ��
 * ������� playerPos1 ���1�ĵ�ǰλ��
 * ������� playerPos2 ���2�ĵ�ǰλ��
 */
void showLLine(int start, int end, int playerPos1, int playerPos2)
{
    int i;

    for (i = start; i < end; i++)
    {
        printf("%s\n", getGraph(map[i], i, playerPos1, playerPos2));
    }
}

/**
 * ��ʾ��ս��ͼ
 * ������� playerPos1 ���1�ĵ�ǰλ��
 * ������� playerPos2 ���2�ĵ�ǰλ��
 */
void showMap(int playerPos1, int playerPos2)
{
    showLine1(0, 31, playerPos1, playerPos2);   // ��ʾ��ͼ��һ��
    printf("\n");                     // ����
    showRLine(31, 35, playerPos1, playerPos2);  // ��ʾ��ͼ������
    showLine2(35, 66, playerPos1, playerPos2); // ��ʾ��ͼ�ڶ���
    printf("\n");                     // ����
    showLLine(66, 69, playerPos1, playerPos2); // ��ʾ��ͼ������
    showLine2(69, 100, playerPos1, playerPos2); // ��ʾ��ͼ��3��
}  

/**
 * ���ö�ս��ɫ
 * ������� no ��Ҵ��� 1�����1 2�����2
 * ������� role ��ɫ����
 */
void setRole(int no, int role)
{
    switch (role)
    {
        case 1: 
            strcpy(playerName[no-1], "�ŷ�");
            break;
        case 2: 
            strcpy(playerName[no-1], "����");
            break;
        case 3:
            strcpy(playerName[no-1], "�����");
            break;
        case 4: 
            strcpy(playerName[no-1], "����");
            break;
        default: 
            break;
    }
}

/**
 * ��ʾ��ս���
 */
void judge()
{
    if (playerPos1 > playerPos2)
    {
        printf("\n��ϲ%s! ����ʤ�ˣ�\n", playerName[0]);
    }
    else
    {
        printf("\n��ϲ%s! ����ʤ�ˣ�\n", playerName[1]);
    }
}

/**
 * ���˶�ս�淨
 */
void play()
{      
    printf("****************************************************\n");
    printf("                     ��Ϸ��ʼ�ˣ�                   \n");
    printf("****************************************************\n\n");

    // ��ʾ��ս˫��ʿ����ʽ
    printf("^_^%s��ʿ��������\n", playerName[0]);
    printf("^_^%s��ʿ����  ��\n\n", playerName[1]);

    // ��ʾ��ս��ͼ
    printf("\nͼ���� �� ��ͣ  �� ��������   �� ����   �� ʱ�����   �� ��ͨ\n\n");

    showMap(playerPos1, playerPos2);

    // ��Ϸ��ʼ
    int step;  // �洢������Ŀ

    while (playerPos1 < 99 && playerPos2 < 99)
    {    
        // ���κ�һ���ߵ��յ㣬����ѭ��
        // ����������
        if (!strcmp(goAndStop[0], "on"))
        {    
            // ���1������
            step = throwShifter(1);   // ������
            // system("cls");
            printf("\n-----------------\n");  // ��ʾ�����Ϣ
            printf("��������%d \n", step);
            playerPos1 = getCurPos(1, playerPos1, step);  // ������һ���ƶ���ĵ�ǰλ��
            printf("\n%s����ǰλ�ã�%d  \n", playerName[0], playerPos1);
            printf("�Է���ǰλ�ã�%d  \n", playerPos2);
            printf("-----------------\n\n");
            showMap(playerPos1, playerPos2); // ��ʾ��ǰ��ͼ
            if (playerPos1 == 99)
            {  // ����ߵ��յ�
                break;   // �˳�
            }
        }
        else
        {
            printf("\n%sͣ��һ�Σ�\n\n", playerName[0]);   // ��ʾ�˴���ͣ��Ϣ
            strcpy(goAndStop[0], "on");   // �����´ο���״̬
        }


        printf("\n\n\n\n\n");

        if (!strcmp(goAndStop[1], "on"))
        {
            // ���2������
            step = throwShifter(2); // ������
            printf("\n-----------------\n"); // ��ʾ�����Ϣ
            printf("��������%d \n", step);
            playerPos2 = getCurPos(2, playerPos2, step);  // ������һ���ƶ���ĵ�ǰλ��
            printf("\n%s����ǰλ�ã�%d  \n", playerName[1], playerPos2);
            printf("�Է���ǰλ�ã�%d\n", playerPos1);
            printf("-----------------\n\n");
            showMap(playerPos1, playerPos2);
            if (playerPos2 == 99)
            {  // ����ߵ��յ�
                break;   // �˳�
            }
        }
        else
        {
            printf("\n%sͣ��һ�Σ�\n\n", playerName[1]);  // ��ʾ�˴���ͣ��Ϣ
            strcpy(goAndStop[1], "on");  // �����´ο���״̬
        }

        printf("\n\n\n\n\n");
    } 

    // ��Ϸ����
    printf("\n\n\n\n\n");
    printf("****************************************************\n");
    printf("                      ��Ϸ������                    \n");
    printf("****************************************************\n\n");
    judge();
}
      
      
/**
 * ��ʼ��Ϸ
 */
void start()
{
    // ��ʼ��
    init();  
    printf("����������������������������������������������������������������\n");
    printf("//                                                            //\n");
    printf("//                                                            //\n");
    printf("//             ��    ʿ    ��    ��    ��                     //\n");
    printf("//                                                            //\n");
    printf("//                                                            //\n");
    printf("����������������������������������������������������������������\n\n\n\n");

    printf("\n~~~~~~~~~~~~~~~~~~~��  ��  ��  ս~~~~~~~~~~~~~~~~~~~\n");
    printf("\n��ѡ���ɫ: 1. �ŷ� 2. ���� 3. ����� 4. ����\n");
    printf("�����1ѡ���ɫ:  ");
    int role1;
    scanf("%d", &role1);
    fflush(stdin);
    int role2;
    do {
        printf("�����2ѡ���ɫ�� ");
        scanf("%d", &role2);  // ˫��ѡ���ɫ����
        fflush(stdin);
    } while (role2==role1);  // �������ɫ�ظ�
    setRole(1, role1);   // �������1����Ľ�ɫ
    setRole(2, role2);   // �������2����Ľ�ɫ
    system("cls");
    play();   // ��ʼ���˶�ս
}
    
/**
 * ������
 * ������� no ��Ҵ���
 * ����ֵ step ������������Ŀ
 */
int throwShifter(int no)
{
    int step = 0;  
    printf("\n\n%s, ������������ĸ����س����������ӣ� ", playerName[no-1]);
    char ch;
    scanf("%c", &ch);
    fflush(stdin);
    step = (int)(rand() * 10) % 6 + 1;// ����һ��1~6������,������������Ŀ
    system("cls");
    return step; 
}
    
/**
 * ������Ҵ˴��ƶ���ĵ�ǰλ��
 * ������� no ��Ҵ���
 * ������� position �ƶ�ǰλ��
 * ������� step ����������Ŀ
 * ����ֵ position �ƶ����λ��
 */
int getCurPos(int no, int position, int step)
{
    position = position + step;  // ��һ���ƶ����λ��
    if (position >= 99)
    {
        return 99;
    }
    switch (map[position])
    {   // ���ݵ�ͼ�еĹؿ����Ž����ж�
        case 0:    // �ߵ���ͨ��
            if (no == 1 && playerPos2 == position)
            {   // ���1��Է��������
                playerPos2 = 0;    // �ȵ��Է����Է��ص����
                printf(":-D  ��������...�ȵ��ˣ�");
            } 
            if (no == 2 && playerPos1 == position)
            { // ���2��Է��������
                playerPos1 = 0;    // �ȵ��Է����Է��ص����
                printf(":-D  ��������...�ȵ��ˣ�\n");
            }
            break;
        case 1:   // ��������
            printf("\n����������ӭ�����������̡�������\n");
            printf("\n%s����ǰλ�ã�%d  \n", playerName[1], playerPos2);
            printf("�Է���ǰλ�ã�%d\n", playerPos1);
            printf("   ��ѡ��һ��������\n");
            printf("   1. ����λ��  2. ��ը\n");
            printf("=============================\n\n");
            int choice;
            scanf("%d", &choice);
            fflush(stdin);
            int temp;
            switch (choice)
            {
                case 1: 
                    if (no == 1)
                    {
                        temp = position;
                        position = playerPos2;
                        playerPos2 = temp; 
                    }
                    else if (no == 2)
                    {
                        temp = position;
                        position = playerPos1;
                        playerPos1 = temp;
                    }
                    break;
                case 2: 
                    if (no == 1 && playerPos2 < 6)
                    {
                        playerPos2 = 0;
                    }
                    else
                    {
                        playerPos2 = playerPos2 - 6;
                    }
                    if (no == 2 && playerPos2 < 6)
                    {
                        playerPos1 = 0;
                    }
                    else
                    {
                        playerPos1 = playerPos1 - 6;
                    }
                    break;
            }
            // printf(":~) �Ҹ����Ҷ�Ҫ����...\n");
            break;
        case 2:   // �ȵ�����
            position = position -6; // �ȵ�������6��
            printf("~:-(  �ȵ����ף�������...\n");
            break;
        case 3:  // ��һ����ͣһ��
            strcpy(goAndStop[no-1], "off");  // �����´���ͣ������
            printf("~~>_<~~  Ҫͣսһ���ˡ�\n");
            break;
        case 4:   // ʱ�����
            position = position + 10;  // ����ʱ�����������10��
            printf("|-P ����ʱ������� ��ˬ��\n");
            break;
    }

    // ���ش˴������Ӻ���ҵ�λ������
    if (position < 0)
    {
        return 0;
    }
    else if (position > 99)
    {
        return 99;
    }
    else
    {
        return position; 
    }
}

int main(int argc, char *argv[])
{
    start();
    
    system("pause");
    return 0;
}
