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
	/// Summary for AddFaculty1
	/// </summary>
	public ref class AddFaculty1 : public System::Windows::Forms::Form
	{
		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		DataTable^ sqlDt = gcnew DataTable();
		MySqlDataAdapter^ sqlDtA = gcnew MySqlDataAdapter();
		MySqlDataReader^ sqlRd;
	public:
		AddFaculty1(void)
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
			confirmPass->Text = "";
			department->Text = "";

		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddFaculty1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::DateTimePicker^ dob;
	protected:

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ submit;

	private: System::Windows::Forms::TextBox^ confirmPass;

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
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::DateTimePicker^ employmentdate;

	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::ComboBox^ department;


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
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->dob = (gcnew System::Windows::Forms::DateTimePicker());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->submit = (gcnew System::Windows::Forms::Button());
			this->confirmPass = (gcnew System::Windows::Forms::TextBox());
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
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->employmentdate = (gcnew System::Windows::Forms::DateTimePicker());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->department = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(244, 195);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(66, 13);
			this->label7->TabIndex = 29;
			this->label7->Text = L"Date of Birth";
			// 
			// dob
			// 
			this->dob->Location = System::Drawing::Point(420, 189);
			this->dob->Name = L"dob";
			this->dob->Size = System::Drawing::Size(237, 20);
			this->dob->TabIndex = 28;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(262, 397);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 27;
			this->button2->Text = L"Cancel";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// submit
			// 
			this->submit->Location = System::Drawing::Point(482, 397);
			this->submit->Name = L"submit";
			this->submit->Size = System::Drawing::Size(75, 23);
			this->submit->TabIndex = 26;
			this->submit->Text = L"Submit";
			this->submit->UseVisualStyleBackColor = true;
			this->submit->Click += gcnew System::EventHandler(this, &AddFaculty1::submit_Click);
			// 
			// confirmPass
			// 
			this->confirmPass->Location = System::Drawing::Point(420, 350);
			this->confirmPass->Name = L"confirmPass";
			this->confirmPass->Size = System::Drawing::Size(237, 20);
			this->confirmPass->TabIndex = 25;
			// 
			// password
			// 
			this->password->Location = System::Drawing::Point(420, 320);
			this->password->Name = L"password";
			this->password->Size = System::Drawing::Size(237, 20);
			this->password->TabIndex = 24;
			// 
			// email
			// 
			this->email->Location = System::Drawing::Point(420, 256);
			this->email->Name = L"email";
			this->email->Size = System::Drawing::Size(237, 20);
			this->email->TabIndex = 23;
			// 
			// lastname
			// 
			this->lastname->Location = System::Drawing::Point(420, 146);
			this->lastname->Name = L"lastname";
			this->lastname->Size = System::Drawing::Size(237, 20);
			this->lastname->TabIndex = 22;
			// 
			// firstname
			// 
			this->firstname->Location = System::Drawing::Point(420, 114);
			this->firstname->Name = L"firstname";
			this->firstname->Size = System::Drawing::Size(237, 20);
			this->firstname->TabIndex = 21;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(241, 357);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(93, 13);
			this->label6->TabIndex = 20;
			this->label6->Text = L"Comfirm Password";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(241, 327);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(53, 13);
			this->label5->TabIndex = 19;
			this->label5->Text = L"Password";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(244, 259);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(32, 13);
			this->label4->TabIndex = 18;
			this->label4->Text = L"Email";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(244, 153);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(58, 13);
			this->label3->TabIndex = 17;
			this->label3->Text = L"Last Name";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(244, 114);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(57, 13);
			this->label2->TabIndex = 16;
			this->label2->Text = L"First Name";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Forte", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(337, 73);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(125, 21);
			this->label1->TabIndex = 15;
			this->label1->Text = L"Add Faculty";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(244, 226);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(90, 13);
			this->label8->TabIndex = 30;
			this->label8->Text = L"Employment Date";
			// 
			// employmentdate
			// 
			this->employmentdate->Location = System::Drawing::Point(420, 219);
			this->employmentdate->Name = L"employmentdate";
			this->employmentdate->Size = System::Drawing::Size(237, 20);
			this->employmentdate->TabIndex = 31;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(244, 300);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(62, 13);
			this->label9->TabIndex = 32;
			this->label9->Text = L"Department";
			// 
			// department
			// 
			this->department->FormattingEnabled = true;
			this->department->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Engineering", L"CSIS", L"Humanities" });
			this->department->Location = System::Drawing::Point(420, 296);
			this->department->Name = L"department";
			this->department->Size = System::Drawing::Size(237, 21);
			this->department->TabIndex = 33;
			// 
			// AddFaculty1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(901, 432);
			this->Controls->Add(this->department);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->employmentdate);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->dob);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->submit);
			this->Controls->Add(this->confirmPass);
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
			this->Name = L"AddFaculty1";
			this->Text = L"AddFaculty1";
			this->Load += gcnew System::EventHandler(this, &AddFaculty1::AddFaculty1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void AddFaculty1_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	//	   // Example using a SQL connection in C++/CLI (requires proper database access and reference to a DB provider)
		   void AddFaculty1::submit_Click(System::Object^ sender, System::EventArgs^ e)
		   {
			   sqlConn->ConnectionString = "datasource = localhost; port=3306;"
				   "username=root; password=""; database=universityrecords";
			   String^ firstNameF = firstname->Text->Trim();
			   String^ lastNameF = lastname->Text->Trim();
			   DateTime dateOfBirth = dob->Value;
			   DateTime employment = employmentdate->Value;
			   String^ emailF = email->Text->Trim();
			   String^ passwordF = password->Text->Trim();
			   String^ confirmPassW = confirmPass->Text->Trim();
			   String^ departmentF = department->SelectedItem->ToString();
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
			   if (confirmPassW != passwordF) {
				   MessageBox::Show("Passwords do not match, please check.");
				   isValid = false;
			   }
			   if (!emailF->Contains("@") || !emailF->Contains(".")) {
				   MessageBox::Show("Please enter a valid email address.");
				   isValid = false;
			   }

			   if (isValid) {
				   try {
					   // Open connection first
					   sqlConn->Open();

					   // Insert into users table
					   sqlCmd->Connection = sqlConn;
					   sqlCmd->CommandText = "INSERT INTO users (FirstName, LastName, DateOfBirth, Email, Password, role) "
						   "VALUES (@firstName, @lastName, @dateOfBirth, @emailA, @passwordA, 'faculty');"
						   "SELECT LAST_INSERT_ID();";  // Get the last inserted UserID

					   // Add parameters for users table
					   sqlCmd->Parameters->AddWithValue("@firstName", firstNameF);
					   sqlCmd->Parameters->AddWithValue("@lastName", lastNameF);
					   sqlCmd->Parameters->AddWithValue("@dateOfBirth", dateOfBirth);
					   sqlCmd->Parameters->AddWithValue("@emailA", emailF);
					   sqlCmd->Parameters->AddWithValue("@passwordA", passwordF);

					   // Execute the query and get the last inserted ID (UserID)
					   int userId = Convert::ToInt32(sqlCmd->ExecuteScalar());  // ExecuteScalar returns the value of the first column in the first row

					   // Insert into admin table using the UserID
					   sqlCmd->CommandText = "INSERT INTO faculty (FacultyID, Department, AppointmentDate) VALUES (@userId, @department, @enrollmentDate)";
	  				   sqlCmd->Parameters->Clear();  // Clear previous parameters
					   sqlCmd->Parameters->AddWithValue("@userId", userId);  // Add the UserID parameter
					   sqlCmd->Parameters->AddWithValue("@department", departmentF);  // Add the UserID parameter
					   sqlCmd->Parameters->AddWithValue("@enrollmentDate", employment);  // Add the UserID parameter

					   // Execute the insert for admin table
					   sqlCmd->ExecuteNonQuery();

				   // Clear input fields after successful insert
					   clearBoxes();
					   MessageBox::Show("Data inserted successfully!");


				   }
				   catch (Exception^ ex) {
					   MessageBox::Show("Inserting Data Failed: " + ex->Message);
				   }
				   finally {
					   sqlConn->Close();  // Ensure the connection is closed even if an exception occurs
				   }
			   }
	   }

};
}
