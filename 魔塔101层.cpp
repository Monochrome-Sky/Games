#include<iostream>
#include<windows.h>
#include<conio.h>
#include<headtitle.h>
#include<random.h>
#define e 1.718281828459
string title="ħ��101��";
void clean()//�������������������������������������������������������������������������������������������������������������������������������� 
{
	system("cls");
	headtitle("                                ",title,"1.11");
}//������������������������������������������������������������������������������������������������������������������������������������������ 
int xp=0,xp_max=100,lv=1,skill=50,day=0,floor=1,hp=100,hp_max=100,mp=0,mp_max=0,luck=0,magic=0;//ȫ�ֱ���
string character="cjmfs";
int item[30];
char input1,input2,input3;
int Event_poison=0;
void condition()//�����ײ����������⡪������������������������������������������������������������������������������������������������������������������ 
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
void attribute()//��ʾ���ԡ������������������������������������������������������������������������������������������������������������������� 
{
	condition(); 
	cout<<"��ɫ:";
	if(character=="cjmfs"){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);cout<<"����ħ��ʹ"<<endl;}
	else if(character=="qwyzh"){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);cout<<"������ֳ��"<<endl;}
	else if(character=="hynh"){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);cout<<"�����к�"<<endl;}
	else if(character=="hmfs"){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);cout<<"��ħ��ʦ"<<endl;}
	else if(character=="zz"){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);cout<<"����"<<endl;}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	cout<<"��ǰ����:"<<endl;
	//HP
	bar(hp,hp_max,207,79);SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);cout<<"         HP:"<<hp<<"/"<<hp_max<<endl;
	bar(mp,mp_max,191,63);SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);cout<<"         MP:"<<mp<<"/"<<mp_max<<endl;
	bar(luck,1000,223,95);SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);cout<<"         ����:";
	if(luck<1000)cout<<luck<<endl;else cout<<"MAX\n";
	bar(xp,xp_max,239,111);SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);cout<<"         XP:(Lv."<<lv<<")"<<xp<<"/"<<xp_max<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);cout<<"״̬:";
	if(hp<=0){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);cout<<"����\n";}
	else{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);cout<<"����\n";}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	cout<<"________________________________________________________________________________\n";
}
int item_use(int id)//ʹ����Ʒ�������������������������������������������������������������������������������������������������������������������� 
{
	int p;//
	if(item[id]>0)
	{
		item[id]--;//��Ʒ���� 
		switch(id)//��Ʒ��Ч 
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
void bag()//���������������������������������������������������������������������������������������������������������������������������� 
{
	int ifUse=0,id,page=1;//id��������1-31-3������ҩˮ��4-61-3��ħ��ҩˮ��7-91-3������ҩˮ��10����ʯ�� 
	loop_backbag:;
	clean();
	attribute();
	cout<<"������Ʒ:\n         ";
	if(page==1)//��һҳ 
	{
		for(id=1;id<11;id++)
		{
			if(item[id]>0)
			{
				if(id==10)cout<<"[0]";
				else cout<<"["<<id<<"]";
				switch(id)
				{
					case 1:cout<<"һ������ҩˮ x ";break;
					case 2:cout<<"��������ҩˮ x ";break;
					case 3:cout<<"��������ҩˮ x ";break;
					case 4:cout<<"һ��ħ��ҩˮ x ";break;
					case 5:cout<<"����ħ��ҩˮ x ";break;
					case 6:cout<<"����ħ��ҩˮ x ";break;
					case 7:cout<<"һ������ҩˮ x ";break;
					case 8:cout<<"��������ҩˮ x ";break;
					case 9:cout<<"��������ҩˮ x ";break;
					case 10:cout<<"����ʯ x ";break;
				}
				cout<<item[id]<<"\n         "; //��Ʒ��� 
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
				switch(id)//11-12����,13����,14-20���� 
				{
					case 11:cout<<"һ�������ؼ� x ";break;
					case 12:cout<<"���������ؼ� x ";break;
					case 13:cout<<"һ�����־��� x ";break;
					case 14:cout<<"һ�Ǻڿ��۾� x ";break;
					case 15:cout<<"���Ǻڿ��۾� x ";break;
					case 16:cout<<"���Ǻڿ��۾� x ";break;
					case 17:cout<<"���Ǻڿ��۾� x ";break;
					case 18:cout<<"���Ǻڿ��۾� x ";break;
					case 19:cout<<"���Ǻڿ��۾� x ";break;
					case 20:cout<<"���Ǻڿ��۾� x ";break;
				}
				cout<<item[id]<<"\n         "; 
			}
		}
	}
	cout<<"\nҳ��:"<<page<<"/2\n";
	cout<<"[q]��һҳ\n[w]��һҳ\n������������ء�\n";
	if(ifUse)
	{
		cout<<"\n\nʹ�óɹ�";
		if(character=="qwyzh"&&page==1&&input3!='0')//������ֳ��-����-��ѧ��Ⱦ 
		{
			if((RandomNumber(100)+1)>(80+0.01*luck))
			{
				hp-=5;
				cout<<"����"; 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
				cout<<"\nҩ���ж���-5HP\n\n";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
			}
			else cout<<"��\n\n";
		}
		else if(character=="hynh"&&page==1&&input3=='0')//�����к�-����-������� 
		{
			hp-=99999; 
			cout<<"����"; 
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
			cout<<"\n�����к��Ļ��Ǳ��������ǣ����޷����ܴ���ʯʱ��Ť���ľ��ҳ�������������HP-99999\n\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		}
		else cout<<"��\n\n";
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
		case 1:return "һ������ҩˮ";break;
		case 2:return "��������ҩˮ";break;
		case 3:return "��������ҩˮ";break;
		case 4:return "һ��ħ��ҩˮ";break;
		case 5:return "����ħ��ҩˮ";break;
		case 6:return "����ħ��ҩˮ";break;
		case 7:return "һ������ҩˮ";break;
		case 8:return "��������ҩˮ";break;
		case 9:return "��������ҩˮ";break;
		case 10:return "����ʯ";break;
		case 11:return "һ�������ؼ�";break;
		case 12:return "���������ؼ�";break;
		case 13:return "һ�����־���";break;
		case 14:return "һ�Ǻڿ��۾�";break;
		case 15:return "���Ǻڿ��۾�";break;
		case 16:return "���Ǻڿ��۾�";break;
		case 17:return "���Ǻڿ��۾�";break;
		case 18:return "���Ǻڿ��۾�";break;
		case 19:return "���Ǻڿ��۾�";break;
		case 20:return "���Ǻڿ��۾�";break;
	}
}
void conjuration()//�ٻ������������������������������������������������������������������������������������������������������������������� 
{
	int cost;
	loop_BackConjuration:;
	clean();
	attribute();
	cout<<"�ٻ���:\n";
	if(magic==0)
	{
		cout<<"        ��\n\n";
		cost=0;
	}
	else if(magic==11||magic==12)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);cout<<"        ����\n\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);cout<<"MP����:";
		cost=30-5*(magic-10);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);cout<<cost<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	}
	else if(magic==13)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);cout<<"        ����\n\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);cout<<"MP����:";
		cost=50;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);cout<<cost<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	}
	else if(magic>=14&&magic<=20)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);cout<<"        ����\n\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);cout<<"MP����:";
		cost=29-magic;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);cout<<cost<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	}
	if(magic!=0)cout<<"�˵�:[1]����\n"; 
	cout<<"������������ء�\n"; 
	input3=getche();
	if(magic==0||mp<cost){}
	else if(input3=='1'&&character=="hynh")//�����к�-����-���з�ӡ 
	{
		clean();
		cout<<"�ٻ��� ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		if(magic==11||magic==12)cout<<"����"; 
		else if(magic==13)cout<<"����";
		else if(magic>=14&&magic<=20)cout<<"����";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout<<" �ٻ�ʧ��\n\n";
		cout<<"��������ء�\n";
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
		cout<<"�ٻ��� ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		if(magic==11||magic==12)cout<<"����"; 
		else if(magic==13)cout<<"����";
		else if(magic>=14&&magic<=20)cout<<"����";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout<<" ����Ч\n\n";
		cout<<"��������ء�\n";
		input3=getche();
		goto loop_BackConjuration;
	}
}
void talent()//�츳���������������������������������������������������������������������������������������������������������������� 
{
	clean();
	attribute();
	cout<<"�츳��:"<<skill<<endl;
	cout<<"�˵�:[1]";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);cout<<"��ǿ��׳����������+1��\n";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	cout<<"     [2]";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);cout<<"ħ����ͨ��ħ������+1��\n";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	cout<<"     [3]";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);cout<<"ŷ�����壨����+5��\n";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	cout<<"������������ء�\n"; 
	input3=getche();
	if(skill==0){}
	else if(input3=='1'){skill--;hp_max++;hp++;talent();}
	else if(input3=='2'){skill--;mp_max++;mp++;talent();}
	else if(input3=='3'){skill--;luck+=5;talent();}
}
void menu()//�˵������������������������������������������������������������������������������������������������������������� 
{
	cout<<"�˵�:[1]�츳\n";
	cout<<"     [2]������Ʒ\n";
	cout<<"     [3]�ٻ���\n";
	cout<<"     [4]��¥\n";
	if(floor>1)cout<<"     [5]��¥\n";
	while(1)//������Ч���� 
	{
		input2=input1;
		input1=getche();
		if(input1!='1'&&input1!='2'&&input1!='3'&&input1!='4'&&input1!='5')cout<<"\b \b";
		else if(input1=='5'&&floor==1)cout<<"\b \b";
		else break;
	}
	if(input1=='1')//����1���鿴���� 
	{
		talent();
		clean();
	}
	else if(input1=='2')//����2���鿴���� 
	{
		bag();
		clean(); 
	}
	else if(input1=='3')//����3���鿴�ٻ� 
	{
		conjuration();
		clean();
	}
	else if(input1=='4')floor++;//����4����¥ 
	else if(input1=='5')floor--;//����5����¥
}
void game()//��Ϸ������������������������������������������������������������������������������������������������������������������������ 
{
	loop_Retry:;
	clean();
	for(int i=1;i<6;i++)
	{
		cout<<"����ħ��֮ǰ����ѡһ��ϲ���Ľ�ɫ�ɣ�\n\n";
		if(i==1)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);cout<<"                               ����\n\n";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
			cout<<"�������ܣ������޽�������ӵ�м�����������ӵ��999��ʼHP���ޡ�"<<endl;
			cout<<"          ����ԴȪ�����߼�ȡ�׼��ߵ�������ÿ��ظ�1HP��"<<endl;
			cout<<"          ��󸻤�壺���ߺ�����֮������׺͹���������ȵ����ܡ�"<<endl; 
		}
		else if(i==2)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);cout<<"                               ��ħ��ʦ\n\n";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
			cout<<"�������ܣ�ħ����ͨ����ħ��ʦԨ����ѧʶ������ǿ��ķ���������ʹ��ʼMP���޺�MP��Ϊ50��"<<endl;
			cout<<"          �ѻ���Լ����ħ��ʦ���Ĥ��ǩ����Լ��ÿ���ܵ����﹥��ʱ��50%�˺�ת��ΪMP��"<<endl;
			cout<<"          �ڰ����ϣ���ħ��ʦ��������������������ħ�������������������ܵ����Թ��﹥���������˺�ʱ����1HP�������ĵ�������˺�֮MP��������˺�����MP��������������HPֵ���ܡ�"<<endl;
		}
		else if(i==3)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);cout<<"                               ����ħ��ʹ\n\n";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
			cout<<"�������ܣ���"<<endl; 
		}
		else if(i==4)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);cout<<"                               ������ֳ��\n\n";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
			cout<<"�������ܣ��������ܣ�������ֳ������Ӵ��������ܣ��ӽ���ħ����һ�쿪ʼ�ͻᱻ���ܾ�����"<<endl;
			cout<<"          ��ѧ��Ⱦ��������ֳ��ʹ�����Ｄ�غ���Ч������ֳ���ܣ�������Я����ҩˮ���ܱ�������Ⱦ��ÿ��ʹ��ҩˮʱ��20%������ʧ5HP��"<<endl;
			cout<<"          �Ϲ���ӡ��������ֳ���汲����ֳ����Ϊ����ɱ�����������ܣ�����ܵ�����֮�����䣬����ħ��ʱ-50HP��"<<endl;
		}	
		else if(i==5)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);cout<<"                               �����к�\n\n";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
			cout<<"�������ܣ��������񣺺����к�������ע���������ʣ�ÿ����ʧ1HP�������к��Ը��ֹ���о�£���ã����ּ�������50%��"<<endl;
			cout<<"          ���з�ӡ�������к����������Ա��������޷�ʹ���κ��ٻ�����"<<endl;
			cout<<"          ������ǣ������к��������롢������¡�׹������������������ǣ������޷�����ʱ��Ť���ľ��ҳ������ʹ�ô���ʯ���ᱬ�������"<<endl;
		}
		cout<<"\n�˵�:[1]�����ˣ�\n";
		cout<<"     [2]��һ��\n";
		while(1)//������Ч���� 
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
	//����ȫ�ֱ���
	xp=0;xp_max=100;lv=1;skill=50;day=0;floor=1;hp=100;hp_max=100;mp=0;mp_max=0;luck=0;magic=0;
	int parameter=0,hp_lost=0,howLuckyAreYou=0,mp_gained=0,Event_hurt=0,Event_fill=0,Event_frog=0,Event_darkShield=0,xpGainedFromUpstair=0,xpGainedFromKilling=0,itemGainedId=0,isFullHP=0;
	for(int a=1;a<21;a++)item[a]=0;
	//��������-��Ϸ��ʼʱ 
	if(character=="zz")//���� 
	{
		hp_max=999;
		hp=999;//�����޽� 
	}
	else if(character=="hmfs")//��ħ��ʦ 
	{
		mp_max=50;
		mp=50;//ħ����ͨ 
	}
	else if(character=="qwyzh")//������ֳ�� 
	{
		hp=50;//�Ϲ���ӡ 
	}
	// 
	do//��Ϸѭ�� 
	{
		day++;
		//��������-ÿ�� 
		if(character=="zz")
		{
			hp++;//����-����-����ԴȪ 
		} 
		if(character=="hynh")
		{
			hp--;//�����к�-����-�������� 
		}
		// 
		condition();
		if(input1=='4')//��þ���
		{
			xpGainedFromUpstair=RandomNumber(floor)+1;
			xp+=xpGainedFromUpstair;
		}
		if((day>100&&character!="zz")||character=="qwyzh")//�����¼� 
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
		parameter=RandomNumber(100)+1;//�����¼� 
		if(character=="hynh")parameter/=2;//�����к�-����-�������� 
		if(parameter<=(20-0.01*luck)&&input1=='4')
		{
			Event_hurt=1;
			hp_lost=RandomNumber(20+2*floor)+1;
			xpGainedFromKilling=RandomNumber(hp_lost);//ɱ�ֵ����� 
			xp+=xpGainedFromKilling;
			hp-=hp_lost;
			if(character=="hmfs")
			{
				mp_gained=(hp_lost+1)/2;
				mp+=mp_gained;//��ħ��ʦ-����-�ѻ���Լ 
				condition();
				if(hp<=0&&mp>0)//��ħ��ʦ-����-�ڰ����� 
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
		parameter=RandomNumber(100)+1;//�����Ʒ�¼� 
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
		cout<<"��ǰʱ��:��"<<day<<"�졣\n";
		cout<<"��ǰ����:��"<<floor<<"�㡣\n";
		cout<<"�¼�:";
		if(character=="qwyzh"&&day==1){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);cout<<"������ֳ��������֮�����䣬-50HP\n     ";}
		if(character=="zz"){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);cout<<"���߼�ȡ�׼��ߵ�������+1HP\n     ";}
		if(character=="hynh"){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);cout<<"�����к��������������ʣ�-1HP\n     ";}
		if(input1=='4'){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);cout<<"��¥̽�������"<<xpGainedFromUpstair<<"XP\n     ";} 
		if(Event_frog){title="Ĥ��101��";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);cout<<"��С�Ĳ�����һֻ���ܡ���";
		if(isFullHP)cout<<"-1HP";else cout<<"-1HP����";cout<<"\n     ";}
		if(Event_hurt){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);cout<<"�������-"<<hp_lost<<"HP\n     ";
						if(character=="hmfs"){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);cout<<"��ħ��ʦ������������+"<<mp_gained<<"MP\n     ";}//
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);cout<<"��ɱ������"<<xpGainedFromKilling<<"XP\n     ";}
		if(Event_darkShield){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);cout<<"��ħ��ʦ�ܵ������˺����������ڰ����ϣ�����MP�ֵ�����˺�\n     ";}
		if(Event_fill){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);cout<<"�����Ʒ��"<<itemsName(itemGainedId)<<"\n     ";}
		if(skill>0){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);cout<<"������ʾ�����츳��δ����\n     ";}
		cout<<"\b\b\b\b\b";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		menu();
		if(input1=='1'||input1=='2'||input1=='3')
		{
			input1=input2;
			goto loop_BackMenu;
		} 
		clean();
	}while(hp>0&&floor<101);//��Ϸ�����ж��������������������������������������������������������������������������������������������������������� 
	if(floor==101&&hp>0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);cout<<"��������Ĥ�����Ӵ�Ĥ����Ϊ��һ����˵����";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);cout<<"����:101\n��ʱ:"<<++day<<"�졣\n";
	}
	else
	{
		if(input1=='4')floor--;
		if(input1=='5')floor++; 
		if(character=="zz"){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);cout<<"������Ĳˣ����߾�Ȼ�ܱ���������";}
		else{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);cout<<"��������ѱ��������ߣ���������˳��ߵ��޾��������ӡ�";}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);cout<<"����:"<<floor<<endl;
	}
	cout<<"��ɫ:";
	if(character=="cjmfs"){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);cout<<"����ħ��ʹ"<<endl;}
	else if(character=="qwyzh"){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);cout<<"������ֳ��"<<endl;}
	else if(character=="hynh"){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);cout<<"�����к�"<<endl;}
	else if(character=="hmfs"){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);cout<<"��ħ��ʦ"<<endl;}
	else if(character=="zz"){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);cout<<"����"<<endl;}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	cout<<"�˵�:[r]����\n     [x]�˳�\n";
	while(1)
	{
		input1=getche();
		if(input1!='r'&&input1!='x')
		cout<<"\b \b";
		else break;
	}
	if(input1=='r')goto loop_Retry;
}
void notice()//����塪�������������������������������������������������������������������������������������������������������������������� 
{
	cout<<"������ȷ��\n";
	cout<<"����BUG��������ϵQQ��2535033006��\n";
	cout<<"���������ѧϰ����������������ҵ��;��\n";
	cout<<"��Ϸ��ʽ�����뷽�����ڵ���ĸ���ɡ�\n";
	cout<<"��ϷĿ�꣺��¥��þ��飬���п�����ʧ��������¥�򲻻ᡣ���ʹ����Ʒ����������101�㡣\n";
	cout<<"�ᰴ N ���������־\n"; 
	cout<<"�����������ʼ��\n";
}
void updateLog()
{
	clean(); 
	cout<<"1.08��\n";
	cout<<"      1�����Ĳ�������������\n";
	cout<<"      2���������ֽ̳̣�\n";
	cout<<"      3�����������츳����������֣�\n";
	cout<<"      4������";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);cout<<"Ĥ���ʵ�";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);cout<<"��\n";
	cout<<"1.09~1.10��\n";
	cout<<"      1����������½�ɫ��Ӧ����Ѷȣ�����-���С���ħ��ʦ-�򵥡�����ħ��ʹ-��ͨ��������ֳ��-���ѡ������к�-������\n";
	cout<<"      2��ƽ���� �ٻ���-���� ��ǿ�ȣ�����ÿ�����ֻ�������ϴ���1~5�㣬����50MP��\n";
	cout<<"      3��ƽ���� ��������ҩˮ ��ǿ�ȣ�����ÿ��ʹ�û�����70�����ˣ�\n";
	cout<<"      4���Ż��˳���ܹ���\n";
	cout<<"1.11��\n";
	cout<<"      1���Ż�����Ϸ���棻\n";
	cout<<"\n�������ʼ��";
}
int main()
{
	string password="123456",pw;
	cout<<"��������:";
	cin>>pw;
	if(pw!=password)return 0;
	clean();
	notice();
	pw=getche();
	if(pw=="n"){updateLog();pw=getche();}
	game();
} 
