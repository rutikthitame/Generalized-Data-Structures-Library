# 📚 Generalised Data Structures Library

**Technology:** C++ Programming  
**Category:** Data Structures & Algorithms  

---

## 📌 Project Overview
This project is a **C++ library of generic data structures** that provides **object-oriented implementations** of both **linear and non-linear data structures**.  

It offers **ready-to-use functionalities** for fundamental as well as advanced operations, designed in a **generic way using templates**, so they can be reused with **any data type**.

The library is designed with **OOP principles** (encapsulation, modularity, and extensibility), making it suitable for both **academic learning** and **real-world application development**.

---

## 🚀 Key Features

### 🔹 Linear Data Structures
- Singly Linked List  
- Singly Circular Linked List  
- Doubly Linked List  
- Doubly Circular Linked List  
- Stack (LIFO)  
- Queue (FIFO)  

### 🔹 Non-Linear Data Structures
- Binary Search Tree (**BST**) with Insert, Delete, Traversal operations  

### 🔹 Algorithms
- Searching (Linear Search, Binary Search)  
- Sorting (Bubble Sort, Selection Sort, Insertion Sort, etc.)  

### 🔹 Generic Implementation
- Implemented using **C++ templates** for **data type independence**  
- Same implementation works for integers, floats, strings, and custom objects  

### 🔹 Library Format
- Designed as a **reusable C++ library** that can be linked with client applications  

---

## 🎯 Learning Outcomes
- Mastery of **C++ Object-Oriented Programming (OOP)** principles  
- Strong foundation in **linear & non-linear data structures**  
- Hands-on experience with **generic programming using templates**  
- Practical knowledge of **searching & sorting algorithms**  
- Experience in designing **reusable libraries** for software development  

---

## 📂 Example Usage

```cpp
int main() {
    SinglyLLL<int> list;

    list.InsertFirst(10);
    list.InsertLast(20);
    list.InsertLast(30);

    list.Display();  // Output: 10 -> 20 -> 30

    return 0;
}
