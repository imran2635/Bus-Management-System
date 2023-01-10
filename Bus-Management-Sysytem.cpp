#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX

void install_bus_information();
void bus_saved();
void Log_In();
void Intro();
void break_t();
void Book_Tickets();
void Cancel_Tickets();
void Available_Bus_Routes();
void bus_info_show();


int flag=0,vertices=0;
vector<pair <string,string> >info;/// From--> To
vector<pair <string,string> >info1;/// For sorting
vector<string> departure_info;/// Departure Information
vector<string>v1(36,"Empty"); ///each bus has 36 seats
vector< vector <string> >v(100,v1); ///100 bus. each bus has 36 seats
vector<int>bus_fair; ///Bus_Fare




void Install_Bus_Information()
{

    char flag;
    do
    {
        ofstream file;
        file.open("Bus_Information.txt",ios::app);


        string f1,f2,f3,f4,f5;

        cout<<"\n\n\n\t\t\tFrom: ";
        cin>>f1;
        cout<<"\n\t\t\tTo: ";
        cin>>f2;
        cout<<"\n\t\t\tDeparture Time: ";
        cin>>f3;
        cout<<"\n\t\t\tFare: ";
        cin>>f5;

        f1[0]=toupper(f1[0]);
        f2[0]=toupper(f2[0]);
        info.push_back(make_pair(f1,f2));
        info1.push_back(make_pair(f1,f2));
        departure_info.push_back(f3);


        f4=f1+" "+f2+" "+f3+" "+f5+"\n";

        file<<f4;

        file.close();


        cout<<"\n\t\t\tBus Information Added!!!"<<endl;

        cout<<"\n\nDo you want to add more bus information(Y/N) :";
        cin>>flag;
    }
    while(flag=='y'||flag=='Y');



}
void bus_saved()
{

    int c=0;
    fstream file;
    string word,file_name,s1,s2,s3;
    file_name="Bus_Information.txt";
    file.open(file_name.c_str());
    while(file>>word)
    {

        c++;
        if(c==1)
            s1=word;
        if(c==2)
            s2=word;
        if(c==3)
        {
            s1[0]=toupper(s1[0]);
            s2[0]=toupper(s2[0]);
            departure_info.push_back(word);
            info.push_back(make_pair(s1,s2));
            info1.push_back(make_pair(s1,s2));



        }
        if(c==4)
        {

            stringstream ss(word);
            int fair;
            ss>>fair;
            bus_fair.push_back(fair);
            c=0;
        }
    }


}
void bus_info_show()
{



    cout<<"Bus Information: "<<endl<<endl;
    cout.width(15);

    cout<<"From";
    cout.width(12);
    cout<<"To";
    cout.width(19);
    cout<<"Departure_Time"<<endl<<endl;


    for(int i=0; i<info.size(); i++)
    {


        cout.width(3);
        cout<<i+1<<'.';
        cout.width(12);
        cout<<info[i].first;
        cout.width(12);
        cout<<info[i].second;
        cout.width(12);
        cout<<departure_info[i]<<endl;

    }


}
void Book_Tickets()
{

    char flag;
    do
    {
        system("cls");
        string Passenger_name;
        vector<int>voo;
        int pay=1,seat_no=0,bus_no,x;

        cout<<"\n\n\n\n\n\n";

        bus_info_show();
top1:
        cout<<"\n\n\n\t\t\t\tEnter Bus No: ";
        cin>>bus_no;
        cout<<endl;
        if(bus_no>info.size())
        {
            cout<<"\t\t\t\tIncorrect Bus No."<<endl;
            cout<<endl<<"\t\t\t\tEnter correct Bus No."<<endl;
            goto top1;
        }
        cout<<"\t\t\t\tEnter Passenger name: ";
        cin>>Passenger_name;
        cout<<endl;
top2:
        cout<<"\t\t\t\tThe number of seat [1-36]: ";
        cin>>seat_no;
        cout<<endl;


        if(seat_no>36)
        {
            cout<<"\t\t\t\tThe seat limit is 36"<<endl<<endl;
            goto top2;
        }
        cout<<"\t\t\t\tEnter seat no that you want to book: ";
        for(int i=0; i<seat_no; i++)
        {

            cin>>x;
            if(v[bus_no-1][x-1]!="Empty")
            {
                cout<<"\n\t\t\t\tThe seat is already reserved"<<endl;
                i--;
            }
            else
            {

                v[bus_no-1][x-1]=Passenger_name;
                voo.push_back(x);

            }

        }
        system("cls");

        cout<<"\n\n\n";
        cout<<"Bus no: "<<bus_no<<endl;
        cout<<"Departure time: "<<departure_info[bus_no-1]<<endl;
        cout<<"From: "<<info[bus_no-1].first<<" to "<<info[bus_no-1].second<<endl;
        cout<<"Passenger name: "<<Passenger_name<<endl;
        cout<<"Seat fare: "<<bus_fair[bus_no-1]<<endl;
        cout<<"*****************************************************************************************"<<endl<<endl;
        for(int i=0; i<v[bus_no-1].size(); i++)
        {
            cout.fill(' ');
            cout.width(7);
            cout.fill(' ');
            cout<<i+1<<".";
            cout.width(12);
            cout.fill(' ');
            cout<<v[bus_no-1][i];
            if((i+1)%4==0)
                cout<<endl;

        }



        cout<<"\n\n\nThe seat no: ";
        for(int i=0; i<voo.size(); i++)
        {
            cout<<voo[i];
            if(i!=voo.size()-1)
                cout<<',';
        }
        cout<<" is reserved for "<<Passenger_name<<endl;
        pay*=(bus_fair[bus_no-1]*seat_no);
        cout<<"Total Fair: "<<pay<<".00 tk"<<endl;


        cout<<"\n\nDo you want to buy more tickets(Y/N) :";
        cin>>flag;

    }
    while(flag=='y'||flag=='Y');



}
void Cancel_Tickets()
{

    system("cls");
    int no,seat_no;
    cout<<"\n\n\n\t\t\tEnter bus no: ";
    cin>>no;
    cout<<"\n\t\t\tEnter seat no that u want to delete: ";
    cin>>seat_no;
    if(v[no-1][seat_no-1]=="Empty")
    {
        cout<<"\n\n\t\t\tThe seat is already empty"<<endl<<endl;;
    }
    else
    {
        v[no-1][seat_no-1]="Empty";
        cout<<"\n\n\t\t\tThe ticket has been canceled successfully!!"<<endl<<endl;
    }
    cout<<"Bus no:"<<no<<endl;
    for(int i=0; i<v[no].size(); i++)
    {

        cout<<i+1<<".\t"<<v[no-1][i]<<"\t";
        if((i+1)%4==0)
            cout<<endl;

    }
    system("pause");





}
int binary_searc(vector< pair<string,string> >v, string from,string to, int low,int high)
{
    transform(from.begin(),from.end(),from.begin(),::toupper);
    transform(to.begin(),to.end(),to.begin(),::toupper);

    while(low<=high)
    {

        int mid=(low+high)/2;
        string s1,s2;
        s1=v[mid].first;
        transform(s1.begin(),s1.end(),s1.begin(),::toupper);




        if(from==s1)
        {
            int i=mid;
            while(from==s1&&i<info1.size())
            {
                s1=v[i].first;
                s2=v[i].second;
                transform(s1.begin(),s1.end(),s1.begin(),::toupper);
                transform(s2.begin(),s2.end(),s2.begin(),::toupper);


                if(to==s2&&from==s1)
                {
                    return i;
                }
                i++;

            }
            s1=from;
            i=mid;
            while(from==s1&&i>=0)
            {
                s1=v[i].first;
                s2=v[i].second;
                transform(s1.begin(),s1.end(),s1.begin(),::toupper);
                transform(s2.begin(),s2.end(),s2.begin(),::toupper);



                if(to==s2&&from==s1)
                {
                    return i;
                }
                i--;

            }

            return -1;
        }
        else if(from>s1)
            low=mid+1;
        else if(from<s1)
            high=mid-1;


    }

    return -1;


}


