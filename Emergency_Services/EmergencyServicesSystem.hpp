#include <vector>
#include <iostream>
#include "PoliceOfficer.hpp"
#include "FireFighter.hpp"
#include "Paramedic.hpp"
#include "Emergency.hpp"
#include "Vehicle.hpp"

using namespace std;

#ifndef EMERGENCYSERVICESSYSTEM_HPP_
#define EMERGENCYSERVICESSYSTEM_HPP_

class EmergencyServicesSystem   {
private:
	std::vector<Emergency*> assignedEmergency;
	//seperate vectors made fro each staff type
	//having seperate vectors makes it easier to assign civillians
	//and keep track of number of each type of staff
	std::vector<PoliceOfficer*> assignedPoliceOfficer;
	std::vector<Paramedic*> assignedParamedic;
	std::vector<FireFighter*> assignedFireFighter;
	//private vector of ownedVehicles created to store instances of vehicles
	//purchased by emergency service system
	std::vector<Vehicle*> ownedVehicles;
	//private total capacity variable used to keep track of total capacity
	//the emergency service system is able to transport. Made private so other
	//classes cannot change
	unsigned int totalCapacity;
public:
	EmergencyServicesSystem();
	static std::string author();
	void hirePoliceOfficer(PoliceOfficer* policeOfficer);
	void hireParamedic(Paramedic* paramedic);
	void hireFireFighter(FireFighter* fireFighter);
	bool addEmergency(Emergency* emergency);
	void buyVehicle(Vehicle* vehicle);
	//i have changed the input types of the parameters to unsigned, to avoid comparing
	//between unsigned and signed integers in the code. This is under the logical
	//assumption that only positive integers will be passed through.
	bool assignStaffToEmergency(Address* address,unsigned int numPoliceOfficers,unsigned int numParamedics,unsigned int numFireFighters);
	bool transportStaff(Address* address);
	bool resolveEmergency(Address* address);
	int getStaffCount();
	virtual ~EmergencyServicesSystem();
};

#endif /* EMERGENCYSERVICESSYSTEM_HPP_ */
