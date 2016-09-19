#pragma once
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>

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
	private: System::Windows::Forms::Label^  label1;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(236, 240);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(103, 62);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Click";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &mainView::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(253, 147);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(41, 12);
			this->label1->TabIndex = 1;
			this->label1->Text = L"label1";
			this->label1->Click += gcnew System::EventHandler(this, &mainView::label1_Click);
			// 
			// mainView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(626, 365);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"mainView";
			this->RightToLeftLayout = true;
			this->Text = L"Metro";
			this->Load += gcnew System::EventHandler(this, &mainView::mainView_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void mainView_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		int k = rand();
		this->label1->Text = Convert::ToString(k);

	}
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	};
}
