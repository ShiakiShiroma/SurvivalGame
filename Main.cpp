#include <stdio.h>
#include<time.h>
#include <windows.h>
#include<iostream>
#include"Human.h"
#include"Dog.h"
#include"Foods.h"
#define RANGE_STRING 10

bool is_FullWidth(char *str);
bool is_sameName(char *str, char *str2);
enum {
	PLAY = 0,
	EAT = 1
};

int main() {
	srand((unsigned int)time(NULL));		//rand関数が出力する値を完全にランダムにする

	char human_name[RANGE_STRING];
	char dog_name[RANGE_STRING];
	int command;
	int amount_of_foods;
	char name[RANGE_STRING];

	bool isGameOver = false;

	/************************[ゲーム開始]ここから****************************/
	printf("ヒトの名前を入力してください(5文字以内&アルファベット):");
	scanf_s("%5s", &human_name, 10);

	while (is_FullWidth(human_name)) {//入力された名前が全角かどうかを判断する
		scanf_s("%*[^\n]%*c");  //バッファクリア
		printf("入力をやり直してください:");
		scanf_s("%5s", &human_name, 10);
	}
	/*
	ここでバッファクリアを入れることで、6文字以上入力されたときに次のscanf_s()関数が動作しないようにする。
	*/
	scanf_s("%*[^\n]%*c");  //バッファクリア

	printf("イヌの名前を入力してください(5文字以内&アルファベット):");
	scanf_s("%5s", &dog_name, 10);

	while (is_FullWidth(dog_name) || is_sameName(dog_name, human_name)) {//入力された名前が全角かどうか、ヒトと同じかどうかを判断する
		scanf_s("%*[^\n]%*c");  //バッファクリア
		printf("入力をやり直してください:");
		scanf_s("%5s", &dog_name, 10);
	}
	/*
	ここでバッファクリアを入れることで、6文字以上入力されたときに次のscanf_s()関数が動作しないようにする。
	*/
	scanf_s("%*[^\n]%*c");  //バッファクリア

	printf("\n\n\n");

	//インスタンスを生成
	amount_of_foods = rand() % 100;
	Foods* foods = new Foods(amount_of_foods);
	Human man(human_name, foods);
	Dog dog(dog_name, foods);

	man.greet();
	dog.bark();

	/************************[ゲーム開始]ここまで**************************************/

	/************************************************[ゲーム中]ここから*******************************************/
	for (int days = 1; days < 11; days++) {
		printf("%d日目\n\n", days);
		man.show_status();
		dog.show_status();
		(*foods).show_stock();
		printf("\n");
		printf("0：%sと遊ぶ\n1：食事をする\n2：なにもしない\n", dog.m_name.c_str());
		printf("今日は何をしますか？ : ");

		//数字を打つまでループする
		while (scanf_s("%d", &command) == 0) {
			scanf_s("%*[^\n]%*c");  //バッファクリア
			printf("今日は何をしますか？ : ");
		}


		switch (command) {
		case PLAY:
			printf("PLAY\n");
			printf("超楽しい！\n");
			Sleep(2000);      //待機
			man.play();
			dog.play();
			break;

		case EAT:
			printf("EAT\n");
			if (foods->check_stock()) {
				printf("どちらが食事をしますか？(名前を入力):");  //どちらが食べるか決める
				scanf_s("%5s", &name, 10);

				printf("どのくらい食べますか？(数字を入力):");   //どのくらい食べるのか決める
				//数字を打つまでループする
				while (scanf_s("%d", &amount_of_foods) == 0) {
					scanf_s("%*[^\n]%*c");
					printf("どのくらい食べますか？(数字を入力):");
				}

				if (name == man.m_name) {
					man.eat(amount_of_foods);
					dog.get_flustration(rand() % 10);
				}
				else if (name == dog.m_name) {
					dog.eat(amount_of_foods);
					man.get_flustration(rand() % 10);
				}
				else {//例外処理
					printf("%s?そんなやつはいない\n", name);
					Sleep(1000);
					printf("今日は何もしなかった\n");
					man.get_flustration(10);
					dog.get_flustration(10);
				}
				Sleep(2000);      //待機
				amount_of_foods = 0;
			}
			else {
				printf("食料は無ぇよ\n");
				man.get_flustration(10);
				dog.get_flustration(10);
			}
			break;
		default://例外処理
			printf("・・・・\n");
			Sleep(1000);	//待機
			printf("今日は何もしなかった\n");
			man.get_flustration(10);
			dog.get_flustration(10);
			break;
		}
		Sleep(2000);

		man.get_hungry(5);
		dog.get_hungry(5);

		printf("%d日目が終わった\n", days);
		printf("\n\n\n");
		Sleep(2000);      //待機
		if ((dog.medicul_check() && man.medicul_check()) == false) {
			days = 100;
			isGameOver = true;
		}

	}
	/**************************************[ゲーム中]ここまで***********************************/
	/**************************************[ゲーム終了]ここから***********************************/
	delete foods;//メモリの開放
	if (isGameOver) {
		printf("\n\nGAME OVER\n\n");
		system("pause");
		return 0;
	}
	else {
		printf("\n\nGAME CLEAR\n\n");
		system("pause");
		return 0;
	}
	/**************************************[ゲーム終了]ここまで***********************************/
}


/*
name		: is_FullWidth
argument	: *str
return value: true/false
function	: バイト数を使って文字列が全角か半角か判断する。半角ならfalse、全角ならtrue
*/
bool is_FullWidth(char *c) {
	std::string str = c;
	
	while (!str.empty()) {
		//文字列の0番目が1バイト文字(半角)か否か判断する
		
		if (IsDBCSLeadByte(str[0]) == 0) {
			str.erase(0, 1);
		}
		else {//全角の場合
			return true;
		}
	}
	return false;
	//return (str[0] < 0x21 || str[0] > 0x7e) ? true : false;
}
/*
name		: is_FullWidth2
argument	: *str
return value: true/false
function	: 文字コードを使って1文字目が全角か半角か判断する。半角ならfalse、全角ならtrue
*/
bool is_FullWidth2(char *str) {
	return (str[0] < 0x21 || str[0] > 0x7e) ? true : false;
}



/*
name		: is_sameName
argument	: *str,*str2
return value: true/false
function	: 二つの文字列が同じかどうか判断し、同じならtrue、違うならfalseを返す。
*/

bool is_sameName(char *str, char *str2) {
	if (std::string(str).compare(str2) == 0) {
		printf("同じ名前です。\n");
		return true;
	}
	else {
		//printf("違う名前です。\n");
		return false;
	}
}
