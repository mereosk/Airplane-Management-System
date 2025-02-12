#ifndef PLANECOMP_H
#define PLANECOMP_H

#include "general.h"
#include "employee.h"
#include <iostream>
using namespace std;

class Employee;

class PlaneComponent:public Object{
public:
  PlaneComponent();
  virtual ~PlaneComponent();
  String toString();
  virtual bool readyCheck() = 0;
  virtual void process(Employee *emp){};
  void secPass();
  void mainPass();
  void cleanPass();
  virtual bool equal(Object *ob) = 0;
  virtual Object *clone() = 0;
protected:
};

class PassengerCompartment: public PlaneComponent{
public:
  PassengerCompartment();
  PassengerCompartment(bool inCo);
  ~PassengerCompartment();
  String toString();
  bool readyCheck();
  PassengerCompartment* getInsideComp();
  void process(Employee *emp);
  bool equal(Object *ob);
  Object *clone();
  void cleanPass();
  void secPass();
private:
  PassengerCompartment *insideComp;
  bool cleaningFlag;
  bool securityFlag;
};

class PrivateCompartment: public PlaneComponent{
public:
  PrivateCompartment();
  ~PrivateCompartment();
  String toString();
  bool readyCheck() = 0;
  virtual bool equal(Object *ob) = 0;
  virtual Object *clone() = 0;
private:
};

class EquipmentCompartment: public PrivateCompartment{
public:
  EquipmentCompartment();
  ~EquipmentCompartment();
  String toString();
  bool readyCheck();
  void process(Employee *emp);
  bool equal(Object *ob);
  Object *clone();
  void secPass();
  void mainPass();
private:
  bool securityFlag;
  bool maintenanceFlag;
};

class CargoBay: public PrivateCompartment{
public:
  CargoBay();
  ~CargoBay();
  String toString();
  bool readyCheck();
  void process(Employee *emp);
  EquipmentCompartment &getInsideEqComp();
  bool equal(Object *ob);
  Object *clone();
  EquipmentCompartment *getPointEqComp();
  void secPass();
  void mainPass();
  void cleanPass();
private:
  EquipmentCompartment eqcomp;
  bool securityFlag;
  bool maintenanceFlag;
  bool cleaningFlag;
};

#endif
