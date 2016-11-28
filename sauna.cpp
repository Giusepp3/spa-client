#include "sauna.h"

namespace SPA{
	
	sauna::sauna() : trattamento(){
		t_max=0;
		g_umidita=0;
	}
	
	sauna::sauna(const char* d, const char* c, const double temp, const double um) : trattamento(d,c){
		this->t_max=temp;
		this->g_umidita=um;
	
	}
	
	void sauna::setT(const double temp){
		this->t_max=temp;
	}
	
	void sauna::setU(const double um){
		this->g_umidita=um;
	}
	
	ostream & sauna::print(ostream & os)const{
		trattamento::print(os);
		os << t_max << " " << g_umidita << " ";
		return os;
	}
	
	ostream & operator<<(ostream & os, const sauna & s){
		s.print(os);
		return os;
	}
	
	sauna::sauna(const sauna & s): trattamento(s){
		g_umidita=s.g_umidita;
		t_max=s.t_max;
	}
	
	sauna & sauna::operator=(const sauna & s){
		if(this!=&s){
			this->setC(s.getC());
			this->setD(s.getD());
			this->g_umidita=s.g_umidita;
			this->t_max=s.t_max;
		}
		return *this;
	}
	
	istream & sauna::read(istream & in){
		trattamento::read(in);
		double buffer;
		in >> buffer; //leggo umidita
		this->setU(buffer);
		in >> buffer;
		this->setT(buffer); //leggo temperatura massima
		return in;
	}
	
	istream & operator>>(istream & in, sauna & s){
		s.read(in);
		return in;
	}
	
	sauna::~sauna(){
		
	}
	
	double sauna::calcola_costo()const{
		double costo=0;
		if(t_max<=45 && g_umidita<=30){
			costo=18;
		}
		else if(t_max<=110 && g_umidita<=15){
			costo=24;
		}
	}
}
