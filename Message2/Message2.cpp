//============================================================================
// Name        : Message.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

class Node {
	friend class Message;
public:
	Node *get_next(); //Returns the pointer to the next node.
	std::string get_fragment(); //Returns the string representing the fragment stored in this packet.
	Node(unsigned int id, std::string frag); // This is the constructor
private:
	unsigned int identifier; //Stores the packet identifier.
	std::string fragment; //Stores the packet message that corresponds to one string.
	Node *p_next; //A pointer to the next node in the linked list of type Node.
};
class Message {
public:
	Message();
	//This is the default constructor. It will set the head to the null pointer.

	~Message();
	//This is the destructor. We must ensure that the dynamically allocated nodes are deallocated properly.

	void insert(unsigned int id, std::string fragment);
	//Inserts a node in the linked list that contains the packet information provided as parameters.

	void print_message();
	//Prints to the console output stream the stored message as described above.

private:
	Node * head; //A pointer to the first packet of the message.
	// Node * tail; //A pointer to the last packet of the message.
};

Node::Node(unsigned int id, std::string frag) :
		identifier { id }, fragment { frag }, p_next { nullptr } {
}

//Returns the pointer to the next node.
Node *Node::get_next() {
	return p_next;
}
//Returns the string representing the fragment stored in this packet.
std::string Node::get_fragment() {
	return fragment;
}

//This is the default constructor. It will set the head to the null pointer.
Message::Message() :
		head { nullptr } {
}

//This is the destructor. We must ensure that the dynamically allocated nodes are deallocated properly.
Message::~Message() {
	Node *p_n = nullptr;
	while (head != nullptr) {
		p_n = head;
		head = head->p_next;
		p_n->p_next = nullptr;
		delete p_n;
	}
}
//Inserts a node in the linked list that contains the packet information provided as parameters.
void Message::insert(unsigned int id, std::string fragment) {
	if (head == nullptr) {
		head = new Node { id, fragment };
	} else {
		Node *a = head;
		Node *last = head;
		int next = a->identifier;
		if (id < next) {
			Node *temp = new Node { id, fragment };
			temp->p_next = head;
			head = temp;
		} else {

			while (id > next) {
				last = a;
				if (a->p_next == nullptr) {
					a->p_next = new Node { id, fragment };
					break;
				} else if (next < id) {
					Node *temp = new Node { id, fragment };
					temp->p_next = last;
					last = temp;
				}

				a = a->p_next;
				next = a-> identifier;
			}
			Node *temp = new Node { id, fragment };
			temp->p_next = last;
			last = temp;
		}
	}
}

//Prints to the console output stream the stored message as described above.
void Message::print_message() {
	if (head == nullptr) {
		std::cout << "???" << std::endl;
	} else {
		Node *a = head;
		int num = 0;
		bool end = false;
		while(a != nullptr){
			if (a->fragment == "EOT") {

			}else{
				std::cout << a->fragment << " ";
			}
			a = a->p_next;
		}
	/*
		while (a != nullptr) {
			if (num == a->identifier) {
				if (a->fragment == "EOT") {
					end = true;
				} else
					std::cout << a->fragment << " ";
			} else {
				for (int i = 0; i < (a->identifier - num) - 1; i++) {
					std::cout << "... ";
				}
				if (a->fragment == "EOT") {
					end = true;
				} else
					std::cout << a->fragment << " ";

			}
			num++;
			a = a->p_next;
		}\
		if (!end)
		{
			std::cout << "???";
		}
		*/
		std::cout << "\n";
	}
}

#ifndef MARMOSET_TESTING
int main() {
	int input { 0 };
	std::string message { "" };

	Message p_m;

	while (input != -2) {
		std::cin >> input;
		if (input == -1) {
			p_m.print_message();
		} else if (input >= 0) {
			std::cin >> message;
			p_m.insert(input, message);
		}

	}
	return 0;
}
#endif

