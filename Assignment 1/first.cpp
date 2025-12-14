#include <iostream>
using namespace std;

//find lenght
void len(char str1[])
{
   int i=0;
   while(str1[i]!=0){
      i++;
   }
   cout<<"length of "<<str1<<" is :"<<i<<endl;
   
}

   
//concatenate
void concat(char str1[], char str2[])
{
   int i=0;
   while(str1[i]!=0){
   i++;
   }
   cout<<"length of str 1 :"<<i<<endl;


   int j=0;
   while(str2[j]!=0)
   {
      str1[i]=str2[j];
      i++;
      j++;
   }
   str1[i]='\0';
   cout<<"Concatenated String :"<<str1;
}

//Reverse the string
void reverse(char str1[])
{

   //finds the last index of string
   int i=0;
   int count=0;
   while(str1[i]!=0){
      i++;
      count++;
   }

      //traverse from last index i.e count-1
   int j=0;
   char rev_str[50];
   for (int i=count-1; i>=0; i--){
      rev_str[j]=str1[i];
      j++;
   }
   rev_str[j]='\0';
   cout<<"The reversed string is :"<<rev_str;
}
 
//copy
void copyStr(char src[], char dest[]) {
    int i = 0;
    while (src[i] != 0) {
        dest[i] = src[i];
        i++;
    } 
    dest[i]=0; 
    cout << "Copied String: " << dest << endl;
}

int main(){
char str1[50], str2[50];
cout<<"Enter first String :";
cin>>str1;

menu:
int choice=0;
cout << "\nMenu:\n";
cout << " 1. Find Length\n 2.Concatenation \n 3.Reverse. \n 4.Copy. \n 5.Exit :\n";
cin >> choice; 
   switch(choice){
   case 1:
      len(str1);
      break;
   case 2:
      cout<<"Enter String to concatenate :";
      cin>>str2;
      concat(str1,str2);
      break;
   case 3:
      reverse(str1);
      break;
   case 4:
      copyStr(str1,str2);
      break;
   case 5: 
      exit(0);
   default:
      cout<<"Please enter valid Choice !!";
   }
   goto menu;
}