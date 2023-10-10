#ifndef DEF_SIM_TOWN_STOREY
#define DEF_SIM_TOWN_STOREY
#include <string>

class Storey
{
	public:
	
		//Constructeur par défaut
		
		//Constructeur
		Storey();
		
		//Constructeur par copie
		Storey( const Storey& rhs );		
		
		//Destructeur
		~Storey();
		
		//Operator =
		Storey& operator=( const Storey& rhs );
		
		//Method
		friend std::ostream& operator<<( std::ostream& out, const Storey& rhs ); 
		// not a member function, but a friend that can access its private items.
		
	private:
		int source_; // "comme un nft" - Victor
		int uid_; //unique identifier.
		static int  serial_number_;
};

#endif // DEF_STOREY
