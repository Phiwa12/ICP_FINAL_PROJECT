#pragma once
#include "DeleteFaculty.h"
#include "AddStudent.h"
#include "UpdateUser.h"
namespace UniversityManagement {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for StudentManagement
	/// </summary>
	public ref class StudentManagement : public System::Windows::Forms::Form
	{
	public:
		StudentManagement(void)
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
		~StudentManagement()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button3;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button2;

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
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(314, 196);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(129, 23);
			this->button3->TabIndex = 18;
			this->button3->Text = L"Delete Student";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &StudentManagement::button3_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(77, 196);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(158, 23);
			this->button1->TabIndex = 16;
			this->button1->Text = L"Add Student";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &StudentManagement::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(204, 91);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(262, 31);
			this->label1->TabIndex = 15;
			this->label1->Text = L"Student Management";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(529, 196);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(129, 23);
			this->button2->TabIndex = 19;
			this->button2->Text = L"Update Student";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &StudentManagement::button2_Click);
			// 
			// StudentManagement
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(736, 381);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"StudentManagement";
			this->Text = L"StudentManagement";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		AddStudent^ addstu = gcnew AddStudent();
		addstu->Show();
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	DeleteFaculty^ delstu = gcnew DeleteFaculty();
	delstu->Show();
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	UpdateUser^ updateU = gcnew UpdateUser();
	updateU->Show();
}
};
}
