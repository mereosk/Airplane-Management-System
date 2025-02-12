#include <iostream>
#include "planeComp.h"

using namespace std;

int flag=2;

PlaneComponent::PlaneComponent(){
  cout<<"PlaneComponent just created!"<<endl;
}

PlaneComponent::~PlaneComponent(){
  cout<<"PlaneComponent to be destroyed!"<<endl;
}

String PlaneComponent::toString(){
  String temp("->(PlaneComponent)");
  temp.concat(Object::toString());

  return temp;
}


PassengerCompartment::PassengerCompartment(){
  cleaningFlag = false;
  securityFlag = false;

  if(flag==2){
    flag=rand()%2;            //temp is either 0 or 1

    if(flag)
      insideComp = new PassengerCompartment;
    else
      insideComp = NULL;
  }
  else{                       //if flag is 0 or 1
    flag=2;
    insideComp = NULL;
    cout<<"PassengerCompartment just created!"<<endl;
  }
}

PassengerCompartment::PassengerCompartment(bool inCo){
  if(inCo)
    insideComp = new PassengerCompartment(false);
  else
    insideComp = NULL;

  cleaningFlag = false;
  securityFlag = false;

  cout<<"PassengerCompartment just created!"<<endl;
}

PassengerCompartment::~PassengerCompartment(){
  if(insideComp != NULL)
    delete insideComp;
  cout<<"PassengerCompartment to be destroyed!"<<endl;
}

String PassengerCompartment::toString(){
  String temp("PassengerCompartment ");
  temp.concat(PlaneComponent::toString());

  return temp;
}

bool PassengerCompartment::readyCheck(){
  if(cleaningFlag && securityFlag){
    this->toString().print();
    cout<<"Passenger Compartment OK!"<<endl;
    return true;
  }
}

PassengerCompartment* PassengerCompartment::getInsideComp(){
  return insideComp;
}

void PassengerCompartment::process(Employee *emp){
  if(this->getInsideComp() != NULL)
    emp->workOn(this->getInsideComp());
  emp->workOn(this);
}

bool PassengerCompartment::equal(Object *ob){
  if(this->getId() != dynamic_cast<PassengerCompartment*>(ob)->getId())
    return false;
  if(this->cleaningFlag != dynamic_cast<PassengerCompartment*>(ob)->cleaningFlag)
    return false;
  if(this->securityFlag != dynamic_cast<PassengerCompartment*>(ob)->securityFlag)
    return false;

  if(this->insideComp != NULL)
    if(this->insideComp->getId() != dynamic_cast<PassengerCompartment*>(ob)->insideComp->getId())
      return false;
  return true;
}

Object *PassengerCompartment::clone(){
  PassengerCompartment *temp;
  if(this->insideComp != NULL){
    temp = new PassengerCompartment(true);
    if(!temp){
      cout<<"Error allocating memory!"<<endl;
      exit(0);
    }
  }
  else{
    temp = new PassengerCompartment(false);
    if(!temp){
      cout<<"Error allocating memory!"<<endl;
      exit(0);
    }
  }

  temp->setId(this->getId());
  if(this->insideComp != NULL)
    temp->insideComp->setId(this->insideComp->getId());

  temp->securityFlag = this->securityFlag;
  temp->cleaningFlag = this->cleaningFlag;

  return temp;
}

void PassengerCompartment::secPass(){
  securityFlag = true;
}

void PassengerCompartment::cleanPass(){
  cleaningFlag = true;
}

PrivateCompartment::PrivateCompartment(){
  cout<<"PrivateCompartment just created!"<<endl;
}

PrivateCompartment::~PrivateCompartment(){
  cout<<"PrivateCompartment to be destroyed!"<<endl;
}

String PrivateCompartment::toString(){
  String temp("->(PrivateCompartment) ");
  temp.concat(PlaneComponent::toString());

  return temp;
}


