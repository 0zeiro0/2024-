#include "Menu.h"
/*ToolsBegin*/
// �̶���ʱ��
void halt()
{
    fflush(stdin);
    printf("�������������...\n");
    getchar();
    fflush(stdin);
}
// ����������(0������Ч���룺1�����˳��ɹ�)
void nout(int opt)
{
    if (opt == 0)
        printf("������Ч�������ԣ�\n");
    if (opt == 1)
        printf("�˳��ɹ���\n");
}
// ��ʾ��������ȡ��(���ޣ�����,��ʾ��)���û�������Ч����-1
int read(int low, int high, char tip[])
{
    int onum = -1;
    if (strcmp(tip, "000"))
    {
        printf("%s", tip);
    }
    printf("������:\n");
    scanf("%d", &onum);
    getchar();
    fflush(stdin);
    if ((onum >= low) && (onum <= high))
    {
        return onum;
    }
    else
    {
        return -1;
    }
}
// ��ʾ��һ���ַ�����ȡ��
void readStr(char *p, const char tip[])
{
    while (true)
    {
        if (strcmp(tip, "000"))
        {
            printf("%s", tip);
        }
        char str[55];
        scanf("%55s", str);
        getchar();
        fflush(stdin);
        if (strlen(str) > 50)
        {
            printf("���볤�ȹ���,������50������!\n");
            continue;
        }
        strcpy(p, str);
        return;
    }
}
//��ʾ��+���ַ�����ȡ��
void readLongStr(char *p, const char tip[])
{
    while (true)
    {
        if (strcmp(tip, "000"))
        {
            printf("%s", tip);
        }
        char str[205];
        scanf("%205s", str);
        getchar();
        fflush(stdin);
        if (strlen(str) > 200)
        {
            printf("���볤�ȹ���,������50������!\n");
            continue;
        }
        strcpy(p, str);
        return;
    }
}
// ��ʽ������(1�˺�,2����)
void pin_readStr(char *p, int opt, const char tip[])
{
    char str[31];
    while (true)
    {
        if (opt == 1)
        {
            if (strcmp(tip, "000"))
            {
                printf("%s", tip);
            }
            scanf("%31s", str);
            getchar();
            if (strlen(str) > 8)
            {
                printf("���볤�ȹ���,������8λ��������!\n");
                continue;
            }
            if (strspn(str, "0123456789") != strlen(str))
            {
                printf("����Ƿ������������Ƿ��Ϊ����!\n");
                continue;
            }
            strcpy(p, str);
            return;
        }
        else if (opt == 2)
        {
            if (strcmp(tip, "000"))
            {
                printf("%s", tip);
            }
            scanf("%51s", str);
            getchar();
            if (strlen(str) > 20)
            {
                printf("���볤�ȹ���,������20λ����!\n");
                continue;
            }
            for (int i = 0; i < 20; i++)
            {
                if (!(str[0] == '_' || isalpha(str[0])))
                {
                    printf("�ַ������Ϸ�������������!\n");
                    continue;
                }
                if (!(str[i] == '_' || isalnum(str[i])))
                {
                    printf("�ַ������Ϸ�������������!\n");
                    continue;
                }
            }
            strcpy(p, str);
            return;
        }
    }
};
//�����������(ʵ��ֵ����׼ֵ)
int sameFloat(float real,float aim){
    if((real-aim)*(real-aim)<0.1){
    return 1;
    }else {
        return 0;
    }
}
/*ToolsEnd***/

// ��ʼ����
void EnterAll(User *UpHeader, Item *IpHeader, Message *MesspHeader)
{
    while (true)
    {
        system("cls");
        printf("��ӭʹ�óɼ�����ϵͳ!\n");
        int opt = read(0, 2, "��ѡ�����Ĳ���:\n1����\n2����\n0�˳�\n");
        if (opt == -1)
        {
            nout(0);
            halt();
            continue;
        }
        else if (opt == 1)
        {
            LogIn(UpHeader, IpHeader, MesspHeader);
        }
        else if (opt == 2)
        {
            in_Mess(UpHeader,MesspHeader,2);
        }
        else if (opt == 0)
        {
            nout(1);
            return;
        }
    }
}
// ������
void LogIn(User *UpHeader, Item *IpHeader, Message *MesspHeader)
{
    char id[51], password[51], passnow[51];
    int useRank = -1;
    readStr(id, "�����������˺ţ�\n");
    User *p = UFindId(UpHeader, id);
    if (!p->next)
    {
        printf("�˺Ų����ڣ������ԣ�\n");
        halt();
        return;
    }
    strcpy(password, p->next->password);
    readStr(passnow, "�������������룺\n");
    if (strcmp(passnow, password))
    {
        printf("�ʺ������벻һ�£������ԣ�\n");
        halt();
    }
    else
    {
        useRank = p->next->useRank;
        switch (useRank)
        {
        case 1:
            ManegerMenu(UpHeader, IpHeader, MesspHeader, p->next->name);
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            printf("�˺�Ȩ����Ϣ���������ԣ�");
            return;
        }
    }
    return;
}

