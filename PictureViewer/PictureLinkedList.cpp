#include "PictureLinkedList.h"



PictureLinkedList::PictureLinkedList()
{
	head = 0;
	tail = 0;
}

PictureLinkedList::~PictureLinkedList()
{
	
	// Loop through images, delete each pointer
	PictureNode *node = head;
	while (node != 0) {
		delete node;
	}
}

void PictureLinkedList::add(std::string value)
{
	insert(size(), value);
}

void PictureLinkedList::insert(int pos, std::string value)
{
	// Let's assume we have 10 cars
	PictureNode *newNode = new PictureNode;
	newNode->picturePath = value;
	newNode->next = 0;
	// we need a pointer to car1 and car2
	PictureNode *pic_at_position = walkToPosition(pos);

	// now we can do the switching
	// The new car is attached to the next car after it
	if (pic_at_position == 0) {
		// This is the first car
		head = newNode;
		head->next = 0;
		head->prev = 0;
	}
	else {
		newNode->next = pic_at_position->next;
		newNode->prev = pic_at_position;

		if (newNode->next != 0) {
			newNode->next->prev = newNode;
		}
		pic_at_position->next = newNode;

	}
}



std::string PictureLinkedList::get(int pos)
{
	PictureNode *pic = walkToPosition(pos);
	return pic->picturePath;
}

void PictureLinkedList::set(int pos, double value)
{
	throw gcnew System::NotImplementedException();
}

int PictureLinkedList::size()
{
	int number_nodes = 0;
	PictureNode *start = head;
	if (head != 0) {
		number_nodes++;
		while (start->next != 0) {
			number_nodes++;
			start = start->next;
		}
	}

	return number_nodes;
}



PictureNode * PictureLinkedList::walkToPosition(int position)
{
	int tmp_pos = 0;
	PictureNode *tmp_node = head;
	while (tmp_pos < position) {
		tmp_pos++;
		if (tmp_node->next != 0) {
			tmp_node = tmp_node->next;
		}
		if (tmp_node->next == 0) {
			break;
		}
	}
	return tmp_node;
}



void PictureLinkedList::remove(int pos)
{
	PictureNode *tmp_node = walkToPosition(pos);
	PictureNode *to_delete = tmp_node->next;
	tmp_node->next = to_delete->next;
	tmp_node->next->prev = tmp_node;
	delete to_delete;
}

/*
void trainCarLinkedList::printCars()
{
	std::cout << "This is the train: " << std::endl;
	trainCar *position = root;
	if (count() > 0) { //Makes sure there is a place to start
		while (position->next != 0) {
			std::cout << position->name << std::endl;
			position = position->next;
		}
		std::cout << position->name << std::endl;
	}
}
*/



