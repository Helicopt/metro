#pragma once
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>

#include "subway.h"
//using namespace subway;

namespace Metro {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for mainView
	/// </summary>
	public ref class mainView : public System::Windows::Forms::Form
	{
	public:
		mainView(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~mainView()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::ListBox^  listBox1;

	private: subway::subway * sd;
	private: subway::planMode pm;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(44, 213);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(103, 31);
			this->button1->TabIndex = 0;
			this->button1->Text = L"查询";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &mainView::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(95, 122);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(98, 21);
			this->textBox1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(42, 125);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(29, 12);
			this->label1->TabIndex = 2;
			this->label1->Text = L"起点";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(42, 172);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(29, 12);
			this->label2->TabIndex = 4;
			this->label2->Text = L"终点";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(95, 169);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(98, 21);
			this->textBox2->TabIndex = 3;
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 12;
			this->listBox1->Location = System::Drawing::Point(253, 22);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(318, 316);
			this->listBox1->TabIndex = 5;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(44, 97);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(59, 16);
			this->radioButton1->TabIndex = 6;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"少换乘";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &mainView::radioButton1_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(134, 97);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(59, 16);
			this->radioButton2->TabIndex = 7;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"少停站";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &mainView::radioButton2_CheckedChanged);
			// 
			// mainView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(626, 365);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"mainView";
			this->RightToLeftLayout = true;
			this->Text = L"Metro";
			this->Load += gcnew System::EventHandler(this, &mainView::mainView_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: static std::string * stdString(System::String ^ str) {
		return new std::string((char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str));
	}
	public: static System::String^ SysString(const char * ch) {
		return System::Runtime::InteropServices::Marshal::PtrToStringAnsi((IntPtr)(char*)ch);
	}
	private: System::Void mainView_Load(System::Object^  sender, System::EventArgs^  e) {
		this->sd = new subway::subway(std::string("./beijing-subway.txt"));
		this->textBox1->Text = "知春路";
		this->textBox2->Text = "沙河";
		this->pm = subway::pm_Short;
		this->radioButton2->Checked = true;
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		System::String^ st1 = this->textBox1->Text;
		System::String^ st2 = this->textBox2->Text;
		std::string *s = this->stdString(st1);
		std::string *t = this->stdString(st2);
		this->listBox1->Items->Clear();
		this->button1->Enabled = false;
		int flag;
		if (this->pm == subway::pm_convi) flag = this->sd->do_c(*s, *t);
		else if (this->pm == subway::pm_Short) flag = this->sd->do_b(*s, *t);
		if (flag == 0) {
			this->listBox1->Items->Add("站数：" + Convert::ToString(this->sd->getPlanNums().first) + "， 换乘次数：" + Convert::ToString(this->sd->getPlanNums().second));
			for (int i = 0; i < this->sd->getCount(); ++i) {
				this->listBox1->Items->Add(this->SysString(this->sd->getStep(i).c_str()));
			}
		}
		else {
			this->listBox1->Items->Add("找不到站点");
		}
		this->button1->Enabled = true;
	}
	private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		this->pm = subway::pm_convi;
	}
	private: System::Void radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		this->pm = subway::pm_Short;
	}
	};
}
