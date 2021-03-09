#include <iostream>
#include <cctype>
#include <cstdlib>
#include <vector>
#include <algorithm>

// flags to enable tests for the later parts of the assignment
//#define ENABLE_T2_TESTS
//#define ENABLE_T3_TESTS
//#define ENABLE_T4_TESTS

// include headers for classes being tested
#include "Emergency_Services/EmergencyServicesSystem.hpp"
#include "Emergency_Services/Address.hpp"
#include "Emergency_Services/Vehicle.hpp"
//#include "Flight/Date.hpp"

#ifdef ENABLE_T2_TESTS
#include "Emergency_Services/Staff.hpp"
#include "Emergency_Services/Civilian.hpp"
#include "Emergency_Services/PoliceOfficer.hpp"
#include "Emergency_Services/Paramedic.hpp"
#include "Emergency_Services/FireFighter.hpp"
#include "Emergency_Services/Suspect.hpp"
#include "Emergency_Services/Victim.hpp"

#endif /*ENABLE_T2_TESTS*/

#ifdef ENABLE_T3_TESTS
#include "Emergency_Services/Emergency.hpp"
//#include "Emergency_Services/Route.hpp"

#endif /*ENABLE_T3_TESTS*/

using namespace std;

enum TestResult { TR_PASS, TR_FAIL };

#define ASSERT(condition)                                                         \
    if ((condition) == false) {                                                   \
        cout << "FAILURE: " << __FILE__ << ":" << __LINE__ << "\n"                \
             << "\tExpression '" << #condition << "' evaluated to false" << endl; \
        return TR_FAIL;                                                           \
    }

/*
 This checks that you are returning your UoA username (formally known as UPI)
 */
TestResult testUPI() {
    string upi = EmergencyServicesSystem::author();

    // UPIs should be at least 4 characters long
    ASSERT(upi.size() >= 4);
    // First character should be alphabetic
    ASSERT(isalpha(upi[0]));
    // Last 3 characters should be numeric
    ASSERT(isdigit(upi[upi.size() - 1]));
    ASSERT(isdigit(upi[upi.size() - 2]));
    ASSERT(isdigit(upi[upi.size() - 3]));

    // If nothing went wrong, the test passed
    return TR_PASS;
}

/*
 * Test creating an instance of the Country class creates it with the correct name and language,
 * and that the getName() and getLanguage() methods work properly.
 * */
TestResult testVehicle() {
	Vehicle firetruck("Firetruck", 10);
	ASSERT(firetruck.getName() == "Firetruck");
	ASSERT(firetruck.getCapacity() == 10);

    return TR_PASS;
}

/*
 * Test creating an instance of the Address class creates it with valid parameters
 * getter methods work properly
 * */
TestResult testAddress() {
	Address address(50, "Wallaby Way", "Sydney", "2357");
	ASSERT(address.getNumber() == 50);
	ASSERT(address.getStreet() == "Wallaby Way");
	ASSERT(address.getSuburb() == "Sydney");
	ASSERT(address.getPostcode() == "2357");
   // Date time(1, 4);
    //ASSERT(time.getDay() == 1);
    //ASSERT(time.getHour() == 4);

    return TR_PASS;
}

/*
 * Check the default values are applied to incorrect address
 * */
TestResult testAddressIncorrect() {

	Address address(5, "Wallaby Way", "Sydney", "5500");
	ASSERT(address.getNumber() == 10);
	ASSERT(address.getStreet() == "Wallaby Way");
	ASSERT(address.getSuburb() == "Sydney");
	ASSERT(address.getPostcode() == "1111");
    return TR_PASS;
}

/*
 * Check if address is changed correctly
 * */
TestResult testChangeAddress() {
	Address address(50, "Wallaby Way", "Sydney", "2357");
	address.changeAddressTo(333,"Sesame Street", "Manhattan", "1234");
	ASSERT(address.getNumber() == 333);
	ASSERT(address.getStreet() == "Sesame Street");
	ASSERT(address.getSuburb() == "Manhattan");
	ASSERT(address.getPostcode() == "1234");

	return TR_PASS;
}

