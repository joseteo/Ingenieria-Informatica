#ifdef Diccionario.h
#define Diccionario.h
#include <set>


class Diccionario{

	private:
	
		set<string> datos;

	public:

		Diccionario(): datos(set<string>()){}

		int size() const;

		vector<string> PalabrasLongitud(int longitud);

		bool Esta(string palabra);

		friend istream& operator>>(istream& is, Diccionario& D);

		friend ostream& operator<<(ostream& os, const Diccionario& D);

};

class iterator{

	private:

		set<string>::iterator it;

	public:

		iterator();

		string operator*();

		iterator& operator++();

		bool operator==(const iterator& i);

		bool operator!=(const iterator& i);

		friend class Diccionario;

};

iterator begin();

iterator end();

#endif
