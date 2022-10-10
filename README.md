# LinkedList-Implementation-using-C-Visual-Studio-
This project implements a Linked List using C++ programming language.
A linked list is a linear data structure, in which the elements are not stored at contiguous memory locations. 
Each element in the link is called a node which is composed of two parts:
a.	Data stored by the node
b.	Link pointed to the next node in the linked list

This is based on an Application of Vaccination list of patients. 

This code implements the following classes and methods:
1.	Node in the linked list with appropriate data types: each node stores the person’ name and the person’s current position (index) in the Linked List and link to the next node in the Linked List.  Every time a new person arrives, a new node is created and added to the linked list. The position (index) of new node is one more than that of the previous node.
2.	Deletion − Deletes a node at the beginning of the linked list: method signature is void deleteFirst() 
3.	Insert Last − Adds a node at the end of the linked list: method signature is void insertLast(String newPersonName)  
4.	Delete Last − Deletes a node from the end of the linked list: method signature is void deleteLast() 
5.	Insert before − Adds a node before another node (according to the provided index in the method parameter) of the linked list: method signature is void insertAfter(int index) 
6.	Delete − Deletes a node from the linked list using the index: method signature is voide deleteAfter(int index)
7.	Search – Search through the linked list to identify the first occurrence of node with match data against the target: method signature is int search(String PersonName)
8.	Display − Displays the complete linked list in a forward manner: method signature is String display( ) 

