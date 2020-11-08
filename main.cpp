#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <vector>
#include <queue>
#include <time.h>
#include <list>
#include <algorithm>
#include <iomanip>
#include <ctype.h>

#define MAX 1000000001

typedef long long ll;
using namespace std;

class Location
{
private:
    const char* country = "Romania";
    char* city;
    char* building;
    char bloc;
    char floor;
    int room;

public:
    static int num_locations;

    Location(char* city, char* building, char bloc, char floor, int room)
    {
        num_locations++;
        this -> city;
        this -> building = building;
        this -> bloc = bloc;
        this -> floor = floor;
        this -> room = room;
    }

    Location()
    {
        num_locations++;
    }

    ///setters Location
    void setCity(char* city)
    {
        this -> city = city;
    }
    void setBuilding(char* building)
    {
        this -> building = building;
    }
    void setBloc(char bloc)
    {
        this -> bloc = bloc;
    }
    void setFloor(char floor)
    {
        this -> floor = floor;
    }
    void setRoom(int room)
    {
        this -> room = room;
    }

    ///getters Location
    char* getCity()
    {
        return city;
    }
    char* getBuilding()
    {
        return building;
    }
    char getBloc()
    {
        return bloc;
    }
    char getFloor()
    {
        return floor;
    }
    char getRoom()
    {
        return room;
    }
    ~Location()
    {
        num_locations--;
    }
};

int Location::num_locations = 0;

class Personnel
{
private:
    static int num_personnel;
    char *name;
    char *surname;
    Location location;

public:
    Personnel(char* name, char* surname)
    {
        num_personnel++;
        this->name= name;
        this->surname = surname;
    }

    Personnel()
    {
        num_personnel++;
    }

    ///setters Location
    void setName(char* name)
    {
        this -> name = name;
    }
    void setSurname(char* surname)
    {
        this -> surname= surname;
    }
    void setLocation(Location location)
    {
        this -> location = location;
    }

    ///getters Location
    char* getName()
    {
        return name;
    }
    char* getSurname()
    {
        return surname;
    }
    Location getLocation()
    {
        return location;
    }

    ~Personnel()
    {
        num_personnel--;
    }

};

int Personnel::num_personnel = 0;

class Object
{
    friend class Location;
    friend class Personnel;

private:
    const int ID;
    char* objType;
    int dimensions[3];
    float buying_price;
    Personnel added;
    Personnel owner;
    bool present;
    string color;
    string material;

public:
    static int num_object;

    Object():ID(00000)
    {
        this -> objType = new char[16];
        this -> dimensions;
    }

    Object(int id, char* objType, int dimensions[3]):ID(id)
    {
        this -> objType = objType;
        for(int i =0; i <3; i++)
        {
            this -> dimensions[i] = dimensions[i];
        }
    }

    ///setters Objects
    void setObjType(char* ObjType)
    {
        this->objType=ObjType;
    }
    void setColor() ///sets the color of the object from fourteen choices
    {
        string colors[] = {"black", "white", "red", "blue", "green", "brown", "pink", "purple", "gray", "orange", "yellow", "cyan", "metallic", "transparent"};
        int len_colors = sizeof(colors)/sizeof(colors[0]);
        for(int i = 0; i <len_colors;i++)
        {
            cout<<i + 1<<" - "<< colors[i]<<endl;
        }
        int colour;
        cout<< "Please enter the number of the color of your object: ";
        cin>>colour;
        while(colour < 0 || colour > len_colors)
        {
            cout<< "You entered an incompatible color..."<<endl<<"Please enter the number of the color of your object: ";
            cin>>colour;
        }
        color= colors[colour - 1];
        this->color=color;
    }
    void setMaterial()
    {
        string materials[] = {"wood", "plastic", "metal", "ceramic", "concrete"};
        int len_materials = sizeof(materials)/sizeof(materials[0]);
        for(int i = 0; i < len_materials ; i++)
        {
            cout<<i + 1<<" - "<< materials[i]<<endl;
        }
        int material;
        cout<< "Please enter the number of the material of your object: ";
        cin>>material;
        while(material < 0 || material > len_materials)
        {
            cout<< "You entered an incompatible material..."<<endl<<"Please enter the number of the material of your object: ";
            cin>>material;
        }
        this->material= materials[material - 1];
    }
    void setBuying_Price(float buying_price) ///sets the buying price of the object
    {
        this->buying_price=buying_price;
    }
    void setAdded(Personnel added) ///sets the person who added the object to the inventory
    {
        this->added=added;
    }
    void setOwner(Personnel owner) ///sets the current owner of the object
    {
        this->owner = owner;
    }
    void setPresent(bool present) ///sets if the object is present in the inventory or not
    {
        this->present=present;
    }

