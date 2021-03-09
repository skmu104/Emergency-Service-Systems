#include "Civilian.hpp"
#ifndef VICTIM_HPP_
#define VICTIM_HPP_

class Victim : public Civilian {

private:

    	Victim& operator=(const Victim& other);
    	Victim(const Victim& other);
    	bool treated;//private treated field so that other classes dont have access
    				 // to the victims condition. Treated keeps track if victim has been treated
    	int treatedAmount;	//private treatedAmount used to keep track of number of times
    						//victim has been treated. Its private so that not any class can
    						//change its value.
public:
	Victim(const std::string &name);
	bool isTreated();
	int getTreatedByAmount();
	void incrementAmount();
	void setTreated(bool treated);
	virtual ~Victim();
};

#endif /* VICTIM_HPP_ */
