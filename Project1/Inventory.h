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
		cout << "인벤토리 복사 완료" << endl;
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
			cout << "인벤이 비었습니다" << endl;

	}
	int GetSize() const {
		return size;
	}
	int GetCapacity() const {
		return capacity;
	}
	void PrintAllItems() const {
		if (size == -1) {
			cout << "인벤이 비었습니다" << endl;
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

	//pitems = new T[]하면 메모리 해체할때 각 인덱스마다 =nullptr안해줘도 되는가 delete[] pitems만 해주면 끝?
	//sort가 안됨
};

