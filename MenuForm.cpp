#include "MenuForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

void Menu(array<String^>^ args)
{
	//https://vipeveloper.tistory.com/32
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Project4::MenuForm form;		// ���ϸ� ��ü
	Application::Run(% form);
}
