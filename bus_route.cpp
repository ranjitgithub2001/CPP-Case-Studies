/*
 * City Travel Fare Calculator
 * 
 * This program calculates the total travel distance and fare between two cities.
 * 
 * Features:
 * - The program supports calculating the total distance and fare based on the selected start and end points.
 * - It uses a predefined list of city names and their corresponding distances to calculate the total distance.
 * - The fare rate is a constant value of 25 units per km.
 * 
 * How to Use:
 * - Run the program to see the list of city names and their respective numbers.
 * - Enter the start and end points by selecting the corresponding numbers.
 * - The program will calculate and display the total distance and travel fare.
 * 
 * Note:
 * - The distance between cities is predefined and stored in the 'distances' array.
 * - The fare rate is fixed at 25 units per km.
 * 
 * Author: Ranjit Kale 
 */

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
