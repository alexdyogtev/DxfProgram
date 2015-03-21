﻿#pragma once

#include "Cl_DxfLib.h"
#include "Cl_ObjectsLib.h"
#include "Cl_GraphicsLib.h"
#include "CheckDialog.h"

struct MOUSEPOINT {
	double x;
	double y;
};

struct DIFFERENT {
	int width;
	int height;
	int oldWidth;
	int oldHeight;
};

MOUSEPOINT dxfLocation;
MOUSEPOINT mouseLocation;
bool fileOpen;
DIFFERENT diffScreen;

namespace DxfProgram {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	// для работы с библиотекой OpenGL 
	using namespace Tao::OpenGl;
	// для работы с библиотекой FreeGLUT 
	using namespace Tao::FreeGlut;
	// для работы с элементом управления SimpleOpenGLControl 
	using namespace Tao::Platform::Windows; 

	DXF dxf;
	WORK *work = NULL;

	/// <summary>
	/// Сводка для Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			GLControl = gcnew GRAPHICS();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	private: GRAPHICS^ GLControl;
	private: float scaleNum;
	private: CheckDialog^ formCheckDialog;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem3;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem4;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem5;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Button^  buttonRight;
	private: System::Windows::Forms::Button^  buttonLeft;
	private: System::Windows::Forms::Button^  buttonBottom;
	private: System::Windows::Forms::Button^  buttonTop;
	private: System::Windows::Forms::Button^  buttonMinus;
	private: System::Windows::Forms::Button^  buttonPlus;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::DataGridView^  ObjectInf;
	private: Tao::Platform::Windows::SimpleOpenGlControl^  renderPanel;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::TextBox^  textBox1;



#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripMenuItem4 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem5 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->buttonRight = (gcnew System::Windows::Forms::Button());
			this->buttonLeft = (gcnew System::Windows::Forms::Button());
			this->buttonBottom = (gcnew System::Windows::Forms::Button());
			this->buttonTop = (gcnew System::Windows::Forms::Button());
			this->buttonMinus = (gcnew System::Windows::Forms::Button());
			this->buttonPlus = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->ObjectInf = (gcnew System::Windows::Forms::DataGridView());
			this->renderPanel = (gcnew Tao::Platform::Windows::SimpleOpenGlControl());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->menuStrip1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ObjectInf))->BeginInit();
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 30;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripMenuItem1, 
				this->toolStripMenuItem5});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
			this->menuStrip1->Size = System::Drawing::Size(910, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->toolStripMenuItem2, 
				this->toolStripMenuItem3, this->toolStripSeparator1, this->toolStripMenuItem4});
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(48, 20);
			this->toolStripMenuItem1->Text = L"Файл";
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(132, 22);
			this->toolStripMenuItem2->Text = L"Открыть";
			this->toolStripMenuItem2->Click += gcnew System::EventHandler(this, &Form1::toolStripMenuItem2_Click);
			// 
			// toolStripMenuItem3
			// 
			this->toolStripMenuItem3->Name = L"toolStripMenuItem3";
			this->toolStripMenuItem3->Size = System::Drawing::Size(132, 22);
			this->toolStripMenuItem3->Text = L"Сохранить";
			this->toolStripMenuItem3->Click += gcnew System::EventHandler(this, &Form1::toolStripMenuItem3_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(129, 6);
			// 
			// toolStripMenuItem4
			// 
			this->toolStripMenuItem4->Name = L"toolStripMenuItem4";
			this->toolStripMenuItem4->Size = System::Drawing::Size(132, 22);
			this->toolStripMenuItem4->Text = L"Выход";
			this->toolStripMenuItem4->Click += gcnew System::EventHandler(this, &Form1::toolStripMenuItem4_Click);
			// 
			// toolStripMenuItem5
			// 
			this->toolStripMenuItem5->Name = L"toolStripMenuItem5";
			this->toolStripMenuItem5->Size = System::Drawing::Size(74, 20);
			this->toolStripMenuItem5->Text = L"Проверки";
			this->toolStripMenuItem5->Click += gcnew System::EventHandler(this, &Form1::toolStripMenuItem5_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::White;
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel1->Location = System::Drawing::Point(0, 481);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(910, 20);
			this->panel1->TabIndex = 1;
			// 
			// textBox1
			// 
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->textBox1->BackColor = System::Drawing::Color::White;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->textBox1->Location = System::Drawing::Point(818, 0);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(92, 20);
			this->textBox1->TabIndex = 5;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->buttonRight);
			this->panel2->Controls->Add(this->buttonLeft);
			this->panel2->Controls->Add(this->buttonBottom);
			this->panel2->Controls->Add(this->buttonTop);
			this->panel2->Controls->Add(this->buttonMinus);
			this->panel2->Controls->Add(this->buttonPlus);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel2->Location = System::Drawing::Point(0, 24);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(47, 457);
			this->panel2->TabIndex = 2;
			// 
			// buttonRight
			// 
			this->buttonRight->Location = System::Drawing::Point(12, 161);
			this->buttonRight->Name = L"buttonRight";
			this->buttonRight->Size = System::Drawing::Size(23, 23);
			this->buttonRight->TabIndex = 5;
			this->buttonRight->Text = L"→";
			this->buttonRight->UseVisualStyleBackColor = true;
			this->buttonRight->Click += gcnew System::EventHandler(this, &Form1::buttonRight_Click);
			// 
			// buttonLeft
			// 
			this->buttonLeft->Location = System::Drawing::Point(12, 132);
			this->buttonLeft->Name = L"buttonLeft";
			this->buttonLeft->Size = System::Drawing::Size(23, 23);
			this->buttonLeft->TabIndex = 4;
			this->buttonLeft->Text = L"←";
			this->buttonLeft->UseVisualStyleBackColor = true;
			this->buttonLeft->Click += gcnew System::EventHandler(this, &Form1::buttonLeft_Click);
			// 
			// buttonBottom
			// 
			this->buttonBottom->Location = System::Drawing::Point(12, 103);
			this->buttonBottom->Name = L"buttonBottom";
			this->buttonBottom->Size = System::Drawing::Size(23, 23);
			this->buttonBottom->TabIndex = 3;
			this->buttonBottom->Text = L"↓";
			this->buttonBottom->UseVisualStyleBackColor = true;
			this->buttonBottom->Click += gcnew System::EventHandler(this, &Form1::buttonBottom_Click);
			// 
			// buttonTop
			// 
			this->buttonTop->Location = System::Drawing::Point(12, 74);
			this->buttonTop->Name = L"buttonTop";
			this->buttonTop->Size = System::Drawing::Size(23, 23);
			this->buttonTop->TabIndex = 2;
			this->buttonTop->Text = L"↑";
			this->buttonTop->UseVisualStyleBackColor = true;
			this->buttonTop->Click += gcnew System::EventHandler(this, &Form1::buttonTop_Click);
			// 
			// buttonMinus
			// 
			this->buttonMinus->Location = System::Drawing::Point(12, 32);
			this->buttonMinus->Name = L"buttonMinus";
			this->buttonMinus->Size = System::Drawing::Size(23, 23);
			this->buttonMinus->TabIndex = 1;
			this->buttonMinus->Text = L"-";
			this->buttonMinus->UseVisualStyleBackColor = true;
			this->buttonMinus->Click += gcnew System::EventHandler(this, &Form1::buttonMinus_Click);
			// 
			// buttonPlus
			// 
			this->buttonPlus->Location = System::Drawing::Point(12, 3);
			this->buttonPlus->Name = L"buttonPlus";
			this->buttonPlus->Size = System::Drawing::Size(23, 23);
			this->buttonPlus->TabIndex = 0;
			this->buttonPlus->Text = L"+";
			this->buttonPlus->UseVisualStyleBackColor = true;
			this->buttonPlus->Click += gcnew System::EventHandler(this, &Form1::buttonPlus_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Dock = System::Windows::Forms::DockStyle::Right;
			this->richTextBox1->Location = System::Drawing::Point(810, 24);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(100, 457);
			this->richTextBox1->TabIndex = 3;
			this->richTextBox1->Text = L"";
			this->richTextBox1->Visible = false;
			// 
			// ObjectInf
			// 
			this->ObjectInf->AllowUserToAddRows = false;
			this->ObjectInf->AllowUserToDeleteRows = false;
			this->ObjectInf->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->ObjectInf->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {this->Column1, this->Column2});
			this->ObjectInf->Dock = System::Windows::Forms::DockStyle::Left;
			this->ObjectInf->Location = System::Drawing::Point(47, 24);
			this->ObjectInf->Name = L"ObjectInf";
			this->ObjectInf->ReadOnly = true;
			this->ObjectInf->RowHeadersVisible = false;
			this->ObjectInf->Size = System::Drawing::Size(250, 457);
			this->ObjectInf->TabIndex = 0;
			this->ObjectInf->SizeChanged += gcnew System::EventHandler(this, &Form1::ObjectInf_SizeChanged);
			// 
			// renderPanel
			// 
			this->renderPanel->AccumBits = static_cast<System::Byte>(0);
			this->renderPanel->AutoCheckErrors = false;
			this->renderPanel->AutoFinish = false;
			this->renderPanel->AutoMakeCurrent = true;
			this->renderPanel->AutoSwapBuffers = true;
			this->renderPanel->BackColor = System::Drawing::Color::White;
			this->renderPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->renderPanel->ColorBits = static_cast<System::Byte>(32);
			this->renderPanel->DepthBits = static_cast<System::Byte>(16);
			this->renderPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->renderPanel->Location = System::Drawing::Point(297, 24);
			this->renderPanel->Name = L"renderPanel";
			this->renderPanel->Size = System::Drawing::Size(513, 457);
			this->renderPanel->StencilBits = static_cast<System::Byte>(0);
			this->renderPanel->TabIndex = 0;
			this->renderPanel->SizeChanged += gcnew System::EventHandler(this, &Form1::renderPanel_SizeChanged);
			this->renderPanel->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::renderPanel_MouseDown);
			this->renderPanel->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::renderPanel_MouseMove);
			this->renderPanel->MouseWheel += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::renderPanel_MouseWheel);
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Свойство";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			this->Column1->Width = 123;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Значение";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			this->Column2->Width = 123;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(910, 501);
			this->Controls->Add(this->renderPanel);
			this->Controls->Add(this->ObjectInf);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"DxfReader";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->SizeChanged += gcnew System::EventHandler(this, &Form1::Form1_SizeChanged);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ObjectInf))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				scaleNum = 1;
				fileOpen = false;
				diffScreen.width = 0;
				diffScreen.height = 0;
				diffScreen.oldWidth = renderPanel->Width;
				diffScreen.oldHeight = renderPanel->Height;
				GLControl->GetOpenGlControl(renderPanel);
				GLControl->InitGL();

				dxfLocation.x = 0;
				dxfLocation.y = 0;

			if(!dxf.Open("DxfFiles\\circles.dxf")) {ShowErr(1); return;}
			int err = 0;
			if((err = dxf.Read()) != 0) {ShowErr(2); return;}
			work = new WORK(dxf._Section);
			fileOpen = true;
			richTextBox1->Text = "";
			Painting();
				

			}
