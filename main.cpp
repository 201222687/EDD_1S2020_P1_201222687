#include <ncurses.h>
#include <iostream>

#include <stdio.h> // para poder imprimir con printf
#include <stdlib.h>// para poder configurar malloc
#include <string.h>//para trabajar strcmp
//#include <stdbool.h>//para trabajar con variables booleanas
//#include <time.h>//Para Calcular la hora del sistema.

using namespace std;

//-----------------Inicio----------------LITA CIRCULAR SIMPLE ENLAZADA-------[Archivos]---
typedef struct NodoEstrucLCE
{   string nombrearchivo;
    string ruta ;
    struct NodoEstrucLCE *Siguiente;
}tipoNodoLCE;

typedef tipoNodoLCE *NodoLCE;

void InsertarLCE(NodoLCE *PrimeroIn,NodoLCE *UltimoIn,string nombrearchivo,string ruta) {
// Creamos un nodo para el nuvo valor a insertar
   NodoLCE nuevo = (NodoLCE)malloc(sizeof(tipoNodoLCE));
   nuevo->nombrearchivo=nombrearchivo;
   nuevo->ruta=ruta;


    if(!(*PrimeroIn))
    {
        (*PrimeroIn)=(*UltimoIn)=nuevo;
        (*UltimoIn)->Siguiente=nuevo;
    }else
    {
    (*UltimoIn)->Siguiente=nuevo;
    nuevo->Siguiente=(*PrimeroIn);
    (*UltimoIn)=nuevo;
    }
}

void MostrarLCE(NodoLCE PrimeroIn)
{
   NodoLCE Actual = PrimeroIn;

    if(Actual!=NULL)
    {
    printf("----Mostrando Lista Circular simple.---\n");
    do
   {
    cout<<"Nombre archivo: "<<Actual->nombrearchivo<<" Ruta: "<<Actual->ruta<<"\n";
     Actual = Actual->Siguiente;
   }while(Actual != PrimeroIn);

    printf("--------fin----------------------.\n");
    }else
    {
    printf("Lista Circular simple Se Encuentra Vacia.\n");
    }

}

//-----------------Fin----------------LITA CIRCULAR SIMPLE ENLAZADA-------------[Archivos]--

//-----------------Inicio----------------Pila----------------------------[Prioridad]------
typedef struct NodoEstruPila
{
    string PalaBuscar;
    string PalaReemplazar;
    string Estado;
    string Palabra;
    string Posicion;
struct NodoEstruPila *Siguiente;
}tipoNodoPila;
typedef tipoNodoPila *NodoPila;

void Pop(NodoPila *Tope)
{
   NodoPila NodoAux; /* variable auxiliar para manipular nodo */
   /* Nodo apunta al primer elemento de la pila */
   NodoAux = *Tope;
   if(!NodoAux)
   {
   printf("Pila de documentos se encuentra vacia.\n");
   return; /* Si no hay nodos en la pila retornamos 0 */
   }
   /* Asignamos a pila toda la pila menos el primer elemento */
   *Tope = NodoAux->Siguiente;
   /* Borrar el nodo */
   free(NodoAux);
}
void PushNormal(NodoPila *Tope,string PalaBuscar,string PalaReemplazar,string Estado,string Palabra,string Posicion)
{
   NodoPila nuevo;
   /* Crear un nodo nuevo */
   nuevo = (NodoPila)malloc(sizeof(tipoNodoPila));
   nuevo->PalaBuscar= PalaBuscar;
   nuevo->PalaReemplazar= PalaReemplazar;
   nuevo->Estado= Estado;
   nuevo->Palabra= Palabra;
   nuevo->Posicion= Posicion;

   /* Añadimos la pila a continuación del nuevo nodo */
   nuevo->Siguiente = *Tope;
   /* Ahora, el comienzo de nuestra pila es en nuevo nodo */
   *Tope = nuevo;
}
void MostrarPila(NodoPila Tope)
{
  NodoPila Actual = Tope;


   printf("------------------Mostrando Pila [Log].-------------\n");

    if(Actual==NULL)
    {
    printf("------Pila De Documentos Se Encuentra Vacia----.\n");
    }
    else
    {

    while (Actual!=NULL)
    {

          cout<<"Palabra Buscada: "<< Actual->PalaBuscar<<" ";
          cout<<"Reemplazada por: "<< Actual->PalaReemplazar<<" ";
          cout<<"Estado: "<< Actual->Estado<<" ";
          cout<<"Palabra: "<< Actual->Palabra<<" ";
          cout<<"Posicion: "<< Actual->Posicion<<"\n";

       Actual = Actual->Siguiente;

    }

    }
    printf("-----------------------fin--------------------------------\n");

}
//-----------------Fin----------------Pila-------------------------------[Prioridad]------

