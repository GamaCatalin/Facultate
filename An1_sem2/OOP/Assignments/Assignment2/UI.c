#include "UI.h"
#include "Services.h"
#include <stdio.h>
#include <string.h>





void menu()
{
	printf("*************************************\n");
	printf("Commands: \n");
	printf("add id,name,manufacturer,quantity\n");
	printf("remove id\n");
	printf("list/list name\n");
	printf("update id,newName,newManufacturer,newQuantity\n");
	printf("undo/redo\n");
	printf("list maxQuantity\n");

	printf("exit\n");
	printf("*************************************\n");

}

void list_all() {

	char* namePointer, * manufacturerPointer;
	int id, quantity;

	int index = get_maxIndex();

	for (int i = 0; i < index; i++) {

		id = get_currentID(i);
		namePointer = get_currentName(i);
		manufacturerPointer = get_currentManufacturer(i);
		quantity = get_currentQuantity(i);



		printf("%d %s %s %d\n", id, namePointer, manufacturerPointer, quantity);

	}
}


void list_quantity(int maxQuantity) {

	char* namePointer, * manufacturerPointer;
	int id, quantity;

	int index = get_maxIndex()-1;

	for (int i = 0; i <= index; i++) {
		if (get_currentQuantity(i)<=maxQuantity) {

			id = get_currentID(i);
			namePointer = get_currentName(i);
			manufacturerPointer = get_currentManufacturer(i);
			quantity = get_currentQuantity(i);

			printf("%d %s %s %d\n", id, namePointer, manufacturerPointer, quantity);
		}

	}

}


void list_name(char name[]){
	char* namePointer, * manufacturerPointer;
	int id, quantity;
	int index = get_maxIndex()-1;
	struct Medicine* currentMedication;


	for (int i = 0; i <= index; i++) {
		
		currentMedication = get_currentElement(i);
		
		if (strcmp(get_currentName(currentMedication), name) == 0) {

			id = get_currentID(i);
			namePointer = get_currentName(i);
			manufacturerPointer = get_currentManufacturer(i);
			quantity = get_currentQuantity(i);

			printf("%d %s %s %d\n", id, namePointer, manufacturerPointer, quantity);
		}

	}
}


int main() {

	
	char temporary_command[100], delimiter_space[2] = " ", delimiter_comma[2] = ", ", name[100], newName[100], manufacturer[100], newManufacturer[100], bufferName[100], listArgument[100];
	char* split_command, * namePointer, * manufacturerPointer, * command;
	int i, j, lenght, id, quantity, newQuantity, errorChecker;


	menu();

	call_populate();
	/*
	while (1) {

		fgets(temporary_command, 100, stdin);


		if (strcmp(temporary_command, "exit\n") == 0) {

			break;

		}

		if (strcmp(temporary_command, "undo\n") == 0) {

			errorChecker = undo_caller();
			if (errorChecker == 0) {

				printf("Can't undo!\n");

			}

			continue;

		}

		if (strcmp(temporary_command, "redo\n") == 0) {

			errorChecker = redo_caller();
			if (errorChecker == 0) {

				printf("Can't redo!\n");

			}

			continue;

		}

		if (strcmp(temporary_command, "list\n") == 0) {

			list_all();

		}
		else {

			split_command = strtok(temporary_command, delimiter_space);
			
			if (strcmp(split_command, "add") == 0) {

				split_command = strtok(NULL, delimiter_comma);
				id = atoi(split_command);

				split_command = strtok(NULL, delimiter_comma);
				strcpy(name, split_command);

				split_command = strtok(NULL, delimiter_comma);
				strcpy(manufacturer, split_command);

				split_command = strtok(NULL, delimiter_comma);
				quantity = atoi(split_command);

				if (check_id(id) == 1) {

					printf("NO!\n");

				}
				else {

					call_adder(id, name, manufacturer, quantity);
				
				}
			}
			else {
				if (strcmp(split_command, "delete") == 0) {

					split_command = strtok(NULL, delimiter_comma);
					id = atoi(split_command);

					if (check_id(id) == 0) {

						printf("NO!\n");

					}
					else {

						call_deleter(id);
					
					}
				}
				else {

					if (strcmp(split_command, "list") == 0) {
						strcpy(listArgument , "\n");
						strcpy(bufferName , "\n");
						split_command = strtok(NULL, delimiter_comma);
						strcpy(bufferName, split_command);
						strncpy(listArgument, bufferName, strlen(bufferName)-1);
						if (checkNumber(listArgument) == 0) {
							
							list_name(listArgument);
							
						}
						if (checkNumber(listArgument) == 1) {

							list_quantity(atoi(listArgument));

						}
						

					}
					else {

						if (strcmp(split_command, "update") == 0) {

							split_command = strtok(NULL, delimiter_comma);
							id = atoi(split_command);

							split_command = strtok(NULL, delimiter_comma);
							strcpy(newName, split_command);

							split_command = strtok(NULL, delimiter_comma);
							strcpy(newManufacturer, split_command);

							split_command = strtok(NULL, delimiter_comma);
							newQuantity = atoi(split_command);

							if (check_id(id) == 0) {

								printf("NO!\n");

							}
							else {

								call_updater(id, newName, newManufacturer, newQuantity);

							}
						}
						else {

							printf("Invalid command!\n");

						}
					}
				}
			}
		}
	}
	return 0;
	*/
repository.tempElement = get_currentElement(1);

printf("%s", get_currentName[repository.tempElement]);
}