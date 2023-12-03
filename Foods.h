#ifndef __FOODS_H__
#define __FOODS_H__
#include<stdio.h>
class Foods {
	public :

		Foods(int amount);

		int show_stock();		//ç›å…ÇämîFÇ∑ÇÈ
		int eat_foods(int amount);
		bool check_stock();
	private:
		int m_stock;			//ç›å…


};

#endif

