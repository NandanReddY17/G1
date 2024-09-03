#include<stdio.h>
#include<stdlib.h>
class List{
    int count = 0;
    struct node{
        int data;
        struct node*next;
    }*head,*tp;
    public:
       List(){
          head = NULL;
             }
        void insertpos(int,int);
        void deletebeg();
        void search(int);
        void display();
       

};

int main(){
    List l1;
    int choice,num,pos;
    while(1){
        printf("  MENU  ");
        printf("Enter \n1 Insertion : \n2 Deletion : \n3 search : ");
        printf("\n4 Display : \n5 exit\n");
        printf("\nEnter your choice");
        scanf("%d",&choice);
        switch (choice){
                case 1:{
                    printf("\n Enter the number insert:");
                    scanf("%d",&num);
                    printf("\n Enter the position insert:");
                    scanf("%d",&pos);
                    l1.insertpos(num , pos);
                    break;
                }
                case 2:{
                    printf("The first number has been deleted");
                    l1.deletebeg();
                    break;
                }
                case 3:{
                    printf("\n Enter the number to search:");
                    scanf("%d",&num);
                    l1.search(num);
                    break;
                }
                case 4:{
                    l1.display();
                    break;
                }
                case 5:{
                    return 0;
                    break;
                }
                default:{
                    printf("\n Invalid choice\n");
                    break;
                }

        }

    }
    return 0;
}

void List::insertpos(int num,int pos){
    if(count<pos||pos<0){
        printf("Out of range\n");
        return;
    }
    
    else{
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        struct node *temp = head;
        newnode->data = num;
        newnode->next = NULL;
        for(int i=0;i<pos-2;i++){
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next=newnode;
        printf("The number has been inserted");
        count++;
    }
}        

void List::deletebeg(){
    if(head==NULL){
        printf("Nothing to delete");
        return;
    }
    else{
        struct node *temp = head;
        head=temp->next;
        free(temp);
        count--;
        return;
    }
}

void List::search(int num){
    if(head==NULL){
        printf("There is nothing to search");
        return;
    }
    struct node *temp = head;
    while (temp->next != NULL) {
        if (temp->data==num){
            printf("The number has been found");
            return;
        }
    temp = temp->next;
    }
    if(temp->next == NULL){
        if (temp->data==num){
            printf("The number has been found");
            return;
        }    
    }
    printf("The number has not been found");
}

void List::display(){
    struct node*ptr;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}
