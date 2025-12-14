#include<iostream>
using namespace std;

struct Node
{
    string name;
    Node* next;
};

class SYCM
{
    Node* head;
    public:
    SYCM()
    {
        head=NULL;
    }

    void insert(string s)
    {
        Node* n=new Node();
        n->name=s;
        n->next=head;
        head=n;
    }
    bool search(string s)
    {
        Node* temp=head;
        while(temp){
            if(temp->name==s)
            return true;

            temp=temp->next;
        }
        return false;
    }

    Node* getHead()
    {
        return head;
    }

    void display()
    {
        Node* temp=head;
        while(temp)
        {
            cout<<temp->name<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main()
{
    SYCM cricket , football;
    int total,n1,n2;
    cout<<"Enter total number of Students : ";
    cin>>total;

    cout<<"Enter the number of Students who likes cricket: ";
    cin>>n1;
    cout<<"Enter names:";
    for(int i=0;i<n1;i++)
    {
        string s;
        cin>>s;
        cricket.insert(s);
    }

    cout<<"Enter the number of students who likes football: ";
    cin>>n2;
    cout<<"Enter Names:";
    for(int i=0;i<n2;i++)
    {
        string s;
        cin>>s;
        football.insert(s);
    }
    
    cout << "\nStudents who like Cricket: ";
    cricket.display();
    cout << "\nStudents who like Football: ";
    football.display();

    //(a) Students who likes both Cricket and football (Intersection)
    cout<<"\nStudents who likes both Cricket and football :";
    Node* tem=cricket.getHead();
    while(tem)
    {
        if (football.search(tem->name))
        {
            cout<<tem->name<<" ";
        }
        tem=tem->next;
    }

    //(b) Students who like either Cricket or Football, but not both. (Symmetric Difference)
    cout<<"\nStudents who like either Cricket or Football, but not both: ";

    Node* temp=cricket.getHead();
    while (temp)
    {
       if(!football.search(temp->name))
       {
            cout<<temp->name<<" ";
       }
       temp=temp->next;
    }
    Node* temp2=football.getHead();
    while(temp2)
    {
        if(!cricket.search(temp2->name))
        {
            cout<<temp2->name<<" ";
        }
        temp2=temp2->next;
    }
    
    //The number of students who like neither Cricket nor Football.
    int count=0;
    Node* t1=cricket.getHead();
    while(t1)
    {
        count++;
        t1=t1->next;
    }

    Node* t2=football.getHead();
    while(t2)
    {
        if(!cricket.search(t2->name))
        {
        count++;
        }
        t2=t2->next;
    }

    cout<<"\nNumber of Students who neither like cricket or football :"<<total-count;
    return 0;
}