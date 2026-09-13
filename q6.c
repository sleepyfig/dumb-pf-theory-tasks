#include <stdio.h>
int main(){
    char vehicleType, parkingMem, disabledPer, avChargingStation;
    float batteryLvl, reqChargingLvl, reqCharging, price, totalCharging, parkingCharges, discount;
    int parkingDur, currentTime, priority, peak;

    parkingCharges = 0;
    price = 0;
    totalCharging = 0;
    priority = 0;
    reqCharging = 0;
    discount = 0;
    peak = 0;


    // all the inputs
    printf("Vehicle Type\n E = Electric Vehicle\n H = Hybrid Vehicle\n Enter E/N: ");
    scanf(" %c", &vehicleType);
    printf("Battery Level: ");
    scanf("%f", &batteryLvl);
    printf("Required Charging level: ");
    scanf("%f", &reqChargingLvl);
    printf("Parking Duration(in hours): ");
    scanf("%d", &parkingDur);
    printf("Current time(24 hr format): ");
    scanf("%d", &currentTime);
    printf("Do u have a parking membership(Y/N): ");
    scanf(" %c", &parkingMem);
    printf("Do u have a disabled person priority status(Y/N): ");
    scanf(" %c", &disabledPer);
    printf("Is a parking station currently avaliable(Y/N): ");
    scanf(" %c", &avChargingStation);

    if (avChargingStation == 'N'){
        if (vehicleType == 'H'){
            printf("Charging unavailable - Parking only\n");
        }
        else{
            printf("No charging slot available\n");
        };
    }
    else{
        if (vehicleType == 'H' && batteryLvl > 40){
            printf("Vehicle does not qualify for EV charging\n");
        }
        else{
            if (reqChargingLvl <= batteryLvl){
                printf("No charging required\n");
            }
            else{
                reqCharging = reqChargingLvl - batteryLvl;
                if (batteryLvl <= 15 && reqChargingLvl >= 80){
                    priority = 1;
                } 
                else if(disabledPer == 'Y' || (parkingMem == 'Y' && batteryLvl <= 30)){
                    priority = 2;
                }
                else{
                    priority = 3;
                };
                if (currentTime < 1700 || currentTime > 2200){
                    // off peak
                    price = 35;
                    peak = 0;
                    if (parkingMem == 'Y' && priority != 1){
                        price = 35 * 0.8;
                        discount += 35 * 0.2;
                    }
                }
                else {
                    // peak
                    price = 50;
                    peak = 1;
                    if (parkingMem == 'Y' && priority != 1){
                        price = 50 * 0.9;
                        discount += 50 * 0.1;
                    }
                };
                totalCharging =  reqCharging * price;
                if (parkingDur <= 2){
                    parkingCharges = 200;
                    printf("Standard parking duration\n");
                }
                else if (parkingDur <= 5){
                    parkingCharges = 400;
                    printf("Standard parking duration\n");
                }
                else if (parkingDur <= 8){
                    parkingCharges = 700;
                    printf("Standard parking duration\n");
                }
                else{
                    parkingCharges = 700;
                    printf("Long-stay warning: Please relocate your vehicle after charging\n");
                };
                if (parkingMem == 'Y'){
                    discount += parkingCharges * 0.2;
                    parkingCharges *= 0.8;
                };
                if (disabledPer == 'Y'){
                    discount += parkingCharges;
                    parkingCharges = 0;
                }
            };
        };
    };


    // outputs
    printf("Vehicle Type : %c\n", vehicleType);
    printf("Current Battery Percentage : %.2f\n", batteryLvl);
    printf("Required Charging Percentage : %.2f\n", reqChargingLvl);
    if (priority == 1){
        printf("Emergency Charging Priority\n");
    }
    else if(priority == 2){
        printf("Priority Charging\n");
    }
    else{
        printf("Normal Charging\n");
    };
    if (peak == 0){
        printf("Off-Peak\n");
    }
    else {
        printf("Peak\n");
    };
    printf("Charging cost : %.2f\n", totalCharging);
    printf("Parking cost : %.2f\n", parkingCharges);
    printf("Discount : %.2f\n", discount);
    printf("Total Amount : %.2f\n", totalCharging + parkingCharges);
    
    
    return 0;
}