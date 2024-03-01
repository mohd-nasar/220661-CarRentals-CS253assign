//Mohd Nasar Siddiqui 220661


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

class Custoumer;
class Manager;
class Car;
class Employee;

class Car {
private:
    string model;
    string condition = "Good";
    int fineperday;
    int dailycharge;
    int minimumCutomerRating;
    bool isavaiable = true;
    bool carFound = false;
    string RentedTO;
public:
    vector<Custoumer*> pendingrentrequests;

    void addcar();
    friend void displaycars();
    friend void updatecar(Car &car);
    friend void deletecar(const string& model);

    Car() = default;
    Car(string model, int fineperday, int dailycharge, int minimumCutomerRating);

    static vector<Car> carlist;
    void showAvaliableCars(bool onlyavaliable);
    void showCarDetail();
    void showpendingrequests();
    friend Car& findCarByModel(const string& model);
    string getmodel () const;
    string getcondition() const;
    int getfineperday  () const ;
    int getdailycharge() const ;
    int getminimumcustoumerrating() const;
    bool getcaravailablestatus() const;
    bool iscarfound() const ;
    string rentedto() const ;

    void setModel(const string& newModel);
    void setCondition(const string& newCondition);
    void setFinePerDay(int newFinePerDay);
    void setDailyCharge(int newDailyCharge);
    void setMinimumCustomerRating(int newMinimumCustomerRating);
    void setCarAvailableStatus(bool newStatus);
    void setCarFoundStatus(bool newStatus);
    void setRentedTo(const string& newRentedTo);
};

vector<Car> Car::carlist;

Car::Car(string model, int fineperday, int dailycharge, int minimumCutomerRating) {
    this->model = model;
    this->fineperday = fineperday;
    this->minimumCutomerRating = minimumCutomerRating;
    this->dailycharge = dailycharge;
    carFound = true;
    carlist.push_back(*this);
}

string Car::getmodel() const{
    return model;
}
string Car::getcondition() const {
    return condition;
}

int Car::getfineperday()  const{
    return fineperday;
}

int Car::getdailycharge() const {
    return dailycharge;
}

int Car::getminimumcustoumerrating() const {
    return minimumCutomerRating;
}

bool Car::getcaravailablestatus() const  {
    return isavaiable;
}

bool Car::iscarfound() const {
    return carFound;
}

string Car::rentedto() const {
    return RentedTO;
}

void Car::setModel(const string& newModel) {
    model = newModel;
}

void Car::setCondition(const string& newCondition) {
    condition = newCondition;
}

void Car::setFinePerDay(int newFinePerDay) {
    fineperday = newFinePerDay;
}

void Car::setDailyCharge(int newDailyCharge) {
    dailycharge = newDailyCharge;
}

void Car::setMinimumCustomerRating(int newMinimumCustomerRating) {
    minimumCutomerRating = newMinimumCustomerRating;
}

void Car::setCarAvailableStatus(bool newStatus) {
    isavaiable = newStatus;
}

void Car::setCarFoundStatus(bool newStatus) {
    carFound = newStatus;
}

void Car::setRentedTo(const string& newRentedTo) {
    RentedTO = newRentedTo;
}

Car& findCarByModel(const string& model) {
    for (auto& car : Car::carlist) {
        if (car.getmodel() == model) {
            return car;
        }
    }
    static Car notFound;
    return notFound;
}

class User {
private:
    string name;
    int todaydate;
    int age;
    string password;
    double custoumerRating = 3.0;
    double totalFineImposed;
    int carRentLimit = 3;
    int rentfromdate;
    int returndate;
  
    
public:
    virtual bool authorize(string password) = 0;
    int ID = 0;
    vector<Car*> requestCarsforRent;
    void getUserDetail();
    vector<Car*> rentedCars;
    void postRentRequests(Custoumer& custoumer, string model);
    string getName() const;
    int getTodayDate() const;
    int getAge() const;
    string getPassword() const;
    double getCustomerRating() const;
    double getTotalFineImposed() const;
    int getCarRentLimit() const;
    int getRentFromDate() const;
    int getReturnDate() const;
    int getID() const;

    // Setter functions
    void setName(const string& newName);
    void setTodayDate(int newTodayDate);
    void setAge(int newAge);
    void setPassword(const string& newPassword);
    void setCustomerRating(double newCustomerRating);
    void setTotalFineImposed(double newTotalFineImposed);
    void setCarRentLimit(int newCarRentLimit);
    void setRentFromDate(int newRentFromDate);
    void setReturnDate(int newReturnDate);
};

// Implementation of getter functions
string User::getName() const {
    return name;
}

int User::getTodayDate() const {
    return todaydate;
}

int User::getAge() const {
    return age;
}

int User::getID() const {
    return ID;
}

string User::getPassword() const {
    return password;
}

double User::getCustomerRating() const {
    return custoumerRating;
}

double User::getTotalFineImposed() const {
    return totalFineImposed;
}

int User::getCarRentLimit() const {
    return carRentLimit;
}

int User::getRentFromDate() const {
    return rentfromdate;
}

int User::getReturnDate() const {
    return returndate;
}

// Implementation of setter functions
void User::setName(const string& newName) {
    name = newName;
}

void User::setTodayDate(int newTodayDate) {
    todaydate = newTodayDate;
}

void User::setAge(int newAge) {
    age = newAge;
}

void User::setPassword(const string& newPassword) {
    password = newPassword;
}

void User::setCustomerRating(double newCustomerRating) {
    custoumerRating = newCustomerRating;
}

