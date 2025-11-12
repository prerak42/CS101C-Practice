# Linked Lists - Brief Overview

A **linked list** is a linear data structure where elements (called **nodes**) are stored in sequence, but unlike arrays, they're not stored in contiguous memory locations.

## Structure

Each node contains:
- **Data**: The actual value being stored
- **Pointer/Reference**: A link to the next node in the sequence

```
[Data|Next] → [Data|Next] → [Data|Next] → NULL
```

## Types

1. **Singly Linked List**: Each node points only to the next node
2. **Doubly Linked List**: Each node has pointers to both next and previous nodes
3. **Circular Linked List**: Last node points back to the first node

## Key Characteristics

**Advantages:**
- Dynamic size (grows/shrinks as needed)
- Efficient insertions/deletions at the beginning (O(1))
- No wasted memory from pre-allocation

**Disadvantages:**
- No random access (must traverse from head)
- Extra memory for storing pointers
- Sequential access only (O(n) to reach an element)

## Common Operations

- **Insert**: Add nodes at beginning, end, or middle
- **Delete**: Remove nodes by value or position
- **Search**: Traverse to find elements
- **Traverse**: Visit each node sequentially

Linked lists are fundamental in implementing other data structures like stacks, queues, and graphs, and are useful when you need frequent insertions/deletions without knowing the size beforehand.


In this directory, the **linkListInteractive** program implements the following functionalities:
- Creates a linked list from user-provided values
- Traverse the linked list
- Add all the elements of the list
- Find the maximum and minimum elements
- Search a specific element by value
- Delete a node by both value and position
- Insert a node at desired position
