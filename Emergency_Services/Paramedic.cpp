#include "Paramedic.hpp"
//TODO Implement Paramedic Class
Paramedic::Paramedic(const std::string &name) : Staff(name){
	//Setting parameter as field
	this->name = name;
	//initialising victim pointer to null
	this-> victim = 0;

	this->staffType = PARAMEDIC;
}

void Paramedic:: assignVictim(Victim* victim){
	//setter method to pass victim instance as parameter, to be assigned
	 this->victim = victim;



}

Victim* Paramedic::getAssignedVictim(){
	//getter method to return victim instance passed into setter method
	return this->victim;
}
void Paramedic:: performJob(){
	// when performJob method of paramedic class called, complete set to true, but also victim
	//instance passed in to assign victim methods value for treated and treatedamount is changed
	//amount treated incremented to keep count of number of times treated
	this->complete = true;
	//incases that the paramedic has been assigned to the emergency with a victm
	//but has not been directly assigned the suspect, we will not change fields of victim
	//in this method because it cannot access the corresponding victim.
if (getAssignedVictim() != 0 ){
	getAssignedVictim()->setTreated(true);
	getAssignedVictim()->incrementAmount();
}

}


Paramedic::~Paramedic(){
	//cout<<"paramedic destroyed"<<endl;
}
