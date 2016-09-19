#include "mainView.h"
using namespace Metro;


int __stdcall wWinMain() {
	Application::EnableVisualStyles();
	Application::Run(gcnew mainView());
	return 0;
}