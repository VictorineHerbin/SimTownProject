#include <iostream>
#include <Building.h>
#include <Storey.h>

using namespace std;

//Constructeur par défaut
Building::Building() : id_( -1 ), storeys_( nullptr ), nb_storeys_(0) {
	std::cout << "Building::Building() at " << this << std::endl;
}
	
//Constructeur
Building::Building( int id, int nb_floors ) : id_( id ), storeys_( nullptr ), nb_storeys_( nb_floors ) {
	storeys_ = new Storey[nb_storeys_];
	std::cout << "Building::Building(" << id << ") at " << this << std::endl;
}

//Constructeur par copie
Building::Building( const Building& rhs ) : id_( rhs.id_ ), storeys_( nullptr ), nb_storeys_( rhs.nb_storeys_ ) {
	std::cout << "Building::Building( rhs = " << &rhs << ", id = " << rhs.id_ << " at this = " << this << std::endl;
	//Storeys* ...
	storeys_ = new Storey[ nb_storeys_ ];
	for(int i = 0; i < nb_storeys_; ++i) {
		storeys_[i] = rhs.storeys_[i];
	}
	//delete[] rhs.storeys_; non parce qu'il ne faut pas détruire la copie dans ce cas-là
}
	
//Destructeur
Building::~Building() {
	std::cout << "Building::~Building " << id_ << std::endl;
}

//Operator =
Building& Building::operator=( const Building& rhs ) {
	if( &rhs != this ) {
		if( nb_storeys_ != rhs.nb_storeys_ ) {
			delete[] storeys_;
			nb_storeys_ = rhs.nb_storeys_;
			storeys_ = new Storey[ nb_storeys_ ];
		}
		id_ = rhs.id_;
		for( int i =0; i < nb_storeys_; ++i ) {
			storeys_[i] = rhs.storeys_[i];
		}
	}
	std::cout << "Building(" << id_ << ") copied at " << this << std::endl;
	return *this;
}

//Method print()
void Building::print( std::ostream& out) const {
	out << "Building " << id_ << " at " << this << std::endl;
}

//Method add_storey()
Storey* Building::create_and_add_storey() {
	Storey* new_storeys = new Storey[nb_storeys_+1];
	clone_storeys( new_storeys , storeys_ );
	delete[] storeys_;
	storeys_ = new_storeys;
	nb_storeys_++;
	return &storeys_[nb_storeys_-1];
	//return &storeys_;
}
	
//Method clone_storeys()
void Building::clone_storeys( Storey* to, Storey* from ) {
	//on pourra préciser plus tard le nb_storeys_ nombre exact
	for( int i = 0; i < nb_storeys_; ++i) {
		to[i] = from[i];
	}
}