    ///getters Objects
    char* getObjType()
    {
        return objType;
    }
    string getColor()
    {
        return color;
    }
    string getMaterial()
    {
        return material;
    }
    float getBuying_Price()
    {
        return buying_price;
    }
    Personnel getAdded()
    {
        return added;
    }
    Personnel getOwner()
    {
        return owner;
    }
    bool getPresent()
    {
        return present;
    }
    ~Object()
    {
        num_object--;
    }
};

int Object::num_object = 0;

class User
{
private:
    static int num_users;
    char username[16];
    char password[64];
    int age;
    bool authorization;
    char *userName = username;
    char *passWord = password;

public:
    User(char *userName, char *passWord)
    {
        num_users++;
        this->userName = userName;
        this->passWord = passWord;
    }

    User()
    {
        num_users++;
    }

    ///setters Users
    void setUserName(char *userName)
    {
        cout<<"Your username has been changed with success!"<<endl;
        this->userName = userName;
    }
    void setPassWord(char *passWord)
    {
        cout<<"Your password has been changed with success!"<<endl;
        this->passWord=passWord;
    }
    void setAge(int age)
    {
        this->age=age;
    }
    void setAuthorization(bool authorization)
    {
        this->authorization = authorization;
    }

    ///getters Users
    char* getUserName()
    {
        return userName;
    }
    char* getPassWord()
    {
        return passWord;
    }
    int getAge()
    {
        return age;
    }
    bool getAuthorization()
    {
        return authorization;
    }
    ~User()
    {
        num_users--;
    }
};

int User::num_users = 0;

