#include "MenuForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

void Menu(array<String^>^ args)
{
	//https://vipeveloper.tistory.com/32
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Project4::MenuForm form;		// 파일명 교체
	Application::Run(% form);
}