void Available_Bus_Routes()
{
    system("cls");
    cout<<"\n\n\n\t\t\t\tAvailable Bus Routes"<<endl<<endl<<endl;

///Bubble sort

    for(int i=0; i<info1.size()-1; i++)
    {

        for(int j=0; j<info1.size()-1-i; j++)
        {

            if(info1[j].first>info1[j+1].first)
            {

                swap(info1[j].first,info1[j+1].first);
                swap(info1[j].second,info1[j+1].second);


            }


        }
    }

    for(int i=0; i<info1.size(); i++)
    {


        cout<<info1[i].first<<" to "<<info1[i].second<<endl<<endl;



    }
    cout<<endl<<endl;

    int flag=0;
    cout<<"\n\n\t\t\t\tEnter 1 to search bus routes: ";
    cin>>flag;
    if(flag==1)
    {
        system("cls");
        cout<<"\n\n\t\t\t\tSearch bus routes that available or not??\n\n";
        int f;
        string from,to;
        cout<<"\t\t\t\tFrom: ";
        cin>>from;
        cout<<"\n\n\t\t\t\tTo: ";
        cin>>to;

        int l=info1.size()-1;
        f=binary_searc(info1,from,to,0,l);



        if(f!=-1)
        {

            cout<<"\n\n\t\t\t\tBus is Available";
            cout<<"\n\n\t\t\t\tFrom: "<<info1[f].first;
            cout<<"\n\n\t\t\t\tTo: "<<info1[f].second<<endl<<endl;

        }
        else
        {
            cout<<"\n\n\t\t\t\tBus is not Available from "<<from<<" to "<<to<<endl<<endl;

        }
    }

    system("pause");

}