//-----------------INICIO----------------LISTA DOBLEMENTE ENLAZADA ----[Caracteres]----------

typedef struct NodoEstrucLDE
{
    string caracter;
    struct NodoEstrucLDE *Siguiente;
    struct NodoEstrucLDE *Anterior;
}tipoNodoLDE;
typedef tipoNodoLDE *NodoLDE;

void InsertarLDE(NodoLDE *primero,NodoLDE *ultimo,string caracter)
{
            NodoLDE nuevo = (NodoLDE)malloc(sizeof(tipoNodoLDE));
            nuevo->caracter=caracter;

    //********************************inicio insercion lista doblemente enlazada **********************//
                   if((*primero)==NULL)
                   {
                       (*primero)=(*ultimo)=nuevo;
                   }
                   else
                   {
                       (*ultimo)->Siguiente =nuevo;
                       nuevo->Anterior = (*ultimo);
                       (*ultimo)=nuevo;
                   }
    //********************************inicio insercion lista doblemente enlazada **********************//


}
void MostrarLDE_PrimeroAlUltimo(NodoLDE Primero){

    NodoLDE Actual=Primero;

    if(Actual!=NULL)
    {
       printf("-----------------------Inicio de la lista doble--------------.\n");
       printf("Del primer nodo al ultimo nodo.\n");
        while(Actual!=NULL)
        {
            cout<<"caracter: "<< Actual->caracter<<"\n";
            Actual=Actual->Siguiente;
        }


       printf("-----------------------Fin de la lista doble------------------.\n");

    }
    else
    {
        printf("La lista doble se encuentra vacia.\n");
    }

}
void MostrarLDE_UltimoAlPrimero(NodoLDE Ultimo){
    NodoLDE Actual=Ultimo;

    if(Actual!=NULL)
    {
       printf("Inicio de la lista doble .\n");
       printf("Del ultimo nodo al primer nodo.\n");

        while(Actual!=NULL)
        {
            cout<<"caracter: "<< Actual->caracter<<"\n";
            Actual=Actual->Anterior;
        }

        printf("Fin de la lista doble .\n");

    }
    else
    {
        printf("La lista doble se encuentra vacia.\n");
    }

}

//-----------------FIN----------------LISTA DOBLEMENTE ENLAZADA -------[Caracteres]--


//-----------------inicio----------------LISTA SIMPLE ENLAZADA -[ORDEN ALFABETICAMENTE]------[Caracteres]--
typedef struct NodoEstrucLS
{   string PalabraBuscada;
    string PalaRemplazada;
    struct NodoEstrucLS *Siguiente;
}tipoNodoLS;

typedef tipoNodoLS *NodoLS;

void InsertarLSAlfa(NodoLS *primero, NodoLS *ultimo,string PalabraBuscada,string PalaRemplazada)
{
    // Creamos un nodo para el nuvo valor a insertar
   NodoLS nuevo = (NodoLS)malloc(sizeof(tipoNodoLS));
   nuevo->PalabraBuscada=PalabraBuscada;
   nuevo->PalaRemplazada=PalaRemplazada;

   //********************************inicio insercion lista simple enlazada ordenada alfabeticamente**********************//
                  //Insercion a la lista simple enlazada ordenada alfabeticamente cuando se encuentra vacia.
                  if((*primero)==NULL)
                  {
                      (*primero)=(*ultimo)=nuevo;
                  }
                                 else
                  {
                  //Insercion al inicio de la lista simple enlazada ordenada alfabeticamente.
                      // numeros positivos letra mas grande.
                      // numeros negativos letras mas pequeñas.
                      if(strcmp(nuevo->PalabraBuscada.c_str(),(*primero)->PalabraBuscada.c_str())<0)
                      {
                          nuevo->Siguiente= (*primero);
                          (*primero)= nuevo;
                      }
                      else
                      {

                          NodoLS actual = (*primero);

                          while (actual->Siguiente!=NULL)
                          {
                   //Insercion en el medio de la lista simple enlazada ordenada alfabeticamente.
                              // numeros positivos letra mas grande.
                              // numeros negativos letras mas pequeñas.
                      if(strcmp(nuevo->PalabraBuscada.c_str(),actual->Siguiente->PalabraBuscada.c_str())<0)
                              {
                                  nuevo->Siguiente = actual->Siguiente;
                                  actual->Siguiente=nuevo;
                                  break;
                              }
                             actual = actual->Siguiente;
                          }
                    //Insercion al final de la lista simple enlazada ordenada alfabeticamente.
                          if(actual->Siguiente==NULL)
                          {
                              actual->Siguiente =nuevo;
                              (*ultimo)=nuevo;
                          }
                      }
                  }
                  //********************************Fin insercion lista simple enlazada ordenada alfabeticamente **********************
}

