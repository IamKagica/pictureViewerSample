#include "MyForm.h"
#include <fstream>
#include <iostream>
#include <msclr\marshal_cppstd.h>
#include "PictureLinkedList.h"

System::String^ s2s(std::string  str) {
	return gcnew System::String(str.c_str());
}


std::string s2s(System::String^ str) {
	return msclr::interop::marshal_as<std::string>(str);
}

PictureViewer::MyForm::MyForm(void)
{

	InitializeComponent();
	addItem("C:\\Users\\Owner\\Pictures\\Numbers.jpg");
	addItem("C:\\Users\\Owner\\Pictures\\City.jpg");
	addItem("C:\\Users\\Owner\\Pictures\\Self.jpg");
	setPicturePosition(0);

}

System::Void PictureViewer::MyForm::btn_remove_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	// TODO remove the picture at the current location
	// load the right picture into the main picture box
	//pic_main->ImageLocation = pic_right->ImageLocation;
	// load the next picture into the right picture box
	//std::string new_path = pictureList.get(current_position+1);
	pictureList.remove(current_position);
	
	//std::string new_picture_path = pictureList.get(current_position);
	
	//pic_right->ImageLocation = gcnew String(new_picture_path.c_str());
	//pic_right->ImageLocation = s2s(new_picture_path);
	setPicturePosition(current_position);
	
	
}



System::Void PictureViewer::MyForm::btn_add_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	// Insert a picture after the picture in the main window
	// load the main picture into the left picture box
	//pic_left->ImageLocation = pic_main->ImageLocation;
	// load the new picture into the main picture box
	//pic_main->ImageLocation = txt_newImage->Text;
	
	addItem(current_position, txt_newImage->Text);
	
	setPicturePosition(current_position);
	
}

System::Void PictureViewer::MyForm::addItem(System::String^ text) {
	addItem(pictureList.size(), text);
	
}
System::Void PictureViewer::MyForm::addItem(int pos, System::String^ text) {
	pictureList.insert(pos,s2s(text));

	ListViewItem^ new_item = gcnew ListViewItem();
	new_item->Text = txt_newImage->Text;
	list_photos->Items->Add(new_item);
}



System::Void PictureViewer::MyForm::btn_next_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	//return System::Void();
	//load the center image into the left picture box
	//pic_left->ImageLocation = pic_main->ImageLocation;
	// Load the right image into the main picture box
	// MessageBox::Show(pic_right->ImageLocation);
	//pic_main->ImageLocation = pic_right->ImageLocation;
	
	//pic_main->Load(pic_right->ImageLocation);
	// load the next (next after the former right) image into the right picture box
	//pic_right->ImageLocation = s2s(pictureList.get(current_position + 2));
	setPicturePosition(current_position+1);


}
System::Void PictureViewer::MyForm::btn_prev_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	// move the main picture into the right picture box
	//pic_right->ImageLocation = pic_main->ImageLocation;
	// move the left picture into the main picture box
	//pic_main->ImageLocation = pic_left->ImageLocation;
	// load the previous picture (previous to the former left) into the left picture box
	//pic_left->ImageLocation = s2s(pictureList.get(current_position - 2));
	setPicturePosition(current_position-1);
}

System::Void PictureViewer::MyForm::setPicturePosition(int pos)
{
	if (pos >= pictureList.size() || pos < 0) {
		// Don't go anywhere. You are at the end of the list
	}
/*	else if (pos = 0)
	{
		System::String^ right_picture = s2s(pictureList.get(pos + 1));
		System::String^ left_picture = s2s(pictureList.get(pos));
		System::String^ main_picture = s2s(pictureList.get(pos));
		pic_right->ImageLocation = right_picture;
		pic_main->ImageLocation = main_picture;
		pic_left->ImageLocation = left_picture;
		current_position = pos;
	}*/
	else {
		System::String^ right_picture = s2s(pictureList.get(pos + 1));
		System::String^ left_picture = s2s(pictureList.get(pos - 1));
		System::String^ main_picture = s2s(pictureList.get(pos));
		pic_right->ImageLocation = right_picture;
		pic_main->ImageLocation = main_picture;
		pic_left->ImageLocation = left_picture;
		current_position = pos;
	}
	
	lbl_current_position->Text = current_position+1 + "/" + pictureList.size();
}
