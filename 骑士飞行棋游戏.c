/**
 * 项目名称：骑士飞行棋游戏，第二次迭代，完成整个游戏
 * 开发日期：2011年5月16日
 * 作    者：BBC
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int map[100];                                         //对战地图
int luckyTurn[] = {6, 23, 40, 55, 69, 83};            // 幸运轮盘
int landMine[] = {5, 13, 17, 33, 38, 50, 64, 80, 94}; // 地雷位置
int pause[] = {9, 27, 60, 93};                        // 暂停
int timeTunnel[] = {20, 25, 45, 63, 72, 88, 90};      // 时空隧道
char graph[10]; 
int playerPos1; // 对战中玩家1的当前位置
int playerPos2; // 对战中玩家2的当前位置
char goAndStop[2][3];   // 走或停标识设置
char playerName[2][20];

      
/**
 * 生成地图: 关卡代号为：1：幸运轮盘 2：地雷 3: 暂停 4：时空隧道 0：普通
 */
void createMap()
{
    int i = 0; 

    // 在对战地图上设置幸运轮盘
    for (i = 0; i < sizeof(luckyTurn) / sizeof(int); i++)
    {
        map[luckyTurn[i]] = 1; 
    }

    // 在对战地图上设置地雷
    for(i = 0; i < sizeof(landMine)/sizeof(int); i++){
        map[landMine[i]] = 2; 
    }

    // 在对战地图上设置暂停
    for (i = 0; i < sizeof(pause) / sizeof(int); i++)
    {
        map[pause[i]] = 3; 
    }

    // 在对战地图上设置时空隧道
    for (i = 0; i < sizeof(timeTunnel) / sizeof(int); i++)
    {
        map[timeTunnel[i]] = 4; 
    }
}

/**
 * 初始化游戏的一局
 */
void init()
{   
    createMap();  // 生成地图
    playerPos1 = 0;   // 设置玩家1起始位置
    playerPos2 = 0;   // 设置玩家2起始位置
    strcpy(goAndStop[0], "on");  // 记录玩家1下一次走或停
    strcpy(goAndStop[1], "on");  // 设置玩家2下一次走或停
}


/**
 * 显示地图关卡对应的图形
 * 输入参数 i 地图当前位置的关卡代号
 * 输入参数 index 当前地图位置编号
 * 输入参数 playerPos1 玩家1的当前位置
 * 输入参数 playerPos2 玩家2的当前位置
 * 返回值 地图当前位置的对应图片
 */
char *getGraph(int i, int index, int playerPos1, int playerPos2)
{
    if (index == playerPos1 && index == playerPos2)
    {
        strcpy(graph, "@@");
    }
    else if (index == playerPos1)
    {    
        // graph = "♀";
        strcpy(graph, "Ａ");
    }
    else if (index == playerPos2)
    {
        // graph = "♂";
        strcpy(graph, "Ｂ");
    }
    else
    {
        switch (i)
        {
            case 1:   // 幸运轮盘
                strcpy(graph, "¤");
                break;
            case 2:   // 地雷
                strcpy(graph, "★");
                break;
            case 3:   // 暂停
                strcpy(graph, "■");
                break;
            case 4:   // 时光隧道
                strcpy(graph, "〓");
                break;
            default:
                strcpy(graph, "∷");
            break;
        }
    }
    return graph;
}
    
/**
 * 输出地图的奇数行（第1、3行）
 * 输入参数 start 输出的起始点在地图上的位置
 * 输入参数 end 输出的结束点在地图上的位置
 * 输入参数 playerPos1 玩家1的当前位置
 * 输入参数 playerPos2 玩家2的当前位置
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
 * 输出地图的偶数行（第2行）
 * 输入参数 start 输出的起始点在地图上的位置
 * 输入参数 end 输出的结束点在地图上的位置
 * 输入参数 playerPos1 玩家1的当前位置
 * 输入参数 playerPos2 玩家2的当前位置
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
 * 输出地图的右竖列
 * 输入参数 start 输出的起始点在地图上的位置
 * 输入参数 end 输出的结束点在地图上的位置
 * 输入参数 playerPos1 玩家1的当前位置
 * 输入参数 playerPos2 玩家2的当前位置
 */
