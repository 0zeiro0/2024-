#include "ListNode.h"

/*MessageBegin*/
// 创建消息头节点
Message *initMessage()
{
    Message *p = (Message *)malloc(sizeof(Message));
    if (!p)
    {
        printf("申请空间失败！\n");
        return NULL;
    }
    strcpy(p->id, "000");
    strcpy(p->text, "000");
    p->time = 0;
    p->messrank=0;
    p->next = NULL;
    return p;
}
//寻找Message尾节点
Message *MessFindTail(Message *pHeader)
{
    while (pHeader->next)
    {
        pHeader = pHeader->next;
    }
    return pHeader;
};
// 创建消息节点（消息链尾节点，来源ID,内容【中文<100字;英文<200字】）
Message *createMessage(Message *pTail, int rank,time_t timeNow, char id[], char text[])
{
    Message *p = (Message *)malloc(sizeof(Message));
    if (!p)
    {
        printf("申请空间失败！\n");
        return NULL;
    }
    strcpy(p->id, id);
    strcpy(p->text, text);
    p->messrank = rank;
    p->next = NULL;
    pTail->next = p;
    p->time = timeNow;
    return p;
}
// 删除消息节点（目标的前节点）
void delete_Mess(Message *Pre)
{
    Message *p = Pre->next;
    Pre->next = p->next;
    free(p);
    p = NULL;
};
// 消息链表清空（头节点，指令int数）：输0即连头节点一起清空，其他数保留头节点
void clear_MessList(Message *pHeader, int opt)
{
    // ...
    if (!pHeader)
    {
        return;
    }
    Message *pNow = pHeader->next;
    Message *pNext = NULL;
    while (pNow)
    {
        pNext = pNow->next;
        free(pNow);
        pNow = pNext;
    }
    pHeader->next = NULL;
    if (opt == 0)
    {
        free(pHeader);
        pHeader = NULL;
    }
};
//遍历找到对应标号Message的前节点                                   /*error//*********返回的是本节点
Message *MessFindNum(Message *pHeader, int num)
{
    if (!pHeader)
    {
        return NULL;
    }
    if (!pHeader->next)
    {
        return NULL;
    }
    Message* pLast=NULL;
    while (num > 0 && pHeader)
    {
        pLast=pHeader;
        pHeader = pHeader->next;
        num--;
    }
    if (num == 0)
    {
        return pLast;
    }
    else
        return NULL;
}
/*MessageEnd***/

/*初始化begin*/
// 创建用户头节点
User *initUser()
{
    User *p = (User *)malloc(sizeof(User));
    if (!p)
    {
        printf("申请空间失败！\n");
        return NULL;
    }
    p->useRank = -1;
    p->next = NULL;
    return p;
};
// 创建素质类头节点
Item *initItem()
{
    Item *p = (Item *)malloc(sizeof(Item));
    if (!p)
    {
        printf("申请空间失败！\n");
        return NULL;
    }
    p->itemRank = -1;
    p->next = NULL;
    p->pMem = NULL;
    return p;
}
// 创建成员头节点
Member *initMember()
{
    Member *p = (Member *)malloc(sizeof(Member));
    if (!p)
    {
        printf("申请空间失败！\n");
        return NULL;
    }
    p->rankscore = -1;
    p->next = NULL;
    return p;
};
/*初始化end*/

