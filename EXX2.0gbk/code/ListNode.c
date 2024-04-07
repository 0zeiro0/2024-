#include "ListNode.h"

/*MessageBegin*/
// ������Ϣͷ�ڵ�
Message *initMessage()
{
    Message *p = (Message *)malloc(sizeof(Message));
    if (!p)
    {
        printf("����ռ�ʧ�ܣ�\n");
        return NULL;
    }
    strcpy(p->id, "000");
    strcpy(p->text, "000");
    p->time = 0;
    p->messrank=0;
    p->next = NULL;
    return p;
}
//Ѱ��Messageβ�ڵ�
Message *MessFindTail(Message *pHeader)
{
    while (pHeader->next)
    {
        pHeader = pHeader->next;
    }
    return pHeader;
};
// ������Ϣ�ڵ㣨��Ϣ��β�ڵ㣬��ԴID,���ݡ�����<100��;Ӣ��<200�֡���
Message *createMessage(Message *pTail, int rank,time_t timeNow, char id[], char text[])
{
    Message *p = (Message *)malloc(sizeof(Message));
    if (!p)
    {
        printf("����ռ�ʧ�ܣ�\n");
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
// ɾ����Ϣ�ڵ㣨Ŀ���ǰ�ڵ㣩
void delete_Mess(Message *Pre)
{
    Message *p = Pre->next;
    Pre->next = p->next;
    free(p);
    p = NULL;
};
// ��Ϣ������գ�ͷ�ڵ㣬ָ��int��������0����ͷ�ڵ�һ����գ�����������ͷ�ڵ�
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
//�����ҵ���Ӧ���Message��ǰ�ڵ�                                   /*error//*********���ص��Ǳ��ڵ�
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

/*��ʼ��begin*/
// �����û�ͷ�ڵ�
User *initUser()
{
    User *p = (User *)malloc(sizeof(User));
    if (!p)
    {
        printf("����ռ�ʧ�ܣ�\n");
        return NULL;
    }
    p->useRank = -1;
    p->next = NULL;
    return p;
};
// ����������ͷ�ڵ�
Item *initItem()
{
    Item *p = (Item *)malloc(sizeof(Item));
    if (!p)
    {
        printf("����ռ�ʧ�ܣ�\n");
        return NULL;
    }
    p->itemRank = -1;
    p->next = NULL;
    p->pMem = NULL;
    return p;
}
// ������Աͷ�ڵ�
Member *initMember()
{
    Member *p = (Member *)malloc(sizeof(Member));
    if (!p)
    {
        printf("����ռ�ʧ�ܣ�\n");
        return NULL;
    }
    p->rankscore = -1;
    p->next = NULL;
    return p;
};
/*��ʼ��end*/

/*��������Node*begin*/
// �û����������½ڵ㲢����β�ڵ�
User *createUser(
    User *pTail,
    int useRank,       // ��ݱ����(1,����Ա;2��ʦ;3ѧ��)
    char name[51],     // �û���ʵ����
    char id[51],       // ѧ��&����&�����=�ʺ���
    char password[51], // �˺�����
    char faculty[51],  // �û�ѧԺ��ѧ������ʦ��
    char major[51],    // ѧ��(רҵ)
    char term[51],     // ѧ��(ѧ��)
    float GPA          // ѧ��(����)
)
{
    User *p = (User *)malloc(sizeof(User));
    if (!p)
    {
        printf("����ռ�ʧ�ܣ�\n");
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
    int itemRank,    // �������(4,paper;5,project;6,award;7,course)
    int level,       // ����(������Ϣ);��(�ȼ�)
    float credit,    // ����(GPA�ӷ�);�γ�(ѧ��)
    char name[51],   // ����
    char id[51],     // ����(��);          ��Ŀ(���);    ��();
    char holder[51], // ����(�ڿ�/��������);��Ŀ(ָ����ʦ);��(���쵥λ); �γ�(ѧԺ)
    char date[51],   // ����(����ʱ��);     ��Ŀ(����ʱ��);��(ʱ��);    �γ�(�Ĵο���)
    char datend[51]  // ����(����);          ��Ŀ(����ʱ��);              �γ�(רҵ)
)
{
    Item *p = (Item *)malloc(sizeof(Item));
    if (!p)
    {
        printf("����ռ�ʧ�ܣ�\n");
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
    char id[51],   // ��Ա����
    int rankscore, // ������(˳��)���γ�(����)��-1��ʾ��ʦ
    float point    // �γ�(����)
)
{
    Member *p = (Member *)malloc(sizeof(Member));
    if (!p)
    {
        printf("����ռ�ʧ�ܣ�\n");
        return NULL;
    }
    strcpy(p->id, id);
    p->rankscore = rankscore;
    p->point = point;
    p->next = NULL;
    pTail->next = p;
    return p;
};
/*ѰβFindTail*begin*/
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
/*ѰβFindTail*end**/
/*�������begin*/
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
/*�������end***/
//
/*ɾ������begin*/
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
        printf("����ռ�ʧ�ܣ�\n");
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
/*ɾ������end***/

/*����������begin*/
// ��ʼ��
Ptr *initPtr()
{
    Ptr *p = (Ptr *)malloc(sizeof(Ptr));
    if (!p)
    {
        printf("����ռ�ʧ�ܣ�\n");
        return NULL;
    }
    strcpy(p->namestr, "000");
    p->pUser = NULL;
    p->pItem = NULL;
    p->pMember = NULL;
    p->next = NULL;
    return p;
}
// Ѱβ
Ptr *PFindTail(Ptr *pHeader)
{
    while (pHeader->next)
    {
        pHeader = pHeader->next;
    }
    return pHeader;
};
// ָ�븡��������
Ptr *createPtr(Ptr *pTail, User *pU, Item *pI, Member *pM)
{
    Ptr *p = (Ptr *)malloc(sizeof(Ptr));
    if (!p)
    {
        printf("����ռ�ʧ�ܣ�\n");
        return NULL;
    }
    p->pUser = pU;
    p->pItem = pI;
    p->pMember = pM;
    p->next = NULL;
    pTail->next = p;
    return p;
};
// ���ָ���������
Ptr *createPtrName(Ptr *pTail, char namestr[])
{
    Ptr *p = (Ptr *)malloc(sizeof(Ptr));
    if (!p)
    {
        printf("����ռ�ʧ�ܣ�\n");
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
// ��� ����0��ʾ��ͷ�ڵ�һ�����
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
// �����ҵ���Ӧ���ֵ�Ptr�ڵ㣨ͷ�ڵ�Ϊ0��
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
/*����������end***/
//
/*���ҽڵ�ǰָ��begin*/
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
        strcpy(pHead->namestr, "����Ա�б�");
    }
    else if (useRank == 2)
    {
        strcpy(pHead->namestr, "��ʦ�б�");
    }
    else if (useRank == 3)
    {
        strcpy(pHead->namestr, "ѧ���б�");
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
        strcpy(pHead->namestr, "�û��б�");
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
        printf("������Ч���޴���ݣ�\n");
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
// User����:��User����Ѱ�ҷ���id��User*��ǰ�ڵ�
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
//Ptr����:��User����Ѱ�ҷ���id��User*��ǰ�ڵ����
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
        strcpy(pHead->namestr, "�����б�");
    }
    else if (itemRank == 5)
    {
        strcpy(pHead->namestr, "��Ŀ�б�");
    }
    else if (itemRank == 6)
    {
        strcpy(pHead->namestr, "���б�");
    }
    else if (itemRank == 7)
    {
        strcpy(pHead->namestr, "�γ��б�");
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
        printf("������Ч���޴������࣡\n");
        return NULL;
    }
}
// level
Ptr *IFindLevel(Item *pHeader, int level, int itemRank)
{
    Ptr *pHead = initPtr(); // itemRankȡ4Ϊ���ģ�ȡ6Ϊ����
    Ptr *pTail = pHead;
    Item *pLast = pHeader;
    if (itemRank == 4)
    {
        if (level == 1)
        {
            strcpy(pHead->namestr, "��һ�� T��:���ֿ�������:");
        }
        else if (level == 2)
        {
            strcpy(pHead->namestr, "�ڶ��� A��:Ȩ�����Ŀ�������:");
        }
        else if (level == 3)
        {
            strcpy(pHead->namestr, "������ B��:��Ҫ���Ŀ�������:");
        }
        else if (level == 4)
        {
            strcpy(pHead->namestr, "���ļ� C��:һ����Ŀ�������:");
        }
        else if (level == 5)
        {
            strcpy(pHead->namestr, "���弶 D��:һ�㹫����������:");
        }
        else if (level == 6)
        {
            strcpy(pHead->namestr, "������ E��:���޹�����������:");
        }
        else if (level == 7)
        {
            strcpy(pHead->namestr, "���߼� ���Ҽ��ڿ�:");
        }
        else if (level == 8)
        {
            strcpy(pHead->namestr, "�ڰ˼� ʡ���ڿ�:");
        }
        else if (level == 9)
        {
            strcpy(pHead->namestr, "�ھż� �����ڿ�:");
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
            printf("������Ч���޴����ĵȼ���\n");
            return NULL;
        }
    }
    if (itemRank == 6)
    {
        if (level == 1)
        {
            strcpy(pHead->namestr, "�صȽ�");
        }
        else if (level == 2)
        {
            strcpy(pHead->namestr, "һ�Ƚ�");
        }
        else if (level == 3)
        {
            strcpy(pHead->namestr, "���Ƚ�");
        }
        else if (level == 4)
        {
            strcpy(pHead->namestr, "���Ƚ�");
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
            printf("������Ч���޴˵ȼ���\n");
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
        strcpy(pHead->namestr, "���������������");
    }
    else if (itemRank == 5)
    {
        strcpy(pHead->namestr, "��Ŀ�����������");
    }
    else if (itemRank == 6)
    {
        strcpy(pHead->namestr, "�������������");
    }
    else if (itemRank == 7)
    {
        strcpy(pHead->namestr, "�γ������������");
    }
    pHeader = pHeader->next;
    if (itemRank == -1)
    { //-1�������������
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
//Ptr����:��Item����Ѱ�ҷ���id��Item*��ǰ�ڵ����
Ptr *IPtrFindId(Item *pHeader, char id[], int itemRank)
{
    Ptr *pHead = initPtr();
    Ptr *pTail = pHead;
    Item *pLast = pHeader;
    if (itemRank == 4)
    {
        strcpy(pHead->namestr, "���������������");
    }
    else if (itemRank == 5)
    {
        strcpy(pHead->namestr, "��Ŀ�����������");
    }
    else if (itemRank == 6)
    {
        strcpy(pHead->namestr, "�������������");
    }
    else if (itemRank == 7)
    {
        strcpy(pHead->namestr, "�γ������������");
    }
    pHeader = pHeader->next;
    if (itemRank == -1)
    { //-1�������������
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
// Item����:��Item����Ѱ�ҷ���id��Item��ǰ�ڵ�ָ��
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
        strcpy(pHead->namestr, "���������������");
    }
    else if (itemRank == 5)
    {
        strcpy(pHead->namestr, "��Ŀ�����������");
    }
    else if (itemRank == 6)
    {
        strcpy(pHead->namestr, "�������������");
    }
    else if (itemRank == 7)
    {
        strcpy(pHead->namestr, "�γ������������");
    }
    pHeader = pHeader->next;
    if (itemRank == -1)
    { //-1�������������
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
        strcpy(pHead->namestr, "���������������");
    }
    else if (itemRank == 5)
    {
        strcpy(pHead->namestr, "��Ŀ�����������");
    }
    else if (itemRank == 6)
    {
        strcpy(pHead->namestr, "�������������");
    }
    else if (itemRank == 7)
    {
        strcpy(pHead->namestr, "�γ��б�");
    }
    pHeader = pHeader->next;
    if (itemRank == -1)
    { //-1�������������
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
        strcpy(pHead->namestr, "���������������");
    }
    else if (itemRank == 5)
    {
        strcpy(pHead->namestr, "��Ŀ�����������");
    }
    else if (itemRank == 6)
    {
        strcpy(pHead->namestr, "�������������");
    }
    else if (itemRank == 7)
    {
        strcpy(pHead->namestr, "�γ������������");
    }
    pHeader = pHeader->next;
    if (itemRank == -1)
    { //-1�������������
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
//Item�µ�Memberͷ�ڵ�:������Member����һ��
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
// id:��Member����Ѱ��
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
// id:��Member����Ѱ��,��������ǰ�ڵ�
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
// id:��Item�µ�����Member����Ѱ��,���������Ptr(Item,Member)Pre��(onum,-1ȫ��,4����,5��Ŀ,6����,7�γ�)
Ptr *IFind_MId(Item *IpHeader, char id[], int onum)
{
    if (!IpHeader)
    {
        printf("��Ŀ��ͷ�ڵ���Ч�������ԣ�\n");
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
// GPA��Χ����
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
/*���ҽڵ�ǰָ��end***/

/*GPA����begin*/
void Get_GPA(User *pUHeader, Item *pIHeader)
{
    if (!pUHeader || !pIHeader)
    {
        printf("ͷ�ڵ���Ч������ʧ�ܣ�\n");
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
/*GPA����end***/

/*Ѱ��&����begin*/
// UserId��Ptr�����أ�����1ָ���أ�����0ָ����
int JSamePtr_UserId(User* pHeader, char id[])
{
    if (!pHeader)
    {
        printf("������ͷָ����Ч������ʧ��!\n");
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
// ItemId��Ptr�����أ�����1ָ���أ�����0ָ����
int JSamePtr_ItemId(Item *pHeader, char id[])
{
    if (!pHeader)
    {
        printf("������ͷָ����Ч������ʧ��!\n");
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
// Ptr���������أ�����1ָ���أ�����0ָ����
int JSamePtr_Name(Ptr *pHeader, char namestr[])
{
    if (!pHeader)
    {
        printf("������ͷָ����Ч������ʧ��!\n");
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
// ����Ѱ��,course��:5��ʦ 6�γ�ѧԺ 7�γ̿��Գ��� 8ĳѧԺ�γ�רҵ:��ǿ����
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
/*Ѱ��&����end***/

/*����begin*/ // pL,pRָĿ��ڵ��ǰָ��
//User:ֱ�ӽ�������(preL,preR)
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
//Item:ֱ�ӽ�������(preL,preR)
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
// member��������(preL,preR)
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
//Message����(preL,preR)
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
// User:GPA,1��ʾ�ӵ͵��ߣ�-1��ʾ�Ӹߵ���(GPA-2��ʾ����Ա,-1��ʾ��ʦ,>=0��ʾѧ��)
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
//Member����:rankscore,1��ʾ�ӵ͵��ߣ�-1��ʾ�Ӹߵ���
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
// �γ�Member����:rankscore,1��ʾ�ӵ͵��ߣ�-1��ʾ�Ӹߵ���
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
// Item�ȼ�����,1��ʾ�ӵ͵��ߣ�-1��ʾ�Ӹߵ���
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
//Mess�ȼ�����,1��ʾ�ӵ͵��ߣ�-1��ʾ�Ӹߵ���
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
/*����end***/
