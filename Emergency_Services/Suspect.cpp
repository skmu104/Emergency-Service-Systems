#include "Suspect.hpp"
#include <iostream>
using namespace std;

Suspect::Suspect(const std::string &name) : Civilian(name) {
	//setting field as parameter passed in
	this->name = name;
	//initialising suspect caught field to be false
	this->caught = false;
	//initialising caught amount to 0;
	this->caughtAmount = 0;
}

bool Suspect::isCaught(){
	//conditional statement to return true if suspect has been caught
	if (this->caught == true){
		return true;
	}
	else{
		return false;
	}
}

int Suspect::getCaughtByAmount(){
	//returns number of times suspect has been caught
	return this->caughtAmount;
}
void Suspect::setCaught(bool caught){
	//setter method to change private caught field
	this->caught = caught;
}

void Suspect::incrementAmount(){
	//setter method to increment private caught field
	this->caughtAmount++;
}

Suspect::~Suspect() {
	//cout<<"suspect destroyed"<< endl;
}

