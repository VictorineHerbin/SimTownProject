#include <iostream>

class Building {
	public:
		Building() : id_( -1 ) {
			std::cout << "Building::Building() at " << this << std::endl;
		}
		Building( int id );
		~Building();
		Building& operator=( const Building& rhs ) {
			if( &rhs != this ) {
				id_ = rhs.id_;
			}
			std::cout << "Building(" << id_ << ") copied at " << this << std::endl;
			return *this;
		}
		void print( std::ostream& out) const {
			out << "Building " << id_ << " at " << this << std::endl;
		}
	private:
		int id_;
};

Building::Building( int id ) : id_( id ) {
	std::cout << "Building::Building(" << id << ") at " << this << std::endl;
}
Building::~Building() { std::cout << "~Building " << id_ << std::endl;
}


int main( int argc, char** argv ) {
	std::cout << "Welcome to SimTown ! Please enter building IDs.(-99 to end)" << std::endl;
	int id = -99;
	Building* street[10];
	for( int i = 0; i < 10; ++i ) {
		street[i] = nullptr;
	}
	
	std::cin >> id;
	int counter = 0;
	while( id != -99 && counter < 10 ) {
		//Building current_house(id);
		//street[counter] = current_house;
		street[counter] = new Building( id );
		//std::cout << " Size = " << sizeof(current_house) << std::endl;
		street[counter]->print( std::cout );
		//current_house.print( std::cout );
		std::cin >> id;
		counter++;
	}
	for( int i = 0; i < 10; ++i ) {
		if( street[i] != nullptr) {
			street[i]->print( std::cout );
		}
	}
	for( int i = 0; i < 10; ++i ) {
		delete street[i];
	}
	
	return 0; //Normal termination
}
	