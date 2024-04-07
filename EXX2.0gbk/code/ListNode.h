#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
#include<ctype.h>
//
// ��Чchar[]ͳһ��"000"��ʾ����Чint��-1��ʾ,��Чfloat��0��ʾ

/*********List***********/
// item�ڵ㶨��
typedef struct Item
{
    int itemRank;    // 1�������(4,paper;5,project;6,award;7,course)
    int level;       // 2����(������Ϣ);��(�ȼ�)
    float credit;    // 3����(GPA�ӷ�);�γ�(ѧ��)
    char name[51];   // 4����
    char id[51];     // 5����(��);��Ŀ(���);��();�γ�(��ʦ)
    char holder[51]; // 6����(�ڿ�/��������);��Ŀ(ָ����ʦ);��(���쵥λ);�γ�(ѧԺ)
    char date[51];   // 7����(����ʱ��);��Ŀ(����ʱ��);��(ʱ��);�γ�(�Ĵο���)
    char datend[51]; // 8����(����);��Ŀ(����ʱ��);�γ�(רҵ)
    //
    struct Item *next;
    struct Member *pMem;
} Item;
// Member�ڵ㶨��
typedef struct Member
{
    char id[51]; // 1��Աid
    int rankscore; // 2������(˳��)���γ�(����)[�����з�1��ͨѶ��Ϊ-1��2��3��n����]
    float point;   // 3�γ�(����), -1ָ��ʦ
    //
    struct Member *next;
} Member;
// ����ָ��ڵ㶨��
typedef struct Ptr
{
    char namestr[51];
    //
    struct User *pUser;
    struct Item *pItem;
    struct Member *pMember;
    struct Ptr *next;
} Ptr;
// User�ڵ㶨��
typedef struct User
{
    int useRank;       // 1��ݱ����(1,����Ա;2,��ʦ;3,ѧ��)
    char name[51];     // 2�û���ʵ����
    char id[51];       // 3ѧ��&����&�����=�ʺ���
    char password[51]; // 4�˺�����
    char faculty[51];  // 5�û�ѧԺ
    char major[51];    // 6ѧ��(רҵ)
    char term[51];     // 7ѧ��(ѧ��)
    float GPA;         // 8ѧ��(ƽ������,������)
    //
    struct User *next;
} User;
/*MessageBegin*/
// Message�ڵ㶨��
typedef struct Message
{
    int messrank; //1 ��ʾ���棬2��ʾ����
    time_t time;
    char id[51];
    char text[201];
    struct Message *next;
} Message;

// ��ʼ��
Message *initMessage();
// ����
Message *createMessage(Message *pTail,int rank,time_t timeNow, char id[], char text[]);
// ɾ��
void delete_Mess(Message *Pre);
//Ѱ��Messageβ�ڵ�
Message *MessFindTail(Message *pHeader);
// �����������
void clear_MessList(Message *pHeader, int opt);
//�����ҵ���Ӧ���Message��ͷ�ڵ�
Message *MessFindNum(Message *pHeader, int num);
/*MessageEnd***/

/*��ʼ��begin*/
// ��ʼ��User
User *initUser();
// ��ʼ��Item
Item *initItem();
// ��ʼ��Member
Member *initMember();
/*��ʼ��end*/
//
/*��������Node*begin*/
// User
User *createUser(
    User *pTail,
    int useRank,       // ��ݱ����(0,����Ա;1,��ʦ;2,ѧ��)
    char name[51],     // �û���ʵ����
    char id[51],       // ѧ��&����&�����=�ʺ���
    char password[51], // �˺�����
    char faculty[51],  //ѧ��,��ʦ����ѧԺ
    char major[51],    // ѧ��(רҵ)
    char term[51],     // ѧ��(ѧ��)
    float GPA          // ѧ��(����)
);
// Item
Item *createItem(
    Item *pTail,
    int itemRank,    // 1�������(4,paper;5,project;6,award;7,course)
    int level,       // 2����(������Ϣ);��(�ȼ�)
    float credit,    // 3����(GPA�ӷ�);�γ�(ѧ��)
    char name[51],   // 4����
    char id[51],     // 5����(��);��Ŀ(���);
    char holder[51], // 6����(�ڿ�/��������);��Ŀ(ָ����ʦ);��(���쵥λ);�γ�(ѧԺ)
    char date[51],   // 7����(����ʱ��);��Ŀ(����ʱ��);��(ʱ��);�γ�(�Ĵο���)
    char datend[51]  // 8����(����);��Ŀ(����ʱ��);�γ�(רҵ)
);
// Member
Member *createMember(
    Member *pTail,
    char id[51], // ��Ա����
    int rankscore, // ������(˳��)���γ�(����)
    float point    // �γ�(����);-1��ʾ��ʦ
);
/*��������Node*end***/
//
/*ѰβFindTail*begin*/
// User
User *UFindTail(User *pHeader);
// Item
Item *IFindTail(Item *pHeader);
// Member
Member *MFindTail(Member *pHeader);
// Ptr
/*ѰβFindTail*end**/
/*�������begin*/
// User
void clear_UList(User *pHeader,int opt );
// Item
void clear_ItemList(Item *pHeader,int opt);
// Member
void clear_MemberList(Member *pHeader,int opt);
/*�������end***/
//
/*ɾ������begin*/
// User
void delete_U(User *Pre,Item* IpHeader);
// Item
void delete_I(Item *Pre);
// Member
void delete_M(Member *Pre);
/*ɾ������end***/