// ����ԱMenu���
void ManegerMenu(User *UpHeader, Item *IpHeader, Message *MpHeader, char *name)
{
    while (true)
    {
        system("cls");
        printf("����Ա%s,��ӭʹ�óɼ�����ϵͳ!\n", name);
        switch (read(0, 6, "��ѡ������鿴����Ŀ:\n1�û�����\n2���Ĺ���\n3��Ŀ����\n4�������\n5�γ̹���\n6֪ͨ����\n0�˳�\n"))
        {
        case 1:
            UserAllEnter(UpHeader,IpHeader);
            break;
        case 2:
            PaperAllEnter(UpHeader,IpHeader);
            break;
        case 3:
            ProjectAllEnter(UpHeader,IpHeader);
            break;
        case 4:
            AwardAllEnter(UpHeader,IpHeader);
            break;
        case 5:
            Course_AllLook(UpHeader,IpHeader);
            break;
        case 6:
            MessageAllEnter(UpHeader,MpHeader,1);
            break;
        case 0:
        {
            nout(1);
            return;
        }
        default:
            nout(0);
            halt();
            break;
        }
    }
}
// ��ʦMenu���
void TeacherMenu(User *UpHeader, Item *IpHeader, Message *MpHeader) {

};
// ѧ��Menu���
void StudentMenu(User *UpHeader, Item *IpHeader, Message *MpHeader)
{

}
//ȫ֪ͨ�鿴���(onum1��ʾ����Ա�鿴��2��ʾѧ���鿴)
void MessageAllEnter(User* UpHeader,Message* MpHeader,int onum){
    int max = 0;
    int choice = 0;
    int opt=-1;
    OrderMess(MpHeader,1);
    while (true)
    {
        system("cls");
        max=M_print_Mess(MpHeader,onum);
        if(onum==1){
        opt = read(0, 3, "\n��ѡ��������еĲ���:\n1�鿴����/����\n2��������\n3ɾ������/����\n0�˳���Ϣ�鿴\n");
        switch (opt)
        {
        case -1:
        {
            nout(0);
            halt();
            continue;
        }
        break;
        case 0:
        {
            nout(1);
            return;
        }
        break;
        case 1:{
            choice = read(1, max, "����������鿴����/���ߵı��\n");
            if (choice == -1)
            {
                nout(0);
                halt();
                continue;
            }
            S_print_Mess(UpHeader,MessFindNum(MpHeader,choice)->next);
            halt();
        }
        break;
        case 2:
        {
            in_Mess(UpHeader,MpHeader,onum);
            OrderMess(MpHeader,1);
            continue;
        }
        break;
        case 3:
        {
            choice = read(1, max, "����������ɾ������/���ߵı��\n");
            if (choice == -1)
            {
                nout(0);
                halt();
                continue;
            }
            delete_Mess(MessFindNum(MpHeader,choice));
            printf("ɾ���ɹ�!\n");
            halt();
        }
        }
        }
        else if(onum==2){
        opt = read(0, 3, "\n��ѡ��������еĲ���:\n1�鿴����\n2��������\n0�˳���Ϣ�鿴\n");
        switch (opt)
        {
        case -1:
        {
            nout(0);
            halt();
            continue;
        }
        break;
        case 0:
        {
            nout(1);
            return;
        }
        break;
        case 1:{
            choice = read(1, max, "����������鿴����/���ߵı��\n");
            if (choice == -1)
            {
                nout(0);
                halt();
                continue;
            }
            S_print_Mess(UpHeader,MessFindNum(MpHeader,choice)->next);
            halt();
        }
        break;
        case 2:
        {
            in_Mess(UpHeader,MpHeader,onum);
            //Order...
            continue;
        }
        break;
        }            
        }
    }     
}
// ȫ�û��������
void UserAllEnter(User *UpHeader,Item* IpHeader)
{
    int onum = -1;
    int max = 0;
    int choice = 0;
    while (true)
    {
        system("cls");
        Get_GPA(UpHeader,IpHeader);
        OrderU(UpHeader,1);
        Ptr *p = UFindRank(UpHeader, -1);
        max = M_print_RankU(p);
        onum = read(0, 3, "\n��ѡ��������еĲ���:\n1�鿴�û�\n2�½��û�\n3ɾ���û�\n0�˳��û��鿴\n");
        switch (onum)
        {
        case -1:
        {
            nout(0);
            halt();
            clear_PList(p, 0);
            continue;
        }
        break;
        case 0:
        {
            nout(1);
            clear_PList(p, 0);
            return;
        }
        break;
        case 1:
        {
            choice = read(1, max, "����������鿴�û��ı��\n");
            if(choice==-1){
                nout(0);
                halt();
                clear_PList(p,0);
                continue;
            }
            S_User(UpHeader,IpHeader,PFindNum(p, choice));
            continue;            
        }
        break;
        case 2:
        {
            in_User(UpHeader, -1);
            OrderU(UpHeader, 1);
            clear_PList(p, 0);
            continue;
        }
        break;
        case 3:
        {
            choice = read(1, max, "����������ɾ���û��ı��\n");
            if (choice == -1)
            {
                nout(0);
                halt();
                clear_PList(p, 0);
                continue;
            }
            delete_U(PFindNum(p, choice)->pUser,IpHeader);
            printf("ɾ���ɹ�!\n");
            halt();
            clear_PList(p, 0);
        }
        }
    }
}
//ȫ���Ĳ鿴���
void PaperAllEnter(User* UpHeader,Item *IpHeader)
{
    int onum = -1;
    int max = 0;
    int choice = 0;
    while (true)
    {
        system("cls");
        Ptr *p = IFindRank(IpHeader, 4);
        max = M_print_LevelI(p, 1);
        onum = read(0, 3, "\n��ѡ��������еĲ���:\n1�鿴����\n2�½�����\n3ɾ������\n0�˳����Ĳ鿴\n");
        switch (onum)
        {
        case -1:
        {
            nout(0);
            halt();
            clear_PList(p, 0);
            continue;
        }
        break;
        case 0:
        {
            nout(1);
            clear_PList(p, 0);
            return;
        }
        break;
        case 1:
        {
            choice = read(1, max, "����������鿴���ĵı��\n");
            if (choice == -1)
            {
                nout(0);
                halt();
                clear_PList(p, 0);
                continue;
            }
            S_Item(UpHeader,IpHeader,PFindNum(p, choice));
            clear_PList(p, 0);
            continue;            
        }
        break;
        case 2:
        {
            in_Item(IpHeader, 4);
            OrderItemLevel(IpHeader, 1);
            clear_PList(p, 0);
            continue;
        }
        break;
        case 3:
        {
            choice = read(1, max, "����������ɾ�����ĵı��\n");
            if (choice == -1)
            {
                nout(0);
                halt();
                clear_PList(p, 0);
                continue;
            }
            delete_I(PFindNum(p, choice)->pItem);
            printf("ɾ���ɹ�!\n");
            halt();
            clear_PList(p, 0);
        }
        }
    }
}
//ȫ��Ŀ�������
void ProjectAllEnter(User* UpHeader,Item *IpHeader)
{
    int onum = -1;
    int max = 0;
    int choice = 0;
    while (true)
    {
        system("cls");
        Ptr *p = IFindRank(IpHeader, 5);
        max = M_print_I(p);
        onum = read(0, 3, "\n��ѡ��������еĲ���:\n1�鿴��Ŀ\n2�½���Ŀ\n3ɾ����Ŀ\n0�˳���Ŀ�鿴\n");
        switch (onum)
        {
        case -1:
        {
            nout(0);
            halt();
            clear_PList(p, 0);
            continue;
        }
        break;
        case 0:
        {
            nout(1);
            clear_PList(p, 0);
            return;
        }
        break;
        case 1:
        {
            choice = read(1, max, "����������鿴��Ŀ�ı��\n");
            if (choice == -1)
            {
                nout(0);
                halt();
                clear_PList(p, 0);
                continue;
            }
            S_Item(UpHeader,IpHeader,PFindNum(p, choice));
            clear_PList(p, 0);
            continue;
        }
        break;
        case 2:
        {
            in_Item(IpHeader, 5);
            OrderItemLevel(IpHeader, 1);
            clear_PList(p, 0);
            continue;
        }
        break;
        case 3:
        {
            choice = read(1, max, "����������ɾ����Ŀ�ı��\n");
            if (choice == -1)
            {
                nout(0);
                halt();
                clear_PList(p, 0);
                continue;
            }
            delete_I(PFindNum(p, choice)->pItem);
            printf("ɾ���ɹ�!\n");
            halt();
            clear_PList(p, 0);
        }
        }
    }
}
//ȫ����������
void AwardAllEnter(User* UpHeader,Item *IpHeader)
{
    int onum = -1;
    int max = 0;
    int choice = 0;
    while (true)
    {
        system("cls");
        Ptr *p = IFindRank(IpHeader, 6);
        max = M_print_LevelI(p, 2);
        onum = read(0, 3, "\n��ѡ��������еĲ���:\n1�鿴����\n2�½�����\n3ɾ������\n0�˳�����鿴\n");
        switch (onum)
        {
        case -1:
        {
            nout(0);
            halt();
            clear_PList(p, 0);
            continue;
        }
        break;
        case 0:
        {
            nout(1);
            clear_PList(p, 0);
            return;
        }
        break;
        case 1:
        {
            choice = read(1, max, "����������鿴����ı��\n");
            if (choice == -1)
            {
                nout(0);
                halt();
                clear_PList(p, 0);
                continue;
            }
            S_Item(UpHeader,IpHeader,PFindNum(p, choice));
            clear_PList(p, 0);
            continue;
        }
        break;
        case 2:
        {
            in_Item(IpHeader,6);
            OrderItemLevel(IpHeader, 1);
            clear_PList(p, 0);
            continue;
        }
        break;
        case 3:
        {
            choice = read(1, max, "����������ɾ������ı��\n");
            if (choice == -1)
            {
                nout(0);
                halt();
                clear_PList(p, 0);
                continue;
            }
            delete_I(PFindNum(p, choice)->pItem);
            printf("ɾ���ɹ�!\n");
            halt();
            clear_PList(p, 0);
        }
        }
    }
}
// ȫ�γ̹�����
void Course_AllLook(User* UpHeader,Item *IpHeader)
{
    int onum = -1;
    int max = 0;
    int choice = 0;
    Ptr* p=NULL;
    while (true)
    {
        system("cls");
        max = M_print_Major(IpHeader,&p);
        onum = read(0, 3, "\n��ѡ��������еĲ���:\n1�鿴���רҵ�µĿγ�\n2�½��γ�\n0�˳��γ̲鿴\n");
        switch (onum)
        {
        case -1:
        {
            nout(0);
            halt();
            clear_PList(p, 0);
            continue;
        }
        break;
        case 0:
        {
            nout(1);
            clear_PList(p, 0);
            return;
        }
        break;
        case 1:
        {
            choice = read(1, max, "����������鿴רҵ�ı��\n");
            if (choice == -1)
            {
                nout(0);
                halt();
                clear_PList(p, 0);
                continue;
            }else{
            Course_Look(UpHeader,IpHeader,PFindNum(p, choice)->namestr);
            clear_PList(p, 0);
            continue;
            }
        }
        break;
        case 2:
        {
            in_Item(IpHeader, 7);
            OrderItemLevel(IpHeader, 1);
            clear_PList(p, 0);
            continue;
        }
        break;
        }
    }
}

