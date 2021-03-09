#include "Human.hpp"
#include "Address.hpp"
#include "Civilian.hpp"

#ifndef STAFF_HPP_
#define STAFF_HPP_
//enum created to store the staff type as either;police,paramedic or firefighter
enum type{
	POLICEOFFICER,
	PARAMEDIC,
	FIREFIGTHER
};

class Staff : public Human {

private:

	Staff& operator=(const Staff& other);
    	Staff(const Staff& other);
     static int IdIncrementer; //static field created to increment everytime new instance create
protected:
     int ID;			//inherited protected fields
     bool complete;
     bool assign;
     type staffType;


public:
	Staff(const std::string &name);
	virtual void performJob();
	void setAssigned(bool assigned);
	bool isAssigned();
	bool isJobComplete();
	int getID();
	virtual ~Staff();
	type getStaffType();
};

#endif /* STAFF_HPP_ */
