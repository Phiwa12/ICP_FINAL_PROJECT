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
	/// Summary for UpdateUser
	/// </summary>
	public ref class UpdateUser : public System::Windows::Forms::Form
	{
		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		DataTable^ sqlDt = gcnew DataTable();
		MySqlDataAdapter^ sqlDtA = gcnew MySqlDataAdapter();
		MySqlDataReader^ sqlRd;
	public:
		UpdateUser(void)
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
		~UpdateUser()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ lastname;
	protected:

	private: System::Windows::Forms::TextBox^ firstname;
	protected:

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ email;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ userid;
	private: System::Windows::Forms::Button^ update;




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
			this->lastname = (gcnew System::Windows::Forms::TextBox());
			this->firstname = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->email = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->userid = (gcnew System::Windows::Forms::TextBox());
			this->update = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lastname
			// 
			this->lastname->Location = System::Drawing::Point(362, 177);
			this->lastname->Name = L"lastname";
			this->lastname->Size = System::Drawing::Size(237, 20);
			this->lastname->TabIndex = 12;
			// 
			// firstname
			// 
			this->firstname->Location = System::Drawing::Point(362, 145);
			this->firstname->Name = L"firstname";
			this->firstname->Size = System::Drawing::Size(237, 20);
			this->firstname->TabIndex = 11;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(200, 184);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(58, 13);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Last Name";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(201, 148);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(57, 13);
			this->label2->TabIndex = 9;
			this->label2->Text = L"First Name";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Forte", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(281, 49);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(119, 21);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Update User";
			// 
			// email
			// 
			this->email->Location = System::Drawing::Point(362, 219);
			this->email->Name = L"email";
			this->email->Size = System::Drawing::Size(237, 20);
			this->email->TabIndex = 14;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(201, 226);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(32, 13);
			this->label4->TabIndex = 13;
			this->label4->Text = L"Email";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(201, 110);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(43, 13);
			this->label5->TabIndex = 15;
			this->label5->Text = L"User ID";
			// 
			// userid
			// 
			this->userid->Location = System::Drawing::Point(362, 107);
			this->userid->Name = L"userid";
			this->userid->Size = System::Drawing::Size(237, 20);
			this->userid->TabIndex = 16;
			// 
			// update
			// 
			this->update->Location = System::Drawing::Point(285, 284);
			this->update->Name = L"update";
			this->update->Size = System::Drawing::Size(75, 23);
			this->update->TabIndex = 17;
			this->update->Text = L"Update";
			this->update->UseVisualStyleBackColor = true;
			this->update->Click += gcnew System::EventHandler(this, &UpdateUser::update_Click);
			// 
			// UpdateUser
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(790, 470);
			this->Controls->Add(this->update);
			this->Controls->Add(this->userid);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->email);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->lastname);
			this->Controls->Add(this->firstname);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"UpdateUser";
			this->Text = L"UpdateUser";
			this->Load += gcnew System::EventHandler(this, &UpdateUser::UpdateUser_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void UpdateUser_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void update_Click(System::Object^ sender, System::EventArgs^ e) {
	// Set up the connection string to your MySQL database
	sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password=;database=universityrecords";

	try {
		// Open the connection
		sqlConn->Open();

		// SQL query to update the user details based on the User ID
		String^ userId = userid->Text;
		String^ firstName = firstname->Text;
		String^ lastName = lastname->Text;

		if (userId == "" || firstName == "" || lastName == "") {
			MessageBox::Show("All fields must be filled out before updating.", "Validation Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		String^ query = "UPDATE users SET FirstName = @FirstName, LastName = @LastName WHERE UserID = @UserId";

		// Prepare the command with parameters
		sqlCmd->Connection = sqlConn;
		sqlCmd->CommandText = query;
		sqlCmd->Parameters->AddWithValue("@UserId", userId);
		sqlCmd->Parameters->AddWithValue("@FirstName", firstName);
		sqlCmd->Parameters->AddWithValue("@LastName", lastName);

		// Execute the update command
		int rowsAffected = sqlCmd->ExecuteNonQuery();

		if (rowsAffected > 0) {
			MessageBox::Show("User details updated successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else {
			MessageBox::Show("No user found with the given User ID.", "Update Failed", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}

		// Clear input fields
		userid->Clear();
		firstname->Clear();
		lastname->Clear();
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error while updating user details: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	finally {
		// Ensure the connection is closed
		sqlConn->Close();
		sqlCmd->Parameters->Clear(); // Clear parameters to avoid reuse issues
	}
}

};
}
