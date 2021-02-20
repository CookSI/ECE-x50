//============================================================================
// Name        : Message.cpp
// Author      : Albert Ndur-Osei
// Version     :
// Copyright   : 
// Description :
//============================================================================

#include <iostream>
#include "Message.h"

Node::Node(unsigned int id, std::string frag):
	identifier{id},
	fragment{frag},
	p_next{nullptr}{

	}
std::string Node::get_fragment(){
	return fragment;
}
Node *Node::get_next(){
	return p_next;
}

Message::Message():
	head{nullptr},
	tail{nullptr}{
		}
Message::~Message()	{
	Node * p_death = nullptr;
	while(head != nullptr){
		p_death = head;
		head = head -> p_next;
		p_death->p_next = nullptr;
		delete p_death;
	}
	p_death = nullptr;
}
void Message::insert(unsigned int id, std::string fragment){
	if(head == nullptr){									//Empty Message
		head = new Node{id, fragment};
		tail = head;
	}else if(head->p_next == nullptr){						//One Packet Message
		if(head->identifier < id){ 							//One Packet Message: Insert at the back
			head->p_next = new Node{id,fragment};
			tail = head->p_next;
		}else{												//One Packet Message: Insert at the front
			Node * temp = new Node{id,fragment};
			temp->p_next = head;
			head = temp;
			tail = head->p_next;
		}
	}else{													//Multiple Packet Message
		if(id < head->identifier){							//Insert at the front
			Node * temp = new Node{id,fragment};
			temp->p_next = head;
			head = temp;
		}else if (id > tail->identifier){					//Insert at the back
			tail->p_next = new Node{id,fragment};
			tail = tail->p_next;
		}else{												//Insert between two nodes
			Node * travel = head;
			Node * upper_node = nullptr;
			while(travel != nullptr){
				if(travel->identifier < id){
					upper_node = travel;
				}
				travel = travel->p_next;
			}
			Node * temp_node = upper_node->p_next;
			upper_node->p_next = new Node{id,fragment};
			upper_node->p_next->p_next = temp_node;
		}
	}
}
void Message::print_message(){
	if(head != nullptr && tail != nullptr){
		Node * travel = head;
			int end {-1};
			unsigned int step {0};
			unsigned int num_nodes{0};

			while(travel != nullptr){			//Find the identifier to end on
				if(travel->fragment == "EOT"){
					end = travel->identifier;
					break;
				}
				travel = travel->p_next;
				++num_nodes;
			}
			if(end >= 0){ 						//Condition 1: There is and EOT
				travel = head;
				if(end == num_nodes){
					while(travel != tail){				// All fragments are in the message
						if(travel == head){
							std::cout<<travel->fragment<<" ";
						}else if(travel == tail){
							std::cout<<travel->fragment;
						}else{
							std::cout<<travel->fragment<<" ";
						}
						travel = travel->p_next;
					}
					std::cout<<"\n";
				}else if(end > num_nodes){				// Missing Fragments
					while(travel != nullptr){
						if(travel->identifier == step){	 // Checks to see if the current node is the node we are looking for
							if(travel->fragment != "EOT"){
								if(travel == head){
									std::cout<<travel->fragment<<" ";
								}else if(travel == tail){
									std::cout<<travel->fragment;
								}else{
									std::cout<<travel->fragment<<" ";
								}
							}
						}else if(travel != nullptr){
							while(step != travel->identifier){
								if(step < travel->identifier){
									std::cout<< "... ";
								}else{
									std::cout<< "...";
								}

								++step;
							}
							if(travel->fragment != "EOT"){
								if(travel == head){
									std::cout<<travel->fragment<<" ";
								}else if(travel == tail){
									std::cout<<travel->fragment;
								}else{
									std::cout<<travel->fragment<<" ";
								}
							}
						}
						travel = travel->p_next;
						++step;
					}
					std::cout<<"\n";
				}

			}else if(end == -1){										//Condition 2: No EOT
				end = tail->identifier;
				travel = head;
				if(end == num_nodes && head != tail){
					while(travel != nullptr){				// All fragments are in the message
						if(travel == head){
							std::cout<<travel->fragment<<" ";
						}else if(travel == tail){
							std::cout<<travel->fragment<<" ???";
						}else{
							std::cout<<travel->fragment<<" ";
						}

						travel = travel->p_next;
					}
					std::cout<<"\n";
				}else if(end > num_nodes){				// Missing Fragments
					while(travel != nullptr){
						if(travel->identifier == step){	 // Checks to see if the current node is the node we are looking for
							if(travel == head){
								std::cout<<travel->fragment<<" ";
							}else if(travel == tail){
								std::cout<<travel->fragment<<" ???";
							}else{
								std::cout<<travel->fragment<<" ";
							}
						}else if(travel != nullptr){
							while(step != travel->identifier){
								if(step < travel->identifier){
									std::cout<< "... ";
								}else{
									std::cout<< "...";
								}
								++step;
							}
								if(travel == head){
									std::cout<<travel->fragment<<" ";
								}else if(travel == tail){
									std::cout<<travel->fragment<<" ???";
								}else{
									std::cout<<travel->fragment<<" ";
								}
						}
						travel = travel->p_next;
						++step;
					}
					std::cout<<"\n";
				}else if(head == tail){
					std::cout<<end;
					std::cout<<num_nodes;
					while(travel != nullptr){
						if(travel->identifier == step){	 // Checks to see if the current node is the node we are looking for
								std::cout<<travel->fragment<<" ???";
						}else if(travel != nullptr){
							while(step != travel->identifier){
								if(step < travel->identifier){
									std::cout<< "... ";
								}else{
									std::cout<< "...";
								}
								++step;
							}
									std::cout<<travel->fragment<<" ???";
						}
						travel = travel->p_next;
						++step;
					}
					std::cout<<"\n";
				}
			}
	}else if(head == nullptr && tail == nullptr){
		std::cout<<"???"<<std::endl;
	}
}



#ifndef MARMOSET_TESTING
int main() {
	int input{0};
	std::string input_frag{""};
	Message New_Message;

	while(input != -2){
		std::cin >> input;
			if(input >= 0){
				std::cin >> input_frag;
				New_Message.insert(input,input_frag);
			}else if(input == -1){
				New_Message.print_message();
			}
	}
	return 0;
}
#endif

