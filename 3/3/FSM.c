#include "FSM.h"
#include <stdbool.h>
#include <ctype.h>

enum States {
	start,
	seenFirstDigit,
	seenSecondDigit,
	seenPoint,
	seenLetter,
	seenThirdDigit,
	seenFourthDigit,
	seenMinus,
	seenM,
};

bool isMathMech(char* string)
{
	enum States state = start;
	int current = 0;
	char temp;
	int i = 0;
	while (true)
	{
		char token = string[current];
		switch (state)
		{
		case start:
			if (isdigit(token))
			{
				state = seenFirstDigit;
				break;
			}
			return false;
		case seenFirstDigit:
			if (isdigit(token))
			{
				state = seenSecondDigit;
				break;
			}
			return false;
		case seenSecondDigit:
			if (token == 'B' || token == 'M' || token == 'S')
			{
				state = seenLetter;
				break;
			}
			return false;
		case seenLetter:
			if (isdigit(token))
			{
				state = seenThirdDigit;
				temp = token;
				break;
			}
			return false;
		case seenThirdDigit:
			if (isdigit(token) && token == '0' && temp == '1')
			{
				state = seenFourthDigit;
				break;
			}
			if (token == '-')
			{
				state = seenMinus;
			}
			return false;
		case seenFourthDigit:
			if (token == '-')
			{
				state = seenMinus;
			}
		case seenMinus:
			if (token == 'm')
			{
				state = seenM;
				i++;
				break;
			}
			else
				return false;
		case seenM:
			if (token == 'm' && i == 1)
			{
				i++;
				break;
			}
			else if (token == '\0' || token == '\n' && i == 2)
			{
				return true;
			}
			return false;
			current++;
		}
	}
}