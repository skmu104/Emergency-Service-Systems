#include "FireFighter.hpp"
#include <iostream>
using namespace std;

FireFighter::FireFighter(const std::string &name) : Staff(name) {
	//Constructed using parent
	//name field set as passed in parameter
	this->name = name;

}

FireFighter::~FireFighter() {
//cout<<"fire destroyed"<<endl;
}