//���û��鿴���
void S_User(User* UpHeader,Item* IpHeader,Ptr* p){
    Ptr* ptr=NULL;
    while(true){
        system("cls");
    switch (p->pUser->next->useRank)
    {
    case 1:
    {
        printf("����Ա:%s\nid��:%s\n����:%s\n", p->pUser->next->name, p->pUser->next->id,p->pUser->next->password);
        switch (read(0,3,"��ѡ�����Ĳ�����\n�޸ģ�\t1����\n\t2id��\n\t3����\n0�˳��鿴\n"))
        {
        case 1:{
            fix_U(p->pUser->next,1);
        }
            break;
        case 2:{
            fix_U(p->pUser->next,2);
        }
        break;
        case 3:{
            fix_U(p->pUser->next,3);
        }
        break;
        case 0:{
            nout(1);
            return;
        }
        default:{
            nout(0);
            halt();
            continue;
        }
            break;
        }
    }
    break;
    case 2:
    {
        printf("��ʦ:%s\nid��:%s\n����:%s\n", p->pUser->next->name, p->pUser->next->id,p->pUser->next->password);
        printf("ѧԺ:%s\n", p->pUser->next->faculty);
        switch (read(0,5,"��ѡ�����Ĳ�����\n�޸ģ�\n\t1����\n\t2����\n\t3����\n\t4ѧԺ\n5��������Ŀ��\n0�˳��鿴\n\n"))
        {
        case 1:{
            fix_U(p->pUser->next,1);
        }
            break;
        case 2:{
            fix_U(p->pUser->next,2);
        }
        break;
        case 3:{
            fix_U(p->pUser->next,3);
        }
        break;
        case 4:{
            fix_U(p->pUser->next,4);
        }
        break;
        case 5:{
            ptr = IFind_MId(IpHeader,p->pUser->next->id,-1);
            M_print_UserDone(ptr,-1,2);
            clear_PList(ptr,0);
            halt();
            continue;
        }
        break;
        case 0:{
            nout(1);
            return;
        }
        default:{
            nout(0);
            halt();
            continue;
        }
            break;
        }        
    }
    break;
    case 3:
    {
        printf("ѧ��:%s\nѧ��:%s\n����:%s\n", p->pUser->next->name, p->pUser->next->id,p->pUser->next->password);
        printf("ѧԺ:%s\n", p->pUser->next->faculty);
        printf("רҵ:%s\nѧ��:%s\n", p->pUser->next->major, p->pUser->next->term);
        printf("GPA:%.4f\n", p->pUser->next->GPA);
        switch (read(0,7,"��ѡ�����Ĳ�����\n�޸ģ�\n\t1����\n\t2����\n\t3����\n\t4ѧԺ\n\t5רҵ\n\t6ѧ��\n7��������Ŀ��\n0�˳��鿴\n"))
        {
        case 1:{
            fix_U(p->pUser->next,1);
        }
            break;
        case 2:{
            fix_U(p->pUser->next,2);
        }
        break;
        case 3:{
            fix_U(p->pUser->next,3);
        }
        break;
        case 4:{
            fix_U(p->pUser->next,4);
        }
        case 5:{
            fix_U(p->pUser->next,5);
        }
        break;
        case 6:{
            fix_U(p->pUser->next,6);
        }
        break;
        case 7:{
            ptr = IFind_MId(IpHeader,p->pUser->next->id,-1);
            M_print_UserDone(ptr,-1,3);
            clear_PList(ptr,0);
            halt();
            continue;
        }
        break;                
        break;
        case 0:{
            nout(1);
            return;
        }
        default:{
            nout(0);
            halt();
            continue;
        }
            break;
        }          
    }
    break;
    }
    OrderU(UpHeader,1);
    }
}
//���û�������鿴���
void S_User_Relate(User* UpHeader,Item* IpHeader,Ptr* p){
    
    while(true){
        system("cls");
        switch(p->pUser->next->useRank){
            case 2:{
                printf("�ý�ʦ�������Ŀ��:\n");
                M_print_UserDone(p,-1,2);
                halt();
            }
            break;
            case 3:{
                printf("��ѧ���������Ŀ��:\n");
                M_print_UserDone(p,-1,3);
                halt();
            }
            break;
            default:{
                nout(0);
                halt();
                return;
            }

        }
    }
}
//��������鿴���
void S_Item(User* UpHeader,Item* IpHeader,Ptr* p){
    while(true){
        system("cls");
    switch (p->pItem->next->itemRank)
    {
    case 4:
    {
        printf("����:%s\n���:%s\n����:%d\n", p->pItem->next->name, p->pItem->next->id,p->pItem->next->level);
        printf("�ڿ�����:%s\n����ʱ��:%s\n����:%s\n",p->pItem->next->holder,p->pItem->next->date,p->pItem->next->datend);
        printf("�ӷ�(GPA):%.4f\n",p->pItem->next->credit);
        switch (read(0,8,"��ѡ�����Ĳ�����\n�޸ģ�\n\t1����\n\t2id��\n\t3����\n\t4�����ڿ�\n\t5����ʱ��\n\t6����\n\t7�ӷ�(����)\n8�鿴��Ա\n0�˳��鿴\n"))
        {
        case 1:{
            fix_I(p->pItem->next,3);
        }
            break;
        case 2:{
            fix_I(p->pItem->next,4);
        }
        break;
        case 3:{
            fix_I(p->pItem->next,1);
        }
        break;
        case 4:{
            fix_I(p->pItem->next,5);
        }
        break;
        case 5:{
            fix_I(p->pItem->next,6);
        }
        break;
        case 6:{
            fix_I(p->pItem->next,7);
        }
        break;
        case 7:{
            fix_I(p->pItem->next,2);
        }
        break;
        case 8:{
            S_Item_Member(UpHeader,p->pItem->next,4);
        }
        break;
        case 0:{
            nout(1);
            return;
        }
        break;
        default:{
            nout(0);
            halt();
            continue;
        }
            break;
        }
    }
    break;
    case 5:{
        printf("��Ŀ:%s\n��Ŀ���:%s\n����ʱ��:%s\n����ʱ��:%s\n", p->pItem->next->name, p->pItem->next->id,p->pItem->next->date,p->pItem->next->datend);
        switch (read(0,5,"��ѡ�����Ĳ�����\n�޸ģ�\n\t1����\n\t2���\n\t3����ʱ��\n\t4����ʱ��\n5�鿴��Ա\n0�˳��鿴\n"))
        {
        case 1:{
            fix_I(p->pItem->next,1);
        }
            break;
        case 2:{
            fix_I(p->pItem->next,2);
        }
        break;
        case 3:{
            fix_I(p->pItem->next,4);
        }
        break;
        case 4:{
            fix_I(p->pItem->next,5);
        }
        break;
        case 5:{
            S_Item_Member(UpHeader,p->pItem->next,5);
        }
        break;
        case 0:{
            nout(1);
            return;
        }
        break;
        default:{
            nout(0);
            halt();
            continue;
        }
            break;
        }
    }
    break;
    case 6:{
        printf("������:%s\n������:%s\n�ȼ�:%d\n���쵥λ:%s\n��ʱ��:%s\n", p->pItem->next->name, p->pItem->next->id,p->pItem->next->level,p->pItem->next->holder,p->pItem->next->date);
        switch (read(0,5,"��ѡ�����Ĳ�����\n�޸ģ�\n\t1����\n\t2�ȼ�\n\t3���쵥λ\n\t4��ʱ��\n5�鿴��Ա\n0�˳��鿴\n"))
        {
        case 1:{
            fix_I(p->pItem->next,2);
        }
            break;
        case 2:{
            fix_I(p->pItem->next,1);
        }
        break;
        case 3:{
            fix_I(p->pItem->next,3);
        }
        break;
        case 4:{
            fix_I(p->pItem->next,4);
        }
        break;
        case 5:{
            S_Item_Member(UpHeader,p->pItem->next,6);
        }
        break;
        case 0:{
            nout(1);
            return;
        }
        break;
        default:{
            nout(0);
            halt();
            continue;
        }
            break;
        }
    }
    break;
    case 7:{
        printf("�γ�:%s\n�γ̱��:%s\nѧԺ:%s\n", p->pItem->next->name, p->pItem->next->id,p->pItem->next->holder);
        printf("ѧ��:%s\n��Ӧרҵ:%s\n�γ�ѧ��:%.4f\n",p->pItem->next->date,p->pItem->next->datend,p->pItem->next->credit);
        printf("�ӷ�(GPA):%.4f\n",p->pItem->next->credit);
        switch (read(0,7,"��ѡ�����Ĳ�����\n�޸ģ�\n\t1����\n\t2�γ̱��\n\t3ѧԺ\n\t4ѧ��\n\t5��Ӧרҵ\n\t6�γ�ѧ��\n7�鿴��Ա\n0�˳��鿴\n"))
        {
        case 1:{
            fix_I(p->pItem->next,2);
        }
            break;
        case 2:{
            fix_I(p->pItem->next,3);
        }
        break;
        case 3:{
            fix_I(p->pItem->next,4);
        }
        break;
        case 4:{
            fix_I(p->pItem->next,5);
        }
        break;
        case 5:{
            fix_I(p->pItem->next,6);
        }
        break;
        case 6:{
            fix_I(p->pItem->next,1);
        }
        break;
        case 7:{
            S_Item_Member(UpHeader,p->pItem->next,7);
        }
        break;
        case 0:{
            nout(1);
            return;
        }
        default:{
            nout(0);
            halt();
            continue;
        }
            break;
        }
    }
    break;
    }
    }
}
//����Ŀ���Ա�鿴���(opt:4����5��Ŀ6����7�γ�)
void S_Item_Member(User* UpHeader,Item* pNow,int opt){
    int onum = -1;
    int max = 0;
    int choice = 0;
    Ptr *p = NULL;
    while (true)
    {
        system("cls");
        p=Item_AllMember(pNow->pMem);
        if(opt==4){
            max=M_print_PaperMem(UpHeader,p);
        }else if(opt==5){
            max=M_print_Name(p,1);//[error]
        }else if(opt==6){
            max=M_print_Mem(UpHeader,pNow->pMem);
        }else if(opt==7){
            max=M_print_CourseMem(UpHeader,p);
        }
        onum = read(0, 2, "\n��ѡ��������еĲ���:\n1������Ա\n2ɾ����Ա\n0�˳���Ա�鿴\n");
        switch (onum)
        {
        case -1:
        {
            nout(0);
            halt();
            clear_PList(p, 0);
            continue;
        }
        break;
        case 0:
        {
            nout(1);
            clear_PList(p, 0);
            return;
        }
        break;
        case 1:
        {
            in_Member(UpHeader,pNow->pMem,opt);
            OrderM(pNow->pMem,1);
            clear_PList(p, 0);
            continue;
        }
        break;
        case 2:
        {
            choice = read(1, max, "����������ɾ����Ա�ı��\n");
            if (choice == -1)
            {
                nout(0);
                halt();
                clear_PList(p, 0);
                continue;
            }
            delete_M(PFindNum(p, choice)->pMember);
            printf("ɾ���ɹ�!\n");
            halt();
            clear_PList(p, 0);
        }
        }
    }    
}
//��רҵ�γ̲鿴��
void Course_Look(User* UpHeader,Item *pHeader, char name[])
{
    Ptr *p = NULL;
    int onum = -1;
    int max=0;
    int choice=-1;
    while (true)
    {
        system("cls");
        p = IFindDatend(pHeader, name, 7);
        max = M_print_I(p);
        onum = read(0, 3, "\n��ѡ��������еĲ���:\n1�鿴�γ�\n2�½��γ�\n3ɾ���γ�\n0�˳��γ̲鿴\n");
        switch (onum)
        {
        case -1:
        {
            nout(0);
            halt();
            clear_PList(p, 0);
            continue;
        }
        break;
        case 0:
        {
            nout(1);
            clear_PList(p, 0);
            return;
        }
        break;
        case 1:
        {
            choice = read(1, max, "����������鿴�γ̵ı��\n");
            if (choice == -1)
            {
                nout(0);
                halt();
                clear_PList(p, 0);
                continue;
            }
            S_Item(UpHeader,pHeader,PFindNum(p, choice));
            clear_PList(p, 0);
            continue;
        }
        break;
        case 2:
        {
            in_Item(pHeader, 7);
            OrderItemLevel(pHeader, 1);
            clear_PList(p, 0);
            continue;
        }
        break;
        case 3:
        {
            choice = read(1, max, "����������ɾ���γ̵ı��\n");
            if (choice == -1)
            {
                nout(0);
                halt();
                clear_PList(p, 0);
                continue;
            }
            delete_I(PFindNum(p, choice)->pItem);
            printf("ɾ���ɹ�!\n");
            halt();
            clear_PList(p, 0);
        }        
        }            
    }
}

