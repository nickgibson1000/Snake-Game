# Snake Game

## **Overview**
A simple implementation of the game Snake in C. It utilizes the ncurses as a TUI (Text-User Interface) for realtime game updates.

## **Installation & Setup**
**NOTICE: This project was developed and tested on WSL (Windows Subsystem for Linux). The following instructions are tailored for this environment but should work on most Linux distributions.**

**I highly recommend setting up WSL (Windows Subsystem for Linux) to run this project. WSL is a lightweight Linux enviroment within windows, utilizing the Ubuntu distribution, making it easier to install and use tools like ncurses. Below is a link to the WSL page for download.**

[DOWNLOAD WSL](https://learn.microsoft.com/en-us/windows/wsl/install)

To get started follow the steps below:

1. **Install ncurses**
```sh
sudo apt-get install libncurses5-dev libncursesw5-dev
```
Note: libncursesw5-dev is included for wide-character support, enabling the use of unicode and multibyte characters. (eg: emojis, currency symbols, "|" etc...).

2. **Compile & Run**
```sh
make
```
Utilizing a makefile this will compile all neccessary c source files into a single object file.

```sh
./snake
```
This will execute our object file and run the program.


**For VScode Users**
If you wish too create your own projects with ncurses I suggest remotely running WSL inside of the IDE. However, in-order for VScode too recognize the ncurses library you will need to update your C/C++ properties file. This can be done as follows...

1. Open the command pallete by pressing **ctrl + shift + p** or by navigating to the settings icon in the bottom left, it should appear at the top of the menu.

2. Enter ``` C/C++: Edit Configurations (JSON) ``` and open the file.
 
3. Under ```includePath``` add in this line somewhere in between its brackets ```"/usr/local/include",```. This is the default location for manually installed headers, so its neccessary for VScode to have access to this directory as it is where the ncurses header is stored.

4. Save the file and start programming!


