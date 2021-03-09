#ifndef ADDRESS_HPP_
#define ADDRESS_HPP_
#include <iostream>
class Address {
private:
	//TODO Add Members
    	Address& operator=(const Address& other);
    	Address(const Address& other);
    	int number;
        std::string street;
        std::string suburb;
    	std::string postCode;

public:
	Address(int number, std::string street, std::string suburb, std::string postcode);
	int getNumber();
	std::string getStreet();
	std::string getSuburb();
	std::string getPostcode();
	void changeAddressTo(int number, std::string street, std::string suburb, std::string postcode);

	virtual ~Address();
};

#endif /* ADDRESS_HPP_ */