void showRLine(int start, int end, int playerPos1, int playerPos2)
{
    int i, j;

    for (i = start; i< end; i++)
    {
        for (j = 30; j > 0; j--)
        {  // 输出30个空格
            printf("  ");
        }
        printf("%s", getGraph(map[i], i, playerPos1, playerPos2));
        printf("\n");
    }
}
    
/**
 * 输出地图的左竖列
 * 输入参数 start 输出的起始点在地图上的位置
 * 输入参数 end 输出的结束点在地图上的位置
 * 输入参数 playerPos1 玩家1的当前位置
 * 输入参数 playerPos2 玩家2的当前位置
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
 * 显示对战地图
 * 输入参数 playerPos1 玩家1的当前位置
 * 输入参数 playerPos2 玩家2的当前位置
 */
void showMap(int playerPos1, int playerPos2)
{
    showLine1(0, 31, playerPos1, playerPos2);   // 显示地图第一行
    printf("\n");                     // 换行
    showRLine(31, 35, playerPos1, playerPos2);  // 显示地图右竖行
    showLine2(35, 66, playerPos1, playerPos2); // 显示地图第二行
    printf("\n");                     // 换行
    showLLine(66, 69, playerPos1, playerPos2); // 显示地图左竖行
    showLine2(69, 100, playerPos1, playerPos2); // 显示地图第3行
}  

/**
 * 设置对战角色
 * 输入参数 no 玩家次序 1：玩家1 2：玩家2
 * 输入参数 role 角色代号
 */
void setRole(int no, int role)
{
    switch (role)
    {
        case 1: 
            strcpy(playerName[no-1], "张飞");
            break;
        case 2: 
            strcpy(playerName[no-1], "关羽");
            break;
        case 3:
            strcpy(playerName[no-1], "诸葛亮");
            break;
        case 4: 
            strcpy(playerName[no-1], "刘备");
            break;
        default: 
            break;
    }
}

/**
 * 显示对战结果
 */
void judge()
{
    if (playerPos1 > playerPos2)
    {
        printf("\n恭喜%s! 您获胜了！\n", playerName[0]);
    }
    else
    {
        printf("\n恭喜%s! 您获胜了！\n", playerName[1]);
    }
}

/**
 * 两人对战玩法
 */
void play()
{      
    printf("****************************************************\n");
    printf("                     游戏开始了！                   \n");
    printf("****************************************************\n\n");

    // 显示对战双方士兵样式
    printf("^_^%s的士兵：　Ａ\n", playerName[0]);
    printf("^_^%s的士兵：  Ｂ\n\n", playerName[1]);

    // 显示对战地图
    printf("\n图例： ■ 暂停  ¤ 幸运轮盘   ★ 地雷   〓 时空隧道   ∷ 普通\n\n");

    showMap(playerPos1, playerPos2);

    // 游戏开始
    int step;  // 存储骰子数目

    while (playerPos1 < 99 && playerPos2 < 99)
    {    
        // 有任何一方走到终点，跳出循环
        // 轮流掷骰子
        if (!strcmp(goAndStop[0], "on"))
        {    
            // 玩家1掷骰子
            step = throwShifter(1);   // 掷骰子
            // system("cls");
            printf("\n-----------------\n");  // 显示结果信息
            printf("骰子数：%d \n", step);
            playerPos1 = getCurPos(1, playerPos1, step);  // 计算这一次移动后的当前位置
            printf("\n%s您当前位置：%d  \n", playerName[0], playerPos1);
            printf("对方当前位置：%d  \n", playerPos2);
            printf("-----------------\n\n");
            showMap(playerPos1, playerPos2); // 显示当前地图
            if (playerPos1 == 99)
            {  // 如果走到终点
                break;   // 退出
            }
        }
        else
        {
            printf("\n%s停掷一次！\n\n", playerName[0]);   // 显示此次暂停信息
            strcpy(goAndStop[0], "on");   // 设置下次可掷状态
        }


        printf("\n\n\n\n\n");

        if (!strcmp(goAndStop[1], "on"))
        {
            // 玩家2掷骰子
            step = throwShifter(2); // 掷骰子
            printf("\n-----------------\n"); // 显示结果信息
            printf("骰子数：%d \n", step);
            playerPos2 = getCurPos(2, playerPos2, step);  // 计算这一次移动后的当前位置
            printf("\n%s您当前位置：%d  \n", playerName[1], playerPos2);
            printf("对方当前位置：%d\n", playerPos1);
            printf("-----------------\n\n");
            showMap(playerPos1, playerPos2);
            if (playerPos2 == 99)
            {  // 如果走到终点
                break;   // 退出
            }
        }
        else
        {
            printf("\n%s停掷一次！\n\n", playerName[1]);  // 显示此次暂停信息
            strcpy(goAndStop[1], "on");  // 设置下次可掷状态
        }

        printf("\n\n\n\n\n");
    } 

    // 游戏结束
    printf("\n\n\n\n\n");
    printf("****************************************************\n");
    printf("                      游戏结束！                    \n");
    printf("****************************************************\n\n");
    judge();
}
      
      
/**
 * 开始游戏
 */
