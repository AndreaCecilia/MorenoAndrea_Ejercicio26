#include <iostream>
#include <fstream>

#include <string.h>

using namespace std;

//Inicializo las funciones del primer punto

void relleno(float* l, int N);

// Inicializo las funciones del segundo punto

float * read_file(string filename, int *n_points);
float multiplicador(float *x, float *y, int n_pointsx, int n_pointsy);
// Inicializo la funcion para guardar el archivo

void ejemplo_escribe(string filename, float a);

// Creo el main
int main () {
cout<<"Escriba un numero del tamaño del arreglo"<<endl;

int N=0; 

cin>>N;

   float * lista  = new float[N]; //Inicializo el vector
 
    relleno(lista, N); //llamo la función que rellena la lista con los valores deseados y la imprime en pantalla
   
   
   delete [] lista; //borro la lista

  float *x=NULL;
  float *y=NULL;
  int n_x=0;
  int n_y=0;

  x = read_file("valores_x.txt", &n_x); //leo el primer archivo mediante la función read file y lo vuelvo un arreglo
  y = read_file("valores_y.txt", &n_y); //leo el segundo archivo  mediante la función read file y lo vuelvo un arreglo
  
 float a= multiplicador(x, y, n_x, n_y); // llamo la funcion que multiplica los dos arreglos  y retorna el resultado 
  string filename;
  filename = "multiplicados.dat";
  ejemplo_escribe(filename,a); // llamo la funcion que crea el archivo.dar

   return 0;
}

void relleno(float* lista, int N){
// como parametros de entrada resive un elemento de tipo puntero que corresponde al puntero del primer elemento de la lista
// y un entero con el tamaño del vector
//La funcion rellena el vector con el factorial de la posicion(0 a N-1) y la imprime en pantalla
    float multi=1;//Inicializo un auuxiliar para poder hacer el factorial
    cout << "Lista"<< endl;
   for (int i=0;i<N;i++){  //rellena cada posicion con su factorial equivalente
       if(i==0){
       lista[i]=1;}
       else{
        multi=multi*i;
       lista[i]=multi;}
     cout << lista[i] << endl;
    
}}


float * read_file(string filename, int *n_points){
//Esta función permite leer los archivos cuyo nombre entre de parametro, y lo guarda en la dirección señalada en el parametro de entrada y retorna el pointer al arreglo que contiene la informacion del archivo que fue leido.
  int n_lines=0;
  ifstream infile; 
  string line;
  int i;
  float *array;

  /*cuenta lineas*/
  infile.open(filename); 
  getline(infile, line);
  while(infile){
    n_lines++;
    getline(infile, line);
  }
  infile.close();
  *n_points = n_lines;

  /*reserva la memoria necesaria*/
  array = new float[n_lines];

  /*carga los valores*/
  i=0;
  infile.open(filename); 
  getline(infile, line);  
  while(infile){
    array[i] = atof(line.c_str());
    i++;
    getline(infile, line);
  }
  infile.close();

  return array;
}

float multiplicador(float *x, float *y, int n_pointsx, int n_pointsy){
//Esta función hace el producto punto de los vectores, para hacer esto verifica que ambos tengan el mismo tamaño, y en caso contrario emite un mensaje.  
// se debe introducir el puntero de los dos arreglos y los tamaños de ambos arreglos. 
//La salida de la función es el resultado del producto
  float a=0;
  int i;
  if( n_pointsx == n_pointsy){
  for(i=0;i<n_pointsx;i++){ 
    a += x[i]*y[i];
  }}
    else{
        cout<<"la multiplicacion es invalida porque los archivos difieren en tamaño";
    }
  return a;
}


void ejemplo_escribe(string filename, float a){
  ofstream outfile;


  outfile.open(filename);

  cout << "Escribiendo en " << filename << endl; 
  outfile << a << endl;
  
  outfile.close(); 
}
