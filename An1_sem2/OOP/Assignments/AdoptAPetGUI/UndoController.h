#pragma once
#include <vector>
#include <string>
#include "Exception.h"
#include "Repository.h"

struct Action {
	std::string actionName;
	TElem undoValue;
	TElem redoValue;
};


class UndoController
{
private:
	std::vector<Action> actions;
	int currentAction;
	int highestAction;
public:
	bool duringUndo;
	UndoController();

	Action undo();
	Action redo();
	void save(std::string action,TElem undoInput,TElem redoInput);
};

