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
	srand((unsigned int)time(NULL));		//rand�֐����o�͂���l�����S�Ƀ����_���ɂ���

	char human_name[RANGE_STRING];
	char dog_name[RANGE_STRING];
	int command;
	int amount_of_foods;
	char name[RANGE_STRING];

	bool isGameOver = false;

	/************************[�Q�[���J�n]��������****************************/
	printf("�q�g�̖��O����͂��Ă�������(5�����ȓ�&�A���t�@�x�b�g):");
	scanf_s("%5s", &human_name, 10);

	while (is_FullWidth(human_name)) {//���͂��ꂽ���O���S�p���ǂ����𔻒f����
		scanf_s("%*[^\n]%*c");  //�o�b�t�@�N���A
		printf("���͂���蒼���Ă�������:");
		scanf_s("%5s", &human_name, 10);
	}
	/*
	�����Ńo�b�t�@�N���A�����邱�ƂŁA6�����ȏ���͂��ꂽ�Ƃ��Ɏ���scanf_s()�֐������삵�Ȃ��悤�ɂ���B
	*/
	scanf_s("%*[^\n]%*c");  //�o�b�t�@�N���A

	printf("�C�k�̖��O����͂��Ă�������(5�����ȓ�&�A���t�@�x�b�g):");
	scanf_s("%5s", &dog_name, 10);

	while (is_FullWidth(dog_name) || is_sameName(dog_name, human_name)) {//���͂��ꂽ���O���S�p���ǂ����A�q�g�Ɠ������ǂ����𔻒f����
		scanf_s("%*[^\n]%*c");  //�o�b�t�@�N���A
		printf("���͂���蒼���Ă�������:");
		scanf_s("%5s", &dog_name, 10);
	}
	/*
	�����Ńo�b�t�@�N���A�����邱�ƂŁA6�����ȏ���͂��ꂽ�Ƃ��Ɏ���scanf_s()�֐������삵�Ȃ��悤�ɂ���B
	*/
	scanf_s("%*[^\n]%*c");  //�o�b�t�@�N���A

	printf("\n\n\n");

	//�C���X�^���X�𐶐�
	amount_of_foods = rand() % 100;
	Foods* foods = new Foods(amount_of_foods);
	Human man(human_name, foods);
	Dog dog(dog_name, foods);

	man.greet();
	dog.bark();

	/************************[�Q�[���J�n]�����܂�**************************************/

	/************************************************[�Q�[����]��������*******************************************/
	for (int days = 1; days < 11; days++) {
		printf("%d����\n\n", days);
		man.show_status();
		dog.show_status();
		(*foods).show_stock();
		printf("\n");
		printf("0�F%s�ƗV��\n1�F�H��������\n2�F�Ȃɂ����Ȃ�\n", dog.m_name.c_str());
		printf("�����͉������܂����H : ");

		//������ł܂Ń��[�v����
		while (scanf_s("%d", &command) == 0) {
			scanf_s("%*[^\n]%*c");  //�o�b�t�@�N���A
			printf("�����͉������܂����H : ");
		}


		switch (command) {
		case PLAY:
			printf("PLAY\n");
			printf("���y�����I\n");
			Sleep(2000);      //�ҋ@
			man.play();
			dog.play();
			break;

		case EAT:
			printf("EAT\n");
			if (foods->check_stock()) {
				printf("�ǂ��炪�H�������܂����H(���O�����):");  //�ǂ��炪�H�ׂ邩���߂�
				scanf_s("%5s", &name, 10);

				printf("�ǂ̂��炢�H�ׂ܂����H(���������):");   //�ǂ̂��炢�H�ׂ�̂����߂�
				//������ł܂Ń��[�v����
				while (scanf_s("%d", &amount_of_foods) == 0) {
					scanf_s("%*[^\n]%*c");
					printf("�ǂ̂��炢�H�ׂ܂����H(���������):");
				}

				if (name == man.m_name) {
					man.eat(amount_of_foods);
					dog.get_flustration(rand() % 10);
				}
				else if (name == dog.m_name) {
					dog.eat(amount_of_foods);
					man.get_flustration(rand() % 10);
				}
				else {//��O����
					printf("%s?����Ȃ�͂��Ȃ�\n", name);
					Sleep(1000);
					printf("�����͉������Ȃ�����\n");
					man.get_flustration(10);
					dog.get_flustration(10);
				}
				Sleep(2000);      //�ҋ@
				amount_of_foods = 0;
			}
			else {
				printf("�H���͖�����\n");
				man.get_flustration(10);
				dog.get_flustration(10);
			}
			break;
		default://��O����
			printf("�E�E�E�E\n");
			Sleep(1000);	//�ҋ@
			printf("�����͉������Ȃ�����\n");
			man.get_flustration(10);
			dog.get_flustration(10);
			break;
		}
		Sleep(2000);

		man.get_hungry(5);
		dog.get_hungry(5);

		printf("%d���ڂ��I�����\n", days);
		printf("\n\n\n");
		Sleep(2000);      //�ҋ@
		if ((dog.medicul_check() && man.medicul_check()) == false) {
			days = 100;
			isGameOver = true;
		}

	}
	/**************************************[�Q�[����]�����܂�***********************************/
	/**************************************[�Q�[���I��]��������***********************************/
	delete foods;//�������̊J��
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
	/**************************************[�Q�[���I��]�����܂�***********************************/
}


/*
name		: is_FullWidth
argument	: *str
return value: true/false
function	: �o�C�g�����g���ĕ����񂪑S�p�����p�����f����B���p�Ȃ�false�A�S�p�Ȃ�true
*/
bool is_FullWidth(char *c) {
	std::string str = c;
	
	while (!str.empty()) {
		//�������0�Ԗڂ�1�o�C�g����(���p)���ۂ����f����
		
		if (IsDBCSLeadByte(str[0]) == 0) {
			str.erase(0, 1);
		}
		else {//�S�p�̏ꍇ
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
function	: �����R�[�h���g����1�����ڂ��S�p�����p�����f����B���p�Ȃ�false�A�S�p�Ȃ�true
*/
bool is_FullWidth2(char *str) {
	return (str[0] < 0x21 || str[0] > 0x7e) ? true : false;
}



/*
name		: is_sameName
argument	: *str,*str2
return value: true/false
function	: ��̕����񂪓������ǂ������f���A�����Ȃ�true�A�Ⴄ�Ȃ�false��Ԃ��B
*/

bool is_sameName(char *str, char *str2) {
	if (std::string(str).compare(str2) == 0) {
		printf("�������O�ł��B\n");
		return true;
	}
	else {
		//printf("�Ⴄ���O�ł��B\n");
		return false;
	}
}