/*���봴��Node*begin*/
// User������
User *in_User(User *UpHeader, int onum)
{
    char name[51];     // �û���ʵ����
    char id[51];       // ѧ��&����&�����=�ʺ���
    char password[51]; // �˺�����
    char faculty[51];  // �û��Ա�
    char major[51];    // ѧ��(רҵ)
    char term[51];     // ѧ��(ѧ��)
    float GPA;         // ѧ��(����)
    //
    int opt;
    int useRank;
    while (true)
    {
        system("cls");
        useRank = onum;
        if (useRank == -1)
        {
            useRank = read(0, 3, "��ѡ�����û������:\n1����Ա\n2��ʦ\n3ѧ��\n��0�˳�����\n");
            if (useRank == -1)
            {
                printf("�����Ϣ��Ч,����������!\n");
                halt();
                continue;
            }
            else if (useRank == 0)
            {
                nout(1);
                return UFindTail(UpHeader);
            }
        }
        printf("�������û�����:\n");
        scanf("%51s", name);
        getchar();
        printf("�������û�����:\n");
        scanf("%51s", id);
        getchar();
        if(UFindId(UpHeader,id)){
            printf("���û��Ѵ��ڣ�������Ч��\n");
            halt();
            return NULL;
        }
        printf("�������û�����:\n");
        scanf("%51s", password);
        getchar();
        if (useRank == 2 || useRank == 3)
        {
            printf("�������û�ѧԺ:\n");
            scanf("%51s", faculty);
            getchar();
        }
        else
        {
            strcpy(faculty, "000");
        }
        if (useRank == 3)
        {
            readStr(major, "�������û���רҵ\n");
            readStr(term, "�������û���ѧ��\n");
            GPA = 0;
        }
        else if (useRank == 1)
        {
            strcpy(major, "000");
            strcpy(term, "000");
            GPA = -2;
        }
        else if (useRank == 2)
        {
            strcpy(major, "000");
            strcpy(term, "000");
            GPA = -1;
        }
        while (true)
        {
            opt = read(0, 1, "�Ƿ񴴽�?1�� 0��\n");
            if (opt == 1)
            {
                printf("�����ɹ���\n");
                Sleep(5);
                return createUser( // �ĳ�return�䴴���ͳ�
                    UFindTail(UpHeader),
                    useRank,  // ��ݱ����(0,����Ա;1,��ʦ;2,ѧ��)
                    name,     // �û���ʵ����
                    id,       // ѧ��&����&�����=�ʺ���
                    password, // �˺�����
                    faculty,  // �û��Ա�->ѧԺ
                    major,    // ѧ��(רҵ)
                    term,     // ѧ��(ѧ��)
                    GPA);     // ѧ��(����);
            }
            else if (opt == 0)
            {
                printf("ȡ���ɹ���\n");
                Sleep(5);
                return NULL;
            }
            else
            {
                printf("������Ч,������!\n");
            }
        }
    }
};
// Item������,�û���ѡ������(-1),4����5��Ŀ6����7�γ�
Item *in_Item(Item *IpHeader, int onum)
{
    int level = -1;
    float credit = 0.0000;
    char name[51] = "000";
    char id[51] = "000";
    char holder[51] = "000";
    char date[51] = "000";
    char datend[51] = "000";
    int itemRank = -1;
    //
    int opt;
    while (true)
    {
        level = -1;
        credit = 0;
        strcpy(name, "000");
        strcpy(id, "000");
        strcpy(holder, "000");
        strcpy(date, "000");
        strcpy(datend, "000");
        system("cls");
        itemRank = onum;
        if (itemRank == -1)
        {
            int i=1;
            while (i)
            {
                system("cls");
                itemRank = read(4, 8, "�����봴��������:\n4����\n5��Ŀ\n6����\n7�γ�\n��:0�˳�����\n");
                if (itemRank == -1)
                {
                    nout(0);
                    halt();
                    continue;
                }
                else if (itemRank == 0)
                {
                    nout(1);
                    return IFindTail(IpHeader);
                }
                i=0;
            }
        }
        if (itemRank == 4)
        {
            level = read(0, 8, "���������ĵȼ���1��һ�� T�ࣺ���ֿ�������\n2�ڶ��� A�ࣺȨ�����Ŀ�������\n3������ B�ࣺ��Ҫ���Ŀ�������\n4���ļ� C�ࣺһ����Ŀ�������\n5���弶 D�ࣺһ�㹫����������\n6������ E�ࣺ���޹�����������\n7���߼� ���Ҽ��ڿ�\n8�ڰ˼� ʡ���ڿ�\n9�ھż� �����ڿ�\n");
            if (level == -1)
            {
                nout(0);
                halt();
                continue;
            }
            readStr(name, "���������ƣ�\n");
            readStr(id, "���������ĺţ�\n");
            if(IFindId(IpHeader,id)){
                printf("��������id�Ѵ��ڣ�������Ч!\n");
                halt();
                return NULL;
            }
            readStr(date, "�����뷢��ʱ�䣺\n");
            readStr(holder, "�������ڿ�/�������ƣ�\n");
            readStr(datend, "��������ڣ�\n");
            printf("���������ļӷ֣�\n");
            scanf("%f", &credit);
            getchar();
            //
        }
        else if (itemRank == 5)
        {
            readStr(name, "����������\n");
            readStr(id, "��������Ŀ��ţ�\n");
            if(IFindId(IpHeader,id)){
                printf("��������id�Ѵ��ڣ�������Ч!\n");
                halt();
                return NULL;
            }            
            readStr(date, "����������ʱ�䣺\n");
            readStr(datend, "���������ʱ�䣺\n");
        }
        else if (itemRank == 6)
        {
            level = read(0, 3, "������񽱵ȼ�:\n0�صȽ�\n1һ�Ƚ�\n2���Ƚ�\n3���Ƚ�\n") + 1;
            if (level == 0)
            {
                nout(0);
                halt();
                continue;
            }
            readStr(name, "����������\n");
            readStr(id, "������񽱱�ţ�\n");
            if(IFindId(IpHeader,id)){
                printf("��������id�Ѵ��ڣ�������Ч!\n");
                halt();
                return NULL;
            }            
            readStr(holder, "���������쵥λ��\n");
            readStr(date, "�������ʱ�䣺\n");
        }
        else if (itemRank == 7)
        { // course
            level = -1;
            readStr(name, "����������\n");
            readStr(holder, "������ѧԺ��\n");
            readStr(datend, "�������Ӧרҵ��\n");
            readStr(id,"������γ̱�ţ�\n");
            if(IFindId(IpHeader,id)){
                printf("��������id�Ѵ��ڣ�������Ч!\n");
                halt();
                return NULL;
            }            
            readStr(date, "�����뿼�Գ��Σ�\n");
            printf("������γ�ѧ��\n");
            scanf("%f", &credit);
            getchar();
        }
        else
        {
            printf("�����Ϣ����,����ʧ�ܣ�\n");
        }
        while (true)
        {
            opt = read(0, 1, "�Ƿ񴴽�?1�� 0��\n");
            if (opt == 1)
            {
                printf("�����ɹ���\n");
                return createItem( // �ĳ�return�䴴���ͳ�
                    IFindTail(IpHeader),
                    itemRank, // �������(4,paper;5,project;6,award;7,course)
                    level,    // ����(������Ϣ);��(�ȼ�)
                    credit,   // ����(GPA�ӷ�);�γ�(ѧ��)
                    name,     // ����
                    id,       // ����(��);��Ŀ(���);��();�γ�(���)
                    holder,   // ����(�ڿ�/��������);��Ŀ(ָ����ʦ);��(���쵥λ);�γ�(ѧԺ)
                    date,     // ����(����ʱ��);��Ŀ(����ʱ��);��(ʱ��);�γ�(�Ĵο���)
                    datend);  // ����(����);��Ŀ(����ʱ��);�γ�(רҵ)
                halt();
            }
            else if (opt == 0)
            {
                nout(1);
                return NULL;
            }
            else if(opt==-1)
            {
                nout(0);
                halt();
                continue;
            }
        }
    }
}
// Member������(opt4����5��Ŀ6����7�γ�)
Member *in_Member(User* UpHeader,Member *MempHeader,int itemclass)
{
    char id[51];
    int rankscore = 0;
    float point = 0;
    int onum = -1;
    int opt;
    //
    while (true)
    {
        system("cls");
        readStr(id, "�������Աid��\n");
        if(!UFindId(UpHeader,id)){
            printf("���޴��ˣ����������룡\n");
            continue;
        };
        if(MemFindId(MempHeader,id)){
        printf("�������ڴ˳�Ա�б��У�������Ч��\n");
        halt();
        continue;
        }
        onum=UFindId(UpHeader,id)->next->useRank;
        if(onum==1){
            printf("����Ա��������࣬���������룡\n");
            halt();
            continue;
        }
        if (onum == 3)
        {
            if(itemclass==5||itemclass==6){
            printf("����������˳��\n");
            scanf("%d", &rankscore);
            getchar();
            point=0;
            }else if(itemclass==4){
            printf("����������˳��\n");
            printf("0ͨѶ����1��һ����2�ڶ�����3��������...");
            scanf("%d", &rankscore);
            getchar();
            if(rankscore<0){
                nout(0);
                halt();
                return NULL;
            }
            point=0;
            }

            if(itemclass==7){
            printf("���������\n");
            scanf("%d", &rankscore);
            getchar();
            printf("�����뼨��:(0��ʾδ����)\n");
            scanf("%f", &point);
            getchar();
            }
            if(point<0){
                nout(0);
                halt();
                continue;
            }
        }
        else if (onum == 2)
        {
            if(opt==4){
            printf("������˳��\n");
            printf("0ͨѶ����1��һ����2�ڶ�����3��������...");
            scanf("%d", &rankscore);
            getchar();
            if(rankscore<0){
                nout(0);
                halt();
                return NULL;
            }            
            }else if(opt==5||opt==6||opt==7){
                rankscore=-1;
            }
            point = -1.00000f; // ���ﲻ��ʾ��Ч����ָ��ʦ
        }
        while (true)
        {
            opt = read(0, 1, "�Ƿ񴴽�?1�� 0��\n");
            if (opt == 1)
            {
                printf("�����ɹ���\n");
                halt();
                return createMember(
                    MFindTail(MempHeader),
                    id,
                    rankscore,
                    point);
            }
            else if (opt == 0)
            {
                printf("ȡ���ɹ���\n");
                halt();
                return NULL;
            }
            else
            {
                nout(0);
                halt();
                continue;
            }
        }
    }
}
// ���ߴ�������������Ϣβ�ڵ㣩onum1��ʾ����Ա2��ʾһ���û�
Message *in_Mess(User* UpHeader,Message *MesspHeader, int onum)
{
    int opt;
    int messrank=0;
    time_t timeNow=0;
    char text[201];
    char id[10];
    while (true)
    {
        system("cls");
        if(onum==1){
            messrank=1;
        pin_readStr(id, 1,"����������id��\n");
        if (!UFindId(UpHeader, id))
        {
        printf("�˺Ų����ڣ������ԣ�\n");
        halt();
        return NULL;
        }
        readLongStr(text, "�����빫������\n");            
        }
        if(onum==2){
            messrank=2;
        pin_readStr(id, 1,"����������id��\n");
        if (!UFindId(UpHeader, id))
        {
        printf("�˺Ų����ڣ������ԣ�\n");
        halt();
        return NULL;
        }
        readLongStr(text, "��������������\n");            
        }

        while (true)
        {
            opt = read(0, 1, "�Ƿ񴴽�?1�� 0��\n");
            if (opt == 1)
            {
                printf("���ͳɹ���\n");
                halt();
                timeNow=time(NULL);
                return createMessage(
                    MessFindTail(MesspHeader),
                    messrank,
                    timeNow,
                    id,
                    text);
            }
            else if (opt == 0)
            {
                printf("ȡ���ɹ���\n");
                halt();
                return NULL;
            }
            else
            {
                nout(0);
                halt();
                continue;
            }
        }
    }
    };
