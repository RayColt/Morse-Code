#include <string>
#include "help.h"

namespace Morseform
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	public ref class Form2 : public System::Windows::Forms::Form
	{
	private:
		System::Windows::Forms::TextBox^ help_textBox;
		System::ComponentModel::Container^ components;

	public:
		Form2(void)
		{
			InitializeComponent();
		}

	protected:
		~Form2()
		{
			if (components)
			{
				delete components;
			}
		}

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Form2::typeid));
			this->help_textBox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// help_textBox
			// 
			this->help_textBox->BackColor = System::Drawing::SystemColors::Desktop;
			this->help_textBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->help_textBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->help_textBox->ForeColor = System::Drawing::SystemColors::Window;
			this->help_textBox->Location = System::Drawing::Point(12, 12);
			this->help_textBox->Multiline = true;
			this->help_textBox->Name = L"help_textBox";
			this->help_textBox->ReadOnly = true;
			this->help_textBox->Size = System::Drawing::Size(584, 370);
			this->help_textBox->TabIndex = 0;
			this->help_textBox->TabStop = false;
			this->help_textBox->Text = L"Colt\'s Morse Manual\r\n\r\n";
			// 
			// Form2
			// 
			this->BackColor = System::Drawing::SystemColors::Desktop;
			this->ClientSize = System::Drawing::Size(608, 394);
			this->Controls->Add(this->help_textBox);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximumSize = System::Drawing::Size(624, 433);
			this->MinimumSize = System::Drawing::Size(624, 433);
			this->Name = L"Form2";
			this->Opacity = 0.9;
			this->Text = L"Help";
			this->Load += gcnew System::EventHandler(this, &Form2::Form2_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		private: System::Void help_textBox_TextChanged(System::Object^ sender, System::EventArgs^ e)
		{

		}
		private: System::Void Form2_Load(System::Object^ sender, System::EventArgs^ e)
		{
			std::string helpText = ::Help::GetHelpTxt();
			System::String^ managedHelpText = gcnew System::String(helpText.c_str());
			this->help_textBox->Text = managedHelpText;
		}
	};
}
