#include "Human.hpp"
#include <string>
#include <iostream>

Human::Human(const std::string &name) {
	this->name = name; //Setting parameter as field

}

std::string Human::getName(){

	return name; //getter function
}

Human::~Human() {
//cout<<"humans destroyed"<<endl;
}