void start()
{
    // 初始化
    init();  
    printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n");
    printf("//                                                            //\n");
    printf("//                                                            //\n");
    printf("//             骑    士    飞    行    棋                     //\n");
    printf("//                                                            //\n");
    printf("//                                                            //\n");
    printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n\n\n\n");

    printf("\n~~~~~~~~~~~~~~~~~~~两  人  对  战~~~~~~~~~~~~~~~~~~~\n");
    printf("\n请选择角色: 1. 张飞 2. 关羽 3. 诸葛亮 4. 刘备\n");
    printf("请玩家1选择角色:  ");
    int role1;
    scanf("%d", &role1);
    fflush(stdin);
    int role2;
    do {
        printf("请玩家2选择角色： ");
        scanf("%d", &role2);  // 双方选择角色代号
        fflush(stdin);
    } while (role2==role1);  // 不允许角色重复
    setRole(1, role1);   // 设置玩家1代表的角色
    setRole(2, role2);   // 设置玩家2代表的角色
    system("cls");
    play();   // 开始两人对战
}
    
/**
 * 掷骰子
 * 输入参数 no 玩家次序
 * 返回值 step 掷出的骰子数目
 */
int throwShifter(int no)
{
    int step = 0;  
    printf("\n\n%s, 请您按任意字母键后回车启动掷骰子： ", playerName[no-1]);
    char ch;
    scanf("%c", &ch);
    fflush(stdin);
    step = (int)(rand() * 10) % 6 + 1;// 产生一个1~6的数字,即掷的骰子数目
    system("cls");
    return step; 
}
    
/**
 * 计算玩家此次移动后的当前位置
 * 输入参数 no 玩家次序
 * 输入参数 position 移动前位置
 * 输入参数 step 掷的骰子数目
 * 返回值 position 移动后的位置
 */
int getCurPos(int no, int position, int step)
{
    position = position + step;  // 第一次移动后的位置
    if (position >= 99)
    {
        return 99;
    }
    switch (map[position])
    {   // 根据地图中的关卡代号进行判断
        case 0:    // 走到普通格
            if (no == 1 && playerPos2 == position)
            {   // 玩家1与对方骑兵相遇
                playerPos2 = 0;    // 踩到对方，对方回到起点
                printf(":-D  哈哈哈哈...踩到了！");
            } 
            if (no == 2 && playerPos1 == position)
            { // 玩家2与对方骑兵相遇
                playerPos1 = 0;    // 踩到对方，对方回到起点
                printf(":-D  哈哈哈哈...踩到了！\n");
            }
            break;
        case 1:   // 幸运轮盘
            printf("\n◆◇◆◇◆欢迎进入幸运轮盘◆◇◆◇◆\n");
            printf("\n%s您当前位置：%d  \n", playerName[1], playerPos2);
            printf("对方当前位置：%d\n", playerPos1);
            printf("   请选择一种运气：\n");
            printf("   1. 交换位置  2. 轰炸\n");
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
            // printf(":~) 幸福的我都要哭了...\n");
            break;
        case 2:   // 踩到地雷
            position = position -6; // 踩到地雷退6步
            printf("~:-(  踩到地雷，气死了...\n");
            break;
        case 3:  // 下一次暂停一次
            strcpy(goAndStop[no-1], "off");  // 设置下次暂停掷骰子
            printf("~~>_<~~  要停战一局了。\n");
            break;
        case 4:   // 时空隧道
            position = position + 10;  // 进入时空隧道，加走10步
            printf("|-P 进入时空隧道， 真爽！\n");
            break;
    }

    // 返回此次掷骰子后玩家的位置坐标
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
