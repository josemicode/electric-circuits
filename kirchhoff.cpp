#include<iostream>
#include<vector>

using namespace std;

typedef struct{
	char type;
	double value;
}Component;

class ComplexCircuit{
	private:
	
		vector<Component> components;
		
	public:
		
		void addComponent(char type, double value){
			Component aux {type, value};
			
			components.push_back(aux);
		}
		
		double calcNodeCurrent(){
			double res = 0;
			
				for(const Component& comp : components){
					if(comp.type == 'R'){
						res += (1.0 / comp.value);
					}
				}
				
			return res;
		}
		
		double calcMeshTension(){
			double res = 0;
			
			for(const Component& comp : components){
				if(comp.type == 'V'){
					res += comp.value;
				}
			}
			
			return res;
		}
};

int main(){
	
	double value, nodeCurrent, meshTension;
	char choice;
	bool loop = true;
	
	ComplexCircuit cc;
	
	do{
		cout << "R = Resistor \nV = Voltage source \nD = Done entering components" << endl;
		cin >> choice;
	
		choice = toupper(choice);
		
		switch(choice){
			case 'R':
				cout << "\nValue in Ohms: ";
				cin >> value;
				
				cc.addComponent(choice, value);
				break;
			case 'V':
				cout << "\nValue in Volts: ";
				cin >> value;
				
				cc.addComponent(choice, value);
				break;
			case 'D':
				loop = false;
			default:
				cout << endl;
				break;
		}
	}while(loop);
	
	nodeCurrent = cc.calcNodeCurrent();
	meshTension = cc.calcMeshTension();
	
	cout << "This node's current is " << nodeCurrent << " A" << endl;
	cout << "This mesh's tension is " << meshTension << " V" << endl;
}