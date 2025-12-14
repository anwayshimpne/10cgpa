#include<iostream>
using namespace std;


class Node{
    public:
    int roll;
    string name;
    Node *next;

    Node(int roll, string name){
        this->roll=roll;
        this->name=name;
        this->next=NULL;
    }

};


class Linklist{
    private:
    Node* head;

    public :
            Linklist(){
                head=NULL;
            }


    //insert node at the end
    void insertATend(int roll, string name)
    {
        Node *newNode = new Node(roll,name);
        if(head==NULL){
            head=newNode;
            cout<<"New Student Added at END"<<endl;
        }
        else{
            //go to the last node
            Node *temp= head;
            while(temp->next != NULL){
                temp=temp->next;
            }
            //add node now
            temp->next=newNode;
            cout<<"New Student Added at END"<<endl;
        }
    }
         
    //Display Linked List
    void showLL(){
        Node *temp= head;
        //traverse list to end
        while(temp != NULL){
            cout<<temp->roll<<" | "<<temp->name<<endl;
            temp=temp->next;
        }
    }

    //insert node at beginning
    void insertATbeg(int roll, string name){
        Node *newNode = new Node(roll, name);
        
        newNode->next=head;   //beacuse head is currently on first node...so if we add its previous node then its next will HEAD offcourse
        head = newNode;

        cout<<"New Node inserted AT beginning"<<endl;
    }


    //insert AT specific Location 
    void insertATspecificLoc(int roll, string name, int pos)
    {
        Node *newNode =new Node(roll,name);
        Node *temp;
        temp=head;
        
        //traverse list till position-1 
        for(int i=0; i<pos-1; i++){
            temp=temp->next;

            if(temp==NULL)//if list ended before position
            {
                    cout<<"There are less than "<<pos<<" elements in list"<<endl;
                    return;
            }
        }

        newNode->next= temp->next;     //very easy logic...refere diagram
        temp->next=newNode;
        cout<<"Element inserted at specific location...!"<<endl;

    }




};



int main(){

    Linklist sll;
    sll.insertATend(10,"Yash");
    sll.insertATend(20,"raj");
    sll.showLL();
    sll.insertATbeg(30, "Arham");
    sll.insertATbeg(19,"Anway");
    sll.showLL();
    
    sll.insertATspecificLoc(15,"naitik", 1);
    sll.showLL();


    return 0;
}