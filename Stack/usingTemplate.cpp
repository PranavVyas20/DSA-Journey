#include<iostream>
using namespace std;
template <typename T, typename V>

class Pair{
    T x;
    V y;
    
    public:
    void setX(T x){
        this->x = x;
    }
    T getX(){
        return x;
    }
    void setY(V y){
        this->y = y;
    }
    V getY(){
        return y;
    }
};

int main (){
// making a 'Pair" class with type of 'Pair' and "int".
// so now T is of type "Pair" 
// and V is of type 'int'
Pair<Pair<int,int>,int> p1;
p1.setY(10);

Pair<int,int> p2;
p2.setX(20);
p2.setY(30);

p1.setX(p2);

cout << p1.getX().getY() << endl;
cout << p1.getY();

}