EquipmentCompartment::EquipmentCompartment(){
  maintenanceFlag = false;
  securityFlag = false;
  cout<<"EquipmentCompartment just created!"<<endl;
}

EquipmentCompartment::~EquipmentCompartment(){
  cout<<"EquipmentCompartment to be destroyed!"<<endl;
}

String EquipmentCompartment::toString(){
  String temp("EquipmentCompartment ");
  temp.concat(PrivateCompartment::toString());

  return temp;
}

bool EquipmentCompartment::readyCheck(){
  if(maintenanceFlag && securityFlag){
    this->toString().print();
    cout<<"Equipment Compartment OK!"<<endl;
    return true;
  }
}

void EquipmentCompartment::process(Employee *emp){
  emp->workOn(this);
}

bool EquipmentCompartment::equal(Object *ob){
  if(this->getId() != dynamic_cast<EquipmentCompartment*>(ob)->getId())
    return false;
  if(this->maintenanceFlag != dynamic_cast<EquipmentCompartment*>(ob)->maintenanceFlag)
    return false;
  if(this->securityFlag != dynamic_cast<EquipmentCompartment*>(ob)->securityFlag)
    return false;
  return true;
}

Object *EquipmentCompartment::clone(){
  EquipmentCompartment *temp = new EquipmentCompartment();
  if(!temp){
    cout<<"Error allocating memory!"<<endl;
    exit(0);
  }

  temp->setId(this->getId());
  temp->maintenanceFlag = this->maintenanceFlag;
  temp->securityFlag = this->securityFlag;

  return temp;
}

void EquipmentCompartment::secPass(){
  securityFlag = true;
}

void EquipmentCompartment::mainPass(){
  maintenanceFlag = true;
}



CargoBay::CargoBay(){
  cleaningFlag = false;
  maintenanceFlag = false;
  securityFlag = false;

  cout<<"CargoBay just created!"<<endl;
}

CargoBay::~CargoBay(){
  cout<<"CargoBay to be destroyed!"<<endl;
}

String CargoBay::toString(){
  String temp("CargoBay ");
  temp.concat(PrivateCompartment::toString());

  return temp;
}

bool CargoBay::readyCheck(){
  if(maintenanceFlag && securityFlag && cleaningFlag){
    this->toString().print();
    cout<<"Cargo Bay OK!"<<endl;
    return true;
  }
}

void CargoBay::process(Employee *emp){
  emp->workOn(&getInsideEqComp());
  emp->workOn(this);
}

EquipmentCompartment &CargoBay::getInsideEqComp(){
  return eqcomp;
}

bool CargoBay::equal(Object *ob){
  if(this->getId() != dynamic_cast<CargoBay*>(ob)->getId())
    return false;
  if(this->eqcomp.getId() != dynamic_cast<CargoBay*>(ob)->eqcomp.getId())
    return false;
  if(this->maintenanceFlag != dynamic_cast<CargoBay*>(ob)->maintenanceFlag)
    return false;
  if(this->securityFlag != dynamic_cast<CargoBay*>(ob)->securityFlag)
    return false;
  if(this->cleaningFlag != dynamic_cast<CargoBay*>(ob)->cleaningFlag)
    return false;
  return true;
}

Object *CargoBay::clone(){
  CargoBay *temp = new CargoBay();
  if(!temp){
    cout<<"Error allocating memory!"<<endl;
    exit(0);
  }

  temp->setId(this->getId());
  temp->eqcomp.setId(this->eqcomp.getId());
  temp->maintenanceFlag = this->maintenanceFlag;
  temp->securityFlag = this->securityFlag;
  temp->cleaningFlag = this->cleaningFlag;

  return temp;
}

EquipmentCompartment *CargoBay::getPointEqComp(){
  EquipmentCompartment *ptr = &eqcomp;

  return ptr;
}

void CargoBay::secPass(){
  securityFlag = true;
}

void CargoBay::mainPass(){
  maintenanceFlag = true;
}

void CargoBay::cleanPass(){
  cleaningFlag = true;
}