/*参数创建Node*begin*/
// 用户参数创建新节点并接入尾节点
User *createUser(
    User *pTail,
    int useRank,       // 身份标记数(1,管理员;2教师;3学生)
    char name[51],     // 用户真实姓名
    char id[51],       // 学号&工号&管理号=帐号名
    char password[51], // 账号密码
    char faculty[51],  // 用户学院（学生，老师）
    char major[51],    // 学生(专业)
    char term[51],     // 学生(学期)
    float GPA          // 学生(绩点)
)
{
    User *p = (User *)malloc(sizeof(User));
    if (!p)
    {
        printf("申请空间失败！\n");
        return NULL;
    }
    p->useRank = useRank;
    strcpy(p->name, name);
    strcpy(p->id, id);
    strcpy(p->password, password);
    strcpy(p->faculty, faculty);
    strcpy(p->major, major);
    strcpy(p->term, term);
    p->next = NULL;
    pTail->next = p;
    return p;
};
// Item
Item *createItem(
    Item *pTail,
    int itemRank,    // 类别标记数(4,paper;5,project;6,award;7,course)
    int level,       // 论文(级别信息);获奖(等级)
    float credit,    // 论文(GPA加分);课程(学分)
    char name[51],   // 名称
    char id[51],     // 论文(号);          项目(编号);    获奖();
    char holder[51], // 论文(期刊/会议名称);项目(指导教师);获奖(主办单位); 课程(学院)
    char date[51],   // 论文(发表时间);     项目(立项时间);获奖(时间);    课程(哪次考试)
    char datend[51]  // 论文(卷期);          项目(结项时间);              课程(专业)
)
{
    Item *p = (Item *)malloc(sizeof(Item));
    if (!p)
    {
        printf("申请空间失败！\n");
        return NULL;
    }
    p->itemRank = itemRank;
    p->level = level;
    p->credit = credit;
    strcpy(p->name, name);
    strcpy(p->id, id);
    strcpy(p->holder, holder);
    strcpy(p->date, date);
    strcpy(p->datend, datend);
    p->next = NULL;
    pTail->next = p;
    p->pMem = initMember();
    return p;
};
// Member
Member *createMember(
    Member *pTail,
    char id[51],   // 成员姓名
    int rankscore, // 素质类(顺序)，课程(分数)：-1表示老师
    float point    // 课程(绩点)
)
{
    Member *p = (Member *)malloc(sizeof(Member));
    if (!p)
    {
        printf("申请空间失败！\n");
        return NULL;
    }
    strcpy(p->id, id);
    p->rankscore = rankscore;
    p->point = point;
    p->next = NULL;
    pTail->next = p;
    return p;
};
/*寻尾FindTail*begin*/
// User
User *UFindTail(User *pHeader)
{
    while (pHeader->next)
    {
        pHeader = pHeader->next;
    }
    return pHeader;
};
// Item
Item *IFindTail(Item *pHeader)
{
    while (pHeader->next)
    {
        pHeader = pHeader->next;
    }
    return pHeader;
};
// Member
Member *MFindTail(Member *pHeader)
{
    while (pHeader->next)
    {
        pHeader = pHeader->next;
    }
    return pHeader;
};
// Ptr
/*寻尾FindTail*end**/
/*清空链表begin*/
// User
void clear_UList(User *pHeader, int opt)
{
    // ...
    if (!pHeader)
    {
        return;
    }
    User *pNow = pHeader->next;
    User *pNext = NULL;
    while (pNow)
    {
        pNext = pNow->next;
        free(pNow);
        pNow = pNext;
    }
    pHeader->next = NULL;
};
// Item
void clear_ItemList(Item *pHeader, int opt)
{
    // ...
    if (!pHeader)
    {
        return;
    }
    Item *pNow = pHeader->next;
    Item *pNext = NULL;
    while (pNow)
    {
        pNext = pNow->next;
        free(pNow);
        pNow = pNext;
    }
    pHeader->next = NULL;
    if (opt == 0)
    {
        free(pHeader);
        pHeader = NULL;
    }
};
// Member
void clear_MemberList(Member *pHeader, int opt)
{
    // ...
    if (!pHeader)
    {
        return;
    }
    Member *pNow = pHeader->next;
    Member *pNext = NULL;
    while (pNow)
    {
        pNext = pNow->next;
        free(pNow);
        pNow = pNext;
    }
    pHeader->next = NULL;
    if (opt == 0)
    {
        free(pHeader);
        pHeader = NULL;
    }
};
/*清空链表end***/
//
/*删除链表begin*/
// User
void delete_U(User *Pre,Item* IpHeader)
{
    Ptr* ptr=IFind_MId(IpHeader,Pre->next->id,-1);
    Ptr* deptr=ptr->next;
    User *p = Pre->next;
    Pre->next = p->next;
    free(p);
    p = NULL;
    while(deptr){
        delete_M(deptr->pMember);
        deptr=deptr->next;
    }
    clear_PList(ptr,0);
    ptr=NULL;
    deptr=NULL;
};
// Item
void delete_I(Item *Pre)
{
    Item *p = Pre->next;
    if (!p)
    {
        printf("申请空间失败！\n");
        return;
    }
    Pre->next = p->next;
    p->next = NULL;
    clear_MemberList(p->pMem, 0);
    free(p);
    p = NULL;
};
// Member
void delete_M(Member *Pre)
{
    Member *p = Pre->next;
    Pre->next = p->next;
    free(p);
    p = NULL;
};
/*删除链表end***/

