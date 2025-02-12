# Airplane Management System

## Overview
This project simulates an **Airplane Management System**, handling airplane components and employees responsible for security, maintenance, and cleaning. It includes object-oriented design with inheritance and polymorphism to model different airplane parts and personnel. The system also supports cloning, encryption, and string manipulation.

## Features
- **Employee Roles**  
  - Security Employee  
  - Maintenance Employee  
  - Cleaning Employee  
- **Airplane Components**  
  - Passenger Compartment  
  - Equipment Compartment  
  - Cargo Bay  
- **Operations**  
  - Employees work on different compartments  
  - Ready check for takeoff  
  - Cloning and comparing airplane objects  
  - String encryption and manipulation  

## File Structure
- `employee.cpp` - Defines employee roles and their responsibilities.
- `plane.cpp` - Implements the `Plane` class, managing airplane components and operations.
- `planeComp.cpp` - Handles different airplane compartments.
- `general.cpp` - Implements core object functionalities, including string operations and cloning.
- `main.cpp` - Runs the simulation, processes employees, and executes cloning and encryption logic.

## Compilation & Execution
To compile and run the project:
```sh
make all
./a.out
