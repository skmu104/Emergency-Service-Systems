#include "Staff.hpp"

int Staff::IdIncrementer = 0; // initialising incrementer field to 0

Staff::Staff(const std::string &name) : Human(name) {

	//Setting parameter as field
	this->name = name;
	//setting unique instance Id to incrementer field, THEN incrementing that value.
	this->ID = IdIncrementer++;
	this->complete = false;
	this->assign = false;//
	this->staffType = FIREFIGTHER;

}

void Staff::performJob(){

	this->complete = true;	// created boolean field and set it to true when method called
}

void Staff::setAssigned(bool assigned){

	//getter function
	this->assign = assigned; //assigning field to parameter passed in, so it is saved

}

bool Staff::isAssigned(){

	//setter function for assign
	if (this->assign == true ){
		return  true;
	}
	else{return false; }
}

bool Staff::isJobComplete(){

	//bool method that returns true when performJob method called
	if (this->complete){
		return true;
	}
	else {return false;};
}

int Staff::getID(){

	//getter function for ID
	return this->ID;
}

type Staff::getStaffType(){
	//getter function for staffType
	return this->staffType;
}

Staff::~Staff() {

}