#ifdef ENABLE_T2_TESTS

/* Test the behavior of the Civilian class */
TestResult testCivilian() {

	Civilian* james = new Civilian("James");
	ASSERT(james->getDebt() == 0);
	james->increaseDebt(500);
	ASSERT(james->getDebt() == 500);
	james->decreaseDebt(200);
	ASSERT(james->getDebt() == 300);

    Human *jamesHuman = james;
    ASSERT(jamesHuman->getName() == "James");

    return TR_PASS;
}

/* Test the behavior of the Firefighter class */
TestResult testFireFighter() {

	FireFighter *bob = new FireFighter("bob");

	ASSERT(bob->isJobComplete() == false);
	bob->performJob();
	ASSERT(bob->isJobComplete() == true);

    return TR_PASS;
}

/* Test the behavior of the Paramedic class */
TestResult testParamedic() {

	Paramedic *bob = new Paramedic("bob");
	Victim *john = new Victim("john");

	bob->assignVictim(john);
	ASSERT(bob->getAssignedVictim() == john);

	ASSERT(bob->isJobComplete() == false);
	bob->performJob();
	ASSERT(bob->isJobComplete() == true);

    return TR_PASS;
}



/* Test the behavior of the PoliceOfficer class */
TestResult testPoliceOfficer() {

	PoliceOfficer *polly = new PoliceOfficer("Polly");
	Suspect *john = new Suspect("john");

	polly->assignSuspect(john);
	ASSERT(polly->getAssignedSuspect() == john);

	ASSERT(polly->isJobComplete() == false);
	polly->performJob();
	ASSERT(polly->isJobComplete() == true);

    return TR_PASS;
}

/* Test the behavior of the Suspect class */
TestResult testSuspect() {

	PoliceOfficer *bob = new PoliceOfficer("bob");
	Suspect* james = new Suspect("James");

	bob->assignSuspect(james);
	ASSERT(james->getName() == "James");
	ASSERT(james->isCaught() == false);

	bob->performJob();
	ASSERT(james->isCaught() == true);
	ASSERT(james->getCaughtByAmount() == 1);


    return TR_PASS;
}

/* Test the behavior of the Victim class */
TestResult testVictim() {

	Paramedic *bob = new Paramedic("bob");
	Victim* james = new Victim("James");

	bob->assignVictim(james);
	ASSERT(james->getName() == "James");
	ASSERT(james->isTreated() == false);

	bob->performJob();
	ASSERT(james->isTreated() == true);
	ASSERT(james->getTreatedByAmount() == 1);

    return TR_PASS;
}



#endif /*ENABLE_T2_TESTS*/

#ifdef ENABLE_T3_TESTS

/*
 * Check emergency is constructed correctly with CRITICAL status
 */
TestResult testEmergencyConstructor() {

	Address* address = new Address(50, "Wallaby Way", "Sydney", "2357");
	Suspect* fred = new Suspect("Fred");
	Victim* james = new Victim("James");
	Emergency* emergency = new Emergency(address, james, fred);

	ASSERT(emergency->getAddress() == address);
	ASSERT(emergency->getVictim() == james);
	ASSERT(emergency->getSuspect() == fred);
	ASSERT(emergency->getStatus() == CRITICAL);


	return TR_PASS;
}

/*
 * Check correctly assigning staff to an Emergency
 */
TestResult testEmergencyAssignStaff() {

	Address* address = new Address(50, "Wallaby Way", "Sydney", "2357");
	Suspect* fred = new Suspect("Fred");
	Victim* james = new Victim("James");
	Emergency* emergency = new Emergency(address, james, fred);
	Paramedic *patrick = new Paramedic("Patrick");
	PoliceOfficer *polly = new PoliceOfficer("Polly");

	emergency->assignStaff(patrick);
	emergency->assignStaff(polly);

	vector<Staff*> staff = emergency->getAssignedStaff();

	//Check assigned staff are in vector that was returned
	ASSERT((std::find(staff.begin(), staff.end(), patrick) != staff.end()) == true);
	ASSERT((std::find(staff.begin(), staff.end(), polly) != staff.end()) == true);

	//Check all staff correctly updated to assigned
	for(unsigned int i = 0; i <staff.size() ; i++){
		ASSERT(staff[i]->isAssigned() == true);
	}

    return TR_PASS;
}

