// Linked list operations in C++
#include <iostream>
#include<string>
using namespace std;

// Create a node
struct Node {
    string Name;
    int index;
    struct Node* next;
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        //constructor to create an empty LinkedList
        head = NULL;
    }

// Insert a node after a node
    void insertAfter(string newElement, int position) {

        //1. allocate node to new element
        Node* newNode = new Node();
        newNode->Name = newElement;
        newNode->next = NULL;
        //2. check if the position is > 0
        if (position < 1) {
            cout << "\nposition should be >= 1.";
        }
        //3. if the position is 1, make next of the
 //   new node as head and new node as head
        else if (position == 1) {
            newNode->next = head;
            head = newNode;
        }
        else {
            //4. Else, make a temp node and traverse to the 
//   node previous to the position

            Node* temp = head;
            for (int i = 1; i < position - 1; i++) {
                if (temp != NULL) {
                    temp = temp->next;
                }
            }


            //5. If the previous node is not null, make 
            //   newNode next as temp next and temp next 
            //   as newNode.
            if (temp != NULL) {
                newNode->next = temp->next;
                temp->next = newNode;
            }
            else {
                //6. When the previous node is null
                cout << "\nThe previous node is null.";
            }
        }
    }

// Insert at the end
void insertLast(string newElement) {
    //1. allocate node
    Node* newNode = new Node();
    //2. assign data element
    newNode->Name = newElement;
    //3. assign null to the next of new node
    newNode->next = NULL;
    //4. Check the Linked List is empty or not,
 //   if empty make the new node as head 
    if (head == NULL) {
        head = newNode;
    }
    else {
        //5. Else, traverse to the last node
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        //6. Change the next of last node to new node
        temp->next = newNode;
    }
}

// Delete a node
void deleteLast() {
    if (head != NULL) {

        //1. if head in not null and next of head
        //   is null, release the head
        Node* temp = head;
        if (temp->next == NULL) {
            head = NULL;
        }
        else {

            //2. Else, traverse to the second last 
            //   element of the list
            Node* temp = head;
            while (temp->next->next != NULL)
                temp = temp->next;

            //3. Change the next of the second 
            //   last node to null and delete the
            //   last node
            Node* lastNode = temp->next;
            temp->next = NULL;
            free(lastNode);
        }
    }
}



void deleteAfter(int position) {
    if (head == NULL)
        return;

    Node* temp = head;

    if (position == 0) {

        // Change head
        head = temp->next;

        // Free old head
        free(temp);
        return;
    }

    // Find previous node of the node to be deleted
    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;

    // If position is more than number of nodes
    if (temp == NULL || temp->next == NULL)
        return;

    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    Node* next = temp->next->next;

    // Unlink the node from linked list
    free(temp->next); // Free memory

    // Unlink the deleted node from list
    temp->next = next;
}

// Search a node
void Search(string searchValue) {

    //1. create a temp node pointing to head
    Node* temp = head;

    //2. create two variables: found - to track
    //   search, idx - to track current index
    int found = 0;
    int i = 0;

    //3. if the temp node is not null check the
    //   node value with searchValue, if found 
    //   update variables and break the loop, else
    //   continue searching till temp node is not null 
    if (temp != NULL) {
        while (temp != NULL) {
            i++;
            if (temp->Name == searchValue) {
                found++;
                break;
            }
            temp = temp->next;
        }
        if (found == 1) {
            cout << searchValue << " is found at index = " << i << ".\n";
        }
        else {
            cout << searchValue << " is not found in the list.\n";
        }
    }
    else {

        //4. If the temp node is null at the start, 
        //   the list is empty
        cout << "The list is empty.\n";
    }
}

void deleteFirst() {
    if (head != NULL) {
        //1. if head is not null, create a
 //   temp node pointing to head
        Node* temp = head;

        //2. move head to next of head
        head = head->next;
        //3. delete temp node
        free(temp);
    }
}


// Print the linked list
void Display() {
    //1. create a temp node pointing to head
    Node* temp = head;
    //2. if the temp node is not null continue 
//   displaying the content and move to the 
//   next node till the temp becomes null
    if (temp != NULL) {
        cout << "The list contains: ";
        while (temp != NULL) {
            cout <<"\n"<< temp->Name << "\n" << endl;
            temp = temp->next;
        }
        cout << endl;
    }
    //3. If the temp node is null at the start, 
 //   the list is empty
    else {
        cout << "The list is empty.\n";
    }
}
};






// Driver program
int main() {

    LinkedList Vaccinations;

   
    Vaccinations.insertLast("Jack Smith");
    Vaccinations.insertLast("Steve Smith");
    Vaccinations.insertLast("Patrick Cummins");
    Vaccinations.deleteLast();

    Vaccinations.insertLast("Virat Kohli");
    Vaccinations.insertLast("Rohit");
    Vaccinations.insertAfter("Abdul", 1);

    Vaccinations.deleteFirst();
    Vaccinations.Search("Rohit");

    Vaccinations.Display();









   

    
    
  



    
}



