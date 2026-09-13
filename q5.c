#include <stdio.h>
int main(){

    char vehicleType, userCategory, parkingPermit, emergencyVehicle;
    int zoneA, zoneB, zoneC;
    int totalProcessed, totalAccepted, totalRejected, carsParked, bikesParked, vansParked;

    zoneA = 0;
    zoneB = 0;
    zoneC = 0;

    totalProcessed = 0;
    totalAccepted = 0;
    totalRejected = 0;
    carsParked = 0;
    bikesParked = 0;
    vansParked = 0;

    const int maxZoneA = 20; // faculty
    const int maxZoneB = 40; // students
    const int maxZoneC = 15; // visitors


    printf("Vehicle Type\n C = Car\n B = Bike\n V = Van\n Enter C/B/V: ");
    scanf(" %c", &vehicleType);
    if (vehicleType != 'C' && vehicleType != 'B' && vehicleType != 'V'){
        printf("Invalid vehicle type\n");
        return 1;
    }

    printf("User Category\n F = Faculty\n S = Student\n G = Visitor/Guest\n Enter F/S/G: ");
    scanf(" %c", &userCategory);
    if (userCategory != 'F' && userCategory != 'S' && userCategory != 'G'){
        printf("Invalid user category\n");
        return 1;
    }

    printf("Do you have a parking permit(Y/N): ");
    scanf(" %c", &parkingPermit);
    if (parkingPermit != 'Y' && parkingPermit != 'N'){
        printf("Invalid input for parking permit\n");
        return 1;
    }

    printf("Is the vehicle an emergency vehicle(Y/N): ");
    scanf(" %c", &emergencyVehicle);
    if (emergencyVehicle != 'Y' && emergencyVehicle != 'N'){
        printf("Invalid input for emergency vehicle\n");
        return 1;
    }

    totalProcessed += 1;

    switch(userCategory){
        case 'F':
            switch(parkingPermit){
                case 'Y':
                    switch(vehicleType){
                        case 'C':
                        case 'B':
                            if (zoneA < maxZoneA){
                                printf("You may park in zone A\n");
                                zoneA += 1;
                                totalAccepted += 1;
                                if (vehicleType == 'C'){ carsParked += 1; }
                                else { bikesParked += 1; }
                            }
                            else {
                                printf("There's no parking available in zone A\n");
                                totalRejected += 1;
                            }
                            break;
                        case 'V':
                            if (zoneA <= maxZoneA - 2){
                                printf("You may park your van in zone A\n");
                                zoneA += 2;
                                totalAccepted += 1;
                                vansParked += 1;
                            }
                            else{
                                printf("Vehicle Rejected as there are no spaces in zone A\n");
                                totalRejected += 1;
                            }
                            break;
                    }
                    break;
                case 'N':
                    if (emergencyVehicle == 'Y'){
                        if (vehicleType == 'V'){
                            if (zoneA <= maxZoneA - 2){
                                printf("You may park in zone A\n");
                                zoneA += 2;
                                totalAccepted += 1;
                                vansParked += 1;
                            } else {
                                printf("Vehicle Rejected as there are no spaces in zone A\n");
                                totalRejected += 1;
                            }
                        } else {
                            if (zoneA < maxZoneA){
                                printf("You may park in zone A\n");
                                zoneA += 1;
                                totalAccepted += 1;
                                if (vehicleType == 'C'){ carsParked += 1; }
                                else { bikesParked += 1; }
                            } else {
                                printf("Vehicle Rejected as there are no spaces in zone A\n");
                                totalRejected += 1;
                            }
                        }
                    }
                    else{
                        printf("Vehicle Rejected - no valid permit\n");
                        totalRejected += 1;
                    }
                    break;
            }
            break;
        case 'S':
            switch(parkingPermit){
                case 'Y':
                    switch(vehicleType){
                        case 'C':
                        case 'B':
                            if (zoneB < maxZoneB){
                                printf("You may park in zone B\n");
                                zoneB += 1;
                                totalAccepted += 1;
                                if (vehicleType == 'C'){ carsParked += 1; }
                                else { bikesParked += 1; }
                            }
                            else {
                                printf("There's no parking available in zone B\n");
                                totalRejected += 1;
                            }
                            break;
                        case 'V':
                            if (zoneC <= maxZoneC - 2){
                                printf("You may park your van in zone C\n");
                                zoneC += 2;
                                totalAccepted += 1;
                                vansParked += 1;
                            }
                            else{
                                printf("Vehicle Rejected as there are no spaces in zone C\n");
                                totalRejected += 1;
                            }
                            break;
                    }
                    break;
                case 'N':
                    if (emergencyVehicle == 'Y'){
                        if (vehicleType == 'V'){
                            if (zoneB <= maxZoneB - 2){
                                printf("You may park in zone B\n");
                                zoneB += 2;
                                totalAccepted += 1;
                                vansParked += 1;
                            } else {
                                printf("Vehicle Rejected as there are no spaces in zone B\n");
                                totalRejected += 1;
                            }
                        } else {
                            if (zoneB < maxZoneB){
                                printf("You may park in zone B\n");
                                zoneB += 1;
                                totalAccepted += 1;
                                if (vehicleType == 'C'){ carsParked += 1; }
                                else { bikesParked += 1; }
                            } else {
                                printf("Vehicle Rejected as there are no spaces in zone B\n");
                                totalRejected += 1;
                            }
                        }
                    }
                    else{
                        printf("Vehicle Rejected - no valid permit\n");
                        totalRejected += 1;
                    }
                    break;
            }
            break;
        case 'G':
            switch(parkingPermit){
                case 'Y':
                    switch(vehicleType){
                        case 'C':
                        case 'B':
                            if (zoneC < maxZoneC){
                                printf("You may park in zone C\n");
                                zoneC += 1;
                                totalAccepted += 1;
                                if (vehicleType == 'C'){ carsParked += 1; }
                                else { bikesParked += 1; }
                            }
                            else {
                                printf("There's no parking available in zone C\n");
                                totalRejected += 1;
                            }
                            break;
                        case 'V':
                            if (zoneC <= maxZoneC - 2){
                                printf("You may park your van in zone C\n");
                                zoneC += 2;
                                totalAccepted += 1;
                                vansParked += 1;
                            }
                            else{
                                printf("Vehicle Rejected as there are no spaces in zone C\n");
                                totalRejected += 1;
                            }
                            break;
                    }
                    break;
                case 'N':
                    if (emergencyVehicle == 'Y'){
                        if (vehicleType == 'V'){
                            if (zoneC <= maxZoneC - 2){
                                printf("You may park in zone C\n");
                                zoneC += 2;
                                totalAccepted += 1;
                                vansParked += 1;
                            } else {
                                printf("Vehicle Rejected as there are no spaces in zone C\n");
                                totalRejected += 1;
                            }
                        } else {
                            if (zoneC < maxZoneC){
                                printf("You may park in zone C\n");
                                zoneC += 1;
                                totalAccepted += 1;
                                if (vehicleType == 'C'){ carsParked += 1; }
                                else { bikesParked += 1; }
                            } else {
                                printf("Vehicle Rejected as there are no spaces in zone C\n");
                                totalRejected += 1;
                            }
                        }
                    }
                    else{
                        printf("Vehicle Rejected - no valid permit\n");
                        totalRejected += 1;
                    }
                    break;
            }
            break;
    }

    // output
    
    printf("Total vehicles processed : %d\n", totalProcessed);
    printf("Total accepted : %d\n", totalAccepted);
    printf("Total rejected : %d\n", totalRejected);
    printf("Cars parked : %d\n", carsParked);
    printf("Bikes parked : %d\n", bikesParked);
    printf("Vans parked : %d\n", vansParked);

    printf("Final Occupancy of zone A : %d\n", zoneA);
    printf("Remaining capacity of zone A : %d\n", maxZoneA - zoneA);
    printf("Final Occupancy of zone B : %d\n", zoneB);
    printf("Remaining capacity of zone B : %d\n", maxZoneB - zoneB);
    printf("Final Occupancy of zone C : %d\n", zoneC);
    printf("Remaining capacity of zone C : %d\n", maxZoneC - zoneC);

    if (zoneA == maxZoneA && zoneB == maxZoneB && zoneC == maxZoneC){
        printf("Campus parking is FULL\n");
    } else {
        printf("Campus parking has space available\n");
    }

    if (zoneA >= zoneB && zoneA >= zoneC){
        printf("Zone A has the highest occupancy\n");
    } else if (zoneB >= zoneC){
        printf("Zone B has the highest occupancy\n");
    } else {
        printf("Zone C has the highest occupancy\n");
    }

    return 0;
}