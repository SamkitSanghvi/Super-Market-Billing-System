#include<bits/stdc++.h>
using namespace std;

class shopping{
    private: 
            int pCode;
            float pPrice;
            float dis;
            string pName;
    public: 
            void Menu();
            void administrators();
            void buyer();
            void add();
            void edit();
            void Remove();
            void list();
            void bill();
};


void shopping:: Menu(){

        m:
        int choice;
        string email;
        string password;

        cout<<"\t\t\t\t--------------------------------------------\n";
        cout<<"\t\t\t\t                                            \n";
        cout<<"\t\t\t\t                Super Market                \n";
        cout<<"\t\t\t\t                                            \n";
        cout<<"\t\t\t\t--------------------------------------------\n";
        cout<<"\t\t\t\t 1) Administrator                           \n";
        cout<<"\t\t\t\t 2) Buyer                                   \n";
        cout<<"\t\t\t\t 3) Exit                                    \n";
        cout<<"\n\t\t\t  Please Enter Your Choice : ";
        cin>>choice;
        switch(choice){
            case 1:
                    cout<<"\t\t\t Please Login \n";
                    cout<<"\t\t\t Enter Email   ";
                    cin>>email;
                    cout<<"\n\t\t\t Enter Password ";
                    cin>>password;
                    if(email == "samkitsanghvi@gmail.com" and password == "Hello@123")
                        administrators();
                    else
                        cout<<"Invalid Email/Password";
                    break;
            case 2:
                    buyer();
                    break;
            case 3:
                    exit(0);
                    break;
            default :
                    cout<<"Plese entre Valid Choice"<<endl;
                    break;
        }
    goto m;
}


void shopping::administrators(){

        m:
        int choice;
    
        cout<<"\t\t\t\t--------------------------------------------\n";
        cout<<"\t\t\t\t                                            \n";
        cout<<"\t\t\t\t                Adminstrator Menu           \n";
        cout<<"\t\t\t\t                                            \n";
        cout<<"\t\t\t\t--------------------------------------------\n";
        cout<<"\t\t\t\t 1) Add the Product                          \n";
        cout<<"\t\t\t\t 2) Modify the Product                       \n";
        cout<<"\t\t\t\t 3) Delete the Product                       \n";
        cout<<"\t\t\t\t 4) Back to Menu                       \n";
        cout<<"\n\t\t\t Please Enter Your Choice                \n";
        cin>>choice;


        switch(choice){
            case 1:
                add();
                break;
            case 2:
                edit();
                break;
            case 3: 
                Remove();
                break;
            case 4: 
                Menu();
                break;
            default:
                cout<<"Please Enter Valid Choice"<<endl;
                break;
        }   
        goto m;
}

void shopping :: buyer(){
    m:  
    int choice;
        cout<<"\t\t\t\t--------------------------------------------\n";
        cout<<"\t\t\t\t                                            \n";
        cout<<"\t\t\t\t                Adminstrator Menu           \n";
        cout<<"\t\t\t\t                                            \n";
        cout<<"\t\t\t\t--------------------------------------------\n";
        cout<<"\t\t\t\t 1) Buy the Product                          \n";
        cout<<"\t\t\t\t 2) Go Back                                  \n";
        cout<<"\n\t\t\t  Please Enter Your Choice                \n";
        cin>>choice;

        switch(choice){
            case 1:
                bill();
                break;
            case 2:
                Menu();
                break;
            default :
                cout<<"Please Enter Valid Choice"<<endl;
        }
        goto m;
}



void shopping :: add(){
    m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;
    
    cout<<"\n\n\t\t\t Add New Product ";
    cout<<"\n\n\t Produce Code of the Product ";
    cin>>pCode;
    cout<<"\n\n\t Name of the Product ";
    cin>>pName;
    cout<<"\n\n\t Price of the Product ";
    cin>>pPrice;
    cout<<"\n\n\t discount on  the Product ";
    cin>>dis;
    data.open("Database.txt",ios::in);

    if(!data){
        
        data.open("Database.txt",ios::app|ios::out);
        data<<" "<<pCode<<" "<<pName<<" "<<pPrice<<" "<<dis<<"\n";
        data.close();
    }

    else{
        data>>c>>n>>p>>d;

        while(!data.eof()){

            if(c == pCode)
                token++;
            data>>c>>n>>p>>d;
        }
        data.close();
    

        if(token == 1)
        goto m;

        else{
        data.open("Database.txt",ios::app|ios::out);
        data<<" "<<pCode<<" "<<pName<<" "<<pPrice<<" "<<dis<<"\n";
        data.close();
        }
    }
    cout<<"\n\n\t\t Record Inserted "<<endl;
}


