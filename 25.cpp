#include <iostream>
using namespace std;

class Stack 
{
private:
    struct Node 
    {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };

    Node* top;

public:
    Stack() : top(nullptr) {}

    ~Stack() 
    {
        while (!isEmpty()) 
        {
            pop();
        }
    }

    bool isEmpty() const 
    {
        return top == nullptr;
    }

    void push(int value) 
    {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    void pop() 
    {
        if (!isEmpty()) 
        {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
        else 
        {
            cout << "Stack is empty, nothing to pop." << endl;
        }
    }

    int peek() const 
    {
        if (!isEmpty()) 
        {
            return top->data;
        }
        else 
        {
            cerr << "Stack is empty, nothing to peek." << endl;
            return -1;
        }
    }

    void printStack() const 
    {
        Node* current = top;
        while (current != nullptr) 
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

class LinkedList {
private:
    struct Node 
    {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };

    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() 
    {
        clear();
    }

    void push(int value) 
    {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void printList() const
    {
        Node* current = head;
        while (current != nullptr) 
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void clear() 
    {
        Node* current = head;
        while (current != nullptr) 
        {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
    }

    LinkedList clone() const 
    {
        LinkedList clonedList;
        if (head == nullptr) 
        {
            return clonedList;
        }

        Node* current = head;
        Node* clonedTail = nullptr;
        while (current != nullptr) 
        {
            Node* newNode = new Node(current->data);
            if (clonedTail == nullptr) 
            {
                clonedList.head = newNode;
                clonedTail = newNode;
            }
            else 
            {
                clonedTail->next = newNode;
                clonedTail = newNode;
            }
            current = current->next;
        }
        return clonedList;
    }

    LinkedList operator+(const LinkedList& other) const 
    {
        LinkedList concatenatedList = clone();
        Node* current = concatenatedList.head;
        while (current != nullptr && current->next != nullptr) 
        {
            current = current->next;
        }

        Node* otherCurrent = other.head;
        while (otherCurrent != nullptr) 
        {
            Node* newNode = new Node(otherCurrent->data);
            if (current == nullptr) 
            {
                concatenatedList.head = newNode;
                current = newNode;
            }
            else 
            {
                current->next = newNode;
                current = newNode;
            }
            otherCurrent = otherCurrent->next;
        }

        return concatenatedList;
    }

    LinkedList operator*(const LinkedList& other) const 
    {
        LinkedList intersectionList;
        Node* current1 = head;
        while (current1 != nullptr) 
        {
            Node* current2 = other.head;
            while (current2 != nullptr) 
            {
                if (current1->data == current2->data) 
                {
                    Node* temp = intersectionList.head;
                    bool found = false;
                    while (temp != nullptr) 
                    {
                        if (temp->data == current1->data) 
                        {
                            found = true;
                            break;
                        }
                        temp = temp->next;
                    }
                    if (!found) 
                    {
                        intersectionList.push(current1->data);
                    }
                    break;
                }
                current2 = current2->next;
            }
            current1 = current1->next;
        }

        return intersectionList;
    }
};

int main() 
{
    //1
    Stack stack;

    stack.push(5);
    stack.push(10);
    stack.push(15);

    cout << "Top of stack: " << stack.peek() << endl;

    stack.pop();

    cout << "Stack after popping the top element:" << endl;
    stack.printStack();

    //2
    LinkedList list1;
    list1.push(5);
    list1.push(10);
    list1.push(15);

    LinkedList list2;
    list2.push(10);
    list2.push(20);
    list2.push(15);

    cout << "List 1: ";
    list1.printList();

    cout << "List 2: ";
    list2.printList();

    LinkedList clonedList = list1.clone();
    cout << "Cloned List 1: ";
    clonedList.printList();

    LinkedList concatenatedList = list1 + list2;
    cout << "Concatenated List (list1 + list2): ";
    concatenatedList.printList();

    LinkedList intersectionList = list1 * list2;
    cout << "Intersection List (list1 * list2): ";
    intersectionList.printList();
}
