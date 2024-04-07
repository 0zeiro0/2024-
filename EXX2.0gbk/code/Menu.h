#include "file.h"
/*ToolsBegin*/
// �̶���ʱ��
void halt();
// ������(0������Ч���룺1�����˳��ɹ�)
void nout(int opt);
// ��ʾ��������ȡ��(���ޣ�����,��ʾ��)���û�������Ч����-1
int read(int low, int high, char tip[]);
// ��ʾ���ַ�����ȡ��
void readStr(char *p, const char tip[]);
//��ʾ�� ���ַ�����ȡ��
void readLongStr(char *p, const char tip[]);
//�����������(ʵ��ֵ����׼ֵ)
int sameFloat(float real,float aim);
/*ToolsEnd***/

// ��ʼ����
void EnterAll(User *UpHeader, Item *IpHeader, Message *MesspHeader);
// ������
void LogIn(User *UpHeader, Item *IpHeader, Message *MesspHeader);
//����ԱMenu
void ManegerMenu(User *UpHeader, Item *IpHeader, Message *MpHeader,char* name);
//��ʦMenu
void TeacherMenu(User *UpHeader, Item *IpHeader, Message *MpHeader);
//ѧ��Menu
void StudentMenu(User *UpHeader, Item *IpHeader, Message *MpHeader);

//ȫ֪ͨ�鿴���(onum1��ʾ����Ա�鿴��2��ʾѧ���鿴)
void MessageAllEnter(User* UpHeader,Message* MpHeader,int onum);
//ȫ�û��鿴���
void UserAllEnter(User *UpHeader,Item* IpHeader);
//ȫ���Ĳ鿴���
void PaperAllEnter(User* UpHeader,Item *IpHeader);
//ȫ��Ŀ��鿴���
void ProjectAllEnter(User *UpHeader,Item *IpHeader);
//ȫ����鿴���
void AwardAllEnter(User *UpHeader,Item* IpHeader);
// ȫ�γ̲鿴��
void Course_AllLook(User *UpHeader,Item *IpHeader);

//���û��鿴���
void S_User(User* UpHeader,Item* IpHeader,Ptr* p);
// User������
User *in_User(User *pTail, int onum);
//��������鿴���
void S_Item(User* UpHeader,Item* IpHeader,Ptr* p);
//����Ŀ���Ա�鿴���(opt:4����5��Ŀ6����7�γ�)
void S_Item_Member(User* UpHeader,Item* pNow,int opt);
// 1ĳרҵ/2ĳ��ʦ�γ̲鿴��
void Course_Look(User *UpHeader,Item *pHeader, char name[]);

/*���봴��Node*begin*/
// Item������,�û���ѡ������(-1),4����5��Ŀ6����7�γ�
Item *in_Item(Item *pTail, int onum);
// Member������
Member *in_Member(User* UpHeader,Member *MempHeader,int itemclass);
// ���ߴ�������������Ϣβ�ڵ㣩
Message *in_Mess(User* UpHeader,Message *pTail, int opt);
/*���봴��Node*end*/

/*��������begin*/
// User
//  UAll
Ptr *UFindAll(User *pHeader);
// Item
Ptr *IFindAll(Item *pHeader);
// Member
Ptr *MFindAll(Member *pHeader);
/*��������end*/

/*�����ӡbegin*/

/*�б��ӡ*/
//Message�б��ӡ
int M_print_Mess(Message* pHeader,int onum);
//һ��User�б��ӡ(������ͷ�ڵ�)
int M_print_U(Ptr *pHeader);
//���User�б��ӡ(������ͷ�ڵ�)
int M_print_RankU(Ptr* pHeader);
//һ��Item�б��ӡ(������ͷ�ڵ�,������)
int M_print_I(Ptr *pHeader);
//(�γ���)ѧԺרҵ��ӡ
int M_print_Major(Item* pIHeader,Ptr** pout);
//����/����ֵȴ�ӡ(������ͷ�ڵ㣬������) 1����,2����
int M_print_LevelI(Ptr* pHeader,int onum);
// ��ӡ������(������ͷ�ڵ�)
int M_print_Name(Ptr *pHeader, int i);
// һ��Member�б��ӡ��������ͷ�ڵ㣩
int M_print_Mem(User* UpHeader,Member *pHeader);
// ����Member�б��ӡ
int M_print_PaperMem(User* UpHeader,Ptr *pHeader);
// �γ�Member�б��ӡ
int M_print_CourseMem(User* UpHeader,Ptr *pHeader);
//�û��������б��ӡ(onum,-1��ӡȫ�֣�4��ӡ���ģ�5��ӡ��Ŀ��6��ӡ���7��ӡ�γ�)(opt,2��ʦ,3ѧ��)
int M_print_UserDone(Ptr* pHeader,int onum,int opt);
//Message�����ӡ(��Ϣ���ڵ�)
void S_print_Mess(User* UpHeader,Message* pNow);
/*�����ӡend***/


/*�޸Ľڵ���begin*/
//User�޸���(��Ӧ��ָ��,������)
void fix_U(User *pNow, int onum);
//Item�޸���(��Ӧ��ָ��,������)
void fix_I(Item *pNow, int onum);
//Member�޸���(��Ӧ��ָ��,������)
void fix_M(Member * pNow, int onum);
/*�޸Ľڵ���end***/
