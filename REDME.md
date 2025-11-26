# Bank System - OOP Project (C++)

## Overview
This is a **console-based banking system** implemented in **C++** using **Object-Oriented Programming (OOP)** principles.  
The project demonstrates core OOP concepts such as:
- **Encapsulation**  
- **Inheritance**  
- **Polymorphism**  
- **Composition**  

It allows managing clients and users, performing transactions, and tracking login history with permissions and security.

---

## Features
- Add, Update, Delete, Find Clients  
- Deposit, Withdraw, Transfer  
- Manage Users (Add, Update, Delete, List)  
- Login system with permissions  
- Password encryption for security  
- Login history tracking  
- User-friendly console UI  
- Fully OOP structured  
- Screenshots included to showcase the program  

---

## Project Structure

/BankSystem-OOP
│
├─ /src
│ ├─ main.cpp
│ ├─ clsUser.cpp
│ ├─ clsClient.cpp
│ └─ clsUtil.cpp
│
├─ /include
│ ├─ clsUser.h
│ ├─ clsClient.h
│ └─ clsUtil.h
│
├─ /data
│ ├─ Users.txt
│ └─ LoginRegister.txt
│
├─ /screenshots
│ └─ console_demo.png
│
└─ README.md

yaml
Copy code

---

## How to Compile and Run
1. Make sure you have a **C++ compiler** (g++, Visual Studio, etc.)  
2. Compile all `.cpp` files:
```bash
g++ src/*.cpp -o BankSystem
Run the executable:

bash
Copy code
./BankSystem   # Linux / macOS
BankSystem.exe # Windows
Demo
Screenshots of the program in action are included in the /screenshots folder:

Main Menu

Add / Update / Delete Client

Transactions (Deposit, Withdraw, Transfer)

Login history and user management

Usage
Run the program

Login with your user credentials

Navigate menus to manage clients and users

Perform transactions and check balances

Admin users can manage other users and view login history

Technologies
C++ (OOP: Classes, Inheritance, Polymorphism, Encapsulation)

File handling for persistent data

Console UI with menu-driven system

Contact
LinkedIn: https://www.linkedin.com/in/moaz-fouda-93363b271/

GitHub Repository: https://github.com/Moaz-fouda/BankSystem-OOP.git