/*浮动链操作begin*/
// 初始化
Ptr *initPtr()
{
    Ptr *p = (Ptr *)malloc(sizeof(Ptr));
    if (!p)
    {
        printf("申请空间失败！\n");
        return NULL;
    }
    strcpy(p->namestr, "000");
    p->pUser = NULL;
    p->pItem = NULL;
    p->pMember = NULL;
    p->next = NULL;
    return p;
}
// 寻尾
Ptr *PFindTail(Ptr *pHeader)
{
    while (pHeader->next)
    {
        pHeader = pHeader->next;
    }
    return pHeader;
};
// 指针浮动链创建
Ptr *createPtr(Ptr *pTail, User *pU, Item *pI, Member *pM)
{
    Ptr *p = (Ptr *)malloc(sizeof(Ptr));
    if (!p)
    {
        printf("申请空间失败！\n");
        return NULL;
    }
    p->pUser = pU;
    p->pItem = pI;
    p->pMember = pM;
    p->next = NULL;
    pTail->next = p;
    return p;
};
// 名字浮动链创建
Ptr *createPtrName(Ptr *pTail, char namestr[])
{
    Ptr *p = (Ptr *)malloc(sizeof(Ptr));
    if (!p)
    {
        printf("申请空间失败！\n");
        return NULL;
    }
    strcpy(p->namestr, namestr);
    p->pUser = NULL;
    p->pItem = NULL;
    p->pMember = NULL;
    p->next = NULL;
    pTail->next = p;
    return p;
}
// 清空 输入0表示连头节点一起清空
Ptr *clear_PList(Ptr *pHeader, int opt)
{
    // ...
    if (!pHeader)
    {
    return NULL;
    }
    Ptr *pNow = pHeader->next;
    Ptr *pNext = NULL;
    while (pNow != NULL && pNow != (Ptr *)0xfeeefeeefeeefeee)
    {
        pNext = pNow->next;
        free(pNow);
        pNow = pNext;
    }
    pHeader->next = NULL;
    if (opt == 0)
    {
        free(pHeader);
        return NULL;
    }
    return pHeader;
};
// 遍历找到对应数字的Ptr节点（头节点为0）
Ptr *PFindNum(Ptr *pHeader, int num)
{
    if (!pHeader)
    {
        return NULL;
    }
    while (num > 0 && pHeader)
    {
        pHeader = pHeader->next;
        num--;
    }
    if (num == 0)
    {
        return pHeader;
    }
    else
        return NULL;
}
/*浮动链操作end***/
//
/*查找节点前指针begin*/
//
// User
// useRank
Ptr *UFindRank(User *pHeader, int useRank)
{
    Ptr *pHead = initPtr();
    Ptr *pTail = pHead;
    User *pLast = pHeader;
    if (useRank == 1)
    {
        strcpy(pHead->namestr, "管理员列表：");
    }
    else if (useRank == 2)
    {
        strcpy(pHead->namestr, "教师列表：");
    }
    else if (useRank == 3)
    {
        strcpy(pHead->namestr, "学生列表：");
    }
    if (useRank == 1 || useRank == 2 || useRank == 3)
    {
        pHeader = pHeader->next;
        while (pHeader)
        {
            if (pHeader->useRank == useRank)
            {
                pTail = createPtr(pTail, pLast, NULL, NULL);
            }
            pLast = pHeader;
            pHeader = pHeader->next;
        }
        return pHead;
    }
    else if (useRank == -1)
    {
        strcpy(pHead->namestr, "用户列表：");
        pHeader = pHeader->next;
        while (pHeader)
        {
            pTail = createPtr(pTail, pLast, NULL, NULL);
            pLast = pHeader;
            pHeader = pHeader->next;
        }
        return pHead;
    }
    else
    {
        printf("输入无效，无此身份！\n");
        return NULL;
    }
}
// name
Ptr *UFindName(User *pHeader, char name[])
{
    Ptr *pHead = initPtr();
    Ptr *pTail = pHead;
    User *pLast = pHeader;
    strcpy(pHead->namestr, name);
    pHeader = pHeader->next;
    while (pHeader)
    {
        if (!strcmp(pHeader->name, name))
        {
            pTail = createPtr(pTail, pLast, NULL, NULL);
        }
        pLast = pHeader;
        pHeader = pHeader->next;
    }
    return pHead;
}
// User返回:在User链中寻找符合id的User*的前节点
User* UFindId(User* pHeader,char* id){
    User *pLast = pHeader;    
    pHeader = pHeader->next;
    while (pHeader)
    {
        if (!strcmp(pHeader->id, id))
        {
            return pLast;
        }
        pLast = pHeader;
        pHeader = pHeader->next;
    }
    return NULL;
}
//Ptr返回:在User链中寻找符合id的User*的前节点的链
Ptr *UFindId_Ptr(User *pHeader, char* id)
{
    Ptr *pHead = initPtr();
    Ptr *pTail = pHead;
    User *pLast = pHeader;
    pHeader = pHeader->next;
    while (pHeader)
    {
        if (!strcmp(pHeader->id, id))
        {
            pTail = createPtr(pTail, pLast, NULL, NULL);
        }
        pLast = pHeader;
        pHeader = pHeader->next;
    }
    return pHead;
};
// major
Ptr *UFindMajor(User *pHeader, char major[])
{
    Ptr *pHead = initPtr();
    Ptr *pTail = pHead;
    User *pLast = pHeader;
    strcpy(pHead->namestr, major);
    pHeader = pHeader->next;
    while (pHeader)
    {
        if (!strcmp(pHeader->major, major))
        {
            pTail = createPtr(pTail, pLast, NULL, NULL);
        }
        pLast = pHeader;
        pHeader = pHeader->next;
    }
    return pHead;
};
// term
Ptr *UFindTerm(User *pHeader, char term[])
{
    Ptr *pHead = initPtr();
    Ptr *pTail = pHead;
    User *pLast = pHeader;
    strcpy(pHead->namestr, term);
    pHeader = pHeader->next;
    while (pHeader)
    {
        if (!strcmp(pHeader->term, term))
        {
            pTail = createPtr(pTail, pLast, NULL, NULL);
        }
        pLast = pHeader;
        pHeader = pHeader->next;
    }
    return pHead;
};
//

