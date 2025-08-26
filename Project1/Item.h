#pragma once

#include<iostream>
using namespace std;

class Item
{
public:
	Item() {};
	Item(string name,int price);
	~Item();

	void PrintInfo() const;
	int GetPrice() const;

private:
	string name;
	int price;
};


