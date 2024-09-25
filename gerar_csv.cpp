#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>  
#include <ctime>    

std::string addMinutes(const std::string& time, int minutes) {
    int hours = std::stoi(time.substr(0, 2));
    int mins = std::stoi(time.substr(3, 2));

    mins += minutes;

    if (mins >= 60) {
        hours += mins / 60;
        mins = mins % 60;
    } else if (mins < 0) {
        hours += (mins / 60) - 1;
        mins = 60 + (mins % 60);
    }

    char result[6];
    std::sprintf(result, "%02d:%02d", hours, mins);
    return std::string(result);
}


int differenceMinutes(const std::string& start, const std::string& end) {
    int startHours = std::stoi(start.substr(0, 2));
    int startMinutes = std::stoi(start.substr(3, 2));
    int endHours = std::stoi(end.substr(0, 2));
    int endMinutes = std::stoi(end.substr(3, 2));

    int startTotalMinutes = startHours * 60 + startMinutes;
    int endTotalMinutes = endHours * 60 + endMinutes;

    return endTotalMinutes - startTotalMinutes;
}

int main(int argc, char* argv[]) {
    
    if (argc != 3 || std::string(argv[1]) != "--amount-days") {
        std::cerr << "Usage: ./generate_csv --amount-days <number_of_days>\n";
        return 1;
    }

    int days = std::stoi(argv[2]);
    std::srand(std::time(0));
    std::string filename = "spreadsheet.csv";
    std::ofstream csvFile(filename);
    
    if (!csvFile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return 1;
    }
    
    csvFile << "day,start,interval,return,end\n";

    std::string baseStart = "09:00";
    std::string baseInterval = "12:00";
    std::string baseReturn = "13:30";
    int workdayDuration = 8 * 60; 

    
    for (int i = 1; i <= days; ++i) {
        
        int startVariation = (std::rand() % 21) - 10;   
        int intervalVariation = (std::rand() % 21) - 10;
        int returnVariation = (std::rand() % 21) - 10;

        std::string start = addMinutes(baseStart, startVariation);
        std::string interval = addMinutes(baseInterval, intervalVariation);
        std::string returnTime = addMinutes(baseReturn, returnVariation);

        int lunchDuration = differenceMinutes(interval, returnTime); 

        int morningDuration = differenceMinutes(start, interval); 
        int afternoonDuration = workdayDuration - morningDuration; 

        std::string end = addMinutes(returnTime, afternoonDuration);

        csvFile << "Day " << i << "," << start << "," << interval << "," << returnTime << "," << end << "\n";
    }

    
    csvFile.close();

    std::cout << "CSV spreadsheet generated successfully: " << filename << std::endl;

    return 0;
}
