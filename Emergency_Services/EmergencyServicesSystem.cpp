#include "EmergencyServicesSystem.hpp"
#include <iostream>
#include <vector>
#include <string.h>

EmergencyServicesSystem::EmergencyServicesSystem(){
	//total capacity initialised to 0 once instance/object created
	this->totalCapacity = 0;
}

std::string EmergencyServicesSystem::author(){
	//UPI of author
	return "skmu104";
}

// TODO implement all the other methods and destructor for EmergencyServicesSystem
bool EmergencyServicesSystem::addEmergency(Emergency *emergency){
	//boolean duplicate variable created in method so that it resets to false
	//out of scope. Variable used to see if address values of emergency arent
	//already in assignedEmergency vector.
	bool duplicate = false;
	//nested conditional statements used to check if address value of passed in emergency
	//instance is already part of a assigned emergency in vector.
	//shows to be duplicate if all values of address are same
	//unsigned int type used because size of vector can only be positive value
	//this avoids and warning from complier.
	for (unsigned int i = 0; i < assignedEmergency.size();i++){
		if (emergency->getAddress()->getNumber() == assignedEmergency[i]->getAddress()->getNumber()){
			if(emergency->getAddress()->getStreet() == assignedEmergency[i]->getAddress()->getStreet()){
				if (emergency->getAddress()->getSuburb() == assignedEmergency[i]->getAddress()->getSuburb()){
					if (emergency->getAddress()->getPostcode() == assignedEmergency[i]->getAddress()->getPostcode()){
						duplicate = true;
					}
				}
			}
		}
	}
	//assigns emergency to assigned emergency vector if no duplicate data and returns true
	if (duplicate == false){
		assignedEmergency.push_back(emergency);
		return true;
	}
	//else if there is duplicate data, returns false and doesnt store the emergency.
	else {return false;
	}
}
int EmergencyServicesSystem::getStaffCount(){
	//getter to return the total staff by summing all indiviual staff type vector sizes.
	return (assignedPoliceOfficer.size() + assignedParamedic.size() + assignedFireFighter.size());
}


//methods used to hire staff and store them into their corresponding vectors
void EmergencyServicesSystem::hirePoliceOfficer(PoliceOfficer* policeOfficer){
	assignedPoliceOfficer.push_back(policeOfficer);
}
void EmergencyServicesSystem::hireParamedic(Paramedic* paramedic){
	assignedParamedic.push_back(paramedic);
}
void EmergencyServicesSystem::hireFireFighter(FireFighter* fireFighter){
	assignedFireFighter.push_back(fireFighter);
}
// method used to purchase vehicle and store in corresponding vector
// and to also update total capacity by adding to it the hired vehicles
//capacity.
void EmergencyServicesSystem::buyVehicle(Vehicle* vehicle){
	ownedVehicles.push_back(vehicle);
	this->totalCapacity += vehicle->getCapacity();

}

bool EmergencyServicesSystem::assignStaffToEmergency(Address* address,unsigned int numPoliceOfficers,unsigned int numParamedics,unsigned int numFireFighters){
	//unsigned int j variable used to check if address passed in matches address of
	//a emergency stored in assigned emergency vector. bool duplicate local variable
	// also created to tell us if the same address passed in, is returned. If address
	//not existing in vector then returns false.
	unsigned int j = 0;
	bool duplicate = false;
	for (unsigned int i = 0;i < assignedEmergency.size();i++){
		if(assignedEmergency[i]->getAddress() == address){
			//loops through every value of address for emergencies stored
			//and equates j variable to i which represents location in vector
			//that corresponds to the same address as parameter.
			j=i;
			duplicate = true;
		}
	}
	//if duplicate remains as false then false returned and unable to assign staff
	if (!duplicate){
		return false;
	}
	//if size of any of the indiviual staff vectors is smaller than the passed in parameters which
	//represent the required staff, then false returned
	if ((assignedPoliceOfficer.size() < numPoliceOfficers)||(assignedParamedic.size() < numParamedics)||(assignedFireFighter.size()< numFireFighters)){
		return false;
	}
	//if there is enough neccessary staff
	//loops used to assign neccessary staff members to emergency
	//and neccessary victims/suspects to paramedics/policeOfficers
	for (unsigned int i = 0; i <numPoliceOfficers;i++){
		assignedEmergency[j]->assignStaff(assignedPoliceOfficer[i]);
		assignedPoliceOfficer[i]->assignSuspect(assignedEmergency[j]->getSuspect());
	}
	for (unsigned int i = 0; i <numParamedics;i++){
		assignedEmergency[j]->assignStaff(assignedParamedic[i]);
		assignedParamedic[i]->assignVictim(assignedEmergency[j]->getVictim());
	}
	for (unsigned int i = 0; i <numFireFighters;i++){
		assignedEmergency[j]->assignStaff(assignedFireFighter[i]);
	}


	//returns true after staff assigned
		return true;
}

bool EmergencyServicesSystem::transportStaff(Address* address){
	//like the method above, we use variable j to ensure address is present

	unsigned int j = 0;
	bool duplicate = false;
	for (unsigned int i = 0;i < assignedEmergency.size();i++){
		if(assignedEmergency[i]->getAddress() == address){
			j=i;
			duplicate = true;
		}
	}
	if (!duplicate){
		return false;
	}
	//also conditional statement used to see if total capacity enough to carry
	//all the staff assigned to emergency
	// if there is enough status of emergency changed to TRANSPORTED
	//and returns true, if not returns false.
	if (assignedEmergency[j]->getAssignedStaff().size() <= this->totalCapacity ){
		assignedEmergency[j]->setStatus(TRANSPORTED);
		return true;
	}


	return false;
}

bool EmergencyServicesSystem::resolveEmergency(Address* address){
	//like previous two methods, same logic used to ensure address present
	unsigned int j = 0;
	bool duplicate = false;
		for (unsigned int i = 0;i < assignedEmergency.size();i++){
			if(assignedEmergency[i]->getAddress() == address){
				j=i;
				duplicate = true;
			}
		}
		if (!duplicate){
			return false;
		}
	// condition used to check if the status is at any point other
	// than the TRANSPORTED status. The status can be represented
	//between values 0-3, with 2 being TRANSPORTED. if not in TRANSPORTED
	// false is returned
	if(assignedEmergency[j]->getStatus()  != 2){
		return false;
	}

	//otherwise the corresponding emergency is resolved, and returned.
	return assignedEmergency[j]->resolve();


}



EmergencyServicesSystem::~EmergencyServicesSystem(){
	//deleting values for assignedEmergency and ownedVehicles vectors
	// we do not have to delete vector values of PoliceOfficer, Paramedic
	//and fireFighter because those instances are already deleted once
	//we exit the emergency scope. The Emergency class destructor deletes
	//those instances
	for (unsigned int i = 0; i < assignedEmergency.size();i++){
		delete assignedEmergency[i];
		}
	for (unsigned int i = 0; i < ownedVehicles.size();i++){
		delete ownedVehicles[i];
	}
	for (unsigned int i = 0; i < assignedPoliceOfficer.size();i++){
		delete assignedPoliceOfficer[i];
	}
	for (unsigned int i = 0; i < assignedParamedic.size();i++){
		delete assignedParamedic[i];
	}
	for (unsigned int i = 0; i < assignedFireFighter.size();i++){
		delete assignedFireFighter[i];
	}
	//cout<< "ems deleted"<<endl;

}