void break_t(unsigned int t)
{
    clock_t tym=t+clock();
    while(tym>clock());
}


void Log_In()
{
    while(1)
    {
        int u,p;
        system("cls");
        Intro();

        if(p==1&&u==1)
            cout<<"\n\n\t\t\t\tWrong username and password!! ,Try again"<<endl;
        else if(u==1)
            cout<<"\n\n\t\t\t\tWrong username!! ,Try again"<<endl;
        else if(p==1)
        {
            cout<<"\n\n\t\t\t\tWrong password!! ,Try again"<<endl;
        }
        u=0,p=0;

        string user_name,password,user="",pass="";
        cout<<"\n\n\t\t\t\tUsername:";
        cin>>user_name;
        cout<<"\n\n\t\t\t\tPassword:";
        cin>>password;


        fstream new_file1,new_file2;
        new_file1.open("username.txt",ios::in);
        new_file2.open("password.txt",ios::in);

        char a,b;
        while(!new_file1.fail())
        {
            new_file1>>a;
            if (new_file1.eof())
            {
                break;
            }
            user+=a; ///user=user+a;
        }


        while(!new_file2.fail())
        {
            new_file2>>b;
            if (new_file2.eof())
            {
                break;
            }
            pass+=b; ///pass=pass+b

        }



        if(user==user_name&&pass==password)
        {
            system("cls");
            cout<<"\n\n\n\n\t\t\t\tWelcome to Bus management system";
            for(int i=0; i<=7; i++)
            {
                break_t(125);
                cout<<".";
            }
            break;

        }
        else
        {
            if(user!=user_name)
                u=1;
            if(pass!=password)
                p=1;

        }

    }
}

void Intro()
{
    cout<<endl<<endl<<endl;
    cout<<"\t\t\t\tBUS MANAGEMENT SYSTEM"<<endl;
}
void Save()
{

    fstream User_Name,Password;
    User_Name.open("username.txt",ios::out);
    Password.open("password.txt",ios::out);
    User_Name<<"admin";
    Password<<"admin";
    User_Name.close();
    Password.close();

}



int main()
{
    bus_saved(); ///Store bus information from file
    Intro();    ///Title print
    Save();    ///Read username & password from file
    Log_In(); ///Log in

    while(1)
    {
        system("cls");

        int press;
        Intro();

        cout<<endl<<endl;
        cout<<"\t\t\t\t1. Book Tickets"<<endl;
        cout<<"\t\t\t\t2. Cancel Tickets"<<endl;
        cout<<"\t\t\t\t3. Available Bus Operators"<<endl;
        cout<<"\t\t\t\t4. Install Bus Information"<<endl;
        cout<<"\t\t\t\t5. Exit"<<endl;

        cout<<"\n\t\t\t\tEnter option:---> ";
        cin>>press;

        switch(press)
        {
        case 1:

        {
            Book_Tickets( );

        }
        break;
        case 2:

        {
            Cancel_Tickets();

        }
        break;
        case 3:

        {
            Available_Bus_Routes();
        }
        break;
        case 4:

        {
            Install_Bus_Information();
        }
        break;
        case 5:

        {
            system("cls");
            exit(0);
        }
        break;
        default:
        {
            printf("Wrong Input.. END!!\n");

        }

        }
    }






}



