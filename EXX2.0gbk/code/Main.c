#include "Menu.h"
int main()
{
    // ��ͷ��ʼ��
    User *UpHeader = initUser();
    Item *IpHeader = initItem();
    Message *MpHeader = initMessage();
    // �����ļ�
    getF_User(UpHeader);
    getF_Item(IpHeader);
    getF_Mess(MpHeader);
    //����У��
    Get_GPA(UpHeader,IpHeader);
    // �û����
    EnterAll(UpHeader, IpHeader, MpHeader);
    // �����ļ�
    toF_Item(IpHeader);
    toF_User(UpHeader);
    toF_Mess(MpHeader);
    // �������
    clear_UList(UpHeader,0);
    clear_ItemList(IpHeader,0);
    clear_MessList(MpHeader,0);
    return 0;
}