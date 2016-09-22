#define DEBUG 1
#undef DEBUG
#include<stdio.h>
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

	subway::subway * tt = new subway::subway(std::string("./beijing-subway.txt"));
#ifndef DEBUG
	if (argc == 2 && !strcmp(argv[1], "-g")) {
		Application::EnableVisualStyles();
		Application::Run(gcnew mainView(tt));
	}
	else {
		int flag = 0;
		if (argc == 4 && !strcmp(argv[1],"-b")) {
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
		else printf("Invalid Input.\n");
		if (flag) {
			printf("stations: %d, transfer: %d\n",tt->getPlanNums().first, tt->getPlanNums().second);
			for (int i = 0; i < tt->getCount(); ++i) {
				printf("%s\n",tt->getStep(i).c_str());
			}
		}
	}
#endif // !DEBUG

#ifdef DEBUG
	tt->do_c(std::string("Öª´ºÂ·"),std::string("É³ºÓ"));
#endif //DEBUG
	return 0;
}