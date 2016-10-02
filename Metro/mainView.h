#pragma once
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>

#include "subway.h"
//using namespace subway;

#define MIN_SIZE 0.3

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
		mainView(subway::swList *mps)
		{
			//this->sd = subw[0];
			this->sds = mps;
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
	private: subway::swList * sds;
	private: subway::planMode pm;
	private: System::Drawing::Bitmap ^ bm, ^src;
	private: Graphics^ gh;
	private: int pbW, pbH;

	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  设置为起点ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  设置为终点ToolStripMenuItem;
	private: System::Windows::Forms::TrackBar^  trackBar1;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::ImageList^  imageList1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::ImageList^  imageList2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip2;
	private: System::Windows::Forms::ToolStripMenuItem^  蓝色ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  红色ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  黑色ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  绿色ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  紫色ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  白色ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  金色ToolStripMenuItem;







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
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->imageList2 = (gcnew System::Windows::Forms::ImageList(this->components));
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->contextMenuStrip2 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->蓝色ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->红色ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->黑色ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->绿色ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->紫色ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->白色ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->金色ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->contextMenuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->contextMenuStrip2->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(166, 556);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(131, 31);
			this->button1->TabIndex = 5;
			this->button1->Text = L"查询";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &mainView::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->ForeColor = System::Drawing::Color::RoyalBlue;
			this->textBox1->Location = System::Drawing::Point(199, 477);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(98, 21);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &mainView::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label1->Location = System::Drawing::Point(164, 483);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(29, 12);
			this->label1->TabIndex = 2;
			this->label1->Text = L"起点";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label2->Location = System::Drawing::Point(164, 529);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(29, 12);
			this->label2->TabIndex = 4;
			this->label2->Text = L"终点";
			this->label2->Click += gcnew System::EventHandler(this, &mainView::label2_Click);
			// 
			// textBox2
			// 
			this->textBox2->ForeColor = System::Drawing::Color::RoyalBlue;
			this->textBox2->Location = System::Drawing::Point(199, 523);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(98, 21);
			this->textBox2->TabIndex = 3;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &mainView::textBox2_TextChanged);
			// 
			// listBox1
			// 
			this->listBox1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->listBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->listBox1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei Light", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->listBox1->ForeColor = System::Drawing::Color::RoyalBlue;
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 21;
			this->listBox1->Location = System::Drawing::Point(392, 471);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(296, 126);
			this->listBox1->TabIndex = 9;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &mainView::listBox1_SelectedIndexChanged);
			this->listBox1->DoubleClick += gcnew System::EventHandler(this, &mainView::listBox1_DoubleClick);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->BackColor = System::Drawing::Color::Transparent;
			this->radioButton1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->radioButton1->Location = System::Drawing::Point(52, 506);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(59, 16);
			this->radioButton1->TabIndex = 7;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"少换乘";
			this->radioButton1->UseVisualStyleBackColor = false;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &mainView::radioButton1_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->BackColor = System::Drawing::Color::Transparent;
			this->radioButton2->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->radioButton2->Location = System::Drawing::Point(52, 529);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(59, 16);
			this->radioButton2->TabIndex = 8;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"少停站";
			this->radioButton2->UseVisualStyleBackColor = false;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &mainView::radioButton2_CheckedChanged);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->ContextMenuStrip = this->contextMenuStrip1;
			this->pictureBox1->Cursor = System::Windows::Forms::Cursors::SizeAll;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(741, 458);
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
			this->contextMenuStrip1->Size = System::Drawing::Size(137, 48);
			this->contextMenuStrip1->Opening += gcnew System::ComponentModel::CancelEventHandler(this, &mainView::contextMenuStrip1_Opening);
			// 
			// 设置为起点ToolStripMenuItem
			// 
			this->设置为起点ToolStripMenuItem->Name = L"设置为起点ToolStripMenuItem";
			this->设置为起点ToolStripMenuItem->Size = System::Drawing::Size(136, 22);
			this->设置为起点ToolStripMenuItem->Text = L"设置为起点";
			this->设置为起点ToolStripMenuItem->Click += gcnew System::EventHandler(this, &mainView::设置为起点ToolStripMenuItem_Click);
			// 
			// 设置为终点ToolStripMenuItem
			// 
			this->设置为终点ToolStripMenuItem->Name = L"设置为终点ToolStripMenuItem";
			this->设置为终点ToolStripMenuItem->Size = System::Drawing::Size(136, 22);
			this->设置为终点ToolStripMenuItem->Text = L"设置为终点";
			this->设置为终点ToolStripMenuItem->Click += gcnew System::EventHandler(this, &mainView::设置为终点ToolStripMenuItem_Click);
			// 
			// trackBar1
			// 
			this->trackBar1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(82)), static_cast<System::Int32>(static_cast<System::Byte>(139)),
				static_cast<System::Int32>(static_cast<System::Byte>(234)));
			this->trackBar1->LargeChange = 3;
			this->trackBar1->Location = System::Drawing::Point(746, 183);
			this->trackBar1->Maximum = 7;
			this->trackBar1->Minimum = 1;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->trackBar1->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->trackBar1->Size = System::Drawing::Size(45, 207);
			this->trackBar1->TabIndex = 10;
			this->trackBar1->Value = 7;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &mainView::trackBar1_Scroll);
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->BackColor = System::Drawing::Color::Transparent;
			this->radioButton3->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->radioButton3->Location = System::Drawing::Point(52, 484);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(71, 16);
			this->radioButton3->TabIndex = 6;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"周游一圈";
			this->radioButton3->UseVisualStyleBackColor = false;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &mainView::radioButton3_CheckedChanged);
			// 
			// imageList1
			// 
			this->imageList1->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^>(resources->GetObject(L"imageList1.ImageStream")));
			this->imageList1->TransparentColor = System::Drawing::Color::Transparent;
			this->imageList1->Images->SetKeyName(0, L"location.png");
			this->imageList1->Images->SetKeyName(1, L"start.png");
			this->imageList1->Images->SetKeyName(2, L"end.png");
			this->imageList1->Images->SetKeyName(3, L"mark1.png");
			this->imageList1->Images->SetKeyName(4, L"mark2.png");
			this->imageList1->Images->SetKeyName(5, L"mark3.png");
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(701, 7);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(32, 32);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 13;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &mainView::pictureBox2_Click);
			this->pictureBox2->MouseEnter += gcnew System::EventHandler(this, &mainView::pictureBox2_MouseEnter);
			this->pictureBox2->MouseLeave += gcnew System::EventHandler(this, &mainView::pictureBox2_MouseLeave);
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox3->Location = System::Drawing::Point(663, 7);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(32, 32);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 14;
			this->pictureBox3->TabStop = false;
			this->pictureBox3->Click += gcnew System::EventHandler(this, &mainView::pictureBox3_Click);
			this->pictureBox3->MouseEnter += gcnew System::EventHandler(this, &mainView::pictureBox3_MouseEnter);
			this->pictureBox3->MouseLeave += gcnew System::EventHandler(this, &mainView::pictureBox3_MouseLeave);
			// 
			// imageList2
			// 
			this->imageList2->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^>(resources->GetObject(L"imageList2.ImageStream")));
			this->imageList2->TransparentColor = System::Drawing::Color::Transparent;
			this->imageList2->Images->SetKeyName(0, L"close_up.png");
			this->imageList2->Images->SetKeyName(1, L"close_press.png");
			this->imageList2->Images->SetKeyName(2, L"mini_up.png");
			this->imageList2->Images->SetKeyName(3, L"mini_press.png");
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(229, 501);
			this->button2->Margin = System::Windows::Forms::Padding(0);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(40, 20);
			this->button2->TabIndex = 15;
			this->button2->Text = L"↓↑";
			this->button2->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &mainView::button2_Click);
			// 
			// contextMenuStrip2
			// 
			this->contextMenuStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->蓝色ToolStripMenuItem,
					this->红色ToolStripMenuItem, this->黑色ToolStripMenuItem, this->绿色ToolStripMenuItem, this->紫色ToolStripMenuItem, this->白色ToolStripMenuItem,
					this->金色ToolStripMenuItem
			});
			this->contextMenuStrip2->Name = L"contextMenuStrip2";
			this->contextMenuStrip2->Size = System::Drawing::Size(125, 158);
			// 
			// 蓝色ToolStripMenuItem
			// 
			this->蓝色ToolStripMenuItem->Name = L"蓝色ToolStripMenuItem";
			this->蓝色ToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->蓝色ToolStripMenuItem->Text = L"苍蓝钢铁";
			this->蓝色ToolStripMenuItem->Click += gcnew System::EventHandler(this, &mainView::蓝色ToolStripMenuItem_Click);
			// 
			// 红色ToolStripMenuItem
			// 
			this->红色ToolStripMenuItem->Name = L"红色ToolStripMenuItem";
			this->红色ToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->红色ToolStripMenuItem->Text = L"绯绯色金";
			this->红色ToolStripMenuItem->Click += gcnew System::EventHandler(this, &mainView::红色ToolStripMenuItem_Click);
			// 
			// 黑色ToolStripMenuItem
			// 
			this->黑色ToolStripMenuItem->Name = L"黑色ToolStripMenuItem";
			this->黑色ToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->黑色ToolStripMenuItem->Text = L"黑之睡莲";
			this->黑色ToolStripMenuItem->Click += gcnew System::EventHandler(this, &mainView::黑色ToolStripMenuItem_Click);
			// 
			// 绿色ToolStripMenuItem
			// 
			this->绿色ToolStripMenuItem->Name = L"绿色ToolStripMenuItem";
			this->绿色ToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->绿色ToolStripMenuItem->Text = L"胶化香蕉";
			this->绿色ToolStripMenuItem->Click += gcnew System::EventHandler(this, &mainView::绿色ToolStripMenuItem_Click);
			// 
			// 紫色ToolStripMenuItem
			// 
			this->紫色ToolStripMenuItem->Name = L"紫色ToolStripMenuItem";
			this->紫色ToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->紫色ToolStripMenuItem->Text = L"荡漾女王";
			this->紫色ToolStripMenuItem->Click += gcnew System::EventHandler(this, &mainView::紫色ToolStripMenuItem_Click);
			// 
			// 白色ToolStripMenuItem
			// 
			this->白色ToolStripMenuItem->Name = L"白色ToolStripMenuItem";
			this->白色ToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->白色ToolStripMenuItem->Text = L"一千减七";
			this->白色ToolStripMenuItem->Click += gcnew System::EventHandler(this, &mainView::白色ToolStripMenuItem_Click);
			// 
			// 金色ToolStripMenuItem
			// 
			this->金色ToolStripMenuItem->Name = L"金色ToolStripMenuItem";
			this->金色ToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->金色ToolStripMenuItem->Text = L"誓约胜利";
			this->金色ToolStripMenuItem->Click += gcnew System::EventHandler(this, &mainView::金色ToolStripMenuItem_Click);
			// 
			// mainView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::SteelBlue;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(741, 610);
			this->ContextMenuStrip = this->contextMenuStrip2;
			this->ControlBox = false;
			this->Controls->Add(this->button2);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->radioButton3);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MaximizeBox = false;
			this->Name = L"mainView";
			this->Opacity = 0.98;
			this->RightToLeftLayout = true;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Metro";
			this->TransparencyKey = System::Drawing::Color::Maroon;
			this->Load += gcnew System::EventHandler(this, &mainView::mainView_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &mainView::mainView_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &mainView::mainView_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &mainView::mainView_MouseUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->contextMenuStrip1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->contextMenuStrip2->ResumeLayout(false);
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
		std::srand(time(0));
		//this->sd = new subway::subway(std::string("./beijing-subway.txt"));
		this->pm = subway::pm_Short;
		this->radioButton2->Checked = true;
		this->contextMenuStrip1->Items->Add("-");
		System::Windows::Forms::ToolStripMenuItem ^fsti;
		for (int i = 0; i < this->sds->size(); ++i) {
			System::Windows::Forms::ToolStripMenuItem ^tsmi = gcnew System::Windows::Forms::ToolStripMenuItem();
			tsmi->Name = this->SysString(this->sds->CityName(i).c_str()) + "itm";
			tsmi->Size = System::Drawing::Size(136, 22);
			tsmi->Text = this->SysString(this->sds->CityName(i).c_str());
			tsmi->Click += gcnew System::EventHandler(this, &mainView::changeMap);
			this->contextMenuStrip1->Items->Add(tsmi);
			if (i == 0) fsti = tsmi;
		}
		fsti->PerformClick();

		this->pictureBox2->Image = this->imageList2->Images[0];
		this->pictureBox3->Image = this->imageList2->Images[2];
		this->pictureBox2->Parent = this->pictureBox1;
		this->pictureBox3->Parent = this->pictureBox1;
		int themeID = std::rand() % 7;
		((ToolStripMenuItem^)(this->contextMenuStrip2->Items[themeID]))->PerformClick();
	}
	private: int CX, CY, SCX, SCY;
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
		this->SCX = (int)((float)this->CX / this->bm->Width*this->src->Width);
		this->SCY = (int)((float)this->CY / this->bm->Height*this->src->Height);
		this->showCenter();
	}

	private: void setScale(float tmp) {
		if (tmp < MIN_SIZE) tmp = MIN_SIZE;
		if (tmp > 1) tmp = 1;
		if (fabs(tmp - this->scale) >= 0.00001) {
			this->scale = tmp;
			this->adjustSize();
		}
	}

	private: bool adjustSize() {
		int XX = (int)(this->src->Width*this->scale);
		int YY = (int)(this->src->Height*this->scale);
		this->CX = (int)(this->SCX*this->scale);
		this->CY = (int)(this->SCY*this->scale);
		this->bm = gcnew Bitmap(XX, YY);
		Graphics ^gh2 = Graphics::FromImage(bm);
		gh2->DrawImage(this->src, System::Drawing::Rectangle(0, 0, XX, YY), System::Drawing::Rectangle(0, 0, this->src->Width, this->src->Height), GraphicsUnit::Pixel);
		return this->drawItem();
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

	private: subway::map<int, subway::PA>* tdm;
	private: int editMode = 0;
	private: int nowAt;

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		if (this->editMode != 0) {
			int id = this->listBox1->SelectedIndex;
			this->textBox1->Text = SysString(this->sd->getStation(id).c_str());
			int xx = this->SUX, yy = this->SUY;
			(*this->tdm)[id] = subway::PA(xx, yy);
			this->textBox1->Text += Convert::ToString(this->tdm->size());
			FILE* TF;
			fopen_s(&TF, "points.txt", "w");
			for (int i = 0; i < this->sd->stationCount(); ++i) {
				if (this->tdm->find(i) != this->tdm->end()) {
					xx = (*this->tdm)[i].first;
					yy = (*this->tdm)[i].second;
					fprintf_s(TF, "%s %d %d\n", this->sd->getStation(i).c_str(), xx, yy);
				}
			}
			fclose(TF);
			return;
		}//edit_Mode

		System::String^ st1 = this->textBox1->Text;
		System::String^ st2 = this->textBox2->Text;
		std::string *s = this->stdString(st1);
		std::string *t = this->stdString(st2);
		this->listBox1->Items->Clear();
		this->button1->Enabled = false;
		this->button2->Enabled = false;
		int flag;
		if (this->textBox2->Enabled == false) flag = this->sd->do_a(*s);
		else if (this->pm == subway::pm_convi) flag = this->sd->do_c(*s, *t);
		else if (this->pm == subway::pm_Short) flag = this->sd->do_b(*s, *t);
		if (flag == 0) {
			this->listBox1->Items->Add("站数：" + Convert::ToString(this->sd->getPlanNums().first) + "， 换乘次数：" + Convert::ToString(this->sd->getPlanNums().second));
			for (int i = 0; i < this->sd->getCount(); ++i) {
				this->listBox1->Items->Add(this->SysString(this->sd->getStep(i).c_str()));
			}
			this->listBox1->SelectedIndex = 1;
			this->hasSigned = false;
			this->hasRoute = true;
			this->hasBegin = true;
			this->hasEnd = true;
			subway::PA be = this->sd->getXYByName(*(this->stdString(this->textBox1->Text))),
				en = this->sd->getXYByName(*(this->stdString(this->textBox2->Text)));
			this->BX = be.first, this->BY = be.second;
			this->EX = en.first, this->EY = en.second;
			this->nowAt = this->sd->getOriginalData(0);
			this->scale = 0.7;
			this->adjustSize();
			this->setCXY((be.first+en.first>>1)*0.5,(be.second+en.second>>1)*0.5,false);
		}
		else {
			this->listBox1->Items->Add("找不到站点");
			this->hasRoute = false;
			this->hasBegin = false;
			this->hasEnd = false;
		}
		this->button1->Enabled = true;
		this->button2->Enabled = true;

		if (*s == "TDM_toka"&&this->radioButton3->Checked) {
			this->editMode = 1;
			this->textBox1->Enabled = false;
			this->textBox1->Enabled = false;
			this->radioButton1->Enabled = false;
			this->radioButton2->Enabled = false;
			this->radioButton3->Enabled = false;
			this->listBox1->Items->Clear();
			int cnt = sd->stationCount();
			for (int i = 0; i < cnt; ++i) {
				this->listBox1->Items->Add(this->SysString(this->sd->getStation(i).c_str()));
			}
			this->tdm = new subway::map<int, subway::PA>();
			this->tdm->clear();
		}//edit_Mode
	}
	private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		this->pm = subway::pm_convi;
		this->textBox2->Enabled = true;
	}
	private: System::Void radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			this->pm = subway::pm_Short;
		this->textBox2->Enabled = true;
	}
	private: System::Void radioButton3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		this->textBox2->Enabled = false;
	}
	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: bool Dragging = false;
	private: int dPreX, dPreY, SX, SY;
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

	private: bool hasSigned = false, hasBegin = false, hasEnd = false, hasRoute = false;

	private: void drawTag(int xx, int yy, int id) {
		std::string pname = this->sd->getNameByXY(subway::PA(xx, yy));
		subway::PA tmp = this->sd->getXYByName(pname);
		xx = tmp.first, yy = tmp.second;
		Graphics ^gh2 = Graphics::FromImage(bm);
		xx = (int)(xx*this->scale);
		yy = (int)(yy*this->scale);
		System::Drawing::Image^tima = this->imageList1->Images[id];
		gh2->DrawImage(tima, System::Drawing::Rectangle(xx - tima->Width / 2 + 3, yy - tima->Height, tima->Width, tima->Height));
	}

	private: bool drawItem() {
		int no = 0;
		if (hasRoute) {
			int cnt = this->sd->getOriginalCNT();
			for (int i = 0; i < cnt; ++i) {
				int tmp = this->sd->getOriginalData(i);
				int trflag = 0;
				if (i > 0 && this->sd->getOriginalData(i - 1) == tmp) trflag = 1;
				if (tmp == this->nowAt) no = 1;
				if (i == 0 || i == cnt - 1) continue;
				subway::PA p = this->sd->getXYByName(this->sd->getStation(tmp));
				if (!no) {
					this->drawTag(p.first, p.second, 4);
				}
				else {
					if (!trflag) this->drawTag(p.first, p.second, 3);
					else this->drawTag(p.first, p.second, 5);
				}
			}
		}
		if (hasSigned) {
			int xx = this->SUX, yy = this->SUY;
			this->drawTag(xx, yy, 0);
		}
		if (hasBegin) {
			int xx = this->BX, yy = this->BY;
			this->drawTag(xx, yy, 1);
		}
		if (hasEnd) {
			int xx = this->EX, yy = this->EY;
			this->drawTag(xx, yy, 2);
		}
		return this->showCenter();
	}

	private: System::Void pictureBox1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left) this->Dragging = false;
		if (e->Y < 45) return;
		if (this->Dragging == false) {
			int dx = abs(e->X - this->SX);
			int dy = abs(e->Y - this->SY);
			if (e->Button == System::Windows::Forms::MouseButtons::Right ||
				e->Button == System::Windows::Forms::MouseButtons::Left&&dx < 3 && dy < 3) {
				this->UX = e->X - this->pbW / 2 + this->CX;
				this->UY = e->Y - this->pbH / 2 + this->CY;
				if (this->editMode) this->textBox1->Text = ("(" + Convert::ToString(this->UX) + ", " + Convert::ToString(this->UY) + ")");
				this->SUX = (int)((float)this->UX / this->bm->Width*this->src->Width);
				this->SUY = (int)((float)this->UY / this->bm->Height*this->src->Height);
				if (this->editMode) this->textBox2->Text = ("(" + Convert::ToString(this->SUX) + ", " + Convert::ToString(this->SUY) + ")");
				if (this->editMode == 0 && e->Button == System::Windows::Forms::MouseButtons::Left) {
					this->hasSigned = true;
					this->adjustSize();
				}
			}
		}
	}
	private: System::Void pictureBox1_MouseWheel(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		float tmp = this->scale;
		if (e->Delta > 0) tmp += 0.1;
		else if (e->Delta < 0) tmp -= 0.1;
		//System::Windows::Forms::MessageBox::Show("滑");
		//this->textBox1->Text = "滑";
		this->setScale(tmp);

	}

	private: int UX = 0, UY = 0, SUX = 0, SUY = 0;
	private: System::Void pictureBox1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		this->trackBar1->Focus();
		if (this->Dragging) {
			int dx = e->X - this->dPreX;
			int dy = e->Y - this->dPreY;
			if (e->Y < 45) {
				this->Location = Point(this->Location.X + dx, this->Location.Y + dy);
				return;
			}
			this->setCXY(-dx, -dy, true);
			this->dPreX = e->X;
			this->dPreY = e->Y;
		}
		else {
			this->pictureBox1->ResetCursor();
		}
	}
	private: double scaleFactor = 0.1;
	private: System::Void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e) {
		this->setScale(1.0 - this->scaleFactor*(7-this->trackBar1->Value));
	}
	private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void contextMenuStrip1_Opening(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
	}
	private: int BX, BY;
	private: System::Void 设置为起点ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		this->hasSigned = false;
		this->hasBegin = true;
		this->hasRoute = false;
		this->BX = this->SUX;
		this->BY = this->SUY;
		int xx = this->BX;
		int yy = this->BY;
		std::string pname = this->sd->getNameByXY(subway::PA(xx, yy));
		this->textBox1->Text = this->SysString(pname.c_str());
		this->adjustSize();
	}
	private: int EX, EY;
	private: System::Void 设置为终点ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		this->hasSigned = false;
		this->hasEnd = true;
		this->hasRoute = false;
		this->EX = this->SUX;
		this->EY = this->SUY;
		int xx = this->EX;
		int yy = this->EY;
		std::string pname = this->sd->getNameByXY(subway::PA(xx, yy));
		this->textBox2->Text = this->SysString(pname.c_str());
		this->adjustSize();
	}

	private: System::Void listBox1_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
		int id = this->listBox1->SelectedIndex;
		if (id > 0 && this->listBox1->Items->Count) {
			std::string * tmp = this->stdString((System::String^)this->listBox1->Items[id]);
			int fnd = tmp->find(transfer);
			if (fnd >= 0 && fnd < tmp->size()) --id, tmp = this->stdString((System::String^)this->listBox1->Items[id]);
			this->nowAt = this->sd->getIDByName(tmp);
			this->adjustSize();
		}
	}
	private: System::Void pictureBox2_Click(System::Object^  sender, System::EventArgs^  e) {
		exit(0);
	}
	private: System::Void pictureBox2_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
		this->pictureBox2->Image = this->imageList2->Images[1];
	}
	private: System::Void pictureBox2_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
		this->pictureBox2->Image = this->imageList2->Images[0];
	}
	private: System::Void pictureBox3_Click(System::Object^  sender, System::EventArgs^  e) {
		this->WindowState = System::Windows::Forms::FormWindowState::Minimized;
	}
	private: System::Void pictureBox3_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
		this->pictureBox3->Image = this->imageList2->Images[3];
	}
	private: System::Void pictureBox3_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
		this->pictureBox3->Image = this->imageList2->Images[2];
	}
	private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: int wdrag = 0,wpx,wpy;
	private: System::Void mainView_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left) {
			this->wdrag = 1;
			this->wpx = e->X;
			this->wpy = e->Y;
		}
	}

	private: System::Void mainView_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left) {
			this->wdrag = 0;
		}
	}
	private: System::Void mainView_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (this->wdrag) {
			int dx = e->X - this->wpx;
			int dy = e->Y - this->wpy;
			this->Location = Point(this->Location.X + dx, this->Location.Y + dy);
			//this->wpx = e->X;
			//this->wpy = e->Y;
		}
	}
	
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		System::String ^tmp = this->textBox1->Text;
		this->textBox1->Text = this->textBox2->Text;
		this->textBox2->Text = tmp;
	}

	private: System::Void changeMap(System::Object^  sender, System::EventArgs^  e) {
		System::Windows::Forms::ToolStripMenuItem^ tmp = ((System::Windows::Forms::ToolStripMenuItem^)sender);
		//fprintf_s(stderr, "%s in %d lines\n", "finding", min(this->sdsC, this->contextMenuStrip1->Items->Count));
		this->hasBegin = false;
		this->hasEnd = false;
		this->hasSigned = false;
		this->hasRoute = false;
		for (int i = 0; i < this->sds->size(); ++i) {
			if (this->contextMenuStrip1->Items[i + 3] == tmp) {
				tmp->Checked = true;
				this->sd = (*(this->sds))[i];
				//fprintf_s(stderr, "%s\n", "find one");
			}
			else ((System::Windows::Forms::ToolStripMenuItem^)(this->contextMenuStrip1->Items[i + 3]))->Checked = false;
		}
		try {
			this->pictureBox1->Image = System::Drawing::Image::FromFile(this->SysString(this->sd->getMapPic().c_str()));
		}
		catch (const System::Exception ^e)
		{
			fprintf_s(stderr, "%s\n", "read map failed.");
			throw e;
		}
		System::Drawing::Pen^ pen = gcnew System::Drawing::Pen(System::Drawing::Color::DarkSeaGreen);
		this->src = (Bitmap^)this->pictureBox1->Image;
		this->pbW = this->pictureBox1->Width;
		this->pbH = this->pictureBox1->Height;
		this->trackBar1->Minimum = 0;
		this->trackBar1->Maximum = 7;
		this->trackBar1->Value = 6;
		this->scaleFactor = (1.0 - max((double)this->pbW / this->src->Width, (double)this->pbH / this->src->Height)) / 7;
		//printf("%.6f\n",this->scaleFactor);
		this->setScale(1.0 - this->scaleFactor*(7-this->trackBar1->Value));
		this->adjustSize();
		this->setCXY(this->src->Width>>1, this->src->Height>>1, false);
		this->textBox1->Text = this->SysString(this->sd->getStation(std::rand() % this->sd->stationCount()).c_str());
		this->textBox2->Text = this->SysString(this->sd->getStation(std::rand() % this->sd->stationCount()).c_str());
		this->Text = "Metro - " + this->SysString(this->sd->getLineName().c_str());
	}