/*���봴��Node*end*/

/*��������begin*/
// User
//  UAll
Ptr *UFindAll(User *pHeader)
{
    int opt = -1;
    while (true)
    {
        printf("��������Ҫ��ѯ��Ա�ķ�ʽ:\n1���\n2����\n3id\n4(ѧ��)רҵ\n5(ѧ��)�꼶\n0�˳�\n");
        scanf("%d", &opt);
        getchar();
        switch (opt)
        {
        case 1:
        {
            int useRank = read(1, 3, "�����������ѯ��Ա����ݣ�\n1����Ա\n2��ʦ\n3ѧ��\n");
            if (useRank == -1)
            {
                printf("������Ч��������!\n");
                break;
            }
            return UFindRank(pHeader, useRank);
        }
        break;
        case 2:
        {
            char name[51];
            readStr(name, "�����������ѯ��Ա��������\n");
            return UFindName(pHeader, name);
        }
        break;
        case 3:
        {
            char id[51];
            readStr(id, "�����������ѯ��Ա��id��\n");
            return UFindId_Ptr(pHeader, id);
        }
        break;
        case 4:
        {
            char major[51];
            readStr(major, "�����������ѯѧ����רҵ��\n");
            return UFindMajor(pHeader, major);
        }
        break;
        case 5:
        {
            char term[51];
            readStr(term, "�����������ѯѧ�����꼶(ѧ��)��\n");
            return UFindTerm(pHeader, term);
        }
        break;
        case 0:
        {
            printf("ȡ����ѯ�ɹ�!\n");
            return NULL;
        }
        default:
        {
            printf("������Ч��������!\n");
        }
        break;
        }
    }
};
// Item
Ptr *IFindAll(Item *pHeader)
{
    int opt = -1;
    char search[51];
    int isearch = -1;
    int onum = -1;
    while (true)
    {
        onum = read(0, 7, "�����������ѯ��ķ�ʽ:\n1ȫ������\n2��������:\n4����\n5��Ŀ\n6����\n7�γ�\n0�˳�");
        switch (opt)
        {
        case 1:
        {
            while (true)
            {
                onum = read(1, 2, "����������ȫ�������Ķ���:\n1 ����\n2 id\n");
                switch (onum)
                {
                case 1:
                {
                    readStr(search, "����������ȫ�ֲ�ѯ������:\n");
                    return IFindName(pHeader, search, -1);
                }
                break;
                case 2:
                {
                    readStr(search, "����������ȫ�ֲ�ѯ��id:\n");
                    return IPtrFindId(pHeader, search, -1);
                }
                break;
                default:
                {
                    nout(0);
                    halt();
                }
                break;
                };
            }
        }
        break;
        case 4:
        {
            while (true)
            {
                onum = read(1, 5, "�����������������ĵķ�ʽ:\n1��������\n2���ĵȼ�\n3����id\n4�����ڿ�/��������\n5���ķ���ʱ��\n");
                switch (onum)
                {
                case 1:
                {
                    readStr(search, "������������������������\n");
                    return IFindName(pHeader, search, 4);
                }
                break;
                case 2:
                {
                    isearch = read(1, 9, "�������������������ĵȼ�\n");
                    return IFindLevel(pHeader, isearch, 4);
                }
                break;
                case 3:
                {
                    readStr(search, "��������������������id\n");
                    return IPtrFindId(pHeader, search, 4);
                }
                break;
                case 4:
                {
                    readStr(search, "���������������������ڿ�/��������\n");
                    return IFindHolder(pHeader, search, 4);
                }
                break;
                case 5:
                {
                    readStr(search, "�������������������ķ���ʱ��\n");
                    return IFindDate(pHeader, search, 4);
                }
                break;
                default:
                {
                    printf("������Ч��������!\n");
                }
                break;
                };
            }
        }
        break;
        case 5:
        {
            while (true)
            {
                onum = read(0, 5, "����������������Ŀ�ķ�ʽ:\n1��Ŀ����\n2��Ŀid\n3��Ŀָ����ʦ\n4��Ŀ����ʱ��\n5��Ŀ����ʱ��\n");
                switch (onum)
                {
                case 1:
                {
                    readStr(search, "������������������Ŀ����\n");
                    return IFindName(pHeader, search, 5);
                }
                break;
                case 2:
                {
                    readStr(search, "������������������Ŀid\n");
                    return IPtrFindId(pHeader, search, 5);
                }
                break;
                case 3:
                {
                    readStr(search, "������������������Ŀָ����ʦ\n");
                    return IFindHolder(pHeader, search, 5);
                }
                break;
                case 4:
                {
                    readStr(search, "������������������Ŀ����ʱ��\n");
                    return IFindDate(pHeader, search, 5);
                }
                break;
                case 5:
                {
                    readStr(search, "������������������Ŀ����ʱ��\n");
                    return IFindDatend(pHeader, search, 5);
                }
                break;
                default:
                {
                    printf("������Ч��������!\n");
                }
                break;
                };
            }
        }
        break;
        case 6:
        {
            while (true)
            {
                onum = read(1, 4, "������������������ķ�ʽ:\n1��������\n2����ȼ�\n3�������쵥λ\n4��ʱ��\n");
                switch (onum)
                {
                case 1:
                {
                    readStr(search, "�����������������������\n");
                    return IFindName(pHeader, search, 6);
                }
                break;
                case 2:
                {
                    printf("������������������ĵȼ�\n");
                    scanf("%d", &isearch);
                    getchar();
                    return IFindLevel(pHeader, isearch, 6);
                }
                break;
                case 3:
                {
                    readStr(search, "����������������������쵥λ\n");
                    return IFindHolder(pHeader, search, 6);
                }
                break;
                case 4:
                {
                    readStr(search, "������������������Ļ�ʱ��\n");
                    return IFindDate(pHeader, search, 6);
                }
                break;
                default:
                {
                    printf("������Ч��������!\n");
                }
                break;
                };
            }
        }
        break;
        case 7:
        {
            while (true)
            {
                printf("���������������γ̵ķ�ʽ:\n1�γ�����\n2�ον�ʦ\n3�γ�ѧԺ\n4�γ��Ĵο���\n5�γ�רҵ\n");
                scanf("%d", &onum);
                getchar();
                switch (onum)
                {
                case 1:
                {
                    readStr(search, "���������������γ̵�����\n");
                    return IFindName(pHeader, search, 7);
                }
                break;
                case 2:
                {
                    readStr(search, "���������������γ̵��ον�ʦ\n");
                    return IPtrFindId(pHeader, search, 7);
                }
                break;
                case 3:
                {
                    readStr(search, "���������������γ̵Ķ�ӦѧԺ\n");
                    return IFindHolder(pHeader, search, 7);
                }
                break;
                case 4:
                {
                    readStr(search, "���������������γ̵Ķ�Ӧ����\n");
                    return IFindDate(pHeader, search, 7);
                }
                break;
                case 5:
                {
                    readStr(search, "���������������γ̵Ķ�Ӧרҵ\n");
                    return IFindDatend(pHeader, search, 7);
                }
                break;
                default:
                {
                    printf("������Ч��������!\n");
                }
                break;
                };
            }
        }
        break;
        case 0:
        {
            printf("�˳��ɹ�!\n");
            return NULL;
        }
        break;
        default:
        {
            printf("������Ч������������!\n");
        }
        break;
        }
    };
}
// Member
Ptr *MFindAll(Member *pHeader)
{
    char search[51];
    readStr(search, "�����������ѯ�ĳ�Աid:\n");
    return MPtrFindId(pHeader, search);
}
/*��������end*/

