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
Note: libncursesw5-dev is included for wide-character support, enabling the use of unicode and multibyte characters. (eg: emojis, currency symbols, "|" etc...)


