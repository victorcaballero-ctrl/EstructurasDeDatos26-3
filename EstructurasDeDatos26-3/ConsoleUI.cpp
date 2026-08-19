#include "ConsoleUI.h"

#include <iostream>
#include <cstdlib>
#include <conio.h>


// Definicion de constantes estaticas

const int ConsoleUI::COLOR_RESET = 0;
const int ConsoleUI::COLOR_RED = 31;
const int ConsoleUI::COLOR_GREEN = 32;
const int ConsoleUI::COLOR_YELLOW = 33;
const int ConsoleUI::COLOR_BLUE = 34;
const int ConsoleUI::COLOR_MAGENTA = 35;
const int ConsoleUI::COLOR_CYAN = 36;
const int ConsoleUI::COLOR_WHITE = 37;


void ConsoleUI::PrintTitle(std::string texto)
{
    int ancho = static_cast<int>(texto.length()) + 4;

    PrintTitle(texto, ancho);
}


void ConsoleUI::PrintTitle(std::string texto, int ancho)
{
    // Ancho minimo para que quepa el texto
    int anchoMinimo = static_cast<int>(texto.length()) + 4;

    // Si el usuario pide un ancho demasiado pequeno,
    // usamos automaticamente el minimo necesario.
    if (ancho < anchoMinimo)
    {
        ancho = anchoMinimo;
    }


    int espacioInterior = ancho - 2;

    int espaciosDisponibles =
        espacioInterior - static_cast<int>(texto.length());

    int espaciosIzquierda = espaciosDisponibles / 2;

    int espaciosDerecha =
        espaciosDisponibles - espaciosIzquierda;


    std::cout << std::string(ancho, '=') << std::endl;

    std::cout
        << "="
        << std::string(espaciosIzquierda, ' ')
        << texto
        << std::string(espaciosDerecha, ' ')
        << "="
        << std::endl;

    std::cout << std::string(ancho, '=') << std::endl;
}


void ConsoleUI::PrintColor(std::string texto, int codigoColor)
{
    std::cout
        << "\033[" << codigoColor << "m"
        << texto
        << "\033[" << COLOR_RESET << "m"
        << std::endl;
}


void ConsoleUI::PrintSuccess(std::string texto)
{
    PrintColor(texto, COLOR_GREEN);
}


void ConsoleUI::PrintError(std::string texto)
{
    PrintColor(texto, COLOR_RED);
}


void ConsoleUI::PrintSeparator()
{
    std::cout << std::string(40, '-') << std::endl;
}


void ConsoleUI::PrintList(int* arreglo, int tamanio)
{
    std::cout << "ID\tDATO" << std::endl;

    PrintSeparator();

    for (int i = 0; i < tamanio; i++)
    {
        std::cout
            << i
            << "\t"
            << arreglo[i]
            << std::endl;
    }
}


void ConsoleUI::PrintText(std::string texto)
{
    std::cout << texto << std::endl;
}


void ConsoleUI::PrintNode(int id, int dato)
{
    std::cout
        << id
        << "\t"
        << dato
        << std::endl;
}



void ConsoleUI::Pause()
{
    PrintText("Presiona una tecla para continuar...");

    _getch();
}


void ConsoleUI::ClearScreen()
{
    std::system("cls");
}