void User::setTotalFineImposed(double newTotalFineImposed) {
    totalFineImposed = newTotalFineImposed;
}

void User::setCarRentLimit(int newCarRentLimit) {
    carRentLimit = newCarRentLimit;
}

void User::setRentFromDate(int newRentFromDate) {
    rentfromdate = newRentFromDate;
}

void User::setReturnDate(int newReturnDate) {
    returndate = newReturnDate;
}

class Custoumer : public User, public Car {
public:
    static vector<Custoumer> custoumerlists;
    static int custoumerid;
public:    
    Custoumer() = default;
    Custoumer(string name, int age, string password) {
        this->setName(name);
        this->setAge(age);
        this->setPassword(password);
        custoumerid++;
        this->ID = custoumerid;
        custoumerlists.push_back(*this);
    };
    bool authorize(string password) {
        return this->getPassword() == password;
    }
    
    friend Custoumer& findCustoumerByID(int id);
    
    public:
        int getID ()const;
        void showCarRentRequests();
        void showRentedCars();
        void returncar();
        void showTotalAmout(Car &car);
        void setCustoumerRating(int condition);
};
int Custoumer::getID ()const {
    return ID;
}
vector<Custoumer> Custoumer::custoumerlists;
int Custoumer::custoumerid = 0;

class Employee : public Custoumer{
    public:
        static vector<Employee> employeeList;
        static int employeeid;   
    Employee() = default;
    Employee(string name, int age, string password);
    friend Employee& findEmployeeByID(int id);
    bool authorize(string password) {
        return this->getPassword() == password;
    }
    int getID() const ;
};

int Employee :: getID() const {
    return this->ID;
}
Employee::Employee(string name, int age, string password) {
        this->setName(name);
        this->setAge(age);
        this->setPassword(password);
        employeeid++;
        this->ID = employeeid;
        employeeList.push_back(*this);
    };

Employee& findEmployeeByID(int id) {
    for (auto& employee : Employee::employeeList) {
        if (employee.ID == id) {
            return employee;
        }
    }
    // Return a reference to a static variable in case no matching customer is found
    static Employee notFound;
    return notFound;
}
vector<Employee> Employee::employeeList;
int Employee::employeeid = 0 ;


class Manager : public Custoumer {
public:
    string name;
    int age;
    string password;

public:
    void approveRentRequest(Car &car, Custoumer &custoumer);
    static int managerid;
    static vector<Manager> managerslists;
    friend void displayManagers();
    friend Manager& searchmanager(int ID);
    Manager() = default;
    Manager(string name, int age, string password);
    
    bool authorize(string password) override;
    int getID() const;
};

int Manager::getID() const{
    return this->ID;
}
vector<Manager> Manager::managerslists;
int Manager::managerid = 0;

Manager::Manager(string name, int age, string password) {
    this->name = name;
    this->age = age;
    managerid++;
    this->ID = managerid;
    this->password = password;
    managerslists.push_back(*this);
}

bool Manager::authorize(string password) {
    return this->password == password;
}


void Car::addcar() {
    std::cout << "Specify the given details to add a new Car to inventory" << endl;
    string model;
    int fineperday, minimumCustoumerRating, dailycharge;
    std::cout << "Enter the model of the car : " << endl;
    std::cin >> model;
    std::cout << "Enter FinePerDay after return date (int) : " << endl;
    std::cin >> fineperday;
    std::cout << "Enter minimum customer rating required (int) : " << endl;
    std::cin >> minimumCustoumerRating;
    std::cout << "Enter the daily Rental charges of " << model << " (int) : " << endl;
    std::cin >> dailycharge;
    Car newcar(model, fineperday, dailycharge, minimumCustoumerRating);
    std::cout << "Car Added to inventory Successfully" << endl;
}

void updatecar(Car& car) {
    string newcondition;
    int new_minimumCustoumerRating;
    int new_fineperday;
    int new_dailycharge;
    std::cout << "Enter the condition : " << endl;
    std::cin >> newcondition;
    std::cout << "Update fine per day : " << endl;
    std::cin >> new_fineperday;
    std::cout << "New Min. Custoumer Rating required : " << endl;
    std::cin >> new_minimumCustoumerRating;
    std::cout << "Update the daily charge : " << endl;
    std::cin >> new_dailycharge;
    car.setCondition(newcondition);
    car.setDailyCharge(new_dailycharge);
    car.setFinePerDay(new_fineperday);
    car.setMinimumCustomerRating(new_minimumCustoumerRating);
    }

void deletecar(const string& model) {
    auto it = find_if(Car::carlist.begin(), Car::carlist.end(),
        [&model](const Car& car) { return car.getmodel() == model; });

    if (it != Car::carlist.end()) {
        Car::carlist.erase(it);
        std::cout << "Car with model '" << it->getmodel() << "' deleted successfully." << endl;
    } else {
        std::cout << "Car with model '" << it->model << "' not found." << endl;
    }
}

Custoumer& findCustoumerByID(int id) {
    for (auto& custoumer : Custoumer::custoumerlists) {
        if (custoumer.getID() == id) {
            return custoumer;
        }
    }
    // Return a reference to a static variable in case no matching customer is found
    static Custoumer notFound;
    return notFound;
}

