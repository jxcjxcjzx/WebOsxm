#include "stdafx.h"
#include <windows.h>
#include <windowsx.h>
#include "resource.h"
#include "MainDlg.h"

/*
Template designed by RuPeng.com. Please visit http://www.rupeng.com for more information
��������http://www.rupeng.com����ѧ�������ѧϰ�������ṩ���������Ƶѧϰ�̳̣��ṩ���Ի�һ��һѧϰָ��
*/
BOOL WINAPI Main_Proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
        HANDLE_MSG(hWnd, WM_INITDIALOG, Main_OnInitDialog);
        HANDLE_MSG(hWnd, WM_COMMAND, Main_OnCommand);
		HANDLE_MSG(hWnd,WM_CLOSE, Main_OnClose);
    }

    return FALSE;
}

BOOL Main_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{  
	    TCHAR str1[30]="������(�������)";
		TCHAR str2[30]="������(�����®)";
	    TCHAR str3[30]="�Ϫɳ(ʮ������)";
	    TCHAR str4[30]="�Ϫɳ(˭������)";	
	    TCHAR str5[30]="�Ϫɳ(��ѩ����)";
	    TCHAR str6[10]="������";
	    TCHAR str7[20]="������ ��Ϧ�Ų� ";
	    TCHAR str8[10]="��ɣ��";
	    TCHAR str9[30]="����ľ����(�ӽ���ʯ)";
        TCHAR str10[20]="�佭�� ";
		TCHAR str11[30]="����ľ����(��겻��)";
	    TCHAR str12[20]="������ (����һƬ)";
		TCHAR str13[20]="������ (˷�紵ɢ)";
		TCHAR str14[20]="������ ";
		TCHAR str15[20]="�ٽ��� ";
		TCHAR str16[20]="���к� ";
		TCHAR str17[20]="������ (Ʈ��ֻ��)";
		TCHAR str18[20]="������ ";
		TCHAR str19[20]="����ľ����";
		TCHAR str20[20]="������ ����������";
		TCHAR str21[20]="������ (�º��о�)";
		TCHAR str22[20]="�ٽ��� ����";
		TCHAR str23[20]="��ɣ�� ����ӽ÷��";
		TCHAR str24[20]="������ ��������";
		TCHAR str25[20]="��ɣ�� (ͮ�ƾþ�) ";
		TCHAR str26[20]="��ɣ�� (�һ�����)";
		TCHAR str27[30]="������  ���������и�";
		TCHAR str28[20]="���ô�";
		TCHAR str29[20]="�촰�� ";
		TCHAR str30[20]="����ľ����";
		TCHAR str31[50]="���к�   �������ϻ���ʱ��Ϊ СӰ  ";
		TCHAR str32[20]="�ٽ��� ��ƽ����";
		TCHAR str33[20]="������  ";
		TCHAR str34[20]="����ľ���� ����  ";
		TCHAR str35[30]="����˼";
		TCHAR str36[20]="ľ���� ��ž�����";
		TCHAR str37[20]="ɽ���� ";
		TCHAR str38[20]="��筴�";
		TCHAR str39[50]="�仨ʱ  ";
		TCHAR str40[20]="̯���Ϫɳ  ";
		TCHAR str41[20]="������";

		HWND hwnd1=GetDlgItem(hwnd,IDC_xuanze);
		HWND hwnd2=GetDlgItem(hwnd,IDC_xuanze2);
		HWND hwnd3=GetDlgItem(hwnd,IDC_xuanze3);
		HWND hwnd4=GetDlgItem(hwnd,IDC_xuanze4);
		HWND hwnd5=GetDlgItem(hwnd,IDC_xuanze5);

		ComboBox_AddString(hwnd1,str1);
		ComboBox_AddString(hwnd1,str2);
		ComboBox_AddString(hwnd1,str3);
		ComboBox_AddString(hwnd1,str4);
		ComboBox_AddString(hwnd1,str5);
		ComboBox_AddString(hwnd1,str6);
		ComboBox_AddString(hwnd1,str7);
		ComboBox_AddString(hwnd1,str8);
		ComboBox_AddString(hwnd2,str9);
		ComboBox_AddString(hwnd2,str10);
		ComboBox_AddString(hwnd2,str11);
		ComboBox_AddString(hwnd2,str12);
		ComboBox_AddString(hwnd2,str13);
		ComboBox_AddString(hwnd2,str14);
		ComboBox_AddString(hwnd2,str15);
		ComboBox_AddString(hwnd2,str16);
		ComboBox_AddString(hwnd3,str17);
		ComboBox_AddString(hwnd3,str18);
		ComboBox_AddString(hwnd3,str19);
		ComboBox_AddString(hwnd3,str20);
		ComboBox_AddString(hwnd3,str21);
		ComboBox_AddString(hwnd3,str22);
		ComboBox_AddString(hwnd3,str23);
		ComboBox_AddString(hwnd3,str24);
		ComboBox_AddString(hwnd4,str25);
		ComboBox_AddString(hwnd4,str26);
		ComboBox_AddString(hwnd4,str27);
		ComboBox_AddString(hwnd4,str28);
		ComboBox_AddString(hwnd4,str29);
		ComboBox_AddString(hwnd4,str30);
		ComboBox_AddString(hwnd4,str31);
		ComboBox_AddString(hwnd4,str32);
		ComboBox_AddString(hwnd5,str33);
		ComboBox_AddString(hwnd5,str34);
		ComboBox_AddString(hwnd5,str35);
		ComboBox_AddString(hwnd5,str36);
		ComboBox_AddString(hwnd5,str37);
		ComboBox_AddString(hwnd5,str38);
		ComboBox_AddString(hwnd5,str39);
		ComboBox_AddString(hwnd5,str40);
		ComboBox_AddString(hwnd5,str41);
		
	
    return TRUE;
}

