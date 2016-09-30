#define DEBUG 1
#undef DEBUG
#include<stdio.h>
#include<windows.h>
#include "mainView.h"

#ifdef DEBUG
#include "subway.h"
using namespace std;
#endif // DEBUG

using namespace Metro;

#ifndef DEBUG
int main(int argc, char** argv) {
#endif // !DEBUG

#ifdef DEBUG
	int main() {
#endif // DEBUG

		subway::subway * tt;
		try {
			tt = new subway::subway(std::string("./beijing-subway.txt"));
		}
		catch (subway::Exc* E) {
			exit(1);
		}

#ifndef DEBUG
		if (argc == 1 || argc == 2 && !strcmp(argv[1], "-g")) {
			Application::EnableVisualStyles();
			Application::Run(gcnew mainView(tt));
			HWND hwnd;
			hwnd = FindWindow(L"ConsoleWindowClass", NULL);
			if (hwnd) {
				ShowOwnedPopups(hwnd, SW_HIDE);
				ShowWindow(hwnd, SW_HIDE);
			}
		}
		else {
			int flag = 0;
			if (argc == 4 && !strcmp(argv[1], "-b")) {
				std::string s(argv[2]);
				std::string t(argv[3]);
				if (!tt->do_b(s, t)) {
					flag = 1;
				}
			}
			else if (argc == 4 && !strcmp(argv[1], "-c")) {
				std::string s(argv[2]);
				std::string t(argv[3]);
				if (!tt->do_c(s, t)) {
					flag = 1;
				}
			}
			else if (argc == 3 && !strcmp(argv[1], "-a")) {
				std::string s(argv[2]);
				if (!tt->do_a(s)) {
					flag = 1;
				}
			}
			else printf("Invalid Input.\n");
			if (flag) {
				printf("stations: %d, transfer: %d\n", tt->getPlanNums().first, tt->getPlanNums().second);
				for (int i = 0; i < tt->getCount(); ++i) {
					printf("%s\n", tt->getStep(i).c_str());
				}
			}
		}
#endif // !DEBUG

#ifdef DEBUG
		tt->do_a("东直门");
		//tt->do_c(std::string("知春路"), std::string("沙河"));
#endif //DEBUG
		return 0;
}