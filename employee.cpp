#include "employee.h"
#include <iostream>

using namespace std;

Employee::Employee(string inName):
  name(inName){
  cout<<"Employee just created!"<<endl;
}

Employee::~Employee(){
  cout<<"Employee to be destroyed!"<<endl;
}

String Employee::toString(){
  String temp("(Employee '"+name+"')");
  temp.concat(Object::toString());

  return temp;
}

string Employee::getName()const{
  return name;
}


SecurityEmployee::SecurityEmployee(string inName):
  Employee(inName){
  cout<<"SecurityEmployee just created!"<<endl;
}

SecurityEmployee::~SecurityEmployee(){
  cout<<"SecurityEmployee to be destroyed!"<<endl;
}

String SecurityEmployee::toString(){
  String temp("SecurityEmployee ");
  temp.concat(Employee::toString());

  return temp;
}

void SecurityEmployee::workOn(PassengerCompartment *pc){
  pc->secPass();
  cout<<"Passenger Compartment processed!"<<endl;
}

void SecurityEmployee::workOn(EquipmentCompartment *ec){
  ec->secPass();
  cout<<"Equipment Compartment processed!"<<endl;
}

void SecurityEmployee::workOn(CargoBay *cb){
  cb->secPass();
  cout<<"Cargo Bay processed!"<<endl;
}

void SecurityEmployee::report(){
  cout<<"Security Employee reported that everything is OK!"<<endl;
}

bool SecurityEmployee::equal(Object *ob){
  if((this->getId() == ob->getId()) && (this->getName() == dynamic_cast<SecurityEmployee*>(ob)->getName()))
    return true;
  return false;
}

Object *SecurityEmployee::clone(){
  SecurityEmployee *temp = new SecurityEmployee();

  temp->name = this->name;
  temp->setId(this->getId());

  return temp;
}


MaintenanceEmployee::MaintenanceEmployee(string inName):
  Employee(inName){
  cout<<"MaintenanceEmployee just created!"<<endl;
}

MaintenanceEmployee::~MaintenanceEmployee(){
  cout<<"MaintenanceEmployee to be destroyed!"<<endl;
}

String MaintenanceEmployee::toString(){
  String temp("MaintenanceEmployee ");
  temp.concat(Employee::toString());

  return temp;
}

void MaintenanceEmployee::workOn(EquipmentCompartment *ec){
  ec->mainPass();
  cout<<"Equipment Compartment processed!"<<endl;
}

void MaintenanceEmployee::workOn(CargoBay *cb){
  cb->mainPass();
  cout<<"Cargo Bay processed!"<<endl;
}

void MaintenanceEmployee::report(){
  cout<<"Maintenance Employee reported that everything is OK!"<<endl;
}

bool MaintenanceEmployee::equal(Object *ob){
  if(this->getId() == ob->getId() && (this->getName() == dynamic_cast<MaintenanceEmployee*>(ob)->getName()))
    return true;
  return false;
}

Object *MaintenanceEmployee::clone(){
  MaintenanceEmployee *temp = new MaintenanceEmployee();

  temp->name = this->name;
  temp->setId(this->getId());

  return temp;
}


CleaningEmployee::CleaningEmployee(string inName):
  Employee(inName){
  cout<<"CleaningEmployee just created!"<<endl;
}

CleaningEmployee::~CleaningEmployee(){
  cout<<"CleaningEmployee to be destroyed!"<<endl;
}

String CleaningEmployee::toString(){
  String temp("CleaningEmployee ");
  temp.concat(Employee::toString());

  return temp;
}

void CleaningEmployee::workOn(PassengerCompartment *pc){
  pc->cleanPass();
  cout<<"Passenger Compartment processed!"<<endl;
}

void CleaningEmployee::workOn(CargoBay *cb){
  cb->cleanPass();
  cout<<"Cargo Bay processed!"<<endl;
}

void CleaningEmployee::report(){
  cout<<"Cleaning reported that everything is OK!"<<endl;
}

bool CleaningEmployee::equal(Object *ob){
  if(this->getId() == ob->getId() && (this->getName() == dynamic_cast<CleaningEmployee*>(ob)->getName()))
    return true;
  return false;
}

Object *CleaningEmployee::clone(){
  CleaningEmployee *temp = new CleaningEmployee();

  temp->name = this->name;
  temp->setId(this->getId());

  return temp;
}