void Custoumer::setCustoumerRating(int condition){
    double custoumerRating = this->getCustomerRating();
    switch (condition)
    {
    case 1:
        custoumerRating=custoumerRating+0.4;
        this->setCustomerRating(custoumerRating);
        if(custoumerRating>=5){
            custoumerRating = 5;
            this->setCustomerRating(custoumerRating);
        }
        break;
    case 2:
        custoumerRating=custoumerRating+0.1;
        this->setCustomerRating(custoumerRating);
        if(custoumerRating>=5){
            custoumerRating = 5;
            this->setCustomerRating(custoumerRating);
        }  
        break;
    case 3:
        custoumerRating=custoumerRating-0.2;
        this->setCustomerRating(custoumerRating);
        if(custoumerRating<=0){
            custoumerRating = 0;
            this->setCustomerRating(custoumerRating);
        }
        break;
    case 4:
        custoumerRating=custoumerRating-0.5;
        this->setCustomerRating(custoumerRating);
        if(custoumerRating<=0){
            custoumerRating = 0;
            this->setCustomerRating(custoumerRating);
        }
        break;
    case 5:
        custoumerRating=custoumerRating-1.5;
        this->setCustomerRating(custoumerRating);
        if(custoumerRating<=0){
            custoumerRating = 0;
            this->setCustomerRating(custoumerRating);
        }
        break;
    }
    this->setCarRentLimit(round(this->getCustomerRating()));
    std::cout<<"new Rating is "<<this->getCustomerRating()<<" and car renting limit is "<<this->getCarRentLimit()<<"\n\n";
}

void Custoumer::showCarRentRequests(){
    if(requestCarsforRent.empty()){
        std::cout<<"Empty !! Either you haven't posted any requests or Requested Car rented to someone else "<<endl;
        std::cout<<"\n\n";
        return;
    }
    for(auto car:this->requestCarsforRent){
        car->showCarDetail();
    }
    std::cout<<"\n\n\n";
}

template <class T>
void addUser(vector<T>& List) {
    string name, password;
    int age;
    std::cout << "Enter the name: " << endl;
    std::cin >> name;
    std::cout << "Enter the password: " << endl;
    std::cin >> password;
    std::cout << "Enter the age: " << endl;
    std::cin >> age;
    T cus(name, age, password);
    std::cout << cus.getName() << " created successfully" << endl;
}

template <class T>
void deleteUser(vector<T>& list) {
    if (list.empty()) {
        std::cout << "\nNo User to show\n\n";
        return;
    }

    int id;
    std::cout << "Enter the ID of the User to delete: ";
    std::cin >> id;

    auto it = find_if(list.begin(), list.end(), [id](const T& c) {
        return c.getID() == id;
    });

    if (it != list.end()) {
        list.erase(it);
        std::cout << "User with ID " << id << " deleted successfully." << endl;
    } else {
        std::cout << "User with ID " << id << " not found." << endl;
    }
}

template <class T>
void updateUser(vector<T>& list) {
    if (list.empty()) {
        std::cout << "\nNo User Found\n\n";
        return;
    }

    int id;
    string name;
    int age;
    double cusRating;
    std::cout << "Enter the ID of the User to update: ";
    std::cin >> id;

    auto it = find_if(list.begin(), list.end(), [id](T& c) {
        return c.getID() == id;
    });

    if (it != list.end()) {
        std::cout << "Current Information for User ID " << id << ":" << endl;
        it->getUserDetail();

        std::cout << "Enter new name: ";
        std::cin >> name;
        it->setName(name);

        std::cout << "Enter new age: ";
        std::cin >> age;
        it->setAge(age);

        std::cout << "Enter the new User Rating: ";
        std::cin >> cusRating;
        it->setCustoumerRating(cusRating);

        std::cout << "User information updated successfully." << endl;
    } else {
        std::cout << "User with ID " << id << " not found." << endl;
    }
}
template <class T>
void showAllUsers(const vector<T> &list) {
    for (const auto &user : list) {
        std::cout << "User ID:             " << user.getID() << endl;
        std::cout << "User name:           " << user.getName() << endl;
        std::cout << "User age:            " << user.getAge() << endl;
        std::cout << "User Rating:         " << user.getCustomerRating() << endl;
        std::cout << "User car Rent limit: " << user.getCarRentLimit() << endl;
        std::cout << endl;
        std::cout << "\t-----------------\t" << endl;
    }
    std::cout << "\n";
}

void User::getUserDetail(){
        std::cout << "User ID :             " << this->getID() <<endl;
        std::cout << "User name :           " << this->getName() <<endl;
        std::cout << "User age :            " << this->getAge() << endl;
        std::cout << "User Rating :         "<< this->getCustomerRating()<<endl;
        std::cout << "User car Rent limit : "<<this->getCarRentLimit()<<endl;
        std::cout << "rent date :                "<< this->getRentFromDate()<<endl;
        std::cout << "return date promised :     "<<getReturnDate()<<endl;
        std::cout <<"- - - - - - - - - - - - - - - - - - - - - - - - - - - "<<endl;
}

