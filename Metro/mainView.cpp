#define DEBUG 1
#undef DEBUG
#include<stdio.h>
#include<windows.h>
#include<TCHAR.h>
#include "mainView.h"

extern int __argc;
extern TCHAR** __targv;

#ifdef DEBUG
#include "subway.h"
#endif // DEBUG

using namespace Metro;

#ifdef DEBUG
using namespace std;
#endif // DEBUG

//typedef HWND(WINAPI *PROCGETCONSOLEWINDOW)();
//PROCGETCONSOLEWINDOW GetConsoleWindow;

#ifndef DEBUG
int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow) {
//int __stdcall wWinMain() {
#endif // !DEBUG

#ifdef DEBUG
int main() {
#endif // DEBUG

	subway::subway * tt = new subway::subway(std::string("./beijing-subway.txt"));
#ifndef DEBUG
	if (__argc == 2 && std::wstring(__targv[1]) == std::wstring(L"-g")) {
		Application::EnableVisualStyles();
		Application::Run(gcnew mainView(tt));
	}
	else {		
		AllocConsole();
		//HMODULE hKernel32 = GetModuleHandle(L"kernel32");
		//GetConsoleWindow = (PROCGETCONSOLEWINDOW)GetProcAddress(hKernel32, "GetConsoleWindow");
		//HWND cmd = GetConsoleWindow();
		//tt->do_c(std::string("知春路"), std::string("沙河"));
		if (__argc == 4 && std::wstring(__targv[1]) == std::wstring(L"-b")) {
			std::wstring s(__targv[2]);
			std::wstring t(__targv[3]);
			printf("-b %s %s\n",s.c_str(), t.c_str());
		}
		else if (__argc == 4 && std::wstring(__targv[1]) == std::wstring(L"-c")) {
			std::wstring s(__targv[2]);
			std::wstring t(__targv[3]);
			printf("-c %s %s\n", s.c_str(), t.c_str());
		}
		else printf("Invalid Input.\n");
		}
#endif // !DEBUG

#ifdef DEBUG
	tt->do_c(std::string("知春路"),std::string("沙河"));
#endif //DEBUG
	return 0;
}