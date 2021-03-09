#include "Vehicle.hpp"
#include <iostream>
using namespace std;

Vehicle::Vehicle(const std::string &name, int capacity) {

	this->vehicleName = name;
	this->vehicleCapacity = capacity;
}

int Vehicle::getCapacity(){

	 return this->vehicleCapacity;//return capacity of vehicle stored as a private variable
}

std::string Vehicle::getName(){

	return this->vehicleName;//return vehicle name stored as a private variable
}

Vehicle::~Vehicle() {
	//cout<<"vehicle destroyed"<<endl;
}