/*�����ӡbegin*/
//��ʽ����ַ���
void print_Str(char* str){
    int i=0;
    int j=0;
    while(str[i]!='\0'){
        printf("%c",str[i]);
        i++;
        j++;
        if(j==10){
            j=0;
            printf("\n");
        }
    }
}
// ��Member��ӡ
//Message�����ӡ(��Ϣ���ڵ�)
void S_print_Mess(User* UpHeader,Message* pNow){
    system("cls");
    if(pNow->messrank==1){
        printf("������:%s\n",UFindId(UpHeader,pNow->id)->next->name);
        printf("��������:\n");
        print_Str(pNow->text);
        printf("\n\t����ʱ��:%s",asctime(localtime(&(pNow->time))));
    }else if(pNow->messrank==2){
        printf("������:%s %s\n",UFindId(UpHeader,pNow->id)->next->name,pNow->id);
        printf("��������:\n");
        print_Str(pNow->text);
        printf("\n\t����ʱ��:%s",asctime(localtime(&(pNow->time))));
    }
    return ;
}

/*�б��ӡ*/
//Message�б��ӡ
int M_print_Mess(Message* pHeader,int onum){
    if(!pHeader){
        printf("ͷ�ڵ���Ч����ӡʧ��!\n");
        return 0;
    }
    int p = 0;
    int i = 1;
    Message *ptr = pHeader;
    printf("��Ϣ�б�:\n");
    if (!(pHeader->next))
    {
        printf("��\n");
        return 0;
    }
    pHeader = pHeader->next;
    pHeader = ptr;
    printf("����:\n");
    while (pHeader)
    {
        if ((pHeader->messrank) == 1)
        {
            p = 1;
            printf("��Ϣ%d :%10s...\n", i++,pHeader->text);
        }
        pHeader = pHeader->next;
    }
    if (p == 0)
    {
        printf("��\n");
    }
    p = 0;
    pHeader = ptr;
    if(onum==2){
        return i-1;
    }
    printf("����:\n");
    while (pHeader)
    {
        if ((pHeader->messrank) == 2)
        {
            p = 1;
            printf("��Ϣ%d:%10s...\n", i++,pHeader->text);
        }
        pHeader = pHeader->next;
    }
    if (p == 0)
    {
        printf("��\n");
    }
    p = 0;
    return i-1;    
}
// һ��User�б��ӡ(������ͷ�ڵ�)
int M_print_U(Ptr *pHeader)
{
    if (!pHeader)
    {
        printf("ͷ�ڵ���Ч����ӡʧ��!\n");
    }
    printf("%s\n", pHeader->namestr);
    if (!(pHeader->next))
    {
        printf("��\n");
        return 0;
    }
    pHeader = pHeader->next;
    int i = 1;
    while (pHeader)
    {
        printf("%d %s\n", i++, pHeader->pUser->next->name);
        pHeader = pHeader->next;
    }
    return i - 1;
};
// ���User�б��ӡ(������ͷ�ڵ�)
int M_print_RankU(Ptr *pHeader)
{
    int p = 0;
    pHeader = pHeader->next;
    int i = 1;
    Ptr *ptr = pHeader;
    printf("�û��б�:\n");
    if (!(pHeader->next))
    {
        printf("��\n");
        return 0;
    }
    pHeader = ptr;
    printf("����Ա:\n");
    while (pHeader)
    {
        if ((pHeader->pUser->next->useRank) == 1)
        {
            p = 1;
            printf("%d %s\n", i++, pHeader->pUser->next->name);
        }
        pHeader = pHeader->next;
    }
    if (p == 0)
    {
        printf("��\n");
    }
    p = 0;
    //
    pHeader = ptr;
    printf("��ʦ:\n");
    while (pHeader)
    {
        if ((pHeader->pUser->next->useRank) == 2)
        {
            p = 1;
            printf("%d %s\n", i++, pHeader->pUser->next->name);
        }
        pHeader = pHeader->next;
    }
    if (p == 0)
    {
        printf("��\n");
    }
    p = 0;
    //
    pHeader = ptr;
    printf("ѧ��:\n");
    while (pHeader)
    {
        if ((pHeader->pUser->next->useRank) == 3)
        {
            p = 1;
            printf("%d %s\n", i++, pHeader->pUser->next->name);
        }
        pHeader = pHeader->next;
    }
    if (p == 0)
    {
        printf("��\n");
    }
    p = 0;
    return i - 1;
}
// һ��Item�б��ӡ(������ͷ�ڵ�,������)
int M_print_I(Ptr *pHeader)
{
    if (!pHeader)
    {
        printf("ͷ�ڵ���Ч����ӡʧ��!\n");
    }
    printf("%s\n", pHeader->namestr);
    if (!(pHeader->next))
    {
        printf("��\n");
        return 0;
    }
    pHeader = pHeader->next;
    int i = 1;
    while (pHeader)
    {
        printf("%d %s\n", i++, pHeader->pItem->next->name);
        pHeader = pHeader->next;
    }
    return i - 1;
};
// ����/����ֵȴ�ӡ(������ͷ�ڵ㣬������) 1����,2����
int M_print_LevelI(Ptr *pHeader, int onum)
{
    int p = 0;
    pHeader = pHeader->next;
    int i = 1;
    Ptr *ptr = pHeader;
    if (onum == 1)
    {
        printf("�����б�:\n");
        if (!(pHeader))
        {
            printf("��\n");
            return 0;
        }
        pHeader = ptr;
        printf("��һ�� T�ࣺ���ֿ�������:\n");
        while (pHeader)
        {
            if ((pHeader->pItem->next->level) == 1)
            {
                p = 1;
                printf("%d %s\n", i++, pHeader->pItem->next->name);
            }
            pHeader = pHeader->next;
        }
        if (p == 0)
        {
            printf("��\n");
        }
        p = 0;
        pHeader = ptr;
        printf("\n�ڶ��� A�ࣺȨ�����Ŀ�������:\n");
        while (pHeader)
        {
            if ((pHeader->pItem->next->level) == 2)
            {
                p = 1;
                printf("%d %s\n", i++, pHeader->pItem->next->name);
            }
            pHeader = pHeader->next;
        }
        if (p == 0)
        {
            printf("��\n");
        }
        p = 0;
        pHeader = ptr;
        printf("\n������ B�ࣺ��Ҫ���Ŀ�������:\n");
        while (pHeader)
        {
            if ((pHeader->pItem->next->level) == 3)
            {
                p = 1;
                printf("%d %s\n", i++, pHeader->pItem->next->name);
            }
            pHeader = pHeader->next;
        }
        if (p == 0)
        {
            printf("��\n");
        }
        p = 0;
        pHeader = ptr;
        printf("\n���ļ� C�ࣺһ����Ŀ�������:\n");
        while (pHeader)
        {
            if ((pHeader->pItem->next->level) == 4)
            {
                p = 1;
                printf("%d %s\n", i++, pHeader->pItem->next->name);
            }
            pHeader = pHeader->next;
        }
        if (p == 0)
        {
            printf("��\n");
        }
        p = 0;
        pHeader = ptr;
        printf("\n���弶 D�ࣺһ�㹫����������:\n");
        while (pHeader)
        {
            if ((pHeader->pItem->next->level) == 5)
            {
                p = 1;
                printf("%d %s\n", i++, pHeader->pItem->next->name);
            }
            pHeader = pHeader->next;
        }
        if (p == 0)
        {
            printf("��\n");
        }
        p = 0;
        pHeader = ptr;
        printf("\n������ E�ࣺ���޹�����������:\n");
        while (pHeader)
        {
            if ((pHeader->pItem->next->level) == 6)
            {
                p = 1;
                printf("%d %s\n", i++, pHeader->pItem->next->name);
            }
            pHeader = pHeader->next;
        }
        if (p == 0)
        {
            printf("��\n");
        }
        p = 0;
        pHeader = ptr;
        printf("\n���߼� ���Ҽ��ڿ�:\n");
        while (pHeader)
        {
            if ((pHeader->pItem->next->level) == 7)
            {
                p = 1;
                printf("%d %s\n", i++, pHeader->pItem->next->name);
            }
            pHeader = pHeader->next;
        }
        if (p == 0)
        {
            printf("��\n");
        }
        p = 0;
        pHeader = ptr;
        printf("\n�ڰ˼� ʡ���ڿ�:\n");
        while (pHeader)
        {
            if ((pHeader->pItem->next->level) == 8)
            {
                p = 1;
                printf("%d %s\n", i++, pHeader->pItem->next->name);
            }
            pHeader = pHeader->next;
        }
        if (p == 0)
        {
            printf("��\n");
        }
        p = 0;
        pHeader = ptr;
        printf("\n�ھż� �����ڿ�:\n");
        while (pHeader)
        {
            if ((pHeader->pItem->next->level) == 9)
            {
                p = 1;
                printf("%d %s\n", i++, pHeader->pItem->next->name);
            }
            pHeader = pHeader->next;
        }
        if (p == 0)
        {
            printf("��\n");
        }
        p = 0;
        return i - 1;
    }
    else if (onum == 2)
    {
        printf("�����б�:\n");
        if (!(pHeader))
        {
            printf("��\n");
            return 0;
        }
        pHeader = ptr;
        printf("�صȽ�:\n");
        while (pHeader)
        {
            if ((pHeader->pItem->next->level) == 1)
            {
                p = 1;
                printf("%d %s\n", i++, pHeader->pItem->next->name);
            }
            pHeader = pHeader->next;
        }
        if (p == 0)
        {
            printf("��\n");
        }
        p = 0;
        pHeader = ptr;
        printf("\nһ�Ƚ�:\n");
        while (pHeader)
        {
            if ((pHeader->pItem->next->level) == 2)
            {
                p = 1;
                printf("%d %s\n", i++, pHeader->pItem->next->name);
            }
            pHeader = pHeader->next;
        }
        if (p == 0)
        {
            printf("��\n");
        }
        p = 0;
        pHeader = ptr;
        printf("\n���Ƚ�:\n");
        while (pHeader)
        {
            if ((pHeader->pItem->next->level) == 3)
            {
                p = 1;
                printf("%d %s\n", i++, pHeader->pItem->next->name);
            }
            pHeader = pHeader->next;
        }
        if (p == 0)
        {
            printf("��\n");
        }
        p = 0;
        pHeader = ptr;
        printf("\n���Ƚ�:\n");
        while (pHeader)
        {
            if ((pHeader->pItem->next->level) == 4)
            {
                p = 1;
                printf("%d %s\n", i++, pHeader->pItem->next->name);
            }
            pHeader = pHeader->next;
        }
        if (p == 0)
        {
            printf("��\n");
        }
        p = 0;
        return i - 1;
    }
}
//(�γ���)ѧԺרҵ��ӡ
int M_print_Major(Item *pIHeader, Ptr** pout)
{
    int i = 0, p = 0;
    Ptr *pHead = NULL;
    Ptr *ptr = NULL;
    Ptr *pMa = initPtr();
    Ptr *pNow = NULL;
    ptr = NFind_Course(pIHeader, 6, "000");
    pHead = ptr;
    ptr = ptr->next;
    pIHeader = pIHeader->next;
    printf("ѧԺ�б�:\n");
    if (!ptr)
    {
        printf("��\n");
        return 0;
    }
    while (ptr)
    {
        printf("%s:\n", ptr->namestr);
        //
        pNow = NFind_Course(pIHeader, 8, ptr->namestr);
        i = M_print_Name(pNow, i + 1);
        PFindTail(pMa)->next = pNow->next;
        free(pNow);
        pNow=NULL;
        //
        ptr = ptr->next;
    }
    *pout = pMa;
    clear_PList(pHead, 0);
    return i;
}
// ��ӡ������(������ͷ�ڵ�)
int M_print_Name(Ptr *pHeader, int i)
{
    if (!pHeader)
    {
        printf("ͷ�ڵ���Ч����ӡʧ��!\n");
        return 0;
    }
    if (!(pHeader->next))
    {
        printf("��\n");
        return 0;
    }
    pHeader = pHeader->next;
    while (pHeader)
    {
        printf("%d %s\n", i++, pHeader->namestr);
        pHeader = pHeader->next;
    }
    return i - 1;
};
// һ��Member�б��ӡ��Userͷ�ڵ㣬Memberͷ�ڵ㣩
int M_print_Mem(User* UpHeader,Member *pHeader)
{
    if (!pHeader)
    {
        printf("ͷ�ڵ���Ч����ӡʧ��!\n");
    }
    printf("��Ա�б�:\n");
    if (!(pHeader->next))
    {
        printf("��\n");
        return 0;
    }
    pHeader = pHeader->next;
    int i = 1;
    while (pHeader)
    {
        printf("%d %s\n", i++,UFindId(UpHeader,pHeader->id)->next->name);
        pHeader = pHeader->next;
    }
    return i - 1;
}
// ����Member�б��ӡ
int M_print_PaperMem(User* UpHeader,Ptr *pHeader)
{
    int p = 0;
    printf("�����������б�:\n");
    if (!(pHeader->next))
    {
        printf("��\n");
        return 0;
    }
    pHeader = pHeader->next;
    Ptr *ptr = pHeader;
    int i = 1;
    printf("ͨѶ����:\n");
    while (pHeader)
    {
        if ((pHeader->pMember->next->rankscore) == 0)
        {
            p = 1;
            printf("%d %s\n", i++, UFindId(UpHeader,pHeader->pMember->next->id)->next->name);
        }
        pHeader = pHeader->next;
    }
    if (p == 0)
    {
        printf("��\n");
    }
    p = 0;
    pHeader = ptr;
    printf("��һ����:\n");
    while (pHeader)
    {
        if ((pHeader->pMember->next->rankscore) == 1)
        {
            p = 1;
            printf("%d %s\n", i++, UFindId(UpHeader,pHeader->pMember->next->id)->next->name);
        }
        pHeader = pHeader->next;
    }
    if (p == 0)
    {
        printf("��\n");
    }
    p = 0;
    pHeader = ptr;
    printf("�ڶ�����:\n");
    while (pHeader)
    {
        if ((pHeader->pMember->next->rankscore) == 2)
        {
            p = 1;
            printf("%d %s\n", i++, UFindId(UpHeader,pHeader->pMember->next->id)->next->name);
        }
        pHeader = pHeader->next;
    }
    if (p == 0)
    {
        printf("��\n");
    }
    p = 0;
    pHeader = ptr;
    printf("��������:\n");
    while (pHeader)
    {
        if ((pHeader->pMember->next->rankscore) == 3)
        {
            p = 1;
            printf("%d %s\n", i++, UFindId(UpHeader,pHeader->pMember->next->id)->next->name);
        }
        pHeader = pHeader->next;
    }
    if (p == 0)
    {
        printf("��\n");
    }
    p = 0;
    pHeader = ptr;
    printf("��������:\n");
    while (pHeader)
    {
        if ((pHeader->pMember->next->rankscore) > 3)
        {
            p = 1;
            printf("%d %s\n", i++, UFindId(UpHeader,pHeader->pMember->next->id)->next->name);
        }
        pHeader = pHeader->next;
    }
    if (p == 0)
    {
        printf("��\n");
    }
    p = 0;
    return i - 1;
}
// �γ�Member�б��ӡ
int M_print_CourseMem(User* UpHeader,Ptr *pHeader)
{
    printf("�ÿγ̳�Ա�б�:\n");
    if (!(pHeader->next)||!pHeader)
    {
        printf("��\n");
        return 0;
    }
    int p = 0;
    pHeader = pHeader->next;
    int i = 1;
    Ptr *ptr = pHeader;
    printf("��ʦ:\n");
    while (pHeader)
    {
        if (UFindId(UpHeader,pHeader->pMember->next->id)->next->useRank==2)
        {
            p = 1;
            printf("%d %s\n", i++, UFindId(UpHeader,pHeader->pMember->next->id)->next->name);
        }
        pHeader = pHeader->next;
    }
    if (p == 0)
    {
        printf("��\n");
    }
    p = 0;
    pHeader = ptr;
    printf("ѧ��:\t\t����\t\t����\n");
    while (pHeader)
    {
        if (UFindId(UpHeader,pHeader->pMember->next->id)->next->useRank==3)
        {
            p = 1;
            if(sameFloat(pHeader->pMember->next->point,0)){
            printf("%d %s\tδ����\tδ����\n", i++, UFindId(UpHeader,pHeader->pMember->next->id)->next->name);
            }else {
            printf("%d %s\t%d\t%.4f\n", i++, UFindId(UpHeader,pHeader->pMember->next->id)->next->name, pHeader->pMember->next->rankscore, pHeader->pMember->next->point);
            }
        }
        pHeader = pHeader->next;
    }
    if (p == 0)
    {
        printf("��\n");
    }
    p = 0;
    return i - 1;
}
//�û��������б��ӡ(onum,-1��ӡȫ�֣�4��ӡ���ģ�5��ӡ��Ŀ��6��ӡ���7��ӡ�γ�)(opt,2��ʦ,3ѧ��)
int M_print_UserDone(Ptr* pHeader,int onum,int opt){
    if(!pHeader){
        printf("Ptr[error]!\n");
        return 0;
    }
    system("cls");
    int p = 0;
    pHeader = pHeader->next;
    int i = 1;
    Ptr *ptr = pHeader;
    if (onum == -1)
    {
        if(opt==2)
        printf("�ý�ʦ�������Ŀ��:\n");
        if(opt==3)
        printf("��ѧ���������Ŀ��:\n");
        if (!(pHeader))
        {
            printf("��\n");
            return 0;
        }
        pHeader = ptr;
        printf("�����б�\t��������˳��:\n");
        while (pHeader)
        {
            if ((pHeader->pItem->next->itemRank) == 4)
            {
                p = 1;
                printf("%s\t%d\n", pHeader->pItem->next->name,pHeader->pMember->next->rankscore);
            }
            pHeader = pHeader->next;
        }
        if (p == 0)
        {
            printf("��\n");
        }
        p = 0;
        pHeader = ptr;
        printf("��Ŀ�б�:\t����˳��\n");
        while (pHeader)
        {
            if ((pHeader->pItem->next->itemRank) == 5)
            {
                p = 1;
                printf("%s\t%d\n", pHeader->pItem->next->name,pHeader->pMember->next->rankscore);
            }
            pHeader = pHeader->next;
        }
        if (p == 0)
        {
            printf("��\n");
        }
        p = 0;
        pHeader = ptr;
        printf("�����б�:\t����˳��\n");
        while (pHeader)
        {
            if ((pHeader->pItem->next->itemRank) == 6)
            {
                p = 1;
                printf("%s\t%d\n", pHeader->pItem->next->name,pHeader->pMember->next->rankscore);
            }
            pHeader = pHeader->next;
        }
        if (p == 0)
        {
            printf("��\n");
        }
        p = 0;
        pHeader = ptr;
        if(opt==2){
        printf("���ڿγ��б�:\n");
        while (pHeader)
        {
            if ((pHeader->pItem->next->itemRank) == 7)
            {
                p = 1;
                printf("%s\n", pHeader->pItem->next->name);
            }
            pHeader = pHeader->next;
        }
        if (p == 0)
        {
            printf("��\n");
        }
        p = 0;            
        }
        if(opt==3){
        printf("�γ��б�:\t�ܷ���\t����\n");
        while (pHeader)
        {
            if ((pHeader->pItem->next->itemRank) == 7)
            {
                p = 1;
                if(pHeader->pMember->next->rankscore==0){
                printf("%s\tδ����\tδ����\n", pHeader->pItem->next->name);
                }else{
                printf("%s\t%d\t%f\n", pHeader->pItem->next->name,pHeader->pMember->next->rankscore,pHeader->pMember->next->point);
                }
            }
            pHeader = pHeader->next;
        }
        if (p == 0)
        {
            printf("��\n");
        }
        p = 0;
        }        
        return 0;           
    }
    if(onum==4){
        printf("�û�������:\n");
        if (!(pHeader))
        {
            printf("��\n");
            return 0;
        }
        pHeader = ptr;
        printf("�����б�\t��������˳��:\n");
        while (pHeader)
        {
            if ((pHeader->pItem->next->itemRank) == 4)
            {
                p = 1;
                printf("%s\t%d\n", pHeader->pItem->next->name,pHeader->pMember->next->rankscore);
            }
            pHeader = pHeader->next;
        }
        if (p == 0)
        {
            printf("��\n");
        }
        p = 0;
        return 0;        
    }
    if(onum==5){
        printf("�û�������:\n");
        if (!(pHeader))
        {
            printf("��\n");
            return 0;
        }
        pHeader = ptr;
        printf("��Ŀ�б�:\t����˳��\n");
        while (pHeader)
        {
            if ((pHeader->pItem->next->itemRank) == 5)
            {
                p = 1;
                printf("%s\t%d\n", pHeader->pItem->next->name,pHeader->pMember->next->rankscore);
            }
            pHeader = pHeader->next;
        }
        if (p == 0)
        {
            printf("��\n");
        }
        p = 0;        
    }
    if(onum==6){
        printf("�û�������:\n");
        if (!(pHeader))
        {
            printf("��\n");
            return 0;
        }
        pHeader = ptr;
        printf("�����б�:\t����˳��\n");
        while (pHeader)
        {
            if ((pHeader->pItem->next->itemRank) == 6)
            {
                p = 1;
                printf("%s\t%d\n", pHeader->pItem->next->name,pHeader->pMember->next->rankscore);
            }
            pHeader = pHeader->next;
        }
        if (p == 0)
        {
            printf("��\n");
        }
        p = 0;        
    }
    if(onum==7){
        printf("�û�������:\n");
        if (!(pHeader))
        {
            printf("��\n");
            return 0;
        }
        pHeader = ptr;
        printf("���ڿγ��б�:\n");
        while (pHeader)
        {
            if ((pHeader->pItem->next->itemRank) == 7)
            {
                p = 1;
                printf("%d %s\n",i++, pHeader->pItem->next->name);
            }
            pHeader = pHeader->next;
        }
        if (p == 0)
        {
            printf("��\n");
        }
        p = 0;
        return i-1;   
}
}
/*�����ӡend***/

