#ifndef PLANE_H
#define PLANE_H

#include "general.h"
#include "planeComp.h"
#include "employee.h"
#include <string>

class Plane: public Object{
public:
  Plane(){}
  Plane(string inTitle,int inCapacity);
  ~Plane();
  String toString();
  void readyCheck();
  void process(Employee *emp);
  string getTitle()const;
  int getCapacity()const;
  CargoBay &getCBay();
  CargoBay *getPointCBay();
  EquipmentCompartment &getEqComp(int pos);
  EquipmentCompartment *getPointEqComp(int pos);
  PassengerCompartment &getPasComp(int pos);
  int getNumOfPasComp()const;
  bool equal(Object *ob);
  Object *clone();
  void deleteClone();

private:
  string title;
  int capacity;
  CargoBay cBay;
  EquipmentCompartment eqCompArray[3];
  PassengerCompartment **PasCompArray;
  int numOfPasComp;
};

#endif
