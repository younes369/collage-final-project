#include<string>
#include<vector>
using namespace std;



bool check_number(string);
string gen_random(const int);

struct Client
{
	string status,address,name,id,age,ID,number,stayingTime,bookedRoom;
};
struct Rooms
{
	int roomNumber;
	string roomType;
	bool Availability;
	time_t startReservation, endReservation;
};


class Hotel{
public:
	vector <Client> clients;
	vector <Rooms> room;

    Client Registration();
    void Booking(Client& TempClient);
    void canclling(Client& TempClient);
};
