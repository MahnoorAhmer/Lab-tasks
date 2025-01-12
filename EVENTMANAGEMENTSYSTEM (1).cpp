#include <iostream>
#include <string>
#include <windows.h> 
using namespace std;
#define RESET   "\033[0m"
#define MAGENTA "\033[35m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define BLUE    "\033[34m"
struct Venue{
    string name;
    string location;
};
struct Event{
    string name;
    string date;
    string time;
    Venue venue; 
};
struct Attendee 
{   string name;
    string contact;
    string city;
    Event* event;  
};
Venue venues[10];
Event events[10];
Attendee attendees[20];
int venueCount=0,eventCount=0,attendeeCount=0;
    void addVenue() {
    if(venueCount>=10){
    cout<<RED<<"Cannot add more venues. Maximum limit reached.\n"<<RESET;
    return;
    }
    cout<<"Enter venue name: ";
    cin.ignore();
    getline(cin,venues[venueCount].name);
    cout<<"Enter venue location: ";
    getline(cin,venues[venueCount].location);
    venueCount++;
    cout<<GREEN<<"Venue added successfully.\n"<<RESET;
}
    void viewVenues() {
    if(venueCount==0) {
        cout<<RED<<"No venues to display.Please add a venue first.\n"<<RESET;
        return;
    }
    cout<<"Venues List:\n";
    for(int i=0;i<venueCount;i++) {
        cout<<i + 1<<". "<<"Venue Name: "<<venues[i].name<<",Location: "<<venues[i].location<<endl;
    }
}
    void updateVenue() {
    if(venueCount==0) {
        cout<<RED<<"No venues available.Please add a venue first.\n"<<RESET;
        return;
    }
	int id;
    cout<<"Enter venue ID to update(1 to "<<venueCount << "): ";
    cin>>id;
    if(id<1||id>venueCount){
    cout<<RED<<"Invalid venue ID.\n"<<RESET;
        return;
    }
    cout<<"Enter new venue name: ";
    cin.ignore();
    getline(cin,venues[id-1].name);
    cout<<"Enter new venue location: ";
    getline(cin,venues[id-1].location);
    cout<<GREEN<<"Venue updated successfully.\n"<<RESET;
}
    void deleteVenue() {
    if(venueCount==0){
        cout<<RED<<"No venues available.Please add a venue first.\n" << RESET;
        return;
    }

    int id;
    cout<<"Enter venue ID to delete (1 to " << venueCount << "): ";
    cin>>id;
    if(id<1||id>venueCount) {
        cout<<RED<<"Invalid venue ID.\n"<<RESET;
        return;
    }
    for(int i=id-1;i<venueCount-1;i++) {
        venues[i]=venues[i+1];
    }
    venueCount--;
    cout<<GREEN<<"Venue deleted successfully.\n"<<RESET;
}
    void addEvent(){
    if(eventCount>=10) {
        cout<<RED<<"Cannot add more events. Maximum limit reached.\n"<<RESET;
        return;
    }
    if(venueCount==0) {
	cout<<RED<<"No venues available.Please add a venue first.\n"<<RESET;
        return;
    }
    cout<<"Enter event name: ";
    cin.ignore();
    getline(cin,events[eventCount].name);
    cout<<"Enter event date: ";
    getline(cin, events[eventCount].date);
    cout<<"Enter event time: ";
    getline(cin, events[eventCount].time);

    cout<<"Available venues:\n";
    for(int i=0;i<venueCount;i++) {
        cout<<i+1<<". "<<venues[i].name<<" - "<<venues[i].location<<endl;
    }
    cout<<"Choose a venue by number: ";
    int venueChoice;
    cin>>venueChoice;

    if(venueChoice>=1&&venueChoice<=venueCount) {
        events[eventCount].venue=venues[venueChoice-1];
        eventCount++;
        cout<<GREEN<<"Event added successfully.\n"<<RESET;
    } else {
        cout<<RED<<"Invalid venue choice.\n"<<RESET;
    }
}
    void viewEvents() {
    if(eventCount == 0) {
        cout<<RED<< "No events to display. Please add an event first.\n"<<RESET;
        return;
    }
    cout << "Events List:\n";
    for(int i=0; i<eventCount; i++) {
        cout<<i + 1<< ". " <<"Event Name: " <<events[i].name << ", Date: " <<events[i].date
             <<", Time: "<< events[i].time <<", Venue: "<< events[i].venue.name << " - " << events[i].venue.location <<endl;}
}


void updateEvent() {
    if(eventCount==0) {
        cout<<RED<<"No events available. Please add an event first.\n" <<RESET;
        return;}

    int id;
    cout<<"Enter event ID to update (1 to " << eventCount << "): ";
    cin>>id;
    if(id<1 || id>eventCount) {
        cout << RED <<"Invalid event ID.\n" <<RESET;
        return;}
    cout<<"Enter new event name: ";
    cin.ignore();
    getline(cin,events[id - 1].name);
    cout<< "Enter new event date: ";
    getline(cin,events[id - 1].date);
    cout<< "Enter new event time: ";
    getline(cin,events[id - 1].time);
    cout<<GREEN<< "Event updated successfully.\n" <<RESET;
}


