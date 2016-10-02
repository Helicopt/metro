#define DEBUG 1
//#undef DEBUG
//#define _AFXDLL
#include<stdio.h>
#include<windows.h>
//#include <afx.h>
#include <direct.h>
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
		subway::swList *mps;
		try {
			 mps = new subway::swList("./data");
			 if (mps->size() == 0) {
				 throw new subway::Exc("Data not found.");
			 }
		}
		catch (subway::Exc *e) {
			fprintf_s(stderr, "%s\n", e->info.c_str());
			//printf("Press any key to continue.");
			system("PAUSE");
			//getch();
			exit(1);
		}
		
		/*CFileFind dir;
		std::string strFilePath("E:\\workspace\\VS\Metro\\Metro\\data\\");
		char * m_szOldDir = (char*)malloc(512);
		getcwd(m_szOldDir, MAX_PATH); // 保存遍历前的起始目录
		puts(m_szOldDir);
		if (chdir(strFilePath.c_str()) == -1) {// 进入指定目录 
			printf("Data not found.");
			system("pause");
			exit(1);
		}
		bool ret = dir.FindFile(L"*.*");
		while (ret) {
			ret = dir.FindNextFileW();
			if (dir.IsDirectory() && !dir.IsDots()) {
				CString dp=dir.GetFilePath();
				CString dn = dir.GetFileName();
				if (GetFileAttributes(dp + dn + "/" + dn + "-subway.txt") != 0xFFFFFFFF && 
					GetFileAttributes(dp + dn + "/" + dn + "-subway.png") != 0xFFFFFFFF) {
					subway::subway * tt;
					try {
						std::string linm((LPCSTR)dn.GetBuffer());
						dn.ReleaseBuffer();
						tt = new subway::subway(linm, std::string("./data/") + linm + "/" + linm + "-subway.txt", std::string("./data/") + linm + "/" + linm + "-subway.png");
					}
					catch (subway::Exc* E) {
						exit(1);
					}
					mps[cnt++] = tt;
				}
			}
		}

		chdir(m_szOldDir);*/

		//Load Map List
		subway::subway * tt;
		tt = (*mps)[0];


#ifndef DEBUG
		if (argc == 1 || argc == 2 && !strcmp(argv[1], "-g")) {
			Application::EnableVisualStyles();
			Application::Run(gcnew mainView(mps));
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
		delete tt;
		//tt->do_a("东直门");
		//tt->do_c(std::string("知春路"), std::string("沙河"));
#endif //DEBUG
		return 0;
}