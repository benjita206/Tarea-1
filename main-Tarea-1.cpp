#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Primera Clase: Pregunta
class Pregunta{
private:
 string enunciado;
  int nivelTaxonomico;

public:
  Pregunta(string enunciado, int nivelTaxonomico);

  virtual ~Pregunta();
  string getEnunciado();
  int getNivelTaxonomico();
  void setEnunciado(string enunciado);
  void setNivelTaxonomico(int nivelTaxonomico);
  virtual void mostrar();
  virtual void mostrarNivelTaxonomico();
};

// Contructor de Pregunta
Pregunta::Pregunta(string enunciado, int nivelTaxonomico){
  this->enunciado = enunciado;
  this->nivelTaxonomico = nivelTaxonomico;
}

// Destructor de Pregunta con su mensaje
Pregunta::~Pregunta(){
  std::cout << "Se ha eliminado la Pregunta" << endl;

}

string Pregunta::getEnunciado(){
  return this->enunciado;
}

int Pregunta::getNivelTaxonomico(){
  return this->nivelTaxonomico;
}

void Pregunta::setEnunciado(string enunciado){
  this->enunciado=enunciado;
}

void Pregunta::setNivelTaxonomico(int nivel) {
  if (nivel >= 1 && nivel <= 6) {
      this->nivelTaxonomico = nivel;
  } else {
      cout << "Nivel inválido" << endl;
  }
}

// Metodos de Pregunta
void Pregunta::mostrar(){
  cout << "Enunciado: " << enunciado << endl;
  cout << "Nivel: " << nivelTaxonomico << endl;
}

void Pregunta::mostrarNivelTaxonomico(){
  cout<<"el nivel taxonomico es "<<this->nivelTaxonomico<<endl;
}

//Segunda Clase: Verdadero y Falso

class VerdaderoFalso : public Pregunta {
  private:
    bool respuesta;
    string justificacion;

  public:
    VerdaderoFalso(string enunciado, int nivel, bool respuesta, string justificacion);
    ~VerdaderoFalso();
    string getJustificacion();
    bool getRespuestaCorrecta();
    void setJustificacion(string justificacion);
    void setRespuestaCorrecta(bool respuesta);
    void mostrar();
};

// Constructor de Verdadero y Falso
VerdaderoFalso::VerdaderoFalso(string enunciado, int nivel, bool respuesta, string justificacion)
  : Pregunta(enunciado, nivel) {
  this->respuesta = respuesta;
  this->justificacion = justificacion;
}

// Destructor de Verdadero y Falso
VerdaderoFalso::~VerdaderoFalso(){

}

//Getters y Setters
string VerdaderoFalso::getJustificacion(){
  return this->justificacion;
}

bool VerdaderoFalso::getRespuestaCorrecta(){
  return this->respuesta;
}

void VerdaderoFalso::setJustificacion(string justificacion){
  this->justificacion = justificacion;
}

void VerdaderoFalso::setRespuestaCorrecta(bool respuesta){
  this->respuesta = respuesta;
}

// Metodos de Verdadero y Falso
void VerdaderoFalso::mostrar(){
  cout << "Tipo: Verdadero/Falso" << endl;
  cout << "Enunciado: " << getEnunciado() << endl;
  cout << "Nivel taxonómico: " << getNivelTaxonomico() << endl;
  cout << "Respuesta: " << (respuesta ? "Verdadero" : "Falso") << endl;

  if (!respuesta) {
    cout << "Justificación: " << getJustificacion() << endl;
  }
}

// Tercera Clase: Alternativa
class Alternativa : public Pregunta{
  private:
      vector<string> alternativas;
      int respuestaCorrecta; // Índice de la alternativa correcta

  public:
      Alternativa(string enunciado, int nivel, vector<string> alternativas, int respuestaCorrecta);
      ~Alternativa();

      vector<string> getAlternativas();
      int getRespuestaCorrecta();

      void setAlternativas(vector<string> alternativas);
      void setRespuestaCorrecta(int respuestaCorrecta);
      void creacion();

};

