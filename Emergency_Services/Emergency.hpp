#include "Address.hpp"
#include "Victim.hpp"
#include "Suspect.hpp"
#include "Staff.hpp"
#include <vector>
#include <iostream>
using namespace std;
#ifndef EMERGENCY_HPP_
#define EMERGENCY_HPP_
enum Status {
	CRITICAL,
	ASSIGNED,
	TRANSPORTED,
	COMPLETED
};

class Emergency {

private:
	std::vector<Staff*> assignedStaff;
    	Emergency& operator=(const Emergency& other);
    	Emergency(const Emergency& other);
    	//fields created to store parameters that will be passed
    	//created in the private sector so, the instances cannot be
    	//accessed by outside classes publicly
    	Address* address;
    	Victim* victim;
    	Suspect* suspect;
    	Status current;
public:
	Emergency(Address* address, Victim* victim, Suspect* suspect);
	int getAssignedSize(); //method created in public sector to return assignedsize.
	Address* getAddress();
	Suspect* getSuspect();
	Victim* getVictim();
	Status getStatus();
	void setStatus(Status status); //setter for status
	void assignStaff(Staff* staff);
	std::vector<Staff*> getAssignedStaff();
	bool resolve();
	virtual ~Emergency();
};

#endif /* EMERGENCY_HPP_ */
