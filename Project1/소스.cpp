#include<iostream>
#include"Inventory.h"
#include"Item.h"
#include<algorithm>

using namespace std;

int main() {
	Inventory<Item> inven(0);
	inven.AddItem(Item("tset", 50));
	inven.AddItem(Item("test2", 30));
	inven.Resize();
	inven.AddItem(Item("test2", 10));

	inven.PrintAllItems();
	Inventory<Item> inven2(0);
	inven2.AddItem(Item("tset", 10));
	inven2.AddItem(Item("test2", 20));	
	inven2.AddItem(Item("test2", 30));
	inven2.AddItem(Item("test2", 800));
	inven2.AddItem(Item("test2", 10));

	inven.Assign(inven2);

	inven2.RemoveLastItem();
	inven2.RemoveLastItem();
	inven2.RemoveLastItem();
	inven2.RemoveLastItem();
	inven2.RemoveLastItem();
	inven2.RemoveLastItem();

	inven2.AddItem(Item("tset", 1));
	inven2.AddItem(Item("test2", 2));
	inven2.AddItem(Item("test2", 3));
	inven2.AddItem(Item("test2", 8));
	inven2.AddItem(Item("test2", 1));

	cout << "000000000000000000000" << endl;
	inven2.PrintAllItems();
	inven.AddItem(Item("test2", 30));

	cout << "000000000000000000000" << endl;
	inven2.PrintAllItems();
	return 0;
}

