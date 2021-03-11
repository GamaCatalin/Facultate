#pragma once
#include "Domain.h"

struct Repository {
	struct Medicine medications[1000];
	int size;
};

struct MemoryController {
	char lastCommand[100];
}memory[1000];

struct Repository repository;

void addElement(struct Medicine* element);
void removeElement(int position);
void updateMedicine(int position, struct Medicine* element);

struct Medicine* getElement(int position);

void updateMemory();

void undo();

void redo();