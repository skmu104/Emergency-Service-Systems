#include "Emergency.hpp"
#include <iostream>


Emergency::Emergency(Address* address, Victim* victim, Suspect* suspect ) {
	//setting the fields to entered parameters
	this->address = address;
	this->victim = victim;
	this->suspect = suspect;
	//initialising current field (status field) to CRITICAL
	this->current = CRITICAL;

}

Address* Emergency::getAddress(){
	//getter method to return private address field
	return this->address;
}

Suspect* Emergency::getSuspect(){
	//getter method to return private suspect field
	return this->suspect;
}

Victim* Emergency::getVictim(){
	//getter method to return private victim field
	return this->victim;
}

Status Emergency::getStatus(){
	//getter method to return private current field
	return this->current;
}

void Emergency::setStatus(Status status){
	//setter method to change current (status)
	//we create this method so that later in other methods
	//we can use this to change the private variable.
	this->current = status;
}


std::vector<Staff*> Emergency::getAssignedStaff(){
	//getter to return our created private vector
	return this->assignedStaff;
}

void Emergency::assignStaff(Staff *staff){
	//conditional statement used to add object to vector field, only
	//if the current state is either CRITICAL or ASSIGNED
	if ((this->current == CRITICAL) | (this->current == ASSIGNED) ){
		//push_back function used to add instance to end of vector.
		assignedStaff.push_back(staff);
		//assigned size only increases everytime this method is called
		// but assignedStaff size starts off at 1 and if we want to access the
		//0th object we must minus by 1.
		assignedStaff[(getAssignedSize())-1]->setAssigned(true);
		//changing the current state to assigned


		setStatus(ASSIGNED);

	}
}

bool Emergency::resolve(){
	if (this->current == COMPLETED){
		// conditional statement process so that true is immediately
		//returned if current state is COMPLETED

		return true;
	}
	else{
		//else another conditional statement that is  only true when staff
		//have been assigned. assignedStaff size will be greater than 0
		//if staff have been assigned.
		if((getAssignedSize()) > 0 ){
			int policeCount = 0;
			int paramedicCount = 0;
			for ( int i = 0; i < getAssignedSize();i++){
				//cycles through vector and executes performJob
				//method on each object stored
				getAssignedStaff()[i]->performJob();
				//if police/paramedic not directly assigned to the victim or suspect,
				//the conditional statement counts how many times the police or paramedic
				//perform their job.
				if ((getVictim()->getTreatedByAmount() == 0) || (getSuspect()->getCaughtByAmount() == 0)){
					if (getAssignedStaff()[i]->getStaffType() == POLICEOFFICER){
						policeCount++;
					}
					if (getAssignedStaff()[i]->getStaffType() == PARAMEDIC){
						paramedicCount++;
					}
				}

			}
			//if staff not directly assigned to victim and/or suspect, they will not
			//be treated/caught therefore we will check if the suspect/victim has been
			//and set it if not
			if (getVictim()->isTreated() == false){
				getVictim()->setTreated(true);
			}
			if (getSuspect()->isCaught() == false){
				getSuspect()->setCaught(true);
			}
			//using loops with the police/paramedic count variable to set the amount
			//of times they've been caught/treated.
			for(int i =0; i < paramedicCount;i++){
				getVictim()->incrementAmount();
			}
			for (int i = 0; i < policeCount; i++){
				getSuspect()->incrementAmount();
			}
			// changes current state to COMPLETED after loop executed
			//current = COMPLETED;
			setStatus(COMPLETED);
			//returns true
			return true;
		}

		return false;


	}
}

int Emergency::getAssignedSize(){
	//getter for assigned staff size just to make code easier to understand.
	return assignedStaff.size();
}

Emergency::~Emergency() {

	//}
	delete address;
	delete victim;
	delete suspect;

	//cout<<"emergency Destroyed"<<endl;
}