/*
 * Check correctly resolving standalone emergency
 */
TestResult testEmergencyResolve() {

	Address* address = new Address(50, "Wallaby Way", "Sydney", "2357");
	Suspect* fred = new Suspect("Fred");
	Victim* james = new Victim("James");
	Emergency* emergency = new Emergency(address, james, fred);
	Paramedic *patrick = new Paramedic("Patrick");
	PoliceOfficer *polly = new PoliceOfficer("Polly");
	patrick->assignVictim(james);
	polly->assignSuspect(fred);

	emergency->assignStaff(patrick);
	emergency->assignStaff(polly);

	ASSERT(emergency->getStatus() == ASSIGNED);

	//Simulate transporting staff to emergency - completed in task 4.
	emergency->setStatus(TRANSPORTED);

	emergency->resolve();
	ASSERT(emergency->getStatus() == COMPLETED);
	ASSERT(patrick->isJobComplete() == true);
	ASSERT(polly->isJobComplete() == true);


    return TR_PASS;
}

#endif /*ENABLE_T3_TESTS*/

#ifdef ENABLE_T4_TESTS

/*
 * Check adding staff to the Emergency Services System
 */
TestResult testHireStaff() {

	EmergencyServicesSystem ems;

	Paramedic *patrick = new Paramedic("Patrick");
	PoliceOfficer *polly = new PoliceOfficer("Polly");
	FireFighter *faye = new FireFighter("Faye");

	ems.hireParamedic(patrick);
	ems.hirePoliceOfficer(polly);
	ems.hireFireFighter(faye);

	ASSERT(ems.getStaffCount() == 3);

    return TR_PASS;
}

/*
 * Check assigning staff to an emergency
 */
TestResult testAssignStaffToEmergency() {
	EmergencyServicesSystem ems;

	Address* address = new Address(50, "Wallaby Way", "Sydney", "2357");
	Suspect* fred = new Suspect("Fred");
	Victim* james = new Victim("James");
	Paramedic *patrick = new Paramedic("Patrick");
	PoliceOfficer *polly = new PoliceOfficer("Polly");
	FireFighter *faye = new FireFighter("Faye");
	Emergency* emergency = new Emergency(address, james, fred);

	ems.hireParamedic(patrick);
	ems.hirePoliceOfficer(polly);
	ems.hireFireFighter(faye);
	ems.addEmergency(emergency);

	ASSERT(ems.assignStaffToEmergency(address, 1, 1, 1) == true);
	ASSERT(emergency->getStatus() == ASSIGNED);
	ASSERT(patrick->isAssigned() == true);
	ASSERT(polly->isAssigned() == true);
	ASSERT(faye->isAssigned() == true);

    return TR_PASS;
}

/*
 * Check booking of tickets
 */
TestResult testTransportStaff() {

	EmergencyServicesSystem ems;

	Address* address = new Address(50, "Wallaby Way", "Sydney", "2357");
	Suspect* fred = new Suspect("Fred");
	Victim* james = new Victim("James");
	Paramedic *patrick = new Paramedic("Patrick");
	PoliceOfficer *polly = new PoliceOfficer("Polly");
	FireFighter *faye = new FireFighter("Faye");
	Emergency* emergency = new Emergency(address, james, fred);

	Vehicle* car = new Vehicle("car", 4);

	ems.hireParamedic(patrick);
	ems.hirePoliceOfficer(polly);
	ems.hireFireFighter(faye);
	ems.buyVehicle(car);
	ems.addEmergency(emergency);

	ASSERT(ems.assignStaffToEmergency(address, 1, 1, 1) == true);

	ASSERT(ems.transportStaff(emergency->getAddress()) == true);
	ASSERT(emergency->getStatus() == TRANSPORTED);

    return TR_PASS;
}

