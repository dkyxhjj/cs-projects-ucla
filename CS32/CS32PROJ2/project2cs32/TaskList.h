#ifndef TASKLIST_H
#define TASKLIST_H

#include <string>

class TaskList {
private:
    // Node structure
    struct Node {
        // Double sided structure
        std::string data;
        Node* next;
        Node* prev;
        
        // Node constructor
        Node(const std::string& task) : data(task), next(nullptr), prev(nullptr) {}
    };
    
    // Private member variables
    Node* head;
    Node* tail;
    int m_size;
    
    // Private helper functions
    void copyList(const TaskList& other);
    void freeList();
    Node* getNode(int pos) const;

public:
    // Constructor
    TaskList();
    
    // Destructor
    ~TaskList();
    
    // Copy constructor
    TaskList(const TaskList& other);
    
    // Assignment operator
    TaskList& operator=(const TaskList& rhs);
    
    // Helper function that checks if list is empty
    bool empty() const;
    
    // Get number of tasks in list
    int size() const;
    
    // Add task to the end of the list
    void addBack(const std::string& task);
    
    // Remove task from the front of the list
    bool removeFront();
    
    // Get task at specified position
    bool get(int pos, std::string& task) const;
    
    // Find first occurrence of task
    // return index or -1 if not found
    int find(const std::string& task) const;
    
    // Clear all tasks from the list
    void clear();
    
    // Print all tasks to cerr (one per line)
    void printAll() const;
};

#endif

