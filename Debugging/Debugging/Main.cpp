// DEBUG - DE-BUG - remove bugs.
//	Yellow arrow indicates that we haven't executed this line of code. As soon as we hit F10, Shift + F11 or F5 it will execute this line of code.

// For memory access go to: Debug/Windows/Memory/Memory 1, a e.g. type &a for the address of the a variable.
// The text on the right is an ASCII representation of the memory.

// Yellow arrow means: that line will be executed next.
// Right click on the variable to change the way it is displayed (from DEC to HEX)
// Add Watch to keep track of the variable in the 'Watch 1' window
// Red variable means it got changed since the last executed line

// CODE 

#include <iostream>

int main()
{
	int a = 8;
	a++;
	const char* string = "Hello World!";

	for (int i = 0; i < 5; i++)
	{
		const char c = string[i];
		std::cout << c << std::endl;
	}

	std::cin.get();	
}