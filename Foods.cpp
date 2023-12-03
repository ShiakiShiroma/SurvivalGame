#include"Foods.h"

Foods::Foods(int amount) {
	m_stock = amount;
}


/*
name		: show_stock
argument	: nothing
return value: m_stock
function	: 現在の在庫の量を表示し、在庫の量を返す
*/
int Foods::show_stock() {
	printf("現在の在庫は%dです",m_stock);
	return m_stock;
}

/*
name		: eat_foods
argument	: amount
return value: nothing
function	: 引数amountの分だけ在庫m_stockを消費し、消費した分amountを返す。
			　在庫よりも引数が大きい場合は、消費する前の値を返す。
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