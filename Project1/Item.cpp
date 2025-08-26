#include "Item.h"

Item::Item(string name, int price)
	:name(name),price(price)
{
}

Item::~Item()
{
}

void Item::PrintInfo() const
{
	cout << "[�̸�: " << name << ", ����: " << price << "g]" << endl;
}

int Item::GetPrice() const
{
	return price;
}
