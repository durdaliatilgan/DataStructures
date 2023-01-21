#pragma GCC diagnostic ignored "-Wdeprecated"
#include <cstdlib>
#include <iostream> 
#include <conio.h> 
#include "ReadData.hpp"
#include "Organ.hpp"
#include "Display.hpp"
#include "Control.hpp"
void printInfo();

using namespace std;
ReadData *read=new ReadData("veriler2.txt");
Control conntrol;

int main()
{
	system("CLS");
	Display disp;
	printInfo();
	read->ReadLines();
	system("CLS");
	disp.printNodes(read->orgList);
    char letter;
    while (std::cin.get(letter)) {
        if (letter == '\n'){
			system("CLS");
			conntrol.controlMutationStatusAndUpdate(read->orgList);
			disp.printNodes(read->orgList);
		}
		else if(letter =='q')
			break;
		else{
			cout<<"wrong selection";
			cin.get(letter);
		}
    }
	read->~ReadData();
	delete read;
	return 0;
}
void printInfo(){
	
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<
	endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<
	"          	                   ORGANISM CREATING"<<endl;
}