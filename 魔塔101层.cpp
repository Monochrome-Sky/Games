#include<iostream>
#include<windows.h>
#include<conio.h>
#include<headtitle.h>
#include<random.h>
#define e 1.718281828459
string title="魔塔101层";
void clean()//清屏函数———————————————————————————————————————————————————————————— 
{
	system("cls");
	headtitle("                                ",title,"1.11");
}//————————————————————————————————————————————————————————————————————— 
int xp=0,xp_max=100,lv=1,skill=50,day=0,floor=1,hp=100,hp_max=100,mp=0,mp_max=0,luck=0,magic=0;//全局变量
string character="cjmfs";
int item[30];
char input1,input2,input3;
int Event_poison=0;
void condition()//反作弊插件、升级监测—————————————————————————————————————————————————————————— 
{
	if(hp>hp_max)hp=hp_max;
	if(mp>mp_max)mp=mp_max;
	if(luck>1000)luck=1000;
	if (xp>=xp_max)
	{
		xp-=xp_max;
		lv++;
		xp_max*=e;
		skill+=10;
	}
}
int bar(int fz, int fm,int color1,int color2)
{
	if(fm==0)fm+=1;
	if(fz<=0)fz=0;
	cout<<"                             ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color1);
	for(int i=1;i<=(fz*40/fm+1)/2;i++)cout<<" ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color2);
	for(int i=(fz*40/fm+1)/2+1;i<=20;i++)cout<<" ";
	cout<<"\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
} 
void attribute()//显示属性—————————————————————————————————————————————————————————— 
{
	condition(); 
	cout<<"角色:";
	if(character=="cjmfs"){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);cout<<"初阶魔法使"<<endl;}
	else if(character=="qwyzh"){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);cout<<"青蛙养殖户"<<endl;}
	else if(character=="hynh"){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);cout<<"红衣男孩"<<endl;}
	else if(character=="hmfs"){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);cout<<"黑魔法师"<<endl;}
	else if(character=="zz"){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);cout<<"长者"<<endl;}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	cout<<"当前属性:"<<endl;
	//HP
	bar(hp,hp_max,207,79);SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);cout<<"         HP:"<<hp<<"/"<<hp_max<<endl;
	bar(mp,mp_max,191,63);SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);cout<<"         MP:"<<mp<<"/"<<mp_max<<endl;
	bar(luck,1000,223,95);SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);cout<<"         幸运:";
	if(luck<1000)cout<<luck<<endl;else cout<<"MAX\n";
	bar(xp,xp_max,239,111);SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);cout<<"         XP:(Lv."<<lv<<")"<<xp<<"/"<<xp_max<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);cout<<"状态:";
	if(hp<=0){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);cout<<"濒死\n";}
	else{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);cout<<"正常\n";}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	cout<<"________________________________________________________________________________\n";
}
int item_use(int id)//使用物品—————————————————————————————————————————————————————————— 
{
	int p;//
	if(item[id]>0)
	{
		item[id]--;//物品消耗 
		switch(id)//物品生效 
		{
			case 1:hp+=5;break;
			case 2:hp+=15;break;
			case 3:hp+=35;break;
			case 4:mp+=5;break;
			case 5:mp+=15;break;
			case 6:mp+=35;break;
			case 7:luck+=10;break;
			case 8:luck+=30;break;
			case 9:luck+=70;break;
			case 10:if(floor<100)
			{
				int Newfloor=RandomNumber(100-floor)+1+floor;
				hp-=(Newfloor-floor);
				floor=Newfloor;
			}
			break;
			default:magic=id;break;
		}
		condition();
		return 1;
	}
	return 0;
}
void bag()//背包———————————————————————————————————————————————————————————— 
{
	int ifUse=0,id,page=1;//id————1-31-3星生命药水，4-61-3星魔法药水，7-91-3星幸运药水，10传送石。 
	loop_backbag:;
	clean();
	attribute();
	cout<<"随身物品:\n         ";
	if(page==1)//第一页 
	{
		for(id=1;id<11;id++)
		{
			if(item[id]>0)
			{
				if(id==10)cout<<"[0]";
				else cout<<"["<<id<<"]";
				switch(id)
				{
					case 1:cout<<"一星生命药水 x ";break;
					case 2:cout<<"二星生命药水 x ";break;
					case 3:cout<<"三星生命药水 x ";break;
					case 4:cout<<"一星魔法药水 x ";break;
					case 5:cout<<"二星魔法药水 x ";break;
					case 6:cout<<"三星魔法药水 x ";break;
					case 7:cout<<"一星幸运药水 x ";break;
					case 8:cout<<"二星幸运药水 x ";break;
					case 9:cout<<"三星幸运药水 x ";break;
					case 10:cout<<"传送石 x ";break;
				}
				cout<<item[id]<<"\n         "; //物品库存 
			}
		}
	}
	else if(page==2)
	{
		for(id=11;id<21;id++)
		{
			if(item[id]>0)
			{
				if(id==20)cout<<"[0]";
				else cout<<"["<<id-10<<"]";
				switch(id)//11-12炼金,13闪现,14-20续命 
				{
					case 11:cout<<"一星炼金秘籍 x ";break;
					case 12:cout<<"二星炼金秘籍 x ";break;
					case 13:cout<<"一星闪现卷轴 x ";break;
					case 14:cout<<"一星黑框眼镜 x ";break;
					case 15:cout<<"二星黑框眼镜 x ";break;
					case 16:cout<<"三星黑框眼镜 x ";break;
					case 17:cout<<"四星黑框眼镜 x ";break;
					case 18:cout<<"五星黑框眼镜 x ";break;
					case 19:cout<<"六星黑框眼镜 x ";break;
					case 20:cout<<"七星黑框眼镜 x ";break;
				}
				cout<<item[id]<<"\n         "; 
			}
		}
	}
	cout<<"\n页码:"<<page<<"/2\n";
	cout<<"[q]上一页\n[w]下一页\n其它任意键返回。\n";
	if(ifUse)
	{
		cout<<"\n\n使用成功";
		if(character=="qwyzh"&&page==1&&input3!='0')//青蛙养殖户-被动-化学污染 
		{
			if((RandomNumber(100)+1)>(80+0.01*luck))
			{
				hp-=5;
				cout<<"……"; 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
				cout<<"\n药里有毒！-5HP\n\n";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
			}
			else cout<<"。\n\n";
		}
		else if(character=="hynh"&&page==1&&input3=='0')//红衣男孩-被动-抽魂炼魄 
		{
			hp-=99999; 
			cout<<"……"; 
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
			cout<<"\n红衣男孩的魂魄被剥离躯壳，因无法承受传送石时空扭曲的剧烈冲击，爆体而亡。HP-99999\n\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		}
		else cout<<"。\n\n";
	}
	input3=getche(); 
	if(input3=='1'||input3=='2'||input3=='3'||input3=='4'||input3=='5'||input3=='6'||input3=='7'||input3=='8'||input3=='9'||input3=='0')
	{
		for(id=1+10*(page-1);id<10*(page-1)+11;id++)
		{
			if(input3==(48+id-10*(page-1)))
			{
				if(item_use(id)){ifUse=1;break;}
				else return;
			}
			else if(input3=='0')
			{
				if(item_use(10+10*(page-1))){ifUse=1;break;}
				else return;
			}
		}
		goto loop_backbag;
	}
	else if(input3=='q')
	{
		if(page==2)page--;
		goto loop_backbag;
	}
	else if(input3=='w')
	{
		if(page==1)page++;
		goto loop_backbag;
	}
}
string itemsName(int id)
{
	switch(id)
	{
		case 1:return "一星生命药水";break;
		case 2:return "二星生命药水";break;
		case 3:return "三星生命药水";break;
		case 4:return "一星魔法药水";break;
		case 5:return "二星魔法药水";break;
		case 6:return "三星魔法药水";break;
		case 7:return "一星幸运药水";break;
		case 8:return "二星幸运药水";break;
		case 9:return "三星幸运药水";break;
		case 10:return "传送石";break;
		case 11:return "一星炼金秘籍";break;
		case 12:return "二星炼金秘籍";break;
		case 13:return "一星闪现卷轴";break;
		case 14:return "一星黑框眼镜";break;
		case 15:return "二星黑框眼镜";break;
		case 16:return "三星黑框眼镜";break;
		case 17:return "四星黑框眼镜";break;
		case 18:return "五星黑框眼镜";break;
		case 19:return "六星黑框眼镜";break;
		case 20:return "七星黑框眼镜";break;
	}
}
void conjuration()//召唤术———————————————————————————————————————————————————————— 
{
	int cost;
	loop_BackConjuration:;
	clean();
	attribute();
	cout<<"召唤术:\n";
	if(magic==0)
	{
		cout<<"        无\n\n";
		cost=0;
	}
	else if(magic==11||magic==12)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);cout<<"        炼金\n\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);cout<<"MP消耗:";
		cost=30-5*(magic-10);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);cout<<cost<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	}
	else if(magic==13)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);cout<<"        闪现\n\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);cout<<"MP消耗:";
		cost=50;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);cout<<cost<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	}
	else if(magic>=14&&magic<=20)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);cout<<"        续命\n\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);cout<<"MP消耗:";
		cost=29-magic;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);cout<<cost<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	}
	if(magic!=0)cout<<"菜单:[1]发动\n"; 
	cout<<"其它任意键返回。\n"; 
	input3=getche();
	if(magic==0||mp<cost){}
	else if(input3=='1'&&character=="hynh")//红衣男孩-被动-五行封印 
	{
		clean();
		cout<<"召唤术 ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		if(magic==11||magic==12)cout<<"炼金"; 
		else if(magic==13)cout<<"闪现";
		else if(magic>=14&&magic<=20)cout<<"续命";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout<<" 召唤失败\n\n";
		cout<<"任意键返回。\n";
		input3=getche();
		goto loop_BackConjuration;
	}
	else if(input3=='1')
	{
		mp-=cost;
		if(magic==11||magic==12)item[RandomNumber(9)+1]++;
		else if(magic==13)
		{
			if(floor<=95)
			{
				floor+=RandomNumber(5)+1; 
			}
			else floor=100;
		}
		else if(magic>=14&&magic<=20){hp_max++;hp++;}
		clean();
		attribute();
		cout<<"召唤术 ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		if(magic==11||magic==12)cout<<"炼金"; 
		else if(magic==13)cout<<"闪现";
		else if(magic>=14&&magic<=20)cout<<"续命";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout<<" 已生效\n\n";
		cout<<"任意键返回。\n";
		input3=getche();
		goto loop_BackConjuration;
	}
}
void talent()//天赋———————————————————————————————————————————————————————— 
{
	clean();
	attribute();
	cout<<"天赋点:"<<skill<<endl;
	cout<<"菜单:[1]";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);cout<<"身强体壮（生命上限+1）\n";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	cout<<"     [2]";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);cout<<"魔法精通（魔法上限+1）\n";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	cout<<"     [3]";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);cout<<"欧气护体（幸运+5）\n";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	cout<<"其它任意键返回。\n"; 
	input3=getche();
	if(skill==0){}
	else if(input3=='1'){skill--;hp_max++;hp++;talent();}
	else if(input3=='2'){skill--;mp_max++;mp++;talent();}
	else if(input3=='3'){skill--;luck+=5;talent();}
}
void menu()//菜单—————————————————————————————————————————————————————— 
{
	cout<<"菜单:[1]天赋\n";
	cout<<"     [2]随身物品\n";
	cout<<"     [3]召唤术\n";
	cout<<"     [4]上楼\n";
	if(floor>1)cout<<"     [5]下楼\n";
	while(1)//作出有效抉择 
	{
		input2=input1;
		input1=getche();
		if(input1!='1'&&input1!='2'&&input1!='3'&&input1!='4'&&input1!='5')cout<<"\b \b";
		else if(input1=='5'&&floor==1)cout<<"\b \b";
		else break;
	}
	if(input1=='1')//抉择1：查看属性 
	{
		talent();
		clean();
	}
	else if(input1=='2')//抉择2：查看背包 
	{
		bag();
		clean(); 
	}
	else if(input1=='3')//抉择3：查看召唤 
	{
		conjuration();
		clean();
	}
	else if(input1=='4')floor++;//抉择4：上楼 
	else if(input1=='5')floor--;//抉择5：下楼
}
void game()//游戏函数—————————————————————————————————————————————————————————— 
{
	loop_Retry:;
	clean();
	for(int i=1;i<6;i++)
	{
		cout<<"进入魔塔之前，先选一个喜欢的角色吧：\n\n";
		if(i==1)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);cout<<"                               长者\n\n";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
			cout<<"被动技能：万寿无疆：长者拥有极长的寿命，拥有999初始HP上限。"<<endl;
			cout<<"          生命源泉：长者汲取献祭者的生命，每天回复1HP。"<<endl;
			cout<<"          金蟾护体：长者和青蛙之间产生亲和共鸣，不会踩到青蛙。"<<endl; 
		}
		else if(i==2)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);cout<<"                               黑魔法师\n\n";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
			cout<<"被动技能：魔法精通：黑魔法师渊博的学识赋予他强大的法术力量，使初始MP上限和MP变为50。"<<endl;
			cout<<"          裂魂契约：黑魔法师与恶膜者签订契约，每次受到怪物攻击时将50%伤害转化为MP。"<<endl;
			cout<<"          黑暗屏障：黑魔法师家族天生具有消耗自身魔力抵消攻击的能力，受到来自怪物攻击的致命伤害时保留1HP，并消耗等于溢出伤害之MP，若溢出伤害超过MP，超出部分仍由HP值承受。"<<endl;
		}
		else if(i==3)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);cout<<"                               初阶魔法使\n\n";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
			cout<<"被动技能：无"<<endl; 
		}
		else if(i==4)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);cout<<"                               青蛙养殖户\n\n";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
			cout<<"被动技能：索命青蛙：青蛙养殖户过多接触活体青蛙，从进入魔塔第一天开始就会被青蛙纠缠。"<<endl;
			cout<<"          化学污染：青蛙养殖户使用生物激素和特效饲料养殖青蛙，其随身携带的药水可能被意外污染，每次使用药水时有20%概率损失5HP。"<<endl;
			cout<<"          上古咒印：青蛙养殖户祖辈以养殖青蛙为生，杀害了无数青蛙，因此受到青蛙之神诅咒，进入魔塔时-50HP。"<<endl;
		}	
		else if(i==5)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);cout<<"                               红衣男孩\n\n";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
			cout<<"被动技能：极阴命格：红衣男孩的生命注定向长者流淌，每天损失1HP；红衣男孩对各种鬼怪有聚拢作用，遇怪几率上升50%。"<<endl;
			cout<<"          五行封印：红衣男孩的五行属性被封锁，无法使用任何召唤术。"<<endl;
			cout<<"          抽魂炼魄：红衣男孩被分魄针、锁魂红衣、坠魂砣三件术器剥离魂魄，躯壳无法承受时空扭曲的剧烈冲击，若使用传送石将会爆体而亡。"<<endl;
		}
		cout<<"\n菜单:[1]就你了！\n";
		cout<<"     [2]换一个\n";
		while(1)//作出有效抉择 
		{
			input3=getche();
			if(input3!='1'&&input3!='2')cout<<"\b \b";
			else break;
		}
		if(input3=='1')
		{
			if(i==1)character="zz";
			else if(i==2)character="hmfs";
			else if(i==3)character="cjmfs";
			else if(i==4)character="qwyzh";
			else if(i==5)character="hynh";
			clean();
			break; 
		}
		if(i==5)i=0;
		clean();
	}
	//所有全局变量
	xp=0;xp_max=100;lv=1;skill=50;day=0;floor=1;hp=100;hp_max=100;mp=0;mp_max=0;luck=0;magic=0;
	int parameter=0,hp_lost=0,howLuckyAreYou=0,mp_gained=0,Event_hurt=0,Event_fill=0,Event_frog=0,Event_darkShield=0,xpGainedFromUpstair=0,xpGainedFromKilling=0,itemGainedId=0,isFullHP=0;
	for(int a=1;a<21;a++)item[a]=0;
	//被动技能-游戏开始时 
	if(character=="zz")//长者 
	{
		hp_max=999;
		hp=999;//万寿无疆 
	}
	else if(character=="hmfs")//黑魔法师 
	{
		mp_max=50;
		mp=50;//魔法精通 
	}
	else if(character=="qwyzh")//青蛙养殖户 
	{
		hp=50;//上古咒印 
	}
	// 
	do//游戏循环 
	{
		day++;
		//被动技能-每天 
		if(character=="zz")
		{
			hp++;//长者-被动-生命源泉 
		} 
		if(character=="hynh")
		{
			hp--;//红衣男孩-被动-极阴命格 
		}
		// 
		condition();
		if(input1=='4')//获得经验
		{
			xpGainedFromUpstair=RandomNumber(floor)+1;
			xp+=xpGainedFromUpstair;
		}
		if((day>100&&character!="zz")||character=="qwyzh")//青蛙事件 
		{
			parameter=RandomNumber(100)+1;
			if(parameter<=(50-0.03*luck))
			{
				Event_frog=1;
				if(hp==hp_max)
				{
					isFullHP=1; 
					hp--;
				}
				else
				{
					isFullHP=0;
					hp_max--;
				}
			}
			else Event_frog=0;
		}
		parameter=RandomNumber(100)+1;//受伤事件 
		if(character=="hynh")parameter/=2;//红衣男孩-被动-极阴命格 
		if(parameter<=(20-0.01*luck)&&input1=='4')
		{
			Event_hurt=1;
			hp_lost=RandomNumber(20+2*floor)+1;
			xpGainedFromKilling=RandomNumber(hp_lost);//杀怪掉经验 
			xp+=xpGainedFromKilling;
			hp-=hp_lost;
			if(character=="hmfs")
			{
				mp_gained=(hp_lost+1)/2;
				mp+=mp_gained;//黑魔法师-被动-裂魂契约 
				condition();
				if(hp<=0&&mp>0)//黑魔法师-被动-黑暗屏障 
				{
					Event_darkShield=1;
					if(mp>=(1-hp))
					{
						mp-=(1-hp);
						hp=1;
					}
					else
					{
						hp+=mp;
						mp=0;
					}
				}
				else Event_darkShield=0;
			}
			
		}
		else {Event_hurt=0;Event_darkShield=0;} 
		parameter=RandomNumber(100)+1;//获得物品事件 
		if(parameter<=(30+0.03*luck))
		{
			Event_fill=1;
			howLuckyAreYou=RandomNumber(100)+1;
			if(howLuckyAreYou<=50)itemGainedId=RandomNumber(3)+1;
			else if(howLuckyAreYou<=85)itemGainedId=RandomNumber(3)+4;
			else if(howLuckyAreYou<=95)itemGainedId=RandomNumber(4)+7;
			else if(howLuckyAreYou<=99)itemGainedId=RandomNumber(3)+11;
			else itemGainedId=RandomNumber(7)+14;
			item[itemGainedId]++;
		}
		else Event_fill=0;
		loop_BackMenu:;
		condition();
		attribute();
		cout<<"当前时间:第"<<day<<"天。\n";
		cout<<"当前层数:第"<<floor<<"层。\n";
		cout<<"事件:";
		if(character=="qwyzh"&&day==1){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);cout<<"青蛙养殖户被青蛙之神诅咒，-50HP\n     ";}
		if(character=="zz"){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);cout<<"长者汲取献祭者的生命，+1HP\n     ";}
		if(character=="hynh"){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);cout<<"红衣男孩的生命向长者流淌，-1HP\n     ";}
		if(input1=='4'){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);cout<<"上楼探索，获得"<<xpGainedFromUpstair<<"XP\n     ";} 
		if(Event_frog){title="膜塔101层";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);cout<<"不小心踩死了一只青蛙……";
		if(isFullHP)cout<<"-1HP";else cout<<"-1HP上限";cout<<"\n     ";}
		if(Event_hurt){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);cout<<"遭遇怪物，-"<<hp_lost<<"HP\n     ";
						if(character=="hmfs"){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);cout<<"黑魔法师凝聚自身法力，+"<<mp_gained<<"MP\n     ";}//
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);cout<<"击杀怪物，获得"<<xpGainedFromKilling<<"XP\n     ";}
		if(Event_darkShield){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);cout<<"黑魔法师受到致命伤害，已启动黑暗屏障，消耗MP抵挡溢出伤害\n     ";}
		if(Event_fill){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);cout<<"获得物品："<<itemsName(itemGainedId)<<"\n     ";}
		if(skill>0){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);cout<<"友情提示：有天赋点未分配\n     ";}
		cout<<"\b\b\b\b\b";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		menu();
		if(input1=='1'||input1=='2'||input1=='3')
		{
			input1=input2;
			goto loop_BackMenu;
		} 
		clean();
	}while(hp>0&&floor<101);//游戏结束判定———————————————————————————————————————————————————— 
	if(floor==101&&hp>0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);cout<<"你征服了膜塔，从此膜塔成为了一个传说……";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);cout<<"层数:101\n用时:"<<++day<<"天。\n";
	}
	else
	{
		if(input1=='4')floor--;
		if(input1=='5')floor++; 
		if(character=="zz"){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);cout<<"你是真的菜，长者竟然能被你玩死！";}
		else{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);cout<<"你的生命已被续给长者，灵魂融入了长者的无尽生命长河。";}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);cout<<"层数:"<<floor<<endl;
	}
	cout<<"角色:";
	if(character=="cjmfs"){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);cout<<"初阶魔法使"<<endl;}
	else if(character=="qwyzh"){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);cout<<"青蛙养殖户"<<endl;}
	else if(character=="hynh"){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);cout<<"红衣男孩"<<endl;}
	else if(character=="hmfs"){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);cout<<"黑魔法师"<<endl;}
	else if(character=="zz"){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);cout<<"长者"<<endl;}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	cout<<"菜单:[r]重试\n     [x]退出\n";
	while(1)
	{
		input1=getche();
		if(input1!='r'&&input1!='x')
		cout<<"\b \b";
		else break;
	}
	if(input1=='r')goto loop_Retry;
}
void notice()//公告板——————————————————————————————————————————————————————————— 
{
	cout<<"密码正确。\n";
	cout<<"如有BUG或建议请联系QQ：2535033006。\n";
	cout<<"本软件仅供学习交流，请勿用于商业用途。\n";
	cout<<"游戏方式：输入方括号内的字母即可。\n";
	cout<<"游戏目标：上楼获得经验，但有可能损失生命；下楼则不会。灵活使用物品，活着走上101层。\n";
	cout<<"轻按 N 浏览更新日志\n"; 
	cout<<"其它任意键开始。\n";
}
void updateLog()
{
	clean(); 
	cout<<"1.08：\n";
	cout<<"      1、更改部分文字描述；\n";
	cout<<"      2、新增新手教程；\n";
	cout<<"      3、新增空余天赋点的提醒文字；\n";
	cout<<"      4、加入";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);cout<<"膜法彩蛋";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);cout<<"。\n";
	cout<<"1.09~1.10：\n";
	cout<<"      1、加入五个新角色对应五个难度：长者-休闲、黑魔法师-简单、初阶魔法使-普通、青蛙养殖户-困难、红衣男孩-炼狱；\n";
	cout<<"      2、平衡了 召唤术-闪现 的强度，现在每次闪现会随机向上传送1~5层，消耗50MP；\n";
	cout<<"      3、平衡了 三星幸运药水 的强度，现在每次使用会增加70点幸运；\n";
	cout<<"      4、优化了程序架构。\n";
	cout<<"1.11：\n";
	cout<<"      1、优化了游戏界面；\n";
	cout<<"\n任意键开始。";
}
int main()
{
	string password="123456",pw;
	cout<<"输入密码:";
	cin>>pw;
	if(pw!=password)return 0;
	clean();
	notice();
	pw=getche();
	if(pw=="n"){updateLog();pw=getche();}
	game();
} 
