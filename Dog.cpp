#include "Dog.h"

Dog::Dog(std::string name, Foods* foods):m_foods(foods) {
	srand((unsigned int)time(NULL));		//rand関数が出力する値を完全にランダムにする
	int random_hp = rand() % 100 + 5;	//0～100
	int random_stress = rand() % 100 - rand() % 10 - 10;	//0～100
	
	if (random_hp == 0) {//体力が0だった場合
		random_hp = 1;
	}
	if (random_stress == 100) {//ストレス値が100だった場合
		random_stress = 99;
	}
	//名前、体力、ストレス値を初期化する。
	m_name = name;
	m_hp = random_hp;
	m_stress = random_stress;

	m_foods = foods;//Foodsクラスのポインタを取得
}


/*
name		: eat
argument	: food
return value: なし
function	: 引数foodの分だけ体力m_hpが回復する。
			　ただし、体力の最大値は100である。体力が無いときは体力が回復しない。
*/
void Dog::eat( int food )
{
	int get_foods = m_foods->eat_foods(food);//foodsはポインタ型なので、アロー演算子を使う。
	//foodsはポインタ型なので、「(*m_foods).eat_foods(food);」でも記述できる。

	printf("[%sは体力が%d回復した]\n", m_name.c_str(), get_foods);
	m_hp = m_hp + get_foods;
	if (m_hp > 100) {
		m_hp = 100;
	}
}

/*
name		: play
argument	: なし
return value: なし
function	: ランダムで決まる疲労fatigueにより、体力m_hpが減少する。減少した分stressが減少する
*/
void Dog::play() {
	unsigned int fatigue = rand() % 10 + 5;

	m_hp = m_hp - fatigue;
	m_stress = m_stress - fatigue;
}

/*
name		: bark
argument	: なし
return value: なし
function	: 体力m_hpを5消費して吠える。体力が無い場合は吠えない。
*/
void Dog::bark() {

	if (m_hp <= 0) {
		printf("・・・・返事がない\n");
	}
	else {

		printf("%s「ワン！」\n",m_name.c_str());
	}
}

/*
name		: medicul_check
argument	: なし
return value: is_health_ok　　true/false
function	: 体力m_hpとストレスstressを調べて、健康ならtrue、不健康ならfalseを返す。
*/
bool Dog::medicul_check() {
	bool is_health_ok = true;

	if (m_hp <= 0) {
		is_health_ok = false;
		printf("%sは餓死した！\n", m_name.c_str());
	}
	else if (m_stress >= 100) {
		is_health_ok = false;
		printf("%sはストレスでおかしくなった！\n", m_name.c_str());
	}

	return is_health_ok;
}

/*
name		: show_status
argument	: なし
return value: nothing
function	: 名前、体力、ストレス値を表示する。
*/
void Dog::show_status() {
	//名前、体力、ストレスを見せる
	printf("[%5s]     HP:%d     STRESS:%d\n", m_name.c_str(), m_hp, m_stress);
}

/*
name		: get_hungry
argument	: how_much
return value: nothing
function	: 引数how_muchの分だけ体力m_hpを消費する
*/
void Dog::get_hungry(int how_much){
	m_hp = m_hp - how_much;
	printf("%sは%dおなかが空いた\n", m_name.c_str(),how_much);
}

/*
name		: get_flustration
argument	: how_much
return value: nothing
function	: 引数how_muchの分だけストレスm_stressがたまる
*/
void Dog::get_flustration(int how_much) {
	m_stress = m_stress + how_much;
	printf("%sは%dストレスが溜まった！\n", m_name.c_str(), how_much);
}