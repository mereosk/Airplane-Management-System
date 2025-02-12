#include <iostream>
#include "general.h"
#include "planeComp.h"
#include "plane.h"
#include "employee.h"

using namespace std;

void cloneEncryptAndPrint(Object &ob){
	Plane *plane = dynamic_cast<Plane*>(ob.clone());
	int i;

	if(ob.equal(plane))										//If it is true
		cout<<endl<<"They are equal"<<endl;
	else
		cout<<endl<<"They are not equal"<<endl;

	if(ob.identical(*plane))										//If it is true
		cout<<endl<<"They are identical"<<endl<<endl;
	else
		cout<<endl<<"They are not identical"<<endl<<endl;

	String string1,string2;
	string1 = ob.toString();
	string2 = plane->toString();
	string1.print();
	string2.print();

	char tempChar,destChar;
	int tempPos,destPos;
	for(i=0 ; i<string2.length()/4 ; i++){							//Somewhat random
		tempPos = rand()%string2.length();
		tempChar = string2.at(tempPos);
		destPos = rand()%string2.length();
		destChar = string2.at(destPos);
		string2.updateAt(destPos,tempChar);
		string2.updateAt(tempPos,destChar);
	}
	cout<<endl<<"String 1 is:"<<endl<<endl;
	string1.print();
	cout<<endl<<"String 2 is:"<<endl<<endl;
	string2.print();

	cout<<endl<<"The concat string is:"<<endl<<endl;
	string1.concat(string2);
	string1.print();
	cout<<"The lenght of the string is "<<string1.length()<<endl;

	char temp;
	if(string1.length()&1 == 1){		//is odd
		temp = string1.at(string1.length()/2);
		cout<<"Middle character is: "<<temp<<endl;
	}
	else{		//is even
		cout<<"The 2 characters are: '";
		temp = string1.at(string1.length()/2-1);
		cout<<temp<<"' and '";
		temp = string1.at(string1.length()/2);
		cout<<temp<<"' "<<endl;
	}
	string1.clear();
	cout<<"The string after clear has "<<string1.length()<<" characters"<<endl;

	cout<<endl<<endl<<endl;
	delete plane;
}

int main() {
	srand(time(NULL));

	Plane p("Boeing 777",250);
	SecurityEmployee K("Kostas");
	MaintenanceEmployee E("Irene");
	CleaningEmployee B("Beatrice");

	p.process(&K);
	K.report();
	p.process(&E);
	E.report();
	p.process(&B);
	B.report();

	p.readyCheck();

	cloneEncryptAndPrint(p);

	cout<<endl<<"END OF MAIN"<<endl<<endl;
	return 0;
}
