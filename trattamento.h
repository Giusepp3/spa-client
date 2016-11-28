#ifndef _TRATT_H
#define _TRATT_H

#include <iostream>
#include <cstring>
#include <fstream>
#include "bad_data.h"


namespace SPA{
	
	using std::cout;
	using std::cin;
	using std::endl;
	using std::istream;
	using std::ostream;
	using std::ofstream;
	
	class trattamento{
		private:
			char* descrizione;
			char* codice;
		protected:
			char* getD()const;
			char* getC()const;
			void setD(const char*);
			void setC(const char*);
			virtual ostream & print(ostream &)const;
			virtual istream & read(istream &);
		public:
			trattamento();
			trattamento(const char* desc,const char* cod);
			trattamento(const trattamento &);
			virtual ~trattamento();
			virtual void stampafile(const char*)const;
	};
	
	
	
}

#endif //_TRATT_H
