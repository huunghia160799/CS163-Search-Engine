#ifndef HLyaout
#define HLyaout

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<Windows.h>
#include <cstdio>
#include<conio.h>
#include<time.h>
#include<string.h>
#include<string>
#include<consoleapi.h>
#include<direct.h>
#include<stdio.h>
#include<filesystem>
#include <experimental/filesystem>
#include<ctime>
#include <iomanip>
#include<amp_graphics.h>

using namespace std;
#define p system("pause")
#define ccc system("cls")
#define tc(a) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a)
void ResizeConsole(int w, int h);
void GOTOXY(int x, int y);
void tsize(int x);
void ready(char(&s)[50]);
void readHistory();
void preSearch();
bool inKeyy(char s[], string ss);
bool inKeyyy(string ss, char s[]);
void inputUName(int x, int y, char(&s)[50]);
void LoadText();
void LoadBorder();
#endif /* HLyaout */