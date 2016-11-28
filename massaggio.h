#ifndef _MASSAGE_H
#define _MASSAGE_H
#include <iostream>
#include <cstring>
#include <fstream>
#include "trattamento.h"
#include "bad_data.h"

using namespace BAD_DATA;

namespace SPA{
	
using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::ostream;
using std::ofstream;

class massaggio : public trattamento{
	private:
		bool completo;
		double durata;
		virtual ostream & print(ostream &)const;
		virtual istream & read(istream &)throw(bad_data);
	public:
		massaggio();
		massaggio(const char*, const char*, const double,const bool);
		massaggio(const massaggio &);
		void setCompleto(bool)throw(bad_data);
		void setDurata(const double)throw(bad_data);
		friend ostream & operator<<(ostream & os, const massaggio & m);
		friend istream & operator>>(istream & in, massaggio & m);
		bool getCompleto()const {return completo;}
		double getDurata()const {return durata;}
		massaggio & operator=(const massaggio &) throw(bad_data);
		double calcola_costo()const;
		virtual ~massaggio();
};
	
	
	
	
	
}


#endif //_MASSAGE_H
