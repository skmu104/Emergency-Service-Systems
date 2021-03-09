#include <string>
#include <iostream>
using namespace std;
#ifndef HUMAN_HPP_
#define HUMAN_HPP_

class Human {

private:
	
    	Human& operator=(const Human& other);
    	Human(const Human& other);

protected:
    	std::string name;// made name field protected so that derived classes of derived classes can access

public:
	Human(const std::string &name);
	std::string getName();
	virtual ~Human();
};

#endif /* HUMAN_HPP_ */