TestResult testResolveEmergency() {

	EmergencyServicesSystem ems;

	Address* address = new Address(50, "Wallaby Way", "Sydney", "2357");
	Suspect* fred = new Suspect("Fred");
	Victim* james = new Victim("James");
	Paramedic *patrick = new Paramedic("Patrick");
	PoliceOfficer *polly = new PoliceOfficer("Polly");
	FireFighter *faye = new FireFighter("Faye");
	Emergency* emergency = new Emergency(address, james, fred);

	Vehicle* car = new Vehicle("car", 4);

	ems.hireParamedic(patrick);
	ems.hirePoliceOfficer(polly);
	ems.hireFireFighter(faye);
	ems.buyVehicle(car);
	ems.addEmergency(emergency);

	ems.assignStaffToEmergency(address, 1, 1, 1);
	ems.transportStaff(address);

	ASSERT(ems.resolveEmergency(address));
	ASSERT(emergency->getStatus() == COMPLETED);

    return TR_PASS;
}

#endif /*ENABLE_T4_TESTS*/

/*
This function collects up all the tests as a vector of function pointers. If you create your own
tests and want to be able to run them, make sure you add them to the `tests` vector here.
*/

vector<TestResult (*)()> generateTests() {
    vector<TestResult (*)()> tests;

    tests.push_back(&testUPI);
    tests.push_back(&testVehicle);
    tests.push_back(&testAddress);
    tests.push_back(&testAddressIncorrect);
    tests.push_back(&testChangeAddress);


#ifdef ENABLE_T2_TESTS
    tests.push_back(&testCivilian);
    tests.push_back(&testPoliceOfficer);
    tests.push_back(&testParamedic);
#endif /*ENABLE_T2_TESTS*/

#ifdef ENABLE_T3_TESTS
    tests.push_back(&testEmergencyConstructor);
    tests.push_back(&testEmergencyAssignStaff);
    tests.push_back(&testEmergencyResolve);
#endif /*ENABLE_T3_TESTS*/

#ifdef ENABLE_T4_TESTS
    tests.push_back(&testHireStaff);
    tests.push_back(&testAssignStaffToEmergency);
    tests.push_back(&testTransportStaff);
    tests.push_back(&testResolveEmergency);

#endif /*ENABLE_T4_TESTS*/

    return tests;
}

int main(int argc, char const* argv[]) {

    // If one or more test numbers are passed as command-line parameters, execute them
    vector<TestResult (*)()> tests_to_run = generateTests();
    unsigned int pass_count = 0;
    unsigned int fail_count = 0;
    unsigned int run_count = 0;
    if (argc > 1) {
        for (int i = 1; i < argc; ++i) {
            unsigned int test_num = atoi(argv[i]);
            if (test_num > tests_to_run.size()) {
                cout << "ERROR: unknown test case " << test_num << endl;
                continue;
            }
            // run the test
            ++run_count;
            TestResult result = tests_to_run[test_num]();
            if (result == TR_FAIL) {
                cout << "FAIL: Test " << test_num << " failed." << endl;
                ++fail_count;
            } else {
                cout << "PASS: Test " << test_num << " passed." << endl;
                ++pass_count;
            }
        }
    } else {
        // otherwise, run all tests
        // Make sure to update this section as you add more tests
        // Add the tests for the first task
        for (unsigned int t = 0; t < tests_to_run.size(); ++t) {
            ++run_count;
            TestResult result = tests_to_run[t]();
            if (result == TR_FAIL) {
                cout << "FAIL: Test " << t << " failed." << endl;
                ++fail_count;
            } else {
                cout << "PASS: Test " << t << " passed." << endl;
                ++pass_count;
            }
        }
    }
    cout << "\n-------------------------------------------------\n"
         << "Total Run: " << run_count << "\n"
         << "Total PASSED: " << pass_count << "\n"
         << "Total FAILED: " << fail_count << "\n"
         << "-------------------------------------------------\n" << endl;

    // Return 0 if everything was ok
    return 0;
}