void shopping :: edit(){

    fstream data,data1;
    int pkey;
    int token = 0;
    int c;
    float p,d;
    string n;

    cout<<"\n\t\t\t Modify the Record";
    cout<<"\n\t\t\t Product Code";
    cin>>pkey;

    data.open("Database.txt",ios::in);
    if(!data)
        cout<<"\n\n File Doesn't exist! ";
    else{
        
        data1.open("Database1.txt",ios::app|ios::out);
        data>>pCode>>pName>>pPrice>>dis;
        while(!data.eof()){
            if(pkey == pCode){
                cout<<"\n\t\t Product New Code";
                cin>>c;
                cout<<"\n\t\t Name of the Product";
                cin>>n;
                cout<<"\n\t\t Price of the Product";
                cin>>p;
                cout<<"\n\t\t Discount of the product";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"Record Edited Sucessfully....";
                token++;
            }
            else{
                data1<<" "<<pCode<<" "<<pName<<" "<<pPrice<<" "<<dis<<"\n";
            }
            data>>pCode>>pName>>pPrice>>dis;
        }
        data.close();
        data1.close();
        remove("Database.txt");
        rename("Database1.txt", "Database.txt");

        if(token == 0)
            cout<<"\n\n Record Not Found"<<endl; 
    }
}

void shopping :: Remove(){
    fstream data,data1;
    int pkey;
    int token = 0;
    cout<<"\n\n\t Delete Product ";
    cout<<"\n\t\t Product Code ";
    cin>>pkey;
    data.open("Database.txt",ios::in);
    if(!data)
        cout<<"\n\n File Doesn't exist! ";
    
    else{
        data1.open("Database1.txt",ios::app|ios::out);
        data>>pCode>>pName>>pPrice>>dis;    
        while(!data.eof()){
            if(pkey == pCode){
                cout<<"\n\n\t Product Deleted Sucessfully";
                token++;
            }
            else{
                data1<<" "<<pCode<<" "<<pName<<" "<<pPrice<<" "<<dis<<"\n";
            }
            data>>pCode>>pName>>pPrice>>dis;
        }
        data.close();
        data1.close();
        remove("Database.txt");
        rename("Database1.txt", "Database.txt");
        if(token == 0)
            cout<<"\n\n Record Not Found"<<endl; 
    }
}

void shopping :: list(){
    fstream data;
    data.open("Database.txt", ios::in);
    cout<<"\n\n|--------------------------------------------------|\n";
    cout<<"Product No\t\t Name \t\t price";
    cout<<"\n\n|--------------------------------------------------|\n";
    data>>pCode>>pName>>pPrice>>dis;
    while(!data.eof()){
        cout<<pCode<<"\t\t"<<pName<<"\t\t"<<pPrice<<endl;
        data>>pCode>>pName>>pPrice>>dis;
    }
    data.close();
}



void shopping :: bill(){

    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float dis = 0;
    float total = 0;
    cout<<"\n\n\t\t\t\t RECEIPT ";
    data.open("Database.txt",ios::in);
    if(!data){
        cout<<"\n\n Empty DataBase..";
    }
    else{ 
        data.close();
        list();
        cout<<"\n---------------------------------------\n";
        cout<<"\n                                        \n";
        cout<<"\n            Place Your Order            \n";
        do{ 
            m:
            cout<<"\n\n Enter the Product Code ";
            cin>>arrc[c];
            cout<<"\n\nEnter the Quantity : ";
            cin>>arrq[c];
            for(int i=0;i<c;i++){
                if(arrc[c] == arrc[i]){
                    cout<<"\n\n Duplicate Product Code...";
                    goto m;
                }
            }
            c++;
            cout<<"Do you want to buy another Product?? if yes then press y else n";
            cin>>choice;
        }
        while(choice == 'y');
        cout<<"\n---------------------------------------\n";
        cout<<"\n                                        \n";
        cout<<"\n            Receipt                     \n";
        cout<<"\n                                        \n";
        cout<<"\n---------------------------------------\n";
        cout<<"\n Product No \t Product Name \t Product Quantity \t Price \t Amount with Discount\n";

        for(int i=0;i<c;i++){
            data.open("Database.txt",ios::in);
            data>>pCode>>pName>>pPrice>>dis;
            while(!data.eof()){
                if(pCode==arrc[i]){
                    amount = pPrice * arrq[i];
                    dis = amount - (amount*dis/100);
                    total = total + dis;
                    cout<<"\n"<<pCode<< "\t\t"<<pName<<"\t\t"<<arrq[i]<<"\t\t"<<pPrice<<"\t"<<amount<<"\t\t"<<dis;
                }
                data>>pCode>>pName>>pPrice>>dis;
            }
        }
        data.close();
    }
    cout<<"\n\nTotal Amount "<<total<<endl;
}

int main(){
    shopping s1;
    s1.Menu();
}