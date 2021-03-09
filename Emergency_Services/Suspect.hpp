#include "Civilian.hpp"
#ifndef SUSPECT_HPP_
#define SUSPECT_HPP_

class Suspect : public Civilian{
//TODO Add members as needed
private:

    	Suspect& operator=(const Suspect& other);
    	Suspect(const Suspect& other);
    	bool caught;// private caught field so that any class cannot access this field
    	int caughtAmount;// private caughtAmount field so that any class cannot access this field

public:
	Suspect(const std::string &name);
	bool isCaught();
	int getCaughtByAmount();
	void setCaught(bool caught);
	void incrementAmount();
	virtual ~Suspect();
};

#endif /* SUSPECT_HPP_ */
