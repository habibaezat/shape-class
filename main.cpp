#include <iostream>
#include <cstring>
using namespace std;
class shape {
   protected:
       char color[50];
   public:
       void setcolor(char c[])
        {
           c = color;
         }
        char* getcolor()
        {
           return color;
        }


};
class shape2D : public shape{
  public:
      shape2D(){}
      virtual double area()=0;
      ~shape2D();
};
class shape3D : public shape{

  public:
      shape3D(){}
      virtual double surfacearea()=0;

      virtual double volume()=0;

     ~shape3D (){}
};
class square:public shape2D,public shape{
protected:
    float side;
public:
    square(){}
    square(float s){
        side=s;
    }

    double area(){
          return (side * side);
    }
    ~square();
};
class sphere:public shape3D,public shape{
protected:
    float height;
    float radius;

public:
    sphere(){}
    sphere(float r, float h ){
      radius =r;
      height =h;

    }
    double surfacearea(){
          return 4*3.14*radius*radius*height;
    }
    double volume(){
          return (4*3.14*radius*radius*radius)/3 ;
     }

    ~sphere();
};
class cylinder :public shape3D,public shape{
protected:
    float height;
    float radius;
public:
    cylinder(){}
    cylinder(float r , float h ){
         radius =r;
         height =h;

    }
    double surfacearea(){
          return (radius+height)*3.14*2*radius;
    }
    double volume(){
        return 3.14*height*radius*radius;
    }
    ~cylinder();
};
class circle :public shape2D,public shape{
protected:
    float radius;
public:
    circle(){}
    circle(float r ){
        radius =r;
    }
    double area(){
          return (3.14*radius*radius);
    }
};
int main()
{
shape z;
shape2D* s;
s=new circle(3);
cout<<"circle area =";
cout<<s->area();
s=new square(3);
cout<<"\n square area =";
cout<<s->area();

shape3D* w;
w=new cylinder(3,5);
cout<<"\ncylinder area =";
cout<<w->surfacearea();
w=new sphere(3,5);
cout<<"\n sphere area =";
cout<<w->surfacearea();
w=new cylinder(3,5);
cout<<"\ncylinder volume =";
cout<<w->volume();
w=new sphere(3,5);
cout<<"\n sphere volume =";
cout<<w->volume();

    return 0;
}
