#include <string>

namespace Morseform
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	public ref class Form3 : public System::Windows::Forms::Form
	{
	private:
		System::ComponentModel::Container^ components;
		System::Windows::Forms::TextBox^ textBox1;
		System::Windows::Forms::TextBox^ textBox3;
		System::Windows::Forms::TextBox^ textBox2;
		System::Windows::Forms::Label^ label1;

	public:
		Form3(void)
		{
			InitializeComponent();
		}

	protected:
		~Form3()
		{
			if (components)
			{
				delete components;
			}
		}

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Form3::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(12, 12);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(10, 41);
			this->textBox1->TabIndex = 0;
			// 
			// textBox3
			// 
			this->textBox3->Enabled = false;
			this->textBox3->Location = System::Drawing::Point(95, 93);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(12, 11);
			this->textBox3->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->label1->Location = System::Drawing::Point(18, 158);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(184, 20);
			this->label1->TabIndex = 3;
			this->label1->Text = L"COLT\'S MORSE 2022";
			// 
			// textBox2
			// 
			this->textBox2->Enabled = false;
			this->textBox2->Location = System::Drawing::Point(245, 105);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(10, 41);
			this->textBox2->TabIndex = 4;
			// 
			// Form3
			// 
			this->BackColor = System::Drawing::SystemColors::Desktop;
			this->ClientSize = System::Drawing::Size(266, 183);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = gcnew System::Drawing::Icon(L"D:\\Repos\\Morse Code\\Morse Code\\app.ico");
			this->MaximumSize = System::Drawing::Size(282, 222);
			this->MinimumSize = System::Drawing::Size(282, 222);
			this->Name = L"Form3";
			this->Opacity = 0.9;
			this->Text = L"About";
			this->Load += gcnew System::EventHandler(this, &Form3::Form3_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	private: System::Void Form3_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
