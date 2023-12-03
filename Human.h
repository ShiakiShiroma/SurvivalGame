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
	//�R���X�g���N�^
	Human( std::string init_name,Foods* foods);

	std::string m_name;		//���O

	void eat(int food);		//�H�ׂ�
	void show_profile(int num);//�v���t�B�[����������
	void greet();			//���A����
	bool medicul_check();	//���N��Ԃ𒲂ׂ�
	void play();			//�V��
	void show_status();		//�X�e�[�^�X��������
	void get_hungry(int how_much);		//���Ȃ�����
	void get_flustration(int how_much);		//�X�g���X�����܂�

private :
	int m_hp;				//�̗�
	int m_stress;			//�X�g���X
	Foods* m_foods;


};


#endif

