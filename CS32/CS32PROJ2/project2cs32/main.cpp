#include "TaskList.h"
#include <iostream>
#include <cassert>
int main(int argc, const char * argv[]) {
    // Empty tasklist
    TaskList emptyList;
    assert(emptyList.size() == 0);
    assert(emptyList.empty() == true);
    
    // Attempt to remove first node should be failed
    bool removed = emptyList.removeFront();
    assert(removed == false);
    
    // Get and find from empty list
    std::string task;
    bool found = emptyList.get(0, task);
    assert(found == false);
    int pos = emptyList.find("cs32rocks");
    assert(pos == -1);
    
    // Test basic functionalities
    TaskList list;
    list.addBack("First Task");
    list.addBack("Second Task");
    list.addBack("Third Task");
    assert(list.size() == 3);
    
    // Get
    assert(list.get(0, task) == true);
    assert(task == "First Task");
    
    // Find
    assert(list.find("First Task") == 0);
    assert(list.find("Fourth Task") == -1);
    
    // Remove front
    assert(list.removeFront() == true);
    assert(list.get(0, task) == true && task == "Second Task");
    assert(list.removeFront() == true);
    assert(list.get(0, task) == true && task == "Third Task");
    assert(list.removeFront() == true);
    assert(list.size() == 0);
    assert(list.empty() == true);
    
    // Invalid inputs
    TaskList invalidList;
    list.addBack("Task 1");
    list.addBack("Task 2");
    list.addBack("Task 3");
    // Negative Index
    assert(list.get(-1, task) == false);
    // Out of bounds
    assert(list.get(3, task) == false);
    
    // Test Copy Constructor
    TaskList original;
    original.addBack("1");
    original.addBack("2");
    original.addBack("3");
    TaskList copy(original);
    assert(copy.size() == 3);
    
    assert(copy.get(0, task) == true && task == "1");
    assert(copy.get(1, task) == true && task == "2");
    assert(copy.get(2, task) == true && task == "3");
    
    TaskList emptyList1;
    TaskList copyOfEmpty(emptyList1);
    assert(copyOfEmpty.size() == 0);
    assert(copyOfEmpty.empty() == true);
    
    // Chain copy
    TaskList a, b, c;
    a.addBack("Chain 1");
    a.addBack("Chain 2");
     
    c = b = a;
     
    assert(a.size() == 2);
    assert(b.size() == 2);
    assert(c.size() == 2);
    
    assert(a.get(0, task) && task == "Chain 1");
    assert(b.get(0, task) && task == "Chain 1");
    assert(c.get(0, task) && task == "Chain 1");
    
    // Assignment from small to large
    TaskList list1;
    list1.addBack("1 1");
    list1.addBack("1 2");
    
    TaskList list2;
    list2.addBack("2 1");
    list2.addBack("2 2");
    list2.addBack("2 3");
    list2.addBack("2 4");
    
    assert(list1.size() == 2);
    assert(list2.size() == 4);
    list1 = list2;
    assert(list1.size() == 4);
    
    assert(list1.get(0, task) == true && task == "2 1");
    assert(list1.get(1, task) == true && task == "2 2");
    assert(list1.get(2, task) == true && task == "2 3");
    assert(list1.get(3, task) == true && task == "2 4");
    
    // Assigning from large to small
    TaskList small;
    small.addBack("Small 1");
    
    TaskList large;
    large.addBack("Large 1");
    large.addBack("Large 2");
    large.addBack("Large 3");
    large.addBack("Large 4");
    
    small = large;
    assert(!small.empty());
    assert(small.size() == 4);
    
    assert(small.get(0, task) && task == "Large 1");
    assert(small.get(1, task) && task == "Large 2");
    assert(small.get(2, task) && task == "Large 3");
    assert(small.get(3, task) && task == "Large 4");
    
    // Assign empty to non empty
    TaskList nonEmpty;
    nonEmpty.addBack("Task 1");
    nonEmpty.addBack("Task 2");
    nonEmpty.addBack("Task 3");
    
    TaskList empty;
        
    nonEmpty = empty;
    assert(nonEmpty.empty());
    assert(nonEmpty.size() == 0);
    assert(!nonEmpty.get(0, task));
    
    // Self assignment
    TaskList* list1Ptr = &list1;
    list1 = *list1Ptr;
    assert(list1.get(0, task) == true && task == "2 1");
    
    // Test clear function
    TaskList clearList;
    clearList.addBack("Task 1");
    clearList.addBack("Task 2");
    clearList.addBack("Task 3");
    clearList.clear();
    assert(clearList.size() == 0);
    assert(clearList.empty() == true);
    
    // Special Characters
    TaskList specialList;
    specialList.addBack("");  // Empty string
    specialList.addBack("   ");  // Spaces
    specialList.addBack("Special!@#$%^&*()");
    assert(specialList.size() == 3);
    assert(specialList.get(0, task) == true && task == "");
    assert(specialList.get(1, task) == true && task == "   ");
    assert(specialList.get(2, task) == true && task == "Special!@#$%^&*()");
    assert(specialList.find("") == 0);
    assert(specialList.find("   ") == 1);
    assert(specialList.find("Special!@#$%^&*()") == 2);
    
    
    
    return 0;
}
