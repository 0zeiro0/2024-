#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
#include<ctype.h>
//
// 无效char[]统一用"000"表示，无效int用-1表示,无效float用0表示

/*********List***********/
// item节点定义
typedef struct Item
{
    int itemRank;    // 1类别标记数(4,paper;5,project;6,award;7,course)
    int level;       // 2论文(级别信息);获奖(等级)
    float credit;    // 3论文(GPA加分);课程(学分)
    char name[51];   // 4名称
    char id[51];     // 5论文(号);项目(编号);获奖();课程(教师)
    char holder[51]; // 6论文(期刊/会议名称);项目(指导教师);获奖(主办单位);课程(学院)
    char date[51];   // 7论文(发表时间);项目(立项时间);获奖(时间);课程(哪次考试)
    char datend[51]; // 8论文(卷期);项目(结项时间);课程(专业)
    //
    struct Item *next;
    struct Member *pMem;
} Item;
// Member节点定义
typedef struct Member
{
    char id[51]; // 1成员id
    int rankscore; // 2素质类(顺序)，课程(分数)[论文中分1，通讯记为-1，2，3和n作者]
    float point;   // 3课程(绩点), -1指教师
    //
    struct Member *next;
} Member;
// 浮动指针节点定义
typedef struct Ptr
{
    char namestr[51];
    //
    struct User *pUser;
    struct Item *pItem;
    struct Member *pMember;
    struct Ptr *next;
} Ptr;
// User节点定义
typedef struct User
{
    int useRank;       // 1身份标记数(1,管理员;2,教师;3,学生)
    char name[51];     // 2用户真实姓名
    char id[51];       // 3学号&工号&管理号=帐号名
    char password[51]; // 4账号密码
    char faculty[51];  // 5用户学院
    char major[51];    // 6学生(专业)
    char term[51];     // 7学生(学期)
    float GPA;         // 8学生(平均绩点,计算获得)
    //
    struct User *next;
} User;
/*MessageBegin*/
// Message节点定义
typedef struct Message
{
    int messrank; //1 表示公告，2表示申诉
    time_t time;
    char id[51];
    char text[201];
    struct Message *next;
} Message;

// 初始化
Message *initMessage();
// 创建
Message *createMessage(Message *pTail,int rank,time_t timeNow, char id[], char text[]);
// 删除
void delete_Mess(Message *Pre);
//寻找Message尾节点
Message *MessFindTail(Message *pHeader);
// 申诉链表清空
void clear_MessList(Message *pHeader, int opt);
//遍历找到对应标号Message的头节点
Message *MessFindNum(Message *pHeader, int num);
/*MessageEnd***/

/*初始化begin*/
// 初始化User
User *initUser();
// 初始化Item
Item *initItem();
// 初始化Member
Member *initMember();
/*初始化end*/
//
/*参数创建Node*begin*/
// User
User *createUser(
    User *pTail,
    int useRank,       // 身份标记数(0,管理员;1,教师;2,学生)
    char name[51],     // 用户真实姓名
    char id[51],       // 学号&工号&管理号=帐号名
    char password[51], // 账号密码
    char faculty[51],  //学生,老师换成学院
    char major[51],    // 学生(专业)
    char term[51],     // 学生(学期)
    float GPA          // 学生(绩点)
);
// Item
Item *createItem(
    Item *pTail,
    int itemRank,    // 1类别标记数(4,paper;5,project;6,award;7,course)
    int level,       // 2论文(级别信息);获奖(等级)
    float credit,    // 3论文(GPA加分);课程(学分)
    char name[51],   // 4名称
    char id[51],     // 5论文(号);项目(编号);
    char holder[51], // 6论文(期刊/会议名称);项目(指导教师);获奖(主办单位);课程(学院)
    char date[51],   // 7论文(发表时间);项目(立项时间);获奖(时间);课程(哪次考试)
    char datend[51]  // 8论文(卷期);项目(结项时间);课程(专业)
);
// Member
Member *createMember(
    Member *pTail,
    char id[51], // 成员姓名
    int rankscore, // 素质类(顺序)，课程(分数)
    float point    // 课程(绩点);-1表示教师
);
/*参数创建Node*end***/
//
/*寻尾FindTail*begin*/
// User
User *UFindTail(User *pHeader);
// Item
Item *IFindTail(Item *pHeader);
// Member
Member *MFindTail(Member *pHeader);
// Ptr
/*寻尾FindTail*end**/
/*清空链表begin*/
// User
void clear_UList(User *pHeader,int opt );
// Item
void clear_ItemList(Item *pHeader,int opt);
// Member
void clear_MemberList(Member *pHeader,int opt);
/*清空链表end***/
//
/*删除链表begin*/
// User
void delete_U(User *Pre,Item* IpHeader);
// Item
void delete_I(Item *Pre);
// Member
void delete_M(Member *Pre);
/*删除链表end***/

