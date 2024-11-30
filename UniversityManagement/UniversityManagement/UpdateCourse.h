#pragma once

namespace UniversityManagement {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for UpdateCourse
	/// </summary>
	public ref class UpdateCourse : public System::Windows::Forms::Form
	{
		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		DataTable^ sqlDt = gcnew DataTable();
		MySqlDataAdapter^ sqlDtA = gcnew MySqlDataAdapter();
	private: System::Windows::Forms::ComboBox^ something;
	private: System::Windows::Forms::TextBox^ credits;
		   MySqlDataReader^ sqlRd;
	public:
		UpdateCourse(void)
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
		~UpdateCourse()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ update;
	protected:

	private: System::Windows::Forms::TextBox^ CourseID;
	protected:

	private: System::Windows::Forms::Label^ label5;


	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ maxEnrollment;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ semester;
	private: System::Windows::Forms::Label^ label6;


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
			this->update = (gcnew System::Windows::Forms::Button());
			this->CourseID = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->maxEnrollment = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->semester = (gcnew System::Windows::Forms::ComboBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->something = (gcnew System::Windows::Forms::ComboBox());
			this->credits = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// update
			// 
			this->update->Location = System::Drawing::Point(213, 323);
			this->update->Name = L"update";
			this->update->Size = System::Drawing::Size(75, 23);
			this->update->TabIndex = 27;
			this->update->Text = L"Update";
			this->update->UseVisualStyleBackColor = true;
			this->update->Click += gcnew System::EventHandler(this, &UpdateCourse::update_Click);
			// 
			// CourseID
			// 
			this->CourseID->Location = System::Drawing::Point(290, 146);
			this->CourseID->Name = L"CourseID";
			this->CourseID->Size = System::Drawing::Size(237, 20);
			this->CourseID->TabIndex = 26;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(129, 149);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(54, 13);
			this->label5->TabIndex = 25;
			this->label5->Text = L"Course ID";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(129, 265);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(39, 13);
			this->label4->TabIndex = 23;
			this->label4->Text = L"Credits";
			// 
			// maxEnrollment
			// 
			this->maxEnrollment->Location = System::Drawing::Point(290, 216);
			this->maxEnrollment->Name = L"maxEnrollment";
			this->maxEnrollment->Size = System::Drawing::Size(237, 20);
			this->maxEnrollment->TabIndex = 22;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(128, 223);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(77, 13);
			this->label3->TabIndex = 20;
			this->label3->Text = L"Max Enrolment";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(129, 187);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 13);
			this->label2->TabIndex = 19;
			this->label2->Text = L"Semester";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Forte", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(209, 88);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(141, 21);
			this->label1->TabIndex = 18;
			this->label1->Text = L"Update Course";
			// 
			// semester
			// 
			this->semester->FormattingEnabled = true;
			this->semester->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Spring", L"Fall" });
			this->semester->Location = System::Drawing::Point(290, 184);
			this->semester->Name = L"semester";
			this->semester->Size = System::Drawing::Size(237, 21);
			this->semester->TabIndex = 28;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(129, 297);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(56, 13);
			this->label6->TabIndex = 29;
			this->label6->Text = L"Availability";
			// 
			// something
			// 
			this->something->FormattingEnabled = true;
			this->something->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"true", L"false" });
			this->something->Location = System::Drawing::Point(290, 289);
			this->something->Name = L"something";
			this->something->Size = System::Drawing::Size(237, 21);
			this->something->TabIndex = 32;
			// 
			// credits
			// 
			this->credits->Location = System::Drawing::Point(290, 258);
			this->credits->Name = L"credits";
			this->credits->Size = System::Drawing::Size(237, 20);
			this->credits->TabIndex = 33;
			// 
			// UpdateCourse
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(655, 435);
			this->Controls->Add(this->credits);
			this->Controls->Add(this->something);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->semester);
			this->Controls->Add(this->update);
			this->Controls->Add(this->CourseID);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->maxEnrollment);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"UpdateCourse";
			this->Text = L"UpdateCourse";
			this->Load += gcnew System::EventHandler(this, &UpdateCourse::UpdateCourse_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void UpdateCourse_Load(System::Object^ sender, System::EventArgs^ e) {
	}
		   System::Void update_Click(System::Object^ sender, System::EventArgs^ e) {
			   sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password=;database=universityrecords";

			   try {
				   sqlConn->Open();

				   // Get values from fields
				   String^ courseId = CourseID->Text;
				   String^ semesterValue = semester->Text;
				   String^ maxEnroll = maxEnrollment->Text;
				   String^ creditsValue = credits->Text;
				   String^ available = something->SelectedItem->ToString();

				   // Validate input
				   if (courseId->Length == 0 || semesterValue->Length == 0 || maxEnroll->Length == 0 || creditsValue->Length == 0 || available->Length == 0) {
					   MessageBox::Show("All fields must be filled out before updating.", "Validation Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					   return;
				   }

				   // Prepare SQL query
				   String^ query = "UPDATE courses SET Semester = @Semester, MaxEnrollment = @MaxEnrollment, Credits = @Credits, Availability = @Availability WHERE CourseID = @CourseID";

				   sqlCmd->Connection = sqlConn;
				   sqlCmd->CommandText = query;
				   sqlCmd->Parameters->AddWithValue("@CourseID", courseId);
				   sqlCmd->Parameters->AddWithValue("@Semester", semesterValue);
				   sqlCmd->Parameters->AddWithValue("@MaxEnrollment", maxEnroll);
				   sqlCmd->Parameters->AddWithValue("@Credits", creditsValue);
				   sqlCmd->Parameters->AddWithValue("@Availability", available);

				   // Execute the command
				   int rowsAffected = sqlCmd->ExecuteNonQuery();
				   if (rowsAffected > 0) {
					   MessageBox::Show("Course updated successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
				   }
				   else {
					   MessageBox::Show("No course found with the given Course ID.", "Update Failed", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				   }

				   // Clear fields
				   CourseID->Clear();
				   semester->SelectedIndex = -1;
				   maxEnrollment->Clear();
				   credits->Clear();
				   something->SelectedIndex = -1;
			   }
			   catch (Exception^ ex) {
				   MessageBox::Show("Error while updating course details: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			   }
			   finally {
				   sqlConn->Close();
				   sqlCmd->Parameters->Clear();
			   }
		   }
};

}
