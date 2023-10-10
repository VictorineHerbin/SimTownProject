#include <iostream>
#include <Building.h>

int main( int argc, char** argv ) {
	std::cout << "Welcome to SimTown ! Please enter building IDs.(-99 to end)" << std::endl;
	
	int size = 0;
	std::cin >> size;
	
	Building* street = new Building[size];
	std::cout << "Street address = " << street << std::endl;
	
	for( int i = 0; i < size; ++i ) {
		street[i] = Building( i );
	}
	
	//resize array.
	{Building* bigger_street = new Building [size +1];
	for( int i = 0; i < size; ++i) {
		bigger_street[i] = street[i];
	}
	delete[] street;
	size +=1 ;
	street = bigger_street;
	}	
	
	{
	Building city_hall(1000);
	Building new_city_hall( city_hall ); //Test copy constructor
	street[size-1] = new_city_hall;
	}
	
	for( int i = 0; i < size; ++i ) {
		street[i].print( std::cout );
	}
	
	delete[] street;
	
	return 0; //Normal termination
}