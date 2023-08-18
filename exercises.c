#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Ejercicio 1: Encuentra el Elemento Mayor
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y devuelva el valor más grande del arreglo.
*/
int findMax(int arr[], int size) 
{
  // Crear la variable maximo y asignarle el primer valor del arreglo  
  int maximo = arr[0]; 

  for (int i = 1; i < size; i++)
    if (arr[i] > maximo)
      // Cada vez que se encuentre un valor mayor al "maximo", se actualiza la             variable maximo 
      maximo = arr[i];
  return maximo;
} 

/*
Ejercicio 2: Invertir un Arreglo
Descripción: Escribe una función que tome un arreglo y su tamaño, y luego
invierta el orden de sus elementos.
*/
void reverseArray(int arr[], int size) 
{
  // Variables auxiliares para recorrer el arreglo
  int inicio = 0;
  int fin = size - 1;

  //Ciclo para intercambiar intercambiar el valor incial con el final del arreglo     a medida que se va recooriendo el mismo.
  while (inicio < fin) 
  {
    int temp = arr[inicio];
    arr[inicio] = arr[fin];
    arr[fin] = temp;

    inicio++;
    fin--;
  }
  return; 
}

/*
Ejercicio 3: Filtrar Números Pares
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y luego devuelva un nuevo arreglo que contenga solo
los números pares del arreglo original.
*/
int *filterEvenNumbers(int arr[], int size, int *newSize) 
{
  // Contar la cantidad de números pares en el arreglo original
  int count = 0;
  for (int i = 0; i < size; i++) 
    if (arr[i] % 2 == 0) count++;    

  // Crear un nuevo arreglo para almacenar los números pares
  int *result = (int *)malloc(count * sizeof(int));
  if (result == NULL) 
  {
    printf("Error al asignar memoria");
    exit(EXIT_FAILURE);
  }

  // Copiar los números pares al nuevo arreglo
  int j = 0;
  for (int i = 0; i < size; i++) 
    if (arr[i] % 2 == 0) 
    {
      result[j] = arr[i];
      j++;
    }
  
  *newSize = count; // Actualizar el valor de newSize

  return result;
}

/*
Ejercicio 4: Fusión de dos Arreglos Ordenados
Descripción: Escribe una función que tome dos arreglos
ordenados y sus tamaños, y luego fusione estos dos
arreglos en un tercer arreglo también ordenado.
*/
void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2,
                       int result[])
{
  int i = 0, j = 0, k = 0;

  // Recorre ambos arreglos y compara los elementos para fusionarlos en 'result'
  while (i < size1 && j < size2) 
  {
    if (arr1[i] < arr2[j]) 
    {
      result[k] = arr1[i];
      i++;
    } 
    else 
    {
      result[k] = arr2[j];
      j++;
    }
    k++;
  }

  // Si quedan elementos en 'arr1', se agregan a 'result'
  while (i < size1) 
  {
    result[k] = arr1[i];
    i++;
    k++;
  }

  // Si quedan elementos en 'arr2', se agregan a 'result'
  while (j < size2) 
  {
    result[k] = arr2[j];
    j++;
    k++;
  }
}

/*
Ejercicio 5: Comprobación de Ordenación
Descripción: Escribe una función que tome un arreglo y su tamaño,
y luego devuelva 1 si el arreglo está ordenado en orden ascendente,
  0 si no está ordenado, y -1 si está ordenado en orden descendente.
*/
int checkSorted(int arr[], int size) 
{
  if (size <= 1) return 1; 
  // Si el arreglo es de tamaño 0 o 1 se asume ordenado
  
  int ascendente = 1;
  int descendente = 1;

  for (int i = 1; i < size; i++) 
  {
    if (arr[i] < arr[i - 1]) ascendente = 0;    
    if (arr[i] > arr[i - 1]) descendente = 0;      
  }

  if (ascendente) return 1;
  else if (descendente) return -1;
  else return 0;
}


/*
Ejercicio 6: Información de una Biblioteca
Descripción: Vamos a representar la información de una biblioteca. En la
biblioteca, hay libros, y cada libro tiene un autor. Queremos organizar esta
información utilizando estructuras anidadas en C. Escribe la función para
inicializar la información de un libro.
*/

typedef struct {
  char nombre[50];
  int anioNacimiento;
} Autor;

typedef struct {
  char titulo[100];
  Autor autor;
  int anioPublicacion;
} Libro;

void inicializarLibro(Libro *libro, const char *titulo, const char *nombreAutor, int anioNacimiento, int anioPublicacion) 
{
  // Copiar el título del libro
  strncpy(libro->titulo, titulo, sizeof(libro->titulo) - 1);
  libro->titulo[sizeof(libro->titulo) - 1] = '\0';

  // Copiar el nombre del autor
  strncpy(libro->autor.nombre, nombreAutor, sizeof(libro->autor.nombre) - 1);
  libro->autor.nombre[sizeof(libro->autor.nombre) - 1] = '\0';

  // Asignación del año de nacimiento del autor
  libro->autor.anioNacimiento = anioNacimiento;

  // Asignación del año de publicación del libro
  libro->anioPublicacion = anioPublicacion;
}

/*
Ejercicio 7: Lista enlazada de números
Descripción: Escribe una función que tome un arreglo de enteros y su tamaño, y
luego cree una lista enlazada usando la estructura Nodo. Cada nodo de la lista
debe contener un número del arreglo, y los nodos deben estar enlazados en el
mismo orden que los números aparecen en el arreglo. El último nodo de la lista
debe apuntar a NULL. La función debe devolver un puntero al primer nodo de la
lista enlazada.
Recuerda reservar memoria dinámica para cada nodo usando malloc.
  */

typedef struct nodo {
  int numero;
  struct nodo *siguiente; // puntero al siguiente nodo
} Nodo;

Nodo *crearListaEnlazada(int arr[], int size)
{
  Nodo *head = NULL; // Puntero al primer nodo de la lista
  Nodo *tail = NULL; // Puntero al último nodo de la lista

  for (int i = 0; i < size; i++) 
  {
    // Crear un nuevo nodo
    Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
    if (nuevoNodo == NULL)
    {
      printf("Error al asignar memoria para el nodo");
      
      while (head != NULL)
      {
        Nodo *temp = head;
        head = head->siguiente;
        free(temp);
      }
      return NULL;
    }
  }
  // Inicializar el nuevo nodo
  nuevoNodo->numero = arr[i];
  nuevoNodo->siguiente = NULL;

  // Enlazar el nuevo nodo al final de la lista
  if (head == NULL) 
  {
    head = nuevoNodo;
    tail = nuevoNodo;
  } else 
  {
    tail->siguiente = nuevoNodo;
    tail = nuevoNodo;
  }
  return head;
}



