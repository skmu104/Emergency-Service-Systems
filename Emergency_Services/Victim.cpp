#include "Victim.hpp"
#include <iostream>
using namespace std;

Victim::Victim(const std::string &name) : Civilian(name) {
	//Setting parameter as field
	this->name = name;
	//treated field initialised as false
	this->treated = false;
	//treated amount field initialised as 0
	this->treatedAmount =0;
}

bool Victim::isTreated(){
	//if treated field changed to true before this method is called
	//will return true
	if (this->treated == true){
		return true;
	}
	else{
	return false;
	}
}

int Victim::getTreatedByAmount(){
	//returns treated amount
	return this->treatedAmount;
}

void Victim::setTreated(bool treated){
	//setter for private field treated
	this->treated = treated;
}

void Victim::incrementAmount(){
	//method to increment amount treated everytime method is called
	this->treatedAmount++;
}

Victim::~Victim() {
	//cout<<"victim destroyed"<<endl;
}

