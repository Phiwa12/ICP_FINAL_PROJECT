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
	/// Summary for AddStudent
	/// </summary>
	public ref class AddStudent : public System::Windows::Forms::Form
	{
		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		DataTable^ sqlDt = gcnew DataTable();
		MySqlDataAdapter^ sqlDtA = gcnew MySqlDataAdapter();
		MySqlDataReader^ sqlRd;
	public:
		AddStudent(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		void clearBoxes() {
			email->Text = "";
			firstname->Text = "";
			lastname->Text = "";
			password->Text = "";
			comfirmpassW->Text = "";
			major->Text = "";

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddStudent()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DateTimePicker^ enrollmendate;
	protected:

	protected:
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::DateTimePicker^ dob;

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ submit;

	private: System::Windows::Forms::TextBox^ comfirmpassW;


	private: System::Windows::Forms::TextBox^ password;

	private: System::Windows::Forms::TextBox^ email;

	private: System::Windows::Forms::TextBox^ lastname;

	private: System::Windows::Forms::TextBox^ firstname;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::ComboBox^ major;



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
			this->enrollmendate = (gcnew System::Windows::Forms::DateTimePicker());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->dob = (gcnew System::Windows::Forms::DateTimePicker());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->submit = (gcnew System::Windows::Forms::Button());
			this->comfirmpassW = (gcnew System::Windows::Forms::TextBox());
			this->password = (gcnew System::Windows::Forms::TextBox());
			this->email = (gcnew System::Windows::Forms::TextBox());
			this->lastname = (gcnew System::Windows::Forms::TextBox());
			this->firstname = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->major = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// enrollmendate
			// 
			this->enrollmendate->Location = System::Drawing::Point(351, 255);
			this->enrollmendate->Name = L"enrollmendate";
			this->enrollmendate->Size = System::Drawing::Size(237, 20);
			this->enrollmendate->TabIndex = 33;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(190, 261);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(82, 13);
			this->label8->TabIndex = 32;
			this->label8->Text = L"Enrollment Date";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(190, 224);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(66, 13);
			this->label7->TabIndex = 31;
			this->label7->Text = L"Date of Birth";
			// 
			// dob
			// 
			this->dob->Location = System::Drawing::Point(351, 217);
			this->dob->Name = L"dob";
			this->dob->Size = System::Drawing::Size(237, 20);
			this->dob->TabIndex = 30;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(208, 444);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 29;
			this->button2->Text = L"Cancel";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// submit
			// 
			this->submit->Location = System::Drawing::Point(399, 444);
			this->submit->Name = L"submit";
			this->submit->Size = System::Drawing::Size(75, 23);
			this->submit->TabIndex = 28;
			this->submit->Text = L"Submit";
			this->submit->UseVisualStyleBackColor = true;
			this->submit->Click += gcnew System::EventHandler(this, &AddStudent::button1_Click);
			// 
			// comfirmpassW
			// 
			this->comfirmpassW->Location = System::Drawing::Point(351, 403);
			this->comfirmpassW->Name = L"comfirmpassW";
			this->comfirmpassW->Size = System::Drawing::Size(237, 20);
			this->comfirmpassW->TabIndex = 27;
			// 
			// password
			// 
			this->password->Location = System::Drawing::Point(351, 366);
			this->password->Name = L"password";
			this->password->Size = System::Drawing::Size(237, 20);
			this->password->TabIndex = 26;
			// 
			// email
			// 
			this->email->Location = System::Drawing::Point(351, 293);
			this->email->Name = L"email";
			this->email->Size = System::Drawing::Size(237, 20);
			this->email->TabIndex = 25;
			// 
			// lastname
			// 
			this->lastname->Location = System::Drawing::Point(351, 174);
			this->lastname->Name = L"lastname";
			this->lastname->Size = System::Drawing::Size(237, 20);
			this->lastname->TabIndex = 24;
			// 
			// firstname
			// 
			this->firstname->Location = System::Drawing::Point(351, 142);
			this->firstname->Name = L"firstname";
			this->firstname->Size = System::Drawing::Size(237, 20);
			this->firstname->TabIndex = 23;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(190, 403);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(93, 13);
			this->label6->TabIndex = 22;
			this->label6->Text = L"Comfirm Password";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(190, 373);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(53, 13);
			this->label5->TabIndex = 21;
			this->label5->Text = L"Password";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(190, 300);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(32, 13);
			this->label4->TabIndex = 20;
			this->label4->Text = L"Email";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(190, 181);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(58, 13);
			this->label3->TabIndex = 19;
			this->label3->Text = L"Last Name";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(186, 142);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(57, 13);
			this->label2->TabIndex = 18;
			this->label2->Text = L"First Name";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Forte", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(268, 101);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(125, 21);
			this->label1->TabIndex = 17;
			this->label1->Text = L"Add Student";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(190, 338);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(33, 13);
			this->label9->TabIndex = 34;
			this->label9->Text = L"Major";
			this->label9->Click += gcnew System::EventHandler(this, &AddStudent::label9_Click);
			// 
			// major
			// 
			this->major->FormattingEnabled = true;
			this->major->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"Computer Science", L"Business Administration", L"Computer Engineering",
					L"Mechanical Engineering", L"Electrical Engineering ", L"Mechatronics"
			});
			this->major->Location = System::Drawing::Point(353, 335);
			this->major->Name = L"major";
			this->major->Size = System::Drawing::Size(235, 21);
			this->major->TabIndex = 35;
			// 
			// AddStudent
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(775, 530);
			this->Controls->Add(this->major);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->enrollmendate);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->dob);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->submit);
			this->Controls->Add(this->comfirmpassW);
			this->Controls->Add(this->password);
			this->Controls->Add(this->email);
			this->Controls->Add(this->lastname);
			this->Controls->Add(this->firstname);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"AddStudent";
			this->Text = L"AddStudent";
			this->Load += gcnew System::EventHandler(this, &AddStudent::AddStudent_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label9_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	sqlConn->ConnectionString = "datasource = localhost; port=3306;"
		"username=root; password=""; database=universityrecords";
	String^ firstNameF = firstname->Text->Trim();
	String^ lastNameF = lastname->Text->Trim();
	DateTime dateOfBirth = dob->Value;
	DateTime enrollmentDate = enrollmendate->Value;
	String^ emailF = email->Text->Trim();
	String^ passwordF = password->Text->Trim();
	String^ confirmPassW = comfirmpassW->Text->Trim();
	String^ majorS = major->SelectedItem->ToString();
	bool isValid = true;

	if (firstNameF->Length == 0) {
		MessageBox::Show("Please enter the first name");
		isValid = false;
	}
	if (lastNameF->Length == 0) {
		MessageBox::Show("Please enter the last name");
		isValid = false;
	}
	if (emailF->Length == 0) {
		MessageBox::Show("Please enter the email");
		isValid = false;
	}
	if (passwordF->Length == 0) {
		MessageBox::Show("Please enter the password");
		isValid = false;
	}
	if (confirmPassW->Length == 0) {
		MessageBox::Show("Please confirm Password");
		isValid = false;
	}
	if (!passwordF->Equals(confirmPassW)) {
		MessageBox::Show("Passwords do not match, please check.");
		isValid = false;
	}
	if (major->SelectedItem == nullptr) {
		MessageBox::Show("Please select a major.");
		isValid = false;
	}
	if (!emailF->Contains("@") || !emailF->Contains(".")) {
		MessageBox::Show("Please enter a valid email address.");
		isValid = false;
	}

	if (isValid) {
		try {
			sqlConn->Open();

			// Insert into users table
			sqlCmd->Connection = sqlConn;
			sqlCmd->CommandText = "INSERT INTO users (FirstName, LastName, DateOfBirth, Email, Password, role) "
				"VALUES (@firstName, @lastName, @dateOfBirth, @emailA, @passwordA, 'student');";
			sqlCmd->Parameters->Clear();
			sqlCmd->Parameters->AddWithValue("@firstName", firstNameF);
			sqlCmd->Parameters->AddWithValue("@lastName", lastNameF);
			sqlCmd->Parameters->AddWithValue("@dateOfBirth", dateOfBirth);
			sqlCmd->Parameters->AddWithValue("@emailA", emailF);
			sqlCmd->Parameters->AddWithValue("@passwordA", passwordF);

			sqlCmd->ExecuteNonQuery();

			// Get the last inserted UserID
			sqlCmd->CommandText = "SELECT LAST_INSERT_ID();";
			int userId = Convert::ToInt32(sqlCmd->ExecuteScalar());

			// Insert into students table
			sqlCmd->CommandText = "INSERT INTO students (StudentID, Major, EnrollmentDate) "
				"VALUES (@userId, @major, @enrollmentDate);";
			sqlCmd->Parameters->Clear();
			sqlCmd->Parameters->AddWithValue("@userId", userId);
			sqlCmd->Parameters->AddWithValue("@major", majorS);
			sqlCmd->Parameters->AddWithValue("@enrollmentDate", enrollmentDate);

			sqlCmd->ExecuteNonQuery();

			// Insert into payments table
			sqlCmd->CommandText = "INSERT INTO payments (StudentID, Semester, TotalAmount, PaidAmount) "
				"VALUES (@userId, 'Spring', 70000, 0.0);";
			sqlCmd->Parameters->Clear();
			sqlCmd->Parameters->AddWithValue("@userId", userId);

			sqlCmd->ExecuteNonQuery();

			clearBoxes();
			MessageBox::Show("Student added successfully!");
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error: " + ex->Message);
		}
		finally {
			sqlConn->Close();
		}
	}
}
private: System::Void major_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void AddStudent_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
