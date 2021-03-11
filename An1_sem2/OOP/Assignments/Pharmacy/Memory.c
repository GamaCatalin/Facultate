#include "Memory.h"

void defineMemoryArray(struct Medicine** array)
{
	*array = (struct Medicine*)malloc(10 * sizeof (struct Medicine*));
}