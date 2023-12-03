#ifndef __HUMAN_H__
#define __HUMAN_H__

#include<string>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include"Foods.h"
class Human 
{
public :
	//コンストラクタ
	Human( std::string init_name,Foods* foods);

	std::string m_name;		//名前

	void eat(int food);		//食べる
	void show_profile(int num);//プロフィールを見せる
	void greet();			//挨拶する
	bool medicul_check();	//健康状態を調べる
	void play();			//遊ぶ
	void show_status();		//ステータスを見せる
	void get_hungry(int how_much);		//おなかが空く
	void get_flustration(int how_much);		//ストレスがたまる

private :
	int m_hp;				//体力
	int m_stress;			//ストレス
	Foods* m_foods;


};


#endif

