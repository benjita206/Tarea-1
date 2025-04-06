#include <iostream>
#include <string>
#include<exception>
#include <vector>

using namespace std;

// Primera Clase: Pregunta
class Pregunta{
private:
 string enunciado;
  int nivelTaxonomico;

public:
  Pregunta(string enunciado, int nivelTaxonomico);
  
  ~Pregunta();
  string getEnunciado();
  int getNivelTaxonomico();
  void setEnunciado(string enunciado);
  void setNivelTaxonomico(int nivelTaxonomico);
  void mostrarPreguntas();
  void mostrarNivelTaxonomico();
};

// Contructor de Pregunta
Pregunta::Pregunta(string enunciado, int nivelTaxonomico){
  this->enunciado = enunciado;
  this->nivelTaxonomico = nivelTaxonomico;
}

// Destructor de Pregunta con su mensaje
Pregunta::~Pregunta(){
  cout << "Se ha eliminado la Pregunta" << endl;
  
}

string Pregunta::getEnunciado(){
  return this->enunciado;
}

int Pregunta::getNivelTaxonomico(){
  return this->nivelTaxonomico;
}


void Pregunta::setEnunciado(string enunciado){
  this->enunciado=enunciado;
 cout< "---- Niveles Taxonomicos ----" << endl;
  cout << "1. Recordar" << endl;
  cout << "2. Entender" << endl;
  cout << "3. Aplicar" << endl;
  cout << "4. Analizar" << endl;
  cout << "5. Evaluar" << endl;
  cout << "6. Crear" << endl;
  cout << "Ingrese el nivel Taxonomico "



// Metodos de Pregunta
void Pregunta::mostrarPreguntas(){
  
}

void Pregunta::mostrarNivelTaxonomico(){
  cout<<"el nivel taxonomico es "<<this->nivelTaxonomico<<endl;
}

//A

class VF : public Pregunta{
private:
  bool VyF;
  string justificacion;
  bool respuestaCorrecta;

public:
  VF(bool VyF, string justificacion, bool respuestaCorrecta, string enunciado, int nivelTaxonomico);
  bool getVyF();
  string getJustificacion();
  bool getRespuestaCorrecta();
  void setVyF();
  void setJustificacion();
  void setRespuestaCorrecta();
  void test();
};

VF::VF(bool VyF, string justificacion, bool respuestaCorrecta):Pregunta(enunciado, nivelTaxonomico){

this->VyF=VyF;
this->=VyF;
}//Getters y Setters



void test{
  cout << "Ingrese el enunciado de la pregunta:" << endl;
  cin >> this->enunciado;

  cout << "Ingrese la respuesta correcta: " << endl;
  cin >> this->respuestaCorrectaVF;

  if(respuestaCorrectaVF == false) {
    cout << "Ingrese la justificación de la respuesta: " << endl;
    cin >> this->justificacion;
  }
}

class Alternativa : public Pregunta{
  private:
  vector<string> alternativas;
  int respuestaCorrecta;
  public:
   Alternativa(vector<string> alternativas, int respuestaCorrecta, string enunciado, int nivelTaxonomico);
   ~Alternativa();
   getrespuestaCorrecta();
   setrespuestacorrecta(int respuestaCorrecta);
   void testeo();
};


Alternativa::Alternativa(vector<string> alternativas, int respuestaCorrecta, string enunciado, int nivelTaxonomico):Pregunta(enunciado, nivelTaxonomico){
  this->alternativas.pushback(alternativas);
  this->respuestaCorrecta = respuestaCorrecta;
  this->enunciado = enunciado;

  

}
Alternativa::~Alternativa(){

}

void Alternativa::testeo{
  int cantidadAlternativas
  cout<<"ingrese la cantidad de alternativas"
  cin>>this->cantidadAlternativas;
  for(i=0,i<this->cantidadAlternativas;i++){
    cout<<"ingrese el enunciado:"<<endl;
    cin>>this->enunciado;
    cout<<"ingresa la alternativa:"<<endl;
    this->alternativas.pushback(Alternativa);
  }
}

// Segunda Clase: Item
class Item : public Pregunta{
private:
  int cantidadPregunta;
  string NombreItem;
  vector<Pregunta*> preguntas;

public:
  Item(int cantidadItem, string NombreItem, Pregunta * pregunta);
  ~Item();
  int getcantidadPregunta();
  string getNombreItem();
  void setCantidadPregunta(int cantidadPregunta);
  void setNombreItem(string NombreItem);
};

// Constructor de Item
Item::Item(int cantidadPregunta, string NombreItem, Pregunta * pregunta){
  this->cantidadPregunta = cantidadPregunta;
  this->NombreItem=NombreItem;
  this->preguntas = preguntas;
} 

// Destructor de Item
Item::~Item(){
  cout<<"Destruyendo item"<<endl;
}

// Getters y setters
int Item::getcantidadPregunta(){
  return this->cantidadPregunta;
}

string Item::getNombreItem(){
  return this->NombreItem;
}

void Item::setCantidadPregunta(int cantidadPregunta){
  this->cantidadPregunta = cantidadPregunta;
  cout<<"la prueba posee "<<cantidadPregunta<<" items"<<endl;
}

void Item::setNombreItem(string NombreItem){
  this->NombreItem=NombreItem;
  cout<<"el nombre del item es "<<NombreItem<<endl;
}


class Prueba : public Item{
private:
  int cantidadItem;
  int tiempo;
  Pregunta *pregunta;
  vector<Item*>Items;

public:
  Prueba(Item* item,Pregunta* preguntas, int tiempo);
  ~Prueba();
  void menu();
  void crearItem();
  void actualizarItem(Item *item);
  void eliminarItem(Item *item);
  void mostrarItem();
  void mostrarTiempo();
};

Prueba::Prueba( Item* item,Pregunta* preguntas, int tiempo){
  this->pregunta=preguntas;
  this->tiempo = tiempo;
  
  
}
void Prueba::menu(){
  int opcion;
  cout<<"1. Crear item"<<endl;
  cout<<"2. Actualizar item"<<endl;
  cout<<"3. Eliminar item"<<endl;
  cout<<"4. Mostrar item"<<endl;
  cout<<"5. Mostrar tiempo"<<endl;
  cout<<"6. Salir"<<endl;
  cin>>opcion;
  
  switch(opcion){
    case 1:
      crearItem();

    case 2:
      actualizarItem(Item *item);

    case 3:
      eliminarItem(Item *item);

    case 4:
      mostrarItem();

   case 5:
      mostrarTiempo();

    case 6:
      cout<<"Saliendo del programa"<<endl;
      break;

    default:
      cout<<"Opcion invalida, Intente de nuevo."<<endl;
  }
}


Prueba::~Prueba(){
  cout<<"Destruyendo prueba"<<endl;
}

void Prueba::crearItem(){
  string NombreItem, enunciado;
  int cantidadPregunta, tipoPregunta;

  cout << "ingresa la cantidad de items:" << endl;
  cin >> cantidadItem;
  
  for(int i = 0; i < cantidadItem; i++) {
    cout << "ingresa el nombre del item:" << endl;
    cin >> NombreItem;
  
    cout << "ingresa la cantidad de preguntas:" << endl;
    cin >> cantidadPregunta;
    
    for(int j = 0; j < cantidadPregunta; j++) {
      cout << "Pregunta " << j+1 <<endl;
      cout << "\n----Tipo de Pregunta----" << endl;
      cout << "1. Verdadero o Falso" << endl;
      cout << "2. Alternativas" << endl;

      while(true) {
        cout << "ingresa el tipo de pregunta:" << endl;
        cin >> tipoPregunta;
  
        if(tipoPregunta == 1) {
          verdaderoFalso();
          break;
        }
          
        else if(tipoPregunta == 2) {
          alternativas();
          break;

        }
        else{
          cout << "Opcion no valida, intente de nuevo." << endl;
        }
      }
    }
  }
}

void Prueba::actualizarItem(Item *item){
  Item * nuevo_item;
  nuevo_item  = crearItem();
  
  for(int i=0;i<Items.size();i++){
    
    if(Items[i]==item){
      this->Items[i]=nuevo_item;
    }
  } 
}
  
void Prueba::eliminarItem(Item *item){
  for(int i=0;i<Items.size();i++)
    if(Items[i]==item){
      Items.erase(Items.begin()+i);
    }
}

void Prueba::mostrarItem(){
  for(int i=0;i<Items.size();i++){
    cout << "----Información del item----" << Items[i]<<endl;
  }
}
  
void Prueba::mostrarTiempo(){
  cout << "El tiempo de la prueba es de " << this->tiempo << endl;
}





int main(){

  Prueba * e1 = new Prueba()
  e1->menu();
  e1->mostrarItem();
  e1->mostrarTiempo();
  e1->eliminarItem(i1);
  e1->mostrarItem();
  e1->mostrarTiempo();
  e1->actualizarItem(i1);
  e1->mostrarItem();
}

