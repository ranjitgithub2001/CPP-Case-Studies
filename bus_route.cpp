#include <iostream>
using namespace std;

int main()
{
	char city_names[9] = "ABCDEFGH";
	int distances[8] = {800, 1200, 2400, 400, 700, 650, 500, 6500};
	int startPoint, endPoint, totalDistance=0;
	float fareRate = 25, totalFare;
	cout<<"Following are the stop names: ";
	for(int i=0;i<8;i++){
		cout<<"\n"<<i+1<<". "<<city_names[i]<<endl;
	}
	cout<<"Enter the Start point: ";
	cin>>startPoint;
	cout<<"Enter the End point: ";
	cin>>endPoint;
	startPoint--;
	endPoint--;
	if(startPoint==endPoint){
		cout<<"You are already at your destination"<<endl;
	}
	else{
	
	if (startPoint < endPoint) {
        for (int i=startPoint;i<endPoint;i++) {
            totalDistance += distances[i];
        }
    } else {
        for (int i=startPoint;i!=endPoint;i=(i + 1)%8) {
            totalDistance += distances[i];
        }
    }
		
	totalFare = (totalDistance/1000.0) * fareRate;
	
	cout<<"Total distance: "<<totalDistance;
	cout<<"\nTotal Travel fare: "<<totalFare;
	}
}
