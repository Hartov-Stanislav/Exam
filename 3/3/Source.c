#include "FSM.h"
#include <stdbool.h>
#include <string.h>

bool testsSucsess()
{
	return (isMathMech("17M10-mm") && isMathMech("20B10-mm"));
}

bool testsFailed
{
	return (!isMathMech("6214871") && !isMathMech("100M6749-mm"));
}

int main()
{
	if (!testsSuscess() && !testsFailed())
	{
		printf("Tests failed");
	}
	char string[MAX] = "";
	printf("Please enter group\n");
	gets_s(string, MAX);
	if (isMathMech(string))
	{
		printf("It is name of group of MM");
	}
	else
	{
		printf("It isn't group of MM");
	}
	return 0;
}