// Item
// itemRank
Ptr *IFindRank(Item *pHeader, int itemRank)
{
    Ptr *pHead = initPtr();
    Ptr *pTail = pHead;
    Item *pLast = pHeader;
    if (itemRank == 4)
    {
        strcpy(pHead->namestr, "论文列表：");
    }
    else if (itemRank == 5)
    {
        strcpy(pHead->namestr, "项目列表：");
    }
    else if (itemRank == 6)
    {
        strcpy(pHead->namestr, "获奖列表：");
    }
    else if (itemRank == 7)
    {
        strcpy(pHead->namestr, "课程列表：");
    }
    //
    if (itemRank == 4 || itemRank == 5 || itemRank == 6 || itemRank == 7)
    {
        pHeader = pHeader->next;
        while (pHeader)
        {
            if (pHeader->itemRank == itemRank)
            {
                pTail = createPtr(pTail, NULL, pLast, NULL);
            }
            pLast = pHeader;
            pHeader = pHeader->next;
        }
        return pHead;
    }
    else if (itemRank == -1)
    {
        pHeader = pHeader->next;
        while (pHeader)
        {
            pTail = createPtr(pTail, NULL, pLast, NULL);
            pLast = pHeader;
            pHeader = pHeader->next;
        }
        return pHead;
    }
    else
    {
        printf("输入无效，无此素质类！\n");
        return NULL;
    }
}
// level
Ptr *IFindLevel(Item *pHeader, int level, int itemRank)
{
    Ptr *pHead = initPtr(); // itemRank取4为论文，取6为奖项
    Ptr *pTail = pHead;
    Item *pLast = pHeader;
    if (itemRank == 4)
    {
        if (level == 1)
        {
            strcpy(pHead->namestr, "第一级 T类:特种刊物论文:");
        }
        else if (level == 2)
        {
            strcpy(pHead->namestr, "第二级 A类:权威核心刊物论文:");
        }
        else if (level == 3)
        {
            strcpy(pHead->namestr, "第三级 B类:重要核心刊物论文:");
        }
        else if (level == 4)
        {
            strcpy(pHead->namestr, "第四级 C类:一般核心刊物论文:");
        }
        else if (level == 5)
        {
            strcpy(pHead->namestr, "第五级 D类:一般公开刊物论文:");
        }
        else if (level == 6)
        {
            strcpy(pHead->namestr, "第六级 E类:受限公开刊物论文:");
        }
        else if (level == 7)
        {
            strcpy(pHead->namestr, "第七级 国家级内刊:");
        }
        else if (level == 8)
        {
            strcpy(pHead->namestr, "第八级 省级内刊:");
        }
        else if (level == 9)
        {
            strcpy(pHead->namestr, "第九级 区级内刊:");
        }
        if ((level >= 1 && level <= 9))
        {
            pHeader = pHeader->next;
            while (pHeader)
            {
                if (pHeader->level == level && pHeader->itemRank == itemRank)
                {
                    pTail = createPtr(pTail, NULL, pLast, NULL);
                }
                pLast = pHeader;
                pHeader = pHeader->next;
            }
            return pHead;
        }
        else
        {
            printf("输入无效，无此论文等级！\n");
            return NULL;
        }
    }
    if (itemRank == 6)
    {
        if (level == 1)
        {
            strcpy(pHead->namestr, "特等奖");
        }
        else if (level == 2)
        {
            strcpy(pHead->namestr, "一等奖");
        }
        else if (level == 3)
        {
            strcpy(pHead->namestr, "二等奖");
        }
        else if (level == 4)
        {
            strcpy(pHead->namestr, "三等奖");
        }
        if ((level >= 1 && level <= 4))
        {
            pHeader = pHeader->next;
            while (pHeader)
            {
                if (pHeader->level == level && pHeader->level == itemRank)
                {
                    pTail = createPtr(pTail, NULL, pLast, NULL);
                }
                pLast = pHeader;
                pHeader = pHeader->next;
            }
            return pHead;
        }
        else
        {
            printf("输入无效，无此等级！\n");
            clear_PList(pHead, 0);
            return NULL;
        }
    }
}
// name
Ptr *IFindName(Item *pHeader, char name[], int itemRank)
{
    Ptr *pHead = initPtr();
    Ptr *pTail = pHead;
    Item *pLast = pHeader;
    if (itemRank == 4)
    {
        strcpy(pHead->namestr, "论文类搜索结果：");
    }
    else if (itemRank == 5)
    {
        strcpy(pHead->namestr, "项目类搜索结果：");
    }
    else if (itemRank == 6)
    {
        strcpy(pHead->namestr, "获奖类搜索结果：");
    }
    else if (itemRank == 7)
    {
        strcpy(pHead->namestr, "课程类搜索结果：");
    }
    pHeader = pHeader->next;
    if (itemRank == -1)
    { //-1不区分类别搜索
        while (pHeader)
        {
            if (!strcmp(pHeader->name, name))
            {
                pTail = createPtr(pTail, NULL, pLast, NULL);
            }
            pLast = pHeader;
            pHeader = pHeader->next;
        }
    }
    else
    {
        while (pHeader)
        {
            if (!strcmp(pHeader->name, name) && pHeader->itemRank == itemRank)
            {
                pTail = createPtr(pTail, NULL, pLast, NULL);
            }
            pLast = pHeader;
            pHeader = pHeader->next;
        }
    }
    return pHead;
}
//Ptr返回:在Item链中寻找符合id的Item*的前节点的链
Ptr *IPtrFindId(Item *pHeader, char id[], int itemRank)
{
    Ptr *pHead = initPtr();
    Ptr *pTail = pHead;
    Item *pLast = pHeader;
    if (itemRank == 4)
    {
        strcpy(pHead->namestr, "论文类搜索结果：");
    }
    else if (itemRank == 5)
    {
        strcpy(pHead->namestr, "项目类搜索结果：");
    }
    else if (itemRank == 6)
    {
        strcpy(pHead->namestr, "获奖类搜索结果：");
    }
    else if (itemRank == 7)
    {
        strcpy(pHead->namestr, "课程类搜索结果：");
    }
    pHeader = pHeader->next;
    if (itemRank == -1)
    { //-1不区分类别搜索
        while (pHeader)
        {
            if (!strcmp(pHeader->id, id))
            {
                pTail = createPtr(pTail, NULL, pLast, NULL);
            }
            pLast = pHeader;
            pHeader = pHeader->next;
        }
    }
    else
    {
        while (pHeader)
        {
            if (!strcmp(pHeader->id, id) && pHeader->itemRank == itemRank)
            {
                pTail = createPtr(pTail, NULL, pLast, NULL);
            }
            pLast = pHeader;
            pHeader = pHeader->next;
        }
    }
    return pHead;
};
// Item返回:在Item链中寻找符合id的Item的前节点指针
Item* IFindId(Item* pHeader,char* id){
    Item *pLast = pHeader;
    pHeader = pHeader->next;
    while (pHeader)
    {
        if (!strcmp(pHeader->id, id))
        {
            return pLast;
        }
        pLast = pHeader;
        pHeader = pHeader->next;
    }
    return NULL;
}
// holder
Ptr *IFindHolder(Item *pHeader, char holder[], int itemRank)
{
    Ptr *pHead = initPtr();
    Ptr *pTail = pHead;
    Item *pLast = pHeader;
    if (itemRank == 4)
    {
        strcpy(pHead->namestr, "论文类搜索结果：");
    }
    else if (itemRank == 5)
    {
        strcpy(pHead->namestr, "项目类搜索结果：");
    }
    else if (itemRank == 6)
    {
        strcpy(pHead->namestr, "获奖类搜索结果：");
    }
    else if (itemRank == 7)
    {
        strcpy(pHead->namestr, "课程类搜索结果：");
    }
    pHeader = pHeader->next;
    if (itemRank == -1)
    { //-1不区分类别搜索
        while (pHeader)
        {
            if (!strcmp(pHeader->holder, holder))
            {
                pTail = createPtr(pTail, NULL, pLast, NULL);
            }
            pLast = pHeader;
            pHeader = pHeader->next;
        }
    }
    else
    {
        while (pHeader)
        {
            if (!strcmp(pHeader->holder, holder) && pHeader->itemRank == itemRank)
            {
                pTail = createPtr(pTail, NULL, pLast, NULL);
            }
            pLast = pHeader;
            pHeader = pHeader->next;
        }
    }
    return pHead;
};
// datend
Ptr *IFindDatend(Item *pHeader, char* datend, int itemRank)
{
    Ptr *pHead = initPtr();
    Ptr *pTail = pHead;
    Item *pLast = pHeader;
    if (itemRank == 4)
    {
        strcpy(pHead->namestr, "论文类搜索结果：");
    }
    else if (itemRank == 5)
    {
        strcpy(pHead->namestr, "项目类搜索结果：");
    }
    else if (itemRank == 6)
    {
        strcpy(pHead->namestr, "获奖类搜索结果：");
    }
    else if (itemRank == 7)
    {
        strcpy(pHead->namestr, "课程列表：");
    }
    pHeader = pHeader->next;
    if (itemRank == -1)
    { //-1不区分类别搜索
        while (pHeader)
        {
            if (!strcmp(pHeader->datend, datend))
            {
                pTail = createPtr(pTail, NULL, pLast, NULL);
            }
            pLast = pHeader;
            pHeader = pHeader->next;
        }
    }
    else
    {
        while (pHeader)
        {
            if (!strcmp(pHeader->datend, datend) && pHeader->itemRank == itemRank)
            {
                pTail = createPtr(pTail, NULL, pLast, NULL);
            }
            pLast = pHeader;
            pHeader = pHeader->next;
        }
    }
    return pHead;
};
// date
Ptr *IFindDate(Item *pHeader, char date[], int itemRank)
{
    Ptr *pHead = initPtr();
    Ptr *pTail = pHead;
    Item *pLast = pHeader;
    if (itemRank == 4)
    {
        strcpy(pHead->namestr, "论文类搜索结果：");
    }
    else if (itemRank == 5)
    {
        strcpy(pHead->namestr, "项目类搜索结果：");
    }
    else if (itemRank == 6)
    {
        strcpy(pHead->namestr, "获奖类搜索结果：");
    }
    else if (itemRank == 7)
    {
        strcpy(pHead->namestr, "课程类搜索结果：");
    }
    pHeader = pHeader->next;
    if (itemRank == -1)
    { //-1不区分类别搜索
        while (pHeader)
        {
            if (!strcmp(pHeader->date, date))
            {
                pTail = createPtr(pTail, NULL, pLast, NULL);
            }
            pLast = pHeader;
            pHeader = pHeader->next;
        }
    }
    else
    {
        while (pHeader)
        {
            if (!strcmp(pHeader->date, date) && pHeader->itemRank == itemRank)
            {
                pTail = createPtr(pTail, NULL, pLast, NULL);
            }
            pLast = pHeader;
            pHeader = pHeader->next;
        }
    }
    return pHead;
};