void deleteEvent() {
    if(eventCount==0) {
    cout<<RED<<"No events available. Please add an event first.\n"<<RESET;
    return;
    }

    int id;
    cout<<"Enter event ID to delete (1 to "<<eventCount<<"): ";
    cin>>id;
    if(id<1 || id>eventCount) {
    cout <<RED<<"Invalid event ID.\n" <<RESET;
    return;
    }
    for(int i=id-1; i<eventCount-1; i++) {
        events[i]=events[i + 1];
    }
    eventCount--;
    cout<<GREEN<<"Event deleted successfully.\n"<<RESET;
}


void addAttendee(){
    if(attendeeCount>=20) {
        cout<<RED<<"Cannot add more attendees.Maximum limit reached.\n"<<RESET;
        return;
    }
    if(eventCount==0) {
        cout<<RED<<"No events available.Please add an event first.\n"<<RESET;
        return;
    }

    cout<<"Enter attendee name: ";
    cin.ignore();
    getline(cin,attendees[attendeeCount].name);
    cout<< "Enter attendee contact: ";
    getline(cin,attendees[attendeeCount].contact);
    cout<< "Enter attendee city: ";
    getline(cin,attendees[attendeeCount].city);

    cout<<"Available events:\n";
    for(int i=0; i<eventCount; i++) {
        cout << i + 1 <<". " <<events[i].name <<" on "<<events[i].date<<" at "<<events[i].time<<endl;
    }
    cout<<"Choose an event by number: ";
    int eventChoice;
    cin>>eventChoice;

    if(eventChoice>=1 && eventChoice<=eventCount) {
        attendees[attendeeCount].event = &events[eventChoice - 1];
        attendeeCount++;
        cout <<GREEN<<"Attendee added successfully.\n" << RESET;
    } else {
        cout <<RED<<"Invalid event choice.\n" << RESET;
    }
}

void viewAttendees() {
    if(attendeeCount==0) {
        cout <<RED<< "No attendees registered. Please add an attendee first.\n"<<RESET;
        return;
    }
    cout<<"Attendees List:\n";
    for (int i=0; i<attendeeCount; i++) {
        cout <<"Name: "<<attendees[i].name <<", Contact: "<<attendees[i].contact
             <<", City: "<<attendees[i].city <<", Event: " <<attendees[i].event->name<<endl;
    }
}


void deleteAttendee(){
    if(attendeeCount==0) {
        cout<<RED<< "No attendees available. Please add an attendee first.\n"<<RESET;
        return;
    }

    int id;
    cout<<"Enter attendee ID to delete (1 to "<<attendeeCount <<"): ";
    cin>>id;
    if(id<1||id>attendeeCount){
    cout<<RED<<"Invalid attendee ID.\n"<<RESET;
    return;
    }
    for(int i=id-1; i<attendeeCount-1; i++) {
    attendees[i]=attendees[i + 1];
    }
    attendeeCount--;
    cout<<GREEN<< "Attendee deleted successfully.\n" << RESET;
}

int main(){
	cout<<"\n\n\n\n\n\n\n\n\n";
	cout<<"\t\t\t\tLoading";
	char x=219;
	for(int i=0;i<35;i++){
		cout<<x; 
		if(i<10){
		Sleep(300);
	}
        if(i>-10 && i<20){
        Sleep(158);
    }
        if(i>-10){
		Sleep(25);
    }
    
}
system("cls");
    int choice;
    do {
    	cout<<MAGENTA<<"-------------------------------------------------------------------------------\n ";
        cout<<MAGENTA<<"    -----------------------Event Management System-----------------------\n";
        cout<<MAGENTA<<"-------------------------------------------------------------------------------\n"<<RESET;
        cout<<"1. Add Venue\n";
        cout<<"2. View Venues\n";
        cout<<"3. Update Venue\n";
        cout<<"4. Delete Venue\n";
        cout<<"5. Add Event\n";
        cout<<"6. View Events\n";
        cout<<"7. Update Event\n";
        cout<<"8. Delete Event\n";
        cout<<"9. Add Attendee\n";
        cout<<"10.View Attendees\n";
        cout<<"11.Delete Attendee\n";
        cout<<"12.Exit\n";
        cout<<"Enter your choice: " ;
        cin>>choice;
        switch (choice) {
            case 1: 
			addVenue(); 
			break;
            case 2: 
			viewVenues(); 
			break;
            case 3: 
			updateVenue(); 
			break;
            case 4: 
			deleteVenue(); 
			break;
            case 5: 
			addEvent(); 
			break;
            case 6: 
			viewEvents(); 
			break;
            case 7: 
			updateEvent(); 
			break;
            case 8: 
			deleteEvent(); 
			break;
            case 9: 
			addAttendee(); 
			break;
            case 10: 
			viewAttendees(); 
			break;
            case 11: 
			deleteAttendee(); 
			break;
            case 12:cout<<MAGENTA<<"Exiting program.\n"<<RESET;
			break;
            default:cout<<RED<<"Invalid choice,please try again.\n"<<RESET;
        }
}     while (choice!=12);
      return 0;
}

