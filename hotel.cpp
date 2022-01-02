#include "hotel.h"
#include <iostream>

	Client Hotel::Registration(){
		Client TempClient;
		bool RegistrationDone = false;
		do
		{
			cout<< "please enter your name: ";
			cin>> TempClient.name; 
			if(check_number( TempClient.name)){
				cout<<"invalid input, please try again \n"; 
				continue;
			}			
			cout<< "please enter your age:  ";
			cin>> TempClient.age;
            if(!check_number( TempClient.age)){
				cout<<"invalid input, please try again \n"; 
				continue;
			}	
			cout<< "please enter your ID:  ";
			cin>> TempClient.ID;
            if(!check_number( TempClient.ID)){
				cout<<"invalid input, please try again \n"; 
				continue;
			}	
			cout<< "please enter your address:  ";
			cin>> TempClient.address;
			if(check_number( TempClient.address)){
				cout<<"invalid input, please try again \n"; 
				continue;
			}	 		
			cout<< "please enter your number:  ";
			cin>> TempClient.number;
            if(!check_number( TempClient.number)){
				cout<<"invalid input, please try again \n"; 
				continue;
			}	
			cout<< "please enter your status:  ";
			cin>> TempClient.status;
			if(check_number( TempClient.status)){
				cout<<"invalid input, please try again \n"; 
				continue;
			}
			cout<< "please enter the dauration you staying with us(In days):  ";
			cin>> TempClient.stayingTime;
            if(!check_number( TempClient.age)){
				cout<<"invalid input, please try again \n"; 
				continue;
			}	
			TempClient.id = gen_random(5);
			clients.push_back(TempClient);
			RegistrationDone = true;
		} while (!RegistrationDone);
		
		return TempClient;
	}

	void Hotel::Booking(Client& TempClient){
		string Broom;
		bool Done = false;


			do
			{
				for(int i =0; i< room.size(); i++ ){
					if(room[i].Availability == true)
					cout<< room[i].roomNumber <<"  "<<room[i].roomType << endl;
				}
				cout<<"please enter the room number you wish to book. \n";
				cin>> Broom;
                if(!check_number( Broom)){
                    cout<<"invalid input, please try again \n"; 
                    continue;
                }	
				for(int i =0; i< room.size(); i++ ){
					if(room[i].roomNumber == stoi(Broom)){
						char receiptPrinting;
						room[i].Availability = false;
						room[i].startReservation = time(0);
						room[i].endReservation = room[i].startReservation + (stoi(TempClient.stayingTime) * 24 * 60 * 60);
						TempClient.bookedRoom = Broom;
						for (int j = 0; j < clients.size(); j++)
						{
							if(clients[j].id == TempClient.id){
								clients[j].bookedRoom = Broom;
							}
						}
						
						cout<<"you have booked the room successfully. \n"; 
						cout<<"would you like to print a receipt(Y/N). \n";
						cin>>receiptPrinting;
						if(receiptPrinting == 'Y' || receiptPrinting == 'y'){
							cout<<"name: " << TempClient.name << "\n"<<"ID: "<<TempClient.ID << "\n" <<"staying time: "<< TempClient.stayingTime << endl;
							cout<< "booked room: "<< Broom << endl; 
							cout<<"starting time: "<<ctime(&room[i].startReservation)<<" ending time: "<<ctime(&room[i].endReservation);

						} 
						Done = true;
					}	
				}
				cout<<"you entered an inavlid room number \n";
			} while (!Done);


	
		
	}
	
	void Hotel::canclling(Client& TempClient){
		for (int j = 0; j < clients.size(); j++){
			if(clients[j].id == TempClient.id){
				clients[j].bookedRoom = "0";
				clients[j].stayingTime = "0";
				TempClient.bookedRoom = "0";
				TempClient.stayingTime = "0";
			}
		}

		cout<<"your room have been cancelled \n";
	}