void Car::showAvaliableCars(bool onlyavaliable) {
    for (auto& car : Car::carlist) {
        if(car.getcaravailablestatus( )&& onlyavaliable){
            std::cout << "\tModel: " << car.getmodel() <<endl;
            std::cout<<"Condition :                  " << car.getcondition() <<endl;
            std::cout<<"Minimum Customer Rating:     " << car.getminimumcustoumerrating() <<endl;
            std::cout<<"Daily Charges :          Rs. " << car.getdailycharge() <<endl;
            std::cout<<"Fine Per Day :           Rs. " << car.getfineperday() << endl;
        }    
            if(!onlyavaliable){
            std::cout << "\t\tModel:  " << car.model <<endl;
            std::cout<<"Condition :                  " << car.getcondition() <<endl;
            std::cout<<"Minimum Customer Rating:     " << car.getminimumcustoumerrating() <<endl;
            std::cout<<"Daily Charges :          Rs. " << car.getdailycharge() <<endl;
            std::cout<<"Fine Per Day :           Rs. " << car.getfineperday() << endl;
            std::cout<<" Car avalibale :          " <<car.getcaravailablestatus()<<endl;
                if(!car.getcaravailablestatus()){
                    std::cout<<"\n Already Rented "<< car.rentedto()<<endl;
                   
                }
                else if(car.pendingrentrequests.empty()){
                    std::cout<<"No pending requests found (Not rented to anyone) "<<endl;
                    
                }
                else if(!car.pendingrentrequests.empty()){
                        std::cout<<"\nList of Rent Requests "<<endl;
                        for(auto custoumer : car.pendingrentrequests){
                            custoumer->getUserDetail();
                            }
                        }
                }
            std::cout<<"\n";
            std::cout<<"\t----------------------------------------\t"<<endl;
            std::cout<<"\n";
        
    }
}

void Custoumer::showRentedCars() {
    std::cout<<"\n\n";
    std::cout<<"        Rent List of "<<this->getName()<<endl;
    if(rentedCars.empty()){
        std::cout<<"    Empty you haven't rented a car "<<endl;
        std::cout<<"\n\n";
        return;
    }
    for (auto& car : this->rentedCars) {
        car->showCarDetail();
        std::cout<<"Rented date          :"<<this->getRentFromDate()<<endl;
        std::cout<<"Return date          :"<<this->getReturnDate()<<endl;
        std::cout<<"-------------------------------------------------------------------------"<<endl;
    }
    std::cout << "\n\n";
}
void User::postRentRequests(Custoumer& custoumer, string model) {
    std::cout<<"\n\n";
    Car& selectedcar = findCarByModel(model);
    if(!selectedcar.iscarfound()){
        std::cout<<"No such car found "<<endl;
        return;
    }
    std::cout << "The Car Details are given" << endl;
    selectedcar.showCarDetail();
    if(selectedcar.getminimumcustoumerrating() > custoumer.getCustomerRating()) {
        std::cout << "Custoumer Rating Required  : "<<selectedcar.getminimumcustoumerrating()<<endl;
        std::cout << "Your Rating : " << custoumer.getCustomerRating() <<endl;
        std::cout<< "Try other cars ! They are cool too\n"<<endl;
        return;
    }
    int rentfromdate, returndate;
    std::cout << "Enter when you want to rent (int): " << endl;
    std::cin >> rentfromdate;
    std::cout << "Enter till when you want it (int): " << endl;
    std::cout<<endl;
    std::cin >> returndate;
    this->setRentFromDate(rentfromdate);
    this->setReturnDate(returndate);

    selectedcar.pendingrentrequests.push_back(&custoumer);
    custoumer.requestCarsforRent.push_back(&selectedcar);
    std::cout <<"posted  Request for "<< selectedcar.getmodel() << endl;
    std::cout << selectedcar.pendingrentrequests.size() << endl;
    std::cout << "     Request is due to manger check back in 5 days!!! " << endl;
    std::cout << "NOTE: For TESTING only -- PLEASE LOGIN AS MANAGER -> 3> VISIT CAR INVENTROY -> 4> APPROVE RENT REQUEST -- (to see all rent request for all cars ,ifany)"<<endl;
    std::cout << endl;
}



void Car::showCarDetail() {
    std::cout << " \tModel: " << this->getmodel() <<endl;
    std::cout<<"Condition :               " << this->getcondition() <<endl;
    std::cout<< "Minimum Customer Rating: " << this->getminimumcustoumerrating() <<endl;
    std::cout <<"Daily Charges :       Rs." << this->getdailycharge() <<endl;
    std::cout<< "Fine Per Day :        Rs." << this->getfineperday() << endl;
    std::cout<<"\n";
    std::cout<<"\t----------------------------------------\t"<<endl;
    std::cout<<"\n";
}

void Custoumer::showTotalAmout(Car &car) {
    int todaydate;
    car.showCarDetail();
    std::cout<<"Enter today's date (int) : "<<endl;
    std::cin>>todaydate;
    this->setTodayDate(todaydate);
    if(this->getTodayDate()<this->getRentFromDate()){
        std::cout<<"You Car is getting Ready to be REndted "<<endl;
        std::cout<<"today is "<<todaydate <<" and your rent from date is "<<this->getRentFromDate()<<endl;
        std::cout<<"Getting Curious to Rent? "<<"check other cars\n\n";
        showTotalAmout(car);
    }
    else if((this->getTodayDate())>=(this->getRentFromDate()) && this->getTodayDate()<=this->getReturnDate()){
        std::cout<<"Return date for this car is "<<this->getReturnDate()<<" and rented on " <<this->getReturnDate()<<endl;
        std::cout<<"--      Total amount for this car till date is      --"<<endl;
        std::cout<<"Daily Charges\t Rs."<<car.getdailycharge()<<"*"<<(this->getTodayDate())-(this->getRentFromDate())<<endl;
        std::cout<<"Fine imposed\t  Rs."<<"0"<<endl;
        std::cout<<"Grand Total     Rs."<<(car.getdailycharge()*(this->getTodayDate()-this->getRentFromDate()))<<endl;
        std::cout<<"\n\n";
    }
    else{
        std::cout<<"Return date for this car was "<<this->getReturnDate()<<endl;
        std::cout<<"--      Total amount for this car till date is      --"<<endl;
        std::cout<<"Daily Charges\t Rs."<<car.getdailycharge()<<"*"<<this->getReturnDate()-this->getRentFromDate()<<endl;
        std::cout<<"Fine imposed\t  Rs."<<car.getfineperday()<<"*"<<this->getTodayDate()-this->getReturnDate()<<endl;
        std::cout<<"Grand Total\t     Rs."<<(car.getdailycharge()*(this->getReturnDate()-this->getRentFromDate()))+(car.getfineperday()*(this->getTodayDate()-this->getReturnDate()));
        std::cout<<"\n\n";
    }
}