/*�޸Ľڵ���begin*/
// User�޸���(��Ӧ��ָ��,������)
void fix_U(User *pNow, int onum)
{
    switch (onum)
    {
    case 1:
    {
        readStr(pNow->name, "���������û�����:\n");
    }
    break;
    case 2:
    {
        readStr(pNow->id, "�������û��º���:\n");
    }
    break;
    case 3:
    {
        readStr(pNow->password, "�������û�������:\n");
    }
    break;
    case 4:
    {
        readStr(pNow->faculty, "�������û���ѧԺ:\n");
    }
    break;
    case 5:
        if (pNow->useRank == 3)
        {
            readStr(pNow->major, "�������û�����רҵ\n");
        }
        else
        {
            nout(0);
            halt();
        }
        break;
    case 6:
    {
        if (pNow->useRank == 3)
        {
            readStr(pNow->term, "�������û���ѧ��\n");
        }
        else
        {
            nout(0);
            halt();
            break;
        }
    }
    break;
    default:
    {
        nout(0);
        halt();
        break;
    }
    }
};
// Item�޸���(��Ӧ��ָ��,������)
void fix_I(Item *pNow, int onum)
{
    // paper
    if (pNow->itemRank == 4)
    {
        switch (onum)
        {
        case 1:
        {
            pNow->level=read(1,9,"�������µ����ĵȼ���\n");
        }
        break;
        case 2:
        {
            printf("�������µ����ļӷ֣�\n");
            scanf("%f", &(pNow->credit));
            getchar();
        }
        break;
        case 3:
        {
            readStr(pNow->name, "�������µ����ƣ�\n");
        }
        break;
        case 4:
        {
            readStr(pNow->id, "�������µ����ĺţ�\n");
        }
        break;
        case 5:
        {
            readStr(pNow->holder, "�������µ��ڿ�/�������ƣ�\n");
        }
        break;
        case 6:
        {
            readStr(pNow->date, "�������µķ���ʱ�䣺\n");
        }
        break;
        case 7:
        {
            readStr(pNow->datend, "�������µľ��ڣ�\n");
        }
        break;
        default:
        {
            nout(0);
            halt();
            break;
        }
        }
    }
    // project
    if (pNow->itemRank == 5)
    {
        switch (onum)
        {
        case 1:
        {
            readStr(pNow->name, "�������µ�����\n");
        }
        break;
        case 2:
        {
            readStr(pNow->id, "�������µ���Ŀ��ţ�\n");
        }
        break;
        case 3:
        {
            readStr(pNow->holder, "�������µ�ָ����ʦ������\n");
        }
        break;
        case 4:
        {
            readStr(pNow->date, "�������µ�����ʱ�䣺\n");
        }
        break;
        case 5:
        {
            readStr(pNow->datend, "�������µĽ���ʱ�䣺\n");
        }
        break;
        default:
        {
            nout(0);
            halt();
            break;
        }
        }
    }
    // award
    if (pNow->itemRank == 6)
    {
        switch (onum)
        {
        case 1:
        {
        pNow->level=read(0,3,"�������µ����ĵȼ���\n")+1;

        }
        break;
        case 2:
        {
            readStr(pNow->name, "�������µ�����\n");
        }
        break;
        case 3:
        {
            readStr(pNow->holder, "�������µ����쵥λ��\n");
        }
        break;
        case 4:
        {
            readStr(pNow->date, "�������µĻ�ʱ�䣺\n");
        }
        break;
        default:
        {
            nout(0);
            halt();
        }
        break;
        }
    }
    // course
    if (pNow->itemRank == 7)
    {
        switch (onum)
        {
        case 1:
        {
            printf("�������µĿγ�ѧ��\n");
            scanf("%f", (&pNow->credit));
            getchar();
        }
        break;
        case 2:
        {
            readStr(pNow->name, "�������µ�����\n");
        }
        break;
        case 3:
        {
            readStr(pNow->id, "�������µĿγ̱�ţ�\n");
        }
        break;
        case 4:
        {
            readStr(pNow->holder, "�������µ�ѧԺ��\n");
        }
        break;
        case 5:
        {
            readStr(pNow->date, "�������µĶ�Ӧѧ�ڣ�\n");
        }
        break;
        case 6:
        {
            readStr(pNow->datend, "�������µĶ�Ӧרҵ��\n");
        }
        break;
        default:
        {
            nout(0);
            halt();
        }
        break;
        }
        return;
    };
}
// Member�޸���(��Ӧ��ָ��,������)
void fix_M(Member *pNow, int onum)
{
    switch (onum)
    {
    case 1:
    {
        readStr(pNow->id, "�������µĳ�Աid��\n");
    }
    break;
    case 2:
    {
        printf("�������µ�˳��/����\n");
        scanf("%d", &(pNow->rankscore));
        getchar();
    }
    break;
    case 3:
    {
        printf("�������µļ���\n");
        scanf("%f", &(pNow->point));
        getchar();
    }
    break;
    default:
    {
        nout(0);
        halt();
    }
    break;
    }
}
/*�޸Ľڵ���end***/
