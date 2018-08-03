

# Basic-Data-Structures

## Tools used:
* Microsoft Visual Studio 2017
* Visual Memory Leak Detector - [available here](https://archive.codeplex.com/?p=vld).
VLD header file has been left included in the main handler, because it does not affect the release version of the project.

## Project description
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

## Structures overview
Base class for all implemented structures is a **Data_Structure** class. It provides basic attributes and a **to_string()** method for easier output handling in the menu.

All structures are divided into two groups:
* Array based 
* List Based

These groups were meant to provide a clear distinction between classes in the file hierarchy.
### Array Based Structures
This group includes following structures:
* Array
* Heap
* Stack

Memory operations on the array have been optimized in a way that the size expands and shrinks according to the consecutive powers of 2. The idea comes from the implementation of a vector within the STL library.

The **Heap** and **Stack** serve as extensions to already existing **Array** class.
While **Stack** is simply a class wrapper that provides the user with a clean public interface, **Heap** introduces a couple of methods concerning sorting and proper heap representation.

### List Based Structures

This group includes following structures:
* Singly-Linked List
* Doubly-Linked List

The access to specific nodes has been simplified with an iterator implementation:
* Singly-Linked List - Forward Iterator
* Doubly-Linked List - Bidirectional Iterator

Doubly Linked List is also an extension of a Singly-Linked List class, however it has to reimplement all handling methods because of bidirectional access.

## Updates
Each commit is stamped with a date which can be looked up in the *UpdateLog* file,
for information about specific changes.