void Custoumer::returncar() {
    if(this->rentedCars.empty()){
        std::cout<<"You don't have  any Rented Cars "<<endl;
        std::cout<<"\n\n";
        return;
    }
    int todaydate;
    int condition;
    string selectedmodel,userResponse;
    this->showRentedCars();
    std::cout<<"Enter the model of the car to return "<<endl;
    std::cin>>selectedmodel;
    Car *selectedcar = &findCarByModel(selectedmodel);
    if(!selectedcar->iscarfound()){
        std::cout <<" No Such Car Found "<<endl;
        return;
    }
    this->showTotalAmout(*selectedcar);
    std::cout<<"      Select the condition of the car   "<<endl;
    std::cout<<"1>Excellent"<<endl;
    std::cout<<"2>Good"<<endl;
    std::cout<<"3>Ok"<<endl;
    std::cout<<"4>Little Defect"<<endl;
    std::cout<<"5>Unsatisfactory"<<endl;
    
    std::cin>>condition;
    this->setCustoumerRating(condition);
    std::cout<<"type Return to return the car "<<endl;
    std::cin>>userResponse;
    if(userResponse == "Return"){
        selectedcar->setCarAvailableStatus(true);
        auto it = find(rentedCars.begin(), rentedCars.end(), selectedcar);
        if (it != rentedCars.end()) {
            rentedCars.erase(it);
        }
        std::cout<<"Car Retured Successfully Happy to serve you "<<endl;
        std::cout<<endl;
    }
    else{
        std::cout<<"invalid INput\n\n";
        return;
    }
}


void Manager::approveRentRequest(Car &car, Custoumer &custoumer) {
    car.setCarAvailableStatus(false);
    car.setRentedTo(custoumer.getName());
    auto it = find(custoumer.requestCarsforRent.begin(), custoumer.requestCarsforRent.end(), &car);
    if (it != custoumer.requestCarsforRent.end()) {
       custoumer.requestCarsforRent.erase(it); // Erase the car from the vector
    }
    car.pendingrentrequests.clear();
    custoumer.rentedCars.push_back(&car);
    std::cout << "Rented to " << custoumer.getName() << endl;
    std::cout << endl;
}

void displayManagers() {
    for (const auto &manager : Manager::managerslists) {
        std::cout << "Manager ID : " << manager.getID() << " Name : " << manager.getName() << " Age : " << manager.getAge() << endl;
    }
}

Manager& searchmanager(int ID) {
    for ( auto &manager : Manager::managerslists) {
        if (manager.getID() == ID) {
            return manager;
        }
    }
    static Manager  notFound;
    return notFound;
    
}

void displaycars() {
    std::cout << "List of Cars in Inventory:" << endl;
    for (auto &car : Car::carlist) {
        if (car.getcaravailablestatus()) {
            std::cout << "Model: " << car.getmodel() << ", Daily Charge: " << car.getdailycharge() << ", Minimum Customer Rating: " << car.getminimumcustoumerrating() << " ";
            std::cout << "Condition: " << car.getcondition() << " , Fine Per Day " << car.getfineperday() << endl;
        } else {
            std::cout << "Model: " << car.getmodel() << ", Daily Charge: " << car.getdailycharge() << ", Minimum Customer Rating: " << car.getminimumcustoumerrating() << " ";
            std::cout << "Condition: " << car.getcondition() << " , Fine Per Day " << car.getfineperday() << endl;
            std::cout << "Pending Requests for Rent " << endl;
            for (auto &custoumer : car.pendingrentrequests) {
                std::cout << "|>> " << custoumer->getName() << " " << custoumer->getID() << endl;
            }
        }
    }
    std::cout << "Enter the Car Model to get Details" << endl;
}

void Car::showpendingrequests() {
    if(pendingrentrequests.empty()){
        std::cout<<"Not found any requests "<<endl;
        std::cout<<"Either you haven't posted any or the request car is rented to someone else "<<endl;
        return;
    }
    for (auto &custoumer : this->pendingrentrequests) {
        std::cout <<"\tCusotumer ID : "<<custoumer->getID()<<" Custoumer Name : "<< custoumer->getName();
        std::cout<<"\nCustoumer rating : "<<custoumer->getCustomerRating()<<" Maximum Car Rent Limit : "<<custoumer->getCarRentLimit();
        std::cout<<"\nRent from date : "<<custoumer->getRentFromDate()<<" Return date promised : "<<custoumer->getReturnDate()<<endl;
        std::cout<<"\t--List of Rented Cars--\t"<<endl;
        for(auto car:custoumer->rentedCars){
            car->showCarDetail();
        }
        std::cout<<endl;
        std::cout<<endl;
    }
    std::cout<<endl;
}

