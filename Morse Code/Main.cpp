#include "Form1.cpp"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(int argc, char* argv[]) 
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew Morseform::Form1()); 
	return 0;
}