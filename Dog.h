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

		std::string m_name;		//���O

		void eat(int food);		//�G�T��^����
		void run();					//����
		void bark();				//�i����
		bool medicul_check();		//���N��Ԃ𒲂ׂ�
		void play();			//�V��
		void show_status();		//�X�e�[�^�X��������
		void get_hungry(int how_much);		//���Ȃ�����
		void get_flustration(int how_much);		//�X�g���X�����܂�

	private:
		int m_hp;		//�̗�
		int m_stress;	//�X�g���X
		Foods* m_foods;
};



#endif

