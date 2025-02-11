// Implementation of Doubly Linked List in C Programming Language
#include<stdio.h>
#include<stdlib.h>

#define operations 13

struct node{
    int rollNo;
    struct node* prev;
    struct node* next;
};

struct node* start = NULL;

//Functions to implement a linked list
        //Insertion Operations
struct node* insert_at_begin(struct node* );
struct node* insert_at_end(struct node* );
struct node* insert_before_node(struct node* );
struct node* insert_after_node(struct node* );
        //Deletion Operations
struct node* delete_begin(struct node* );
struct node* delete_end(struct node* );
struct node* delete_before_node(struct node* );
struct node* delete_after_node(struct node* );
struct node* destroy_list(struct node*);
        //Traversing List
void display_list(struct node* );
int searching(struct node* , int );
int length_of_list(struct node* );

int main(){
    printf("\t\t\t\tIMPLEMENTATION of DOUBLY LINKED LIST in C\n");
    int option, index, num, length;
    do{
    printf("\n\n********** MAIN MENU **********");
    printf("\n\t1. Insert node at begining");
    printf("\n\t2. Insert node at end");
    printf("\n\t3. Insert node before given node");
    printf("\n\t4. Insert node after given node");
    printf("\n\t5. Delete node at Begining");
    printf("\n\t6. Delete node at End");
    printf("\n\t7. Delete node before given Node");
    printf("\n\t8. Delete node after given Node");
    printf("\n\t9. Search Node in the Linked List");
    printf("\n\t10. Display Linked List");
    printf("\n\t11. Destroy Linked List");
    printf("\n\t12. Length of Linked List");
    printf("\n\t13. Exit Program");
    printf("\nEnter your choice:- ");
    scanf("%d", &option);
    if(option < operations){
        switch(option){
            case 1:
                start = insert_at_begin(start);
                break;
            case 2:
                start = insert_at_end(start);
                break;
            case 3:
                start = insert_before_node(start);
                break;
            case 4:
                start = insert_after_node(start);
                break;
            case 5:
                start = delete_begin(start);
                break;
            case 6:
                start = delete_end(start);
                break; 
            case 7:
                start = delete_before_node(start);
                break;
            case 8:
                start = delete_after_node(start);
                break;
            case 9:
                printf("Enter Roll No. to be searched:- ");
                scanf("%d", &num);
                index = searching(start, num);
                if(index == -1)
                    printf("\nSearch Result:- Entered Node is not present in the Linked List");
                else
                    printf("\nSearch Result:- Entered Node is present in the Linked List at index %d", index);
                break;
            case 10:
                display_list(start);
                break;
            case 11:
                start = destroy_list(start);
                break;
            case 12:
                length = length_of_list(start);
                printf("\nLength of List = %d\n", length);
                break;
        }
    }
    else if(option == operations){
        start = destroy_list(start);
        printf("\n*********** END OF PROGRAM ***********");
    }
    else
        printf("\nError:- Invalid operation!!!");
    }while(option != operations);
    return 0;
}

struct node* insert_at_begin(struct node* head){
    //printf("\nInserting Node at the Start of List...");
    struct node* newNode;
    int data;
    //char *name; 
    printf("\nEnter Roll No.:- ");
    scanf("%d", &data);
    newNode = (struct node*) malloc(sizeof(struct node));
    if (newNode == NULL)
        printf("\nError:- coludn't allocate space for the node!!!");
    else if(head == NULL){
        printf("\nSuccess:- Memory Allocated Successfully...");    
        newNode->rollNo = data;
        head = newNode;
        newNode->next = NULL;
        newNode->prev = NULL;
        printf("\nStart:- Pre-Node = %x\tRoll No. = %d\tNext Node = %x", head->prev, head->rollNo, head->next);
    }
    else{
        printf("\nSuccess:- Memory Allocated Successfully...");    
        newNode->rollNo = data;
        head->prev = newNode;
        newNode->next = head;
        newNode->prev = NULL;
        head = newNode;
        printf("\nStart:- Pre-Node = %x\tRoll No. = %d\tNext Node = %x", head->prev, head->rollNo, head->next);
    }
    return head;
}

