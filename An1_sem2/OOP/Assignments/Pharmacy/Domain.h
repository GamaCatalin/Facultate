#pragma once
#include <string>
#include <stdlib.h>

typedef struct Medicine {
	int id;
	int quantity;
	char  manufacturer[1000];
	char name[1000];
};

typedef struct Medicine Medicine;
