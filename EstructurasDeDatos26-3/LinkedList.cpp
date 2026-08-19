#include "LinkedList.h"
#include "ConsoleUI.h"


LinkedList::LinkedList()
{
    _size = 0;

    _first = nullptr;

    _last = nullptr;
}


void LinkedList::Add(int dato)
{
    Nodo* nuevo = new Nodo(dato, nullptr, _size);


    // Si la lista esta vacia
    if (_first == nullptr)
    {
        _first = nuevo;
        _last = nuevo;
    }

    // Si ya hay elementos
    else
    {
        _last->setNext(nuevo);

        _last = nuevo;
    }


    _size++;
}


int LinkedList::GetAt(int index)
{
    // Verificar que el indice exista
    if (index < 0 || index >= _size)
    {
        return -1;
    }


    Nodo* actual = _first;


    // Avanzar hasta la posicion solicitada
    for (int i = 0; i < index; i++)
    {
        actual = actual->getNext();
    }


    return actual->GetDato();
}


int LinkedList::GetSize()
{
    return _size;
}


void LinkedList::Print()
{
    if (_first == nullptr)
    {
        ConsoleUI::PrintError("La lista esta vacia.");

        return;
    }


    ConsoleUI::PrintText("ID\tDATO");

    ConsoleUI::PrintSeparator();


    Nodo* actual = _first;


    while (actual != nullptr)
    {
        ConsoleUI::PrintNode(
            actual->GetId(),
            actual->GetDato()
        );


        actual = actual->getNext();
    }
}


void LinkedList::SelectionSort()
{
    // Una lista con 0 o 1 elementos ya esta ordenada
    if (_size < 2)
    {
        return;
    }


    Nodo* actual = _first;


    while (actual != nullptr)
    {
        // Suponemos que el actual es el menor
        Nodo* menor = actual;


        // Empezamos a buscar desde el siguiente nodo
        Nodo* buscador = actual->getNext();


        while (buscador != nullptr)
        {
            if (buscador->GetDato() < menor->GetDato())
            {
                menor = buscador;
            }


            buscador = buscador->getNext();
        }


        // Intercambiamos solamente _dato
        // NO movemos nodos ni cambiamos _next

        if (menor != actual)
        {
            int temporal = actual->GetDato();

            actual->setDato(
                menor->GetDato()
            );

            menor->setDato(
                temporal
            );
        }


        actual = actual->getNext();
    }
}


void LinkedList::InsertionSort()
{
    // Una lista con 0 o 1 elementos ya esta ordenada
    if (_size < 2)
    {
        return;
    }


    // El primer elemento por si solo ya esta ordenado
    Nodo* actual = _first->getNext();


    while (actual != nullptr)
    {
        int datoInsertar = actual->GetDato();


        // Buscar desde el principio donde deberia
        // insertarse el valor actual
        Nodo* posicion = _first;


        while (
            posicion != actual &&
            posicion->GetDato() <= datoInsertar
            )
        {
            posicion = posicion->getNext();
        }


        // Si posicion != actual significa que el
        // valor necesita moverse hacia la izquierda
        if (posicion != actual)
        {
            int valorMover = datoInsertar;

            Nodo* mover = posicion;


            // Desplazar los DATOS entre los nodos.
            // Los punteros _next nunca se modifican.
            while (mover != actual->getNext())
            {
                int temporal = mover->GetDato();

                mover->setDato(valorMover);

                valorMover = temporal;

                mover = mover->getNext();
            }
        }


        actual = actual->getNext();
    }
}


LinkedList::~LinkedList()
{
    Nodo* actual = _first;


    while (actual != nullptr)
    {
        // Guardamos el siguiente ANTES del delete
        Nodo* siguiente = actual->getNext();


        delete actual;


        actual = siguiente;
    }


    _first = nullptr;

    _last = nullptr;

    _size = 0;
}