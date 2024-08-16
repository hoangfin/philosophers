# philosophers
The Dining Philosophers problem is a classic synchronization problem in computer science.
It illustrates issues related to resource sharing and thread/process synchronization,
particularly in the context of avoiding deadlock and starvation. This project implements the
Dining Philosophers problem using in C language and provides a simulation to demonstrate the
behavior of the solution.

### Problem Description
The Dining Philosophers problem involves a number of philosophers sitting around a circular table.
Each philosopher alternates between thinking, eating and sleeping. A fork is placed between
each pair of adjacent philosophers. To eat, a philosopher must pick up both adjacent forks,
one at a time. The challenge is to design a protocol that ensures that no two neighboring
philosophers are eating simultaneously, avoiding deadlock and starvation.
