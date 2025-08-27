#pragma once
#include<iostream>
#include<algorithm>
#include"Item.h"

using namespace std; 

void compareItemsByPrice(const Item& a, const Item& b);

template <typename T>
class Inventory
{
public:
	Inventory(int capacity) :capacity(capacity)
	{
		if (capacity == 0) {
			this->capacity = 1;
		}

		pitems = new T[this->capacity];
		size = -1;

	}
	Inventory(const Inventory<T>& other) {
		capacity = other.capacity;
		size = other.size;
		pitems = new T[capacity];
		for (int i = 0; i < size; ++i) {
			pitems[i] = other.pitems[i];
		}
		cout << "�κ��丮 ���� �Ϸ�" << endl;
	}

	void Assign(const Inventory<T>& other) {
		if (other.size > this->size) {
			capacity = other.capacity;
			size = other.size;
			delete[] pitems;
			pitems = nullptr;

			pitems = new T[other.capacity];
			for (int i = 0; i <= other.size; ++i) {
				pitems[i] = other.pitems[i];
			}
		}
		else {
			for (int i = 0; i <= other.size; ++i) {
				pitems[i] = other.pitems[i];
			}
		}
		
	}

	~Inventory()
	{			
		
		delete[] pitems;
		pitems = nullptr;
	}

	void AddItem(const T& item) {
		if (size < capacity-1) {
			++size;
			pitems[size] = item;
		}
		else {		
			Resize();
			++size;
			pitems[size] = item;
		}
	}

	void Resize() {
		capacity *= 2;
		T* newPitems = new T[capacity];

		for (int i = 0; i <= size; ++i) {
			newPitems[i] = pitems[i];
		}

		delete[] pitems;
		pitems = newPitems;		

	}

	void RemoveLastItem() {
		if (size >=0)
			--size;
		else
			cout << "�κ��� ������ϴ�" << endl;

	}
	int GetSize() const {
		return size;
	}
	int GetCapacity() const {
		return capacity;
	}
	void PrintAllItems() const {
		if (size == -1) {
			cout << "�κ��� ������ϴ�" << endl;
			return;
		}
		for (int i = 0; i <= size; i++) {
			pitems[i].PrintInfo();
		}
	}
		
private:
	int capacity;
	int size;

	T* pitems;

	//pitems = new T[]�ϸ� �޸� ��ü�Ҷ� �� �ε������� =nullptr�����൵ �Ǵ°� delete[] pitems�� ���ָ� ��?
	//sort�� �ȵ�
};

