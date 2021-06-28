#include <iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
using namespace std;
void administrator();
int main();
class products
{
public:
    int id;
    std::string name;
    float price,tax,qty;

    int admin()   //read fn
    {
        int n;
        ifstream File;
        File.open("product2.txt");
        while(File>>id>>name>>price>>tax)
        {
           std::cout<<"\n"<<id<<"   "<<name<<"  "<<price<<"    "<<tax<<"\n";
        }
        File.close();
        cout<<"\n\n\npress 9 to go back : ";
        cin>>n;
        if(n==9)
        {
            system("CLS");
            administrator();
        }
    }   
    int admin(int m)  //write
        {
        int i;
        fstream File;
        File.open("product2.txt", ios::in | ios::out | ios::app);
        for(int i=0;i<m;i++)
        {
        cout<<"\nEnter the id :";
        cin>>id;
        cout<<"\nEnter the name of the product  :";
        cin>>name;
        cout<<"\nEnter price  :";
        cin>>price;
        cout<<"\nEnter tax(%)  :  ";
        cin>>tax;
         File<<"\n"<<id<<" "<<name<<"          "<<price<<"      "<<tax;
        cout<<"\nProduct has been created successfully \n ";
        }
        File.close();
        system("CLS");
        administrator();
    } 
    int admin(float q,int m)   //delete
    {
     fstream File;
      File.open("product2.txt", ios:: in | ios::out );
      fstream File2;
      File2.open("Temp.txt", ios::out);
      for(int i=0;i<m;i++)
      {
      while(File>>id>>name>>price>>tax)
      {

       if(id!=q)
        
        {
            File2<<"\n"<<id<<" "<<name<<"          "<<price<<"      "<<tax;
        }
      }
      
      File2.close();
      File.close();
      remove("product2.txt");
      rename("Temp.txt", "product2.txt");
      cout << "\n\n\tRecord Deleted ..\n\n";
    }
    }
};


class customer:public products
{
    public:
  int w,c;
  int sid[10000];
  string nname[10000],cashier,last;
  char date[20],z;
  float pricen[10000],taxx[10000],finalprice[10000],total,qqty[10000];
  customer ()
  {
     c=1;
     total=0;
  }
    
  int cust()
  {
    int i,s;
 cout<<"\nenter the id (id starts from 11:currently 7 items included): ";
 cin>>w;
 fstream File;
 File.open("product2.txt");
while(File>>id>>name>>price>>tax)
 {

       if(id==w)
       {
        cout<<"\nEnter the quantity : ";
         cin>>qqty[c];
         
        sid[c]=id;
        nname[c]=name;
        pricen[c]=price;
        taxx[c]=tax;
        finalprice[c]=qqty[c]*(price+((tax*price)/100));
         cout<<"\nproduct successfully added\n " ;
         break;
       }
 }
 if(id!=w)
 {
     cout<<"\nInvalid code";
     
     cout<<"\n\n1.To re-enter id (press 1) \n2.go to main menu (press 2)\n \nEnter code : ";
     cin>>s;
     if(s==1)
     {
         system("CLS");
         cust();
         exit(1);
     }
     else if(s==2)
     {
         system("CLS");
       main();
       exit(1);
    
     }
     else
     {
         system("CLS");
         cout<<"\nInvalid";
         exit(1);
         

     }
     
 }

   
         
         cout<<"\nadd new product(y/n) :  ";
         cin>>z;
         if(z=='y')
         {
             c++;
             cust();
         }
         else
         {
             cout<<"\nDate(dd-mm-yyyy) : ";
             cin>>date;
             cout<<"\nName of the cashier(Full name) : ";
             cin>>cashier>>last;
             system("CLS");
             cout<<"\n     KARTHIKA SUPERMARKET\n\n";
             cout<<"Date :"<<date;
             cout<<"\nName of the cashier : "<<cashier<<" "<<last;


             cout<<"\n";
             cout<<"________________________________________________________________________"<<"\n";
             cout<<"id |  price      |   tax(%)   |   Qty   |   Fprice    | Name           |"<<"\n";
             cout<<"___|_____________|____________|_________|_____________|________________|"<<"\n";
             for(i=1;i<=c;i++)
             {
                 total=total+finalprice[i];
                std::cout<<sid[i]<<"     "<<pricen[i]<<"            "<<taxx[i]<<"           "<<qqty[i]<<"         "<<finalprice[i]<<"          "<<nname[i]<<"\n";
                 cout<<"   |             |            |         |             |                |"<<"\n";
             }
             cout<<"_________________________________________________________________________";
             cout<<"\n\nTOTAL : Rs "<<total<<"\n\n";
             system("pause");
             
         }
         
 }        
};
products m;
customer o;
void administrator()
{ 
    
    int b,s;
    float w;
    
    
    cout<<"1.Display products\n2.Add products \n3.Delete product\n4.modify product\n5.back to main menu\n";
                cout<<"\nEnter code  : ";
                
                cin>>b;
                switch(b)
                {
                    case 1: system("CLS");
                             m.admin();
                             break;
                    case 2: system("CLS");
                            cout<<"How many new products(number) : ";
                            cin>>s;
                             m.admin(s);
                             break;
                    case 3: system("CLS");
                            cout<<"\nenter no: of files to be deleted : ";
                            cin>>s;
                            cout<<"\nenter the id (id starts from 11:currently 7 items included) to modify or delete: ";
                            cin>>w;
                            m.admin(w,s);
                            break;
                    case 4: system("CLS");
                            cout<<"\nenter no: of files to be deleted : ";
                            cin>>s;
                            cout<<"\nenter the id (id starts from 11:currently 7 items included) to modify or delete: ";
                            cin>>w;
                            m.admin(w,s);
                            cout<<"\nEnter modified details : \n";
                             m.admin(s);
                            break;
                    case 5: system("CLS");
                            main();
                            exit(1);
                    default: cout<<"\n\nInvalid code\n ";
                             exit(1);
                }
                
    
                
}
int verification()
{
    int no;
    string username,password;
    cout<<"\nusername :";
    cin>>username;
    cout<<"\npassword : ";
    cin>>password;
    system("CLS");
    if(username=="karthika" && password=="123456")
    {
        administrator();
    }
    
    else
    {
        cout<<"\nWrong username/password ";
        cout<<"\n\npress 7 to go to main menu : ";
        cin>>no;
        if(no==7)
        {
            main();
        }
    }
}


int main()
{
    int a;
    system("CLS");
    cout<<"1.Customer\n2.Administrator\n3.Exit\n";
    cout<<"Enter code : ";
    cin>>a;
    switch(a)
    {
        case 1:  o.cust();
                 break;
        case 2: system("CLS");
                verification();
                administrator();
                break;
        case 3: system("CLS");
                cout<<"\n      END OF THE PROGRAM \n\n ";
                break;
        default: cout<<"\n\nInvalid code ";
    }
    return 0;
}
    
