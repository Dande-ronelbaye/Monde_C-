#include <iostream>

using namespace std;

//passage de parametre par copie faisable aussi en C
void copie(int a, int b)
{
    cout<< " copie: valeur de a=="<< a << " et valeur de b="<<b<< endl;
    int temp =a;
    a=b;
    b=temp;
    cout<< "copie apres permutation : valeur de a=="<< a << " et valeur de b="<<b <<endl;
}
//passage de parametre par pointeur faisable aussi en C
void pointeur (int*a , int*b)
{
     cout<< "pointeur: valeur de a=="<< *a << " et valeur de b="<<*b<< endl;
    int temp =*a;
    *a=*b;
    *b=temp;
    cout<< "pointeur apres permutation : valeur de a=="<< *a << " et valeur de b="<<*b <<endl;
}

//passage de parametre par reference specifique a C++
void referenc(int &a, int &b)
{

    cout<< " reference : valeur de a=="<< a << " et valeur de b="<<b<< endl;
    int temp =a;
    a=b;
    b=temp;
    cout<< "reference  apres permutation : valeur de a=="<< a << " et valeur de b="<<b <<endl;
}

int & mini(const int &a, const int & b)
{
return const_cast <int&> (a,b?a:b);
}

//the  surcharge of  fonctions
void charge()
{
    cout<<" charge with zero parameter "<< endl;
}
void charge(int a)
{
    cout<< " charge with an integer parameter  "<< a<< endl;
}
void charge (int *pt)
{
    cout<< "charge with an pointer parameter  "<<endl;
}
void charge (const char*s, int a)
{
    cout<<" charge with two parameter,character and integer "<<endl;
}

// surcharge operator
struct Paire {int f; int s;};

ostream & operator<<( ostream & os , Paire p)
{
    os <<p.f << " et "<< p.s<<endl;
    return os;
}


int main()
{
    // test fonction copie
    int frist=33;
    int second=44;
    copie(frist,second);

    //test fonction pointeur
    int fristp=33;
    int secondp=44;
    pointeur (&fristp,&secondp);

    // test fonction reference
    int fristr=33;
    int secondr=44;
    referenc(fristr,secondr);

    int a=55;
    int & alias =a;
    alias=66; // the value of a  changed by 66

    // test of charges the fonction
    cout<< "the surcharge of methodes" << endl;
    charge();
    charge(3);
    charge(nullptr); //or int pt; charge(& a);
    charge("maya",2);

    // surcharge operator
    cout << "surcharge operator << "<< endl;
    Paire p;
    p.f=52;
    p.s=68;
    cout <<p<< endl;

    return 0;
}
