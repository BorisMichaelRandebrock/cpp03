# ClapTrap Project - C++ Module 03: Inheritance

## Introduction

This project is part of **C++ Module 03**, focusing on inheritance and object-oriented principles in C++. The exercises involved creating several classes that inherit from each other, simulating a hierarchy of ClapTrap robots. All tasks were developed in compliance with the **C++98 standard**, following the Orthodox Canonical Form for class design.

---

## Key Classes and Features

### 1. **ClapTrap**

The `ClapTrap` class was the foundation of the project. I implemented it with attributes such as:

- **Name** (passed as a constructor parameter)
- **Hit Points** (initialized to 10)
- **Energy Points** (initialized to 10)
- **Attack Damage** (initialized to 0)

The class supports actions like:
- **attack(target)** – Outputs a message indicating an attack.
- **takeDamage(amount)** – Reduces the hit points.
- **beRepaired(amount)** – Increases hit points, consumes energy.

Each action includes descriptive messages for easy tracking. The constructor and destructor also print messages upon their calls.

### 2. **ScavTrap**

Derived from `ClapTrap`, the `ScavTrap` class introduced new functionality with:

- **Hit Points** (initialized to 100)
- **Energy Points** (initialized to 50)
- **Attack Damage** (initialized to 20)
- **Special Mode**: `guardGate()` function, which signals that the ScavTrap is now in Gatekeeper mode.

Constructors and destructors were chained to show the proper inheritance hierarchy, and specific messages were output for each.

### 3. **FragTrap**

This class, also derived from `ClapTrap`, had different attributes:
- **Hit Points** (initialized to 100)
- **Energy Points** (initialized to 100)
- **Attack Damage** (initialized to 30)
- **Special Move**: `highFivesGuys()` function, requesting high fives in a positive tone.

Proper construction/destruction chains were ensured, with distinct messages for the FragTrap class.

### 4. **DiamondTrap**

The final class, `DiamondTrap`, inherits from both `FragTrap` and `ScavTrap`. This class combined their properties with the following key elements:

- **Name** (inherits `ClapTrap::name` with "_clap_name" suffix).
- Attributes such as **hit points**, **energy points**, and **attack damage** were taken from the respective parent classes.
- **attack()** from ScavTrap.
- **whoAmI()** – Outputs both the `DiamondTrap` name and its `ClapTrap` name.

The constructor and destructor chains were carefully crafted to ensure that `ClapTrap` was initialized only once, and the object destruction sequence followed the correct order.

---

## Summary of Achievements

In this project, I implemented multiple inheritance and demonstrated how constructors and destructors operate in an inheritance hierarchy. Each class added unique behaviors while following strict rules of C++ inheritance. All exercises have been tested with custom test cases to verify the integrity of the inheritance chain and the functionality of the special moves (`guardGate()`, `highFivesGuys()`, and `whoAmI()`).

### Additional Features

- Extensive testing to ensure all destructors and constructors print in the correct order.
- Utilized defensive coding to avoid memory leaks.
- Managed attribute shadowing using explicit calls to parent class constructors.

---

## Conclusion

This project provided deep insights into **inheritance** in C++, enhancing my understanding of how different objects relate and interact. From simple `ClapTrap` behavior to the more complex `DiamondTrap`, each class builds upon the last, demonstrating the power and flexibility of inheritance in object-oriented design.
