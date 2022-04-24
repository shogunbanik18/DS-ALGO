// #include<bits/stdc++.h>
// // #include "Hero.cpp"
// using namespace std;

// class Hero
// {
//   public:
//     int health;
//     char level;
// };

// // // Incase of empty class size of memory = 1 Byte

// int main()
// {
//     Hero h1;
//     cout<<"size : "<<sizeof(h1)<<endl;
//     return 0;
// }

// // Access Modifiers
// #include <bits/stdc++.h>
// using namespace std;

// class Hero
// {
// public:
//     int health;
//     char level;

//     // default constructor
//     Hero()
//     {
//         health = 100;
//         level = 'A';
//     }
// };

// // // Incase of empty class size of memory = 1 Byte

// int main()
// {
//     Hero h1;

//     h1.health = 70;
//     h1.level = 'B';

//     cout << "Health is  : " << h1.health << endl;
//     cout << "Level is  : " << h1.level << endl;

//     return 0;
// }

// // Getters and Setters for private members
// // Accessing the private data members of the class
// #include <bits/stdc++.h>
// using namespace std;

// class Hero
// {
// private:
//     int health;

// public:
//     char level;

//     // default constructor
//     Hero()
//     {
//         health = 100;
//         level = 'A';
//     }

//     int getHealth()
//     {
//         return health;
//     }

//     char getLevel()
//     {
//         return level;
//     }

//     void setHealth(int h, char name)
//     {
//         if (name == 'B')
//         {
//             health = h;
//         }
//     }

//     void setLevel(char l)
//     {
//         level = l;
//     }
// };

// int main()
// {
//     Hero h1;

//     h1.setHealth(70, 'A');
//     h1.level = 'B';

//     cout << "Health is  : " << h1.getHealth() << endl;
//     cout << "Level is  : " << h1.level << endl;

//     cout << "Size  of h1 : " << sizeof(h1) << endl;

//     return 0;
// }

// // Static and Dynamic Memory Allocation
// #include <bits/stdc++.h>
// using namespace std;

// class Hero
// {
// private:
//     int health;

// public:
//     char level;

//     // default constructor
//     Hero()
//     {
//         cout<<"constructor called"<<endl;
//         health = 100;
//         level = 'A';
//     }

//     Hero(int health)
//     {
//         cout<<this<<endl;
//         this->health = health;
//     }

//     Hero(int health,char level)
//     {
//         cout<<this<<endl;
//         this->health = health;
//         this->level = level;
//     }

//     int getHealth()
//     {
//         return health;
//     }

//     char getLevel()
//     {
//         return level;
//     }

//     void setHealth(int h, char name)
//     {
//         if (name == 'B')
//         {
//             health = h;
//         }
//     }

//     void setLevel(char l)
//     {
//         level = l;
//     }

//     void print()
//     {
//         cout<<level<<endl;
//     }
// };

// int main()
// {
//     // object created statically
//     Hero ramesh(7,'B');
//     cout<<"Address of Ramesh is :" << &ramesh <<endl;
//     cout<<ramesh.getHealth()<<endl;

//     ramesh.print();

//     // object created dynamically
//     Hero *h = new Hero;
//     h->print();

//     // // static alloaction
//     // Hero a;
//     // a.setHealth(80,'B');
//     // a.setLevel('B');
//     // cout << "Health of a : " << a.getHealth() << endl;
//     // cout << "Level of a : " << a.level << endl;

//     // // dynamic allocation
//     // Hero *h1 = new Hero;
//     // cout << "Health of h1 : " << (*h1).getHealth() << endl;
//     // cout << "Level of h1  : " << (*h1).level << endl;

//     // h1->setHealth(70,'B');
//     // h1->setLevel('B');
//     // cout << "Health of h1 : " << h1->getHealth() << endl;
//     // cout << "Level of h1  : " << h1->level << endl;

//     // Hero h1;

//     // h1.setHealth(70, 'A');
//     // h1.level = 'B';

//     // cout << "Health is  : " << h1.getHealth() << endl;
//     // cout << "Level is  : " << h1.level << endl;

//     // cout << "Size  of h1 : " << sizeof(h1) << endl;

//     return 0;
// }

// // Copy Constructor
// #include <bits/stdc++.h>
// using namespace std;

// class Hero
// {
// private:
//     int health;

// public:
//     char *name;
//     char level;

//     // default constructor
//     Hero()
//     {
//         cout << "Default constructor called" << endl;
//         health = 100;
//         level = 'A';
//         name = new char[100];
//     }

//     // Parameterised connstructor called
//     Hero(int health, char level)
//     {
//         // cout<<this<<endl;
//         this->health = health;
//         this->level = level;
//     }

//     // // copy constructor
//     Hero(Hero &temp)
//     {
//         // cout << "copy constructor called" << endl;
//         // // statically allocated

//         char *ch = new char[strlen(temp.name) + 1];
//         strcpy(ch, temp.name);
//         this->name = ch;