private: void Painting() {
			unsigned int i;
			if(work && !work->Section.Entities.Lines.empty()) for(i=0; i<work->Section.Entities.Lines.size(); i++)
				GLControl->DrawLine(
					work->Section.Entities.Lines[i].p[0].x,
					work->Section.Entities.Lines[i].p[0].y,
					work->Section.Entities.Lines[i].p[1].x,
					work->Section.Entities.Lines[i].p[1].y
				);

			if(work && !work->Section.Entities.Circles.empty()) for(i=0; i<work->Section.Entities.Circles.size(); i++) {
				if(work->Section.Entities.Circles[i].current) {
					GLControl->SetColor(0.0, 0.0, 1.0);
					GLControl->DrawPoint(work->Section.Entities.Circles[i].p.x, work->Section.Entities.Circles[i].p.y, 2.0);
				}
				GLControl->DrawCircle(
					work->Section.Entities.Circles[i].p.x,
					work->Section.Entities.Circles[i].p.y,
					work->Section.Entities.Circles[i].r
				);
				if(work->Section.Entities.Circles[i].current) GLControl->SetColor(0.0, 0.0, 0.0);
			}

			/*if(work && !work->errPoints.empty()) {
				bool fl;
				if(richTextBox1->Text == "") fl = true;
				else fl = false;
				for(i=0; i<work->errPoints.size(); i++) {
					GLControl->DrawErrorPoint(work->errPoints[i].x, work->errPoints[i].y, work->errPointR);
					if(fl) richTextBox1->Text += work->errPoints[i].type + "\n" + work->errPoints[i].x + "\n" + work->errPoints[i].y + "\n\n";
				}
			}*/

			if(work && !work->ErrPoints.empty()) for(i=0; i<work->ErrPoints.size(); i++) {
				//bool fl;
				//if(richTextBox1->Text == "") fl = true;
				//else fl = false;

				if(work->ErrPoints[i].current) {
					GLControl->SetColor(0.0, 1.0, 0.0);
					GLControl->DrawPoint(work->ErrPoints[i].x, work->ErrPoints[i].y, 2.0);
				}
				else GLControl->SetColor(1.0, 0.0, 0.0);
				
				//GLControl->DrawErrorPoint(work->ErrPoints[i].x, work->ErrPoints[i].y, work->errPointR);
				GLControl->DrawCircle(
					work->ErrPoints[i].x,
					work->ErrPoints[i].y,
					work->errPointR
				);
				//if(fl) richTextBox1->Text += work->ErrPoints[i].type + "\n" + work->ErrPoints[i].x + "\n" + work->ErrPoints[i].y + "\n\n";
				
				GLControl->SetColor(0.0, 0.0, 0.0);
			}

			if(work && !work->Section.Entities.Ellipses.empty()) for(i=0; i<work->Section.Entities.Ellipses.size(); i++) {
				GLControl->DrawEllipse(
					work->Section.Entities.Ellipses[i].p.x,
					work->Section.Entities.Ellipses[i].p.y,
					work->Section.Entities.Ellipses[i].width,
					work->Section.Entities.Ellipses[i].height,
					work->Section.Entities.Ellipses[i].angle
				);
			}

			if(work && !work->Section.Entities.Arcs.empty()) for(i=0; i<work->Section.Entities.Arcs.size(); i++) {
				GLControl->DrawArc(
					work->Section.Entities.Arcs[i].p.x,
					work->Section.Entities.Arcs[i].p.y,
					work->Section.Entities.Arcs[i].r,
					work->Section.Entities.Arcs[i].angleStart,
					work->Section.Entities.Arcs[i].angleEnd
				);
			}

			GLControl->PrintCursor(0, 0);
		}

