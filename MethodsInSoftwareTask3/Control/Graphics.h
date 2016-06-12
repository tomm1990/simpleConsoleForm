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


class Graphics
{
public:
	Graphics(DWORD stdHandle = STD_OUTPUT_HANDLE);
	void clearScreen() const;
	void moveTo(int x, int y)const ;
	void setBackground(Color color = Color::Black);
	void setForeground(Color color = Color::White);
	void write(const string s) const;
	void write(const int x, const int y, const string s)const;
	void write(const wstring s)const;
	void write(const int x, const int y, const wstring s)const;
	void setCursorVisibility(bool isVisible) const ;
	void updateConsoleAttributes();

private:
	HANDLE _console;
	Color _background, _foreground;

};

bool isInside(int x, int y, int left, int top, int width, int height);
