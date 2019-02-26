#include <cmath>
#include <ctime>
#include <string>
#include <cstdlib>
using namespace std;
#ifndef PROPERTY_H
#define PROPERTY_H

struct Tenant{
	int agreeNum;
	float budget;
};

struct Business{
	float budget;
	int agreeNum;
	int turns;
};
class Property{
	protected:
		float rent;
		float monthly_mortgage;
		int mortgage_duration;//months remaining on mortgage
		float propTax;//percent
		float property_value;
		string location; //NW,SW,SE,NE,MW
	public:
		Property();
	//	~Property();
		void initialize_location();
		float get_value();
		string get_location();
		void modify_value(float percent);
		float get_mortgage();
		int get_mortgage_duration();
		float get_rent()const;
		float get_propTax();
		void set_rent(float newrent);
};
#endif
