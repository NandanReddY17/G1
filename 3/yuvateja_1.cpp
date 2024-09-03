#include <stdio.h>
#include <stdlib.h>

class LL{
    public:
        struct node{
            int val;
            struct node* next;
        };
        struct node* head;

        LL(){
            head = NULL;
        }

        void ins(int num){
            struct node* NewNode = (struct node *)malloc(sizeof(node));
            NewNode->val = num;
            NewNode->next = NULL;
            if(head == NULL){
                head = NewNode;
            }
            else{
                struct node* temp = head;
                while(temp->next != NULL){
                    temp = temp->next;
                }
                temp->next = NewNode;
            }
        }

        int del(int num){
            if(head == NULL){
                return 0;
            }
            struct node * temp = head;
            struct node * par = NULL;
            while(temp != NULL && temp->val != num){
                par = temp;
                temp = temp->next;
            }
            if(temp == head){
                if(temp->next == NULL){
                    head = NULL;
                    free(temp);
                    return 1;
                }
                else{
                    head = head->next;
                    free(temp);
                    return 1;
                }
            }
            else if(temp == NULL){
                return 0;
            }
            else{
                par->next = temp->next;
                free(temp);
                return 1;
            }
        }

        void disp(){
            printf("The Linked List is:-\n");
            struct node* temp = head;
            while(temp != NULL){
                printf("%d || ", temp->val);
                temp = temp->next;
            }
        }

        bool search(int num){
            struct node * temp = head;
            struct node * par = NULL;
            while(temp != NULL && temp->val != num){
                par = temp;
                temp = temp->next;
            }
            if(temp == NULL){
                return false;
            }
            else{
                return true;
            }
        }
};


int main(){
    LL l1;
    int num;
    while(1){
        printf("\nEnter:-\n1. For Inserting New Node\n2. For Deleting Node\n3. For Displaying Linked List\n4. For Searching\n5. For Exit\nExnter: ");
        int n;
        scanf("%d", &n);

        switch(n){
            case 1:
                printf("Enter the number you wanted to Insert : ");
                scanf("%d", &num);
                l1.ins(num);
                break;

            case 2:
                printf("Enter the number you wanted to Delete : ");
                scanf("%d", &num);
                if(l1.del(num) == 1){
                    printf("Deleted Successfully.");
                }
                else{
                    printf("Couldn't find %d in the Linked List",num);
                }
                break;

            case 3:
                l1.disp();
                break;

            case 4:
                printf("Enter the number you wanted to Search for : ");
                scanf("%d", &num);
                if(l1.search(num) == true){
                    printf("%d is Found !!", num);
                }
                else{
                    printf("Couldn't find %d in the Linked List",num);
                }
                break;

            case 5:
                exit(0);
                
            default:
                printf("Please Enter a Valid Choice !!");
        }
    }
}
