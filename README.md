# Airplane Management System

## Overview
This project is part of a **larger desktop application** developed using **Electron.js** for the frontend and **Java** for the backend. The C++ module presented here handles the core logic of **airplane management**, including airplane components, employee operations, cloning, and encryption. It was designed to be integrated with the Java backend for data processing and the Electron.js interface for user interaction.

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