struct node* insert_before_node(struct node* head){
    printf("\nInserting Node Before given Node...");
    if(head != NULL){
        struct node* newNode;
        struct node *ptr, *prevPtr;
        int data, val;
        printf("\nEnter the Roll No. before which node is to be inserted:- ");
        scanf("%d", &val);
        if(searching(head, val) != -1){
            printf("\nEnter data for the node:- ");
            scanf("%d", &data);
            newNode = (struct node*) malloc(sizeof(struct node));
            if(newNode != NULL){
                printf("\nSuccess:- Memory Allocated Successfully...");    
                if(head->rollNo == val){
                    newNode->rollNo = data;
                    newNode->next = head;
                    newNode->prev = NULL;
                    head->prev = newNode;
                    head = newNode;
                    printf("\nStart:- Pre-Node = %x\tRoll No. = %d\tNext Node = %x", head->prev, head->rollNo, head->next);
                }
                else{
                    newNode->rollNo = data;
                    ptr = start;
                    while(ptr->rollNo != val){
                        //printf("\nTraversing through the List...");
                        prevPtr = ptr;
                        ptr = ptr->next;
                    }
                    prevPtr->next = newNode;
                    newNode->prev = prevPtr;
                    newNode->next = ptr;
                    ptr->prev = newNode;
                }
            }
            else
                printf("\nError:- Couldn't allocate space for node...");
        }
        else
            printf("\nError:- Entered No. is not in the Linked List...");
    }
    else
        printf("\nError:- EMPTY LIST!!! Can't perform operation...");
    return head;
}

struct node* insert_after_node(struct node* head){
    printf("\nInserting Node After given Node...");
    if(head != NULL){
        struct node* newNode;
        struct node *ptr, *nextPtr;
        int data, val;
        printf("\nEnter the Roll No. after which node is to be inserted:- ");
        scanf("%d", &val);
        if(searching(head, val) != -1){
            printf("\nEnter data for the node:- ");
            scanf("%d", &data);
            newNode = (struct node*) malloc(sizeof(struct node));
            if(newNode != NULL){
                printf("\nSuccess:- Memory Allocated Successfully...\n");
                newNode->rollNo = data;
                ptr = start;
                nextPtr = start->next;
                while(ptr->rollNo != val){
                    //printf("Traversing through the List...\n");
                    ptr = ptr->next;
                    nextPtr = ptr->next;
                }
                ptr->next = newNode;
                newNode->next = nextPtr;
            }
            else
                printf("\nError:- Couldn't allocate space for node...");
        }
        else
            printf("\nError:- Entered No. is not present in the Linked List...");
    }
    else
        printf("\nError:- EMPTY LIST!!! Can't perform operaton...");
    return head;
}

struct node* insert_at_end(struct node* head){
    printf("\nInserting Node at the End...");
    struct node *ptr, *newNode;
    int data;  
    if(head == NULL)
        head = insert_at_begin(head);
    else{
        printf("\nSuccess:- Memory Allocated Successfully...");    
        printf("\nEnter the data : ");
        scanf("%d", &data);
        newNode = (struct node *)malloc(sizeof(struct node));
        if(newNode == NULL)
            printf("\nError:- Couldn't Allocate Memory");
        else{
            newNode->rollNo = data;
            newNode->next = NULL;
            ptr = start;
            while(ptr->next != NULL)
                ptr = ptr -> next;
            ptr->next = newNode;
            newNode->prev = ptr;
            printf("\nNewNode:- Roll No. = %d\tNext Node = %x", newNode->rollNo, newNode->next);
        }
    }
    return head;
}


struct node* delete_begin(struct node* head){
    printf("\nDeleting the first Node...\n");
    struct node* temp = head;
    if(head != NULL){
        temp = head;
        head = head->next;
        head->prev = NULL;
        printf("\nDeleted Node:- Data = %d   Address = %x", temp->rollNo, temp->next);
        free(temp);
    }
    else
        printf("\nError:- Can't delete on an EMPTY Linked List");
    return head;
}

struct node* delete_before_node(struct node* head){
    //printf("\nDeleting Node Before given Node...");  
    if(head != NULL){
        struct node* ptr;
        struct node* nextPtr;
        struct node* prevPtr;
        int data;
        printf("\nEnter the Roll No. of the node before which deletion is to take place: ");
        scanf("%d", &data);
        if(searching(head, data) != -1){
            if(head->rollNo == data)
                printf("\nError:- No Node before this node. Deletion can't be performed...");
            else if(head->next->rollNo == data)
                head = delete_begin(head);
            else{
                ptr = start;
                nextPtr = start->next;
                while(nextPtr->rollNo != data){
                    prevPtr = ptr;
                    ptr = ptr->next;
                    nextPtr = ptr->next;
                }
                //printf("\nPrevPtr-> %d %x\nPtr-> %d %x\nNextPtr-> %d %x", prevPtr->rollNo, prevPtr->next, ptr->rollNo, ptr->next, nextPtr->rollNo, nextPtr->next);
                prevPtr->next = nextPtr;
                nextPtr->prev = prevPtr;
                free(ptr);
            }
        }
        else
            printf("\nError:- Entered Node is not present in the Linked List...");
    }
    else
        printf("\nError:- EMPTY Linked List...\n");
    return head;
}

