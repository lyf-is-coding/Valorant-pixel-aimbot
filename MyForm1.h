#pragma once

#include <Windows.h>
#include "pch.h"
#include "interception.h"
#include <stdio.h>
#include <iostream>
#include <cstdlib> 
#include <thread>
#include <chrono>
#include "winres.h"

#pragma comment(lib, "interception.lib")

int get_screen_width(void) {
	return GetSystemMetrics(SM_CXSCREEN);
}

int get_screen_height(void) {
	return GetSystemMetrics(SM_CYSCREEN);
}

struct point {
	double x;
	double y;
	point(double x, double y) : x(x), y(y) {}
};

inline bool IsMauSac(int red, int green, int blue)
{
	if (green >= 190) {
		return false;
	}

	if (green >= 140) {
		return abs(red - blue) <= 8 &&
			red - green >= 50 &&
			blue - green >= 50 &&
			red >= 105 &&
			blue >= 105;
	}

	return abs(red - blue) <= 13 &&
		red - green >= 60 &&
		blue - green >= 60 &&
		red >= 110 &&
		blue >= 100;
}



 
//bool bot() {
//	int w = 100, h = 100;
//	auto t_start = std::chrono::high_resolution_clock::now();
//	auto t_end = std::chrono::high_resolution_clock::now();
//
//	HDC hScreen = GetDC(NULL);
//	HBITMAP hBitmap = CreateCompatibleBitmap(hScreen, w, h);
//	screenData = (BYTE*)malloc(5 * screen_width * screen_height);
//	HDC hDC = CreateCompatibleDC(hScreen);
//	point middle_screen(screen_width / 2, screen_height / 2);
//
//	BITMAPINFOHEADER bmi = { 0 };
//	bmi.biSize = sizeof(BITMAPINFOHEADER);
//	bmi.biPlanes = 1;
//	bmi.biBitCount = 32;
//	bmi.biWidth = w;
//	bmi.biHeight = -h;
//	bmi.biCompression = BI_RGB;
//	bmi.biSizeImage = 0;
//
//	while (run_threads) {
//		bool stop_loop = false;
//		Sleep(6);
//
//		HGDIOBJ old_obj = SelectObject(hDC, hBitmap);
//		BOOL bRet = BitBlt(hDC, 0, 0, w, h, hScreen, middle_screen.x - (w / 2), middle_screen.y - (h / 2), SRCCOPY);
//		SelectObject(hDC, old_obj);
//		GetDIBits(hDC, hBitmap, 0, h, screenData, (BITMAPINFO*)&bmi, DIB_RGB_COLORS);
//		
//
//		for (int j = 0; j < h; ++j) {
//			for (int i = 0; i < w * 4; i += 4) {
//				#define red screenData[i + (j*w*4) + 2]
//				#define green screenData[i + (j*w*4) + 1]
//				#define blue screenData[i + (j*w*4) + 0]
//
//				if (IsMauSac(red, green, blue)) {
//					aim_x = (i / 4) - (w / 2);
//					aim_y = j - (h / 2) + 3;
//					stop_loop = true;
//					break;
//				}
//			}
//			if (stop_loop) break;
//		}
//		if (!stop_loop) {
//			aim_x = 0;
//			aim_y = 0;
//		}
//	}
//	return 0;
//}

InterceptionContext context;
InterceptionDevice device;
InterceptionStroke stroke;

BYTE* screenData = 0;

using namespace std;

