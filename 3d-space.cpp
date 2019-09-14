//Quinton Negron
//This program takes some boundaries
//and prints out the length of that vector
//using the euclidean formula
#include <iostream>
#include <cmath>
using namespace std;

//We could declare variables normally,
//but classes and dynamic memory were required

//Here we are declaring the variables seperately
class Coord3D{
public:
    double x;
    double y;
    double z;
};

Coord3D * createCoord3D(double x, double y, double z)
{
    Coord3D * set = new Coord3D;
    *set = {x,y,z};
    return set;
}


void deleteCoord3D(Coord3D *p)
{
    delete (p);
}

void move(Coord3D *ppos, Coord3D *pvel, double dt)
{
    ppos -> x = ((ppos -> x) + ((pvel -> x) * dt));
    ppos -> y = ((ppos -> y) + ((pvel -> y) * dt));
    ppos -> z = ((ppos -> z) + ((pvel -> z) * dt));
}

double length(Coord3D *q)
{
    double total;
    //the *p is pulling its values for x,y,z
    //from the class established above
    total = sqrt((pow((*q).x,2) + pow((*q).y, 2) + pow((*q).z,2)));
    return total;
}

Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2){
    if(length(p1) > length(p2))
    {
//        cout << "p1";
        return p1;
    
    }
    else
    {
        return p2;
    }
}
        
//double length(Coord3D *p)
//{
//    double total1;
//    //the *p is pulling its values for x,y,z
//    //from the class established above
//    total = sqrt((pow((*p).x,2) + pow((*p).y, 2) + pow((*p).z,2)));
//    return total1
//}


int main()
{
    double x,y,z;
    cout << "Enter position: ";
    cin >> x >> y >> z;
    Coord3D *ppos = createCoord3D(x,y,z);
    
    cout << "Enter velocity: ";
    cin >> x >> y >> z;
    Coord3D *pvel = createCoord3D(x,y,z);
    
    //cout << "Address of P: " << &pointP << endl;
    //cout << "Address of Q: " << &pointQ << endl << endl;
    
    move(ppos, pvel, 10.0);
    cout << "Coordinates after 10 seconds: " << (*ppos).x << " " << (*ppos).y << " " << (*ppos).z << endl;
    
    deleteCoord3D(ppos);
    deleteCoord3D(pvel);
    
    //Coord3D * ans = fartherFromOrigin(&pointP, &pointQ);
    //cout << "ans = " << ans << endl; // would print 37.4166
}
