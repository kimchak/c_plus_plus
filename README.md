# implementacja_c_plus_plus

This code is a text book exercise that I solved in the AGH University of Science course in computer science.

The task was to implement a rational numbers class in  C++ including operator overloading and ad-hoc polymorphism basing on a code snipet that was given. 
The expected results of the calculations were also given.

The main problem was to find proper way of introducing polymorphism for calculating numbers with different denominators and overloading operators for adding, substracting, multiplying and dividing them and then, normalizing them using the greatest common denominator which is calculated in the recurrent initialize function. Other problems included processing negative denominators and initializing rational number objects basing on existing objects.

The code is divided into two parts, the header "rational.h" in which the class is implemented ant the "rational.cpp" file in which ultimate calculations are done.
