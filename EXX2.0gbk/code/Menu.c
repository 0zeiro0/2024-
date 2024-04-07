#include "Menu.h"
/*ToolsBegin*/
// 固定延时器
void halt()
{
    fflush(stdin);
    printf("按下任意键继续...\n");
    getchar();
    fflush(stdin);
}
// 基本报告器(0，报无效输入：1，报退出成功)
void nout(int opt)
{
    if (opt == 0)
        printf("输入无效，请重试！\n");
    if (opt == 1)
        printf("退出成功！\n");
}
// 提示词整数读取器(下限，上限,提示词)，用户输入无效返回-1
int read(int low, int high, char tip[])
{
    int onum = -1;
    if (strcmp(tip, "000"))
    {
        printf("%s", tip);
    }
    printf("请输入:\n");
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
// 提示词一般字符串读取器
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
            printf("输入长度过长,请输入50字以内!\n");
            continue;
        }
        strcpy(p, str);
        return;
    }
}
//提示词+长字符串读取器
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
            printf("输入长度过长,请输入50字以内!\n");
            continue;
        }
        strcpy(p, str);
        return;
    }
}
// 格式输入器(1账号,2密码)
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
                printf("输入长度过长,请输入8位以内数字!\n");
                continue;
            }
            if (strspn(str, "0123456789") != strlen(str))
            {
                printf("输入非法，请检查输入是否均为数字!\n");
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
                printf("输入长度过长,请输入20位以内!\n");
                continue;
            }
            for (int i = 0; i < 20; i++)
            {
                if (!(str[0] == '_' || isalpha(str[0])))
                {
                    printf("字符串不合法，请重新输入!\n");
                    continue;
                }
                if (!(str[i] == '_' || isalnum(str[i])))
                {
                    printf("字符串不合法，请重新输入!\n");
                    continue;
                }
            }
            strcpy(p, str);
            return;
        }
    }
};
//浮点数检测器(实际值，界准值)
int sameFloat(float real,float aim){
    if((real-aim)*(real-aim)<0.1){
    return 1;
    }else {
        return 0;
    }
}
/*ToolsEnd***/

// 初始界面
void EnterAll(User *UpHeader, Item *IpHeader, Message *MesspHeader)
{
    while (true)
    {
        system("cls");
        printf("欢迎使用成绩管理系统!\n");
        int opt = read(0, 2, "请选择您的操作:\n1登入\n2申诉\n0退出\n");
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
// 登入器
void LogIn(User *UpHeader, Item *IpHeader, Message *MesspHeader)
{
    char id[51], password[51], passnow[51];
    int useRank = -1;
    readStr(id, "请输入您的账号：\n");
    User *p = UFindId(UpHeader, id);
    if (!p->next)
    {
        printf("账号不存在，请重试！\n");
        halt();
        return;
    }
    strcpy(password, p->next->password);
    readStr(passnow, "请输入您的密码：\n");
    if (strcmp(passnow, password))
    {
        printf("帐号与密码不一致，请重试！\n");
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
            printf("账号权限信息错误，请重试！");
            return;
        }
    }
    return;
}

// 管理员Menu入口
void ManegerMenu(User *UpHeader, Item *IpHeader, Message *MpHeader, char *name)
{
    while (true)
    {
        system("cls");
        printf("管理员%s,欢迎使用成绩管理系统!\n", name);
        switch (read(0, 6, "请选择您想查看的类目:\n1用户管理\n2论文管理\n3项目管理\n4奖项管理\n5课程管理\n6通知管理\n0退出\n"))
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
// 教师Menu入口
void TeacherMenu(User *UpHeader, Item *IpHeader, Message *MpHeader) {

};
// 学生Menu入口
void StudentMenu(User *UpHeader, Item *IpHeader, Message *MpHeader)
{

}
//全通知查看入口(onum1表示管理员查看，2表示学生查看)
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
        opt = read(0, 3, "\n请选择您想进行的操作:\n1查看公告/申诉\n2新增公告\n3删除公告/申诉\n0退出信息查看\n");
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
            choice = read(1, max, "请输入您想查看公告/申诉的标号\n");
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
            choice = read(1, max, "请输入您想删除公告/申诉的标号\n");
            if (choice == -1)
            {
                nout(0);
                halt();
                continue;
            }
            delete_Mess(MessFindNum(MpHeader,choice));
            printf("删除成功!\n");
            halt();
        }
        }
        }
        else if(onum==2){
        opt = read(0, 3, "\n请选择您想进行的操作:\n1查看公告\n2发起申诉\n0退出信息查看\n");
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
            choice = read(1, max, "请输入您想查看公告/申诉的标号\n");
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
// 全用户管理入口
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
        onum = read(0, 3, "\n请选择您想进行的操作:\n1查看用户\n2新建用户\n3删除用户\n0退出用户查看\n");
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
            choice = read(1, max, "请输入您想查看用户的标号\n");
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
            choice = read(1, max, "请输入您想删除用户的标号\n");
            if (choice == -1)
            {
                nout(0);
                halt();
                clear_PList(p, 0);
                continue;
            }
            delete_U(PFindNum(p, choice)->pUser,IpHeader);
            printf("删除成功!\n");
            halt();
            clear_PList(p, 0);
        }
        }
    }
}
//全论文查看入口
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
        onum = read(0, 3, "\n请选择您想进行的操作:\n1查看论文\n2新建论文\n3删除论文\n0退出论文查看\n");
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
            choice = read(1, max, "请输入您想查看论文的标号\n");
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
            choice = read(1, max, "请输入您想删除论文的标号\n");
            if (choice == -1)
            {
                nout(0);
                halt();
                clear_PList(p, 0);
                continue;
            }
            delete_I(PFindNum(p, choice)->pItem);
            printf("删除成功!\n");
            halt();
            clear_PList(p, 0);
        }
        }
    }
}
//全项目管理入口
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
        onum = read(0, 3, "\n请选择您想进行的操作:\n1查看项目\n2新建项目\n3删除项目\n0退出项目查看\n");
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
            choice = read(1, max, "请输入您想查看项目的标号\n");
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
            choice = read(1, max, "请输入您想删除项目的标号\n");
            if (choice == -1)
            {
                nout(0);
                halt();
                clear_PList(p, 0);
                continue;
            }
            delete_I(PFindNum(p, choice)->pItem);
            printf("删除成功!\n");
            halt();
            clear_PList(p, 0);
        }
        }
    }
}
//全奖项管理入口
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
        onum = read(0, 3, "\n请选择您想进行的操作:\n1查看奖项\n2新建奖项\n3删除奖项\n0退出奖项查看\n");
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
            choice = read(1, max, "请输入您想查看奖项的标号\n");
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
            choice = read(1, max, "请输入您想删除奖项的标号\n");
            if (choice == -1)
            {
                nout(0);
                halt();
                clear_PList(p, 0);
                continue;
            }
            delete_I(PFindNum(p, choice)->pItem);
            printf("删除成功!\n");
            halt();
            clear_PList(p, 0);
        }
        }
    }
}
// 全课程管理器
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
        onum = read(0, 3, "\n请选择您想进行的操作:\n1查看标号专业下的课程\n2新建课程\n0退出课程查看\n");
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
            choice = read(1, max, "请输入您想查看专业的标号\n");
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

