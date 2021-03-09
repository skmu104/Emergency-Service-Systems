#include "PoliceOfficer.hpp"
#include <iostream>
using namespace std;

PoliceOfficer::PoliceOfficer(const std::string &name) : Staff(name){
	//Setting parameter as field
	this->name = name;
	//suspect pointer initialised to null.
	suspect = 0;
	this->staffType = POLICEOFFICER;
}

void PoliceOfficer :: assignSuspect(Suspect* suspect){
	//setter method to pass suspect instance as parameter, to be assigned
	this->suspect = suspect;
}

Suspect* PoliceOfficer :: getAssignedSuspect(){
	//getter method to return victim instance passed into setter method
	return this->suspect;
}

void PoliceOfficer::performJob(){
	// when performJob method of policeofficer class called, complete set to true, but also suspect
	//instance passed in to assign suspect methods, value for caught and caughtamount is changed.
	//amount caught incremented to keep count of number of times suspect has been caught
	this->complete = true;
	//incases that the policeofficer has been assigned to the emergency with a suspect
	//but has not been directly assigned the suspect, we will not change fields of suspect
	//in this method because it cannot access the corresponding suspect
if(getAssignedSuspect() != 0){
	getAssignedSuspect()->setCaught(true);
	getAssignedSuspect()->incrementAmount();
}
}

PoliceOfficer::~PoliceOfficer(){
	//cout<<"Police delete"<<endl;

}