private: System::Void toolStripMenuItem2_Click(System::Object^  sender, System::EventArgs^  e) {
				openFileDialog1->InitialDirectory = System::IO::Directory::GetCurrentDirectory() + "\\DxfFiles";
				openFileDialog1->Filter = "dxf files (*.dxf)|*.dxf|bmp files (*.bmp)|*.bmp";
				openFileDialog1->FilterIndex = 1;
				openFileDialog1->FileName = "";
				openFileDialog1->Multiselect = false;
				if(openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK){
					string name = Sysstr2str(openFileDialog1->FileName);
					if(name[name.length() - 1] == 'p') {
						MessageBox::Show("Open bmp file.");
						/*
							Юркина функция открытия bmp
						*/
					}
					if(!dxf.Open(Sysstr2str(openFileDialog1->FileName))) {ShowErr(1); return;}
					int err = 0;
					if((err = dxf.Read()) != 0) {ShowErr(2); return;}
					work = new WORK(dxf._Section);
					fileOpen = true;
					richTextBox1->Text = "";
					Painting();
				}
		 }
private: System::Void toolStripMenuItem3_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(dxf.SaveErrorPoints()) MessageBox::Show("Записано");
			 else MessageBox::Show("Ошибка записи");
			 /*
				Дашкина функция сохранения в БД
			 */
		 }
