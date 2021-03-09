#include "Address.hpp"
#include <iostream>
using namespace std;

Address::Address(int number, std::string street, std::string suburb, std::string postcode){
	//conditional statement so that private number field only set if number between
	//10 and 999, if number entered invalid, initialised as 10
	 if ((number > 9) & (number < 1000) ){
	        this->number = number;
	        }
	 else this->number = 10;

	 this->street = street;
	 this->suburb = suburb;
	 //conditional statement to ensure parameters entered for postcode had first two numbers
	 //between 1-4 inclusive and next two numbers between 0-9 inclusive. If number entered
	 //invalid, postcode initialised to 1111
	 if(postcode.size() == 4){
		 if((postcode[0] <(5 +48)) & (postcode[0]>(0 +48) ) & (postcode[1] < (5 +48)) & (postcode[1] > (0 +48)) ){
		 	 if ((postcode[2] < (10 + 48)) & (postcode[2] > ( 47 )) & (postcode[3] < (10 +48) ) & (postcode[3] >(47) ) ){
		 		 	 this->postCode = postcode;
		 		}
		 	 else {
		 		 this->postCode = "1111";
		 	 }
	 	 }
	 	 else {
		 	 this->postCode = "1111";
	 	 }
	 }
	 else {this->postCode = "1111";}


}

void Address::changeAddressTo(int number, std::string street, std::string suburb, std::string postcode){
	// method called to change private field values from constructor
	// same conditions used as from constructor
	//if invalid values entered default values set rather than previous constructor values
	if ((number > 9) & (number < 1000) ){
		this->number = number;
	}
	else {
		this->number = 10;
	}

	this->street = street;
	this->suburb = suburb;
	if(postcode.size() == 4){
		if((postcode[0] <(5 +48)) & (postcode[0]>(0 +48) ) & (postcode[1] < (5 +48)) & (postcode[1] > (0 +48)) ){
			if ((postcode[2] < (10 + 48)) & (postcode[2] > ( 47 )) & (postcode[3] < (10 +48) ) & (postcode[3] >(47) ) ){
		 	 	 this->postCode = postcode;
			}
			else {
				this->postCode = "1111";
			}
		}
		else {
			this->postCode = "1111";
		}
	}
	else {this->postCode = "1111";}

}

int Address::getNumber() {
	//getter for number
	return this->number;
}

std::string Address::getPostcode() {
	//getter for postcode
	return this->postCode;
}

std::string Address::getStreet() {
	//getter for street
	return this->street;
}

std::string Address::getSuburb() {
	//getter for suburb
	return this->suburb;
}

Address::~Address() {
	//cout<<"address deleted"<<endl;
}

