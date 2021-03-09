#include "Staff.hpp"
#ifndef FIREFIGHTER_HPP_
#define FIREFIGHTER_HPP_

class FireFighter : public Staff{
//TODO add members if required
private:
    	FireFighter& operator=(const FireFighter& other);
    	FireFighter(const FireFighter& other);
public:
	FireFighter(const std::string &name);
	virtual ~FireFighter();
};

#endif /* FIREFIGHTER_HPP_ */
