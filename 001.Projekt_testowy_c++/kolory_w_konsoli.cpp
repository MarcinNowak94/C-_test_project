#include "stdafx.h"
#include "second.h"

void kolory_w_konsoli()
{
	HANDLE hStdout;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	cls(hStdout);
	const WORD colors[] =
	{
		0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
		0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
	};

	HANDLE hstdin = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD   index = 0;

	// Remember how things were when we started
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout, &csbi);

	// Tell the user how to stop
	SetConsoleTextAttribute(hstdout, 0xEC);
	std::cout << "Press any key to quit.\n";
	// Draw pretty colors until the user presses any key
	for (int i=0;i<13;++i)
    // orygina³: while (WaitForSingleObject(hstdin, 100) == WAIT_TIMEOUT)
	{
		SetConsoleTextAttribute(hstdout, colors[index]);
		std::cout << "\t\t\t\t Hello World \t\t\t\t" << index << std::endl;
		if (++index > sizeof(colors) / sizeof(colors[0]))
			index = 0;
	};
	FlushConsoleInputBuffer(hstdin);

	// Keep users happy
	SetConsoleTextAttribute(hstdout, csbi.wAttributes);
	std::cout << "Wcisnij dowolny klawisz by powrocic\n";
	_getch();
	return;

	/*
	 Oh, yeah, colors are bit-encoded thus:

	bit 1 - foreground green
	bit 2 - foreground red
	bit 3 - foreground intensity

	bit 4 - background blue
	bit 5 - background green
	bit 6 - background red
	bit 7 - background intensity
	*/

	/*
	krótsza implementacja
	SetConsoleTextAttribute( GetStdHandle( STD_INPUT_HANDLE ), 0x5B )
	*/
}