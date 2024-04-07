// // 论文查看器
// void PaperLook(Item *pHeader, int opt)
// {
//     int onum;
//     int choice;
//     int max;
//     while (true)
//     {
//         system("cls");
//         switch (opt)
//         {
//         case 1:
//         {
//             Ptr *p = IFindRank(pHeader, 4);
//             max = M_print_I(p);
//             //
//             onum = read(0, 3, "\n请选择您想进行的操作:\n1查看论文项\n2新建论文项\n3删除论文项\n0退出全局论文查看\n");
//             switch (onum)
//             {
//             case -1:
//             {
//                 nout(0);
//                 halt;
//                 clear_PList(p, 0);
//                 continue;
//             }
//             break;
//             case 0:
//             {
//                 nout(1);
//                 halt;
//                 clear_PList(p, 0);
//                 return;
//             }
//             break;
//             case 1:
//             {
//                 choice = read(1, max, "请输入您想查看论文的标号\n");
//                 Ptr *pLook = PFindNum(p, choice);
//             }
//             break;
//             case 2:
//             {
//                 in_Item(IFindTail(pHeader), 4);
//                 clear_PList(p, 0);
//                 continue;
//             }
//             break;
//             case 3:
//             {
//                 choice = read(1, max, "请输入您想删除论文的标号\n");
//                 if (choice == -1)
//                 {
//                     nout(0);
//                     halt;
//                     clear_PList(p, 0);
//                     continue;
//                 }
//                 delete_I(PFindNum(p, choice)->pItem);
//                 printf("删除成功!\n");
//                 halt;
//                 clear_PList(p, 0);
//             }
//             }
//             //
//         }
//         break;
//         case 2:
//         {
//             printf("1第一级_T类：特种刊物论文\n2第二级_A类：权威核心刊物论文\n3第三级_B类：重要核心刊物论文\n4第四级_C类：一般核心刊物论文\n5第五级_D类：一般公开刊物论文\n6第六级_E类：受限公开刊物论文\n7第七级_国家级内刊\n8第八级_省级内刊\n9第九级_区级内刊\n");
//             choice = read(1, 9, "请输入您要查询的等级\n");
//             if (choice == -1)
//             {
//                 nout(0);
//                 halt;
//                 continue;
//             }
//             else
//             {
//                 Ptr *p = IFindLevel(pHeader, choice, 4);
//                 max = M_print_I(p);
//                 //
//                 system("cls");
//                 onum = read(0, 3, "\n请选择您想进行的操作:\n1查看论文项\n2新建论文项\n3删除论文项\n0退出分等论文查看\n");
//                 switch (onum)
//                 {
//                 case -1:
//                 {
//                     nout(0);
//                     halt;
//                     clear_PList(p, 0);
//                     continue;
//                 }
//                 break;
//                 case 0:
//                 {
//                     nout(1);
//                     halt;
//                     clear_PList(p, 0);
//                     return;
//                 }
//                 break;
//                 case 1:
//                 {
//                     choice = read(1, max, "请输入您想查看论文的标号\n");
//                     Ptr *pLook = PFindNum(p, choice);
//                 }
//                 break;
//                 case 2:
//                 {
//                     in_Item(IFindTail(pHeader), 4);
//                     clear_PList(p, 0);
//                     continue;
//                 }
//                 break;
//                 case 3:
//                 {
//                     choice = read(1, max, "请输入您想删除论文的标号\n");
//                     if (choice == -1)
//                     {
//                         nout(0);
//                         halt;
//                         clear_PList(p, 0);
//                         continue;
//                     }
//                     delete_I(PFindNum(p, choice)->pItem);
//                     printf("删除成功!\n");
//                     halt;
//                     clear_PList(p, 0);
//                 }
//                 }
//                 //
//             }
//         }
//         default:{         
//         }
//             break;
//         }
//     }
// };

// // 项目查看器
// void ProjectLook(Item *pHeader, int opt)
// {
//     int onum;
//     while (true)
//     {
//         system("cls");
//         switch (opt)
//         {
//         case 1:
//         {
//             Ptr *p = IFindRank(pHeader, 5);
//             M_print_I(p);
//             //
//             onum = read(0, 1, "\n请选择您想进行的操作:\n1新建项目项\n0退出项目查看\n");
//             switch (onum)
//             {
//             case -1:
//             {
//                 nout(0);
//                 halt;
//                 clear_PList(p, 0);
//                 continue;
//             }
//             break;
//             case 0:
//             {
//                 nout(1);
//                 halt;
//                 clear_PList(p, 0);
//                 return;
//             }
//             break;
//             case 1:
//             {
//                 in_Item(IFindTail(pHeader), 5);
//                 clear_PList(p, 0);
//                 continue;
//             }
//             break;
//             }
//             //
//         }
//         break;
//         case 2:{
//         }
//         break;
//         default:{
//         }
//         break;
//         };
//     }
// }

