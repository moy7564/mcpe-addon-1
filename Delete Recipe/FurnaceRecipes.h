#pragma once

class ItemInstance;
class FurnaceRecipes{
	public:
		static FurnaceRecipes *getInstance();
		void clearFurnaceRecipes();
};