private: System::Void 红色ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	this->BackColor = Color::LightPink;
	Color lab = Color::FromArgb(236,30,66);
	Color tex = Color::FromArgb(239, 75, 104);
	Color bgm = Color::White;
	this->label1->ForeColor = lab;
	this->label2->ForeColor = lab;
	this->radioButton1->ForeColor = lab;
	this->radioButton2->ForeColor = lab;
	this->radioButton3->ForeColor = lab;
	this->textBox1->ForeColor = tex;
	this->textBox2->ForeColor = tex;
	this->listBox1->ForeColor = tex;
	this->textBox1->BackColor = bgm;
	this->textBox2->BackColor = bgm;
	this->listBox1->BackColor = bgm;
	this->textBox1->BorderStyle = BorderStyle::Fixed3D;
	this->textBox2->BorderStyle = BorderStyle::Fixed3D;
}
private: System::Void 蓝色ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	this->BackColor = Color::SteelBlue;
	Color lab = Color::White;
	Color tex = Color::SteelBlue;
	Color bgm = Color::White;
	this->label1->ForeColor = lab;
	this->label2->ForeColor = lab;
	this->radioButton1->ForeColor = lab;
	this->radioButton2->ForeColor = lab;
	this->radioButton3->ForeColor = lab;
	this->textBox1->ForeColor = tex;
	this->textBox2->ForeColor = tex;
	this->listBox1->ForeColor = tex;
	this->textBox1->BackColor = bgm;
	this->textBox2->BackColor = bgm;
	this->listBox1->BackColor = bgm;
	this->textBox1->BorderStyle = BorderStyle::Fixed3D;
	this->textBox2->BorderStyle = BorderStyle::Fixed3D;
}
private: System::Void 黑色ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	this->BackColor = Color::FromArgb(64,64,64);
	Color lab = Color::White;
	Color tex = Color::White;
	Color bgm = Color::FromArgb(32, 32, 32);
	this->label1->ForeColor = lab;
	this->label2->ForeColor = lab;
	this->radioButton1->ForeColor = lab;
	this->radioButton2->ForeColor = lab;
	this->radioButton3->ForeColor = lab;
	this->textBox1->ForeColor = tex;
	this->textBox2->ForeColor = tex;
	this->listBox1->ForeColor = tex;
	this->textBox1->BackColor = bgm;
	this->textBox2->BackColor = bgm;
	this->listBox1->BackColor = bgm;
	this->textBox1->BorderStyle = BorderStyle::FixedSingle;
	this->textBox2->BorderStyle = BorderStyle::FixedSingle;
}
private: System::Void 绿色ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	this->BackColor = Color::FromArgb(82,235,86);
	Color lab = Color::FromArgb(24,100,60);
	Color tex = Color::FromArgb(22,214,95);
	Color bgm = Color::White;
	this->label1->ForeColor = lab;
	this->label2->ForeColor = lab;
	this->radioButton1->ForeColor = lab;
	this->radioButton2->ForeColor = lab;
	this->radioButton3->ForeColor = lab;
	this->textBox1->ForeColor = tex;
	this->textBox2->ForeColor = tex;
	this->listBox1->ForeColor = tex;
	this->textBox1->BackColor = bgm;
	this->textBox2->BackColor = bgm;
	this->listBox1->BackColor = bgm;
	this->textBox1->BorderStyle = BorderStyle::Fixed3D;
	this->textBox2->BorderStyle = BorderStyle::Fixed3D;
}
private: System::Void 紫色ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	this->BackColor = Color::FromArgb(106, 57, 104);
	Color lab = Color::White;
	Color tex = Color::FromArgb(106, 57, 104);
	Color bgm = Color::White;
	this->label1->ForeColor = lab;
	this->label2->ForeColor = lab;
	this->radioButton1->ForeColor = lab;
	this->radioButton2->ForeColor = lab;
	this->radioButton3->ForeColor = lab;
	this->textBox1->ForeColor = tex;
	this->textBox2->ForeColor = tex;
	this->listBox1->ForeColor = tex;
	this->textBox1->BackColor = bgm;
	this->textBox2->BackColor = bgm;
	this->listBox1->BackColor = bgm;
	this->textBox1->BorderStyle = BorderStyle::Fixed3D;
	this->textBox2->BorderStyle = BorderStyle::Fixed3D;
}
private: System::Void 白色ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	this->BackColor = Color::GhostWhite;
	Color lab = Color::FromArgb(32, 32, 32);
	Color tex = Color::FromArgb(32, 32, 32);
	Color bgm = Color::White;
	this->label1->ForeColor = lab;
	this->label2->ForeColor = lab;
	this->radioButton1->ForeColor = lab;
	this->radioButton2->ForeColor = lab;
	this->radioButton3->ForeColor = lab;
	this->textBox1->ForeColor = tex;
	this->textBox2->ForeColor = tex;
	this->listBox1->ForeColor = tex;
	this->textBox1->BackColor = bgm;
	this->textBox2->BackColor = bgm;
	this->listBox1->BackColor = bgm;
	this->textBox1->BorderStyle = BorderStyle::Fixed3D;
	this->textBox2->BorderStyle = BorderStyle::Fixed3D;
}
private: System::Void 金色ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	this->BackColor = Color::FromArgb(247,237,159);
	Color lab = Color::FromArgb(26, 34, 79);
	Color tex = Color::FromArgb(243, 143, 33);
	Color bgm = Color::White;
	this->label1->ForeColor = lab;
	this->label2->ForeColor = lab;
	this->radioButton1->ForeColor = lab;
	this->radioButton2->ForeColor = lab;
	this->radioButton3->ForeColor = lab;
	this->textBox1->ForeColor = tex;
	this->textBox2->ForeColor = tex;
	this->listBox1->ForeColor = tex;
	this->textBox1->BackColor = bgm;
	this->textBox2->BackColor = bgm;
	this->listBox1->BackColor = bgm;
	this->textBox1->BorderStyle = BorderStyle::Fixed3D;
	this->textBox2->BorderStyle = BorderStyle::Fixed3D;
}
};
}
