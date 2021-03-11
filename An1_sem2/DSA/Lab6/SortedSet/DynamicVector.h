#pragma once


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

	void add(const templateObject& element);
	void remove(int position);
	void update(int position, const templateObject& element);
	int lenght() const;
	templateObject pop_back();
	templateObject lastElement();


	templateObject get_element(int position);
};


template <typename templateObject>
DynamicVector<templateObject>::DynamicVector(int capacity)
{
	this->capacity = capacity;
	this->size = 0;
	this->elements = new templateObject[this->capacity];
}

template <typename templateObject>
DynamicVector<templateObject>::DynamicVector(const DynamicVector& vector)
{
	this->capacity = vector.capacity;
	this->size = vector.size;

	this->elements = new templateObject[this->capacity];
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

	this->elements = new templateObject[this->capacity];
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
void DynamicVector<templateObject>::add(const templateObject& element)
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
void DynamicVector<templateObject>::update(int position, const templateObject& element)
{

	this->elements[position] = element;

}

template <typename templateObject>
int DynamicVector<templateObject>::lenght() const
{
	return this->size;
}

template<typename templateObject>
inline templateObject DynamicVector<templateObject>::pop_back()
{
	templateObject elem = this->elements[--this->size];
	return elem;
}

template<typename templateObject>
inline templateObject DynamicVector<templateObject>::lastElement()
{
	return this->elements[this->size-1];
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

	templateObject* auxiliary = new templateObject[this->capacity];
	for (int i = 0; i < this->size; i++) {
		auxiliary[i] = this->elements[i];
	}

	delete[] this->elements;
	this->elements = auxiliary;
}