//单用户查看入口
void S_User(User* UpHeader,Item* IpHeader,Ptr* p){
    Ptr* ptr=NULL;
    while(true){
        system("cls");
    switch (p->pUser->next->useRank)
    {
    case 1:
    {
        printf("管理员:%s\nid号:%s\n密码:%s\n", p->pUser->next->name, p->pUser->next->id,p->pUser->next->password);
        switch (read(0,3,"请选择您的操作：\n修改：\t1名称\n\t2id号\n\t3密码\n0退出查看\n"))
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
        printf("教师:%s\nid号:%s\n密码:%s\n", p->pUser->next->name, p->pUser->next->id,p->pUser->next->password);
        printf("学院:%s\n", p->pUser->next->faculty);
        switch (read(0,5,"请选择您的操作：\n修改：\n\t1名称\n\t2工号\n\t3密码\n\t4学院\n5浏览相关项目类\n0退出查看\n\n"))
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
        printf("学生:%s\n学号:%s\n密码:%s\n", p->pUser->next->name, p->pUser->next->id,p->pUser->next->password);
        printf("学院:%s\n", p->pUser->next->faculty);
        printf("专业:%s\n学期:%s\n", p->pUser->next->major, p->pUser->next->term);
        printf("GPA:%.4f\n", p->pUser->next->GPA);
        switch (read(0,7,"请选择您的操作：\n修改：\n\t1名称\n\t2工号\n\t3密码\n\t4学院\n\t5专业\n\t6学期\n7浏览相关项目类\n0退出查看\n"))
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
//单用户参与项查看入口
void S_User_Relate(User* UpHeader,Item* IpHeader,Ptr* p){
    
    while(true){
        system("cls");
        switch(p->pUser->next->useRank){
            case 2:{
                printf("该教师参与的项目类:\n");
                M_print_UserDone(p,-1,2);
                halt();
            }
            break;
            case 3:{
                printf("该学生参与的项目类:\n");
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
//单素质类查看入口
void S_Item(User* UpHeader,Item* IpHeader,Ptr* p){
    while(true){
        system("cls");
    switch (p->pItem->next->itemRank)
    {
    case 4:
    {
        printf("论文:%s\n编号:%s\n级别:%d\n", p->pItem->next->name, p->pItem->next->id,p->pItem->next->level);
        printf("期刊名称:%s\n发表时间:%s\n卷期:%s\n",p->pItem->next->holder,p->pItem->next->date,p->pItem->next->datend);
        printf("加分(GPA):%.4f\n",p->pItem->next->credit);
        switch (read(0,8,"请选择您的操作：\n修改：\n\t1名称\n\t2id号\n\t3级别\n\t4发表期刊\n\t5发表时间\n\t6卷期\n\t7加分(绩点)\n8查看成员\n0退出查看\n"))
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
        printf("项目:%s\n项目编号:%s\n立项时间:%s\n结项时间:%s\n", p->pItem->next->name, p->pItem->next->id,p->pItem->next->date,p->pItem->next->datend);
        switch (read(0,5,"请选择您的操作：\n修改：\n\t1名称\n\t2编号\n\t3立项时间\n\t4结项时间\n5查看成员\n0退出查看\n"))
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
        printf("竞赛获奖:%s\n奖项编号:%s\n等级:%d\n主办单位:%s\n获奖时间:%s\n", p->pItem->next->name, p->pItem->next->id,p->pItem->next->level,p->pItem->next->holder,p->pItem->next->date);
        switch (read(0,5,"请选择您的操作：\n修改：\n\t1名称\n\t2等级\n\t3主办单位\n\t4获奖时间\n5查看成员\n0退出查看\n"))
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
        printf("课程:%s\n课程编号:%s\n学院:%s\n", p->pItem->next->name, p->pItem->next->id,p->pItem->next->holder);
        printf("学期:%s\n对应专业:%s\n课程学分:%.4f\n",p->pItem->next->date,p->pItem->next->datend,p->pItem->next->credit);
        printf("加分(GPA):%.4f\n",p->pItem->next->credit);
        switch (read(0,7,"请选择您的操作：\n修改：\n\t1名称\n\t2课程编号\n\t3学院\n\t4学期\n\t5对应专业\n\t6课程学分\n7查看成员\n0退出查看\n"))
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
//单项目类成员查看入口(opt:4论文5项目6奖项7课程)
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
        onum = read(0, 2, "\n请选择您想进行的操作:\n1新增成员\n2删除成员\n0退出成员查看\n");
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
            choice = read(1, max, "请输入您想删除成员的标号\n");
            if (choice == -1)
            {
                nout(0);
                halt();
                clear_PList(p, 0);
                continue;
            }
            delete_M(PFindNum(p, choice)->pMember);
            printf("删除成功!\n");
            halt();
            clear_PList(p, 0);
        }
        }
    }    
}
//单专业课程查看器
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
        onum = read(0, 3, "\n请选择您想进行的操作:\n1查看课程\n2新建课程\n3删除课程\n0退出课程查看\n");
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
            choice = read(1, max, "请输入您想查看课程的标号\n");
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
            choice = read(1, max, "请输入您想删除课程的标号\n");
            if (choice == -1)
            {
                nout(0);
                halt();
                clear_PList(p, 0);
                continue;
            }
            delete_I(PFindNum(p, choice)->pItem);
            printf("删除成功!\n");
            halt();
            clear_PList(p, 0);
        }        
        }            
    }
}

/*输入创建Node*begin*/
// User创建器
User *in_User(User *UpHeader, int onum)
{
    char name[51];     // 用户真实姓名
    char id[51];       // 学号&工号&管理号=帐号名
    char password[51]; // 账号密码
    char faculty[51];  // 用户性别
    char major[51];    // 学生(专业)
    char term[51];     // 学生(学期)
    float GPA;         // 学生(绩点)
    //
    int opt;
    int useRank;
    while (true)
    {
        system("cls");
        useRank = onum;
        if (useRank == -1)
        {
            useRank = read(0, 3, "请选择赋予用户的身份:\n1管理员\n2教师\n3学生\n或：0退出创建\n");
            if (useRank == -1)
            {
                printf("身份信息无效,请重新输入!\n");
                halt();
                continue;
            }
            else if (useRank == 0)
            {
                nout(1);
                return UFindTail(UpHeader);
            }
        }
        printf("请输入用户姓名:\n");
        scanf("%51s", name);
        getchar();
        printf("请输入用户号码:\n");
        scanf("%51s", id);
        getchar();
        if(UFindId(UpHeader,id)){
            printf("该用户已存在，创建无效！\n");
            halt();
            return NULL;
        }
        printf("请输入用户密码:\n");
        scanf("%51s", password);
        getchar();
        if (useRank == 2 || useRank == 3)
        {
            printf("请输入用户学院:\n");
            scanf("%51s", faculty);
            getchar();
        }
        else
        {
            strcpy(faculty, "000");
        }
        if (useRank == 3)
        {
            readStr(major, "请输入用户的专业\n");
            readStr(term, "请输入用户的学期\n");
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
            opt = read(0, 1, "是否创建?1是 0否\n");
            if (opt == 1)
            {
                printf("创建成功！\n");
                Sleep(5);
                return createUser( // 改成return变创建就出
                    UFindTail(UpHeader),
                    useRank,  // 身份标记数(0,管理员;1,教师;2,学生)
                    name,     // 用户真实姓名
                    id,       // 学号&工号&管理号=帐号名
                    password, // 账号密码
                    faculty,  // 用户性别->学院
                    major,    // 学生(专业)
                    term,     // 学生(学期)
                    GPA);     // 学生(绩点);
            }
            else if (opt == 0)
            {
                printf("取消成功！\n");
                Sleep(5);
                return NULL;
            }
            else
            {
                printf("输入无效,请重试!\n");
            }
        }
    }
};
// Item输入器,用户自选输入类(-1),4论文5项目6奖项7课程
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
                itemRank = read(4, 8, "请输入创建的类型:\n4论文\n5项目\n6奖项\n7课程\n或:0退出创建\n");
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
            level = read(0, 8, "请输入论文等级：1第一级 T类：特种刊物论文\n2第二级 A类：权威核心刊物论文\n3第三级 B类：重要核心刊物论文\n4第四级 C类：一般核心刊物论文\n5第五级 D类：一般公开刊物论文\n6第六级 E类：受限公开刊物论文\n7第七级 国家级内刊\n8第八级 省级内刊\n9第九级 区级内刊\n");
            if (level == -1)
            {
                nout(0);
                halt();
                continue;
            }
            readStr(name, "请输入名称：\n");
            readStr(id, "请输入论文号：\n");
            if(IFindId(IpHeader,id)){
                printf("此素质类id已存在，输入无效!\n");
                halt();
                return NULL;
            }
            readStr(date, "请输入发表时间：\n");
            readStr(holder, "请输入期刊/会议名称：\n");
            readStr(datend, "请输入卷期：\n");
            printf("请输入论文加分：\n");
            scanf("%f", &credit);
            getchar();
            //
        }
        else if (itemRank == 5)
        {
            readStr(name, "请输入名称\n");
            readStr(id, "请输入项目编号：\n");
            if(IFindId(IpHeader,id)){
                printf("此素质类id已存在，输入无效!\n");
                halt();
                return NULL;
            }            
            readStr(date, "请输入立项时间：\n");
            readStr(datend, "请输入结项时间：\n");
        }
        else if (itemRank == 6)
        {
            level = read(0, 3, "请输入获奖等级:\n0特等奖\n1一等奖\n2二等奖\n3三等奖\n") + 1;
            if (level == 0)
            {
                nout(0);
                halt();
                continue;
            }
            readStr(name, "请输入名称\n");
            readStr(id, "请输入获奖编号：\n");
            if(IFindId(IpHeader,id)){
                printf("此素质类id已存在，输入无效!\n");
                halt();
                return NULL;
            }            
            readStr(holder, "请输入主办单位：\n");
            readStr(date, "请输入获奖时间：\n");
        }
        else if (itemRank == 7)
        { // course
            level = -1;
            readStr(name, "请输入名称\n");
            readStr(holder, "请输入学院：\n");
            readStr(datend, "请输入对应专业：\n");
            readStr(id,"请输入课程编号：\n");
            if(IFindId(IpHeader,id)){
                printf("此素质类id已存在，输入无效!\n");
                halt();
                return NULL;
            }            
            readStr(date, "请输入考试场次：\n");
            printf("请输入课程学分\n");
            scanf("%f", &credit);
            getchar();
        }
        else
        {
            printf("类别信息错误,创建失败！\n");
        }
        while (true)
        {
            opt = read(0, 1, "是否创建?1是 0否\n");
            if (opt == 1)
            {
                printf("创建成功！\n");
                return createItem( // 改成return变创建就出
                    IFindTail(IpHeader),
                    itemRank, // 类别标记数(4,paper;5,project;6,award;7,course)
                    level,    // 论文(级别信息);获奖(等级)
                    credit,   // 论文(GPA加分);课程(学分)
                    name,     // 名称
                    id,       // 论文(号);项目(编号);获奖();课程(编号)
                    holder,   // 论文(期刊/会议名称);项目(指导教师);获奖(主办单位);课程(学院)
                    date,     // 论文(发表时间);项目(立项时间);获奖(时间);课程(哪次考试)
                    datend);  // 论文(卷期);项目(结项时间);课程(专业)
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
// Member创建器(opt4论文5项目6奖项7课程)
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
        readStr(id, "请输入成员id：\n");
        if(!UFindId(UpHeader,id)){
            printf("查无此人，请重新输入！\n");
            continue;
        };
        if(MemFindId(MempHeader,id)){
        printf("此人已在此成员列表中，输入无效！\n");
        halt();
        continue;
        }
        onum=UFindId(UpHeader,id)->next->useRank;
        if(onum==1){
            printf("管理员不列入此类，请重新输入！\n");
            halt();
            continue;
        }
        if (onum == 3)
        {
            if(itemclass==5||itemclass==6){
            printf("请输入所在顺序\n");
            scanf("%d", &rankscore);
            getchar();
            point=0;
            }else if(itemclass==4){
            printf("请输入所在顺序\n");
            printf("0通讯作者1第一作者2第二作者3第三作者...");
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
            printf("请输入分数\n");
            scanf("%d", &rankscore);
            getchar();
            printf("请输入绩点:(0表示未结算)\n");
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
            printf("请输入顺序\n");
            printf("0通讯作者1第一作者2第二作者3第三作者...");
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
            point = -1.00000f; // 这里不表示无效，代指教师
        }
        while (true)
        {
            opt = read(0, 1, "是否创建?1是 0否\n");
            if (opt == 1)
            {
                printf("创建成功！\n");
                halt();
                return createMember(
                    MFindTail(MempHeader),
                    id,
                    rankscore,
                    point);
            }
            else if (opt == 0)
            {
                printf("取消成功！\n");
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
// 申诉创建发送器（消息尾节点）onum1表示管理员2表示一般用户
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
        pin_readStr(id, 1,"请输入您的id号\n");
        if (!UFindId(UpHeader, id))
        {
        printf("账号不存在，请重试！\n");
        halt();
        return NULL;
        }
        readLongStr(text, "请输入公告内容\n");            
        }
        if(onum==2){
            messrank=2;
        pin_readStr(id, 1,"请输入您的id号\n");
        if (!UFindId(UpHeader, id))
        {
        printf("账号不存在，请重试！\n");
        halt();
        return NULL;
        }
        readLongStr(text, "请输入申诉内容\n");            
        }

        while (true)
        {
            opt = read(0, 1, "是否创建?1是 0否\n");
            if (opt == 1)
            {
                printf("发送成功！\n");
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
                printf("取消成功！\n");
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
/*输入创建Node*end*/

/*搜索窗口begin*/
// User
//  UAll
Ptr *UFindAll(User *pHeader)
{
    int opt = -1;
    while (true)
    {
        printf("请输入您要查询人员的方式:\n1身份\n2姓名\n3id\n4(学生)专业\n5(学生)年级\n0退出\n");
        scanf("%d", &opt);
        getchar();
        switch (opt)
        {
        case 1:
        {
            int useRank = read(1, 3, "请输入您想查询人员的身份：\n1管理员\n2教师\n3学生\n");
            if (useRank == -1)
            {
                printf("输入无效，请重试!\n");
                break;
            }
            return UFindRank(pHeader, useRank);
        }
        break;
        case 2:
        {
            char name[51];
            readStr(name, "请输入您想查询人员的姓名：\n");
            return UFindName(pHeader, name);
        }
        break;
        case 3:
        {
            char id[51];
            readStr(id, "请输入您想查询人员的id：\n");
            return UFindId_Ptr(pHeader, id);
        }
        break;
        case 4:
        {
            char major[51];
            readStr(major, "请输入您想查询学生的专业：\n");
            return UFindMajor(pHeader, major);
        }
        break;
        case 5:
        {
            char term[51];
            readStr(term, "请输入您想查询学生的年级(学年)：\n");
            return UFindTerm(pHeader, term);
        }
        break;
        case 0:
        {
            printf("取消查询成功!\n");
            return NULL;
        }
        default:
        {
            printf("输入无效，请重试!\n");
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
        onum = read(0, 7, "请输入您想查询类的方式:\n1全局搜索\n2按类搜索:\n4论文\n5项目\n6奖项\n7课程\n0退出");
        switch (opt)
        {
        case 1:
        {
            while (true)
            {
                onum = read(1, 2, "请输入您想全局搜索的对象:\n1 名称\n2 id\n");
                switch (onum)
                {
                case 1:
                {
                    readStr(search, "请输入您想全局查询的名称:\n");
                    return IFindName(pHeader, search, -1);
                }
                break;
                case 2:
                {
                    readStr(search, "请输入您想全局查询的id:\n");
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
                onum = read(1, 5, "请输入您想搜索论文的方式:\n1论文名称\n2论文等级\n3论文id\n4论文期刊/会议名称\n5论文发表时间\n");
                switch (onum)
                {
                case 1:
                {
                    readStr(search, "请输入您想搜索的论文名称\n");
                    return IFindName(pHeader, search, 4);
                }
                break;
                case 2:
                {
                    isearch = read(1, 9, "请输入您想搜索的论文等级\n");
                    return IFindLevel(pHeader, isearch, 4);
                }
                break;
                case 3:
                {
                    readStr(search, "请输入您想搜索的论文id\n");
                    return IPtrFindId(pHeader, search, 4);
                }
                break;
                case 4:
                {
                    readStr(search, "请输入您想搜索的论文期刊/会议名称\n");
                    return IFindHolder(pHeader, search, 4);
                }
                break;
                case 5:
                {
                    readStr(search, "请输入您想搜索的论文发表时间\n");
                    return IFindDate(pHeader, search, 4);
                }
                break;
                default:
                {
                    printf("输入无效，请重试!\n");
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
                onum = read(0, 5, "请输入您想搜索项目的方式:\n1项目名称\n2项目id\n3项目指导教师\n4项目立项时间\n5项目结项时间\n");
                switch (onum)
                {
                case 1:
                {
                    readStr(search, "请输入您想搜索的项目名称\n");
                    return IFindName(pHeader, search, 5);
                }
                break;
                case 2:
                {
                    readStr(search, "请输入您想搜索的项目id\n");
                    return IPtrFindId(pHeader, search, 5);
                }
                break;
                case 3:
                {
                    readStr(search, "请输入您想搜索的项目指导教师\n");
                    return IFindHolder(pHeader, search, 5);
                }
                break;
                case 4:
                {
                    readStr(search, "请输入您想搜索的项目立项时间\n");
                    return IFindDate(pHeader, search, 5);
                }
                break;
                case 5:
                {
                    readStr(search, "请输入您想搜索的项目结项时间\n");
                    return IFindDatend(pHeader, search, 5);
                }
                break;
                default:
                {
                    printf("输入无效，请重试!\n");
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
                onum = read(1, 4, "请输入您想搜索奖项的方式:\n1奖项名称\n2奖项等级\n3奖项主办单位\n4获奖时间\n");
                switch (onum)
                {
                case 1:
                {
                    readStr(search, "请输入您想搜索奖项的名称\n");
                    return IFindName(pHeader, search, 6);
                }
                break;
                case 2:
                {
                    printf("请输入您想搜索奖项的等级\n");
                    scanf("%d", &isearch);
                    getchar();
                    return IFindLevel(pHeader, isearch, 6);
                }
                break;
                case 3:
                {
                    readStr(search, "请输入您想搜索奖项的主办单位\n");
                    return IFindHolder(pHeader, search, 6);
                }
                break;
                case 4:
                {
                    readStr(search, "请输入您想搜索奖项的获奖时间\n");
                    return IFindDate(pHeader, search, 6);
                }
                break;
                default:
                {
                    printf("输入无效，请重试!\n");
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
                printf("请输入您想搜索课程的方式:\n1课程名称\n2任课教师\n3课程学院\n4课程哪次考试\n5课程专业\n");
                scanf("%d", &onum);
                getchar();
                switch (onum)
                {
                case 1:
                {
                    readStr(search, "请输入您想搜索课程的名称\n");
                    return IFindName(pHeader, search, 7);
                }
                break;
                case 2:
                {
                    readStr(search, "请输入您想搜索课程的任课教师\n");
                    return IPtrFindId(pHeader, search, 7);
                }
                break;
                case 3:
                {
                    readStr(search, "请输入您想搜索课程的对应学院\n");
                    return IFindHolder(pHeader, search, 7);
                }
                break;
                case 4:
                {
                    readStr(search, "请输入您想搜索课程的对应考试\n");
                    return IFindDate(pHeader, search, 7);
                }
                break;
                case 5:
                {
                    readStr(search, "请输入您想搜索课程的对应专业\n");
                    return IFindDatend(pHeader, search, 7);
                }
                break;
                default:
                {
                    printf("输入无效，请重试!\n");
                }
                break;
                };
            }
        }
        break;
        case 0:
        {
            printf("退出成功!\n");
            return NULL;
        }
        break;
        default:
        {
            printf("输入无效，请重新输入!\n");
        }
        break;
        }
    };
}
// Member
Ptr *MFindAll(Member *pHeader)
{
    char search[51];
    readStr(search, "请输入您想查询的成员id:\n");
    return MPtrFindId(pHeader, search);
}
/*搜索窗口end*/

/*链表打印begin*/
//格式输出字符串
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
// 单Member打印
//Message单项打印(消息本节点)
void S_print_Mess(User* UpHeader,Message* pNow){
    system("cls");
    if(pNow->messrank==1){
        printf("发送者:%s\n",UFindId(UpHeader,pNow->id)->next->name);
        printf("公告内容:\n");
        print_Str(pNow->text);
        printf("\n\t发送时间:%s",asctime(localtime(&(pNow->time))));
    }else if(pNow->messrank==2){
        printf("发送者:%s %s\n",UFindId(UpHeader,pNow->id)->next->name,pNow->id);
        printf("申诉内容:\n");
        print_Str(pNow->text);
        printf("\n\t发送时间:%s",asctime(localtime(&(pNow->time))));
    }
    return ;
}

/*列表打印*/
//Message列表打印
int M_print_Mess(Message* pHeader,int onum){
    if(!pHeader){
        printf("头节点无效，打印失败!\n");
        return 0;
    }
    int p = 0;
    int i = 1;
    Message *ptr = pHeader;
    printf("消息列表:\n");
    if (!(pHeader->next))
    {
        printf("无\n");
        return 0;
    }
    pHeader = pHeader->next;
    pHeader = ptr;
    printf("公告:\n");
    while (pHeader)
    {
        if ((pHeader->messrank) == 1)
        {
            p = 1;
            printf("消息%d :%10s...\n", i++,pHeader->text);
        }
        pHeader = pHeader->next;
    }
    if (p == 0)
    {
        printf("无\n");
    }
    p = 0;
    pHeader = ptr;
    if(onum==2){
        return i-1;
    }
    printf("申诉:\n");
    while (pHeader)
    {
        if ((pHeader->messrank) == 2)
        {
            p = 1;
            printf("消息%d:%10s...\n", i++,pHeader->text);
        }
        pHeader = pHeader->next;
    }
    if (p == 0)
    {
        printf("无\n");
    }
    p = 0;
    return i-1;    
}
// 一般User列表打印(浮动链头节点)
int M_print_U(Ptr *pHeader)
{
    if (!pHeader)
    {
        printf("头节点无效，打印失败!\n");
    }
    printf("%s\n", pHeader->namestr);
    if (!(pHeader->next))
    {
        printf("无\n");
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
// 身份User列表打印(浮动链头节点)
int M_print_RankU(Ptr *pHeader)
{
    int p = 0;
    pHeader = pHeader->next;
    int i = 1;
    Ptr *ptr = pHeader;
    printf("用户列表:\n");
    if (!(pHeader->next))
    {
        printf("无\n");
        return 0;
    }
    pHeader = ptr;
    printf("管理员:\n");
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
        printf("无\n");
    }
    p = 0;
    //
    pHeader = ptr;
    printf("教师:\n");
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
        printf("无\n");
    }
    p = 0;
    //
    pHeader = ptr;
    printf("学生:\n");
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
        printf("无\n");
    }
    p = 0;
    return i - 1;
}
// 一般Item列表打印(浮动链头节点,操作数)
int M_print_I(Ptr *pHeader)
{
    if (!pHeader)
    {
        printf("头节点无效，打印失败!\n");
    }
    printf("%s\n", pHeader->namestr);
    if (!(pHeader->next))
    {
        printf("无\n");
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
// 论文/奖项分等打印(浮动链头节点，操作数) 1论文,2奖项
int M_print_LevelI(Ptr *pHeader, int onum)
{
    int p = 0;
    pHeader = pHeader->next;
    int i = 1;
    Ptr *ptr = pHeader;
    if (onum == 1)
    {
        printf("论文列表:\n");
        if (!(pHeader))
        {
            printf("无\n");
            return 0;
        }
        pHeader = ptr;
        printf("第一级 T类：特种刊物论文:\n");
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
            printf("无\n");
        }
        p = 0;
        pHeader = ptr;
        printf("\n第二级 A类：权威核心刊物论文:\n");
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
            printf("无\n");
        }
        p = 0;
        pHeader = ptr;
        printf("\n第三级 B类：重要核心刊物论文:\n");
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
            printf("无\n");
        }
        p = 0;
        pHeader = ptr;
        printf("\n第四级 C类：一般核心刊物论文:\n");
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
            printf("无\n");
        }
        p = 0;
        pHeader = ptr;
        printf("\n第五级 D类：一般公开刊物论文:\n");
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
            printf("无\n");
        }
        p = 0;
        pHeader = ptr;
        printf("\n第六级 E类：受限公开刊物论文:\n");
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
            printf("无\n");
        }
        p = 0;
        pHeader = ptr;
        printf("\n第七级 国家级内刊:\n");
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
            printf("无\n");
        }
        p = 0;
        pHeader = ptr;
        printf("\n第八级 省级内刊:\n");
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
            printf("无\n");
        }
        p = 0;
        pHeader = ptr;
        printf("\n第九级 区级内刊:\n");
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
            printf("无\n");
        }
        p = 0;
        return i - 1;
    }
    else if (onum == 2)
    {
        printf("奖项列表:\n");
        if (!(pHeader))
        {
            printf("无\n");
            return 0;
        }
        pHeader = ptr;
        printf("特等奖:\n");
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
            printf("无\n");
        }
        p = 0;
        pHeader = ptr;
        printf("\n一等奖:\n");
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
            printf("无\n");
        }
        p = 0;
        pHeader = ptr;
        printf("\n二等奖:\n");
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
            printf("无\n");
        }
        p = 0;
        pHeader = ptr;
        printf("\n三等奖:\n");
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
            printf("无\n");
        }
        p = 0;
        return i - 1;
    }
}
//(课程用)学院专业打印
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
    printf("学院列表:\n");
    if (!ptr)
    {
        printf("无\n");
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
// 打印名字链(浮动链头节点)
int M_print_Name(Ptr *pHeader, int i)
{
    if (!pHeader)
    {
        printf("头节点无效，打印失败!\n");
        return 0;
    }
    if (!(pHeader->next))
    {
        printf("无\n");
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
// 一般Member列表打印（User头节点，Member头节点）
int M_print_Mem(User* UpHeader,Member *pHeader)
{
    if (!pHeader)
    {
        printf("头节点无效，打印失败!\n");
    }
    printf("成员列表:\n");
    if (!(pHeader->next))
    {
        printf("无\n");
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
// 论文Member列表打印
int M_print_PaperMem(User* UpHeader,Ptr *pHeader)
{
    int p = 0;
    printf("该论文作者列表:\n");
    if (!(pHeader->next))
    {
        printf("无\n");
        return 0;
    }
    pHeader = pHeader->next;
    Ptr *ptr = pHeader;
    int i = 1;
    printf("通讯作者:\n");
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
        printf("无\n");
    }
    p = 0;
    pHeader = ptr;
    printf("第一作者:\n");
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
        printf("无\n");
    }
    p = 0;
    pHeader = ptr;
    printf("第二作者:\n");
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
        printf("无\n");
    }
    p = 0;
    pHeader = ptr;
    printf("第三作者:\n");
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
        printf("无\n");
    }
    p = 0;
    pHeader = ptr;
    printf("其他作者:\n");
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
        printf("无\n");
    }
    p = 0;
    return i - 1;
}
// 课程Member列表打印
int M_print_CourseMem(User* UpHeader,Ptr *pHeader)
{
    printf("该课程成员列表:\n");
    if (!(pHeader->next)||!pHeader)
    {
        printf("无\n");
        return 0;
    }
    int p = 0;
    pHeader = pHeader->next;
    int i = 1;
    Ptr *ptr = pHeader;
    printf("教师:\n");
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
        printf("无\n");
    }
    p = 0;
    pHeader = ptr;
    printf("学生:\t\t分数\t\t绩点\n");
    while (pHeader)
    {
        if (UFindId(UpHeader,pHeader->pMember->next->id)->next->useRank==3)
        {
            p = 1;
            if(sameFloat(pHeader->pMember->next->point,0)){
            printf("%d %s\t未结算\t未结算\n", i++, UFindId(UpHeader,pHeader->pMember->next->id)->next->name);
            }else {
            printf("%d %s\t%d\t%.4f\n", i++, UFindId(UpHeader,pHeader->pMember->next->id)->next->name, pHeader->pMember->next->rankscore, pHeader->pMember->next->point);
            }
        }
        pHeader = pHeader->next;
    }
    if (p == 0)
    {
        printf("无\n");
    }
    p = 0;
    return i - 1;
}
//用户参与项列表打印(onum,-1打印全局，4打印论文，5打印项目，6打印奖项，7打印课程)(opt,2教师,3学生)
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
        printf("该教师参与的项目类:\n");
        if(opt==3)
        printf("该学生参与的项目类:\n");
        if (!(pHeader))
        {
            printf("无\n");
            return 0;
        }
        pHeader = ptr;
        printf("论文列表\t所在作者顺序:\n");
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
            printf("无\n");
        }
        p = 0;
        pHeader = ptr;
        printf("项目列表:\t所在顺序\n");
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
            printf("无\n");
        }
        p = 0;
        pHeader = ptr;
        printf("奖项列表:\t所在顺序\n");
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
            printf("无\n");
        }
        p = 0;
        pHeader = ptr;
        if(opt==2){
        printf("教授课程列表:\n");
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
            printf("无\n");
        }
        p = 0;            
        }
        if(opt==3){
        printf("课程列表:\t总分数\t绩点\n");
        while (pHeader)
        {
            if ((pHeader->pItem->next->itemRank) == 7)
            {
                p = 1;
                if(pHeader->pMember->next->rankscore==0){
                printf("%s\t未结算\t未结算\n", pHeader->pItem->next->name);
                }else{
                printf("%s\t%d\t%f\n", pHeader->pItem->next->name,pHeader->pMember->next->rankscore,pHeader->pMember->next->point);
                }
            }
            pHeader = pHeader->next;
        }
        if (p == 0)
        {
            printf("无\n");
        }
        p = 0;
        }        
        return 0;           
    }
    if(onum==4){
        printf("用户参与项:\n");
        if (!(pHeader))
        {
            printf("无\n");
            return 0;
        }
        pHeader = ptr;
        printf("论文列表\t所在作者顺序:\n");
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
            printf("无\n");
        }
        p = 0;
        return 0;        
    }
    if(onum==5){
        printf("用户参与项:\n");
        if (!(pHeader))
        {
            printf("无\n");
            return 0;
        }
        pHeader = ptr;
        printf("项目列表:\t所在顺序\n");
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
            printf("无\n");
        }
        p = 0;        
    }
    if(onum==6){
        printf("用户参与项:\n");
        if (!(pHeader))
        {
            printf("无\n");
            return 0;
        }
        pHeader = ptr;
        printf("奖项列表:\t所在顺序\n");
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
            printf("无\n");
        }
        p = 0;        
    }
    if(onum==7){
        printf("用户参与项:\n");
        if (!(pHeader))
        {
            printf("无\n");
            return 0;
        }
        pHeader = ptr;
        printf("教授课程列表:\n");
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
            printf("无\n");
        }
        p = 0;
        return i-1;   
}
}
/*链表打印end***/