/*Member*/
//Item下的Member头节点:由所有Member生成一链
Ptr* Item_AllMember(Member* pHeader){
    Ptr *pHead = initPtr();
    Ptr *pTail = pHead;
    Member *pLast = pHeader;
    pHeader = pHeader->next;
    while (pHeader)
    {
        pTail = createPtr(pTail, NULL, NULL, pLast);
        pLast = pHeader;
        pHeader = pHeader->next;
    }
    return pHead;    
}
// id:在Member链中寻找
Ptr *MPtrFindId(Member *pHeader, char id[])
{
    Ptr *pHead = initPtr();
    Ptr *pTail = pHead;
    Member *pLast = pHeader;
    pHeader = pHeader->next;
    while (pHeader)
    {
        if (!strcmp(pHeader->id, id))
        {
            pTail = createPtr(pTail, NULL, NULL, pLast);
        }
        pLast = pHeader;
        pHeader = pHeader->next;
    }
    return pHead;
}
// id:在Member链中寻找,并返回其前节点
Member *MemFindId(Member *pHeader, char id[])
{
    if (!pHeader)
    {
        return 0;
    }
    int i = 0;
    Member *pLast = pHeader;
    pHeader = pHeader->next;
    while (pHeader)
    {
        if (!strcmp(pHeader->id, id))
        {
            return pLast;
        }
        pLast = pHeader;
        pHeader = pHeader->next;
    }
    return NULL;
}
// id:在Item下的所有Member链中寻找,返回有其的Ptr(Item,Member)Pre链(onum,-1全局,4论文,5项目,6奖项,7课程)
Ptr *IFind_MId(Item *IpHeader, char id[], int onum)
{
    if (!IpHeader)
    {
        printf("项目类头节点无效，请重试！\n");
        return NULL;
    }
    Ptr *pHead = initPtr();
    Ptr *pTail = pHead;
    Item *pLast = IpHeader;
    IpHeader = IpHeader->next;
    if (onum == -1)
    {
        while (IpHeader)
        {
            if (MemFindId(IpHeader->pMem, id))
            {
                pTail = createPtr(pTail, NULL, pLast, MemFindId(IpHeader->pMem, id));
            }
            pLast = IpHeader;
            IpHeader = IpHeader->next;
        }
        return pHead;
    }
    else
    {
        while (IpHeader)
        {
            if (IpHeader->itemRank == onum && MemFindId(IpHeader->pMem, id))
            {
                pTail = createPtr(pTail, NULL, pLast, MemFindId(IpHeader->pMem, id));
            }
            pLast = IpHeader;
            IpHeader = IpHeader->next;
        }
        return pHead;
    }
}
// GPA范围查找
Ptr *MFindGPA(Member *pHeader, float low, float high)
{
    Ptr *pHead = initPtr();
    Ptr *pTail = pHead;
    Member *pLast = pHeader;
    pHeader = pHeader->next;
    while (pHeader)
    {
        if (pHeader->point >= low && pHeader->point <= high)
        {
            pTail = createPtr(pTail, NULL, NULL, pLast);
        }
        pLast = pHeader;
        pHeader = pHeader->next;
    }
    return pHead;
};
/*查找节点前指针end***/

