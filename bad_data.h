#ifndef _BAD_DATA_H
#define _BAD_DATA_H
#include <iostream>
#include <string>
#include <cstring>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::ostream;

namespace BAD_DATA{
	
	class bad_data{
		private:
			string message;
			string funzione;
		public:
			bad_data(const char * m="errore generico", const char * f="non disponibile") : message (m), funzione(f) {}
			friend ostream & operator<<(ostream & os, bad_data b){os << b.message << " " << b.funzione << endl; return os;}
			
	};
	
	
	
}

#endif //_BAD_DATA_H
