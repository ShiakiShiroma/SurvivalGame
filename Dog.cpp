#include "Dog.h"

Dog::Dog(std::string name, Foods* foods):m_foods(foods) {
	srand((unsigned int)time(NULL));		//rand�֐����o�͂���l�����S�Ƀ����_���ɂ���
	int random_hp = rand() % 100 + 5;	//0�`100
	int random_stress = rand() % 100 - rand() % 10 - 10;	//0�`100
	
	if (random_hp == 0) {//�̗͂�0�������ꍇ
		random_hp = 1;
	}
	if (random_stress == 100) {//�X�g���X�l��100�������ꍇ
		random_stress = 99;
	}
	//���O�A�̗́A�X�g���X�l������������B
	m_name = name;
	m_hp = random_hp;
	m_stress = random_stress;

	m_foods = foods;//Foods�N���X�̃|�C���^���擾
}


/*
name		: eat
argument	: food
return value: �Ȃ�
function	: ����food�̕������̗�m_hp���񕜂���B
			�@�������A�̗͂̍ő�l��100�ł���B�̗͂������Ƃ��̗͑͂��񕜂��Ȃ��B
*/
void Dog::eat( int food )
{
	int get_foods = m_foods->eat_foods(food);//foods�̓|�C���^�^�Ȃ̂ŁA�A���[���Z�q���g���B
	//foods�̓|�C���^�^�Ȃ̂ŁA�u(*m_foods).eat_foods(food);�v�ł��L�q�ł���B

	printf("[%s�̗͑͂�%d�񕜂���]\n", m_name.c_str(), get_foods);
	m_hp = m_hp + get_foods;
	if (m_hp > 100) {
		m_hp = 100;
	}
}

/*
name		: play
argument	: �Ȃ�
return value: �Ȃ�
function	: �����_���Ō��܂��Jfatigue�ɂ��A�̗�m_hp����������B����������stress����������
*/
void Dog::play() {
	unsigned int fatigue = rand() % 10 + 5;

	m_hp = m_hp - fatigue;
	m_stress = m_stress - fatigue;
}

/*
name		: bark
argument	: �Ȃ�
return value: �Ȃ�
function	: �̗�m_hp��5����Ėi����B�̗͂������ꍇ�͖i���Ȃ��B
*/
void Dog::bark() {

	if (m_hp <= 0) {
		printf("�E�E�E�E�Ԏ����Ȃ�\n");
	}
	else {

		printf("%s�u�����I�v\n",m_name.c_str());
	}
}

/*
name		: medicul_check
argument	: �Ȃ�
return value: is_health_ok�@�@true/false
function	: �̗�m_hp�ƃX�g���Xstress�𒲂ׂāA���N�Ȃ�true�A�s���N�Ȃ�false��Ԃ��B
*/
bool Dog::medicul_check() {
	bool is_health_ok = true;

	if (m_hp <= 0) {
		is_health_ok = false;
		printf("%s�͉쎀�����I\n", m_name.c_str());
	}
	else if (m_stress >= 100) {
		is_health_ok = false;
		printf("%s�̓X�g���X�ł��������Ȃ����I\n", m_name.c_str());
	}

	return is_health_ok;
}

/*
name		: show_status
argument	: �Ȃ�
return value: nothing
function	: ���O�A�̗́A�X�g���X�l��\������B
*/
void Dog::show_status() {
	//���O�A�̗́A�X�g���X��������
	printf("[%5s]     HP:%d     STRESS:%d\n", m_name.c_str(), m_hp, m_stress);
}

/*
name		: get_hungry
argument	: how_much
return value: nothing
function	: ����how_much�̕������̗�m_hp�������
*/
void Dog::get_hungry(int how_much){
	m_hp = m_hp - how_much;
	printf("%s��%d���Ȃ����󂢂�\n", m_name.c_str(),how_much);
}

/*
name		: get_flustration
argument	: how_much
return value: nothing
function	: ����how_much�̕������X�g���Xm_stress�����܂�
*/
void Dog::get_flustration(int how_much) {
	m_stress = m_stress + how_much;
	printf("%s��%d�X�g���X�����܂����I\n", m_name.c_str(), how_much);
}