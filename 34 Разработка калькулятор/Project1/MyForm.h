#pragma once
#include <cmath>
#include "Function.h"

namespace Project1 {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form {
	public: MyForm(void) {
		InitializeComponent();
	}
	protected:~MyForm() {
		if (components) delete components;
	}
	
	private: System::Windows::Forms::Label^ funcxLabel;
	private: System::Windows::Forms::Label^ intervalFromLabel;
	private: System::Windows::Forms::Label^ intervalToLabel; 
	private: System::Windows::Forms::Label^ accuracyLabel;
	private: System::Windows::Forms::Label^ methodLabel;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ solveButton;
	private: System::Windows::Forms::TextBox^ x1TextBox;
	private: System::Windows::Forms::TextBox^ intervalFromTextBox;
	private: System::Windows::Forms::TextBox^ intervalToTextBox;
	private: System::Windows::Forms::TextBox^ accuracyTextBox;
	private: System::Windows::Forms::ComboBox^ methodComboBox;
	private: System::Windows::Forms::Label^ xLabel;
	private: System::Windows::Forms::TextBox^ x2TextBox;
	private: System::Windows::Forms::TextBox^ x3TextBox;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ answerTextBox;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void) {
			this->accuracyLabel = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->x1TextBox = (gcnew System::Windows::Forms::TextBox());
			this->funcxLabel = (gcnew System::Windows::Forms::Label());
			this->intervalToLabel = (gcnew System::Windows::Forms::Label());
			this->intervalFromTextBox = (gcnew System::Windows::Forms::TextBox());
			this->intervalToTextBox = (gcnew System::Windows::Forms::TextBox());
			this->accuracyTextBox = (gcnew System::Windows::Forms::TextBox());
			this->methodLabel = (gcnew System::Windows::Forms::Label());
			this->methodComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->intervalFromLabel = (gcnew System::Windows::Forms::Label());
			this->solveButton = (gcnew System::Windows::Forms::Button());
			this->xLabel = (gcnew System::Windows::Forms::Label());
			this->x2TextBox = (gcnew System::Windows::Forms::TextBox());
			this->x3TextBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->answerTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// accuracyLabel
			// 
			this->accuracyLabel->AutoSize = true;
			this->accuracyLabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->accuracyLabel->Location = System::Drawing::Point(552, 185);
			this->accuracyLabel->Name = L"accuracyLabel";
			this->accuracyLabel->Size = System::Drawing::Size(119, 21);
			this->accuracyLabel->TabIndex = 9;
			this->accuracyLabel->Text = L"Погрешность";
			this->accuracyLabel->Click += gcnew System::EventHandler(this, &MyForm::accuracyLabel_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(229, 148);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 24);
			this->label4->TabIndex = 10;
			// 
			// x1TextBox
			// 
			this->x1TextBox->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->x1TextBox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->x1TextBox->HideSelection = false;
			this->x1TextBox->Location = System::Drawing::Point(189, 103);
			this->x1TextBox->Name = L"x1TextBox";
			this->x1TextBox->Size = System::Drawing::Size(57, 39);
			this->x1TextBox->TabIndex = 11;
			this->x1TextBox->Text = L"6";
			this->x1TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->x1TextBox->TextChanged += gcnew System::EventHandler(this, &MyForm::x1TextBox_TextChanged);
			this->x1TextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::x1TextBox_KeyPress);
			// 
			// funcxLabel
			// 
			this->funcxLabel->AutoSize = true;
			this->funcxLabel->Font = (gcnew System::Drawing::Font(L"Arial", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->funcxLabel->Location = System::Drawing::Point(95, 104);
			this->funcxLabel->Name = L"funcxLabel";
			this->funcxLabel->Size = System::Drawing::Size(89, 36);
			this->funcxLabel->TabIndex = 23;
			this->funcxLabel->Text = L"f(x) =";
			// 
			// intervalToLabel
			// 
			this->intervalToLabel->AutoSize = true;
			this->intervalToLabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->intervalToLabel->Location = System::Drawing::Point(322, 187);
			this->intervalToLabel->Name = L"intervalToLabel";
			this->intervalToLabel->Size = System::Drawing::Size(34, 21);
			this->intervalToLabel->TabIndex = 28;
			this->intervalToLabel->Text = L"до:";
			// 
			// intervalFromTextBox
			// 
			this->intervalFromTextBox->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->intervalFromTextBox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->intervalFromTextBox->HideSelection = false;
			this->intervalFromTextBox->Location = System::Drawing::Point(189, 175);
			this->intervalFromTextBox->MaxLength = 4;
			this->intervalFromTextBox->Name = L"intervalFromTextBox";
			this->intervalFromTextBox->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->intervalFromTextBox->Size = System::Drawing::Size(102, 39);
			this->intervalFromTextBox->TabIndex = 29;
			this->intervalFromTextBox->Text = L"-10";
			this->intervalFromTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->intervalFromTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::intervalFromTextBox_KeyPress);
			// 
			// intervalToTextBox
			// 
			this->intervalToTextBox->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->intervalToTextBox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->intervalToTextBox->HideSelection = false;
			this->intervalToTextBox->Location = System::Drawing::Point(379, 175);
			this->intervalToTextBox->MaxLength = 4;
			this->intervalToTextBox->Name = L"intervalToTextBox";
			this->intervalToTextBox->Size = System::Drawing::Size(100, 39);
			this->intervalToTextBox->TabIndex = 30;
			this->intervalToTextBox->Text = L"10";
			this->intervalToTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->intervalToTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::intervalToTextBox_KeyPress);
			// 
			// accuracyTextBox
			// 
			this->accuracyTextBox->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->accuracyTextBox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->accuracyTextBox->HideSelection = false;
			this->accuracyTextBox->Location = System::Drawing::Point(697, 173);
			this->accuracyTextBox->MaxLength = 7;
			this->accuracyTextBox->Name = L"accuracyTextBox";
			this->accuracyTextBox->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->accuracyTextBox->Size = System::Drawing::Size(166, 39);
			this->accuracyTextBox->TabIndex = 31;
			this->accuracyTextBox->Text = L"0,001";
			this->accuracyTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->accuracyTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::accuracyTextBox_KeyPress);
			// 
			// methodLabel
			// 
			this->methodLabel->AutoSize = true;
			this->methodLabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->methodLabel->Location = System::Drawing::Point(552, 117);
			this->methodLabel->Name = L"methodLabel";
			this->methodLabel->Size = System::Drawing::Size(139, 21);
			this->methodLabel->TabIndex = 33;
			this->methodLabel->Text = L"Метод решения:";
			// 
			// methodComboBox
			// 
			this->methodComboBox->FormattingEnabled = true;
			this->methodComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"Метод половинного деления", L"Метод Ньютона",
					L"Метод итераций"
			});
			this->methodComboBox->Location = System::Drawing::Point(697, 117);
			this->methodComboBox->Name = L"methodComboBox";
			this->methodComboBox->Size = System::Drawing::Size(166, 21);
			this->methodComboBox->TabIndex = 34;
			// 
			// intervalFromLabel
			// 
			this->intervalFromLabel->AutoSize = true;
			this->intervalFromLabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->intervalFromLabel->Location = System::Drawing::Point(93, 184);
			this->intervalFromLabel->Name = L"intervalFromLabel";
			this->intervalFromLabel->Size = System::Drawing::Size(90, 21);
			this->intervalFromLabel->TabIndex = 8;
			this->intervalFromLabel->Text = L"Интервал ";
			// 
			// solveButton
			// 
			this->solveButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->solveButton->Location = System::Drawing::Point(379, 271);
			this->solveButton->Name = L"solveButton";
			this->solveButton->Size = System::Drawing::Size(158, 37);
			this->solveButton->TabIndex = 36;
			this->solveButton->Text = L"Вычислить";
			this->solveButton->UseVisualStyleBackColor = true;
			this->solveButton->Click += gcnew System::EventHandler(this, &MyForm::solveButton_Click);
			// 
			// xLabel
			// 
			this->xLabel->AutoSize = true;
			this->xLabel->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->xLabel->Location = System::Drawing::Point(109, 336);
			this->xLabel->Name = L"xLabel";
			this->xLabel->Size = System::Drawing::Size(40, 29);
			this->xLabel->TabIndex = 38;
			this->xLabel->Text = L"x: ";
			this->xLabel->Click += gcnew System::EventHandler(this, &MyForm::xLabel_Click);
			// 
			// x2TextBox
			// 
			this->x2TextBox->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->x2TextBox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->x2TextBox->HideSelection = false;
			this->x2TextBox->Location = System::Drawing::Point(314, 102);
			this->x2TextBox->Name = L"x2TextBox";
			this->x2TextBox->Size = System::Drawing::Size(57, 39);
			this->x2TextBox->TabIndex = 39;
			this->x2TextBox->Text = L"4";
			this->x2TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->x2TextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::x2TextBox_KeyPress);
			// 
			// x3TextBox
			// 
			this->x3TextBox->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->x3TextBox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->x3TextBox->HideSelection = false;
			this->x3TextBox->Location = System::Drawing::Point(430, 103);
			this->x3TextBox->Name = L"x3TextBox";
			this->x3TextBox->Size = System::Drawing::Size(72, 39);
			this->x3TextBox->TabIndex = 40;
			this->x3TextBox->Text = L"-3";
			this->x3TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->x3TextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::x3TextBox_KeyPress);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(249, 107);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(24, 27);
			this->label3->TabIndex = 41;
			this->label3->Text = L"x";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(375, 115);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(0, 21);
			this->label5->TabIndex = 42;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(267, 96);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(19, 21);
			this->label6->TabIndex = 43;
			this->label6->Text = L"2";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(287, 114);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(21, 21);
			this->label7->TabIndex = 44;
			this->label7->Text = L"+";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(377, 107);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(24, 27);
			this->label8->TabIndex = 45;
			this->label8->Text = L"x";
			// 
			// answerTextBox
			// 
			this->answerTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->answerTextBox->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->answerTextBox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->answerTextBox->HideSelection = false;
			this->answerTextBox->Location = System::Drawing::Point(162, 336);
			this->answerTextBox->MaxLength = 4;
			this->answerTextBox->Name = L"answerTextBox";
			this->answerTextBox->ReadOnly = true;
			this->answerTextBox->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->answerTextBox->Size = System::Drawing::Size(67, 34);
			this->answerTextBox->TabIndex = 46;
			this->answerTextBox->Text = L"0";
			this->answerTextBox->TextChanged += gcnew System::EventHandler(this, &MyForm::answerTextBox_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(403, 112);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(21, 21);
			this->label1->TabIndex = 47;
			this->label1->Text = L"+";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label2->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(78, 31);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(802, 25);
			this->label2->TabIndex = 48;
			this->label2->Text = L"Решение уравнения методами половинного деления, Ньютона или итераций ";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(989, 432);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->answerTextBox);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->x3TextBox);
			this->Controls->Add(this->x2TextBox);
			this->Controls->Add(this->xLabel);
			this->Controls->Add(this->solveButton);
			this->Controls->Add(this->methodComboBox);
			this->Controls->Add(this->methodLabel);
			this->Controls->Add(this->accuracyTextBox);
			this->Controls->Add(this->intervalToTextBox);
			this->Controls->Add(this->intervalFromTextBox);
			this->Controls->Add(this->intervalToLabel);
			this->Controls->Add(this->x1TextBox);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->accuracyLabel);
			this->Controls->Add(this->intervalFromLabel);
			this->Controls->Add(this->funcxLabel);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->MaximizeBox = false;
			this->MinimumSize = System::Drawing::Size(423, 357);
			this->Name = L"MyForm";
			this->Text = L"Калькулятор";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	String^ TorZ; // Точка или запятая

	private: void checkTextBox(System::Windows::Forms::TextBox^ textBox, System::Windows::Forms::KeyPressEventArgs^ e) {
		bool TZFound = false; // Разделительный знак найден?
		String^ FirstChar; //знаки + и - разрешены первым символом
		FirstChar = "";
		if (textBox->Text->Length > 0) FirstChar = textBox->Text->Substring(0, 1);
		bool badPosition = (FirstChar == L"-" && textBox->SelectionStart == 0);
		if (Char::IsDigit(e->KeyChar) == true) {
			if (badPosition) e->Handled = true;
			return; //Найдена цифра
		}
		if (e->KeyChar == (char)Keys::Back) return; //Найден BackSpace
		if (e->KeyChar == L'-') {
			if (FirstChar == L"-") textBox->Text = textBox->Text->Substring(1);
			if (textBox->SelectionStart == 0) return;
		}
		if (textBox->Text->IndexOf(TorZ) != -1) TZFound = true; //Найден разделитель целой и дробной частей
		if (TZFound == true) { e->Handled = true; return; } //Уже есть, второй не добавляем
		if (e->KeyChar.ToString() == TorZ && !badPosition) return; //А первый - можно
		e->Handled = true; //Не разрешать дальнейшую обработку
	}

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		methodComboBox->SelectedIndex = 0;
		TorZ = Globalization::NumberFormatInfo::CurrentInfo->NumberDecimalSeparator;
	}

	private: System::Void solveButton_Click(System::Object^ sender, System::EventArgs^ e) {
		double x1 = (Convert::ToDouble(x1TextBox->Text));
		double x2 = (Convert::ToDouble(x2TextBox->Text));
		double x3 = (Convert::ToDouble(x3TextBox->Text));
		FunctionData func(x1, x2, x3);

		double left = (Convert::ToDouble(intervalFromTextBox->Text));
		double right = (Convert::ToDouble(intervalToTextBox->Text));
		double eps = (Convert::ToDouble(accuracyTextBox->Text));
		int method = methodComboBox -> SelectedIndex;
		EquationData data(func, left, right, eps, method);
		try {
			double x = solve(data);
			answerTextBox->Text = Convert::ToString(x);
		} catch (const char* msg) {
			answerTextBox->Text = Convert::ToString(msg);
		}
		
	}

	private: System::Void x1TextBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		checkTextBox(x1TextBox, e);
	}

	private: System::Void x2TextBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		checkTextBox(x2TextBox, e);
	}
	private: System::Void x3TextBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		checkTextBox(x3TextBox, e);
	}
	private: System::Void intervalFromTextBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		checkTextBox(intervalFromTextBox, e);
	}
	private: System::Void intervalToTextBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		checkTextBox(intervalToTextBox, e);
	}
	private: System::Void accuracyTextBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		checkTextBox(accuracyTextBox, e);
	}
private: System::Void x1TextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void accuracyLabel_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void answerTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void xLabel_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
