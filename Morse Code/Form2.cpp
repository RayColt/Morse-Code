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

	public ref class Form2 : public System::Windows::Forms::Form
	{
	private:
		System::Windows::Forms::TextBox^ help_textBox;
		System::ComponentModel::Container^ components;
		System::String^ helptxt;

	public:
		Form2(void)
		{
			InitializeComponent();
			helptxt = "Colt's Morse Manual\r\n";
			helptxt += "Morse Dictionary, chars(url save) and spaces, lower case will be made upper case:\r\n";
			helptxt += "ABC DEFGHIJKLMNOPQRSTUVWXYZ 12 34567 890 !$ ' \" (), . _ - / : ; = ? @ \r\n\r\n";
			helptxt += "Select Modus for encoding or decoding:\r\n";
			helptxt += "[. - space] Morse Normal - with 2 whitespaces between words\r\n";
			helptxt += "[0 1 space] Binary Morse - morse with 1's and 0's and 2 whitespaces between words\r\n";
			helptxt += "[2E 2D 20] HeX Morse - morse with 2E's(.) and 2D's(-) and 20's(spaces)\r\n";
			helptxt += "[30 31 20] HeX Binary - morse with 2E's(.) and 2D's(-) and 20's(spaces)\r\n\r\n";
			helptxt += "Select modus for encoding to sound :\r\n";
			helptxt += "[Morse to Wav] Windows Wav Stereo - with local sound file\r\n";
			helptxt += "[Morse to Wav] Windows Wav Mono - with local sound file\r\n\r\n";
			helptxt += "Sound settings:\r\n";
			helptxt += "Tone(Hz), tone frequency in Herz, allowed between 20 Hz - 8000 Hz\r\n";
			helptxt += "WPM, words per minute, allowed between 0 wpm - 50 wpm\r\n";
			helptxt += "SPS, samples per second, allowed between 8000 Hz - 48000 Hz\r\n\r\n";
			helptxt += "A maximum of 5000 characters is allowed.\r\n\r\n";
			helptxt += "For creating sound files a maximum of 750 chars is advised, bigger text might lead to a long term 'not responding'.";
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
			this->Icon = gcnew System::Drawing::Icon(L"D:\\Repos\\Morse Code\\Morse Code\\app.ico");
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
			this->help_textBox->Text = helptxt;
		}
	};
}
