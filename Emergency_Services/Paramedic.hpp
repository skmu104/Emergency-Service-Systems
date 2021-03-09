#include "Staff.hpp"
#include "Victim.hpp"
#ifndef PARAMEDIC_HPP_
#define PARAMEDIC_HPP_

class Paramedic : public Staff{
//TODO Add members as needed
private:

    	Paramedic& operator=(const Paramedic& other);
    	Paramedic(const Paramedic& other);
    	Victim* victim; //private victim instance field created so that other classes
    					//cannot access. Used to store the victim instance, passed
    					// in by setter.

public:
	Paramedic(const std::string &name);
	void assignVictim(Victim* victim);
	Victim* getAssignedVictim();
	void performJob();
	~Paramedic();
};

#endif /* PARAMEDIC_HPP_ */
