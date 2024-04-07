#include "file.h"
/*ToolsBegin*/
// 固定延时器
void halt();
// 报告器(0，报无效输入：1，报退出成功)
void nout(int opt);
// 提示词整数读取器(下限，上限,提示词)，用户输入无效返回-1
int read(int low, int high, char tip[]);
// 提示词字符串读取器
void readStr(char *p, const char tip[]);
//提示词 长字符串读取器
void readLongStr(char *p, const char tip[]);
//浮点数检测器(实际值，界准值)
int sameFloat(float real,float aim);
/*ToolsEnd***/

// 初始界面
void EnterAll(User *UpHeader, Item *IpHeader, Message *MesspHeader);
// 登入器
void LogIn(User *UpHeader, Item *IpHeader, Message *MesspHeader);
//管理员Menu
void ManegerMenu(User *UpHeader, Item *IpHeader, Message *MpHeader,char* name);
//教师Menu
void TeacherMenu(User *UpHeader, Item *IpHeader, Message *MpHeader);
//学生Menu
void StudentMenu(User *UpHeader, Item *IpHeader, Message *MpHeader);

//全通知查看入口(onum1表示管理员查看，2表示学生查看)
void MessageAllEnter(User* UpHeader,Message* MpHeader,int onum);
//全用户查看入口
void UserAllEnter(User *UpHeader,Item* IpHeader);
//全论文查看入口
void PaperAllEnter(User* UpHeader,Item *IpHeader);
//全项目类查看入口
void ProjectAllEnter(User *UpHeader,Item *IpHeader);
//全奖项查看入口
void AwardAllEnter(User *UpHeader,Item* IpHeader);
// 全课程查看器
void Course_AllLook(User *UpHeader,Item *IpHeader);

//单用户查看入口
void S_User(User* UpHeader,Item* IpHeader,Ptr* p);
// User创建器
User *in_User(User *pTail, int onum);
//单素质类查看入口
void S_Item(User* UpHeader,Item* IpHeader,Ptr* p);
//单项目类成员查看入口(opt:4论文5项目6奖项7课程)
void S_Item_Member(User* UpHeader,Item* pNow,int opt);
// 1某专业/2某教师课程查看器
void Course_Look(User *UpHeader,Item *pHeader, char name[]);

/*输入创建Node*begin*/
// Item输入器,用户自选输入类(-1),4论文5项目6奖项7课程
Item *in_Item(Item *pTail, int onum);
// Member创建器
Member *in_Member(User* UpHeader,Member *MempHeader,int itemclass);
// 申诉创建发送器（消息尾节点）
Message *in_Mess(User* UpHeader,Message *pTail, int opt);
/*输入创建Node*end*/

/*搜索窗口begin*/
// User
//  UAll
Ptr *UFindAll(User *pHeader);
// Item
Ptr *IFindAll(Item *pHeader);
// Member
Ptr *MFindAll(Member *pHeader);
/*搜索窗口end*/

/*链表打印begin*/

/*列表打印*/
//Message列表打印
int M_print_Mess(Message* pHeader,int onum);
//一般User列表打印(浮动链头节点)
int M_print_U(Ptr *pHeader);
//身份User列表打印(浮动链头节点)
int M_print_RankU(Ptr* pHeader);
//一般Item列表打印(浮动链头节点,操作数)
int M_print_I(Ptr *pHeader);
//(课程用)学院专业打印
int M_print_Major(Item* pIHeader,Ptr** pout);
//论文/奖项分等打印(浮动链头节点，操作数) 1论文,2奖项
int M_print_LevelI(Ptr* pHeader,int onum);
// 打印名字链(浮动链头节点)
int M_print_Name(Ptr *pHeader, int i);
// 一般Member列表打印（浮动链头节点）
int M_print_Mem(User* UpHeader,Member *pHeader);
// 论文Member列表打印
int M_print_PaperMem(User* UpHeader,Ptr *pHeader);
// 课程Member列表打印
int M_print_CourseMem(User* UpHeader,Ptr *pHeader);
//用户参与项列表打印(onum,-1打印全局，4打印论文，5打印项目，6打印奖项，7打印课程)(opt,2教师,3学生)
int M_print_UserDone(Ptr* pHeader,int onum,int opt);
//Message单项打印(消息本节点)
void S_print_Mess(User* UpHeader,Message* pNow);
/*链表打印end***/


/*修改节点器begin*/
//User修改器(对应项指针,操作数)
void fix_U(User *pNow, int onum);
//Item修改器(对应项指针,操作数)
void fix_I(Item *pNow, int onum);
//Member修改器(对应项指针,操作数)
void fix_M(Member * pNow, int onum);
/*修改节点器end***/
