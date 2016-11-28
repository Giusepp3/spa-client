#include "massaggio.h"
#include "trattamento.h"

namespace SPA{
	
	massaggio::massaggio() : trattamento(){
		durata=0;
		completo=false; //decido di inizializzare il completo a false (massaggio parziale) per essere coerente con la durata che viene inizializzata a 0
		
	}
	
	massaggio::massaggio(const char* desc, const char * cod,const double d, const bool c) : trattamento(desc,cod){
		durata=d;
		completo=c;
		
	}
	
	
	ostream & massaggio::print(ostream & os)const{
		trattamento::print(os);
		os<<" "<<durata << " ";
		if (completo) os << "completo";
		else os << "parziale";
		return os;
	}
	
	ostream & operator<<(ostream & os, const massaggio & m){
		m.print(os);
		return os;
	}
	
	void massaggio::setCompleto(bool b ) throw(bad_data){
		if(b&&durata>=40 || durata==0) completo=b;
		else if(!b&&durata<=40 || durata==0) completo=b;
		else throw bad_data("errore dati inseriti non corretti","funzione setCompleto");
	}
	
	void massaggio::setDurata(const double d) throw(bad_data){
		if(d== 25 || d == 40 || d == 50 || d == 80){
			if(completo){
				if (d>=40) durata=d;
				else throw bad_data("errore il massaggio completo deve durare almeno 40 minuti","funzione setDurata");
			}
			else if(!completo){
				if(d<=40) durata=d;
				else throw bad_data("il massggio parziale non puo durare piu di 40 minuti","funzione setData");
			}
		} else throw bad_data("errore nella durata del massaggio","funzione setDurata");
		
		
	}
	
	massaggio::massaggio(const massaggio & m): trattamento(m){
		durata=m.durata;
		completo=m.completo;
		
	}
	
	massaggio & massaggio::operator=(const massaggio & m) throw (bad_data){
		if(this!= &m){
			this->setC(m.getC());
			this->setD(m.getD());
			try{
			this->setCompleto(m.completo);
			} catch(bad_data b){
				cout << b << endl;
			}
			try{
			this->setDurata(m.durata);
			}catch(bad_data b){
				cout << b << endl;
			}
		}
		return *this;
	}
	
	istream & massaggio::read(istream & in)throw (bad_data){
		trattamento::read(in);
		char comp; //completo
		double dur; //durata
		cout << "Inserire 1 per il massaggio completo e 0 per il massaggio parziale: 	";
		in >> comp;
		try{
		if(comp=='1')
		this->setCompleto(true);
		else if(comp=='0') this->setCompleto(false);
		else throw bad_data("Errore inserimento dati!:	", "Funzione read()!");
		} catch(bad_data & d){
			cout << "Rilevato Errore!!:	" << d;
		}
		in >> dur; 
		try{
			this->setDurata(dur);
		}catch(bad_data & d){
			cout << "Rilevato Errore!! :	"<< d;
		}
		return in;
	}
	
	istream & operator>>(istream & in, massaggio & m){
		m.read(in);
		return in;
	}
	
	massaggio::~massaggio(){
		
	}
	
	double massaggio::calcola_costo()const{
		double costo=0;
		if(completo){
			for(int i=0;i<durata;i++){
				costo=costo+1;
			}
		}
		else if(!completo){
			for(int i=0;i<durata;i++){
				costo=costo+0.50;
			}
		}
		return costo;
	}
}
