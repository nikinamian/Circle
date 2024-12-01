//
//  main.cpp
//  Circle
//
//  Created by Niki Namian on 12/1/24.
//

#include <iostream>

using namespace std;

class Circle{
private:
    int radius;
public:
    //Constructor overloading
    Circle(int radius);
    
    //Member function area, it output the area of a circle
    double area();
    
    //Getter and setter
    int getRadius () const;
    void setRadius(int r);
    
    //Operator overloading
    Circle operator + (const Circle& c);
    Circle operator - (const Circle& c);
    
    //Friend function and operator overloading
    friend ostream& operator << (ostream& out,const Circle& c);
};
//Constructor definition
Circle::Circle(int radius){
    this->radius=radius;
}
//Member function
int Circle::getRadius()const{
    return this->radius;
}

void Circle::setRadius(int r){
    this->radius=r;
}
double Circle::area(){
    return 3.14*(this->radius*this->radius);
}
//operator overloading
Circle Circle::operator + (const Circle&c){
    int newRadius = this -> getRadius()+c.getRadius();
    Circle newCircle(newRadius);
    return newCircle;
}
Circle Circle::operator - (const Circle&c){
    int newRadius = this->getRadius()-c.getRadius();
    Circle newCircle(newRadius);
    return newCircle;
}

//Friend function, operator overloading
ostream & operator <<(ostream&out,Circle&c){
    out<<"Radius:"<<c.getRadius()<<" Area:"<<c.area()<<"\n";
    return out;
}
int main()
{
    Circle c1(15);
    cout<<"C1 is "<<c1;
    
    Circle c2(10);
    cout<<"C2 is "<<c2;
    
    Circle sub=c1-c2;
    cout<<"c1-c2 is "<<sub;
    
    Circle add=c1+c2;
    cout<<"c1+c2 is "<<add;
    return 0;
}
