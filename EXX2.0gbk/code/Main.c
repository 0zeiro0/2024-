#include "Menu.h"
int main()
{
    // 表头初始化
    User *UpHeader = initUser();
    Item *IpHeader = initItem();
    Message *MpHeader = initMessage();
    // 加载文件
    getF_User(UpHeader);
    getF_Item(IpHeader);
    getF_Mess(MpHeader);
    //数据校正
    Get_GPA(UpHeader,IpHeader);
    // 用户入口
    EnterAll(UpHeader, IpHeader, MpHeader);
    // 保存文件
    toF_Item(IpHeader);
    toF_User(UpHeader);
    toF_Mess(MpHeader);
    // 清除链表
    clear_UList(UpHeader,0);
    clear_ItemList(IpHeader,0);
    clear_MessList(MpHeader,0);
    return 0;
}