// Constructor de Alternativa
Alternativa::Alternativa(string enunciado, int nivel, vector<string> alternativas, int respuestaCorrecta)
: Pregunta(enunciado, nivel){
    this->alternativas = alternativas;
    this->respuestaCorrecta = respuestaCorrecta;
}

// Destructor de Alternativas
Alternativa::~Alternativa(){
  cout << "Destruyendo Alternativa" << endl;
}

//Getters y Setters

vector<string> Alternativa::getAlternativas(){
  return alternativas;
}

int Alternativa::getRespuestaCorrecta(){
  return respuestaCorrecta;
}

void Alternativa::setAlternativas(vector<string> alternativas){
  this->alternativas = alternativas;
}

void Alternativa::setRespuestaCorrecta(int respuestaCorrecta){
  this->respuestaCorrecta = respuestaCorrecta;
}

// Metodos de Alternativas
void Alternativa::creacion(){
  int cantidadAlternativas;
  string alt;
  string enunciado;

  cout << "Ingrese la cantidad de alternativas: ";
  cin >> cantidadAlternativas;
  cin.ignore(); // Para limpiar el buffer del enter

  vector<string> nuevasAlternativas;

  for (int i = 0; i < cantidadAlternativas; i++) {
      cout << "Ingrese la alternativa " << (i + 1) << ": ";
      getline(cin, alt);
      nuevasAlternativas.push_back(alt);
  }

  this->setAlternativas(nuevasAlternativas);

  int correcta;
  cout << "Ingrese el índice de la respuesta correcta (0 a " << cantidadAlternativas - 1 << "): ";
  cin >> correcta;
  this->setRespuestaCorrecta(correcta);
}

// Cuarta Clase: Item
class Item{
  private:
    string nombre;
    vector<Pregunta*> preguntas;


  public:
    Item(string nombre);
    ~Item();

    void agregarPregunta(Pregunta* p);
    string getNombre();
    void mostrar();
    vector<Pregunta*> getPreguntas();

};

// Constructor de Item
Item::Item(string nombre){
  this->nombre=nombre;
} 

// Destructor de Item
Item::~Item() {
  for (size_t i = 0; i < preguntas.size(); i++) {
    delete preguntas[i];
  }
}

// Getters y setters

string Item::getNombre(){
  return this->nombre;
}

void Item::agregarPregunta(Pregunta* p) {
  preguntas.push_back(p);
}

// Metodos de Item
void Item::mostrar() {
  cout << "Item: " << nombre << endl;
  for (size_t i = 0; i < preguntas.size(); i++) {
    cout << "Pregunta " << i + 1 << ":" << endl;
    preguntas[i]->mostrar();
    cout << endl;
  }
}

vector<Pregunta*> Item::getPreguntas() {
    return preguntas;
}

// Quinta clase: Prueba
class Prueba {
  private:
    vector<Item*> Items;
    int tiempo;

  public:
    Prueba();
    ~Prueba();

    void crearItem();
    void actualizarItem(Item* item);
    void eliminarItem(Item* item);
    void calcularTiempo();
    void mostrarItem();
    void mostrarTiempo();
    void menu();

    Pregunta* crearVerdaderoFalso();
    Pregunta* crearAlternativa();
};

// Constructor de Prueba
Prueba::Prueba() {
  this->tiempo = 0; // Definir por default que no tiene minutos
}

// Destructor de Prueba
Prueba::~Prueba() {
  cout << "Destruyendo prueba" << endl;
  for (size_t i = 0; i < Items.size(); i++) {
    delete Items[i];
  }
}

