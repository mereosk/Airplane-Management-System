#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "planeComp.h"
#include "general.h"

class PassengerCompartment;
class EquipmentCompartment;
class CargoBay;

class Employee: public Object{
public:
  Employee(string inName = "");
  virtual ~Employee();
  String toString();
  virtual void workOn(PassengerCompartment *pc){}
  virtual void workOn(EquipmentCompartment *ec){}
  virtual void workOn(CargoBay *cb) = 0;
  virtual void report() = 0;
  string getName()const;
  virtual bool equal(Object *ob) = 0;
  virtual Object *clone() = 0;
protected:
  string name;
};

class SecurityEmployee: public Employee{
public:
  SecurityEmployee(string inName = "");
  ~SecurityEmployee();
  String toString();
  void workOn(PassengerCompartment *pc);
  void workOn(EquipmentCompartment *ec);
  void workOn(CargoBay *cb);
  void report();
  bool equal(Object *ob);
  Object *clone();
private:
};

class MaintenanceEmployee: public Employee{
public:
  MaintenanceEmployee(string inName = "");
  ~MaintenanceEmployee();
  String toString();
  void workOn(EquipmentCompartment *ec);
  void workOn(CargoBay *cb);
  void report();
  bool equal(Object *ob);
  Object *clone();
private:
};

class CleaningEmployee: public Employee{
public:
  CleaningEmployee(string inName = "");
  ~CleaningEmployee();
  String toString();
  void workOn(PassengerCompartment *pc);
  void workOn(CargoBay *cb);
  void report();
  bool equal(Object *ob);
  Object *clone();
private:
};

#endif
