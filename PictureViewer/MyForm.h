#pragma once
#include "PictureLinkedList.h"

namespace PictureViewer {

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
		MyForm(void);
	
	private: 
		PictureLinkedList pictureList;
		int current_position = 0;
	private: System::Windows::Forms::Label^  lbl_current_position;
	private: System::Windows::Forms::ListView^  list_photos;

	private: System::Windows::Forms::TextBox^  txt_newImage;
			 
		//PictureNode *currentPicture;

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
	private: System::Windows::Forms::Button^  btn_prev;
	protected:
	private: System::Windows::Forms::Button^  btn_next;
	private: System::Windows::Forms::PictureBox^  pic_main;
	private: System::Windows::Forms::PictureBox^  pic_right;
	private: System::Windows::Forms::PictureBox^  pic_left;



	private: System::Windows::Forms::Button^  btn_add;
	private: System::Windows::Forms::Button^  btn_remove;

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
			this->btn_prev = (gcnew System::Windows::Forms::Button());
			this->btn_next = (gcnew System::Windows::Forms::Button());
			this->pic_main = (gcnew System::Windows::Forms::PictureBox());
			this->pic_right = (gcnew System::Windows::Forms::PictureBox());
			this->pic_left = (gcnew System::Windows::Forms::PictureBox());
			this->btn_add = (gcnew System::Windows::Forms::Button());
			this->btn_remove = (gcnew System::Windows::Forms::Button());
			this->txt_newImage = (gcnew System::Windows::Forms::TextBox());
			this->lbl_current_position = (gcnew System::Windows::Forms::Label());
			this->list_photos = (gcnew System::Windows::Forms::ListView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_main))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_right))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_left))->BeginInit();
			this->SuspendLayout();
			// 
			// btn_prev
			// 
			this->btn_prev->Location = System::Drawing::Point(13, 296);
			this->btn_prev->Name = L"btn_prev";
			this->btn_prev->Size = System::Drawing::Size(75, 23);
			this->btn_prev->TabIndex = 0;
			this->btn_prev->Text = L"Previous";
			this->btn_prev->UseVisualStyleBackColor = true;
			this->btn_prev->Click += gcnew System::EventHandler(this, &MyForm::btn_prev_Click);
			// 
			// btn_next
			// 
			this->btn_next->Location = System::Drawing::Point(409, 296);
			this->btn_next->Name = L"btn_next";
			this->btn_next->Size = System::Drawing::Size(75, 23);
			this->btn_next->TabIndex = 1;
			this->btn_next->Text = L"Next";
			this->btn_next->UseVisualStyleBackColor = true;
			this->btn_next->Click += gcnew System::EventHandler(this, &MyForm::btn_next_Click);
			// 
			// pic_main
			// 
			this->pic_main->Location = System::Drawing::Point(137, 12);
			this->pic_main->Name = L"pic_main";
			this->pic_main->Size = System::Drawing::Size(236, 242);
			this->pic_main->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pic_main->TabIndex = 2;
			this->pic_main->TabStop = false;
			this->pic_main->Click += gcnew System::EventHandler(this, &MyForm::pic_main_Click);
			// 
			// pic_right
			// 
			this->pic_right->Location = System::Drawing::Point(409, 93);
			this->pic_right->Name = L"pic_right";
			this->pic_right->Size = System::Drawing::Size(75, 99);
			this->pic_right->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pic_right->TabIndex = 3;
			this->pic_right->TabStop = false;
			this->pic_right->Click += gcnew System::EventHandler(this, &MyForm::btn_next_Click);
			// 
			// pic_left
			// 
			this->pic_left->Location = System::Drawing::Point(12, 93);
			this->pic_left->Name = L"pic_left";
			this->pic_left->Size = System::Drawing::Size(76, 99);
			this->pic_left->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pic_left->TabIndex = 4;
			this->pic_left->TabStop = false;
			this->pic_left->Click += gcnew System::EventHandler(this, &MyForm::btn_prev_Click);
			// 
			// btn_add
			// 
			this->btn_add->Location = System::Drawing::Point(298, 330);
			this->btn_add->Name = L"btn_add";
			this->btn_add->Size = System::Drawing::Size(75, 23);
			this->btn_add->TabIndex = 5;
			this->btn_add->Text = L"Add";
			this->btn_add->UseVisualStyleBackColor = true;
			this->btn_add->Click += gcnew System::EventHandler(this, &MyForm::btn_add_Click);
			// 
			// btn_remove
			// 
			this->btn_remove->Location = System::Drawing::Point(208, 260);
			this->btn_remove->Name = L"btn_remove";
			this->btn_remove->Size = System::Drawing::Size(75, 23);
			this->btn_remove->TabIndex = 6;
			this->btn_remove->Text = L"Remove";
			this->btn_remove->UseVisualStyleBackColor = true;
			this->btn_remove->Click += gcnew System::EventHandler(this, &MyForm::btn_remove_Click);
			// 
			// txt_newImage
			// 
			this->txt_newImage->Location = System::Drawing::Point(137, 330);
			this->txt_newImage->Name = L"txt_newImage";
			this->txt_newImage->Size = System::Drawing::Size(155, 20);
			this->txt_newImage->TabIndex = 7;
			// 
			// lbl_current_position
			// 
			this->lbl_current_position->AutoSize = true;
			this->lbl_current_position->Location = System::Drawing::Point(9, 355);
			this->lbl_current_position->Name = L"lbl_current_position";
			this->lbl_current_position->Size = System::Drawing::Size(93, 13);
			this->lbl_current_position->TabIndex = 8;
			this->lbl_current_position->Text = L"Current Position: 0";
			// 
			// list_photos
			// 
			this->list_photos->Location = System::Drawing::Point(519, 26);
			this->list_photos->Name = L"list_photos";
			this->list_photos->Size = System::Drawing::Size(152, 324);
			this->list_photos->TabIndex = 9;
			this->list_photos->UseCompatibleStateImageBehavior = false;
			this->list_photos->View = System::Windows::Forms::View::List;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(783, 377);
			this->Controls->Add(this->list_photos);
			this->Controls->Add(this->lbl_current_position);
			this->Controls->Add(this->txt_newImage);
			this->Controls->Add(this->btn_remove);
			this->Controls->Add(this->btn_add);
			this->Controls->Add(this->pic_left);
			this->Controls->Add(this->pic_right);
			this->Controls->Add(this->pic_main);
			this->Controls->Add(this->btn_next);
			this->Controls->Add(this->btn_prev);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_main))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_right))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_left))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		#pragma endregion
		private: System::Void btn_next_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void btn_remove_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void btn_add_Click(System::Object^  sender, System::EventArgs^  e);
				 System::Void addItem(System::String ^ text);
				 System::Void addItem(int pos, System::String ^ text);
		private: System::Void btn_prev_Click(System::Object^  sender, System::EventArgs^  e);
				 System::Void setPicturePosition(int pos);
private: System::Void pic_main_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
