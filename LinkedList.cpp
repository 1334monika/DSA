// 1. insertion at the beginning 
//2. insertion at the end
//3. insertion at any given position
//4 Deletion from the beginning
//5. Deletion from the end
//6. Deletion from any given position


#include<iostream>
#include<vector>

using namespace std;

class Node{
public:
    int value;
    Node *next;

    public : Node(int val){
        value=val;
        next=NULL;
    }

};

Node* createNode(int value){
    Node *temp= new Node(value);
    return temp;
}

Node* insertAtBeginning(Node* head, int value){
    Node *ptr=head;
    Node* temp=createNode(value);
    temp->next=head;
    head=temp;
    return head;
}

Node* insertAtEnd(Node* head, int value){

    Node* ptr=head;
    Node *temp=createNode(value);
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=temp;
    return head;
}

int countNodes(Node* head){
    int count=0;

    Node* ptr=head;

    while(ptr!=NULL){
        ptr=ptr->next;
        count++;
    }
    return count;

}

Node *insertAtPosition(Node* head, int value, int position){
    Node *ptr, *temp;
    if(position==1){
        return insertAtBeginning(head, value);
    }
    
    int totalNodes=countNodes(head);
    if(position>totalNodes){
        return insertAtEnd(head,value);
    }

    ptr=head;

    while(ptr->next && position-2 >0){
        position--;
        ptr=ptr->next;
    }
    
    temp=createNode(value);
    temp->next=ptr->next;
    ptr->next=temp;
    return head;

}

Node* deleteFromBeginning(Node* head){
    if(head==NULL) return head;
    if(head->next==NULL){//single node
        delete head;
        head=NULL;
        return head;
    }
    //moret than one nodes

    Node* temp=head;
    head=head->next;
    delete temp;
    temp=NULL;
    return head;
}

Node* deleteFromEnd(Node* head){
    if(head==NULL) return head;// unable to delete
    if(head->next==NULL){
        delete head;
        head=NULL;
        return head;
    }
    //more than one nodes

    Node *ptr=head;
    while(ptr->next && ptr->next->next!=NULL){
            ptr=ptr->next;

    }
    Node* temp=ptr->next;
    ptr->next=NULL;
    delete temp;
    temp=NULL;
    return head;

}

Node* deleteFromPosition(Node*head , int position){
    if(position==1){
        return deleteFromBeginning(head);
    }
    if(position>countNodes(head)){ 
        return deleteFromEnd(head);
    }

    Node *ptr=head;
    while(ptr->next && position-2 >0){
        ptr=ptr->next;
        position--;
    }
    Node* temp=ptr->next;
    ptr->next=temp->next;
    delete temp;
    temp=NULL;
    return head;
}

void PrintList(Node* head){
    Node* ptr=head;
    while(ptr->next){
        cout<<ptr->value<<" -> ";
        ptr=ptr->next;
    }
    cout<<ptr->value<<endl;
    return ;
}

int main(){

    cout<<"Simulation of Singly linked list options: "<<endl;
    cout<<"1. Insertion at the beginning"<<endl;
    cout<<"2. Insertion at the end"<<endl;
    cout<<"3. Insertion at any given position"<<endl;
    cout<<"4. Deletion from the beginning"<<endl;
    cout<<"5. Deletion from the end"<<endl;
    cout<<"6. Deletion from any given position"<<endl;
    cout<<"7. Number of nodes in the List"<<endl;
    cout<<"8. Print the List"<<endl;
    cout<<"9. Exit the Program"<<endl;

    Node *head=NULL;
    int value;
    while(true){
        int choice;
        cout<<"Enter your choice: ";
        cin>> choice;

        switch(choice){
            case 1:{
                cout<<"Enter the value to insert at the beginning: ";
                cin>>value;
                head=insertAtBeginning(head, value);
                break;
            }
            case 2:{
                cout<<"Enter the value to insert at the end: ";
                cin>>value;
                head=insertAtEnd(head, value);
                break;

            }
            case 3:{
                cout<<"Enter the value to insert  ";
                int pos;
                cin>> value;
                cout<<"Enter the position to insert: ";
                cin>>pos;
                head=insertAtPosition(head, value, pos);
                break;
            }
            case 4:{
                head=deleteFromBeginning(head);
                cout<<"value deleted"<<endl;
                break;
            }
            case 5:{
                head=deleteFromEnd(head);
                cout<<"Value deleted"<<endl;
                break;
            }
            case 6:{
                cout<<"Enter the position to delete: ";
                int pos;
                cin>>pos;
                head=deleteFromPosition(head, pos);
                break;
            }
            case 7:{
                cout<<"Number of nodes in the list: "<<countNodes(head)<<endl;
                break;
            }
            case 8:{
                cout<<"List: ";
                PrintList(head);
                break;
            }
            case 9:{
                cout<<"Exiting the program"<<endl;
                return 0;
            }
        }
    }
    return 0;

}
