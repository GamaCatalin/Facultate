#pragma once
#include "Pet.h"
#include <string>
#include <iostream>

typedef Pet TElem;

template <typename templateObject>
class DynamicVector
{
private:
	int size;
	int capacity;

	templateObject* elements;
	void resize();
public:
	DynamicVector(int capacity = 10);
	DynamicVector(const DynamicVector& vector);
	const DynamicVector& operator=(const DynamicVector& vector);
	~DynamicVector();
	
	void add(TElem element);
	void remove(int position);
	void update(int position, TElem element);
	int lenght();



	templateObject get_element(int position);
};


template <typename templateObject>
DynamicVector<templateObject>::DynamicVector(int capacity)
{
	this->capacity = capacity;
	this->size = 0;
	this->elements = new TElem[this->capacity];
}

template <typename templateObject>
DynamicVector<templateObject>::DynamicVector(const DynamicVector& vector)
{
	this->capacity = vector.capacity;
	this->size = vector.size;

	this->elements = new TElem[this->capacity];
	for (int i = 0; i < this->size; i++) {
		this->elements[i] = vector.elements[i];
	}
}

template <typename templateObject>
const DynamicVector<templateObject>& DynamicVector<templateObject>::operator=(const DynamicVector<templateObject>& vector)
{
	if (this == &vector) {
		return *this;
	}
	this->capacity = vector.capacity;
	this->size = vector.size;

	delete[] this->elements;

	this->elements = new TElem[this->capacity];
	for (int i = 0; i < this->size; i++) {
		this->elements[i] = vector.elements[i];
	}

	return *this;
}

template <typename templateObject>
DynamicVector<templateObject>::~DynamicVector()
{
	delete[] this->elements;
}

template <typename templateObject>
void DynamicVector<templateObject>::add(TElem element)
{

	if (this->size == this->capacity) {
		this->resize();
	}
	this->elements[this->size++] = element;
}

template <typename templateObject>
void DynamicVector<templateObject>::remove(int position)
{
	for (int i = position; i < this->size; i++) {
		this->elements[i] = this->elements[i + 1];
	}
	this->size--;
}

template <typename templateObject>
void DynamicVector<templateObject>::update(int position, TElem element)
{

	this->elements[position] = element;

}

template <typename templateObject>
int DynamicVector<templateObject>::lenght()
{
	return this->size;
}


template <typename templateObject>
templateObject DynamicVector<templateObject>::get_element(int position)
{
	return this->elements[position];
}


template <typename templateObject>
void DynamicVector<templateObject>::resize()
{
	this->capacity *= 2;

	TElem* auxiliary = new TElem[this->capacity];
	for (int i = 0; i < this->size; i++) {
		auxiliary[i] = this->elements[i];
	}

	delete[] this->elements;
	this->elements = auxiliary;
}
