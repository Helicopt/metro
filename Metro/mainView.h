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
		mainView(subway::subway *subw)
		{
			this->sd = subw;
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
	private: System::Drawing::Bitmap ^ bm;
	private: Graphics^ gh;
	private: int pbW, pbH;

	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  设置为起点ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  设置为终点ToolStripMenuItem;



	private: System::ComponentModel::IContainer^  components;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(mainView::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->设置为起点ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->设置为终点ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->contextMenuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 220);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(103, 31);
			this->button1->TabIndex = 0;
			this->button1->Text = L"查询";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &mainView::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(63, 129);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(98, 21);
			this->textBox1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(10, 132);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(29, 12);
			this->label1->TabIndex = 2;
			this->label1->Text = L"起点";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(10, 179);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(29, 12);
			this->label2->TabIndex = 4;
			this->label2->Text = L"终点";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(63, 176);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(98, 21);
			this->textBox2->TabIndex = 3;
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 12;
			this->listBox1->Location = System::Drawing::Point(167, 68);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(126, 316);
			this->listBox1->TabIndex = 5;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(12, 104);
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
			this->radioButton2->Location = System::Drawing::Point(102, 104);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(59, 16);
			this->radioButton2->TabIndex = 7;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"少停站";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &mainView::radioButton2_CheckedChanged);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox1->Cursor = System::Windows::Forms::Cursors::SizeAll;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(299, 30);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(482, 388);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pictureBox1->TabIndex = 8;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &mainView::pictureBox1_Click);
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &mainView::pictureBox1_MouseDown);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &mainView::pictureBox1_MouseMove);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &mainView::pictureBox1_MouseUp);
			this->pictureBox1->MouseWheel += gcnew System::Windows::Forms::MouseEventHandler(this, &mainView::pictureBox1_MouseWheel);
				// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->设置为起点ToolStripMenuItem,
					this->设置为终点ToolStripMenuItem
			});
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(153, 70);
			// 
			// 设置为起点ToolStripMenuItem
			// 
			this->设置为起点ToolStripMenuItem->Name = L"设置为起点ToolStripMenuItem";
			this->设置为起点ToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->设置为起点ToolStripMenuItem->Text = L"设置为起点";
			// 
			// 设置为终点ToolStripMenuItem
			// 
			this->设置为终点ToolStripMenuItem->Name = L"设置为终点ToolStripMenuItem";
			this->设置为终点ToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->设置为终点ToolStripMenuItem->Text = L"设置为终点";
			// 
			// mainView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(787, 447);
			this->Controls->Add(this->pictureBox1);
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->contextMenuStrip1->ResumeLayout(false);
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
		//this->sd = new subway::subway(std::string("./beijing-subway.txt"));
		this->textBox1->Text = "知春路";
		this->textBox2->Text = "沙河";
		this->pm = subway::pm_Short;
		this->radioButton2->Checked = true;
		System::Drawing::Pen^ pen = gcnew System::Drawing::Pen(System::Drawing::Color::DarkSeaGreen);
		this->bm = (Bitmap^)this->pictureBox1->Image;
		this->pbW = this->pictureBox1->Width;
		this->pbH = this->pictureBox1->Height;
		this->setCXY(589, 438, false);
	}
	private: int CX, CY;
	private: float scale = 1.0;
	private: void setCXY(int x, int y, bool delta) {
		if (delta) {
			this->CX += x;
			this->CY += y;
		}
		else {
			this->CX = x;
			this->CY = y;
		}
		this->showCenter();
		if (this->scale <= 0.999999) this->adjustSize();
	}

	private: void setScale(float tmp) {
		if (tmp < 0.4) tmp = 0.4;
		if (tmp > 1) tmp = 1;
		if (fabs(tmp - this->scale)>=0.00001) {
			this->scale = tmp;
			this->adjustSize();
		}
	}

	private: bool adjustSize() {
		int XX = (int)(this->bm->Width*this->scale);
		int YY = (int)(this->bm->Height*this->scale);
		int tcx = (int)(this->CX*this->scale);
		int tcy = (int)(this->CY*this->scale);
		Bitmap^bm2 = gcnew Bitmap(XX,YY);
		Graphics ^gh2 = Graphics::FromImage(bm2);
		gh2->DrawImage(bm, System::Drawing::Rectangle(0, 0, this->pbW, this->pbH), System::Drawing::Rectangle(0, 0, this->bm->Width, this->bm->Height), GraphicsUnit::Pixel);
		int tx = tcx - this->pbW / 2;
		int ty = tcy - this->pbH / 2;
		int gx = 0, gy = 0;
		if (tx < 0) gx = -tx, tx = 0;
		if (ty < 0) gy = -ty, ty = 0;
		Bitmap^ bmp = gcnew Bitmap(this->pbW, this->pbH);
		this->gh = Graphics::FromImage(bmp);
		this->gh->DrawImage(bm2, System::Drawing::Rectangle(tx, ty, this->pbW - gx, this->pbH - gy), System::Drawing::Rectangle(tx, ty, this->pbW - gx, this->pbH - gy), GraphicsUnit::Pixel);
		this->pictureBox1->Image = bmp;
		return true;
	}

	private: bool showCenter() {
		int x = this->CX;
		int y = this->CY;
		if (this->bm == nullptr || x < 0 || x >= this->bm->Width || y<0 || y>this->bm->Height) return false;
		x = max(x, this->pbW >> 1);
		y = max(y, this->pbH >> 1);
		x = min(x, this->bm->Width - this->pbW / 2);
		y = min(y, this->bm->Height - this->pbH / 2);
		this->CX = x;
		this->CY = y;
		int tx = x - this->pbW / 2;
		int ty = y - this->pbH / 2;
		Bitmap^ bmp = gcnew Bitmap(this->pbW, this->pbH);
		this->gh = Graphics::FromImage(bmp);
		this->gh->DrawImage(this->bm, System::Drawing::Rectangle(0, 0, this->pbW, this->pbH), System::Drawing::Rectangle(tx, ty, this->pbW, this->pbH), GraphicsUnit::Pixel);
		this->pictureBox1->Image = bmp;
		return true;
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
	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: bool Dragging = false;
	private: int dPreX, dPreY, SX,SY;
	private: System::Void pictureBox1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (this->Dragging) return;
		if (e->Button == System::Windows::Forms::MouseButtons::Left) {
			this->Dragging = true;
			this->dPreX = e->X;
			this->dPreY = e->Y;
			this->SX = e->X;
			this->SY = e->Y;
			this->pictureBox1->Cursor = Cursors::SizeAll;
		}
		else if (e->Button == System::Windows::Forms::MouseButtons::Right) {
			this->contextMenuStrip1->Show(MousePosition);
		}
	}
	private: System::Void pictureBox1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (e->Button==System::Windows::Forms::MouseButtons::Left) this->Dragging = false;
	}
	private: System::Void pictureBox1_MouseWheel(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		float tmp = this->scale;
		if (e->Delta > 0) tmp += 0.1;
		else if (e->Delta < 0) tmp -= 0.1;
		//System::Windows::Forms::MessageBox::Show("滑");
		this->textBox1->Text = "滑";
		this->setScale(tmp);

	}
	private: System::Void pictureBox1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (this->Dragging) {
			int dx = e->X - this->dPreX;
			int dy = e->Y - this->dPreY;
			this->setCXY(-dx, -dy, true);
			this->dPreX = e->X;
			this->dPreY = e->Y;
		}
		else {
			int dx = abs(e->X - this->SX);
			int dy = abs(e->Y - this->SY);
			this->pictureBox1->ResetCursor();
			if (e->Button == System::Windows::Forms::MouseButtons::Right ||
				e->Button == System::Windows::Forms::MouseButtons::Left&&dx < 3 && dy < 3) {

			}
		}
	}
	};
}
