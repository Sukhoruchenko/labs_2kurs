#include "MyForm.h"
#include "Array.h"

using namespace std;
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Massiv::MyForm form;
	Application::Run(%form);
}