#ifndef DEF_SIM_TOWN_BUILDING
#define DEF_SIM_TOWN_BUILDING
#include <string>
//#include <Storey.h>

//forward declaration
class Storey;

class Building
{
	public:
	
		//Constructeur par défaut
		Building();
		
		//Constructeur
		Building( int id, int nb_floors=1 );
		
		//Constructeur par copie
		Building( const Building& rhs );
		
		//Destructeur
		~Building();
		
		//Operator =
		Building& operator=( const Building& rhs );
		
		//Method
		void print( std::ostream& out ) const;
		Storey* create_and_add_storey();
		
	private:
		int id_;
		Storey* storeys_;
		int nb_storeys_;
		
		void clone_storeys( Storey* to, Storey* from );
};


#endif // DEF_BUILDING
