#include "str_assign.h"

int main()
{
  cout << "TEST PROGRAM !!" << endl;
  
  str s1("Hello"); 
  
  cout << "s1 = "; 
  s1.print();

  str s2 = s1;
  
  cout << "s2 = "; 
  s2.print();

  str s3("!!!"); 
  
  cout << "s3 = "<<s3<<endl;

  
  cout << "DO s2.append(s3)" << endl;
  s2.append(s3);

  cout << "\ts2 = "; 
  s2.print();

  cout << "DO swap(s2,s3)" << endl;
  swap(s2,s3);

  cout << "\ts2 = "; 
  s2.print();

  cout << "\ts3 = "; 
  s3.print();
  
  str s4;
  cout<<"Enter s4: "<<endl;
  cin>>s4;
  cout<<"s4="<<s4<<endl;
  
  cout<<"s1+s4="<<s1+s4<<endl;
  

  return 0;
}