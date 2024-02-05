#include<iostream>
#include<cmath>

#define MAX 100

using namespace std;

// Input resistors and voltage, output power and intensity

int main(){
	
	int resistorNum;
	double voltage, resistorValues[MAX];
	
	cout << "Enter this circuit's voltage: " << endl;
	cin >> voltage;
	
	cout << "Now, indicate the number of resistors: " << endl;
	cin >> resistorNum;
	
	for(int i = 0; i<resistorNum; i++){
		cout << "Resistor " << i+1 << "'s Ohms: " << endl;
		cin >> resistorValues[i];
	}
	
}