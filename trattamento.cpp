#include "trattamento.h"

namespace SPA{
	
	using std::cout;
	using std::cin;
	using std::endl;
	using std::istream;
	using std::ostream;
	using std::ofstream;
		
	trattamento::trattamento(){
		this->descrizione=new char[1];
		strcpy(this->descrizione,"");
		this->codice=new char[1];
		strcpy(this->codice,"");
	}
	
	trattamento::trattamento(const char * desc, const char * cod){
		this->descrizione=new char [strlen(desc)+1];
		this->setD(desc);
		this->codice=new char[strlen(cod)+1];
		this->setC(cod);
	}
	
	char* trattamento::getD()const{
		return this->descrizione;
	}
	char* trattamento::getC()const{
		return this->codice;
	}
	void trattamento::setD(const char* desc){
		if(this->descrizione) delete [] this->descrizione;
		this->descrizione = new char[strlen(desc)+1];
		strcpy(this->descrizione,desc);
	}
	void trattamento::setC(const char* cod){
		if(this->codice) delete [] this->codice;
		this->codice = new char[strlen(cod)+1];
		strcpy(this->codice,cod);
	}
	
	trattamento::~trattamento(){
		delete[] this->codice;
		delete[] this->descrizione;
	}
	
	ostream & trattamento::print(ostream & os)const{
		os << descrizione << " " << codice << " ";
		return os;
	}
	
	trattamento::trattamento(const trattamento & t){
		this->descrizione=new char[strlen(t.descrizione)+1];
		strcpy(this->descrizione,t.descrizione);
		this->codice=new char[strlen(t.codice)+1];
		strcpy(this->codice,t.codice);
		
	}
	
	//input da tastiera
	istream & trattamento::read(istream & in){
		char buffer [400];
		in.getline(buffer,400); //input codice da tastiera 
		this->setC(buffer);
		in.getline(buffer,400); //input descrizione da tastiera
		this->setD(buffer);
		return in;
	}
	
	void trattamento::stampafile(const char * nomefile)const {
		ofstream out;
		out.open(nomefile);
		if(out.fail()){
			exit (10)
;		}
		out << codice << "	" << descrizione << "	";
		out.close();
	}
	
}
