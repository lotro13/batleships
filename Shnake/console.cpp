#include "pch.h"
#include "console.h"

console::console()
{
	cls();
}


console::~console()
{
	cls();
}

void console::cls() 
{
	// Get the Win32 handle representing standard output.
	// This generally only has to be done once, so we make it static.
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	COORD topLeft = { 0, 0 };

	// std::cout uses a buffer to batch writes to the underlying console.
	// We need to flush that to the console because we're circumventing
	// std::cout entirely; after we clear the console, we don't want
	// stale buffered text to randomly be written out.
	cout.flush();

	// Figure out the current width and height of the console window
	if (!GetConsoleScreenBufferInfo(hOut, &csbi)) {
		// TODO: Handle failure!
		return;
	}
	DWORD length = csbi.dwSize.X * csbi.dwSize.Y;
	DWORD written;

	// Flood-fill the console with spaces to clear it
	FillConsoleOutputCharacter(hOut, TEXT(' '), length, topLeft, &written);

	// Reset the attributes of every character to the default.
	// This clears all background colour formatting, if any.
	FillConsoleOutputAttribute(hOut, csbi.wAttributes, length, topLeft, &written);

	// Move the cursor back to the top left for the next sequence of writes
	SetConsoleCursorPosition(hOut, topLeft);
}
/*
void console::print(char** batlefield, int width, int heigth)
{
	cls();
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < heigth; j++)
			cout << batlefield[i][j] << ' ';
		cout << endl;
	}
}*/
void console::print(char item, int x, int y) 
{
	//Prints char symbol (item) in the (x, y) position in console.
	change_console_view(x, y);
	cout << item << ' ';
}

void console::print(std::string line, int x, int y)
{
	//Prints string (line) with the start position (x, y) in console.
	change_console_view(x, y);
	cout << line;
}

void console::print(field F, int x, int y)
{
	//Prints 10x10 matrix with the start in(x, y).0
	for (int i = 0; i < 10; i++) {
		change_console_view(x, y+i);
		for (int j = 0; j < 10; j++)
			cout << F.getFieldAtPosition(i, j) << ' ';
	}
}

void console::change_console_view(int x, int y)
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
}