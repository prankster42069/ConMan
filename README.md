Tested working on Visual Studio 2019.
It seems like the colors in the terminal don't make Code::Blocks happy. Removing and/or modifying everything regarding color might make it work.

# ConMan
A minimalistic and efficient contact manager (ConMan for short). 
This project is also aimed at making me more fluent and comfortable with C++ programming.

## Overview
ConMan is entirely terminal-based. It works with shortcuts to the main functionalities.

For example, pressing [n] in the main menu lets you directly create a new contact.
Efficient, isn't it?

You don't even have to press Enter!

The motto of ConMan is never to let you press a key you don't absolutely have to press.


## Main functionalities
### - List contacts
### - New contact
This function allows you to create new contacts (it's a contact manager after all).

It takes the provided fields in the [fields/fields.txt] file and ask for user entry for each of them.

### - Edit contact
### - Delete contact
### - Search contact
### - Settings

## Let's get deeper

### File and folder structure
- [interface] folder contains every text file regarding interface.
- [config] folder contains every configuration file, if you don't want to configure everything from the app itself.
- [database] folder contains the contact database. You get a file containing ALL contacts, and one file per contact.

### Config file
Detailling the config file.