/*GPA计算begin*/
void Get_GPA(User *pUHeader, Item *pIHeader)
{
    if (!pUHeader || !pIHeader)
    {
        printf("头节点无效，计算失败！\n");
        return;
    }
    float sum = 0;
    float creditsum = 0;
    Item *p = pIHeader->next;
    pUHeader=pUHeader->next;
    while (pUHeader)
    {
        sum = 0;
        creditsum = 0;
        p = pIHeader->next;
        if(pUHeader->useRank==1){
            pUHeader->GPA=-2;
        }        
        if(pUHeader->useRank==2){
            pUHeader->GPA=-1;
        }
        if (pUHeader->useRank == 3)
        {
            while (p)
            {
                if (p->itemRank == 7)
                {
                    Ptr *ptrhead = MPtrFindId(p->pMem, pUHeader->id);
                    if (ptrhead->next)
                    {
                        sum += (ptrhead->next->pMember->point) * (p->credit);
                        creditsum += p->credit;
                    }
                    clear_PList(ptrhead, 0);
                }
                p = p->next;
            }
            pUHeader->GPA = (creditsum == 0 ? 0 : (sum / creditsum));
        }
        pUHeader = pUHeader->next;
    }
    return;
}
/*GPA计算end***/

/*寻名&查重begin*/
// UserId的Ptr链查重，返回1指无重，返回0指有重
int JSamePtr_UserId(User* pHeader, char id[])
{
    if (!pHeader)
    {
        printf("名字链头指针无效，查重失败!\n");
        return -1;
    }
    pHeader = pHeader->next;
    while (pHeader)
    {
        if (!strcmp(pHeader->id , id))
        {
            return 0;
        }
        pHeader = pHeader->next;
    }
    return 1;
}
// ItemId的Ptr链查重，返回1指无重，返回0指有重
int JSamePtr_ItemId(Item *pHeader, char id[])
{
    if (!pHeader)
    {
        printf("名字链头指针无效，查重失败!\n");
        return -1;
    }
    pHeader = pHeader->next;
    while (pHeader)
    {
        if (!strcmp(pHeader->id , id))
        {
            return 0;
        }
        pHeader = pHeader->next;
    }
    return 1;
}
// Ptr名字链查重，返回1指无重，返回0指有重
int JSamePtr_Name(Ptr *pHeader, char namestr[])
{
    if (!pHeader)
    {
        printf("名字链头指针无效，查重失败!\n");
        return -1;
    }
    pHeader = pHeader->next;
    while (pHeader)
    {
        if (!strcmp(pHeader->namestr,namestr))
        {
            return 0;
        }
        pHeader = pHeader->next;
    }
    return 1;
}
// 除重寻名,course类:5教师 6课程学院 7课程考试场次 8某学院课程专业:加强功能
Ptr *NFind_Course(Item *pHeader, int opt, char name[])
{
    Ptr *pHead = initPtr();
    Ptr *pTail = pHead;
    pHeader = pHeader->next;
    if (opt == 5)
    {
        while (pHeader)
        {
            if (JSamePtr_Name(pHead, pHeader->id) && (!strcmp(pHeader->holder, name)))
            {
                pTail = createPtrName(pTail, pHeader->id);
            }
            pHeader = pHeader->next;
        }
    }
    if (opt == 6)
    {
        while (pHeader)
        {
            if (JSamePtr_Name(pHead, pHeader->holder) && pHeader->itemRank == 7)
            {
                pTail = createPtrName(pTail, pHeader->holder);
            }
            pHeader = pHeader->next;
        }
    }
    else if (opt == 7)
    {
        while (pHeader)
        {
            if (JSamePtr_Name(pHead, pHeader->date) && pHeader->itemRank == 7)
            {
                pTail = createPtrName(pTail, pHeader->date);
            }
            pHeader = pHeader->next;
        }
    }
    else if (opt == 8)
    {
        while (pHeader)
        {
            if (JSamePtr_Name(pHead, pHeader->datend) && (!strcmp(pHeader->holder, name)) && pHeader->itemRank == 7)
            {
                pTail = createPtrName(pTail, pHeader->datend);
            }
            pHeader = pHeader->next;
        }
    }
    return pHead;
}
/*寻名&查重end***/