private: System::Void toolStripMenuItem5_Click(System::Object^  sender, System::EventArgs^  e) {
			 richTextBox1->Text = "";
			 formCheckDialog = gcnew CheckDialog(work);
			 formCheckDialog->Show();
			 formCheckDialog->Activate();
			 formCheckDialog->Focus();
		 }

private: System::Void toolStripMenuItem4_Click(System::Object^  sender, System::EventArgs^  e) {
			 Application::Exit();
		 }

private: string Sysstr2str(String ^str) {
	string str1 = "";
	for(int i=0; i<str->Length; i++) str1 += (char)str[i];
	return str1;
}

private: void ShowErr(int number) {
	switch(number) {
		case 1: MessageBox::Show("Ошибка открытия файла.");
	}
}

private: void ShowErr(int number, int errRead) {
	switch(number) {
		case 2: MessageBox::Show("Ошибка чтения файла #" + errRead + ".");
	}
}

private: System::Void buttonPlus_Click(System::Object^  sender, System::EventArgs^  e) {
			 GLControl->Scale(1);
			 scaleNum *= 2;
		 }
private: System::Void buttonMinus_Click(System::Object^  sender, System::EventArgs^  e) {
			 GLControl->Scale(-1);
			 scaleNum /= 2;
		 }
private: System::Void buttonTop_Click(System::Object^  sender, System::EventArgs^  e) {
			 GLControl->Translate(0, 10);
			 dxfLocation.y += 10 * scaleNum;
		 }
