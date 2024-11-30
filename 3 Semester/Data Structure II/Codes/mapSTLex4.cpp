// Author: reDragonCoder

//LIBRARIES
#include <iostream>
#include <iterator>
#include <list>
#include <map>

//NAMESPACE
using namespace std;

//CLASS
class Date{
    private:
        int dd;
        int mm;
        int yy;

    public:
        Date(int dd, int mm, int yy){
            this->dd=dd;
            this->mm=mm;
            this->yy=yy;
        }

        int getDay(){
            return dd;
        }

        int getMonth(){
            return mm;
        }

        int getYear(){
            return yy;
        }

        void setDay(int day){
            this->dd=day;
        }

        void setMonth(int month){
            this->mm=month;
        }

        void setYear(int year){
            this->yy=year;
        }

        bool operator<(const Date &tempDate) const{
            if(this->yy==tempDate.yy){
                if(this->mm==tempDate.mm){
                    return this->dd<tempDate.dd;
                }else{
                    return this->mm<tempDate.mm;
                }
            }else{
                return this->yy<tempDate.yy;
            }
        }

        bool operator==(const Date &tempDate) const{
            if(this->yy==tempDate.yy){
                if(this->mm==tempDate.mm){
                    if(this->dd==tempDate.dd){
                        return true;
                    }
                }
            }
            return false;
        }
};

class Hour{
    private:
        int hour;
        int minutes;
    
    public:
        Hour(int hour, int minutes){
            this->hour=hour;
            this->minutes=minutes;
        }

        int getHour(){
            return hour;
        }

        int getMinutes(){
            return minutes;
        }

        void setHours(int hh){
            this->hour=hh;
        }

        void setMinutes(int mm){
            this->minutes=mm;
        }

        bool operator<(const Hour &tempHour) const{
            if(this->hour==tempHour.hour){
                return this->minutes<tempHour.minutes;
            }else{
                return this->hour<tempHour.hour;
            }
        }

        bool operator==(const Hour &tempHour) const{
            if(this->hour==tempHour.hour){
                if(this->minutes==tempHour.minutes){
                    return true;
                }
            }
            return false;
        }
};

class Agenda{
    private:
        map<Date, map<Hour, string>> classMap;

    public:
        void insertEvent(const Date &date, const Hour &hour, const string &description){
            classMap[date][hour]=description;
        }

        list<pair<Hour, string>> dayEvent(const Date &date){
            list<pair<Hour, string>> tempList;
            auto it=classMap.find(date);

            if(it!=classMap.end()){
                const map<Hour, string> &events=it->second;
                for(const auto &event:events){
                    tempList.push_back(event);
                }
            }

            return tempList;
        }

        list<pair<Hour, string>> eventsDay(const Date &date, const Hour &from, const Hour &to){
            list<pair<Hour, string>> tempList;
            
            auto it=classMap.find(date);
            if(it!=classMap.end()){
                const map<Hour, string> &events=it->second;

                for(const auto &event:events){
                    const Hour &eventHour=event.first; 

                    if((from<eventHour || eventHour==from) && (eventHour<to || eventHour==to)){
                        tempList.push_back(event);
                    }  
                }            
            }

            return tempList;
        }

        void deleteEvents(const Date &from_date, const Hour &from_hour, const Date &to_date, const Hour &to_hour){
            for(auto it = classMap.lower_bound(from_date); it!=classMap.end(); it++){
                const Date &currentDate = it->first;
                if(to_date<currentDate) break; 

                auto &hourMap=it->second;

                for(auto hourIt=hourMap.lower_bound(from_hour); hourIt!=hourMap.end(); hourIt++){
                    const Hour &currentHour=hourIt->first;

                    if(currentDate==to_date && to_hour<currentHour) break; 

                    if(currentDate==from_date && currentHour<from_hour) continue;
                    if(currentDate==to_date && to_hour<currentHour) continue; 

                    hourIt=hourMap.erase(hourIt); 
                    if(hourMap.empty()) {
                        classMap.erase(it); 
                        break;
                    }
                }
            }
        }

};

//MAIN
int main() {
    Agenda agenda;

    //Insert events
    cout<<"Inserting events..."<<endl;
    agenda.insertEvent(Date(29, 11, 2024), Hour(9, 30), "Event 1");
    agenda.insertEvent(Date(29, 11, 2024), Hour(10, 30), "Event 2");
    agenda.insertEvent(Date(29, 11, 2024), Hour(12, 0), "Event 3");
    agenda.insertEvent(Date(30, 11, 2024), Hour(9, 30), "Event 4");
    agenda.insertEvent(Date(30, 11, 2024), Hour(11, 0), "Event 5");

    //Get events for a specific day
    cout<<"\nEvents on 29/11/2024:"<<endl;
    list<pair<Hour, string>> events=agenda.dayEvent(Date(29, 11, 2024));
    for(auto event:events){
        cout<<"Event at "<<event.first.getHour()<<":"
            <<(event.first.getMinutes()<10?"0":"")<<event.first.getMinutes()<<" - "<<event.second<<endl;
    }

    //Get events within a specific time range
    cout<<"\nEvents on 29/11/2024 between 09:00 and 11:00:"<<endl;
    list<pair<Hour, string>> eventsRange=agenda.eventsDay(Date(29, 11, 2024), Hour(9, 0), Hour(11, 0));
    for(auto event : eventsRange){
        cout<<"Event at "<<event.first.getHour()<<":"
            <<(event.first.getMinutes()<10?"0":"")<<event.first.getMinutes()<<" - "<<event.second<<endl;
    }

    //Delete events within a time range
    cout<<"\nDeleting events between 29/11/2024 10:00 and 29/11/2024 12:00..."<<endl;
    agenda.deleteEvents(Date(29, 11, 2024), Hour(10, 0), Date(29, 11, 2024), Hour(12, 0));

    //Get events after deletion
    cout<<"\nEvents on 29/11/2024 after deletion:"<<endl;
    events=agenda.dayEvent(Date(29, 11, 2024));
    for(auto event:events){
        cout<<"Event at "<<event.first.getHour()<<":"
            <<(event.first.getMinutes()<10?"0":"")<<event.first.getMinutes()<<" - "<<event.second<< endl;
    }

    //Delete events spanning multiple days
    cout<<"\nDeleting events between 29/11/2024 09:30 and 30/11/2024 10:30..."<<endl;
    agenda.deleteEvents(Date(29, 11, 2024), Hour(9, 30), Date(30, 11, 2024), Hour(10, 30));

    //Get events after deleting across multiple days
    cout<<"\nEvents on 29/11/2024 after deletion across multiple days:" << endl;
    events=agenda.dayEvent(Date(29, 11, 2024));
    for(auto event:events) {
        cout<<"Event at " << event.first.getHour()<<":"
            << (event.first.getMinutes()<10?"0":"")<<event.first.getMinutes()<<" - "<<event.second<<endl;
    }

    cout<<"\nEvents on 30/11/2024 after deletion across multiple days:"<<endl;
    events=agenda.dayEvent(Date(30, 11, 2024));
    for(auto event:events){
        cout<<"Event at "<<event.first.getHour()<<":"
            <<(event.first.getMinutes()<10?"0":"")<<event.first.getMinutes()<<" - "<<event.second<<endl;
    }

    return 0;
}