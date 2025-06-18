# CANTEEN BILLING SYSTEM

_Transforming Transactions, Empowering Seamless Business Growth_

![last commit today](https://img.shields.io/badge/last%20commit-today-brightgreen) ![C++](https://img.shields.io/badge/language-C%2B%2B-blue) ![Lines of Code](https://img.shields.io/badge/lines%20of%20code-200+-lightgrey)

---

## Built With

- **C++**  
- No external dependencies (uses standard library only)  
- File-based inventory storage (`inventory.txt`)  

---

## Table of Contents

1. [Features](#features)  
2. [Prerequisites](#prerequisites)  
3. [Getting Started](#getting-started)  
4. [Usage](#usage)  
5. [Inventory File Format](#inventory-file-format)  
6. [Screenshots](#screenshots)  
7. [License](#license)  

---

## Features

- ✔️ Add, display, update & remove items  
- ✔️ Generate a formatted billing receipt (`receipt.txt`)  
- ✔️ Simulate QR-code style input (`id,name,price,quantity`)  
- ✔️ Graceful exit prompt after every operation  
- ✔️ Simple file-based persistence  

---

## Prerequisites

- A C++11-compatible compiler (e.g. `g++`, Visual Studio)  
- (Windows / macOS / Linux)  
- No additional libraries required  

---

## Getting Started

1. **Clone the repo**  
   ```bash
   git clone https://github.com/your-username/canteen-billing-system.git
   cd canteen-billing-system

2. **Compile**
   ```bash
   # Linux / macOS
   g++ -std=c++11 CBS.cpp -o CBS
   ```

   ```bash
   # Windows (MinGW)
   g++ -std=c++11 CBS.cpp -o CBS.exe
   ```
   
3. **Create an initial inventory file**
   ```bash
   itemid     name        price    quantity
   1          Tea         10.0     100
   2          Coffee      20.0     50
   3          Sandwich    40.0     30

---

##Usage
```bash
# Run the program
./CBS       # or CBS.exe on Windows

