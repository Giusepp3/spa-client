#ifndef _SAUNA_H
#define _SAUNA_H
#include <iostream>
#include <cstring>
#include <fstream>
#include "trattamento.h"

namespace SPA{
	
	using std::cout;
	using std::cin;
	using std::endl;
	using std::istream;
	using std::ostream;
	using std::ofstream;
	
	class sauna : public trattamento {
		private:
			double t_max;
			double g_umidita;
			virtual ostream & print(ostream &)const;
			virtual istream & read(istream &);
		public:
			sauna();
			sauna(const char*, const char*, double, double);
			sauna(const sauna &);
			void setT(const double);
			void setU(const double);
			double getT()const {return t_max;}
			double getU()const {return g_umidita;}
			friend ostream & operator<<(ostream & os, const sauna &);
			friend istream & operator>>(istream & in, sauna & s);
			sauna & operator=(const sauna &);
			double calcola_costo()const;
			virtual ~sauna();
			
	};
	
	
	
	
	
	
	
	
}


#endif //_SAUNA_H
