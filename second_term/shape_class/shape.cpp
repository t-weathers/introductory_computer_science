#include <string>
#include <iostream>
#include <cmath>

using namespace std; 

class shape{
	protected:
		string name;
		float area; 
		string color; 
	public:
		shape(){
			name = "shape";
			color = "yellow";
			area = 0.0;
		}
		virtual void calculate_area(){
			
		}
		string get_name(){
			return name;
		}
		void set_name(string input){
			name = input;
		}
		float get_area(){
			return area;
		}
		void set_areas(float input){
			area = input;
		}
		string get_color(){
			return color;
		}
		void set_color(string input){
			color = input;
		}
};
class Circle : public shape{
	protected: 
		float radius;
	public:
		Circle(){
			name = "circle";
			color = "red";
			radius = 3.5;
			calculate_area();
		}
		float get_radius(){
			return radius;
		}
		void set_radius(float input){
			radius = input;
		}
		virtual void calculate_area(){
			area = 3.14 * (radius * radius);
		}
		
};
class Rectangle: public shape{
	protected:
		float length;
		float width;
	public:
		Rectangle(){
			name = "rectangle";
			color = "blue";
			length = 5.0;
			width = 6.0;
			calculate_area();
		}
		float get_length(){
			return length;
		}
		void set_length(float input){
			length = input;
		}
		float get_width(){
			return width;
		}
		void set_width(float input){
			width = input;
		}
		virtual void calculate_area(){
			area = length * width;
		}

};