// Metodos de Prueba
void Prueba::menu(){
  int opcion;
  cout << "---- Menú ----" << endl;
  cout << "1. Crear item" << endl;
  cout << "2. Actualizar item" << endl;
  cout << "3. Eliminar item" << endl;
  cout << "4. Mostrar item" << endl;
  cout << "5. Mostrar tiempo" << endl;
  cout << "6. Salir" << endl;
  cout << "Ingrese una opción: \n"<< endl;
  cin >> opcion;

  switch(opcion){
    case 1:
      crearItem();
      return;

    case 2:
      if (Items.empty()) {
        cout << "No hay items para actualizar.\n";
      } 

      else {
        int index;
        mostrarItem();
        cout << "Ingrese el número del item a actualizar: ";
        cin >> index;
        cin.ignore();

        if (index >= 1 && index <= Items.size()) {
          actualizarItem(Items[index - 1]);
        } 

        else {
          cout << "Índice no válido.\n";
        }
      }
      break;

    case 3:
      if (Items.empty()) {
        cout << "No hay items para eliminar.\n";
      }

      else {
        int index;
        mostrarItem();
        cout << "Ingrese el número del item a eliminar: ";
        cin >> index;
        cin.ignore();

        if (index >= 1 && index <= Items.size()) {
          eliminarItem(Items[index - 1]);
          cout << "Item eliminado.\n";
        } 

        else {
          cout << "Índice no válido.\n";
        }
      }
      break;

    case 4:
      if (Items.empty()) {
        cout << "No hay items para mostrar.\n";
      }

      else
        mostrarItem();

      return;

    case 5:
      calcularTiempo();
      mostrarTiempo();
      break;

    case 6:
      cout<<"Saliendo del programa"<<endl;
      break;

    default:
      cout<<"Opcion invalida, Intente de nuevo."<<endl;
  }
}

void Prueba::crearItem() {
  int cantidadItem, cantidadPregunta, tipoPregunta;
  string nombreItem;

  cout << "Ingresa la cantidad de items: ";
  while (true){
    cin >> cantidadItem;
    cin.ignore();

    if (cantidadItem > 0)
      break;

    else
      cout << "Cantidad no permitida. Ingrese de nuevo: ";

  }

  for (int i = 0; i < cantidadItem; i++) {
    cout << "Ingresa el nombre del item: ";
    getline(cin, nombreItem);

    Item* item = new Item(nombreItem);

    cout << "Ingresa la cantidad de preguntas: ";

    while (true){
      cin >> cantidadPregunta;
      cin.ignore();

      if (cantidadPregunta > 0)
        break;

      else
        cout << "Cantidad no permitida. Ingrese de nuevo: ";

    }

    for (int j = 0; j < cantidadPregunta; j++) {
      cout << "\nPregunta " << j + 1 << ":" << endl;
      cout << "1. Verdadero/Falso" << endl;
      cout << "2. Alternativas" << endl;

      while (true) {
        cout << "Elige tipo de pregunta: ";
        cin >> tipoPregunta;
        cin.ignore();

        if (tipoPregunta == 1) {
          item->agregarPregunta(crearVerdaderoFalso());
          break;
        } 

        else if (tipoPregunta == 2) {
          item->agregarPregunta(crearAlternativa());
          break;
        } 

        else {
          cout << "Opción inválida, intenta nuevamente." << endl;
        }
      }
    }
    Items.push_back(item);
  }
}

Pregunta* Prueba::crearVerdaderoFalso(){
  string enunciado, justificacion;
  int nivel;
  int respuesta;

  cout << "Ingrese enunciado: ";
  getline(cin, enunciado);

  cout<< "---- Niveles Taxonomicos ----" << endl;
  cout << "1. Recordar" << endl;
  cout << "2. Entender" << endl;
  cout << "3. Aplicar" << endl;
  cout << "4. Analizar" << endl;
  cout << "5. Evaluar" << endl;
  cout << "6. Crear" << endl;
  cout << "Ingrese el nivel Taxonomico: " << endl;

  while(true){
    cin >> nivel;
    cin.ignore();

    if (nivel < 1 || nivel > 6)
      cout << "Opción inválida, intenta nuevamente: ";

    else
      break;
  }

  cout << "Ingrese la respuesta (true o false): ";
    cin >> respuesta;
    cin.ignore();

    if (!respuesta) {
      cout << "Ingrese justificación: ";
      getline(cin, justificacion);
    }

    return new VerdaderoFalso(enunciado, nivel, respuesta, justificacion);
  }

