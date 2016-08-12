#pragma once

class Item{
	public:
		static Item* mItems[4096];
		virtual int getAttackDamage();
};