int main()
{
    User user1("rabia_erturk", "123456asd");

    string username0 = "rabia_erturk";
    string password0 = "123456asd";

    int log_in;
    cout<<"How would you like to log in?"<<endl;
    cout<<"1 - as a guest"<<endl;
    cout<<"2 - i have an account"<<endl;
    cin>>log_in;

    switch(log_in)
    {
    case 1:
    {
        string guest_name;
        cout<<"Please enter your name: "<<endl;
        cin>>guest_name;
        cout<<endl<<"Welcome "<<guest_name<<"!"<<endl<<endl;

        int access;
        cout<<"choose 1 to access inventory"<<endl;
        cout<<"choose 2 to access personnel"<<endl;
        cout<<"choose 3 to access locations"<<endl;
        cin>>access;
        cout<<endl;

        switch(access)
        {
        case 1:
        {
            cout<<"you successfully accessed inventory!"<<endl<<endl;
            int operation;
            cout<<"please enter the operation you want to do now: "<<endl;
            cout<<"choose 1 to view an object from the inventory!"<<endl;
            cout<<"choose 2 to add a new object to the inventory!"<<endl;
            cout<<"choose 3 to remove an object from the inventory!"<<endl;
            cin>>operation;

            cout<<"---------------------------------------------------------";

            switch(operation)
            {
            case 1:
                cout<<"this operation is not available yet..."<<endl;
                break;

            case 2:
                cout<<"you are not authorized to use this operation..."<<endl;
                break;

            case 3:
                cout<<"you are not authorized to use this operation..."<<endl;
                break;

            default:
                cout<<"you entered an incompatible operation..."<<endl;
                break;
            }
            break;
        }

        case 2:
        {
            string personnel0;
            cout<<"you accessed personnel!"<<endl;
            cout<<"please type the id of the personnel you want to view: "<<endl;
            cin>>personnel0;
            cout<<"the personnel info isn't available at the moment..."<<endl;
            break;
        }

        case 3:
        {

            cout<<"you accessed locations!"<<endl<<endl;
            int operation0;
            cout<<"please enter the operation you want to do now: "<<endl;
            cout<<"choose 1 to view a location!"<<endl;
            cout<<"choose 2 to add a new location!"<<endl;
            cout<<"choose 3 to remove a location!"<<endl;
            cin>>operation0;

            cout<<"---------------------------------------------------------";

            switch(operation0)
            {
            case 1:
                cout<<"this operation is not available yet..."<<endl;
                break;

            case 2:
                cout<<"you are not authorized to use this operation..."<<endl;
                break;

            case 3:
                cout<<"you are not authorized to use this operation..."<<endl;
                break;

            default:
                cout<<"you entered an incompatible operation..."<<endl;
                break;
            }
            break;
        }

        default:
            cout<<"you entered an incompatible choice..."<<endl;
            break;
        }
        break;
    }

    case 2:
    {
        cout<<"please enter your username: "<<endl;
        cin>>username0;
        cout<<"please enter your password: "<<endl;
        cin>>password0;

        while(user1.getUserName()!=username0 || user1.getPassWord()!=password0)
        {
            cout<<"seems like something went wrong"<<endl<<"please check your information..."<<endl;
            cout<<"please enter your username: "<<endl;
            cin>>username0;
            cout<<"please enter your password: "<<endl;
            cin>>password0;
        }

        cout<<"---------------------------------------------------------";

        if(user1.getUserName()==username0 && user1.getPassWord()==password0)
        {
            cout<<"you logged in as "<<user1.getUserName()<<"!"<<endl;
        }

        cout<<"---------------------------------------------------------";

        int access0;
        cout<<"choose 1 to access inventory"<<endl;
        cout<<"choose 2 to access personnel"<<endl;
        cout<<"choose 3 to access locations"<<endl;
        cin>>access0;

        cout<<"---------------------------------------------------------";

        switch(access0)
        {
        case 1:
            cout<<"you accessed inventory!"<<endl<<endl;
            int operation0_0;
            cout<<"please enter the operation you want to do now:"<<endl;
            cout<<"choose 1 to view an object from the inventory!"<<endl;
            cout<<"choose 2 to add a new object to the inventory!"<<endl;
            cout<<"choose 3 to remove an object from the inventory!"<<endl;
            cin>>operation0_0;

            cout<<"---------------------------------------------------------";

            switch(operation0_0)
            {
            case 1:
                cout<<"this operation is not available yet..."<<endl;
                break;

            case 2:
                cout<<"this operation is not available yet..."<<endl;
                break;

            case 3:
                cout<<"this operation is not available yet..."<<endl;
                break;

            default:
                cout<<"you entered an incompatible operation..."<<endl;
                break;
            }
            break;

        case 2:
        {

            cout<<"you accessed personnel!"<<endl;
            string personnel01;
            cout<<"please type the id of the personnel you want to view!"<<endl;
            cin>> personnel01;
            cout<<"the personnel info isn't available at the moment...";
            break;
        }

        case 3:
        {
            cout<<"you accessed locations!"<<endl<<endl;
            int operation0_1;
            cout<<"please enter the operation you want to do now:"<<endl;
            cout<<"choose 1 to view a location!"<<endl;
            cout<<"choose 2 to add a new location!"<<endl;
            cout<<"choose 3 to remove a location!"<<endl;
            cin>>operation0_1;
            cout<<"---------------------------------------------------------";

            switch(operation0_1)
            {
            case 1:
                cout<<"this operation is not available yet..."<<endl;
                break;

            case 2:
                cout<<"this operation is not available yet..."<<endl;
                break;

            case 3:
                cout<<"this operation is not available yet..."<<endl;
                break;

            default:
                cout<<"you entered an incompatible operation..."<<endl;
                break;
            }
            break;
        }

        default:
        {
            cout<<"you entered an incompatible choice..."<<endl;
            break;
        }
        }
    }
    }

    return 0;
}
