#include<iostream>
#include<cmath>

#define MAX 100

using namespace std;

// Input resistors and voltage, output power and intensity

class SerialCircuit {
	private:
		
		double totalResistance;
		
		void calcTotalResistance(double resistors[], int n){
			totalResistance = 0;
			
			for(int i=0; i<n; i++){
				totalResistance += resistors[i];
			}
		}
	
		double calcPower(double current, double resistance){
			double res;
			
			res = pow(current, 2) * resistance;
			return res;
		}
		
	public:
		
		double calcCurrent(double voltage, double resistors[], int n){
			double res;
			calcTotalResistance(resistors, n);
			
			res = voltage/totalResistance;
			return res;
		}
		
		void listWattages(double current, double resistors[], int n){
			double power;
			
			for(int i=0; i<n; i++){
				power = calcPower(current, resistors[i]);
				
				cout << "Resistor " << i+1 << " --> " << power << " W" << endl;
			}
		}
};

int main(){
	
	int resistorNum;
	double voltage, resistorValues[MAX], current;
	
	cout << "Enter this circuit's voltage: " << endl;
	cin >> voltage;
	
	cout << "Now, indicate the number of resistors: " << endl;
	cin >> resistorNum;
	
	for(int i = 0; i<resistorNum; i++){
		cout << "Resistor " << i+1 << "'s Ohms: " << endl;
		cin >> resistorValues[i];
	}
	
	SerialCircuit circuit1;
	
	current = circuit1.calcCurrent(voltage, resistorValues, resistorNum);
	
	cout << "This circuit's current is " << current << " Amperes" << endl;
	cout << "These are the resistor's respective values in Watts: " << endl;
	
	circuit1.listWattages(current, resistorValues, resistorNum);
}