Pregunta* Prueba::crearAlternativa(){
  string enunciado;
  int nivel, cantidad, correcta;
  vector<string> alternativas;
  string alt;

  cout << "Ingrese enunciado: ";
  getline(cin, enunciado);

  cout<< "---- Niveles Taxonomicos ----" << endl;
  cout << "1. Recordar" << endl;
  cout << "2. Entender" << endl;
  cout << "3. Aplicar" << endl;
  cout << "4. Analizar" << endl;
  cout << "5. Evaluar" << endl;
  cout << "6. Crear" << endl;
  cout << "Ingrese el nivel Taxonomico: " << endl;

  while(true){
    cin >> nivel;
    cin.ignore();

    if (nivel < 1 || nivel > 6)
      cout << "Opción inválida, intenta nuevamente: ";

    else
      break;
  }

  cout << "Ingrese cantidad de alternativas: ";

  while(true){
    cin >> cantidad;
    cin.ignore();

    if (cantidad < 2)
      cout << "Cantidad no permitida. Ingrese de nuevo: ";

    else
      break;
  }

  for (int i = 0; i < cantidad; i++){
    cout << "Alternativa " << i << ": ";
    getline(cin, alt);
    alternativas.push_back(alt);
  }

  cout << "Ingrese índice de la respuesta correcta (0 a " << cantidad - 1 << "): ";
  cin >> correcta;
  cin.ignore();

  return new Alternativa(enunciado, nivel, alternativas, correcta);
}

void Prueba::actualizarItem(Item* item) {
    vector<Pregunta*> preguntas = item->getPreguntas();

    if (preguntas.empty()) {
        cout << "Este ítem no tiene preguntas.\n";
        return;
    }

    cout << "\nPreguntas en el item '" << item->getNombre() << "':\n";
    for (size_t i = 0; i < preguntas.size(); ++i){
        cout << i + 1 << ". ";
        preguntas[i]->mostrar();
        cout << endl;
    }

    int indice;
    cout << "Ingrese el número de la pregunta que desea actualizar: ";
    cin >> indice;
    cin.ignore();

    if (indice < 1 || indice > preguntas.size()){
        cout << "Índice inválido.\n";
        return;
    }

    // Eliminar la antigua
    delete preguntas[indice - 1];

    // Elegir nuevo tipo
    int tipo;
    cout << "Seleccione el nuevo tipo de pregunta:\n1. Verdadero/Falso\n2. Alternativas\nOpción: ";
    cin >> tipo;
    cin.ignore();

    Pregunta* nueva = nullptr;
    if (tipo == 1) {
        nueva = crearVerdaderoFalso();
    } 

    else if (tipo == 2) {
        nueva = crearAlternativa();
    } 

    else {
        cout << "Tipo inválido. Cancelando actualización.\n";
        return;
    }

    // Reemplazar
    preguntas[indice - 1] = nueva;

    cout << "Pregunta actualizada exitosamente.\n";
}

void Prueba::eliminarItem(Item* item) {
  for (size_t i = 0; i < Items.size(); i++) {
    if (Items[i] == item) {
      delete Items[i];
      Items.erase(Items.begin() + i);
      break;
    }
  }
}

void Prueba::mostrarItem() {
  for (size_t i = 0; i < Items.size(); i++) {
    cout << "\n=== Item " << i + 1 << " ===" << endl;
    Items[i]->mostrar();
  }
}

void Prueba::calcularTiempo() {
  tiempo = 0;
  for (size_t i = 0; i < Items.size(); i++) {
    Item* item = Items[i];
    vector<Pregunta*> preguntas = item->getPreguntas();

    for (size_t j = 0; j < preguntas.size(); j++) {
      // Deducción de tipo por dynamic_cast
      if (dynamic_cast<VerdaderoFalso*>(preguntas[j])) {
        tiempo += 3; // 3 minuto
      } else if (dynamic_cast<Alternativa*>(preguntas[j])) {
        tiempo += 2; // 2 minutos
      }
    }
  }
}

void Prueba::mostrarTiempo() {
  cout << "El tiempo de la prueba es de " << tiempo << " minutos." << endl;
}
int main() {
    Prueba prueba;
    while (true) {
        prueba.menu();
        char continuar;
        cout << "¿Desea realizar otra acción? (s/n): ";
        cin >> continuar;
        cin.ignore();
        if (continuar != 's' && continuar != 'S') break;
    }
    return 0;
}