/*修改节点器begin*/
// User修改器(对应项指针,操作数)
void fix_U(User *pNow, int onum)
{
    switch (onum)
    {
    case 1:
    {
        readStr(pNow->name, "请输入新用户姓名:\n");
    }
    break;
    case 2:
    {
        readStr(pNow->id, "请输入用户新号码:\n");
    }
    break;
    case 3:
    {
        readStr(pNow->password, "请输入用户新密码:\n");
    }
    break;
    case 4:
    {
        readStr(pNow->faculty, "请输入用户新学院:\n");
    }
    break;
    case 5:
        if (pNow->useRank == 3)
        {
            readStr(pNow->major, "请输入用户的新专业\n");
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
            readStr(pNow->term, "请输入用户的学期\n");
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
// Item修改器(对应项指针,操作数)
void fix_I(Item *pNow, int onum)
{
    // paper
    if (pNow->itemRank == 4)
    {
        switch (onum)
        {
        case 1:
        {
            pNow->level=read(1,9,"请输入新的论文等级：\n");
        }
        break;
        case 2:
        {
            printf("请输入新的论文加分：\n");
            scanf("%f", &(pNow->credit));
            getchar();
        }
        break;
        case 3:
        {
            readStr(pNow->name, "请输入新的名称：\n");
        }
        break;
        case 4:
        {
            readStr(pNow->id, "请输入新的论文号：\n");
        }
        break;
        case 5:
        {
            readStr(pNow->holder, "请输入新的期刊/会议名称：\n");
        }
        break;
        case 6:
        {
            readStr(pNow->date, "请输入新的发表时间：\n");
        }
        break;
        case 7:
        {
            readStr(pNow->datend, "请输入新的卷期：\n");
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
            readStr(pNow->name, "请输入新的名称\n");
        }
        break;
        case 2:
        {
            readStr(pNow->id, "请输入新的项目编号：\n");
        }
        break;
        case 3:
        {
            readStr(pNow->holder, "请输入新的指导老师名单：\n");
        }
        break;
        case 4:
        {
            readStr(pNow->date, "请输入新的立项时间：\n");
        }
        break;
        case 5:
        {
            readStr(pNow->datend, "请输入新的结项时间：\n");
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
        pNow->level=read(0,3,"请输入新的论文等级：\n")+1;

        }
        break;
        case 2:
        {
            readStr(pNow->name, "请输入新的名称\n");
        }
        break;
        case 3:
        {
            readStr(pNow->holder, "请输入新的主办单位：\n");
        }
        break;
        case 4:
        {
            readStr(pNow->date, "请输入新的获奖时间：\n");
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
            printf("请输入新的课程学分\n");
            scanf("%f", (&pNow->credit));
            getchar();
        }
        break;
        case 2:
        {
            readStr(pNow->name, "请输入新的名称\n");
        }
        break;
        case 3:
        {
            readStr(pNow->id, "请输入新的课程编号：\n");
        }
        break;
        case 4:
        {
            readStr(pNow->holder, "请输入新的学院：\n");
        }
        break;
        case 5:
        {
            readStr(pNow->date, "请输入新的对应学期：\n");
        }
        break;
        case 6:
        {
            readStr(pNow->datend, "请输入新的对应专业：\n");
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
// Member修改器(对应项指针,操作数)
void fix_M(Member *pNow, int onum)
{
    switch (onum)
    {
    case 1:
    {
        readStr(pNow->id, "请输入新的成员id：\n");
    }
    break;
    case 2:
    {
        printf("请输入新的顺序/分数\n");
        scanf("%d", &(pNow->rankscore));
        getchar();
    }
    break;
    case 3:
    {
        printf("请输入新的绩点\n");
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
/*修改节点器end***/