struct node* delete_after_node(struct node* head){
    //printf("\nDeleting Node After given Node...\n");
    struct node* ptr;
    struct node* last;
    struct node* nextPtr;
    int data;
    if(start != NULL){
        printf("\nEnter the Roll No. of the node before which deletion is to take place: ");
        scanf("%d", &data);
        if(searching(head, data) != -1){
            last = start;
            while(last->next != NULL)
                last = last->next;
            if(last->rollNo == data){
                printf("\nError:-  No Node after this node. Deletion can't be performed...");
            }
            else if(last->prev->rollNo == data){
                printf("\nDeleting Last Element...");
                struct node* temp;
                temp = last;
                last = temp->prev;
                last->next = NULL;
                temp->prev = NULL;
                printf("\nDeleted Node:- Data = %d   Address = %x", temp->rollNo, temp->next);
                free(temp);
            }
            else{   
                ptr = start;
                nextPtr = start->next;
                while(ptr->rollNo != data){
                    ptr = ptr->next;
                    nextPtr = ptr->next;
                }
                //printf("\nPtr-> %d %x\nNextPtr-> %d %x", ptr->rollNo, ptr->next, nextPtr->rollNo, nextPtr->next);
                ptr->next = nextPtr->next;
                nextPtr->next->prev = ptr;
                free(nextPtr);
            }
        }
        else
            printf("\nError:- Entered Node is not present in the Linked List...");
    }
    else
        printf("\nError:- EMPTY Linked List...");
    return head;
}

struct node* delete_end(struct node* head){
    printf("\nDeleting the last Node...\n");
    struct node* ptr;
    struct node* prev;
    if(head != NULL){
        if(head->next != NULL){
            ptr = start;
            while(ptr->next != NULL){
                prev = ptr;
                ptr = ptr->next;
            }
            prev->next = NULL;
            ptr->prev = NULL;
            printf("Deleted Node:- Data = %d   Address = %x\n", ptr->rollNo, ptr->next);
            free(ptr); 
        }
        else{
            free(head);
            head = NULL;
            printf("Deleted Node:- Data = %d   Address = %x\n", ptr->rollNo, ptr->next);
        }
    }
    else
        printf("Error:- EMPTY Linked List!!!\n");
    return head;
}

struct node* destroy_list(struct node* head){
    printf("Destroying the entire list...\n");
    if(head != NULL){
        struct node* current;
        struct node* nextPointer;
        current = head;
        while(current != NULL){
            //printf("\nDeleting Node with Roll No. %d ...\n", current->rollNo);
            printf("\nCurrent-> Roll No.:- %d\tAddress:- %x", current->rollNo,current->next);
            nextPointer = current->next;
            free(current);
            printf("\nCurrent-> Roll No.:- %d\tAddress:- %x", current->rollNo,current->next);
            current = nextPointer;
        }
        head = current;
    }
    else
        printf("Error:- the list is already EMPTY...");
    return head;
}

void display_list(struct node* head){
    printf("\nDisplaying the Linked List...\n");
    struct node* ptr = head;
    if(head == NULL)
        printf("Error:- EMPTY LIST...\n");
    else{
        while(ptr != NULL){
            printf("Current Node:- Previous Node = %x\tData = %d & Address = %x\tNext Node = %x\n", ptr->prev, ptr->rollNo, ptr, ptr->next);
            ptr = ptr->next;
        }
    } 
}

// Not Working
int searching(struct node* head, int key){
    printf("\nSearching for Node in the Singly Linked List...");
    //printf("\nkey= %d", key);
    if(head != NULL){
        struct node* ptr;
        ptr = head;
        //printf("\nPtr-> %d %x", ptr->rollNo, ptr->next, ptr);
        int i = 0;
        int test;
        while(ptr != NULL){
            test = (ptr->rollNo == key);
            //printf("\ntest = %d", test);
            //printf("\nIteration = %d\tPtr-> %d %x", i, ptr->rollNo, ptr->next, ptr);
            if(ptr->rollNo == key){
                //printf("inside if-> key = %d", i);
                return i+1;
            }
            ptr = ptr->next;
            i++;
        }
        return -1;
    }
    else{
        printf("Error:- EMPTY List...\n");
        return -1;
    }
}

int length_of_list(struct node* head){
    printf("\nCouting nodes of the Linked List...");
    if(head == NULL)
        return 0;
    else{
        struct node* ptr;
        int len;
        ptr = start;
        for(len=0; ptr != NULL; len++){
            ptr = ptr->next;
        }
        return len;
    }
}