private: System::Void buttonBottom_Click(System::Object^  sender, System::EventArgs^  e) {
			 GLControl->Translate(0, -10);
			 dxfLocation.y -= 10 * scaleNum;
		 }
private: System::Void buttonLeft_Click(System::Object^  sender, System::EventArgs^  e) {
			 GLControl->Translate(-10, 0);
			 dxfLocation.x -= 10 * scaleNum;
		 }
private: System::Void buttonRight_Click(System::Object^  sender, System::EventArgs^  e) {
			 GLControl->Translate(10, 0);
			 dxfLocation.x += 10 * scaleNum;
		 }
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
			 if(GLControl->IsInit) {
				 GLControl->Render();
				 Painting();
				 GLControl->SwapBuffers();
			 }
		 }
private: System::Void renderPanel_SizeChanged(System::Object^  sender, System::EventArgs^  e) {
			 GLControl->Resize(renderPanel->Width, renderPanel->Height);
		 }

int ConvertX(int x) { return (x - renderPanel->Width/2); }
int ConvertY(int y) { return (renderPanel->Height/2 - y); }

Point point;

private: System::Void renderPanel_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			if(e->Button == System::Windows::Forms::MouseButtons::Left) {
				point = e->Location;
				if(fileOpen) work->ClickOnObject(
					(mouseLocation.x - dxfLocation.x) / scaleNum,
					(mouseLocation.y - dxfLocation.y) / scaleNum,
					scaleNum, ObjectInf
				);
			}
		}
private: System::Void renderPanel_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if(e->Button == System::Windows::Forms::MouseButtons::Left) {
				 double dx = (ConvertX(e->X) - ConvertX(point.X)) / scaleNum;
				 double dy = (ConvertY(e->Y) - ConvertY(point.Y)) / scaleNum;
				 GLControl->Translate(dx, dy);
				 dxfLocation.x += dx * scaleNum;
				 dxfLocation.y += dy * scaleNum;
				 point.X = e->X;
				 point.Y = e->Y;
			 }
			 mouseLocation.x = ConvertX(e->X);
			 mouseLocation.y = ConvertY(e->Y);
			 int x = (int)((mouseLocation.x - dxfLocation.x) / scaleNum);
			 int y = (int)((mouseLocation.y - dxfLocation.y) / scaleNum);
			 textBox1->Text = (x) + " " + (y);
			 //textBox2->Text = mouseLocation.x + " " + mouseLocation.y;
			 //textBox3->Text = dxfLocation.x + " " + dxfLocation.y;
		 }
private: System::Void renderPanel_MouseWheel(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if(e->Delta > 0) { GLControl->Scale(1); scaleNum *= 2; }
			 else { GLControl->Scale(-1); scaleNum /= 2; }
		 }

void table_SizeChaged() {
	for(int i=0; i<ObjectInf->ColumnCount; i++) ObjectInf->Columns[i]->Width = (ObjectInf->Width)/ObjectInf->ColumnCount - 2;
}

private: System::Void Form1_SizeChanged(System::Object^  sender, System::EventArgs^  e) {
			 table_SizeChaged();
		 }
private: System::Void ObjectInf_SizeChanged(System::Object^  sender, System::EventArgs^  e) {
			 table_SizeChaged();
		 }
};
}