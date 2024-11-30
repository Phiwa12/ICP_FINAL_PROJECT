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
	/// Summary for EnterGrades
	/// </summary>
	public ref class EnterGrades : public System::Windows::Forms::Form
	{
		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		DataTable^ sqlDt = gcnew DataTable();
		MySqlDataAdapter^ sqlDtA = gcnew MySqlDataAdapter();
		MySqlDataReader^ sqlRd;
		String^ userid;
	public:
		EnterGrades(String^ id)
		{
			InitializeComponent();
			userid = id;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~EnterGrades()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ studentId;
	private: System::Windows::Forms::Button^ submit;




	private: System::Windows::Forms::ComboBox^ grade;
	private: System::Windows::Forms::TextBox^ courseId;




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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->studentId = (gcnew System::Windows::Forms::TextBox());
			this->submit = (gcnew System::Windows::Forms::Button());
			this->grade = (gcnew System::Windows::Forms::ComboBox());
			this->courseId = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(253, 67);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(172, 31);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Enter Grades";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(177, 167);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(58, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Student ID";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(177, 216);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(40, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Course";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(177, 261);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(36, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Grade";
			// 
			// studentId
			// 
			this->studentId->Location = System::Drawing::Point(284, 160);
			this->studentId->Name = L"studentId";
			this->studentId->Size = System::Drawing::Size(189, 20);
			this->studentId->TabIndex = 4;
			// 
			// submit
			// 
			this->submit->Location = System::Drawing::Point(284, 308);
			this->submit->Name = L"submit";
			this->submit->Size = System::Drawing::Size(75, 23);
			this->submit->TabIndex = 7;
			this->submit->Text = L"Submit";
			this->submit->UseVisualStyleBackColor = true;
			this->submit->Click += gcnew System::EventHandler(this, &EnterGrades::submit_Click);
			// 
			// grade
			// 
			this->grade->FormattingEnabled = true;
			this->grade->Items->AddRange(gcnew cli::array< System::Object^  >(10) {
				L"A+", L"A", L"B+", L"B", L"C+", L"C", L"D+", L"D",
					L"E", L"F"
			});
			this->grade->Location = System::Drawing::Point(284, 253);
			this->grade->Name = L"grade";
			this->grade->Size = System::Drawing::Size(189, 21);
			this->grade->TabIndex = 9;
			// 
			// courseId
			// 
			this->courseId->Location = System::Drawing::Point(284, 209);
			this->courseId->Name = L"courseId";
			this->courseId->Size = System::Drawing::Size(189, 20);
			this->courseId->TabIndex = 10;
			// 
			// EnterGrades
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(742, 461);
			this->Controls->Add(this->courseId);
			this->Controls->Add(this->grade);
			this->Controls->Add(this->submit);
			this->Controls->Add(this->studentId);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"EnterGrades";
			this->Text = L"EnterGrades";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void treeView1_AfterSelect(System::Object^ sender, System::Windows::Forms::TreeViewEventArgs^ e) {
	}
private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void submit_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		// Validate input
		if (String::IsNullOrEmpty(studentId->Text) || String::IsNullOrEmpty(courseId->Text) || String::IsNullOrEmpty(grade->Text)) {
			MessageBox::Show("Please fill in all fields.", "Validation Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// Connect to the database
		sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password=;database=universityrecords";
		sqlConn->Open();

		// Check if the faculty is authorized to manage grades for the specified course
		String^ checkPermissionQuery =
			"SELECT COUNT(*) FROM CourseFaculty "
			"WHERE CourseID = @CourseID AND FacultyID = @FacultyID;";
		sqlCmd->Connection = sqlConn;
		sqlCmd->CommandText = checkPermissionQuery;
		sqlCmd->Parameters->Clear();
		sqlCmd->Parameters->AddWithValue("@CourseID", courseId->Text);
		sqlCmd->Parameters->AddWithValue("@FacultyID", userid);

		int permissionCount = Convert::ToInt32(sqlCmd->ExecuteScalar());
		if (permissionCount == 0) {
			MessageBox::Show("You are not authorized to enter grades for this course.", "Permission Denied", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// Update or insert the grade in the Enrollments table
		String^ updateGradeQuery =
			"UPDATE Enrollments "
			"SET Grade = @Grade "
			"WHERE StudentID = @StudentID AND CourseID = @CourseID;";
		sqlCmd->CommandText = updateGradeQuery;
		sqlCmd->Parameters->Clear();
		sqlCmd->Parameters->AddWithValue("@StudentID", studentId->Text);
		sqlCmd->Parameters->AddWithValue("@CourseID", courseId->Text);
		sqlCmd->Parameters->AddWithValue("@Grade", grade->Text);

		int rowsAffected = sqlCmd->ExecuteNonQuery();
		if (rowsAffected > 0) {
			MessageBox::Show("Grade entered successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else {
			MessageBox::Show("Failed to update the grade. Please check the Student ID and Course ID.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	finally {
		sqlConn->Close();
	}
}

};
}
