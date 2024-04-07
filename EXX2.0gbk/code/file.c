#include "file.h"
// ����������ļ������������

// user***begin
// �û�����д���ļ�
void toF_User(User *pHeader)
{
    if (!pHeader)
    {
        return;
    }
    pHeader = pHeader->next;
    FILE *p = fopen("UserList", "w");
    while (pHeader)
    {
        fprintf(p, "%d %s %s %s %s %s %s\n", pHeader->useRank, pHeader->name, pHeader->id, pHeader->password, pHeader->faculty, pHeader->major, pHeader->term);
        pHeader = pHeader->next;
    }
    fclose(p);
};
// �û���������ļ�
void getF_User(User *pHeader)
{
    int useRank;
    char name[51], id[51], password[51], faculty[51], major[51], term[51];
    if (!pHeader)
    {
        printf("ͷ�ڵ���Ч��\n");
        return;
    }
    FILE *p = fopen("UserList", "r");
    getc(p);
    if (feof(p))
    {
        return;
    }
    else
    {
        rewind(p);
    }
    while (!feof(p))
    {
        fscanf(p, "%d %s %s %s %s %s %s\n", &useRank, name, id, password, faculty, major, term);
        pHeader = createUser(pHeader, useRank, name, id, password, faculty, major, term, 0);
    }
    fclose(p);
};
// user***end

// item***begin
// ����������д���ļ�
void toF_Item(Item *pHeader)
{
    if (!pHeader)
    {
        return;
    }
    pHeader = pHeader->next;
    Member *pm;
    FILE *p = fopen("ItemList", "w");
    while (pHeader)
    {
        fprintf(p, "!%d %d %.4f %s %s %s %s %s\n", pHeader->itemRank, pHeader->level, pHeader->credit, pHeader->name, pHeader->id, pHeader->holder, pHeader->date, pHeader->datend);
        pm = pHeader->pMem->next;
        while (pm)
        {
            fprintf(p, "@%s %d %.4f\n", pm->id, pm->rankscore, pm->point);
            pm = pm->next;
        }
        pHeader = pHeader->next;
    }
    fclose(p);
};
// ��������������ļ�
void getF_Item(Item *pHeader)
{
    if (!pHeader)
    {
        return;
    }
    Member *pm = NULL;
    int itemRank, level;
    float credit;
    char name[51], id[51], holder[51], date[51], datend[51];
    //
    char mid[51] = "000";
    int rankscore;
    float point;
    //
    char opt;
    FILE *p = fopen("ItemList", "r");
    getc(p);
    if (feof(p))
    {
        return;
    }
    else
    {
        rewind(p);
    }
    while (!feof(p))
    {
        opt = fgetc(p);
        if (opt == '!')
        {
            fscanf(p, "%d %d %f %s %s %s %s %s\n", &itemRank, &level, &credit, name, id, holder, date, datend);
            pHeader = createItem(pHeader, itemRank, level, credit, name, id, holder, date, datend);
            pm = pHeader->pMem;
        }
        else if (opt == '@')
        {
            fscanf(p, "%s %d %.4f\n", mid, &rankscore, &point);
            pm = createMember(pm, mid, rankscore, point);
        }
    }
    fclose(p);
    return;
};
// item***end

// Message***begin
// ��Ϣ����д���ļ�
void toF_Mess(Message *pHeader)
{
    if (!pHeader)
    {
        return;
    }
    pHeader = pHeader->next;
    FILE *p = fopen("MessageList", "w");
    while (pHeader)
    {
        fprintf(p, "%d %ld %s %s\n", pHeader->messrank, pHeader->time, pHeader->id, pHeader->text);
        pHeader = pHeader->next;
    }
    fclose(p);
};
// ��Ϣ����������ļ�
void getF_Mess(Message *pHeader)
{
    int messRank = -1;
    time_t time = 0;
    char id[51], text[100];
    if (!pHeader)
    {
        printf("ͷ�ڵ���Ч��\n");
        return;
    }
    FILE *p = fopen("MessageList", "r");
    getc(p);
    if (feof(p))
    {
        return;
    }
    else
    {
        rewind(p);
    }
    while (!feof(p))
    {
        fscanf(p, "%d %ld %s %s\n", &messRank, &time, id, text);
        pHeader = createMessage(pHeader, messRank,time, id, text);
    }
    fclose(p);
};
// Message***end