/*����������begin*/
// ��ʼ��
Ptr *initPtr();
// Ѱβ
Ptr *PFindTail(Ptr *pHeader);
// ָ�븡��������
Ptr *createPtr(Ptr *pTail, User *pU, Item *pI, Member *pM);
// ���ָ���������
Ptr *createPtrName(Ptr *pTail, char namestr[]);
// ���
Ptr* clear_PList(Ptr *pHeader, int opt);
//�����ҵ���Ӧ���ֵ�Ptr�ڵ㣨ͷ�ڵ�Ϊ0��
Ptr* PFindNum(Ptr* pHeader,int num);
/*����������end***/
//
/*���ҽڵ�ǰָ��begin*/
//
// User
// useRank
Ptr *UFindRank(User *pHeader, int useRank);
// name
Ptr *UFindName(User *pHeader, char name[]);
// User����:��User����Ѱ�ҷ���id��User*��ǰ�ڵ�
User* UFindId(User* pHeader,char* id);
//Ptr����:��User����Ѱ�ҷ���id��User*��ǰ�ڵ����
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
//Ptr����:��Item����Ѱ�ҷ���id��Item*��ǰ�ڵ����
Ptr *IPtrFindId(Item *pHeader, char id[], int itemRank);
// Item����:��Item����Ѱ�ҷ���id��Item��ǰ�ڵ�ָ��
Item* IFindId(Item* pHeader,char* id);
// holder
Ptr *IFindHolder(Item *pHeader, char holder[], int itemRank);
// datend
Ptr *IFindDatend(Item *pHeader, char datend[], int itemRank);
// date
Ptr *IFindDate(Item *pHeader, char date[], int itemRank);

// Member
//Item�µ�Memberͷ�ڵ�:������Member����һ��
Ptr* Item_AllMember(Member* pHeader);
// id:��Member����Ѱ��
Ptr *MPtrFindId(Member *pHeader, char id[]);
//GPA��Χ����
Ptr *MPtrFindGPA(Member*pHeader,float low,float high);
// id:��Member����Ѱ��,��������ǰ�ڵ�
Member *MemFindId(Member *pHeader, char id[]);
//id:��Item�µ�����Member����Ѱ��,���������Ptr(Item,Member)Pre��
Ptr* IFind_MId(Item* IpHeader,char id[],int onum);
/*���ҽڵ�ǰָ��end***/

/*GPA����begin*/
void Get_GPA(User *pUHeader, Item *pIHeader);
/*GPA����end***/

/*Ѱ��&����begin*/
// UserId��Ptr�����أ�����1ָ���أ�����0ָ����
int JSamePtr_UserId(User* pHeader,char id[]);
// ItemId��Ptr�����أ�����1ָ���أ�����0ָ����
int JSamePtr_ItemId(Item* pHeader,char id[]);
// Ptr���������أ�����1ָ���أ�����0ָ����
int JSamePtr_Name(Ptr *pHeader, char namestr[]);
// ����Ѱ��,course��:5��ʦ 6�γ�ѧԺ 7�γ̿��Գ��� 8ĳѧԺ�γ�רҵ:��ǿ����
Ptr *NFind_Course(Item *pHeader, int opt, char name[]);
/*Ѱ��&����end***/

/*����begin*/ // pL,pRָĿ��ڵ��ǰָ��
//User:ֱ�ӽ�������
void ExchangeU(User* pL,User* pR);
//Item:ֱ�ӽ�������
void ExchangeI(Item* pL,Item* pR);
// member��������
void ExchangeMem(Member *pL, Member *pR);
// User:GPA,1��ʾ�ӵ͵��ߣ�-1��ʾ�Ӹߵ���
void OrderU(User *pHeader, int opt);
// Member:rankscore,1��ʾ�ӵ͵��ߣ�-1��ʾ�Ӹߵ���
void OrderM(Member *pHeader, int opt);
//Item�ȼ�����,1��ʾ�ӵ͵��ߣ�-1��ʾ�Ӹߵ���
void OrderItemLevel(Item* pHeader,int opt);
//Mess�ȼ�����,1��ʾ�ӵ͵��ߣ�-1��ʾ�Ӹߵ���
void OrderMess(Message*pHeader, int opt);
/*����end***/

