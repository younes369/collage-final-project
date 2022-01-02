#include <iostream> //for using cin and cout
#include <fstream> // for reading from a file
#include <string> // for using string and getline()
#include <ctime>  // for using time
#include "hotel.h" 
using namespace std;




int main() {
	Client TempClient;
	Hotel HotelName;
	Rooms room1,room2,room3;
	int state =0, c = 0;
	room1.roomNumber = 55;
	room1.Availability = true;
	room1.roomType = "single";
	room2.roomNumber = 54;
	room2.Availability = true;
	room2.roomType = "single";
	room3.roomNumber = 53;
	room3.Availability = true;
	room3.roomType = "single";
	HotelName.room.push_back(room1);
	HotelName.room.push_back(room2);
	HotelName.room.push_back(room3);
	do
	{
		if (c == 0)
		{
			cout<<"welcome to our hotel!\n 1.if you are ready to registrare please press 1\n 2.if you want to exite press 2 \n";
			cin>> state;
			if(state == 2)
				break;
				
		}else{
			cout<<"welcome to our hotel!\n 1.if you are ready to make a new registrare please press 1\n 2.if you want to check your profile please press 2\n 3.if you want to ask for room service plese press 3 \n 4.if you want to cancel your room press 4 \n 5.if you want to exite press 5\n";
			cin>> state;
		}
		if (state == 1){
			TempClient = HotelName.Registration();
			HotelName.Booking(TempClient);
		}else if (state == 2)
		{
			cout<<"name: " << TempClient.name << "\n"<<"ID: "<<TempClient.ID << "\n" <<"staying time: "<< TempClient.stayingTime <<" days"<< "\n" <<"phone number: "<< TempClient.number << "\n" <<"booked room : "<< TempClient.bookedRoom<< "\n" <<"age : "<< TempClient.age<<" years" <<endl;
			for(int i =0; i< HotelName.room.size(); i++ ){
				if(stoi(TempClient.bookedRoom) == HotelName.room[i].roomNumber){
				cout<<"starting time: "<<ctime(&HotelName.room[i].startReservation)<<" ending time: "<<ctime(&HotelName.room[i].endReservation);
				}
			}

		}else if (state == 4){
			HotelName.canclling(TempClient);
		}

			
		c++;
		
	} while (state != 5);

	for(int i =0; i< HotelName.room.size(); i++ ){
		cout<< HotelName.room[i].roomNumber <<"  "<<HotelName.room[i].roomType <<"  " <<HotelName.room[i].Availability<< endl;
	}
	for(int i =0; i< HotelName.clients.size(); i++ ){
		cout<< HotelName.clients[i].name <<"  "<<HotelName.clients[i].bookedRoom <<"  " <<HotelName.clients[i].id<< endl;
	}

	time_t t = std::time(0);
	cout<< ctime(&t);

	return 0;
}


bool check_number(string str) {
   for (int i = 0; i < str.length(); i++) // initialize a loop to check every single char. in the string
   if (isdigit(str[i]) == false) // if any single char. in the string is not a number
      return false; // return false 
      return true; // else return true 
}


string gen_random(const int len) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"; // initialize all the char. used in the id
    string tmp_s; //initialize a variale called tmp_s from type string
    tmp_s.reserve(len); // reserving a number of bytes in the memory equal to the length of the id

    for (int i = 0; i < len; ++i) { // looping number of times equal to the length of the id each time adding a random char.
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    
    return tmp_s;
}