#include "Civilian.hpp"
#include <iostream>
using namespace std;

Civilian::Civilian(const std::string &name) : Human(name) {
	this->name = name;//Setting parameters as fields
	this->debt = 0; //initialisng all debt for created instances to be 0
}

int Civilian::getDebt(){
	return this->debt; //getter for debt field
}

void Civilian::increaseDebt(int debt){
	this->debt += debt; // incrementing debt field by whatevers being passed as a parameter

}

void Civilian::decreaseDebt(int debt){
	//conditional statement used to display text if debt would decrease below 0,
	//setting debt to 0, and not anything below that
	if ((this->debt - debt) < 0){
		cout << "Don't overpay your debt!!"<<endl;
		this->debt = 0;
	}
	else {
		this->debt -= debt; //decrementing debt field by parameter value
	}
}
Civilian::~Civilian(){
	//cout<<"civilian destroyed"<<endl;
}


