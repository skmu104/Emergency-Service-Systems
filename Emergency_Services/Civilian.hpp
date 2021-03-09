#include "Human.hpp"
#ifndef CIVILIAN_HPP_
#define CIVILIAN_HPP_

class Civilian : public Human {

private:
	Civilian& operator=(const Civilian& other);
    	Civilian(const Civilian& other);
    	int debt; // private debt field, made in private so that another class cannot change the
    			  // value of debt

protected:


public:
	Civilian(const std::string &name);
	int getDebt();
	void increaseDebt(int debt);
	void decreaseDebt(int debt);
	virtual ~Civilian();
};

#endif /* CIVILIAN_HPP_ */