/*浮动链操作begin*/
// 初始化
Ptr *initPtr();
// 寻尾
Ptr *PFindTail(Ptr *pHeader);
// 指针浮动链创建
Ptr *createPtr(Ptr *pTail, User *pU, Item *pI, Member *pM);
// 名字浮动链创建
Ptr *createPtrName(Ptr *pTail, char namestr[]);
// 清空
Ptr* clear_PList(Ptr *pHeader, int opt);
//遍历找到对应数字的Ptr节点（头节点为0）
Ptr* PFindNum(Ptr* pHeader,int num);
/*浮动链操作end***/
//
/*查找节点前指针begin*/
//
// User
// useRank
Ptr *UFindRank(User *pHeader, int useRank);
// name
Ptr *UFindName(User *pHeader, char name[]);
// User返回:在User链中寻找符合id的User*的前节点
User* UFindId(User* pHeader,char* id);
//Ptr返回:在User链中寻找符合id的User*的前节点的链
Ptr *UFindId_Ptr(User *pHeader, char* id);
// major
Ptr *UFindMajor(User *pHeader, char major[]);
// term
Ptr *UFindTerm(User *pHeader, char term[]);
//

// Item
// itemRank
Ptr *IFindRank(Item *pHeader, int itemRank);
// level
Ptr *IFindLevel(Item *pHeader, int itemRank, int realRank);
// name
Ptr *IFindName(Item *pHeader, char name[], int itemRank);
//Ptr返回:在Item链中寻找符合id的Item*的前节点的链
Ptr *IPtrFindId(Item *pHeader, char id[], int itemRank);
// Item返回:在Item链中寻找符合id的Item的前节点指针
Item* IFindId(Item* pHeader,char* id);
// holder
Ptr *IFindHolder(Item *pHeader, char holder[], int itemRank);
// datend
Ptr *IFindDatend(Item *pHeader, char datend[], int itemRank);
// date
Ptr *IFindDate(Item *pHeader, char date[], int itemRank);

// Member
//Item下的Member头节点:由所有Member生成一链
Ptr* Item_AllMember(Member* pHeader);
// id:在Member链中寻找
Ptr *MPtrFindId(Member *pHeader, char id[]);
//GPA范围查找
Ptr *MPtrFindGPA(Member*pHeader,float low,float high);
// id:在Member链中寻找,并返回其前节点
Member *MemFindId(Member *pHeader, char id[]);
//id:在Item下的所有Member链中寻找,返回有其的Ptr(Item,Member)Pre链
Ptr* IFind_MId(Item* IpHeader,char id[],int onum);
/*查找节点前指针end***/

/*GPA计算begin*/
void Get_GPA(User *pUHeader, Item *pIHeader);
/*GPA计算end***/

/*寻名&查重begin*/
// UserId的Ptr链查重，返回1指无重，返回0指有重
int JSamePtr_UserId(User* pHeader,char id[]);
// ItemId的Ptr链查重，返回1指无重，返回0指有重
int JSamePtr_ItemId(Item* pHeader,char id[]);
// Ptr名字链查重，返回1指无重，返回0指有重
int JSamePtr_Name(Ptr *pHeader, char namestr[]);
// 除重寻名,course类:5教师 6课程学院 7课程考试场次 8某学院课程专业:加强功能
Ptr *NFind_Course(Item *pHeader, int opt, char name[]);
/*寻名&查重end***/

/*排序begin*/ // pL,pR指目标节点的前指针
//User:直接交换函数
void ExchangeU(User* pL,User* pR);
//Item:直接交换函数
void ExchangeI(Item* pL,Item* pR);
// member交换函数
void ExchangeMem(Member *pL, Member *pR);
// User:GPA,1表示从低到高，-1表示从高到低
void OrderU(User *pHeader, int opt);
// Member:rankscore,1表示从低到高，-1表示从高到低
void OrderM(Member *pHeader, int opt);
//Item等级排序,1表示从低到高，-1表示从高到低
void OrderItemLevel(Item* pHeader,int opt);
//Mess等级排序,1表示从低到高，-1表示从高到低
void OrderMess(Message*pHeader, int opt);
/*排序end***/

