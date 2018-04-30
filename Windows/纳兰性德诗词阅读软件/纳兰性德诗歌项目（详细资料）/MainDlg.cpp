#include "stdafx.h"
#include <windows.h>
#include <windowsx.h>
#include "resource.h"
#include "MainDlg.h"

/*
Template designed by RuPeng.com. Please visit http://www.rupeng.com for more information
如鹏网（http://www.rupeng.com）大学生计算机学习社区，提供大量免费视频学习教程，提供个性化一对一学习指导
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
	    TCHAR str1[30]="如梦令(正是轱辘)";
		TCHAR str2[30]="如梦令(万帐穹庐)";
	    TCHAR str3[30]="浣溪沙(十八年来)";
	    TCHAR str4[30]="浣溪沙(谁念西风)";	
	    TCHAR str5[30]="浣溪沙(残雪凝辉)";
	    TCHAR str6[10]="虞美人";
	    TCHAR str7[20]="虞美人 秋夕信步 ";
	    TCHAR str8[10]="采桑子";
	    TCHAR str9[30]="减字木兰花(从教铁石)";
        TCHAR str10[20]="忆江南 ";
		TCHAR str11[30]="减字木兰花(相逢不语)";
	    TCHAR str12[20]="菩萨蛮 (晶帘一片)";
		TCHAR str13[20]="菩萨蛮 (朔风吹散)";
		TCHAR str14[20]="百字令 ";
		TCHAR str15[20]="临江仙 ";
		TCHAR str16[20]="于中好 ";
		TCHAR str17[20]="菩萨蛮 (飘蓬只逐)";
		TCHAR str18[20]="金缕曲 ";
		TCHAR str19[20]="减字木兰花";
		TCHAR str20[20]="菩萨蛮 寄梁汾苕中";
		TCHAR str21[20]="菩萨蛮 (新寒中酒)";
		TCHAR str22[20]="临江仙 寒柳";
		TCHAR str23[20]="采桑子 塞上咏梅花";
		TCHAR str24[20]="南乡子 柳沟晓发";
		TCHAR str25[20]="采桑子 (彤云久绝) ";
		TCHAR str26[20]="采桑子 (桃花羞作)";
		TCHAR str27[30]="金缕曲  亡妇忌日有感";
		TCHAR str28[20]="画堂春";
		TCHAR str29[20]="红窗月 ";
		TCHAR str30[20]="减字木兰花";
		TCHAR str31[50]="于中好   送梁汾南还，时方为 小影  ";
		TCHAR str32[20]="临江仙 永平道中";
		TCHAR str33[20]="蝶恋花  ";
		TCHAR str34[20]="减字木兰花 新月  ";
		TCHAR str35[30]="长相思";
		TCHAR str36[20]="木兰花 拟古绝决词";
		TCHAR str37[20]="山花子 ";
		TCHAR str38[20]="点绛唇";
		TCHAR str39[50]="落花时  ";
		TCHAR str40[20]="摊破浣溪沙  ";
		TCHAR str41[20]="菩萨蛮";

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
			   TCHAR shi1[999]="	如梦令                                                           "
				   "正是轱辘金井，满砌落花红冷，蓦地一相逢，心事眼波难定。谁省？谁省？从此纹灯影。";
		       SetDlgItemText(hwnd,IDC_EDIT1,shi1);
		   }
		    if(CurSel==4)
			{     
			   TCHAR shi2[999]="   	如梦令                                                          "
                  "万帐穹庐人静，  星影摇摇欲坠。  归梦隔狼河，    又被河声搅碎。  还睡，  还睡，    解道醒来无味。";
		       SetDlgItemText(hwnd,IDC_EDIT1,shi2);
		   }
			 if(CurSel==2)
			 {             
			   TCHAR shi3[999]="    浣溪沙                                                                  " 
                  "十八年来堕世间，吹花嚼蕊弄冰弦。多情情寄阿谁边？紫玉钗斜灯影背，红绵粉冷枕函边。相看好处却无言。";
		       SetDlgItemText(hwnd,IDC_EDIT1,shi3);
		   }
			  if(CurSel==3)
		   {
			   TCHAR shi4[999]="    浣溪沙                                                          "
                  "谁念西风独自凉，萧萧黄叶闭疏窗。沉思往事立残阳。被酒莫惊春睡重，赌书消得泼茶香。当时只道是寻常。";
		       SetDlgItemText(hwnd,IDC_EDIT1,shi4);
		   }
			  if(CurSel==1)
		   {
			   TCHAR shi5[999]="    浣溪沙                                                              "
                  "残雪凝辉冷画屏，落梅横笛已三更，更无人处月朦胧。我是人间惆怅客，知君何事泪纵横，断肠声里忆平生。";
		       SetDlgItemText(hwnd,IDC_EDIT1,shi5);
		   }
			  if(CurSel==6)
		   {
			   TCHAR shi6[999]="    虞美人                                                                             "
                  "银床淅沥青梧老，粉秋蜇扫。采香行处蹙连线，拾得翠翘何恨不能言。回廊一寸相思地，落地成孤倚。背灯和月就花阴，已经十年踪迹十年心。";
		       SetDlgItemText(hwnd,IDC_EDIT1,shi6);
		   }
			  if(CurSel==7)
		   {
			   TCHAR shi7[999]="    虞美人 秋夕信步                                                                       "
                  "愁痕满地无人省，露湿琅玕影。闲阶小立倍荒凉。还剩旧时月色在潇湘。薄情转是多情累，曲曲柔肠碎。红笺向壁字模糊，忆共灯前呵手为伊书。";
		       SetDlgItemText(hwnd,IDC_EDIT1,shi7);
		   }
			  if(CurSel==0)
		   {
			   TCHAR shi8[999]="    采桑子                                                              "
                  "而今才道当时错，心绪凄迷。红泪偷垂，满眼春风百事非。情知此后来无计，强说欢期。一别如斯，落尽梨花月又西。";
		       SetDlgItemText(hwnd,IDC_EDIT1,shi8);
		   }break;
			 
			  
	   
	   case IDC_xuanze2:
	
		        

				if(CurSel2==1)
		   {
			   TCHAR shi9[999]="     减字木兰花                                                          "
                  "从教铁石，每见花开成惜惜。泪点难消，滴损苍烟玉一条。怜伊太冷，添个纸窗疏竹影，记取相思，环佩归来月上时。";
		       SetDlgItemText(hwnd,IDC_EDIT1,shi9);
		   }
				if(CurSel2==6)
		   {
			   TCHAR shi10[999]="    忆江南                                                                         "
                  "（宿双林禅院有感）心灰尽，有发未全僧。风雨消磨生死别，似曾相识只孤，情在不能醒。摇落后，清吹那堪听。淅沥暗飘金井叶，乍闻风定又钟声，薄福荐倾城。挑灯坐，坐久忆年时。薄雾笼花娇欲泣，夜深微月下杨枝。催道太眠迟。憔悴去，此恨有谁知？天上人间俱怅望，经声佛火两凄迷。未梦已先疑。";
		       SetDlgItemText(hwnd,IDC_EDIT1,shi10);
		   }
			  
			  if(CurSel2==2)
		   {
			   TCHAR shi11[999]="    减字木兰花                                                                      "
                  "相逢不语，一朵芙蓉着秋雨。小晕红潮，斜溜鬟心只凤翘。待将低唤，直为凝情恐人见。欲诉幽怀，转过回阑叩玉钗。";
		       SetDlgItemText(hwnd,IDC_EDIT1,shi11);
		   }
			  if(CurSel2==4)
		   {
			   TCHAR shi12[999]="    菩萨蛮                                                                    "
                  "晶帘一片伤心白，云鬟香雾成远隔。无语问添衣，桐阴月已西。西风鸣络纬，不许愁人睡。只是去年秋，如何泪欲流。";
		       SetDlgItemText(hwnd,IDC_EDIT1,shi12);
		   }
			  if(CurSel2==5)
			  { 
			   TCHAR shi13[999]="    菩萨蛮                                                                "
                  "朔风吹散三更雪，倩魂犹恋桃花月。梦好莫相催，由他好处行。无端听画角，枕畔红冰薄。塞马一声嘶，残星拂大旗。";
		       SetDlgItemText(hwnd,IDC_EDIT1,shi13);
		   }
			  if(CurSel2==0)
		   {
			   TCHAR shi14[999]="    百字令                                                                  "
                  "人生能几？总不如休惹、情条恨叶。刚是尊前同一笑，又到别离时节。灯挑残，炉燕尽无语空凝咽。一天凉露，芳魂此夜偷接。怕见人去楼空，柳枝无恙，犹扫窗间月。无分暗香深处住，悔把兰襟亲结。尚暖檀痕，犹寒翠影，触绪添悲切。愁多成病，此愁知向谁说？";
		       SetDlgItemText(hwnd,IDC_EDIT1,shi14);
		   }
			  if(CurSel2==3)
			  { 
			   TCHAR shi15[999]="    临江仙                                                                 "
                  "点滴芭蕉心欲碎，声声催忆当初。欲眠还展旧时书。鸳鸯小字，犹记手生疏。倦眼乍低缃乱，重看一半模糊。幽窗冷雨一灯孤。料应情尽，还道有情无？";
		       SetDlgItemText(hwnd,IDC_EDIT1,shi15);
		   }
			  if(CurSel2==7)
		   {
			   TCHAR shi16[999]="    于中好                                                                   "
                  "独背残阳上小楼，谁家玉笛韵偏幽。一行白鹭遥天暮，几点黄花满地秋。惊节序，叹浮沉，秾华如梦水东流。人间所事堪惆怅，莫向横塘问旧游。";
		       SetDlgItemText(hwnd,IDC_EDIT1,shi16);
		   }break;

	
	 case IDC_xuanze3:
	 
		       

				if(CurSel3==6)
		   {
			   TCHAR sh1[999]="   菩萨蛮                                                  "
                 "新寒中酒敲窗雨，残香细袅秋情绪。才道莫伤神，青衫湿一痕。无聊成独卧，弹指韶光过。记得别伊时，桃花柳万丝。";
		       SetDlgItemText(hwnd,IDC_EDIT1,sh1);
		   }
			  
			  if(CurSel3==2)
		   {
			   TCHAR sh2[999]="    金缕曲                                                                "
                 "谁复留君住？叹人生，几番离合，便成迟暮。最忆西窗同翦烛，却话家山夜雨。不道只、暂时相聚。衮衮长江萧萧木，送遥天、白雁哀鸣去。黄叶下，秋如许。曰归因甚添愁绪。料强似，冷烟寒月，栖迟梵宇。一事伤心君落魂，两鬓飘萧未遇。有解忆、长安儿女。裘敝入门空太息，信古来、才命真相负。身世恨，共谁语。";
		       SetDlgItemText(hwnd,IDC_EDIT1,sh2);
		   }
			  if(CurSel3==1)
		   {
			   TCHAR sh3[999]="    减字木兰花                                                                "
                 "断魂无据，万水千山何处去。没个音书，尽日东风上绿除。故园春好，寄语落花须自扫。莫更伤春，同是恹恹多病人。";
		       SetDlgItemText(hwnd,IDC_EDIT1,sh3);
		   }
			  if(CurSel3==7)
		   {
			   TCHAR sh4[999]="    菩萨蛮 寄梁汾苕中                                              "
                 "知君此际情萧索，黄芦苦竹孤舟泊。烟白酒旗青，水村鱼市晴。柁楼今夕梦，脉脉春寒送。直过画眉桥，钱塘江上潮。";
		       SetDlgItemText(hwnd,IDC_EDIT1,sh4);
		   }
			  if(CurSel3==5)
		   {
			   TCHAR sh5[999]="    菩萨蛮                                                       "
                 "飘蓬只逐惊飙转，行人过尽烟光远。立马认河流，茂陵风雨秋。寂寥行殿锁，梵呗琉璃火。塞雁与宫鸦，山深日易斜。";
		       SetDlgItemText(hwnd,IDC_EDIT1,sh5);
		   }
			  if(CurSel3==3)
		   {
			   TCHAR sh6[999]="   临江仙 寒柳                                                   "
                 "飞絮飞花何处是？层冰积雪摧残。疏疏一树五更寒。爱他明月好，憔悴也相关。最是繁丝摇落后，转教人忆春山。湔裙梦断续应难。西风多少恨，吹不散眉弯。";
		       SetDlgItemText(hwnd,IDC_EDIT1,sh6);
		   }
			  if(CurSel3==0)
		   {
			   TCHAR sh7[999]="   采桑子 塞上咏梅花                                                "
                 "非关癖爱轻模样，冷处偏佳。别有根芽。不是人间富贵花。谢娘别后谁能惜，漂泊天涯，寒月悲笳。万里西风瀚海沙。";
		       SetDlgItemText(hwnd,IDC_EDIT1,sh7);
		   }
				if(CurSel3==4)
		   {
			   TCHAR sh8[999]="     南乡子 柳沟晓发                                                            "
                 "灯影伴鸣梭，织女依然怨隔河。曙色远连山色起，青螺。回首微茫忆翠娥。凄切客中过。料抵秋闺一半多。一世疏狂应为著，横波。作个鸳鸯消得么？";
		       SetDlgItemText(hwnd,IDC_EDIT1,sh8);
		   }break;
				
	
	 case IDC_xuanze4:
	 
		       

				if(CurSel4==0)
		   {
			   TCHAR shp1[999]="   采桑子                                                     "
                 "桃花羞作无情死，感激东风。吹落娇红，飞入窗间伴懊侬。谁怜辛苦东阳瘦，也为春慵。不及芙蓉，一片幽情冷处浓。";
		       SetDlgItemText(hwnd,IDC_EDIT1,shp1);
		   }
			  
			  if(CurSel4==1)
		   {
			   TCHAR shp2[999]="   采桑子                                                               "
                 "彤云久绝飞琼宇字，人在谁边，今夜玉清眠不眠。香销被冷残灯灭，静数秋天，又误心期到下弦。";
		       SetDlgItemText(hwnd,IDC_EDIT1,shp2);
		   }
			  if(CurSel4==5)
		   {
			   TCHAR shp3[999]="   金缕曲  亡妇忌日有感                                              "
                 "此恨何时已。滴空阶、寒更雨歇，葬花天气。三载悠悠魂梦杳，是梦久应醒矣。料也觉，人间无味。不及夜太尘土隔，冷清清、一片埋愁地。钗钿约，竟抛弃。重泉若有双鱼寄。好知他、年来苦乐，与谁相倚。我自中宵成转侧，忍听湘弦重理。待结个、他生知己。还怕两人俱薄命，再缘悭、剩月零风里。清泪尽，纸灰起。";
		       SetDlgItemText(hwnd,IDC_EDIT1,shp3);
		   }
			  if(CurSel4==3)
		   {
			   TCHAR shp4[999]="   画堂春                                                             " 
                 "一生一代一双人，争教两处销魂。相思相望不相亲，天为谁春？桨向蓝桥易乞，药成碧海难奔。若容相访饮牛津，相对忘贫。";
		       SetDlgItemText(hwnd,IDC_EDIT1,shp4);
		   }
			  if(CurSel4==2)
		   {
			   TCHAR shp5[999]="    红窗月                                           "
                 "燕归花谢，早因循、过了清明。是一般心事，两样心情。犹记碧桃影里、誓三生。乌丝阑纸娇红篆，历历春星。道休孤密约，鉴取深盟。语罢一丝清露、湿银屏。";
		       SetDlgItemText(hwnd,IDC_EDIT1,shp5);
		   }
			  if(CurSel4==4)
			  { 
			   TCHAR shp6[999]="   减字木兰花                                             "
                 "烛花摇影，冷透疏衾刚欲醒，待不思量，不许孤眠不断肠。茫茫碧落，天上人间情一诺。银汉难通，稳耐风波愿始从。";
		       SetDlgItemText(hwnd,IDC_EDIT1,shp6);
		   }
			  if(CurSel4==7)
		   {
			   TCHAR shp7[999]="   于中好   送梁汾南还，时方为 小影                              "
                 "握手西风泪不干，年来多在别离间。遥知独听灯前雨，转忆同看雪后山。凭寄语，劝加餐，桂花时节约重还。分明小像沉香缕，一片伤心欲画难。";
		       SetDlgItemText(hwnd,IDC_EDIT1,shp7);
		   }
				if(CurSel4==6)
		   {
			   TCHAR shp8[999]="     临江仙 永平道中                                              "
                 "独客单衾谁念我，晓来凉雨飕飕。缄书欲寄又还休，个依憔悴，禁得更添愁。曾记年年三月病，而今病向深秋。庐龙风景白人头，药炉烟里，支枕听河流。";
		       SetDlgItemText(hwnd,IDC_EDIT1,shp8);
		   }break;
				

	 case IDC_xuanze5:
	 
		       

				if(CurSel5==2)
		   {
			   TCHAR shpp1[999]="    蝶恋花                                                     "
                 "今古河山无定据，画角声中，牧马频来去。满目荒凉谁可语？西风吹老丹枫树。从来幽怨应无数？铁马金戈、青冢黄昏路。一往情深深几许？深山夕照深秋雨。";
		       SetDlgItemText(hwnd,IDC_EDIT1,shpp1);
		   }
			  
			  if(CurSel5==3)
		   {
			   TCHAR shpp2[999]="   减字木兰花 新月                                             "
                 "晚妆欲罢，更把纤眉临镜画，准待分明。和雨和烟两不胜。莫教星替，守取团圆终必遂，此夜红楼，天上人间一样愁。";
		       SetDlgItemText(hwnd,IDC_EDIT1,shpp2);
		   }
			  if(CurSel5==0)
		   {
			   TCHAR shpp3[999]="   长相思                                                   "
                 "山一程，水一程，身向榆关那畔行，夜深千帐灯。风一更，雪一更，聒碎乡心梦不成，故园无此声。";
		       SetDlgItemText(hwnd,IDC_EDIT1,shpp3);
		   }
			  if(CurSel5==5)
		   {
			   TCHAR shpp4[999]="   木兰花 拟古绝决词                                   "
                 "人生若只若初见，何事西风悲画扇？等闲变却故人心，却道故人心易变。骊山语罢清宵半，夜雨霖铃终不怨。何如薄幸锦衣儿，比翼连枝当日愿。";
		       SetDlgItemText(hwnd,IDC_EDIT1,shpp4);
		   }
			  if(CurSel5==7)
		   {
			   TCHAR shpp5[999]="    山花子                                                      "
                 "风絮飘残已化萍，泥莲刚倩藕丝萦；珍重别拈香一瓣，记前生。人到情多情转薄，而今真个悔多情；又到断肠回首处，泪偷滴。";
		       SetDlgItemText(hwnd,IDC_EDIT1,shpp5);
		   }
			  if(CurSel5==1)
			  {    
			   TCHAR shpp6[999]="   点绛唇                                                     "
                 "一种蛾眉，下弦不似初弦好。庾郎未老，何事伤心早？素壁斜辉，竹影横窗扫。空房悄，乌啼欲晓，又下西楼了。";
		       SetDlgItemText(hwnd,IDC_EDIT1,shpp6);
		   }
			  if(CurSel5==4)
		   {
			   TCHAR shpp7[999]="   落花时                                                   "
                 "夕阳谁唤下楼梯，一握香荑回头忍笑阶前立，总无语，也依依。笺书直恁无凭据，休说相思。劝伊好向红窗醉，须莫及，落花时。";
		       SetDlgItemText(hwnd,IDC_EDIT1,shpp7);
		   }
				if(CurSel5==8)
		   {
			   TCHAR shpp8[999]="     摊破浣溪沙                                    "
                 "一霎灯前醉不醒，恨如春梦畏分明。澹云澹月窗外雨，一声声。人到情多情转薄，而今真个不多情。又听鹧鸪啼遍了，短长亭。";
		       SetDlgItemText(hwnd,IDC_EDIT1,shpp8);
		   }
				if(CurSel5==6)
		   {
			   TCHAR shpp9[999]="   菩萨蛮                                                 "
                 "白日惊飙冬已半，解鞍正值昏鸦乱。冰合大河流，茫茫一片愁。烧痕空极望，鼓角高城上。明日近长安，客心愁未阑。";
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