// // 奖项查看器
// void AwardLook(Item *pHeader, int opt)
// {
//     int onum, choice;
//     while (true)
//     {
//         system("cls");
//         switch (opt)
//         {
//         case 1:
//         {
//             Ptr *p = IFindRank(pHeader, 6);
//             M_print_I(p);
//             //
//             onum = read(0, 1, "\n请选择您想进行的操作:\n1新建奖项\n0退出奖项查看\n");
//             switch (onum)
//             {
//             case -1:
//             {
//                 nout(0);
//                 halt;
//                 clear_PList(p, 0);
//                 continue;
//             }
//             break;
//             case 0:
//             {
//                 nout(1);
//                 halt;
//                 clear_PList(p, 0);
//                 return;
//             }
//             break;
//             case 1:
//             {
//                 in_Item(IFindTail(pHeader), 6);
//                 clear_PList(p, 0);
//                 continue;
//             }
//             break;
//             }
//             //
//         }
//         break;
//         case 2:
//         {
//             printf("0特等奖\n1一等奖\n2二等奖\n3三等奖\n");
//             choice = read(0, 3, "请输入您要查询的等级\n");
//             system("cls");
//             if (choice == -1)
//             {
//                 nout(0);
//                 halt;
//                 continue;
//             }
//             else
//             {
//                 choice++;
//                 Ptr *p = IFindLevel(pHeader, choice, 6);
//                 M_print_I(p);
//                 //
//                 onum = read(0, 1, "\n请选择您想进行的操作:\n1新建奖项\n0退出奖项查看\n");
//                 switch (onum)
//                 {
//                 case -1:
//                 {
//                     nout(0);
//                     halt;
//                     clear_PList(p, 0);
//                     continue;
//                 }
//                 break;
//                 case 0:
//                 {
//                     nout(1);
//                     halt;
//                     clear_PList(p, 0);
//                     return;
//                 }
//                 break;
//                 case 1:
//                 {
//                     in_Item(IFindTail(pHeader), 7);
//                     clear_PList(p, 0);
//                     continue;
//                 }
//                 break;
//                 }
//                 //
//             }
//         }
//         break;
//         default:
//         {
//         }
//         break;
//         }
//     }
// }

// // 全用户分类查看入口
// void UserEnter(User *UpHeader)
// {
//     while (true)
//     {
//         system("cls");
//         int opt = read(0, 3, "请选择您想查看的用户:\n\t1管理员\n\t2教师\n\t3学生\n或：0退出\n");
//         switch (opt)
//         {
//         case -1:
//         {
//             nout(0);
//             halt();
//             continue;
//         }
//         break;
//         case 0:
//         {
//             nout(1);
//             halt();
//             return;
//         }
//         break;
//         default:
//         {
//             UserLook(UpHeader, opt);
//         }
//         break;
//         }
//     }
// }

// // 全用户分类查看器
// void UserLook(User *UpHeader, int opt)
// {
//     while (true)
//     {
//         system("cls");
//         Ptr *p = UFindRank(UpHeader, opt);
//         M_print_U(p);
//         switch (read(0, 1, "\n请选择您想进行的操作:\n\t1新建用户\n\t0退出学生查看\n"))
//         {
//         case 1:
//         {
//             in_User(UFindTail(UpHeader), -1);
//             clear_PList(p, 0);
//         }
//         break;
//         case 0:
//         {
//             nout(1);
//             clear_PList(p, 0);
//             halt();
//             return;
//         }
//         break;
//         case -1:
//         {
//             nout(0);
//             halt();
//         }
//         break;
//         }
//         clear_PList(p, 0);
//     }
// }

// // 某学院专业查看器
// void Course_Major_Look(Item *pHeader, char name[])
// {
//     Ptr *p = NULL;
//     int opt = -1;
//     //
//     while (true)
//     {
//         system("cls");
//         p = NFind_Course(pHeader, 8, name);
//         printf("%s专业列表：\n", name);
//         opt = M_print_Name(p, 1);
//         opt = read(0, opt, "\n请选择您想查看的专业：\n或：0退出\n");
//         if (opt == -1)
//         {
//             nout(0);
//             halt();
//             clear_PList(p, 0);
//             continue;
//         }
//         else if (opt == 0)
//         {
//             nout(1);
//             halt();
//             clear_PList(p, 0);
//             return;
//         }
//         else
//         {
//         }
//     }
// }

// // 课程学院查看器
// void Course_Department_Look(Item *pHeader)
// {
//     Ptr *p = NULL;
//     int opt = -1;
//     int onum = -1;
//     while (true)
//     {
//         system("cls");
//         p = NFind_Course(pHeader, 6, "000");
//         printf("学院列表：\n");
//         opt = M_print_Name(p, 1);
//         opt = read(0, opt, "\n请选择您想查看的学院：\n或：0退出\n");
//         if (opt == -1)
//         {
//             nout(0);
//             halt();
//             clear_PList(p, 0);
//             continue;
//         }
//         if (opt == 0)
//         {
//             nout(1);
//             halt();
//             clear_PList(p, 0);
//             return;
//         }
//     }
// }




