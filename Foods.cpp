#include"Foods.h"

Foods::Foods(int amount) {
	m_stock = amount;
}


/*
name		: show_stock
argument	: nothing
return value: m_stock
function	: ���݂̍݌ɂ̗ʂ�\�����A�݌ɂ̗ʂ�Ԃ�
*/
int Foods::show_stock() {
	printf("���݂̍݌ɂ�%d�ł�",m_stock);
	return m_stock;
}

/*
name		: eat_foods
argument	: amount
return value: nothing
function	: ����amount�̕������݌�m_stock������A�������amount��Ԃ��B
			�@�݌ɂ����������傫���ꍇ�́A�����O�̒l��Ԃ��B
*/
int Foods::eat_foods(int amount) {
	int before_stock = m_stock;

	m_stock = m_stock - amount;

	if (m_stock <= 0) {
		return before_stock;
	}
	return amount;
}

bool Foods::check_stock() {
	return (m_stock >= 0) ? true : false;
}