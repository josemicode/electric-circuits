#include<iostream>
#include<vector>

using namespace std;

typedef struct Component{
	char type;
	double value;
};

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
}

int main(){
	
}