//         this->health = temp.health;
//         this->level = temp.level;
//     }

//     int getHealth()
//     {
//         return health;
//     }

//     char getLevel()
//     {
//         return level;
//     }

//     void setHealth(int h)
//     {
//         health = h;
//     }

//     void setLevel(char l)
//     {
//         level = l;
//     }

//     void setname(char name[])
//     {
//         strcpy(this->name, name);
//     }

//     void print()
//     {
//         cout << "{ health is  : " << this->health << " ";
//         cout << "level is : " << this->level << " ";
//         cout << "name is : " << this->name << " }" << endl;
//     }
// };

// int main()
// {
//     // Hero suresh(70,'C');
//     // suresh.print();

//     // Hero R(suresh);
//     // R.print();

//     Hero hero1;

//     hero1.setHealth(70);
//     hero1.setLevel('D');
//     char name[7] = "babbar";
//     hero1.setname(name);

//     hero1.print();

//     // user default copy constructor
//     Hero hero2(hero1);
//     hero2.print();

//     hero1.name[0] = 'G';
//     hero1.print();
//     hero2.print();

//     hero1 = hero2;
//     hero1.print();
//     hero2.print();

//     return 0;
// }

// // Destructor
// #include <bits/stdc++.h>
// using namespace std;

// class Hero
// {
// private:
//     int health;

// public:
//     char *name;
//     char level;

//     // default constructor
//     Hero()
//     {
//         cout << "Default constructor called" << endl;
//         health = 100;
//         level = 'A';
//         name = new char[100];
//     }

//     // Parameterised connstructor called
//     Hero(int health, char level)
//     {
//         // cout<<this<<endl;
//         this->health = health;
//         this->level = level;
//     }

//     // // copy constructor
//     Hero(Hero &temp)
//     {
//         // cout << "copy constructor called" << endl;
//         // // statically allocated

//         char *ch = new char[strlen(temp.name) + 1];
//         strcpy(ch, temp.name);
//         this->name = ch;

//         this->health = temp.health;
//         this->level = temp.level;
//     }

//     int getHealth()
//     {
//         return health;
//     }

//     char getLevel()
//     {
//         return level;
//     }

//     void setHealth(int h)
//     {
//         health = h;
//     }

//     void setLevel(char l)
//     {
//         level = l;
//     }

//     void setname(char name[])
//     {
//         strcpy(this->name, name);
//     }

//     void print()
//     {
//         cout << "{ health is  : " << this->health << " ";
//         cout << "level is : " << this->level << " ";
//         cout << "name is : " << this->name << " }" << endl;
//     }

//     ~Hero()
//     {
//         cout << "Destructor Bhai Called" << endl;
//     }
// };

// int main()
// {
//     // static
//     Hero a;

//     // Dynamic
//     Hero *b = new Hero;
//     delete b;
// }

// static keyword
#include <bits/stdc++.h>
using namespace std;

class Hero
{
private:
    int health;

public:
    char *name;
    char level;
    static int timetocomplete;

    // default constructor
    Hero()
    {
        cout << "Default constructor called" << endl;
        health = 100;
        level = 'A';
        name = new char[100];
    }

    // Parameterised connstructor called
    Hero(int health, char level)
    {
        // cout<<this<<endl;
        this->health = health;
        this->level = level;
    }

    // // copy constructor
    Hero(Hero &temp)
    {
        // cout << "copy constructor called" << endl;
        // // statically allocated

        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);
        this->name = ch;

        this->health = temp.health;
        this->level = temp.level;
    }

    int getHealth()
    {
        return health;
    }

    char getLevel()
    {
        return level;
    }

    void setHealth(int h)
    {
        health = h;
    }

    void setLevel(char l)
    {
        level = l;
    }

    void setname(char name[])
    {
        strcpy(this->name, name);
    }

    static int random()
    {
        return timetocomplete;
    }

    void print()
    {
        cout << "{ health is  : " << this->health << " ";
        cout << "level is : " << this->level << " ";
        cout << "name is : " << this->name << " }" << endl;
    }
};

// using scope
int Hero ::timetocomplete = 5;

int main()
{
    // Hero suresh(70,'C');
    // suresh.print();

    // Hero R(suresh);
    // R.print();

    // cout << Hero::timetocomplete << endl;
    cout << Hero::random() << endl;

    // Hero hero1;
    // cout << hero1.timetocomplete << endl;

    // Hero hero2;
    // hero2.timetocomplete = 10;
    // cout << hero1.timetocomplete << endl;
    // cout << hero2.timetocomplete << endl;

    // // hero1.setHealth(70);
    // // hero1.setLevel('D');
    // // char name[7] = "babbar";
    // // hero1.setname(name);

    // // hero1.print();

    // // // user default copy constructor
    // // // Hero hero2(hero1);
    // // hero2.print();

    // // hero1.name[0] = 'G';
    // // hero1.print();
    // // hero2.print();

    // // hero1 = hero2;
    // // hero1.print();
    // // hero2.print();

    return 0;
}