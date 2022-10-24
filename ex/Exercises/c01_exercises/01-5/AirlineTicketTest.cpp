import <iostream>;
import <format>;
import airline_ticket;

using namespace std;

int main()
{
	AirlineTicket myTicket;  // Stack-based AirlineTicket
	myTicket.setPassengerName("Sherman T. Socketwrench");
	myTicket.setNumberOfMiles(700);
	const double cost{ myTicket.calculatePriceInDollars() };
	cout << format("This ticket will cost ${}", cost) << endl;
} 
