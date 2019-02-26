#include <string>
#include <iostream>
#include <cmath>
#include "shape.cpp"

using namespace std;

void print_shape_info( shape *input){
	cout<<"name: "<<input->get_name()<<endl;
	cout<<"color: "<<input->get_color()<<endl;
	cout<<"area: "<<input->get_area()<<endl;
};
	
int main(){ 
	shape *j = new shape;
	shape *s;
	s = new Circle;
	shape *d;
	d = new Rectangle;

	print_shape_info(j);
	print_shape_info(s);
	print_shape_info(d);

	return 0;
}