namespace Lavender {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}




	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::TrackBar^ trackBar1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::RadioButton^ mickey5;






	private: System::Windows::Forms::RadioButton^ mickey4;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label10;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker2;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::TrackBar^ trackBar2;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::CheckBox^ checkBox1;









	private: System::ComponentModel::IContainer^ components;
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
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->mickey5 = (gcnew System::Windows::Forms::RadioButton());
			this->mickey4 = (gcnew System::Windows::Forms::RadioButton());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->backgroundWorker2 = (gcnew System::ComponentModel::BackgroundWorker());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(14, 82);
			this->trackBar1->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->trackBar1->Minimum = 1;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(208, 45);
			this->trackBar1->TabIndex = 1;
			this->trackBar1->TickStyle = System::Windows::Forms::TickStyle::None;
			this->trackBar1->Value = 1;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar1_Scroll);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->label1->Location = System::Drawing::Point(16, 115);
			this->label1->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(154, 28);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Mickey sm00th";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold));
			this->label2->Location = System::Drawing::Point(217, 82);
			this->label2->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(21, 24);
			this->label2->TabIndex = 3;
			this->label2->Text = L"1";
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->WorkerReportsProgress = true;
			this->backgroundWorker1->WorkerSupportsCancellation = true;
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker1_DoWork);
			// 
			// mickey5
			// 
			this->mickey5->AutoSize = true;
			this->mickey5->Location = System::Drawing::Point(14, 49);
			this->mickey5->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->mickey5->Name = L"mickey5";
			this->mickey5->Size = System::Drawing::Size(107, 23);
			this->mickey5->TabIndex = 5;
			this->mickey5->TabStop = true;
			this->mickey5->Text = L"Mickey 5";
			this->mickey5->UseVisualStyleBackColor = true;
			// 
			// mickey4
			// 
			this->mickey4->AutoSize = true;
			this->mickey4->Location = System::Drawing::Point(131, 51);
			this->mickey4->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->mickey4->Name = L"mickey4";
			this->mickey4->Size = System::Drawing::Size(107, 23);
			this->mickey4->TabIndex = 6;
			this->mickey4->TabStop = true;
			this->mickey4->Text = L"Mickey 4";
			this->mickey4->UseVisualStyleBackColor = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Location = System::Drawing::Point(16, 281);
			this->label3->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(79, 19);
			this->label3->TabIndex = 7;
			this->label3->Text = L"@imb0t:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->ForeColor = System::Drawing::Color::Maroon;
			this->label4->Location = System::Drawing::Point(92, 281);
			this->label4->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(39, 19);
			this->label4->TabIndex = 8;
			this->label4->Text = L"OFF";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Consolas", 14.25F));
			this->textBox1->Location = System::Drawing::Point(252, 83);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(149, 30);
			this->textBox1->TabIndex = 9;
			this->textBox1->Text = L"1";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(248, 51);
			this->label5->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(129, 19);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Mickey Sens:";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(35, 35);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 11;
			this->pictureBox1->TabStop = false;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label6->Font = (gcnew System::Drawing::Font(L"SimSun", 15.75F, System::Drawing::FontStyle::Bold));
			this->label6->ForeColor = System::Drawing::Color::Maroon;
			this->label6->Location = System::Drawing::Point(40, 9);
			this->label6->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(220, 21);
			this->label6->TabIndex = 12;
			this->label6->Text = L"是一起身體 不能不要";
			// 
			// label7
			// 
			this->label7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label7->BackColor = System::Drawing::Color::FloralWhite;
			this->label7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label7->ForeColor = System::Drawing::Color::Maroon;
			this->label7->Location = System::Drawing::Point(385, 9);
			this->label7->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(21, 21);
			this->label7->TabIndex = 13;
			this->label7->Text = L"x";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label7->Click += gcnew System::EventHandler(this, &MyForm::label7_Click);
			// 
			// label8
			// 
			this->label8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label8->BackColor = System::Drawing::Color::FloralWhite;
			this->label8->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label8->ForeColor = System::Drawing::Color::Maroon;
			this->label8->Location = System::Drawing::Point(354, 9);
			this->label8->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(21, 21);
			this->label8->TabIndex = 14;
			this->label8->Text = L"-";
			this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label8->Click += gcnew System::EventHandler(this, &MyForm::label8_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(248, 127);
			this->label9->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(99, 19);
			this->label9->TabIndex = 15;
			this->label9->Text = L"Mickey Y:";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->panel1->Controls->Add(this->label8);
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->label7);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(419, 36);
			this->panel1->TabIndex = 16;
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Consolas", 14.25F));
			this->textBox2->Location = System::Drawing::Point(252, 158);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(149, 30);
			this->textBox2->TabIndex = 17;
			this->textBox2->Text = L"2";
			// 
			// label10
			// 
			this->label10->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L".TMC-Ong Do", 15.75F));
			this->label10->Location = System::Drawing::Point(358, 281);
			this->label10->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(61, 31);
			this->label10->TabIndex = 18;
			this->label10->Text = L"UC <3";
			// 
			// backgroundWorker2
			// 
			this->backgroundWorker2->WorkerReportsProgress = true;
			this->backgroundWorker2->WorkerSupportsCancellation = true;
			this->backgroundWorker2->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker2_DoWork);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->label11->Location = System::Drawing::Point(16, 192);
			this->label11->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(203, 56);
			this->label11->TabIndex = 20;
			this->label11->Text = L"Delay between every\r\nmickey acceleration\r\n";
			// 
			// trackBar2
			// 
			this->trackBar2->Location = System::Drawing::Point(14, 159);
			this->trackBar2->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->trackBar2->Maximum = 100;
			this->trackBar2->Name = L"trackBar2";
			this->trackBar2->Size = System::Drawing::Size(208, 45);
			this->trackBar2->TabIndex = 19;
			this->trackBar2->TickStyle = System::Windows::Forms::TickStyle::None;
			this->trackBar2->Value = 1;
			this->trackBar2->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar2_Scroll);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold));
			this->label12->Location = System::Drawing::Point(217, 159);
			this->label12->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(21, 24);
			this->label12->TabIndex = 21;
			this->label12->Text = L"1";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(252, 205);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(158, 42);
			this->checkBox1->TabIndex = 22;
			this->checkBox1->Text = L"Only Mickey X\r\n@ssist";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			// 
			// MyForm
			// 
			this->AccessibleName = L"mainForm";
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 19);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(26)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->ClientSize = System::Drawing::Size(419, 312);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->trackBar2);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->mickey4);
			this->Controls->Add(this->mickey5);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->panel1);
			this->DoubleBuffered = true;
			this->Font = (gcnew System::Drawing::Font(L"SimSun", 14.25F));
			this->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Opacity = 0.9;
			this->Text = L"是一起身體 不能不要";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e)
	{
		/*std::thread(bot).detach();*/
		 
		backgroundWorker1->WorkerSupportsCancellation = true;
		backgroundWorker1->RunWorkerAsync();

		backgroundWorker2->WorkerSupportsCancellation = true;
		backgroundWorker2->RunWorkerAsync();

		pictureBox1->Image = Image::FromFile("D:\\Working\\LYFHACK LOGO\\mrbump69_logo.png");
		pictureBox1->Refresh();

		
	}

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e)
{
	 
}


    bool mickey_toggle = false;

    float sm00th = 1;
	int mickey_delay = 1;
	
	double mickey_sens = 1;
	
	bool left_mickey_down = false;

	bool only_mickey_X = false;

	private: System::Void backgroundWorker1_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
		auto t_start = std::chrono::high_resolution_clock::now();
		auto t_end = std::chrono::high_resolution_clock::now();
		auto left_mouese_pressed_start = std::chrono::high_resolution_clock::now();
		auto left_mouese_pressed_end = std::chrono::high_resolution_clock::now();
		
		bool first_time_left_mickey_down = true;
		bool first_time_left_mickey_up = true;
		auto left_mickey_pressed_start = std::chrono::high_resolution_clock::now();
		auto left_mickey_pressed_end = std::chrono::high_resolution_clock::now();
		auto left_mickey_pressed_now = std::chrono::high_resolution_clock::now();
		auto elapsed_left_mickey_pressed = std::chrono::duration<double, std::milli>(left_mickey_pressed_end - left_mickey_pressed_start).count();

		bool disabled = false;
		//bool m3 = false;
		bool m4 = false;
		bool m5 = false;

		context = interception_create_context();
		interception_set_filter(context, interception_is_mouse, INTERCEPTION_FILTER_MOUSE_ALL);

		

		AllocConsole();
		auto w_f = freopen("CON", "w", stdout);
		auto r_f = freopen("CON", "r", stdin);
		std::cout << "Rito, please don't ban me!!!\nGo making Music Videos <3" << endl;
		/*std::cout << "Go into loop" << std::endl;*/

		CURSORINFO cursorInfo = { 0 };
		cursorInfo.cbSize = sizeof(cursorInfo);

		while (interception_receive(context, device = interception_wait(context), &stroke, 1) > 0){

			
			
			InterceptionMouseStroke& mstroke = *(InterceptionMouseStroke*)&stroke;

			GetCursorInfo(&cursorInfo);

			//if (mstroke.state & INTERCEPTION_MOUSE_BUTTON_3_DOWN && mouse3->Checked)
			//{
			//	m3 = !m3;
			//	label4->Text = m3 ? "ON" : "OFF";
			//	label4->ForeColor = m3 ? ForeColor.Green : ForeColor.Maroon;
			//}

			//if (mstroke.state & INTERCEPTION_MOUSE_BUTTON_4_DOWN && mickey4->Checked) {
			//	mickey_toggle = !mickey_toggle;
			//	m4 = !m4;
			//	label4->Text = m4 ? "ON" : "OFF";
			//	label4->ForeColor = m4 ? ForeColor.Green : ForeColor.Maroon;
			//}
			//else if (mstroke.state & INTERCEPTION_MOUSE_BUTTON_5_DOWN && mickey5->Checked) {
			//	mickey_toggle = !mickey_toggle;
			//	m5 = !m5;
			//	label4->Text = m5 ? "ON" : "OFF";
			//	label4->ForeColor = m5 ? ForeColor.Green : ForeColor.Maroon;
			//}

			//on / off aimbot
			if ((mstroke.state & INTERCEPTION_MOUSE_BUTTON_4_DOWN && mickey4->Checked) ||
				(mstroke.state & INTERCEPTION_MOUSE_BUTTON_5_DOWN && mickey5->Checked)) {
				mickey_toggle = !mickey_toggle;
				label4->Text = mickey_toggle ? "ON" : "OFF";
				label4->ForeColor = mickey_toggle ? ForeColor.Green : ForeColor.Maroon;
			}

			//kiểm tra khi Cursor không xuất hiện
			if (/*cursorInfo.flags != 1*/ true) {
				if (mstroke.state & INTERCEPTION_MOUSE_LEFT_BUTTON_DOWN /*&& first_time_left_mickey_down*/) {

					/*cout << "mickey left down" << endl;*/

					if (first_time_left_mickey_down) {
						left_mickey_down = true;

						//lấy tgian chuột trái đc giữ xuống
						left_mickey_pressed_start = std::chrono::high_resolution_clock::now();

						first_time_left_mickey_down = false;
						first_time_left_mickey_up = true;
					}

					//nếu aimbot được kích hoạt
					if (mickey_toggle) {

					}
				}
				else if ((mstroke.state & INTERCEPTION_MOUSE_LEFT_BUTTON_UP) && first_time_left_mickey_up) {
					/*cout << "mickey left up" << endl;*/
					left_mickey_down = false;

					//lấy tgian chuột trái đc thả ra
					left_mickey_pressed_end = std::chrono::high_resolution_clock::now();

					
					/*cout << "elapsed: " << elapsed_left_mickey_pressed << endl;*/

					first_time_left_mickey_down = true;
					first_time_left_mickey_up = false;
				}

				//lấy tgian hiện tại khi chuột trái đang đc giữ
				left_mickey_pressed_now = std::chrono::high_resolution_clock::now();

				//tính tgian từ lúc chuột trái đc nhấn xuống -> tgian hiện tại
				elapsed_left_mickey_pressed = std::chrono::duration<double, std::milli>(left_mickey_pressed_now - left_mickey_pressed_start).count();

				//điều chỉnh aim khi chuột trái đc giữ (đang bắn) piupiupiu
				if ( left_mickey_down && mickey_toggle && elapsed_left_mickey_pressed > 99 ) {
					/*cout << "held down :D" << endl;*/
					/*left_mouese_pressed_start = std::chrono::high_resolution_clock::now();*/
					/*left_mouese_pressed_end = std::chrono::high_resolution_clock::now();*/
							/*double recoil_ms = std::chrono::duration<double, std::milli>(left_mouese_pressed_end - left_mouese_pressed_start).count();*/
							/*double extra = 38.1 * (screen_height / 1080.0) * (recoil_ms / 1000.0);*/

							/*if (!left_mickey_down) {
								extra = 0;
							}
							else if (extra > 38.1) {
								extra = 38.1;
							}*/
				}

				t_end = std::chrono::high_resolution_clock::now();
				double elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end - t_start).count();

				//luôn luôn aim
				if ((/*m5 || m4*/mickey_toggle) && (mstroke.flags == 0) && (!left_mickey_down) ) {
					//delay between every aim
					if (elapsed_time_ms > mickey_delay) {
						t_start = std::chrono::high_resolution_clock::now();
						
						//kiểm tra mục tiêu x y có hợp lệ ko
						if (target_x != 0 || target_y != 0) {
							/*cout << "normal aim" << endl;*/
							if (left_mickey_down) {
								cout << "aim and firing" << endl;
							}

							mickey_sens = Convert::ToDouble(textBox1->Text);

							//X
							double v_x = ( double(target_x) ) / (sm00th + sm00th * mickey_sens);

							if (fabs(v_x) < 1.0) {
								v_x = v_x > 0 ? 1.05 : -1.05;
							}

							mstroke.x += v_x;

							//Y. if assist both axis, not only X
							if (!only_mickey_X) {
								double v_y = (double(target_y /*+ extra*/)) / (sm00th + sm00th * mickey_sens);

								if (fabs(v_y) < 1.0) {
									v_y = v_y > 0 ? 1.05 : -1.05;
								}
								mstroke.y += v_y;
							}
							
							
							
							
						}
					}
				}
			}

			interception_send(context, device, &stroke, 1);
			
	}

		fclose(w_f);
		fclose(r_f);
		FreeConsole();
	}

	private: System::Void label8_Click(System::Object^ sender, System::EventArgs^ e) {
		WindowState = FormWindowState::Minimized;
	}

	private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
		System::Windows::Forms::Application::ExitThread();
		System::Windows::Forms::Application::Exit();
	}

	
	

	const int screen_width = get_screen_width(), screen_height = get_screen_height();

	int target_x = 0;
	int target_y = 0;

	float mickeyY = 0;

	bool run_threads = true;

	

	private: System::Void backgroundWorker2_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
		int w = 100, h = 100;
		auto t_start = std::chrono::high_resolution_clock::now();
		auto t_end = std::chrono::high_resolution_clock::now();

		HDC hScreen = GetDC(NULL);
		HBITMAP hBitmap = CreateCompatibleBitmap(hScreen, w, h);
		screenData = (BYTE*)malloc(5 * screen_width * screen_height);
		HDC hDC = CreateCompatibleDC(hScreen);
		point middle_screen(screen_width / 2, screen_height / 2);

		BITMAPINFOHEADER bmi = { 0 };
		bmi.biSize = sizeof(BITMAPINFOHEADER);
		bmi.biPlanes = 1;
		bmi.biBitCount = 32;
		bmi.biWidth = w;
		bmi.biHeight = -h;
		bmi.biCompression = BI_RGB;
		bmi.biSizeImage = 0;

		while (run_threads) {
			bool stop_loop = false;
			Sleep(1);

			HGDIOBJ old_obj = SelectObject(hDC, hBitmap);
			BOOL bRet = BitBlt(hDC, 0, 0, w, h, hScreen, middle_screen.x - (w / 2), middle_screen.y - (h / 2), SRCCOPY);
			SelectObject(hDC, old_obj);
			GetDIBits(hDC, hBitmap, 0, h, screenData, (BITMAPINFO*)&bmi, DIB_RGB_COLORS);


			for (int j = 0; j < h; ++j) {
				for (int i = 0; i < w * 4; i += 4) {
					#define red screenData[i + (j*w*4) + 2]
					#define green screenData[i + (j*w*4) + 1]
					#define blue screenData[i + (j*w*4) + 0]

					if (IsMauSac(red, green, blue)) {
						mickeyY = Convert::ToDouble(textBox2->Text);
						target_x = (i / 4) - (w / 2);
						target_y = j - (h / 2) + mickeyY;
						/*cout << "find target" << endl;*/
						stop_loop = true;
						break;
					}
				}
				if (stop_loop) break;
			}
			
			if (!stop_loop) {
				target_x = 0;
				target_y = 0;
			}
		}
	}
	private: System::Void trackBar2_Scroll(System::Object^ sender, System::EventArgs^ e) {
		mickey_delay = trackBar2->Value;

		label12->Text = trackBar2->Value.ToString();
	}

	private: System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e) {
		/*int trackBarValue = trackBar1->Value;*/
		sm00th = trackBar1->Value;

		label2->Text = trackBar1->Value.ToString();
	}
	private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		only_mickey_X = checkBox1->Checked;
	}
};
}