void employeedashboard(Manager &manager) {
    std::cout << endl;
    std::cout << "   Welcome to employee dashboard   ~" <<manager.getName()<< endl;
    std::cout << endl;
    std::cout << "1> Add Employee " << endl;
    std::cout << "2> Delete Employee " << endl;
    std::cout << "3> Modify Employee Details " << endl;
    std::cout << "4> See all Employee " << endl;
    std::cout << "5> Go back "<<endl;
    std::cout << "You need to visit a particular Employee to see details " << endl;

    std::cout << endl;
    int userResponse;
    std::cin >> userResponse;
    if (std::cin.fail()) {
        std::cout << "Only Integers Response " << endl;
        std::cin.clear();
        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    switch (userResponse) {
        case 1:
            addUser(Employee::employeeList);
            employeedashboard(manager);
            break;
        case 2:
            showAllUsers(Employee::employeeList);
            deleteUser(Employee::employeeList);
            employeedashboard(manager);
            break;
        case 3:
            showAllUsers(Employee::employeeList);
            updateUser(Employee::employeeList);
            employeedashboard(manager);
            break;
        case 4:
            showAllUsers(Employee::employeeList);
            employeedashboard(manager);
            break;
        default:
            break;
    }
    return;
}
void custoumerdashboard(Manager &manager) {
    std::cout << endl;
    std::cout << "   Welcome to custoumer dashboard   ~" <<manager.getName()<< endl;
    std::cout << endl;
    std::cout << "1> Add Custoumer " << endl;
    std::cout << "2> Delete Custoumer " << endl;
    std::cout << "3> Modify Custoumer Details " << endl;
    std::cout << "4> See all Custoumer " << endl;
    std::cout << "5> Go back "<<endl;
    std::cout << "You need to visit a particular custoumer to see details " << endl;

    std::cout << endl;
    int userResponse;
    std::cin >> userResponse;
    if (std::cin.fail()) {
        std::cout << "Only Integers Response " << endl;
        std::cin.clear();
        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    switch (userResponse) {
        case 1:
            addUser(Custoumer::custoumerlists);
            custoumerdashboard(manager);
            break;
        case 2:
            showAllUsers(Custoumer::custoumerlists);
            deleteUser(Custoumer::custoumerlists);
            custoumerdashboard(manager);
            break;
        case 3:
            showAllUsers(Custoumer::custoumerlists);
            updateUser(Custoumer::custoumerlists);
            custoumerdashboard(manager);
            break;
        case 4:
            showAllUsers(Custoumer::custoumerlists);
            custoumerdashboard(manager);
            break;
        default:
            break;
    }
    return;
}
void carsdashboard(Manager &manager) {
    std::cout << "\n\n";
    std::cout << "\t\tWelcome to carsdashboard         ~" << manager.getName() << endl;
    std::cout << endl;
    std::cout << "1> Add car to inventory " << endl;
    std::cout << "2> Update Car Details " << endl;
    std::cout << "3> Delete a car " << endl;
    std::cout << "4> Approve a Rent Request" << endl;
    std::cout << "5> Display All cars in Inventory"<<endl;
    std::cout << "6> Log out "<<endl;
    std::cout << "\n\n";
    int userResponse;
    string selectedmodel;
    std::cin >> userResponse;
    if (std::cin.fail() ) {
        std::cout << "Only Integar Responses" << endl;
        std::cin.clear();
        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');                
    }
    Car* selectedcar = nullptr;
    Custoumer* selectedCustoumer = nullptr;
    switch (userResponse) {
        case 1:
            manager.addcar();
            carsdashboard(manager);
            break;
        case 2:
            if(manager.carlist.empty()){
                std::cout << "No Cars in Garage \n"<<endl;
                carsdashboard(manager);
                return;
            }
            manager.showAvaliableCars(false);
            std::cout << "Enter the model of the car to update" << endl;
            std::cin >> selectedmodel;
            selectedcar = &findCarByModel(selectedmodel);
            if(!selectedcar->iscarfound()){
                std::cout <<" No Such Car Found "<<endl;
                return;
            }
            updatecar(*selectedcar);
            std::cout<<"Car Updated Successfully\n\n";
            carsdashboard(manager);
            break;
        case 3:
            if(manager.carlist.empty()){
                std::cout << "No Cars in Garage \n"<<endl;
                carsdashboard(manager);
                return;
            }
            manager.showAvaliableCars(false);
            std::cout << "Enter the car Model to delete the car" << endl;
            std::cin >> selectedmodel;
            deletecar(selectedmodel);
            carsdashboard(manager);
            break;

        case 4:
            manager.showAvaliableCars(false);
            std::cout << "Enter the model of the car to proceed " << endl;
            std::cin >> selectedmodel;
            selectedcar = &findCarByModel(selectedmodel);
            if(!selectedcar->iscarfound()){
                std::cout <<" No Such Car Found "<<endl;
                return;
            }
            selectedcar->showCarDetail();
            if(selectedcar->pendingrentrequests.empty()){
                std::cout << " No pending requests or input the correct model \n"<<endl;
                custoumerdashboard(manager);
                return;
            }
            std::cout << "Enter customer ID to approve rent request " << endl;
            selectedcar->showpendingrequests();
            std::cin >> userResponse;
            selectedCustoumer = &findCustoumerByID(userResponse);
            if(!selectedCustoumer->getID()){
                std::cout << " No such custoumer found "<<endl;
                carsdashboard(manager);
                return;
            }
            manager.approveRentRequest(*selectedcar, *selectedCustoumer);
            carsdashboard(manager);
            break;

        case 5:
            manager.showAvaliableCars(false);
            carsdashboard(manager);
            break;

        default:
            std::cout << "visiting previous page \n"<<endl;
            break;
    }
    return;
}
void managerdashboard(Manager &manager) {
    std::cout << "\n\n";
    std::cout << "\t\tWelcome to Managers Dashboard   ~" <<manager.getName()<< endl;
    std::cout << endl;
    std::cout << "1> Visit Employee Dashboard " << endl;
    std::cout << "2> Visit Custoumer Dashboard " << endl;
    std::cout << "3> Visit Car Inventory " << endl;
    std::cout << "4> Logut "<<endl;
    std::cout << "5> Exit "<<endl;
    std::cout << endl;
    std::cout << "NOTE: you need to visit the particular page to perform operations" << endl;
    std::cout << endl;
    int userResponse;
    std::cin >> userResponse;
    if (std::cin.fail() ) {
        std::cout << "Only integer Response " << endl;
        std::cin.clear();
        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
        managerdashboard(manager);
        return;
                    
    }
    switch (userResponse) {
        case 1:
            employeedashboard(manager);
            break;

        case 2:
            custoumerdashboard(manager);
            
            break;

        case 3:
            carsdashboard(manager);
            break;
        case 4:
            std::cout << "loging out\n"<<endl;
            break;
        case 5:
            std::cout <<"Exiting the program\n"<<endl;
            exit(0);
            break;    
        default:
            break;
    }
    return;
}

bool isNumber(const string& s) {
    return !s.empty() && all_of(s.begin(), s.end(), ::isdigit);
}

void managerpage(){
    string userResponse;
    string name;
    int age;
    string password;
    std::cout<<"Enter Your ID to login into managers dashboard"<<endl;
    displayManagers();
    std::cout<<"New Manager? Enter 'Register' to Create Account or go 'Back'"<<endl;
    std::cin>>userResponse;
    if(userResponse == "Register"){
        std::cout<<"Enter your name "<<endl;
        std::cin>>name;
        std::cout<<"Enter your age "<<endl;
        std::cin>>age;
        std::cout<<"Enter password"<<endl;
        std::cin>>password;
        Manager(name,age,password);
        std::cout<<"Account created successfully please remember your password "<<endl;
        managerpage();
    }else if(userResponse == "Back"){
        return;
    }
    else{
        if (!isNumber(userResponse)) {
            std::cout << "Invalid input. Please enter a valid ID or 'Register'.\n" << endl;    
            managerpage();
            return; 
        }
        Manager &loginedinManager = searchmanager(stoi(userResponse));
        if(!loginedinManager.getID()){
            std::cout<<"Incorrect ID \n"<<endl;
            managerpage();
            return;
        }
        string password;
        int chances = 3;
        do
        {
            std::cout<<"Enter your Password Attempt "<<chances<<"/3" <<endl;
            std::cin>>password;
            chances --;
        } while (!loginedinManager.authorize(password) && chances> 0);
        if(chances>0){
            managerdashboard(loginedinManager);
            return;
        }
        else{
            std::cout<<"Attempt Exhausted"<<endl;
            
        }
        
    }
}



void userLoginPage(Custoumer* custoumer) {
    std::cout << "\n\n\n";
    std::cout << "\t   Hi " << custoumer->getName() << "  we will be happy to serve you !!!" << endl;
    std::cout << "1> View All Avaliable Cars " << endl;
    std::cout << "2> View all Rented Cars " << endl;
    std::cout << "3> Post a Rent Request " << endl;
    std::cout << "4> Return a car" << endl;
    std::cout << "5> Show total Amount" << endl;
    std::cout << "6> Show pending Requests "<<endl;
    std::cout << "7> View Profile "<<endl;
    std::cout << "8> Logout"<<endl;
    std::cout << "9> Exit"<<endl;
    //std::cout << "Note: ENTER ANY OTHER INT TO GO TO HOMEPAGE"<<endl;
    std::cout << "\n\n";

    int userResponse;
    string selectedmodel;
    std::cin >> userResponse;
    if (std::cin.fail()) {
        std::cout << "only integer responses" << endl;
        std::cin.clear();
        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
        userLoginPage(custoumer);
        return;
    }

    switch (userResponse) {
        case 1:
            if(Car::carlist.empty()) {
                std::cout << "No Cars to Rent check back later !! ";
                userLoginPage(custoumer);
                return;
            }
            std::cout<<"\n      --List of Avaliable Cars-- \n";
            custoumer->showAvaliableCars(true);
            std::cout<<"\n\n";
            userLoginPage(custoumer);
            break;
        case 2:
            custoumer->showRentedCars();
            userLoginPage(custoumer);
            break;
        case 3:
            if(Car::carlist.empty()) {
                std::cout << "No Cars to Rent check back later !! ";
                userLoginPage(custoumer);
                return;
            }
            custoumer->showAvaliableCars(true);
            std::cout << "Enter car model to post a rent request " << endl;
            std::cin >> selectedmodel;
            custoumer->postRentRequests(*custoumer, selectedmodel);
            userLoginPage(custoumer);
            break;
        case 4:
            custoumer->returncar();
            userLoginPage(custoumer);
            break;
        case 5:
            if(!custoumer->rentedCars.empty()){
                for(auto *car:custoumer->rentedCars){
                    custoumer->showTotalAmout(*car);
                } 
            }
            else{
                std::cout<<"You haven't Rented any Cars yet"<<endl;
            }
            userLoginPage(custoumer);
            break;
        case 6:
            std::cout<<"The List of Requests for Rent "<<endl;
            custoumer->showCarRentRequests();
            userLoginPage(custoumer);
            break;
                
        case 7:
            custoumer->getUserDetail();
            userLoginPage(custoumer);
            break;  
        case 8:
             std::cout <<"Logout successful"<<endl;
             break; 
        case 9:
             std::cout <<"Exiting the program"<<endl;
             exit(0);             
        default:
            break;
    }
    return;
}

void employeepage () {
    std::cout<<"\n\n\n";
    std::cout << "      Welcome to Car Rentals   " << endl;
    string userResponse;
    string name;
    int age;
    int custoumerid;
    string password;
    std::cout << "Enter Your ID and password to login into Car Rentals " << endl;
    std::cout << "New Emplyee? Enter 'Register' to Create Account or go 'Back' " << endl;
    std::cout << endl;
    std::cin >> userResponse;

    if (userResponse == "Register") {
        std::cout << "Enter your name " << endl;
        std::cin >> name;
        std::cout << "Enter your age " << endl;
        std::cin >> age;
        std::cout << "Enter password" << endl;
        std::cin >> password;
        Employee* newemployee = new Employee(name, age, password);
        std::cout << "Generated ID is " << newemployee->getID() << endl;
        std::cout << "Account created successfully please remember your password and ID for future login " << endl;
        employeepage();
        return;
    } else if(userResponse == "Back"){
        return;
    }
    else {

        if (!isNumber(userResponse)) {
            std::cout << "Invalid input. Please enter a valid ID or 'Register'." << endl;    
            employeepage();
            return; 
        }
        Employee* loginedinEmployee = &findEmployeeByID(stoi(userResponse));
        if (!loginedinEmployee->getID()) {
            std::cout << "Incorrect ID " << endl;
            employeepage();
            return;
        }
        string password;
        int chances = 3;
        do {
            std::cout << "Enter your Password "<<loginedinEmployee->getName() <<" Attempt " << chances << "/3" << endl;
            std::cin >> password;
            chances--;
        } while (!loginedinEmployee->authorize(password) && chances > 0);

        if (chances > 0) {
            userLoginPage(loginedinEmployee);
            return;
        } else {
            std::cout << "Attempt Exhausted" << endl;
            return;
        }
    }
}

void custoumerpage() {
    std::cout<<"\n\n\n";
    std::cout << "      Welcome to Car Rentals   " << endl;
    string userResponse;
    string name;
    int age;
    int custoumerid;
    string password;
    std::cout << "Enter Your ID and password to login into Car Rentals " << endl;
    std::cout << "New Custoumer? Enter 'Register' to Create Account or go 'Back'" << endl;
    std::cout << endl;
    std::cin >> userResponse;

    if (userResponse == "Register") {
        std::cout << "Enter your name " << endl;
        std::cin >> name;
        std::cout << "Enter your age " << endl;
        std::cin >> age;
        std::cout << "Enter password" << endl;
        std::cin >> password;
        Custoumer* newcustoumer = new Custoumer(name, age, password);
        std::cout << "Generated ID is " << newcustoumer->getID() << endl;
        std::cout << "Account created successfully please remember your password and ID for future login " << endl;
        custoumerpage();
        return;
    } else if(userResponse == "Back"){
        return;
    }
    else {
    
        if (!isNumber(userResponse)) {
            std::cout << "Invalid input. Please enter a valid ID or 'Register'." << endl;    
            custoumerpage();
            return; 
        }
        Custoumer* loginedinCustoumer = &findCustoumerByID(stoi(userResponse));
        if (!loginedinCustoumer->getID()) {
            std::cout << "Incorrect ID " << endl;
            custoumerpage();
            return;
        }
        string password;
        int chances = 3;
        do {
            std::cout << "Enter your Password "<<loginedinCustoumer->getName() <<" Attempt " << chances << "/3" << endl;
            std::cin >> password;
            chances--;
        } while (!loginedinCustoumer->authorize(password) && chances > 0);

        if (chances > 0) {
            userLoginPage(loginedinCustoumer);
            return;
        } else {
            std::cout << "Attempt Exhausted" << endl;
            return;
        }
    }
}
void homepage(){
    std::cout<<"       WELCOME TO CAR RENTALS      "<<endl;
    std::cout<<"1> Manager"<<endl;
    std::cout<<"2> Employee"<<endl;
    std::cout<<"3> Customer"<<endl;
    std::cout<<"4> Exit "<<endl;
    std::cout<<"NOTE: ENTER ANY OTHER INT TO GO BACK TO HOMEPAGE"<<endl;
    std::cout<<endl;
    int userDesignation;
    std::cin>>userDesignation;
    if (std::cin.fail()) {
        std::cout << "only int values allowed" << endl;
        std::cin.clear();
        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    
    }
    switch (userDesignation)
    {
    case 1:
        managerpage();
        break;
    case 2:
        employeepage();
        break;
    case 3:
        custoumerpage();
        break;
       
    case 4:
        exit(0);

    
    default:
        break;
    }
};

void initiaizedata(){
    Manager manager("manger1",65,"manager");
    Custoumer ("nasar",32,"user");
    Custoumer ("nasar",32,"user");
    Custoumer ("user2",43,"user");
    Custoumer ("user3",24,"user");
    Custoumer ("user4",54,"user");
    Employee ("asd",2343,"employee");
    Employee ("asd",2343,"employee");
    Employee ("asd",2343,"employee");
    Employee ("asd",2343,"employee");
    Employee ("asd",2343,"employee");
    Car("ferai",348,5,3);
    Car  ("lambo",283,4,3);
    Car ("kurkure",883,2,4);
    Car ("crea",334,3,2);
    Car  ("suzuki",832,4,2);
}


int main(){
    initiaizedata();
    while(1){
        homepage();
    }
    return 0 ;
}