void MostrarLS_PrimeroUltimo(NodoLS primero)
{

    NodoLS Actual=primero;

    if(Actual!=NULL)
        {
       printf("Inicio de la lista simple ordenada alfabeticamente.\n");
       printf("Del primer nodo al ultimo nodo.\n");
        while(Actual!=NULL)
        {
            cout<<"Busqueda :"<<Actual->PalabraBuscada<<" ";
            cout<<"Remplazada por :"<<Actual->PalaRemplazada<<"\n";

            Actual=Actual->Siguiente;
        }
        printf("Fin de la lista simple ordenada alfabeticamente.\n");
        }
        else
        {
            printf("La lista simple ordenada alfabeticamente se encuentra vacia.\n");
        }
}
//-----------------fin----------------LISTA SIMPLE ENLAZADA -----[ORDEN ALFABETICAMENTE]--[Caracteres]--


int main()
{
    //cout << "Hello world!" << endl;

    /*Declaracion de la Lista circular enlazada [Archivos]*/
     NodoLCE  InicioPLCE=NULL,InicioULCE=NULL;

    /*Declaracion de la Pila[Log]*/
    NodoPila Tope=NULL;

    /*Declaracion de la lista doble enlazada [caracter]*/
    NodoLDE InicioLDE=NULL,UltimoLDE=NULL;
    /*Declaracion de la lista simple ordenada alfabeticamente [palabras buscadas]*/
    NodoLS InicioLS = NULL, UltimoLS=NULL;

    InsertarLCE(&InicioPLCE,&InicioULCE,"archivo1.txt","/home/user/archivo1.txt");
    InsertarLCE(&InicioPLCE,&InicioULCE,"archivo2.txt","/home/user/archivo2.txt");
    InsertarLCE(&InicioPLCE,&InicioULCE,"archivo3.txt","/home/user/archivo3.txt");
    InsertarLCE(&InicioPLCE,&InicioULCE,"archivo4.txt","/home/user/archivo4.txt");
    InsertarLCE(&InicioPLCE,&InicioULCE,"archivo5.txt","/home/user/archivo5.txt");
    MostrarLCE(InicioPLCE);

    PushNormal(&Tope,"Universidad","Palabra1","Revertido","null","null");
    PushNormal(&Tope,"Universidad","Palabra2","Revertido","null","null");
    PushNormal(&Tope,"de","Palabra3","No Revertido","null","null");
    PushNormal(&Tope,"San","Palabra4","Revertido","null","null");
    PushNormal(&Tope,"Carlos","Palabra5","No Revertido","null","null");
    MostrarPila(Tope);

    InsertarLDE(&InicioLDE,&UltimoLDE,"a");
    InsertarLDE(&InicioLDE,&UltimoLDE,"b");
    InsertarLDE(&InicioLDE,&UltimoLDE,"c");
    InsertarLDE(&InicioLDE,&UltimoLDE,"d");
    InsertarLDE(&InicioLDE,&UltimoLDE,"e");
    MostrarLDE_PrimeroAlUltimo(InicioLDE);

    InsertarLSAlfa(&InicioLS,&UltimoLS,"z","addd");
    InsertarLSAlfa(&InicioLS,&UltimoLS,"m","bdd");
    InsertarLSAlfa(&InicioLS,&UltimoLS,"k","cdd");
    InsertarLSAlfa(&InicioLS,&UltimoLS,"o","ddd");
    InsertarLSAlfa(&InicioLS,&UltimoLS,"s","edd");
    MostrarLS_PrimeroUltimo(InicioLS);

    initscr();
    printw("Practica Uno con ncurses!!");
    refresh();
    getch();
    endwin();


    return 0;
}
