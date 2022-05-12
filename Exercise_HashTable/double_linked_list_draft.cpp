#include <iostream>
#include <string>

using namespace std;

struct node 
{
    int data;
    int key;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *last = NULL;
struct node *current = NULL;

bool isEmpty() 
{
    return head == NULL;
}

int length() 
{
    int length = 0;
    struct node *current;
	
    for( current = head; current != NULL; current = current->next )
    {
        length++;
    }
	
    return length;
}

void displayForward() 
{
    struct node *ptr = head;
	
    cout << endl << "[ " ;
	
    while(ptr != NULL)
    {        
        cout << "( [" << ptr->key << "] , " << ptr->data << " ) ";
        ptr = ptr->next;
    }

    cout << "]";
}

void insertFirst(int key, int data) 
{
    struct node *link = (struct node*) malloc(sizeof(struct node));
    link->key = key;
    link->data = data;
	
    if( isEmpty() ) 
    {
        last = link;
    } 
    else 
    {
        head->prev = link;
    }

    link->next = head;
	
    head = link;
}

void insertLast(int key, int data) 
{
    struct node *link = (struct node*) malloc(sizeof(struct node));
    link->key = key;
    link->data = data;
    
    if( isEmpty() ) 
    {
        last = link;
    } 
    else 
    {
        last->next = link;      
        link->prev = last;
    }
    last = link;
}

struct node* deleteFirst() 
{
    struct node *tempLink = head;
	
    if(head->next == NULL)
    {
        last = NULL;
    } 
    else 
    {
        head->next->prev = NULL;
    }
    head = head->next;

    return tempLink;
}

struct node* deleteLast() 
{
    struct node *tempLink = last;

    if(head->next == NULL) 
    {
        head = NULL;
    } 
    else 
    {
        last->prev->next = NULL;
    }
	
    last = last->prev;

    return tempLink;
}


struct node* delete_key(int key) 
{
    struct node* current = head;
    struct node* previous = NULL;

    if( isEmpty() ) 
    {
        return NULL;
    }

    while(current->key != key) 
    {
        if(current->next == NULL) 
        {
            return NULL;
        }
        else 
        {
            previous = current;
            
            current = current->next;
        }
    }

    if(current == head) 
    {
        head = head->next;
    } 
    else 
    {
        current->prev->next = current->next;
    }    

    if(current == last) 
    {
        last = current->prev;
    }
    else 
    {
        current->next->prev = current->prev;
    }
	
    return current;
}

bool insertAfter(int key, int newKey, int data) 
{
    struct node *current = head; 

    if( isEmpty() ) 
    {
        return false;
    }

    while(current->key != key) 
    {
        if(current->next == NULL) 
        {
            return false;
        } 
        else 
        {
            current = current->next;
        }
    }

    struct node *newLink = (struct node*) malloc(sizeof(struct node));
    newLink->key = newKey;
    newLink->data = data;

    if(current == last) 
    {
        newLink->next = NULL; 
        last = newLink; 
    }   
    else 
    {
        newLink->next = current->next;         
        current->next->prev = newLink;
    }
	
    newLink->prev = current; 
    current->next = newLink; 
    return true; 
}

void searchElement(int searchValue) 
{   
    struct node* temp = head;
    int found = 0;
    int i = 0;

    if( temp != NULL ) 
    {
        while( temp != NULL ) 
        {
            i++;
            if(temp->data == searchValue) 
            {
                found++;
                break;
            }
            temp = temp->next;
        }
        if ( found ) 
        {
            cout << searchValue << " is found at key = "<< temp->key << ", position " << length() - i << endl;
        }
        else 
        {
            cout << searchValue << " is not found in the list." << endl;
        }
    }
    else 
    {
        cout<<"The list is empty" << endl;
    }
} 

int main() 
{
    insertFirst(1,10);
    insertFirst(2,20);
    insertFirst(3,30);
    insertFirst(4,1);
    insertFirst(5,40);
    insertFirst(6,56); 

    cout << "List (First to Last): ";  
    displayForward();
    cout << endl << endl;
	
    cout << "List , after deleting first record: ";
    deleteFirst();        
    displayForward();
    cout << endl << endl;

    cout << "List , after deleting last record: ";  
    deleteLast();
    displayForward();
    cout << endl << endl;
	
    cout << "List , insert after key(4) and key (3): ";  
    insertAfter(4,7,13);
    insertAfter(3,8,26);
    displayForward();
    cout << endl << endl;

    cout << "List, after delete key(4) : ";  
    delete_key(4);
    displayForward();
    cout << endl << endl;

    cout << "Search for element: 40" << endl;
    searchElement(40);
    cout << endl;

    cout << "Search for element: 56" << endl;
    searchElement(56);
    cout << endl;

    return 0;
}
