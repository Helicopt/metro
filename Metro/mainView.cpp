#define DEBUG 1
#undef DEBUG

#include "mainView.h"

#ifdef DEBUG
#include "subway.h"
#endif // DEBUG

using namespace Metro;

#ifdef DEBUG
using namespace std;
#endif // DEBUG

#ifndef DEBUG
int __stdcall wWinMain() {
#endif // !DEBUG

#ifdef DEBUG
int main() {
#endif // DEBUG

#ifndef DEBUG
	Application::EnableVisualStyles();
	Application::Run(gcnew mainView());
#endif // !DEBUG

#ifdef DEBUG
	subway::subway * tt = new subway::subway(std::string("./beijing-subway.txt"));
	tt->do_c(std::string("Öª´ºÂ·"),std::string("É³ºÓ"));
#endif //DEBUG
	return 0;
}