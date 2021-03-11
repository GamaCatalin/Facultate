#include "UndoController.h"

UndoController::UndoController()
{
	this->currentAction = 0;
	this->highestAction = 0;
	this->duringUndo = false;
}

Action UndoController::undo()
{
	Action action;

	if (this->currentAction <= 0) {
		throw ExceptionNoUndo("Can't undo!");
	}

	this->currentAction--;

	action.actionName = this->actions[this->currentAction].actionName;
	action.undoValue = this->actions[this->currentAction].undoValue;
	action.redoValue = this->actions[this->currentAction].redoValue;

	return action;
}

Action UndoController::redo()
{
	Action action;

	if (this->currentAction >= this->highestAction) {
		throw ExceptionNoRedo("Can't Redo!");
	}

	

	action.actionName = this->actions[this->currentAction].actionName;
	action.undoValue = this->actions[this->currentAction].undoValue;
	action.redoValue = this->actions[this->currentAction].redoValue;

	this->currentAction++;
	
	return action;
}

void UndoController::save(std::string action, TElem undoInput,TElem redoInput)
{
	Action saveAction;
	
	saveAction.actionName = action;
	saveAction.undoValue = undoInput;
	saveAction.redoValue = redoInput;

	if (this->currentAction < this->actions.size()) {
		std::vector<Action> saveArray;
		for (int i = 0; i <= this->currentAction; i++) {
			saveArray.push_back(this->actions[i]);
		}
		this->actions.clear();
		this->actions = saveArray;
		this->highestAction = this->currentAction;
	}
	else {
		this->actions.push_back(saveAction);
		this->currentAction++;
		this->highestAction++;
	}
}
