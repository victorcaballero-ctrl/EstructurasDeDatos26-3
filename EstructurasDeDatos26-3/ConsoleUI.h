#pragma once

#include <string>

class ConsoleUI
{
public:

    // Codigos ANSI
    static const int COLOR_RESET;
    static const int COLOR_RED;
    static const int COLOR_GREEN;
    static const int COLOR_YELLOW;
    static const int COLOR_BLUE;
    static const int COLOR_MAGENTA;
    static const int COLOR_CYAN;
    static const int COLOR_WHITE;

    static void PrintTitle(std::string texto);

    static void PrintTitle(std::string texto, int ancho);

    static void PrintColor(std::string texto, int codigoColor);

    static void PrintSuccess(std::string texto);

    static void PrintError(std::string texto);

    static void PrintSeparator();

    static void PrintList(int* arreglo, int tamanio);

    static void Pause();

    static void ClearScreen();


    // Metodos auxiliares
    static void PrintText(std::string texto);

    static void PrintNode(int id, int dato);
};