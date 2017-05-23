#include <iostream>
#include <conio.h>
#include "TTable.h"
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	TTable table1(10);
	TRecord r1("S", 1);
	TRecord r2("M", 2);
	TRecord r3("N", 2);
	TRecord r4("L", 2);
	TRecord r5("z", 3);
	TRecord r6("x", 2);
	TRecord r7("y", 2);
	TRecord r8("e", 2);

	table1.AddRecord(r1);
	table1.AddRecord(r2);
	table1.AddRecord(r3);
	table1.AddRecord(r4);
	table1.AddRecord(r5);
	table1.AddRecord(r6);
	table1.AddRecord(r7);
	table1.AddRecord(r8);


	table1.Print();
	
	cout << endl<<"Запись с ключом \"N\": номер " << (table1.SeachRecord("N")+1) << endl;
	cout << "Запись с ключом \"e\": номер " << (table1.SeachRecord("e") + 1) << endl;
	
	cout <<endl<< "Оператор []:"<<endl;
	cout << table1["S"] << endl;
	cout << table1["N"] << endl;
	cout << table1["z"] << endl;
	
	table1.DelRecord("M");

	cout << endl;
	table1.Print();


	_getch();
	return 0;
}