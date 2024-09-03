#include <stdio.h>
#include <stdlib.h>

class Linked_List
{
    struct node
    {
        int data;
        struct node *next;
    } *head;
    struct node *temp = head;

public:
    Linked_List()
    {
        head = NULL;
    }
    struct node *getHead()
    {
        return head;
    }

    void insert_beg(int num);
    void insert_end(int num);
    void insert_pos(int num, int pos);
    int del_beg();
    int del_end();
    int del_pos(int pos);
    void search(int num);
  
    void display();
};
int main()
{
    int pos;
    int ch = 0;
    int num;
    Linked_List l1;
    printf("Choice 1: Insert at Beginning.\nChoice 2: Insert at End.\nChoice 3: Insert at a Position.\nChoice 4: Delete at Beginning.\nChoice 5: Delete at End.\nChoice 6: Delete at a position. \nChoice 7:Search for an Element.\nChoice 8: Display List.\nChoice 9 : Exit.\n");
    while (ch != 9)
    {
        printf("Enter your choice: ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            printf("Enter number to insert at beginning: ");
            scanf("%d", &num);
            l1.insert_beg(num);
        }
        else if (ch == 2)
        {
            printf("Enter number to insert at end: ");
            scanf("%d", &num);
            l1.insert_end(num);
        }
        else if (ch == 3)
        {
            printf("Enter number to insert: ");
            scanf("%d", &num);
            printf("Enter position to insert at: ");
            scanf("%d", &pos);
            l1.insert_pos(num, pos);
        }
        else if (ch == 4)
        {
            int data = l1.del_beg();
            printf("Deleted element %d at beginning.\n", data);
        }
        else if (ch == 5)
        {
            int data = l1.del_end();
            printf("Deleted element %d at end.\n", data);
        }
        else if (ch == 6)
        {
            int pos;
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            int data = l1.del_pos(pos);
            printf("Deleted element %d at index %d\n", data, pos);
        }
        else if (ch == 7)
        {
            int num;
            printf("Enter element to search for : ");
            scanf("%d", &num);
            l1.search(num);
        }
        else if (ch == 8)
        {
            printf("List is : ");
            l1.display();
            printf("\n");
        }
       
        }
        else if (ch == 9)
        {
            printf("Thank You\n");
        }
        else
        {
            printf("Enter valid choice.\n");
        }
    }
}
// Insert element in the beginning. Time Complexity is O(1).
void Linked_List::insert_beg(int num)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = head;
    head = newnode;
}

// Insert element in the end. Time Complexity is O(n).
void Linked_List::insert_end(int num)
{
    if (head == NULL)
    {
        insert_beg(num);
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = num;
        newnode->next = NULL;
        temp->next = newnode;
    }
}
// Insert element at a position. Time complexity is Worst case scenario: O(n). Best case scenario: O(1).
void Linked_List::insert_pos(int num, int pos)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    if (pos == 0)
    {
        insert_beg(num);
    }
    else
    {
        for (int i = 0; i < (pos - 1); i++)
        {
            temp = temp->next; // Go to the node before required position.
        }
        newnode->data = num;
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

// Delete the element at the beginning. Time complexity is O(1).
int Linked_List::del_beg()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return 0;
    }
    else
    {
        struct node *temp = head;
        head = head->next;
        int data = temp->data;
        free(temp);
        temp = NULL;
        return data;
    }
}

// Delete element at the end. Time complexity is O(n).
int Linked_List::del_end()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return 0;
    }
    else
    {
        struct node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        int data = temp->next->data;
        temp->next = NULL;
        return data;
    }
}

// Delete element at requested position. Time complexity is Worst Case Scenario: O(n) Best Case Scenario: O(1).
int Linked_List::del_pos(int pos)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return 0;
    }
    else
    {
        struct node *temp = head;
        for (int i = 0; i < (pos - 1); i++)
        {
            if (temp->next != NULL)
            {
                temp = temp->next;
            }
            else
            {
                printf("No element at given position\n");
                return 0;
            }
        }
        int data = temp->next->data;
        temp->next = temp->next->next;
        return data;
    }
}

// Search for elements in the list. Time complexity is O(n).
void Linked_List::search(int num)
{
  int pos = 0;
struct node *temp;

if (head == NULL) {
    printf("List is empty.\n");
} else {
    temp = head;
    while (temp != NULL) {
        if (num == temp->data) {
            printf("%d element is found at index %d.\n", num, pos);
            break;
        } else {
            temp = temp->next;
            pos++;
        }
    }

    // If the loop ends and temp is NULL, the element was not found
    if (temp == NULL) {
        printf("Element %d is not available in the linked list.\n", num);
    }
}

}

// Display the Linked List. Time complexity is O(n).
void Linked_List::display()
{
    struct node *temp = head;
    if (temp == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}
