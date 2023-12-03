#ifndef __DOG_H__
#define __DOG_H__
#include<string>
#include<stdlib.h>
#include<iostream>
#include<time.h>
#include"Foods.h"
class Dog {
	public:
		Dog(std::string name,Foods* foods);

		std::string m_name;		//名前

		void eat(int food);		//エサを与える
		void run();					//走る
		void bark();				//吠える
		bool medicul_check();		//健康状態を調べる
		void play();			//遊ぶ
		void show_status();		//ステータスを見せる
		void get_hungry(int how_much);		//おなかが空く
		void get_flustration(int how_much);		//ストレスがたまる

	private:
		int m_hp;		//体力
		int m_stress;	//ストレス
		Foods* m_foods;
};



#endif

