#include "TaskList.h"
#include <iostream>

//Constructor
TaskList::TaskList() {
    // initialization
    head = nullptr;
    tail = nullptr;
    m_size = 0;
}

// Destructor
TaskList::~TaskList() {
    freeList();
}
// Copy Constructore
TaskList::TaskList(const TaskList& other) {
    // Set up
    head = nullptr;
    tail = nullptr;
    m_size = 0;
        
    // Use helper function to set up everything else
    copyList(other);
}

// Assignment operator
TaskList& TaskList::operator=(const TaskList& rhs) {
    // Check for self-assignment
    if (this == &rhs) {
        return *this;
    }
    // Clear current list
    freeList();
    // Copy all nodes to the new list
    copyList(rhs);
    return *this;
}
// Helper function that checks if the tasklist is empty
bool TaskList::empty() const {
    return m_size == 0;
}
// Helper function that checks the size/length of the tasklist
int TaskList::size() const {
    return m_size;
}

// Add a task to the end
void TaskList::addBack(const std::string& task) {
    Node* newNode = new Node(task);

    if (empty()) {
        // Set head and tail to newNode if the node is empty
        head = tail = newNode;
    } else {
        // Link the current tail to the new node
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    ++m_size;
}

// Remove the front task
bool TaskList::removeFront() {
    // Can't remove the front if there is none
    if (head == nullptr) {
        return false;
    }
        
    // Store temporary reference
    Node* temp = head;
        
    // move head to the next pointer, skip the first one
    head = head->next;
    // Update the new head's prev pointer (if it exists)
    if (head != nullptr) {
        head->prev = nullptr;
    } else {
        // so tail should also be null if head is null
        tail = nullptr;
    }
    // Remove temporary variable
    delete temp;
        
    // Decrement size
    --m_size;
        
    return true;
}

// Set task at a specific position
bool TaskList::get(int pos, std::string& task) const {
   // Use helper function getNode to find the position
    Node* node = getNode(pos);
        
    // If node is at nullptr, then it's invalid
    if (node == nullptr) {
        return false;
    }
    // Set the task reference to the node's data
    task = node->data;
    return true;
    
}

// Find a task in the doubly linked list
int TaskList::find(const std::string& task) const {
    
    Node* curr = head;
    int index = 0;
    
    // Traverse the list looking for the task
    while (curr != nullptr) {
        if (curr->data == task) {
            return index;  // return the correct index
        }
        curr = curr->next; // progress forward
        index++;
    }
    // if not found, return -1
    return -1;
}

// Simple call to freeList
void TaskList::clear() {
    freeList();
}

// Print all tasks
void TaskList::printAll() const {
    Node* curr = head;
    // Traverse the list from head to tail
    while (curr != nullptr) {
        std::cerr << curr->data << std::endl;
        curr = curr->next;
    }
}
// Helper copyList function for deep copying
void TaskList::copyList(const TaskList& other) {
    Node* curr = other.head;
    // copying current data if current pointer isn't at the end
    while (curr != nullptr) {
        addBack(curr->data);
        curr = curr->next;
    }
}
// Helper function that frees the tasklist
void TaskList::freeList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    m_size = 0;
}

TaskList::Node* TaskList::getNode(int pos) const {
    // If invalid position
    if (pos < 0 || pos >= m_size) {
        return nullptr;
    }
    
    // Start frmo head and traverse to the position
    Node* curr = head;
    for (int i = 0; i < pos; i++) {
        curr = curr->next;
    }
    
    return curr;
}
