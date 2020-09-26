// ContactMan.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>

using namespace std;

string VERSION = "0.2alpha";

string COLOR_WELCOME = "lightblue";
string COLOR_QUOTE = "green";
string COLOR_VERSION = "yellow";
string COLOR_MENU = "green";


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
char submenu(char userInput);
void message(string message);

void listContacts();
void newContact();
void editContact();
void deleteContact();
void searchContact();
void settings();
void quit();
void wrongKey();

void addTextToFile(string fichier, string chaine);

int main()
{
    char userInput = 'Z';
    char output = 'Z';

    welcome();
    version();
    space();

    do
    {
        space();
        menu();
        space();

        userInput = input();
        output = submenu(userInput);
    } while (output != 'q');
}

//affiche le message de bienvenue
void welcome()
{
    color(test_displayTextFile("interface/welcome.txt"),COLOR_WELCOME);
    color(test_displayTextFile("interface/random_quote.txt"), COLOR_QUOTE);
}

//affiche la version de CM
void version()
{
    //utilise le string constant 'VERSION', d�clar� avant le main
    color("Version: ", COLOR_VERSION);
    color(VERSION, COLOR_VERSION);
}

//affiche le menu qui liste les commandes possibles
void menu()
{
    color("=======MAIN MENU=======", "purple");
    space();
    displayTextFile("interface/menu.txt");
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

//capte les inputs de l'utilisateur, retourne un char si la lettre entr�e est correcte
char input()
{
    //bool�en qui devient true si l'entr�e est bien une des lettres attendues
    int a = 0;

    //letter est initialis� � 'Z' pour la boucle while, qui s'interrompt si letter != 'Z'
    char letter = 'Z';

    do
    {
        a = _getch();
        if (a == 'l' || a == 'L')
        {letter = 'l';}
        else if (a == 'n' || a == 'N')
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
        else if (a == 'y' || a == 'Y')
        {letter = 'y';}
        else
        {letter = a;}

    } while (letter == 'Z');

    return letter;
}


//fonction qui saute des lignes dans la console
//'a' est le nombre de lignes � sauter
//par d�faut, saute une seule ligne
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

//reli� � welcome pour afficher l'ascii art
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
    cout << Art;
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
//premier argument = texte � colorer
//deuxi�me argument = couleur � adopter
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
    //autres couleurs � ajouter

    cout << "\033[" << i << "m" << chaine << "\033[0m";
}

//aiguille vers la bonne fonction en fonction de la lettre entr�e
char submenu(char userInput)
{
    bool cont = true;
    char answer = 'Z';

        switch (userInput)
        {
        case 'l':
            listContacts();
            break;
        case 'n':
            newContact();
            break;
        case 'e':
            editContact();
            break;
        case 'd':
            deleteContact();
            break;
        case 'f':
            searchContact();
            break;
        case 's':
            settings();
            break;
        case 'q':
            answer = 'q';
            quit();
            break;
        default:
            wrongKey();
            cont = false;
            break;
        }

    return answer;
}

void listContacts()
{
    space();
    color("BEGINNING OF THE LIST", "green");
    displayTextFile("database/contact_list.txt");
    color("END OF THE LIST", "green");
}

//fonction pour cr�er un nouveau contact
void newContact()
{
    bool ok = false;

    do {
        color("======NEW CONTACT======", "green");
        space();

        bool firstSpace = true;
        bool secondSpace = true;

        string field1, field2;

        string current_field = "";
        string answer = "";
        string rapport = "";

        //pr�l�vement des champs dans le fichier 'fields'
        string fields = test_displayTextFile("fields/fields.txt");

        for (int i = 0; i < fields.length(); i++)
        {
            if (fields[i] == 32 || i == fields.length() - 1) //si la boucle rencontre un espace
            {
                cout << "[" << current_field << "]" << "?" << endl;

                getline(cin, answer);

                rapport += current_field;
                rapport += " : ";
                rapport += answer;
                rapport += "\n";

                //pr�l�vement des deux premiers champs pour les inclure dans le nom du fichier
                if (firstSpace == true)
                {
                    field1 = answer;
                    firstSpace = false;
                }
                else if (secondSpace == true)
                {
                    field2 = answer;
                    secondSpace = false;
                }

                //r�initialisation r�ponse & champ une fois la r�ponse rentr�e
                current_field = "";
                answer == "";
            }
            else
            {
                current_field += fields[i];
            }
        }

    space();
    color("=====CONTACT FILE=====","yellow");
    space();
    message(rapport);
    color("Is everything ok?[y/n/q]","red");
    space();

    char userInput;
    userInput = input();
    if (userInput == 'y')
    {
        ok = true;

        string filename = "database/" + field1 + " " + field2 + ".txt";
        ofstream MyFile(filename);
        
        string existing_file;
        MyFile << rapport;
        MyFile.close();

        //ajout du nom du contact � la liste des contacts 'contact_list.txt'
        addTextToFile("database/contact_list.txt", field1 + " " + field2 + "\n");

        color("CONTACT CREATED!","green");
    }
    else if (userInput == 'n')
    {message("Let's start from the beginning, shall we?");}
    else if (userInput == 'q')
    {ok = true;}

    } while (ok == false);
}

void editContact()
{

}

void deleteContact()
{

}

void searchContact()
{

}

void settings()
{
    space();

    char userInput = 'Z';
    char output = 'Z';

    color(test_displayTextFile("interface/settings_logo.txt"),"red");
    space();
    
    displayTextFile("interface/settings_menu.txt");

    while (userInput != 'q')
    {
        userInput = input();
    }

    color("EXITING SETTINGS MENU","red");
    //param�tres � d�finir

}

void quit()
{
    color(test_displayTextFile("interface/bye.txt"),"red");
}

void wrongKey()
{
    message("WRONG KEY!");
}

//affiche simplement un message
//permet de s'�viter de taper cout blablabla � chaque fois
void message(string message)
{
    cout << message << endl;
}


void addTextToFile(string fichier, string chaine)
{
    ofstream fout;
    ifstream fin;
    fin.open("database/contact_list.txt");
    fout.open("database/contact_list.txt", ios::app);
    if (fin.is_open())
        fout << chaine;
    fin.close();
    fout.close();
    string word;
}