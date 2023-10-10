#include <iostream>
#include <Storey.h>

using namespace std;

//Constructeur par défaut
	
//Constructeur
Storey::Storey() : source_(serial_number_), uid_( serial_number_ ) {
	++serial_number_;
	std::cout << "Storey:: storey(): id = " << uid_ << " at " << this << std::endl;
}

//Constructeur par copie
Storey::Storey( const Storey& rhs ) : source_ ( rhs.source_), uid_( serial_number_++ ) {
	std::cout << "Storey::Storey( rhs.uid_ = " << rhs.uid_ << "), uid_ = " << uid_ << " at " << this << std::endl;
}

//Destructeur
Storey::~Storey(){
	std::cout << "Storey::~Storey( rhs = id = " << uid_ << ")" << std::endl;
}

//Operator =
Storey& Storey::operator=( const Storey& rhs) {
	if( this != &rhs ) {
		std::cout << "Storey::Storey operator = (rhs = id = " << uid_ << " at " << this << std::endl;
		source_ = rhs.source_;
		uid_ = serial_number_++;
	}
	return *this;
}

//Method
int Storey::serial_number_ = 1;
std::ostream& operator<<( std::ostream& out, const Storey& rhs) {
	out << " --Storey " << &rhs << ": id= " << rhs.uid_ << ", NFT= " << rhs.source_ << "\n";
	return out;
}
	
