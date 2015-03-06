#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

bool infinit=false;
int turn=1;
int turn2=0;
bool totalflag = false;
bool segmentflag= false;

//ターンカウンター制作　一回の起動で終了させないためにwhile文で捕まえ、キーボード操作があればターン数を加算
//意図的な無限ループを使用
//イフ文がずっと処理されてるのを直したい　201510124
//naotta

int main()
{
	
	cout << "スペースでターン数の加算です" << endl;
	cout << "Aで特定敵専用ターン数の計算です" << endl;
	cout << "自分のターンに加算してください" << endl;
	cout << turn<< "ターン目です！" << endl;
	
	//継続条件はFalseのときループ
	while (infinit==false)
	{
		if (_kbhit() && _getch() == 27)infinit=true; //ASCIIコード　ESCに対応　ループの終了
		if (_kbhit() && _getch() == 32) //ASCIIコード　スペースに対応
		{
			turn += 1;
			cout << turn << "ターン目です！" << endl;
			totalflag = true;
		}
		if (turn % 4 == 0 || turn % 5 == 0)
		{
			if (totalflag == true)
			{
				cout << "次は" << turn << "ターン目です！" << endl;
				totalflag = false;
			}
		}

		if (_kbhit() && _getch() == 97) //ASCIIコード　Aに対応
		{
			turn += 1;
			turn2 += 1;
			cout << "特定敵との戦闘がはじまって" << turn2 << "ターン目です！" << endl;
			segmentflag = true;
		}
		if (turn2 % 4 == 0 || turn2 % 5 == 0)
		{
			if (segmentflag == true)
			{
				cout << "次は" << turn2 << "ターン目です！特殊攻撃に備えろ！！" << endl;
				segmentflag = false;
			}
		}
	}
}
