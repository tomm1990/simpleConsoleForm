#pragma once
#include <string>
#include <Windows.h>

using namespace std;

enum class Color
{
	Black,
	Blue,
	Green,
	Red,
	Cyan,
	Purple,
	Orange,
	White
};

class Graphics{
public:
	Graphics(DWORD stdHandle = STD_OUTPUT_HANDLE);
	void clearScreen() const;
	void moveTo(const int, const int) const ;
	void setBackground(const Color color = Color::Black);
	void setForeground(const Color color = Color::White);
	void write(const string) const;
	void write(const int, const int, const string) const;
	void write(const wstring) const;
	void write(const int, const int, const wstring) const;
	void setCursorVisibility(const bool) ;
	void updateConsoleAttributes() const;
	bool getCursorVisbility() const { return cursorVisbility; };
private:
	bool cursorVisbility;
	HANDLE _console;
	Color _background, _foreground;
};

bool isInside(int, int, const int, const int, const int, const int);