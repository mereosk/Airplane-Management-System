#include <iostream>
#include <cstdlib>
#include <ctime>
#include "plane.h"

Plane::Plane(string inTitle,int inCapacity):
  title(inTitle),capacity(inCapacity){
  numOfPasComp = capacity/(50+rand()%126);

  if(!numOfPasComp)     //if numOfPasComp=0 make it 1
    numOfPasComp++;

  PasCompArray = new PassengerCompartment *[numOfPasComp];
  if(!PasCompArray){
    cout<<"Error allocating memory!";
    exit(0);
  }
  for(int i=0 ; i<numOfPasComp ; i++){
    PasCompArray[i] = new PassengerCompartment(rand()%2);
    if(!PasCompArray[i]){
      cout<<"Error allocating memory!";
      exit(0);
    }
  }

  cout<<"Plane just created!"<<endl;
}

Plane::~Plane(){
  for(int i=0 ; i<numOfPasComp ; i++)
    delete PasCompArray[i];
  delete [] PasCompArray;

  cout<<"Plane to be destroyed!"<<endl;
}

String Plane::toString(){
  int i;
  String temp("Plane '"+title+"' capacity = "+to_string(capacity));
  temp.concat(Object::toString());
  temp.concat(cBay.toString());
  string tempStr="Inside ";
  temp.concat(tempStr);
  temp.concat(cBay.getInsideEqComp().toString());
  for(i=0 ; i<3 ; i++)
    temp.concat(eqCompArray[i].toString());

  for(i=0 ; i<numOfPasComp ; i++){
    temp.concat(PasCompArray[i]->toString());
    if(PasCompArray[i]->getInsideComp() != NULL){
      temp.concat(tempStr);
      temp.concat(PasCompArray[i]->getInsideComp()->toString());
    }
  }

  return temp;
}

void Plane::readyCheck(){
  bool flag = true;

  if(!cBay.readyCheck())
    flag = false;

  for(int i=0 ; i<3 ; i++)
    if(!eqCompArray[i].readyCheck())
      flag = false;

  for(int i=0 ; i<numOfPasComp ; i++)
    if(!(PasCompArray[i]->readyCheck()))
      flag = false;

  this->toString().print();

  if(flag)    //true
    cout<<"Plane ready to take off!"<<endl;
  else
    cout<<"Plane was unable to take off!"<<endl;
}

void Plane::process(Employee *emp){
  cout<<endl;
  cBay.process(emp);
  for(int i=0 ; i<3 ; i++)
    eqCompArray[i].process(emp);
  for(int i=0 ; i<numOfPasComp ; i++)
    PasCompArray[i]->process(emp);
  cout<<"Plane processed!"<<endl;
}

string Plane::getTitle()const{
  return title;
}

int Plane::getCapacity()const{
  return capacity;
}

CargoBay &Plane::getCBay(){
  return cBay;
}

CargoBay *Plane::getPointCBay(){
  CargoBay *ptr=&cBay;

  return ptr;
}

EquipmentCompartment &Plane::getEqComp(int pos){
  if(pos<0 || pos>=3)
    cout<<"Wrong position input"<<endl;
  else
    return eqCompArray[pos];
}

EquipmentCompartment *Plane::getPointEqComp(int pos){
  EquipmentCompartment *ptr = &eqCompArray[pos];

  return ptr;
}

PassengerCompartment &Plane::getPasComp(int pos){
  if(pos<0 || pos>=numOfPasComp)
    cout<<"Wrong position input"<<endl;
  else
    return *PasCompArray[pos];
}

int Plane::getNumOfPasComp()const{
  return numOfPasComp;
}

bool Plane::equal(Object *ob){
  int i;

  if(this->getId() != dynamic_cast<Plane*>(ob)->getId())
    return false;
  if(!cBay.equal(dynamic_cast<Object*>(dynamic_cast<Plane*>(ob)->getPointCBay())))
    return false;
  for(i=0 ; i<3 ; i++)
    if(!(eqCompArray[i].equal(dynamic_cast<Object*>(dynamic_cast<Plane*>(ob)->getPointEqComp(i)))))
      return false;
  for(i=0 ; i<numOfPasComp ; i++)
    if(!(PasCompArray[i]->equal(dynamic_cast<Object*>(dynamic_cast<Plane*>(ob)->PasCompArray[i]))))
      return false;
  return true;
}

Object *Plane::clone(){
  int i;
  Plane *temp = new Plane();

  temp->title = this->title;
  temp->capacity = this->capacity;
  temp->setId(this->getId());

  CargoBay *tempPtr = temp->getPointCBay();
  tempPtr = dynamic_cast<CargoBay*>(this->cBay.clone());
  temp->cBay = *tempPtr;

  delete tempPtr;

  for(i=0 ; i<3 ; i++){
    EquipmentCompartment *tempPtr = temp->getPointEqComp(i);
    tempPtr = dynamic_cast<EquipmentCompartment*>(this->eqCompArray[i].clone());
    temp->eqCompArray[i] = *tempPtr;

    delete tempPtr;
  }

  temp->numOfPasComp = this->numOfPasComp;

  temp->PasCompArray = new PassengerCompartment *[temp->numOfPasComp];
    if(!temp->PasCompArray){
      cout<<"Error allocating memory!";
      exit(0);
    }
  for(i=0 ; i<temp->numOfPasComp ; i++){
    temp->PasCompArray[i] = dynamic_cast<PassengerCompartment*>(this->PasCompArray[i]->clone());
  }
  return temp;
}

void Plane::deleteClone(){
  delete getPointCBay();
  for(int i=0 ; i<3 ; i++)
    delete getPointEqComp(i);
}
