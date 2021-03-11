#include "Repository.h"

void addElement(struct Medicine* element)
{
	repository.medications[repository.size++] = element;
}

void removeElement(int position)
{
	for (int i = position; i < repository.size; i++) {
		repository.medications[i] = repository.medications[i + 1];
	}
	repository.size--;
}

void updateMedicine(int position,struct Medicine* element)
{
	repository.medications[position] = element;
}


struct Medicine* getElement(int position)
{
	return repository.medications[position];
}


void updateMemory()
{

}

void undo()
{
}

void redo()
{
}