/*排序begin*/ // pL,pR指目标节点的前指针
//User:直接交换函数(preL,preR)
void ExchangeU(User* pL,User* pR){
    User *temp = NULL;
    if (pL->next == pR)
    {
        pL->next = pR->next;
        pR->next = pL->next->next;
        pL->next->next = pR;
    }
    else
    {
        temp = pL->next->next;
        pL->next->next = pR->next->next;
        pR->next->next = temp;
        //
        temp = pL->next;
        pL->next = pR->next;
        pR->next = temp;
    }
}
//Item:直接交换函数(preL,preR)
void ExchangeI(Item* pL,Item* pR){
    Item *temp = NULL;
    if (pL->next == pR)
    {
        pL->next = pR->next;
        pR->next = pL->next->next;
        pL->next->next = pR;
    }
    else
    {
        temp = pL->next->next;
        pL->next->next = pR->next->next;
        pR->next->next = temp;
        //
        temp = pL->next;
        pL->next = pR->next;
        pR->next = temp;
    }    
}
// member交换函数(preL,preR)
void ExchangeMem(Member *pL, Member *pR)
{
    Member *temp = NULL;
    if (pL->next == pR)
    {
        pL->next = pR->next;
        pR->next = pL->next->next;
        pL->next->next = pR;
    }
    else
    {
        temp = pL->next->next;
        pL->next->next = pR->next->next;
        pR->next->next = temp;
        //
        temp = pL->next;
        pL->next = pR->next;
        pR->next = temp;
    }
};
//Message交换(preL,preR)
void ExchangeMess(Message *pL, Message *pR)
{
    Message *temp = NULL;
    if (pL->next == pR)
    {
        pL->next = pR->next;
        pR->next = pL->next->next;
        pL->next->next = pR;
    }
    else
    {
        temp = pL->next->next;
        pL->next->next = pR->next->next;
        pR->next->next = temp;
        //
        temp = pL->next;
        pL->next = pR->next;
        pR->next = temp;
    }
};
// User:GPA,1表示从低到高，-1表示从高到低(GPA-2表示管理员,-1表示教师,>=0表示学生)
void OrderU(User *pHeader, int opt)
{
    User* pL=NULL;
    User* pR=NULL;
    if (!pHeader || !pHeader->next)
    {
        return;
    }
    else if (!pHeader->next->next)
    {
        return;
    }
    int i = 1;
    if (opt == 1)
    {
        while (i)
        {
            i = 0;
            pL = pHeader;
            pR = pHeader->next;
            while (pR&&pR->next)  //right fix
            {
                if ((pL->next->GPA) > (pR->next->GPA)) 
                {
                    ExchangeU(pL, pR);
                    i = 1;
                }
                pR = pR->next;
                pL = pL->next;
            }
        }
    }
    else if (opt = -1)
    {
        while (i)
        {
            i = 0;
            pL = pHeader;
            pR = pHeader->next;
            while (pR&&pR->next)
            {
                if ((pL->next->GPA) < (pR->next->GPA))
                {
                    ExchangeU(pL, pR);
                    i = 1;
                }
                pR = pR->next;
                pL = pL->next;
            }
        }
    }
};
//Member排序:rankscore,1表示从低到高，-1表示从高到低
void OrderM(Member *pHeader, int opt)
{
    if (!pHeader || !pHeader->next)
    {
        return;
    }
    else if (!pHeader->next->next)
    {
        return;
    }
    Member *pL = NULL;
    Member *pR = NULL;
    int i = 1;
    if (opt == 1)
    {
        while (i)
        {
            i = 0;
            pL = pHeader;
            pR = pHeader->next;
            while (pR&&pR->next)
            {
                if ((pL->next->rankscore) > (pR->next->rankscore))
                {
                    ExchangeMem(pL, pR);
                    i = 1;
                }
                pR = pR->next;
                pL = pL->next;
            }
        }
    }
    else if (opt == -1)
    {
        while (i)
        {
            i = 0;
            pL = pHeader;
            pR = pHeader->next;
            while (pR&&pR->next)
            {
                if ((pL->next->rankscore) < (pR->next->rankscore))
                {
                    ExchangeMem(pL, pR);
                    i = 1;
                }
                pR = pR->next;
                pL = pL->next;
            }
        }
    };
}
// 课程Member排序:rankscore,1表示从低到高，-1表示从高到低
void OrderCourseM(Member *pHeader, int opt)
{
    if (!pHeader || !pHeader->next)
    {
        return;
    }
    else if (!pHeader->next->next)
    {
        return;
    }
    Member *pL = NULL;
    Member *pR = NULL;
    int i = 1;
    if (opt == 1)
    {
        while (i)
        {
            i = 0;
            pL = pHeader;
            pR = pHeader->next;
            while (pR&&pR->next)
            {
                if ((((pL->next->rankscore) > (pR->next->rankscore)) || (pR->next->rankscore) == -1) && ((pL->next->rankscore) != -1))
                {
                    ExchangeMem(pL, pR);
                    i = 1;
                }
                pR = pR->next;
                pL = pL->next;
            }
        }
    }
    else if (opt == -1)
    {
        while (i)
        {
            i = 0;
            pL = pHeader;
            pR = pHeader->next;
            while (pR&&pR->next)
            {
                if ((((pL->next->rankscore) < (pR->next->rankscore)) || (pR->next->rankscore) == -1) && ((pL->next->rankscore) != -1))
                {
                    ExchangeMem(pL, pR);
                    i = 1;
                }
                pR = pR->next;
                pL = pL->next;
            }
        }
    };
}
// Item等级排序,1表示从低到高，-1表示从高到低
void OrderItemLevel(Item *pHeader, int opt)
{
    if (!pHeader || !pHeader->next)
    {
        return;
    }
    else if (!pHeader->next->next)
    {
        return;
    }
    Item *pL = NULL;
    Item *pR = NULL;
    int i = 1;
    if (opt == 1)
    {
        while (i)
        {
            i = 0;
            pL = pHeader;
            pR = pHeader->next;
            while (pR && pR->next)
            {
                if ((pL->next->level) > (pR->next->level))
                {
                    ExchangeI(pL, pR);
                    i = 1;
                }
                pR = pR->next;
                pL = pL->next;
            }
        }
    }
    else if (opt = -1)
    {
        while (i)
        {
            i = 0;
            pL = pHeader;
            pR = pHeader->next;
            while (pR && pR->next)
            {
                if ((pL->next->level) < (pR->next->level))
                {
                    ExchangeI(pL, pR);
                    i = 1;
                }
                pR = pR->next;
                pL = pL->next;
            }
        }
    }
};
//Mess等级排序,1表示从低到高，-1表示从高到低
void OrderMess(Message*pHeader, int opt)
{
    if (!pHeader || !pHeader->next)
    {
        return;
    }
    else if (!pHeader->next->next)
    {
        return;
    }
    Message *pL = NULL;
    Message *pR = NULL;
    int i = 1;
    if (opt == 1)
    {
        while (i)
        {
            i = 0;
            pL = pHeader;
            pR = pHeader->next;
            while (pR && pR->next)
            {
                if ((pL->next->messrank) > (pR->next->messrank))
                {
                    ExchangeMess(pL, pR);
                    i = 1;
                }
                pR = pR->next;
                pL = pL->next;
            }
        }
    }
    else if (opt = -1)
    {
        while (i)
        {
            i = 0;
            pL = pHeader;
            pR = pHeader->next;
            while (pR && pR->next)
            {
                if ((pL->next->messrank) < (pR->next->messrank))
                {
                    ExchangeMess(pL, pR);
                    i = 1;
                }
                pR = pR->next;
                pL = pL->next;
            }
        }
    }
};
/*排序end***/
