// // ���Ĳ鿴��
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
//             onum = read(0, 3, "\n��ѡ��������еĲ���:\n1�鿴������\n2�½�������\n3ɾ��������\n0�˳�ȫ�����Ĳ鿴\n");
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
//                 choice = read(1, max, "����������鿴���ĵı��\n");
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
//                 choice = read(1, max, "����������ɾ�����ĵı��\n");
//                 if (choice == -1)
//                 {
//                     nout(0);
//                     halt;
//                     clear_PList(p, 0);
//                     continue;
//                 }
//                 delete_I(PFindNum(p, choice)->pItem);
//                 printf("ɾ���ɹ�!\n");
//                 halt;
//                 clear_PList(p, 0);
//             }
//             }
//             //
//         }
//         break;
//         case 2:
//         {
//             printf("1��һ��_T�ࣺ���ֿ�������\n2�ڶ���_A�ࣺȨ�����Ŀ�������\n3������_B�ࣺ��Ҫ���Ŀ�������\n4���ļ�_C�ࣺһ����Ŀ�������\n5���弶_D�ࣺһ�㹫����������\n6������_E�ࣺ���޹�����������\n7���߼�_���Ҽ��ڿ�\n8�ڰ˼�_ʡ���ڿ�\n9�ھż�_�����ڿ�\n");
//             choice = read(1, 9, "��������Ҫ��ѯ�ĵȼ�\n");
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
//                 onum = read(0, 3, "\n��ѡ��������еĲ���:\n1�鿴������\n2�½�������\n3ɾ��������\n0�˳��ֵ����Ĳ鿴\n");
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
//                     choice = read(1, max, "����������鿴���ĵı��\n");
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
//                     choice = read(1, max, "����������ɾ�����ĵı��\n");
//                     if (choice == -1)
//                     {
//                         nout(0);
//                         halt;
//                         clear_PList(p, 0);
//                         continue;
//                     }
//                     delete_I(PFindNum(p, choice)->pItem);
//                     printf("ɾ���ɹ�!\n");
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

// // ��Ŀ�鿴��
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
//             onum = read(0, 1, "\n��ѡ��������еĲ���:\n1�½���Ŀ��\n0�˳���Ŀ�鿴\n");
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

// // ����鿴��
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
//             onum = read(0, 1, "\n��ѡ��������еĲ���:\n1�½�����\n0�˳�����鿴\n");
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
//             printf("0�صȽ�\n1һ�Ƚ�\n2���Ƚ�\n3���Ƚ�\n");
//             choice = read(0, 3, "��������Ҫ��ѯ�ĵȼ�\n");
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
//                 onum = read(0, 1, "\n��ѡ��������еĲ���:\n1�½�����\n0�˳�����鿴\n");
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

// // ȫ�û�����鿴���
// void UserEnter(User *UpHeader)
// {
//     while (true)
//     {
//         system("cls");
//         int opt = read(0, 3, "��ѡ������鿴���û�:\n\t1����Ա\n\t2��ʦ\n\t3ѧ��\n��0�˳�\n");
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

// // ȫ�û�����鿴��
// void UserLook(User *UpHeader, int opt)
// {
//     while (true)
//     {
//         system("cls");
//         Ptr *p = UFindRank(UpHeader, opt);
//         M_print_U(p);
//         switch (read(0, 1, "\n��ѡ��������еĲ���:\n\t1�½��û�\n\t0�˳�ѧ���鿴\n"))
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

// // ĳѧԺרҵ�鿴��
// void Course_Major_Look(Item *pHeader, char name[])
// {
//     Ptr *p = NULL;
//     int opt = -1;
//     //
//     while (true)
//     {
//         system("cls");
//         p = NFind_Course(pHeader, 8, name);
//         printf("%sרҵ�б�\n", name);
//         opt = M_print_Name(p, 1);
//         opt = read(0, opt, "\n��ѡ������鿴��רҵ��\n��0�˳�\n");
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

// // �γ�ѧԺ�鿴��
// void Course_Department_Look(Item *pHeader)
// {
//     Ptr *p = NULL;
//     int opt = -1;
//     int onum = -1;
//     while (true)
//     {
//         system("cls");
//         p = NFind_Course(pHeader, 6, "000");
//         printf("ѧԺ�б�\n");
//         opt = M_print_Name(p, 1);
//         opt = read(0, opt, "\n��ѡ������鿴��ѧԺ��\n��0�˳�\n");
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




