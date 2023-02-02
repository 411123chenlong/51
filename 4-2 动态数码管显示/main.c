#include <REGX52.H>

//鏁扮爜绠℃鐮佽〃
unsigned char NixieTable[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

//寤舵椂瀛愬嚱鏁�
void Delay(unsigned int xms)
{
	unsigned char i, j;
	while(xms--)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
	}
}

//鏁扮爜绠℃樉绀哄瓙鍑芥暟
void Nixie(unsigned char Location,Number)
{
	switch(Location)		//浣嶇爜杈撳嚭
	{
		case 1:P2_4=1;P2_3=1;P2_2=1;break;
		case 2:P2_4=1;P2_3=1;P2_2=0;break;
		case 3:P2_4=1;P2_3=0;P2_2=1;break;
		case 4:P2_4=1;P2_3=0;P2_2=0;break;
		case 5:P2_4=0;P2_3=1;P2_2=1;break;
		case 6:P2_4=0;P2_3=1;P2_2=0;break;
		case 7:P2_4=0;P2_3=0;P2_2=1;break;
		case 8:P2_4=0;P2_3=0;P2_2=0;break;
	}
	P0=NixieTable[Number];	//娈电爜杈撳嚭
	Delay(1);				//鏄剧ず涓€娈垫椂闂�
	P0=0x00;				//娈电爜娓�0锛屾秷褰�
}

void main()
{
	while(1)
	{
		Nixie(1,1);		//鍦ㄦ暟鐮佺鐨勭1浣嶇疆鏄剧ず1
//		Delay(20);
		Nixie(2,2);		//鍦ㄦ暟鐮佺鐨勭2浣嶇疆鏄剧ず2
//		Delay(20);
		Nixie(3,3);		//鍦ㄦ暟鐮佺鐨勭3浣嶇疆鏄剧ず3
//		Delay(20);
	}
}