void Main_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{ 
	HWND hwnd1=GetDlgItem(hwnd,IDC_xuanze);
	int CurSel=ComboBox_GetCurSel(hwnd1);
    HWND hwnd3=GetDlgItem(hwnd,IDC_xuanze3);
    int CurSel3=ComboBox_GetCurSel(hwnd3);
	HWND hwnd2=GetDlgItem(hwnd,IDC_xuanze2);
    int CurSel2=ComboBox_GetCurSel(hwnd2);
	HWND hwnd4=GetDlgItem(hwnd,IDC_xuanze4);
    int CurSel4=ComboBox_GetCurSel(hwnd4);
	HWND hwnd5=GetDlgItem(hwnd,IDC_xuanze5);
    int CurSel5=ComboBox_GetCurSel(hwnd5);

    switch(id)
    {
   case IDC_xuanze:
	   
    		if(CurSel==5)
		   {
			   TCHAR shi1[999]="	������                                                           "
				   "������ꤽ𾮣������仨���䣬���һ��꣬�����۲��Ѷ���˭ʡ��˭ʡ���Ӵ��Ƶ�Ӱ��";
		       SetDlgItemText(hwnd,IDC_EDIT1,shi1);
		   }
		    if(CurSel==4)
			{     
			   TCHAR shi2[999]="   	������                                                          "
                  "�����®�˾���  ��Ӱҡҡ��׹��  ���θ��Ǻӣ�    �ֱ��������顣  ��˯��  ��˯��    ���������ζ��";
		       SetDlgItemText(hwnd,IDC_EDIT1,shi2);
		   }
			 if(CurSel==2)
			 {             
			   TCHAR shi3[999]="    �Ϫɳ                                                                  " 
                  "ʮ�����������䣬��������Ū���ҡ�������İ�˭�ߣ�������б��Ӱ��������������ߡ��࿴�ô�ȴ���ԡ�";
		       SetDlgItemText(hwnd,IDC_EDIT1,shi3);
		   }
			  if(CurSel==3)
		   {
			   TCHAR shi4[999]="    �Ϫɳ                                                          "
                  "˭�������������������Ҷ���贰����˼����������������Ī����˯�أ����������ò��㡣��ʱֻ����Ѱ����";
		       SetDlgItemText(hwnd,IDC_EDIT1,shi4);
		   }
			  if(CurSel==1)
		   {
			   TCHAR shi5[999]="    �Ϫɳ                                                              "
                  "��ѩ�����仭������÷����������������˴������ʡ������˼����ͣ�֪���������ݺᣬ�ϳ�������ƽ����";
		       SetDlgItemText(hwnd,IDC_EDIT1,shi5);
		   }
			  if(CurSel==6)
		   {
			   TCHAR shi6[999]="    ������                                                                             "
                  "�������������ϣ�������ɨ�������д������ߣ�ʰ�ô��̺κ޲����ԡ�����һ����˼�أ���سɹ��С����ƺ��¾ͻ������Ѿ�ʮ���ټ�ʮ���ġ�";
		       SetDlgItemText(hwnd,IDC_EDIT1,shi6);
		   }
			  if(CurSel==7)
		   {
			   TCHAR shi7[999]="    ������ ��Ϧ�Ų�                                                                       "
                  "�����������ʡ��¶ʪ�ū\Ӱ���н�С������������ʣ��ʱ��ɫ�����档����ת�Ƕ����ۣ������᳦�顣��������ģ�����乲��ǰ����Ϊ���顣";
		       SetDlgItemText(hwnd,IDC_EDIT1,shi7);
		   }
			  if(CurSel==0)
		   {
			   TCHAR shi8[999]="    ��ɣ��                                                              "
                  "����ŵ���ʱ���������ԡ�����͵�������۴�����·ǡ���֪�˺����޼ƣ�ǿ˵���ڡ�һ����˹���価�滨��������";
		       SetDlgItemText(hwnd,IDC_EDIT1,shi8);
		   }break;
			 
			  
	   
	   case IDC_xuanze2:
	
		        

				if(CurSel2==1)
		   {
			   TCHAR shi9[999]="     ����ľ����                                                          "
                  "�ӽ���ʯ��ÿ��������ϧϧ��������������������һ��������̫�䣬���ֽ������Ӱ����ȡ��˼�������������ʱ��";
		       SetDlgItemText(hwnd,IDC_EDIT1,shi9);
		   }
				if(CurSel2==6)
		   {
			   TCHAR shi10[999]="    �佭��                                                                         "
                  "����˫����Ժ�иУ��ĻҾ����з�δȫɮ��������ĥ������������ʶֻ�£����ڲ����ѡ�ҡ����崵�ǿ�����������Ʈ��Ҷ��է�ŷ綨����������������ǡ�����������������ʱ������������������ҹ��΢������֦���ߵ�̫�߳١���ȥ���˺���˭֪�������˼��������������������ԡ�δ�������ɡ�";
		       SetDlgItemText(hwnd,IDC_EDIT1,shi10);
		   }
			  
			  if(CurSel2==2)
		   {
			   TCHAR shi11[999]="    ����ľ����                                                                      "
                  "��겻�һ��ܽ�������ꡣС�κ쳱��б������ֻ���̡������ͻ���ֱΪ������˼��������Ļ���ת������ߵ���Ρ�";
		       SetDlgItemText(hwnd,IDC_EDIT1,shi11);
		   }
			  if(CurSel2==4)
		   {
			   TCHAR shi12[999]="    ������                                                                    "
                  "����һƬ���İף����������Զ�������������£�ͩ������������������γ���������˯��ֻ��ȥ��������������";
		       SetDlgItemText(hwnd,IDC_EDIT1,shi12);
		   }
			  if(CurSel2==5)
			  { 
			   TCHAR shi13[999]="    ������                                                                "
                  "˷�紵ɢ����ѩ��ٻ�������һ��¡��κ�Ī��ߣ������ô��С��޶������ǣ����Ϻ����������һ��˻�����Ƿ����졣";
		       SetDlgItemText(hwnd,IDC_EDIT1,shi13);
		   }
			  if(CurSel2==0)
		   {
			   TCHAR shi14[999]="    ������                                                                  "
                  "�����ܼ����ܲ������ǡ�������Ҷ��������ǰͬһЦ���ֵ�����ʱ�ڡ������У�¯�ྡ��������ʡ�һ����¶�������ҹ͵�ӡ��¼���ȥ¥�գ���֦������ɨ�����¡��޷ְ����ס���ڰ������׽ᡣ��ů̴�ۣ��̺���Ӱ���������С����ɲ����˳�֪��˭˵��";
		       SetDlgItemText(hwnd,IDC_EDIT1,shi14);
		   }
			  if(CurSel2==3)
			  { 
			   TCHAR shi15[999]="    �ٽ���                                                                 "
                  "��ΰŽ������飬�������䵱�������߻�չ��ʱ�顣ԧ��С�֣��̼������衣����է����ң��ؿ�һ��ģ�����Ĵ�����һ�ƹ¡���Ӧ�龡�����������ޣ�";
		       SetDlgItemText(hwnd,IDC_EDIT1,shi15);
		   }
			  if(CurSel2==7)
		   {
			   TCHAR shi16[999]="    ���к�                                                                   "
                  "����������С¥��˭�������ƫ�ġ�һ�а���ң��ĺ������ƻ������������̾��������������ˮ�������˼����¿���꣬Ī������ʾ��Ρ�";
		       SetDlgItemText(hwnd,IDC_EDIT1,shi16);
		   }break;

	
	 case IDC_xuanze3:
	 
		       

				if(CurSel3==6)
		   {
			   TCHAR sh1[999]="   ������                                                  "
                 "�º��о��ô��꣬����ϸ�����������ŵ�Ī��������ʪһ�ۡ����ĳɶ��ԣ���ָ�ع�����ǵñ���ʱ���һ�����˿��";
		       SetDlgItemText(hwnd,IDC_EDIT1,sh1);
		   }
			  
			  if(CurSel3==2)
		   {
			   TCHAR sh2[999]="    ������                                                                "
                 "˭������ס��̾������������ϣ���ɳ�ĺ����������ͬ����ȴ����ɽҹ�ꡣ����ֻ����ʱ��ۡ����򳤽�����ľ����ң�졢���㰧��ȥ����Ҷ�£�������Ի���������������ǿ�ƣ����̺��£��ܳ����һ�����ľ���꣬����Ʈ��δ�����н��䡢������Ů���ñ����ſ�̫Ϣ���Ź������������ฺ�������ޣ���˭�";
		       SetDlgItemText(hwnd,IDC_EDIT1,sh2);
		   }
			  if(CurSel3==1)
		   {
			   TCHAR sh3[999]="    ����ľ����                                                                "
                 "�ϻ��޾ݣ���ˮǧɽ�δ�ȥ��û�����飬���ն������̳�����԰���ã������仨����ɨ��Ī���˴���ͬ�������ಡ�ˡ�";
		       SetDlgItemText(hwnd,IDC_EDIT1,sh3);
		   }
			  if(CurSel3==7)
		   {
			   TCHAR sh4[999]="    ������ ����������                                              "
                 "֪���˼�����������«������۲����̰׾����࣬ˮ�������硣��¥��Ϧ�Σ����������͡�ֱ����ü�ţ�Ǯ�����ϳ���";
		       SetDlgItemText(hwnd,IDC_EDIT1,sh4);
		   }
			  if(CurSel3==5)
		   {
			   TCHAR sh5[999]="    ������                                                       "
                 "Ʈ��ֻ���ת�����˹����̹�Զ�������Ϻ�����ï�����������е��������������������빬ѻ��ɽ������б��";
		       SetDlgItemText(hwnd,IDC_EDIT1,sh5);
		   }
			  if(CurSel3==3)
		   {
			   TCHAR sh6[999]="   �ٽ��� ����                                                   "
                 "�����ɻ��δ��ǣ������ѩ�ݲС�����һ����������������ºã���Ҳ��ء����Ƿ�˿ҡ���ת�����䴺ɽ����ȹ�ζ���Ӧ�ѡ�������ٺޣ�����ɢü�䡣";
		       SetDlgItemText(hwnd,IDC_EDIT1,sh6);
		   }
			  if(CurSel3==0)
		   {
			   TCHAR sh7[999]="   ��ɣ�� ����ӽ÷��                                                "
                 "�ǹ�񱰮��ģ�����䴦ƫ�ѡ����и�ѿ�������˼主�󻨡�л����˭��ϧ��Ư�����ģ����±��ա���������嫺�ɳ��";
		       SetDlgItemText(hwnd,IDC_EDIT1,sh7);
		   }
				if(CurSel3==4)
		   {
			   TCHAR sh8[999]="     ������ ��������                                                            "
                 "��Ӱ������֯Ů��ȻԹ���ӡ���ɫԶ��ɽɫ�����ݡ�����΢ã�������п��й����ϵ����һ��ࡣһ�����ӦΪ�����Შ������ԧ������ô��";
		       SetDlgItemText(hwnd,IDC_EDIT1,sh8);
		   }break;
				
	
	 case IDC_xuanze4:
	 
		       

				if(CurSel4==0)
		   {
			   TCHAR shp1[999]="   ��ɣ��                                                     "
                 "�һ��������������м����硣���使�죬���봰����ٯ��˭�����ණ���ݣ�ҲΪ��㼡�����ܽ�أ�һƬ�����䴦Ũ��";
		       SetDlgItemText(hwnd,IDC_EDIT1,shp1);
		   }
			  
			  if(CurSel4==1)
		   {
			   TCHAR shp2[999]="   ��ɣ��                                                               "
                 "ͮ�ƾþ��������֣�����˭�ߣ���ҹ�����߲��ߡ���������е��𣬾������죬�������ڵ����ҡ�";
		       SetDlgItemText(hwnd,IDC_EDIT1,shp2);
		   }
			  if(CurSel4==5)
		   {
			   TCHAR shp3[999]="   ������  ���������и�                                              "
                 "�˺޺�ʱ�ѡ��οսס�������Ъ���Ứ�������������ƻ����ã����ξ�Ӧ���ӡ���Ҳ�����˼���ζ������ҹ̫�������������塢һƬ���ء�����Լ������������Ȫ����˫��ġ���֪�����������֣���˭���С�����������ת�࣬�����������������������֪�����������˾㱡������Ե㥡�ʣ���������ᾡ��ֽ����";
		       SetDlgItemText(hwnd,IDC_EDIT1,shp3);
		   }
			  if(CurSel4==3)
		   {
			   TCHAR shp4[999]="   ���ô�                                                             " 
                 "һ��һ��һ˫�ˣ������������ꡣ��˼���������ף���Ϊ˭����������������ҩ�ɱ̺��ѱ������������ţ�������ƶ��";
		       SetDlgItemText(hwnd,IDC_EDIT1,shp4);
		   }
			  if(CurSel4==2)
		   {
			   TCHAR shp5[999]="    �촰��                                           "
                 "��黨л������ѭ��������������һ�����£��������顣�̼Ǳ���Ӱ�����������˿��ֽ����׭���������ǡ����ݹ���Լ����ȡ���ˡ����һ˿��¶��ʪ������";
		       SetDlgItemText(hwnd,IDC_EDIT1,shp5);
		   }
			  if(CurSel4==4)
			  { 
			   TCHAR shp6[999]="   ����ľ����                                             "
                 "��ҡӰ����͸���������ѣ�����˼����������߲��ϳ���ãã���䣬�����˼���һŵ��������ͨ�����ͷ粨Ըʼ�ӡ�";
		       SetDlgItemText(hwnd,IDC_EDIT1,shp6);
		   }
			  if(CurSel4==7)
		   {
			   TCHAR shp7[999]="   ���к�   �������ϻ���ʱ��Ϊ СӰ                              "
                 "���������᲻�ɣ��������ڱ���䡣ң֪������ǰ�꣬ת��ͬ��ѩ��ɽ��ƾ���Ȱ�Ӳͣ���ʱ��Լ�ػ�������С������ƣ�һƬ���������ѡ�";
		       SetDlgItemText(hwnd,IDC_EDIT1,shp7);
		   }
				if(CurSel4==6)
		   {
			   TCHAR shp8[999]="     �ٽ��� ��ƽ����                                              "
                 "���͵���˭���ң����������쬡����������ֻ��ݣ������㲣����ø��������������²������������®���羰����ͷ��ҩ¯���֧����������";
		       SetDlgItemText(hwnd,IDC_EDIT1,shp8);
		   }break;
				

	 case IDC_xuanze5:
	 
		       

				if(CurSel5==2)
		   {
			   TCHAR shpp1[999]="    ������                                                     "
                 "��ź�ɽ�޶��ݣ��������У�����Ƶ��ȥ����Ŀ����˭������紵�ϵ�������������ԹӦ�����������ꡢ��ڣ�ƻ�·��һ�����������ɽϦ�������ꡣ";
		       SetDlgItemText(hwnd,IDC_EDIT1,shpp1);
		   }
			  
			  if(CurSel5==3)
		   {
			   TCHAR shpp2[999]="   ����ľ���� ����                                             "
                 "��ױ���գ�������ü�پ�����׼�������������������ʤ��Ī�����棬��ȡ��Բ�ձ��죬��ҹ��¥�������˼�һ���";
		       SetDlgItemText(hwnd,IDC_EDIT1,shpp2);
		   }
			  if(CurSel5==0)
		   {
			   TCHAR shpp3[999]="   ����˼                                                   "
                 "ɽһ�̣�ˮһ�̣������ܹ������У�ҹ��ǧ�ʵơ���һ����ѩһ�������������β��ɣ���԰�޴�����";
		       SetDlgItemText(hwnd,IDC_EDIT1,shpp3);
		   }
			  if(CurSel5==5)
		   {
			   TCHAR shpp4[999]="   ľ���� ��ž�����                                   "
                 "������ֻ���������������籯���ȣ����б�ȴ�����ģ�ȴ���������ױ䡣��ɽ��������룬ҹ�������ղ�Թ�����籡�ҽ��¶���������֦����Ը��";
		       SetDlgItemText(hwnd,IDC_EDIT1,shpp4);
		   }
			  if(CurSel5==7)
		   {
			   TCHAR shpp5[999]="    ɽ����                                                      "
                 "����Ʈ���ѻ�Ƽ��������ٻź˿�ӣ����ر�����һ�꣬��ǰ�����˵������ת������������ڶ��飻�ֵ��ϳ����״�����͵�Ρ�";
		       SetDlgItemText(hwnd,IDC_EDIT1,shpp5);
		   }
			  if(CurSel5==1)
			  {    
			   TCHAR shpp6[999]="   ��筴�                                                     "
                 "һ�ֶ�ü�����Ҳ��Ƴ��Һá�����δ�ϣ����������磿�ر�б�ԣ���Ӱ�ᴰɨ���շ��ģ�����������������¥�ˡ�";
		       SetDlgItemText(hwnd,IDC_EDIT1,shpp6);
		   }
			  if(CurSel5==4)
		   {
			   TCHAR shpp7[999]="   �仨ʱ                                                   "
                 "Ϧ��˭����¥�ݣ�һ�������ͷ��Ц��ǰ���������Ҳ����������ֱ���ƾ�ݣ���˵��˼��Ȱ������촰����Ī�����仨ʱ��";
		       SetDlgItemText(hwnd,IDC_EDIT1,shpp7);
		   }
				if(CurSel5==8)
		   {
			   TCHAR shpp8[999]="     ̯���Ϫɳ                                    "
                 "һ����ǰ���ѣ����紺��η�����������´����꣬һ�������˵������ת����������������顣�����������ˣ��̳�ͤ��";
		       SetDlgItemText(hwnd,IDC_EDIT1,shpp8);
		   }
				if(CurSel5==6)
		   {
			   TCHAR shpp9[999]="   ������                                                 "
                 "���վ�쭶��Ѱ룬�ⰰ��ֵ��ѻ�ҡ����ϴ������ããһƬ��պۿռ������ĽǸ߳��ϡ����ս����������ĳ�δ����";
		       SetDlgItemText(hwnd,IDC_EDIT1,shpp9);
		   }break;


	
   default:
		break;
    }
}

void Main_OnClose(HWND hwnd)
{
    EndDialog(hwnd, 0);
}