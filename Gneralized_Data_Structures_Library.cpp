
#include<iostream>
using namespace std;
/////////////////////////////////////////////////////////////////////////
//
//  Class :         GEN_QUEUE (Node Structure)
//  Description:    Node structure used for generic Queue implementation
//  Author :        Rutik Shivaji Thitame
//
/////////////////////////////////////////////////////////////////////////

template <class T>
struct GEN_QUEUE 
{
    T data;                        // Data of the node
    struct GEN_QUEUE<T> *next;     // Pointer to next node
};

/////////////////////////////////////////////////////////////////////////
//
//  Class :         QueueX
//  Description:    Generic implementation of Queue (FIFO principle)
//  Author :        Rutik Shivaji Thitame
//
/////////////////////////////////////////////////////////////////////////

template <class T>
class QueueX
{
    private:
        struct GEN_QUEUE<T> *first;   // Pointer to first node in queue
        int iCount;                   // Number of elements in queue

    public:
        QueueX();

        void enqueue(
                        T no
                    );

        T dequeue();

        void Display();

        int Count();
};

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : QueueX (Constructor)
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Initializes an empty queue
//  Returns         : NONE
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
QueueX<T>::QueueX()
{
   this->first = NULL;
   this->iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : enqueue
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : [IN] T no
//                    Element to be inserted in the queue
//  Description     : Inserts an element at the end of the queue
//  Returns         : void
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void QueueX<T>::enqueue(
                            T no
                        )
{
    struct GEN_QUEUE<T> *newn = new GEN_QUEUE<T>;
    struct GEN_QUEUE<T> *temp = NULL;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)   // If queue is empty
    {
        first = newn;
    }
    else                // Traverse till last node and insert
    {
        temp = first;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }

    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : dequeue
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Removes element from front of the queue and returns it
//  Returns         : T
//                    Element removed from the queue
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
T QueueX<T>::dequeue()
{
    struct GEN_QUEUE<T> *temp = NULL;
    T iValue = T();   // Initialize with default value of T

    if(first == NULL)   // If queue is empty
    {
        cout << "Unable to remove as Queue is empty\n";
        return iValue;
    }
    else
    {
        temp = first;
        iValue = temp->data;

        first = first->next;
        delete temp;

        iCount--;

        return iValue;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Display
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Displays all elements present in the queue
//  Returns         : void
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void QueueX<T>::Display()
{
    struct GEN_QUEUE<T> *temp = NULL;
    temp = first;

    while(temp != NULL)
    {
        cout << " | " << temp->data << " | -";
        temp = temp->next;
    }
    cout << "\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Count
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Returns the number of elements currently in the queue
//  Returns         : int
//                    Number of nodes in queue
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int QueueX<T>::Count()
{
    return iCount;
}
/////////////////////////////////////////////////////////////////////////
//
//  Class :         GEN_STACK (Node Structure)
//  Description:    Node structure used for generic Stack implementation
//  Author :        Rutik Shivaji Thitame
//
/////////////////////////////////////////////////////////////////////////

template <class T>
struct GEN_STACK 
{
    T data;                        // Data of the node
    struct GEN_STACK<T> *next;     // Pointer to next node
};

/////////////////////////////////////////////////////////////////////////
//
//  Class :         StackX
//  Description:    Generic implementation of Stack (LIFO principle)
//  Author :        Rutik Shivaji Thitame
//
/////////////////////////////////////////////////////////////////////////

template <class T>
class StackX
{
    private:
        struct GEN_STACK<T> *first;   // Pointer to first node (top of stack)
        int iCount;                   // Number of elements in stack

    public:
        StackX();

        void push(
                        T no
                    );

        T pop();

        void Display();

        int Count();
};

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : StackX (Constructor)
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Initializes an empty stack
//  Returns         : NONE
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
StackX<T>::StackX()
{
   this->first = NULL;
   this->iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : push
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : [IN] T no
//                    Element to be inserted in the stack
//  Description     : Inserts an element at the top of the stack
//  Returns         : void
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void StackX<T>::push(
                        T no
                    )
{
    struct GEN_STACK<T> *newn = new GEN_STACK<T>;

    newn->data = no;
    newn->next = first;
    first = newn;

    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : pop
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Removes element from top of the stack and returns it
//  Returns         : T
//                    Element removed from the stack
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
T StackX<T>::pop()
{
    struct GEN_STACK<T> *temp = NULL;
    T iValue = T();   // default initialize

    if(first == NULL)   // If stack is empty
    {
        cout << "Stack is empty\n";
        return iValue;
    }
    else
    {
        temp = first;
        iValue = temp->data;

        first = first->next;
        delete temp;

        iCount--;

        return iValue;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Display
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Displays all elements present in the stack
//  Returns         : void
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void StackX<T>::Display()
{
    struct GEN_STACK<T> *temp = NULL;
    temp = first;

    while(temp != NULL)
    {
        cout << " | " << temp->data << " | -";
        temp = temp->next;
    }
    cout << "\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Count
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Returns the number of elements currently in the stack
//  Returns         : int
//                    Number of nodes in stack
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int StackX<T>::Count()
{
    return iCount;
}

/////////////////////////////////////////////////////////////////////////
//
//  Class Name      : SinglyCLL
//  Class Date      : 15/09/2025
//  Class Author    : Rutik Shivaji Thitame
//  Description     : Generic Implementation of Singly Circular Linked List
//
/////////////////////////////////////////////////////////////////////////

template <class T>
struct GEN_SCLIST 
{
    T data;
    struct GEN_SCLIST<T> *next;
};

template <class T>
class SinglyCLL
{
    private:
        struct GEN_SCLIST<T> *first;
        struct GEN_SCLIST<T> *last;
        int iCount;

    public:
        SinglyCLL();

        void InsertFirst(
                            T
                        );

        void InsertLast(    
                            T
                        );

        void DeleteFirst();

        void DeleteLast();   

        void Display();    

        int  Count();     

        void InsertAtPos(
                            T, 
                            int
                        );

        void DeleteAtPos(
                            int
                        );

        void SearchFirstOcc(    
                                T
                            );

        void SearchLastOcc( 
                                T
                            );

        T Addition();       

        T Maximum();      

        T Minimum();      

        void DisplayPerfect(); 

        void DisplayPrime();   

        T AdditionEven();      

        T SecMaximum();             
};

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : SinglyCLL (Constructor)
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Initializes an empty circular linked list
//  Returns         : NONE
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
SinglyCLL<T>::SinglyCLL()
{
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : InsertFirst
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : T no
//                    Data to be inserted
//  Description     : Inserts a new node at the beginning of the circular linked list
//  Returns         : NONE
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::InsertFirst( 
                                    T no
                                )
{
    struct GEN_SCLIST<T> *newn = new GEN_SCLIST<T>;
    newn->data = no;
    newn->next = NULL;

    if(first == NULL && last == NULL)
    {
        first = last = newn;
        last->next = first;
    }
    else
    {
        newn->next = first;
        first = newn;
        last->next = first;
    }
    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : InsertLast
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : T no
//                    Data to be inserted
//  Description     : Inserts a new node at the end of the circular linked list
//  Returns         : NONE
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::InsertLast(
                                T no
                            )
{
    struct GEN_SCLIST<T> *newn = new GEN_SCLIST<T>;
    newn->data = no;
    newn->next = NULL;

    if(first == NULL && last == NULL)
    {
        first = last = newn;
        last->next = first;
    }
    else
    {
        last->next = newn;
        last = newn;
        last->next = first;
    }
    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : DeleteFirst
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Deletes the first node from the circular linked list
//  Returns         : NONE
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::DeleteFirst()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = last = NULL;
    }
    else
    {
        struct GEN_SCLIST<T>* temp = first;
        first = first->next;
        delete temp;
        last->next = first;
    }
    iCount--;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : DeleteLast
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Deletes the last node from the circular linked list
//  Returns         : NONE
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::DeleteLast()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = last = NULL;
    }
    else
    {
        struct GEN_SCLIST<T>* temp = first;
        while(temp->next != last)
        {
            temp = temp->next;
        }
        delete last;
        last = temp;
        last->next = first;
    }
    iCount--;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Display
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Displays all nodes of the circular linked list
//  Returns         : NONE
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::Display()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    struct GEN_SCLIST<T>* temp = first;
    do
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp->next;
    }while(temp != first);
    cout<<"(Back to first)\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Count
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Returns the number of nodes currently in the circular linked list
//  Returns         : int
//                    Number of nodes in the list
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyCLL<T>::Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : InsertAtPos
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : T no   -> Data to be inserted
//                    int pos -> Position at which to insert
//  Description     : Inserts a node at a specific position in the circular linked list
//  Returns         : NONE
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::InsertAtPos(
                                    T no, 
                                    int pos
                                )
{
    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }
    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        struct GEN_SCLIST<T>* newn = new GEN_SCLIST<T>;
        newn->data = no;
        newn->next = NULL;

        struct GEN_SCLIST<T>* temp = first;
        for(int i = 1; i < pos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : DeleteAtPos
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : int pos -> Position of node to delete
//  Description     : Deletes a node from a specific position in the circular linked list
//  Returns         : NONE
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::DeleteAtPos(
                                    int pos
                                )
{
    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid position\n";
        return;
    }
    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        struct GEN_SCLIST<T>* temp = first;
        for(int i = 1; i < pos-1; i++)
        {
            temp = temp->next;
        }
        struct GEN_SCLIST<T>* target = temp->next;
        temp->next = target->next;
        delete target;
        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : SearchFirstOcc
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : T no -> Element to search
//  Description     : Searches the first occurrence of a given element
//  Returns         : NONE (prints position if found)
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::SearchFirstOcc(
                                    T no
                                )
{
    struct GEN_SCLIST<T>* temp = first;
    int pos = -1;

    for(int i = 1; i <= iCount; i++)
    {
        if(temp->data == no)
        {
            pos = i;
            break;
        }
        temp = temp->next;
    }

    if(pos != -1)
        cout<<"First occurrence of "<<no<<" is at position "<<pos<<"\n";
    else
        cout<<no<<" not found\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : SearchLastOcc
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : T no -> Element to search
//  Description     : Searches the last occurrence of a given element
//  Returns         : NONE (prints position if found)
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::SearchLastOcc(
                                    T no
                                )
{
    struct GEN_SCLIST<T>* temp = first;
    int pos = -1;

    for(int i = 1; i <= iCount; i++)
    {
        if(temp->data == no)
        {
            pos = i;
        }
        temp = temp->next;
    }

    if(pos != -1)
        cout<<"Last occurrence of "<<no<<" is at position "<<pos<<"\n";
    else
        cout<<no<<" not found\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Addition
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Returns the sum of all elements in the circular linked list
//  Returns         : T
//                    Sum of all node values
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
T SinglyCLL<T>::Addition()
{
    T sum = 0;
    struct GEN_SCLIST<T>* temp = first;
    do
    {
        sum += temp->data;
        temp = temp->next;
    }while(temp != first);
    return sum;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Maximum
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Returns the maximum element from the circular linked list
//  Returns         : T
//                    Maximum node value
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
T SinglyCLL<T>::Maximum()
{
    T maxVal = first->data;
    struct GEN_SCLIST<T>* temp = first->next;
    do
    {
        if(temp->data > maxVal)
            maxVal = temp->data;
        temp = temp->next;
    }while(temp != first);
    return maxVal;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Minimum
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Returns the minimum element from the circular linked list
//  Returns         : T
//                    Minimum node value
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
T SinglyCLL<T>::Minimum()
{
    T minVal = first->data;
    struct GEN_SCLIST<T>* temp = first->next;
    do
    {
        if(temp->data < minVal)
            minVal = temp->data;
        temp = temp->next;
    }while(temp != first);
    return minVal;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : DisplayPerfect
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Displays all perfect numbers from the circular linked list
//  Returns         : NONE
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::DisplayPerfect()
{
    struct GEN_SCLIST<T>* temp = first;
    do
    {
        int sum = 0;
        for(int i = 1; i <= temp->data/2; i++)
        {
            if(temp->data % i == 0)
                sum += i;
        }
        if(sum == temp->data)
            cout<<temp->data<<"\t";
        temp = temp->next;
    }while(temp != first);
    cout<<"are perfect numbers\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : DisplayPrime
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Displays all prime numbers from the circular linked list
//  Returns         : NONE
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::DisplayPrime()
{
    struct GEN_SCLIST<T>* temp = first;
    do
    {
        bool prime = true;
        if(temp->data < 2) prime = false;

        for(int i = 2; i <= temp->data/2; i++)
        {
            if(temp->data % i == 0)
            {
                prime = false;
                break;
            }
        }

        if(prime)
            cout<<temp->data<<" is prime number\n";

        temp = temp->next;
    }while(temp != first);
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : AdditionEven
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Returns the sum of all even elements in the circular linked list
//  Returns         : T
//                    Sum of even node values
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
T SinglyCLL<T>::AdditionEven()
{
    T sum = 0;
    struct GEN_SCLIST<T>* temp = first;
    do
    {
        if(temp->data % 2 == 0)
            sum += temp->data;
        temp = temp->next;
    }while(temp != first);
    return sum;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : SecMaximum
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Returns the second maximum element from the circular linked list
//  Returns         : T
//                    Second largest node value
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
T SinglyCLL<T>::SecMaximum()
{
    T max1 = first->data;
    T max2 = first->data;
    struct GEN_SCLIST<T>* temp = first->next;

    do
    {
        if(temp->data > max1)
        {
            max2 = max1;
            max1 = temp->data;
        }
        else if(temp->data < max1 && temp->data > max2)
        {
            max2 = temp->data;
        }
        temp = temp->next;
    }while(temp != first);

    return max2;
}
/////////////////////////////////////////////////////////////////////////
//
//  Class :         DoublyCLL
//  Description:    Generic Implementation of Doubly Circular Linked List
//  Author :        Rutik Shivaji Thitame
//
/////////////////////////////////////////////////////////////////////////

template <class T>
struct GEN_DCLIST 
{
    T data;
    struct GEN_DCLIST<T>* next;
    struct GEN_DCLIST<T>* prev;
};

template <class T>
class DoublyCLL
{
    private:
        struct GEN_DCLIST<T>* first;
        struct GEN_DCLIST<T>* last;
        int iCount;

    public:
        DoublyCLL();

        void Display();

        int Count();

        void InsertFirst(
                            T
                        );

        void InsertLast(
                            T
                        );

        void InsertAtPos(
                            T, 
                            int
                        );

        void DeleteFirst();

        void DeleteLast();
        
        void DeleteAtPos(
                            int
                        );


        void SearchFirstOcc(
                                T
                            );

        void SearchLastOcc(
                                T
                            );

        T Addition();

        T Maximum();

        T Minimum();

        T SecMaximum();

        T AdditionEven();

        void DisplayPerfect();

        void DisplayPrime();
};

/////////////////////////////////////////////////////////////////////////
//
//  Function Name   : DoublyCLL (Constructor)
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Initializes empty doubly circular linked list
//  Returns         : NONE
//
/////////////////////////////////////////////////////////////////////////

template <class T>
DoublyCLL<T>::DoublyCLL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

/////////////////////////////////////////////////////////////////////////
//
//  Function Name   : InsertFirst
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : T no
//  Description     : Inserts node at beginning of doubly circular linked list
//  Returns         : void
//
/////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T>::InsertFirst(
                                    T no
                                )
{
    struct GEN_DCLIST<T>* newn = new GEN_DCLIST<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)   // Empty list
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }
    last->next = first;
    first->prev = last;
    iCount++;
}

/////////////////////////////////////////////////////////////////////////
//
//  Function Name   : InsertLast
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : T no
//  Description     : Inserts node at end of doubly circular linked list
//  Returns         : void
//
/////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T>::InsertLast(
                                T no
                            )
{
    struct GEN_DCLIST<T>* newn = new GEN_DCLIST<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->prev = last;
        last->next = newn;
        last = newn;
    }
    last->next = first;
    first->prev = last;
    iCount++;
}

/////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Display
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Displays all elements in doubly circular linked list
//  Returns         : void
//
/////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T>::Display()
{
    if(first == NULL && last == NULL)
    {
        cout<<"Linked List is empty\n";
        return;
    }

    struct GEN_DCLIST<T>* temp = first;
    do
    {
        cout<<" | "<<temp->data<<" | <=>";
        temp = temp->next;
    } while(temp != first);
    cout<<"\n";
}

/////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Count
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Returns number of nodes in the list
//  Returns         : int
//
/////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyCLL<T>::Count()
{
    return iCount;
}

/////////////////////////////////////////////////////////////////////////
//
//  Function Name   : DeleteFirst
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Deletes first node from doubly circular linked list
//  Returns         : void
//
/////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T>::DeleteFirst()
{
    if(first == NULL && last == NULL)   // Empty
    {
        return;
    }
    else if(first == last)              // Single node
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        struct GEN_DCLIST<T>* temp = first;
        first = first->next;
        delete temp;
        first->prev = last;
        last->next = first;
    }
    iCount--;
}

/////////////////////////////////////////////////////////////////////////
//
//  Function Name   : DeleteLast
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Deletes last node from doubly circular linked list
//  Returns         : void
//
/////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T>::DeleteLast()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete last;
        first = NULL;
        last = NULL;
    }
    else
    {
        struct GEN_DCLIST<T>* temp = last;
        last = last->prev;
        delete temp;
        last->next = first;
        first->prev = last;
    }
    iCount--;
}

/////////////////////////////////////////////////////////////////////////
//
//  Function Name   : InsertAtPos
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : T no, int pos
//  Description     : Inserts node at given position
//  Returns         : void
//
/////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T>::InsertAtPos(
                                    T no, 
                                    int pos
                                )
{
    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        struct GEN_DCLIST<T>* newn = new GEN_DCLIST<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        struct GEN_DCLIST<T>* temp = first;
        for(int i = 1; i < pos-1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->prev = temp;
        temp->next->prev = newn;
        temp->next = newn;
        iCount++;
    }
}

/////////////////////////////////////////////////////////////////////////
//
//  Function Name   : DeleteAtPos
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : int pos
//  Description     : Deletes node at given position
//  Returns         : void
//
/////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T>::DeleteAtPos(
                                    int pos
                                )
{
    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        struct GEN_DCLIST<T>* temp = first;
        for(int i = 1; i < pos-1; i++)
        {
            temp = temp->next;
        }
        struct GEN_DCLIST<T>* target = temp->next;
        temp->next = target->next;
        target->next->prev = temp;
        delete target;
        iCount--;
    }
}

/////////////////////////////////////////////////////////////////////////
//
//  Function Name   : SearchFirstOcc
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : T no
//  Description     : Searches for first occurrence of element
//  Returns         : void
//
/////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T>::SearchFirstOcc(
                                        T no
                                    )
{
    if(first == NULL) { cout<<"List is empty\n"; return; }

    struct GEN_DCLIST<T>* temp = first;
    int pos = 1;
    do
    {
        if(temp->data == no)
        {
            cout<<"First occurrence of "<<no<<" is at position "<<pos<<"\n";
            return;
        }
        pos++;
        temp = temp->next;
    }while(temp != first);

    cout<<"Element "<<no<<" not found\n";
}

/////////////////////////////////////////////////////////////////////////
//
//  Function Name   : SearchLastOcc
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : T no
//  Description     : Searches for last occurrence of element
//  Returns         : void
//
/////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T>::SearchLastOcc(   
                                    T no
                                )
{
    if(first == NULL) { cout<<"List is empty\n"; return; }

    struct GEN_DCLIST<T>* temp = first;
    int pos = 1, lastPos = -1;
    do
    {
        if(temp->data == no)
        {
            lastPos = pos;
        }
        pos++;
        temp = temp->next;
    }while(temp != first);

    if(lastPos != -1)
        cout<<"Last occurrence of "<<no<<" is at position "<<lastPos<<"\n";
    else
        cout<<"Element "<<no<<" not found\n";
}

/////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Addition
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Adds all elements from list
//  Returns         : T (sum of elements)
//
/////////////////////////////////////////////////////////////////////////

template <class T>
T DoublyCLL<T>::Addition()
{
    if(first == NULL) return T();

    T sum = 0;
    struct GEN_DCLIST<T>* temp = first;
    do
    {
        sum += temp->data;
        temp = temp->next;
    }while(temp != first);
    return sum;
}

/////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Maximum
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Returns maximum element
//  Returns         : T (maximum value)
//
/////////////////////////////////////////////////////////////////////////

template <class T>
T DoublyCLL<T>::Maximum()
{
    if(first == NULL) return T();

    T maxVal = first->data;
    struct GEN_DCLIST<T>* temp = first->next;
    do
    {
        if(temp->data > maxVal)
            maxVal = temp->data;
        temp = temp->next;
    }while(temp != first);
    return maxVal;
}

/////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Minimum
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Returns minimum element
//  Returns         : T (minimum value)
//
/////////////////////////////////////////////////////////////////////////

template <class T>
T DoublyCLL<T>::Minimum()
{
    if(first == NULL) return T();

    T minVal = first->data;
    struct GEN_DCLIST<T>* temp = first->next;
    do
    {
        if(temp->data < minVal)
            minVal = temp->data;
        temp = temp->next;
    }while(temp != first);
    return minVal;
}

/////////////////////////////////////////////////////////////////////////
//
//  Function Name   : SecMaximum
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Returns second maximum element
//  Returns         : T (second maximum value)
//
/////////////////////////////////////////////////////////////////////////

template <class T>
T DoublyCLL<T>::SecMaximum()
{
    if(first == NULL || first->next == first) return T();

    T max1 = first->data, max2 = T();
    struct GEN_DCLIST<T>* temp = first->next;
    do
    {
        if(temp->data > max1)
        {
            max2 = max1;
            max1 = temp->data;
        }
        else if(temp->data < max1 && temp->data > max2)
        {
            max2 = temp->data;
        }
        temp = temp->next;
    }while(temp != first);

    return max2;
}

/////////////////////////////////////////////////////////////////////////
//
//  Function Name   : AdditionEven
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Adds all even elements from list
//  Returns         : T (sum of even elements)
//
/////////////////////////////////////////////////////////////////////////

template <class T>
T DoublyCLL<T>::AdditionEven()
{
    if(first == NULL) return T();

    T sum = 0;
    struct GEN_DCLIST<T>* temp = first;
    do
    {
        if(temp->data % 2 == 0)
            sum += temp->data;
        temp = temp->next;
    }while(temp != first);
    return sum;
}

/////////////////////////////////////////////////////////////////////////
//
//  Function Name   : DisplayPerfect
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Displays perfect numbers from the list
//  Returns         : void
//
/////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T>::DisplayPerfect()
{
    if(first == NULL) return;

    struct GEN_DCLIST<T>* temp = first;
    do
    {
        T sum = 0;
        for(int i = 1; i <= temp->data/2; i++)
        {
            if(temp->data % i == 0)
                sum += i;
        }
        if(sum == temp->data)
            cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp != first);
    cout<<"are perfect numbers\n";
}

/////////////////////////////////////////////////////////////////////////
//
//  Function Name   : DisplayPrime
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Displays prime numbers from the list
//  Returns         : void
//
/////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T>::DisplayPrime()
{
    if(first == NULL) return;

    struct GEN_DCLIST<T>* temp = first;
    do
    {
        bool isPrime = true;
        if(temp->data < 2) isPrime = false;
        else
        {
            for(int i = 2; i <= temp->data/2; i++)
            {
                if(temp->data % i == 0)
                {
                    isPrime = false;
                    break;
                }
            }
        }
        if(isPrime)
            cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp != first);
    cout<<"are prime numbers\n";
}

/////////////////////////////////////////////////////////////////////////
//
//  Class :         SinglyLLL
//  Description:    Generic Implementation of Singly Linear Linked List
//  Author :        Rutik Shivaji Thitame
//
/////////////////////////////////////////////////////////////////////////

template <class T>
struct GEN_SLLIST
{
    T data;
    struct GEN_SLLIST<T>* next;
};

template <class T>
class SinglyLLL
{
private:
    struct GEN_SLLIST<T>* first;
    int iCount;

public:
    SinglyLLL();

    void InsertFirst(
                        T
                    );

    void InsertLast(
                        T
                    );

    void InsertAtPos(   
                        T,
                        int
                    );

    void DeleteFirst();

    void DeleteLast();

    void DeleteAtPos(
                        int
                    );

    void Display();

    int Count();

    void SearchFirstOcc(
                            T
                        );

    void SearchLastOcc( 
                            T
                        );

    void ReverseLL();

    T Addition();

    T Maximum();

    T Minimum();

    void DisplayPerfect();

    void DisplayPrime();

    T AdditionEven();

    T SecMaximum();
};

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Constructor
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Initializes an empty Singly Linear Linked List
//  Returns         : NONE
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
SinglyLLL<T>::SinglyLLL()
{
    first = NULL;
    iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : InsertFirst
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : T no
//  Description     : Inserts a node at the beginning of the list
//  Returns         : NONE
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T>::InsertFirst( 
                                    T no
                                )
{
    GEN_SLLIST<T>* newn = new GEN_SLLIST<T>;
    newn->data = no;
    newn->next = first;
    first = newn;
    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : InsertLast
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : T no
//  Description     : Inserts a node at the end of the list
//  Returns         : NONE
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T>::InsertLast(  
                                T no
                            )
{
    GEN_SLLIST<T>* newn = new GEN_SLLIST<T>;
    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        GEN_SLLIST<T>* temp = first;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newn;
    }
    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : InsertAtPos
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : T no, int pos
//  Description     : Inserts a node at a specific position
//  Returns         : NONE
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T>::InsertAtPos(
                                    T no,
                                    int pos
                                )
{
    if(pos < 1 || pos > iCount+1)
    {
        cout << "Invalid Position\n";
        return;
    }

    if(pos == 1)
        InsertFirst(no);
    else if(pos == iCount+1)
        InsertLast(no);
    else
    {
        GEN_SLLIST<T>* temp = first;
        for(int i = 1; i < pos-1; i++)
            temp = temp->next;

        GEN_SLLIST<T>* newn = new GEN_SLLIST<T>;
        newn->data = no;
        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : DeleteFirst
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Deletes the first node
//  Returns         : NONE
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T>::DeleteFirst()
{
    if(first == NULL)
    {
        cout << "LL is empty\n";
        return;
    }

    GEN_SLLIST<T>* temp = first;
    first = first->next;
    delete temp;
    iCount--;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : DeleteLast
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Deletes the last node
//  Returns         : NONE
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T>::DeleteLast()
{
    if(first == NULL)
    {
        cout << "LL is empty\n";
        return;
    }

    if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        GEN_SLLIST<T>* temp = first;
        while(temp->next->next != NULL)
            temp = temp->next;

        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : DeleteAtPos
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : int pos
//  Description     : Deletes node at a specific position
//  Returns         : NONE
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T>::DeleteAtPos(
                                    int pos
                                )
{
    if(pos < 1 || pos > iCount)
    {
        cout << "Invalid Position\n";
        return;
    }

    if(pos == 1)
        DeleteFirst();
    else if(pos == iCount)
        DeleteLast();
    else
    {
        GEN_SLLIST<T>* temp = first;
        for(int i = 1; i < pos-1; i++)
            temp = temp->next;

        GEN_SLLIST<T>* target = temp->next;
        temp->next = target->next;
        delete target;
        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Display
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Displays all nodes of the linked list
//  Returns         : NONE
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T>::Display()
{
    GEN_SLLIST<T>* temp = first;
    cout << "| NULL | -> ";
    while(temp != NULL)
    {
        cout << "| " << temp->data << " | -> ";
        temp = temp->next;
    }
    cout << "| NULL |\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Count
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Returns the number of elements currently in the list
//  Returns         : int
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyLLL<T>::Count()
{
    return iCount;
}
///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : SearchFirstOcc
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : T no
//  Description     : Searches for the first occurrence of an element
//  Returns         : NONE
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T>::SearchFirstOcc(
                                    T no
                                )
{
    GEN_SLLIST<T>* temp = first;
    int pos = -1;

    for(int i = 1; temp != NULL; i++)
    {
        if(temp->data == no)
        {
            pos = i;
            break;
        }
        temp = temp->next;
    }

    if(pos != -1)
        cout << "First occurrence of " << no << " is at position " << pos << "\n";
    else
        cout << no << " not found\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : SearchLastOcc
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : T no
//  Description     : Searches for the last occurrence of an element
//  Returns         : NONE
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T>::SearchLastOcc(
                                    T no
                                )
{
    GEN_SLLIST<T>* temp = first;
    int pos = -1;

    for(int i = 1; temp != NULL; i++)
    {
        if(temp->data == no)
            pos = i;
        temp = temp->next;
    }

    if(pos != -1)
        cout << "Last occurrence of " << no << " is at position " << pos << "\n";
    else
        cout << no << " not found\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Addition
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Returns sum of all elements in the list
//  Returns         : T
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
T SinglyLLL<T>::Addition()
{
    GEN_SLLIST<T>* temp = first;
    T sum = 0;

    while(temp != NULL)
    {
        sum += temp->data;
        temp = temp->next;
    }

    return sum;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Maximum
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Returns the maximum element in the list
//  Returns         : T
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
T SinglyLLL<T>::Maximum()
{
    if(first == NULL) return T(); // Return default if list empty

    GEN_SLLIST<T>* temp = first;
    T maxVal = temp->data;

    while(temp != NULL)
    {
        if(temp->data > maxVal)
            maxVal = temp->data;
        temp = temp->next;
    }

    return maxVal;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Minimum
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Returns the minimum element in the list
//  Returns         : T
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
T SinglyLLL<T>::Minimum()
{
    if(first == NULL) return T(); // Return default if list empty

    GEN_SLLIST<T>* temp = first;
    T minVal = temp->data;

    while(temp != NULL)
    {
        if(temp->data < minVal)
            minVal = temp->data;
        temp = temp->next;
    }

    return minVal;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : DisplayPerfect
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Displays all perfect numbers in the list
//  Returns         : NONE
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T>::DisplayPerfect()
{
    GEN_SLLIST<T>* temp = first;

    cout << "Perfect numbers: ";
    while(temp != NULL)
    {
        int sum = 0;
        for(int i = 1; i <= temp->data / 2; i++)
        {
            if(temp->data % i == 0)
                sum += i;
        }
        if(sum == temp->data)
            cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : DisplayPrime
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Displays all prime numbers in the list
//  Returns         : NONE
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T>::DisplayPrime()
{
    GEN_SLLIST<T>* temp = first;

    cout << "Prime numbers: ";
    while(temp != NULL)
    {
        bool prime = true;
        if(temp->data < 2)
            prime = false;

        for(int i = 2; i <= temp->data / 2; i++)
        {
            if(temp->data % i == 0)
            {
                prime = false;
                break;
            }
        }

        if(prime)
            cout << temp->data << " ";

        temp = temp->next;
    }
    cout << "\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : AdditionEven
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Returns sum of all even elements in the list
//  Returns         : T
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
T SinglyLLL<T>::AdditionEven()
{
    GEN_SLLIST<T>* temp = first;
    T sum = 0;

    while(temp != NULL)
    {
        if(temp->data % 2 == 0)
            sum += temp->data;
        temp = temp->next;
    }

    return sum;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : SecMaximum
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Returns the second maximum element in the list
//  Returns         : T
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
T SinglyLLL<T>::SecMaximum()
{
    if(first == NULL || first->next == NULL) return T(); // Not enough elements

    GEN_SLLIST<T>* temp = first;
    T max1 = first->data;
    T max2 = first->data;

    while(temp != NULL)
    {
        if(temp->data > max1)
        {
            max2 = max1;
            max1 = temp->data;
        }
        else if(temp->data < max1 && temp->data > max2)
        {
            max2 = temp->data;
        }
        temp = temp->next;
    }

    return max2;
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : ReverseLL
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Returns the ReversedLinked List
//  Returns         : T
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T>::ReverseLL()
{
    GEN_SLLIST<T>* previousNode = NULL;
    GEN_SLLIST<T>* currentNode = first;
    GEN_SLLIST<T>* nextNode = NULL;

    while(currentNode != NULL)
    {
        nextNode = currentNode->next;
        currentNode->next = previousNode;
        previousNode = currentNode;
        currentNode = nextNode;
    }
    first = previousNode;

}

/////////////////////////////////////////////////////////////////////////
//
//  Class :         DoublyLLL
//  Description:    Generic Implementation of Doubly Linear Linked List
//  Author :        Rutik Shivaji Thitame
//
/////////////////////////////////////////////////////////////////////////

template <class T>
struct GEN_DLLIST
{
    T data;
    struct GEN_DLLIST<T> * next;
    struct GEN_DLLIST<T> * prev;
};

template <class T>
class DoublyLLL
{
private:
    struct GEN_DLLIST<T> * first;
    int iCount;

public:
    DoublyLLL();

    void Display();

    void Count();

    void InsertFirst(
                        T
                    );

    void InsertLast(
                        T
                    );

    void InsertAtPos(   
                        T,
                        int
                    );

    void DeleteFirst();

    void DeleteLast();

    void DeleteAtPos(
                        int
                    );

    void SearchFirstOcc(
                            T
                        );

    void SearchLastOcc(
                            T
                        );

    void ReverseLL();

    T Addition();

    T Maximum();

    T Minimum();

    void DisplayPerfect();

    void DisplayPrime();

    T AdditionEven();

    T SecMaximum();
};

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : DoublyLLL
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Constructor to initialize empty Doubly Linked List
//  Returns         : NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
DoublyLLL<T>::DoublyLLL()
{
    first = NULL;
    iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Display
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Displays all elements of the list
//  Returns         : NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::Display()
{
    GEN_DLLIST<T>* temp = first;
    cout << " | NULL | <=> ";
    while(temp != NULL)
    {
        cout << " | " << temp->data << " | <=> ";
        temp = temp->next;
    }
    cout << " | NULL | \n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Count
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Returns the number of elements currently in the list
//  Returns         : int
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::Count()
{
    cout << "Number of elements in Doubly Linear LinkedList are: " << iCount << "\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : InsertFirst
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : T no
//  Description     : Inserts a new element at the beginning of the list
//  Returns         : NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::InsertFirst(
                                    T no
                                )
{
    GEN_DLLIST<T>* newn = new GEN_DLLIST<T>;
    newn->data = no;
    newn->next = first;
    newn->prev = NULL;

    if(first != NULL)
        first->prev = newn;

    first = newn;
    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : InsertLast
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : T no
//  Description     : Inserts a new element at the end of the list
//  Returns         : NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::InsertLast(  
                                T no
                            )
{
    GEN_DLLIST<T>* newn = new GEN_DLLIST<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        GEN_DLLIST<T>* temp = first;
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newn;
        newn->prev = temp;
    }
    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : InsertAtPos
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : T no, int pos
//  Description     : Inserts a new element at a given position
//  Returns         : NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::InsertAtPos(
                                    T no,
                                    int pos
                                )
{
    if(pos < 1 || pos > iCount+1)
    {
        cout << "Invalid Position\n";
        return;
    }

    if(pos == 1)
        InsertFirst(no);
    else if(pos == iCount+1)
        InsertLast(no);
    else
    {
        GEN_DLLIST<T>* temp = first;
        for(int i = 1; i < pos-1; i++)
            temp = temp->next;

        GEN_DLLIST<T>* newn = new GEN_DLLIST<T>;
        newn->data = no;
        newn->next = temp->next;
        newn->prev = temp;
        temp->next->prev = newn;
        temp->next = newn;
        iCount++;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : DeleteFirst
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Deletes the first element from the list
//  Returns         : NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::DeleteFirst()
{
    if(first == NULL) return;

    GEN_DLLIST<T>* temp = first;
    first = first->next;
    if(first != NULL)
        first->prev = NULL;

    delete temp;
    iCount--;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : DeleteLast
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Deletes the last element from the list
//  Returns         : NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::DeleteLast()
{
    if(first == NULL) return;

    GEN_DLLIST<T>* temp = first;
    while(temp->next != NULL)
        temp = temp->next;

    if(temp->prev != NULL)
        temp->prev->next = NULL;
    else
        first = NULL;

    delete temp;
    iCount--;
}
///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : DeleteAtPos
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : int pos
//  Description     : Deletes the element at a given position
//  Returns         : NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::DeleteAtPos(
                                    int pos
                                )
{
    if(pos < 1 || pos > iCount)
    {
        cout << "Invalid Position\n";
        return;
    }

    if(pos == 1)
        DeleteFirst();
    else if(pos == iCount)
        DeleteLast();
    else
    {
        GEN_DLLIST<T>* temp = first;
        for(int i = 1; i < pos-1; i++)
            temp = temp->next;

        GEN_DLLIST<T>* target = temp->next;
        temp->next = target->next;
        target->next->prev = temp;
        delete target;
        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : SearchFirstOcc
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : T no
//  Description     : Finds the first occurrence of a value
//  Returns         : NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::SearchFirstOcc(
                                    T no
                                )
{
    GEN_DLLIST<T>* temp = first;
    int iPos = 1;

    while(temp != NULL)
    {
        if(temp->data == no)
        {
            cout << "First occurrence of " << no << " is at position " << iPos << "\n";
            return;
        }
        temp = temp->next;
        iPos++;
    }

    cout << no << " not found in the list\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : SearchLastOcc
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : T no
//  Description     : Finds the last occurrence of a value
//  Returns         : NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::SearchLastOcc(
                                    T no
                                )
{
    GEN_DLLIST<T>* temp = first;
    int iPos = 0, currentPos = 1;

    while(temp != NULL)
    {
        if(temp->data == no)
            iPos = currentPos;

        temp = temp->next;
        currentPos++;
    }

    if(iPos != 0)
        cout << "Last occurrence of " << no << " is at position " << iPos << "\n";
    else
        cout << no << " not found in the list\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Addition
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Returns the sum of all elements in the list
//  Returns         : T (sum of elements)
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
T DoublyLLL<T>::Addition()
{
    GEN_DLLIST<T>* temp = first;
    T isum = 0;

    while(temp != NULL)
    {
        isum += temp->data;
        temp = temp->next;
    }

    return isum;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Maximum
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Returns the maximum element in the list
//  Returns         : T (maximum value)
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
T DoublyLLL<T>::Maximum()
{
    if(first == NULL) return 0;

    GEN_DLLIST<T>* temp = first;
    T iMax = temp->data;

    while(temp != NULL)
    {
        if(temp->data > iMax)
            iMax = temp->data;
        temp = temp->next;
    }

    return iMax;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Minimum
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Returns the minimum element in the list
//  Returns         : T (minimum value)
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
T DoublyLLL<T>::Minimum()
{
    if(first == NULL) return 0;

    GEN_DLLIST<T>* temp = first;
    T iMin = temp->data;

    while(temp != NULL)
    {
        if(temp->data < iMin)
            iMin = temp->data;
        temp = temp->next;
    }

    return iMin;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : DisplayPerfect
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Displays all perfect numbers in the list
//  Returns         : NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::DisplayPerfect()
{
    GEN_DLLIST<T>* temp = first;

    while(temp != NULL)
    {
        T iSum = 0;
        for(T i = 1; i <= temp->data/2; i++)
        {
            if(temp->data % i == 0)
                iSum += i;
        }

        if(iSum == temp->data)
            cout << temp->data << "\t";

        temp = temp->next;
    }

    cout << "are perfect numbers\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : DisplayPrime
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Displays all prime numbers in the list
//  Returns         : NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::DisplayPrime()
{
    GEN_DLLIST<T>* temp = first;

    while(temp != NULL)
    {
        bool prime = true;
        if(temp->data <= 1) prime = false;

        for(T i = 2; i <= temp->data/2 && prime; i++)
        {
            if(temp->data % i == 0)
                prime = false;
        }

        if(prime)
            cout << temp->data << " is prime number\n";

        temp = temp->next;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : AdditionEven
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Returns the sum of all even elements in the list
//  Returns         : T (sum of even elements)
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
T DoublyLLL<T>::AdditionEven()
{
    GEN_DLLIST<T>* temp = first;
    T iSum = 0;

    while(temp != NULL)
    {
        if(temp->data % 2 == 0)
            iSum += temp->data;

        temp = temp->next;
    }

    return iSum;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : SecMaximum
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Returns the second maximum element in the list
//  Returns         : T (second maximum value)
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
T DoublyLLL<T>::SecMaximum()
{
    if(first == NULL) return 0;

    GEN_DLLIST<T>* temp = first;
    T iMax1 = temp->data;
    T iMax2 = 0;

    while(temp != NULL)
    {
        if(temp->data > iMax1)
        {
            iMax2 = iMax1;
            iMax1 = temp->data;
        }
        else if(temp->data < iMax1 && temp->data > iMax2)
        {
            iMax2 = temp->data;
        }

        temp = temp->next;
    }

    return iMax2;
}

template <class T>
void DoublyLLL<T>::ReverseLL()
{
    GEN_DLLIST<T>* previousNode = NULL;
    GEN_DLLIST<T>* currentNode = first;
    GEN_DLLIST<T>* nextNode = NULL;

    while(currentNode != NULL)
    {
        nextNode = currentNode->next;
        currentNode->next = previousNode;
        previousNode = currentNode;
        currentNode = nextNode;
    }
    first = previousNode;

}

/////////////////////////////////////////////////////////////////////////
//
//  Class :         BST
//  Description:    Generic Implementation of Binary Search Tree
//  Author :        Rutik Shivaji Thitame
//
/////////////////////////////////////////////////////////////////////////

template <class T>
struct BSTnode
{
    T data;
    struct BSTnode<T>* lchild;
    struct BSTnode<T>* rchild;
};

template <class T>
class BST
{
    private:
        struct BSTnode<T>* first;

    public:
        BST();

        void Insert(
                        struct BSTnode<T>**,
                        T
                    );

        void Inorder(
                        struct BSTnode<T>*
                    );

        void Preorder(
                        struct BSTnode<T>*
                    );

        void Postorder(
                            struct BSTnode<T>*
                        );

        bool Search(
                        struct BSTnode<T>*,
                        T
                    );

        T Count(
                    struct BSTnode<T>*
                );

        T CountLeafNodes(
                            struct BSTnode<T>*
                        );

        T CountParentNodes(
                                struct BSTnode<T>*
                            );
};

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : BST (Constructor)
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Initializes an empty BST
//  Returns         : NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
BST<T>::BST()
{
    this->first = NULL;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Insert
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : struct BSTnode<T>** first, T no
//  Description     : Inserts a new node into BST
//  Returns         : NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void BST<T>::Insert(
                        struct BSTnode<T>** first,
                        T no
                    )
{
    BSTnode<T>* newn = new BSTnode<T>;
    newn->data = no;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(*first == NULL)  // BST is empty
    {
        *first = newn;
    }
    else
    {
        BSTnode<T>* temp = *first;
        while(1)
        {
            if(no == temp->data)
            {
                printf("Duplicate element: Unable to insert node\n");
                free(newn);
                break;
            }
            else if(no > temp->data)
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }
                temp = temp->rchild;
            }
            else // no < temp->data
            {
                if(temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    break;
                }
                temp = temp->lchild;
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Inorder
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : BSTnode<T>* first
//  Description     : Displays nodes of BST in inorder traversal
//  Returns         : NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void BST<T>::Inorder(       
                        BSTnode<T>* first
                    )
{
    if(first != NULL)
    {
        Inorder(first->lchild);
        printf("%d\t", first->data);
        Inorder(first->rchild);
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Preorder
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : BSTnode<T>* first
//  Description     : Displays nodes of BST in preorder traversal
//  Returns         : NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void BST<T>::Preorder(
                        BSTnode<T>* first
                    )
{
    if(first != NULL)
    {
        printf("%d\t", first->data);
        Preorder(first->lchild);
        Preorder(first->rchild);
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Postorder
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : BSTnode<T>* first
//  Description     : Displays nodes of BST in postorder traversal
//  Returns         : NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void BST<T>::Postorder(
                            BSTnode<T>* first
                        )
{
    if(first != NULL)
    {
        Postorder(first->lchild);
        Postorder(first->rchild);
        printf("%d\t", first->data);
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Search
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : BSTnode<T>* first, T no
//  Description     : Searches for a value in BST and prints time complexity
//  Returns         : bool (true if found, false otherwise)
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
bool BST<T>::Search(
                        BSTnode<T>* first,
                        T no
                    )
{
    bool bFlag = false;
    int TimeComplexity = 0;

    while(first != NULL)
    {
        if(no == first->data)
        {
            bFlag = true;
            break;
        }
        else if(no > first->data)
            first = first->rchild;
        else
            first = first->lchild;

        TimeComplexity++;
    }

    printf("Time complexity of search is : %d\n", TimeComplexity);
    return bFlag;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Count
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : BSTnode<T>* first
//  Description     : Counts total nodes in BST
//  Returns         : T (number of nodes)
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
T BST<T>::Count(
                    BSTnode<T>* first
                )
{
    static int iCount = 0;
    if(first != NULL)
    {
        iCount++;
        Count(first->rchild);
        Count(first->lchild);
    }
    return iCount;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : CountLeafNodes
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : BSTnode<T>* first
//  Description     : Counts leaf nodes in BST
//  Returns         : T (number of leaf nodes)
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
T BST<T>::CountLeafNodes(
                            BSTnode<T>* first
                        )
{
    static int iCount = 0;
    if(first != NULL)
    {
        if(first->lchild == NULL && first->rchild == NULL)
            iCount++;

        CountLeafNodes(first->rchild);
        CountLeafNodes(first->lchild);
    }
    return iCount;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : CountParentNodes
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : BSTnode<T>* first
//  Description     : Counts parent (non-leaf) nodes in BST
//  Returns         : T (number of parent nodes)
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
T BST<T>::CountParentNodes(
                                BSTnode<T>* first
                            )
{
    static int iCount = 0;
    if(first != NULL)
    {
        if(first->lchild != NULL || first->rchild != NULL)
            iCount++;

        CountParentNodes(first->rchild);
        CountParentNodes(first->lchild);
    }
    return iCount;
}
/////////////////////////////////////////////////////////////////////////
//
//  Class :         Sorting
//  Description:    Generic Implementation of Sorting Algorithms
//  Author :        Rutik Shivaji Thitame
//
/////////////////////////////////////////////////////////////////////////

template <class T>
class ArrayX
{
    public:
        T *Arr;
        int iSize;
        bool Sorted;

        ArrayX(
                    T
                );

        ~ArrayX();

        void Accept();

        void Display();

        void BubbleSort();

        void BubbleSortEfficient();

        void SelectionSort();

        void InsertionSort();
};

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Constructor
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : T no (size of array)
//  Description     : Allocates dynamic array of size 'no' and initializes Sorted flag
//  Returns         : NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
ArrayX<T>::ArrayX(
                    T no
                )
{
    iSize = no;
    Arr = new T[iSize];
    Sorted = true;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Destructor
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Frees dynamically allocated array
//  Returns         : NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
ArrayX<T>::~ArrayX()
{
    delete[] Arr;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Accept
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Accepts input for the array and checks if it is already sorted
//  Returns         : NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void ArrayX<T>::Accept()
{
    cout << "Enter " << iSize << " elements:\n";
    for(int i = 0; i < iSize; i++)
    {
        cout << "Enter element no " << i + 1 << " : ";
        cin >> Arr[i];

        if((i > 0) && (Sorted == true))
        {
            if(Arr[i] < Arr[i - 1])
                Sorted = false;
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Display
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Displays all elements of the array
//  Returns         : NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void ArrayX<T>::Display()
{
    cout << "Elements of the array are: \n";
    for(int i = 0; i < iSize; i++)
        cout << Arr[i] << "\t";
    cout << "\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : BubbleSort
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Simple Bubble Sort algorithm with pass-wise display
//  Returns         : NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void ArrayX<T>::BubbleSort()
{
    if(Sorted)
        return;

    T temp;
    for(int i = 0; i < iSize; i++)
    {
        for(int j = 0; j < iSize - 1 - i; j++)
        {
            if(Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = temp;
            }
        }
        cout << "Data after pass " << i + 1 << ":\n";
        Display();
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : BubbleSortEfficient
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Optimized Bubble Sort with early exit if array is already sorted
//  Returns         : NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void ArrayX<T>::BubbleSortEfficient()
{
    if(Sorted)
        return;

    T temp;
    bool bFlag = true;

    for(int i = 0; i < iSize && bFlag; i++)
    {
        bFlag = false;
        for(int j = 0; j < iSize - 1 - i; j++)
        {
            if(Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = temp;
                bFlag = true;
            }
        }
        cout << "Data after pass " << i + 1 << ":\n";
        Display();
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : SelectionSort
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Sorts the array using Selection Sort algorithm
//  Returns         : NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void ArrayX<T>::SelectionSort()
{
    T temp;
    for(int i = 0; i < iSize - 1; i++)
    {
        int min_index = i;
        for(int j = i + 1; j < iSize; j++)
        {
            if(Arr[j] < Arr[min_index])
                min_index = j;
        }

        if(i != min_index)
        {
            temp = Arr[i];
            Arr[i] = Arr[min_index];
            Arr[min_index] = temp;
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : InsertionSort
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Sorts the array using Insertion Sort algorithm
//  Returns         : NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void ArrayX<T>::InsertionSort()
{
    for(int i = 1; i < iSize; i++)
    {
        T selected = Arr[i];
        int j;
        for(j = i - 1; j >= 0 && Arr[j] > selected; j--)
        {
            Arr[j + 1] = Arr[j];
        }
        Arr[j + 1] = selected;
    }
}/////////////////////////////////////////////////////////////////////////
//
//  Class           : Search
//  Description     : Generic Implementation of Searching Algorithms
//  Author          : Rutik Shivaji Thitame
//
/////////////////////////////////////////////////////////////////////////

template <class T>
class Search
{
    public:
        T *Arr;          
        int iSize;       
        bool Sorted;     

        Search(
                    T no
                );    
        ~Search();   

        void Accept();   

        void Display();  

        // Searching algorithms
        bool LinearSearch(
                            T
                        );

        bool BiDirectionalSearch(
                                    T
                                );

        bool BinarySearchInc(
                                T
                            );

        bool BinarySearchDec(
                                T
                            );

        bool BinarySearchEfficientInc(
                                        T
                                    );

        bool BinarySearchEfficientDec(
                                        T
                                    );


        // Sorted checks
        bool CheckSortedInc();

        bool CheckSortedDec();
};

/////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Search (Constructor)
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : T no (Size of array)
//  Description     : Allocates memory for array and initializes variables
//  Returns         : NONE
//
/////////////////////////////////////////////////////////////////////////

template <class T>
Search<T>::Search(
                    T no
                )
{
    iSize = no;
    Arr = new T[iSize];
    Sorted = true;
}

/////////////////////////////////////////////////////////////////////////
//
//  Function Name   : ~Search (Destructor)
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Deallocates memory of array
//  Returns         : NONE
//
/////////////////////////////////////////////////////////////////////////

template <class T>
Search<T>::~Search()
{
    delete [] Arr;
}

/////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Accept
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Accepts elements from user and checks if sorted
//  Returns         : NONE
//
/////////////////////////////////////////////////////////////////////////

template <class T>
void Search<T>::Accept()
{
    cout << "Enter " << iSize << " elements:\n";

    for(int i = 0; i < iSize; i++)
    {
        cout << "Enter element no " << i + 1 << " : ";
        cin >> Arr[i];

        if((i > 0) && Sorted)   // Check if array remains sorted
        {
            if(Arr[i] < Arr[i - 1])
                Sorted = false;
        }
    }
}

/////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Display
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Displays elements of the array
//  Returns         : NONE
//
/////////////////////////////////////////////////////////////////////////

template <class T>
void Search<T>::Display()
{
    cout << "Elements of the array are:\n";
    for(int i = 0; i < iSize; i++)
        cout << Arr[i] << "\t";
    cout << "\n";
}

/////////////////////////////////////////////////////////////////////////
//
//  Function Name   : LinearSearch
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : T no (Element to search)
//  Description     : Performs linear search on array
//                    If array is sorted, switches to efficient binary search
//  Returns         : bool (true if found, false otherwise)
//
/////////////////////////////////////////////////////////////////////////

template <class T>
bool Search<T>::LinearSearch(
                                T no
                            )
{
    if(Sorted)    // Use efficient binary search if already sorted
    {
        cout << "Data is sorted. Using BinarySearchEfficientInc.\n";
        return BinarySearchEfficientInc(no);
    }

    for(int i = 0; i < iSize; i++)
    {
        if(Arr[i] == no)
            return true;
    }
    return false;
}

/////////////////////////////////////////////////////////////////////////
//
//  Function Name   : BiDirectionalSearch
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : T no (Element to search)
//  Description     : Searches element from both ends simultaneously
//  Returns         : bool (true if found, false otherwise)
//
/////////////////////////////////////////////////////////////////////////

template <class T>
bool Search<T>::BiDirectionalSearch(
                                        T no
                                    )
{
    int iStart = 0;
    int iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        if(Arr[iStart] == no || Arr[iEnd] == no)
            return true;
        iStart++;
        iEnd--;
    }
    return false;
}

/////////////////////////////////////////////////////////////////////////
//
//  Function Name   : BinarySearchInc
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : T no (Element to search)
//  Description     : Performs binary search in ascending sorted array
//  Returns         : bool (true if found, false otherwise)
//
/////////////////////////////////////////////////////////////////////////

template <class T>
bool Search<T>::BinarySearchInc(
                                    T no
                                )
{
    int iStart = 0, iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        int iMid = iStart + (iEnd - iStart) / 2;

        if(Arr[iMid] == no)
            return true;
        else if(no < Arr[iMid])
            iEnd = iMid - 1;
        else
            iStart = iMid + 1;
    }
    return false;
}

/////////////////////////////////////////////////////////////////////////
//
//  Function Name   : BinarySearchDec
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : T no (Element to search)
//  Description     : Performs binary search in descending sorted array
//  Returns         : bool (true if found, false otherwise)
//
/////////////////////////////////////////////////////////////////////////

template <class T>
bool Search<T>::BinarySearchDec(
                                    T no
                                )
{
    int iStart = 0, iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        int iMid = iStart + (iEnd - iStart) / 2;

        if(Arr[iMid] == no)
            return true;
        else if(no > Arr[iMid])
            iEnd = iMid - 1;
        else
            iStart = iMid + 1;
    }
    return false;
}

/////////////////////////////////////////////////////////////////////////
//
//  Function Name   : BinarySearchEfficientInc
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : T no (Element to search)
//  Description     : Optimized binary search (ascending order) with 
//                    additional boundary checks
//  Returns         : bool (true if found, false otherwise)
//
/////////////////////////////////////////////////////////////////////////

template <class T>
bool Search<T>::BinarySearchEfficientInc(
                                            T no
                                        )
{
    if(!Sorted)
    {
        cout << "Data is not sorted. Using Linear Search.\n";
        return LinearSearch(no);
    }

    int iStart = 0, iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        int iMid = iStart + (iEnd - iStart) / 2;

        if(Arr[iMid] == no || Arr[iStart] == no || Arr[iEnd] == no)
            return true;
        else if(no < Arr[iMid])
            iEnd = iMid - 1;
        else
            iStart = iMid + 1;
    }
    return false;
}

/////////////////////////////////////////////////////////////////////////
//
//  Function Name   : BinarySearchEfficientDec
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : T no (Element to search)
//  Description     : Optimized binary search (descending order) with 
//                    additional boundary checks
//  Returns         : bool (true if found, false otherwise)
//
/////////////////////////////////////////////////////////////////////////

template <class T>
bool Search<T>::BinarySearchEfficientDec(
                                            T no
                                        )
{
    if(!Sorted)
    {
        cout << "Data is not sorted. Using Linear Search.\n";
        return LinearSearch(no);
    }

    int iStart = 0, iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        int iMid = iStart + (iEnd - iStart) / 2;

        if(Arr[iMid] == no || Arr[iStart] == no || Arr[iEnd] == no)
            return true;
        else if(no > Arr[iMid])
            iEnd = iMid - 1;
        else
            iStart = iMid + 1;
    }
    return false;
}

/////////////////////////////////////////////////////////////////////////
//
//  Function Name   : CheckSortedInc
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Checks if array is sorted in ascending order
//  Returns         : bool
//
/////////////////////////////////////////////////////////////////////////

template <class T>
bool Search<T>::CheckSortedInc()
{
    for(int i = 0; i < iSize - 1; i++)
    {
        if(Arr[i] > Arr[i + 1])
            return false;
    }
    return true;
}

/////////////////////////////////////////////////////////////////////////
//
//  Function Name   : CheckSortedDec
//  Function Date   : 15/09/2025
//  Function Author : Rutik Shivaji Thitame
//  Parameters      : NONE
//  Description     : Checks if array is sorted in descending order
//  Returns         : bool
//
/////////////////////////////////////////////////////////////////////////

template <class T>
bool Search<T>::CheckSortedDec()
{
    for(int i = 0; i < iSize - 1; i++)
    {
        if(Arr[i] < Arr[i + 1])
            return false;
    }
    return true;
}




///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Entry point function
//	Function Date			:	15/09/2025
//	Function Author		:	Rutik Shivaji Thitame 
//	Brief Description	:	
//
///////////////////////////////////////////////////////////////////////////////////////////


int main()
{

    SinglyLLL<int> sobj;

    sobj.InsertLast(11);
    sobj.InsertLast(21);
    sobj.InsertLast(51);
    sobj.InsertLast(101);
    sobj.InsertLast(111);
    sobj.InsertLast(121);

    sobj.Display();

    sobj.ReverseLL();

    sobj.Display();



    return 0;
}
