# Basic-Data-Structures
## Author: Krystian Plata

## Project description.
This implementation is a a partial result of a course "Data Structures and Computational Complexity".
This project's requirements were as following:
1. Implement following data structures:
	* Singly Linked List
	* Doubly Linked List
	* Array
	* Heap 
2. All of the above are to be developed without the use of libraries such as: STL or Boost.
The Red and Black Tree was also required, however it was decided to move it to a second part
of this project - "Data Structures", and introduce the Stack instead.

## Structures overwiew.

### Data Structure.
This abstract class was meant to be a highest level of relation tree.
It implements a pure virtual method : toString() and an attribute "size", 
by which every structure should be characterized.
Links used:
	* [Abstract Classes](https://www.ibm.com/support/knowledgecenter/en/SSLTBW_2.3.0/com.ibm.zos.v2r3.cbclx01/cplr142.htm)
	* Pure Virtual Functions: [Wikipedia](https://en.wikipedia.org/wiki/Virtual_function) and [cppreference](https://en.cppreference.com/w/cpp/language/abstract_class)

### Array
Sizes of the Array are consecutive powers of 2,
in order to achieve the least amount of memory accesses per insertion/deletion.

## Node
Basic unit of a List structure.
It contains a value(key) and a pointer to a next node in the list.

## NodeDL
Direct child of Node, serves as a basic unit of a Doubly Linked List structure.
Apart from parents attributes, it also contains a pointer to a previous node in the list.

## List
Implements methods for handling a group of **Node** objects.
In order to provide better traversal of a list, a forward iterator has been implemented - **ListIterator**.
Links used:
	* Iterators: [cppreference](https://en.cppreference.com/w/cpp/iterator), [Tobias Anderberg's Blog](http://anderberg.me/2016/07/04/c-custom-iterators/)

## Doubly Linked List
Quite similar to a List structure, however it provides a possibility of bidirectional traversal.
Similary to **List**, an iterator has been provided - **DLListIterator**(Bidirectional).

## Updates.
Each commit is stamped with a date which can be looked up in the *UpdateLog* file,
for information about specific changes.

*This file hasn't reached it's final form, so it doesn't describe all structures listed.*
*Next update planned on 12 July, 2018.*


