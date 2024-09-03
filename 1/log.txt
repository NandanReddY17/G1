#include <stdio.h>
#include <stdlib.h>

class list {
    struct node {
        int data;
        node* next;
    };
    struct node* head;
public:
    list() {
        head = NULL;
    }
    void insertNode(int data, int position);
    void deleteNode(int data, int position);
    void searchNode(int data);
    void printList();
};

int main() {
    list L;
    int choice, data, position;
    while (1) {
        printf("\n1. Insert at position\n2. Delete at position");
        printf("\n3. Search node\n4. Print list\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter data to be inserted: ");
                scanf("%d", &data);
                printf("\nEnter position to be inserted at: ");
                scanf("%d", &position);
                L.insertNode(data, position);
                break;
            case 2:
                printf("\nEnter data to be deleted: ");
                scanf("%d", &data);
                printf("\nEnter position to be deleted at: ");
                scanf("%d", &position);
                L.deleteNode(data, position);
                break;
            case 3:
                printf("\nEnter the data to be searched: ");
                scanf("%d", &data);
                L.searchNode(data);
                break;
            case 4:
                L.printList();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

void list::insertNode(int data, int position) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if (position == 1) {
        newnode->next = head;
        head = newnode;
    } else {
        struct node* temp = head;
        for (int i = 1; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp != NULL) {
            newnode->next = temp->next;
            temp->next = newnode;
        } else {
            printf("Position is out of bounds\n");
            free(newnode);
        }
    }
}

void list::deleteNode(int data, int position) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node* temp = head;

    if (position == 1) {
        head = head->next;
        free(temp);
    } else {
        struct node* prev = NULL;
        for (int i = 1; i < position && temp != NULL; i++) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Position out of bounds\n");
        } else {
            prev->next = temp->next;
            free(temp);
        }
    }
}

void list::searchNode(int data) {
    struct node* temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            printf("\nPresent\n");
            return;
        }
        temp = temp->next;
    }
    printf("Not found\n");
}

void list::printList() {
    if (head == NULL) {
        printf("\nList is empty\n");
    } else {
        struct node* temp = head;
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
