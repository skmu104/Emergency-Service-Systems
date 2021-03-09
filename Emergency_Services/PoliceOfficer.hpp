#include "Staff.hpp"
#include "Suspect.hpp"
#ifndef POLICEOFFICER_HPP_
#define POLICEOFFICER_HPP_

class PoliceOfficer : public Staff {

private:
	PoliceOfficer& operator=(const PoliceOfficer& other);
        PoliceOfficer(const PoliceOfficer& other);
        Suspect* suspect;//private suspect instance field created to assign suspect
        			 	 //made private so other classes cannot access this.
public:
	PoliceOfficer(const std::string &name);
	void assignSuspect(Suspect* suspect);
	Suspect* getAssignedSuspect();
	void performJob();
	virtual ~PoliceOfficer();
};

#endif /* POLICEOFFICER_HPP_ */
