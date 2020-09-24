// ContactMan.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>

using namespace std;

string VERSION = "0.1alpha";

void welcome();
void version();
void menu();
char input();
void test_input();
void space(int a=1);

void color(string chaine, string color);

void displayTextFile(string a);
string test_displayTextFile(string a); //test de textdisplay pour qu'il retourne un string au lieu d'afficher avec cout

string getFileContents(ifstream&);

int main()
{
    welcome();
    version();
    space();
    menu();
}

//affiche le message de bienvenue
void welcome()
{
    color(test_displayTextFile("welcome.txt"),"lightblue");
}

//affiche la version de CM
void version()
{
    //utilise le string constant 'VERSION', déclaré avant le main
    color("Version: ", "green");
    color(VERSION, "green");
}

//affiche le menu qui liste les commandes possibles
void menu()
{
    displayTextFile("menu.txt");
}

void test_input()
{
    int a = 0;

    for (int i = 0; i < 10; i++)
    {
        a = _getch();
        cout << a << endl;
    }
}

//capte les inputs de l'utilisateur, retourne un char si la lettre entrée est correcte
char input()
{
    //booléen qui devient true si l'entrée est bien une des lettres attendues
    int a = 0;

    //letter est initialisé à 'Z' pour la boucle while, qui s'interrompt si letter != 'Z'
    char letter = 'Z';

    do
    {
        a = _getch();
        cout << a << endl;
        if (a == 'n' || a == 'N')
        {letter = 'n';}
        else if (a == 'e' || a == 'E')
        {letter = 'e';}
        else if (a == 'd' || a == 'D')
        {letter = 'd';}
        else if (a == 'f' || a == 'F')
        {letter = 'f';}
        else if (a == 's' || a == 'S')
        {letter = 's';}
        else if (a == 'q' || a == 'Q')
        {letter = 'q';}

    } while (letter == 'Z');
    cout << "DONE" << endl;

    return letter;
}


//fonction qui saute des lignes dans la console
//'a' est le nombre de lignes à sauter
//par défaut, saute une seule ligne
void space(int a)
{
    if (a > 0)
    {
        for (int i = 0;i < a;i++)
        {
            cout << endl;
        }
    }
}

//relié à welcome pour afficher l'ascii art
string getFileContents(ifstream& File)
{
    string Lines = "";        //All lines

    if (File)                      //Check if everything is good
    {
        while (File.good())
        {
            string TempLine;                  //Temp line
            getline(File, TempLine);        //Get temp line
            TempLine += "\n";                      //Add newline character

            Lines += TempLine;                     //Add newline
        }
        return Lines;
    }
    else                           //Return error
    {
        return "ERROR File does not exist.";
    }
}

//permet d'afficher le contenu d'un fichier texte dans le terminal
void displayTextFile(string a)
{
    ifstream Reader(a); // a est le nom du fichier, bien indiquer l'extension
    string Art = getFileContents(Reader);
    cout << Art << endl;
    Reader.close();
}

string test_displayTextFile(string a)
{
    ifstream Reader(a); // a est le nom du fichier, bien indiquer l'extension
    string Art = getFileContents(Reader);
    return Art;
    Reader.close();
}

//permet d'afficher un texte en couleur
//premier argument = texte à colorer
//deuxième argument = couleur à adopter

void color(string chaine, string color)
{
    int i = 0;

    // conversion du string color en int
    if (color == "red")
    {i = 31;}
    else if (color == "green")
    {i = 32;}
    else if (color == "yellow")
    {i = 33;}
    else if (color == "blue")
    {i = 34;}
    else if (color == "purple")
    {i = 35;}
    else if (color == "lightblue")
    {i = 36;}
    //il reste des couleurs à inclure

    cout << "\033[" << i << "m" << chaine << "\033[0m" << endl;
}