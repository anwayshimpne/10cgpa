#include<iostream>
using namespace std;

int multipy(int x, int y)
{
    return x*y;
}

int divide(int x, int y){
    return x/y;
}

int add(int x, int y ){
    return x+y;
}

int substract(int x, int y ){
    return x-y;
}

int main(){

    int a,b;
    char op='c';
    cout<<"Enter two numbers :";
    cin>>a,b;

    cout<<"What operation would u like to perform : \n add(+) \n  substract(-) \n  division(/) \n multiply(*) ";
        cin>>op;
    while(op!='e'){
        

        switch(op){
            case '+' :
            cout<<a<<" + "<<b<<" = "<<add(a,b);
            break;

            case '-' :
            cout<<a<<" - "<<b<<" = "<<substract(a,b);
            break;

            case '/' :
            cout<<a<<" / "<<b<<" = "<<divide(a,b);
            break;

            case '*' :
            cout<<a<<" * "<<b<<" = "<<multipy(a,b);
            break;

            default :
             cout<<"Invalid choice ...";
        }

    }

    return 0;
}