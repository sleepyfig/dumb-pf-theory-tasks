#include <stdio.h>

int main() {
    char vehicleType, parkingMem, disabledPer, stationAvailable;
    float batteryLvl, reqChargingLvl, reqCharging, baseRate, rate, discountRate, chargingCost, parkingCharges, discount;
    int parkingDur, currentTime, priority, peak;

    reqCharging = 0;
    chargingCost = 0;
    parkingCharges = 0;
    discount = 0;
    baseRate = 0;
    rate = 0;
    discountRate = 0;
    priority = 3;
    peak = 0;

    printf("Vehicle type (E = Electric, H = Hybrid): ");
    scanf(" %c", &vehicleType);
    printf("Current battery level (0 - 100): ");
    scanf("%f", &batteryLvl);
    printf("Required charging level (0 - 100): ");
    scanf("%f", &reqChargingLvl);
    printf("Expected parking duration (hours): ");
    scanf("%d", &parkingDur);
    printf("Current time in HHMM 24-hour form (e.g. 1830): ");
    scanf("%d", &currentTime);
    printf("Parking membership (Y/N): ");
    scanf(" %c", &parkingMem);
    printf("Disabled-person priority (Y/N): ");
    scanf(" %c", &disabledPer);
    printf("Is the charging station available (Y/N): ");
    scanf(" %c", &stationAvailable);


    if (vehicleType != 'E' && vehicleType != 'H') {
        printf("Invalid vehicle type!\n");
        return 1;
    }
    if (batteryLvl < 0 || batteryLvl > 100) {
        printf("Invalid battery level!\n");
        return 1;
    }
    if (reqChargingLvl < 0 || reqChargingLvl > 100) {
        printf("Invalid required charging level!\n");
        return 1;
    }
    if (parkingDur <= 0) {
        printf("Invalid parking duration!\n");
        return 1;
    }
    if (currentTime < 0 || currentTime > 2359) {
        printf("Invalid time!\n");
        return 1;
    }
    if (parkingMem != 'Y' && parkingMem != 'N') {
        printf("Invalid membership input!\n");
        return 1;
    }
    if (disabledPer != 'Y' && disabledPer != 'N') {
        printf("Invalid priority status input!\n");
        return 1;
    }
    if (stationAvailable != 'Y' && stationAvailable != 'N') {
        printf("Invalid station availability input!\n");
        return 1;
    }


    if (stationAvailable == 'N') {
        if (vehicleType == 'H') {
            printf("Charging unavailable - Parking only\n");
        } else {
            printf("No charging slot available\n");
        }
        return 0;
    }

    if (vehicleType == 'H' && batteryLvl >= 40) {
        printf("Vehicle does not qualify for EV charging\n");
        return 0;
    }

    if (reqChargingLvl <= batteryLvl) {
        printf("No charging required\n");
        return 0;
    }

    reqCharging = reqChargingLvl - batteryLvl;

    if (batteryLvl <= 15 && reqChargingLvl >= 80) {
        priority = 1;
    } else if (disabledPer == 'Y' || (parkingMem == 'Y' && batteryLvl <= 30)) {
        priority = 2;
    } else {
        priority = 3;
    }

    if (currentTime < 1700 || currentTime > 2200) {
        peak = 0;
        baseRate = 35;
        discountRate = 0.20;
    } else {
        peak = 1;
        baseRate = 50;
        discountRate = 0.10;
    }

    rate = baseRate;
    if (parkingMem == 'Y' && priority != 1) {
        rate = baseRate * (1 - discountRate);
        discount = discount + (reqCharging * baseRate * discountRate);
    }

    chargingCost = reqCharging * rate;


    if (parkingDur <= 2) {
        parkingCharges = 200;
    } else if (parkingDur <= 5) {
        parkingCharges = 400;
    } else {
        parkingCharges = 700;
    }

    if (parkingMem == 'Y') {
        discount = discount + (parkingCharges * 0.20);
        parkingCharges = parkingCharges * 0.80;
    }

    if (disabledPer == 'Y') {
        discount = discount + parkingCharges;
        parkingCharges = 0;
    }

    printf("\n----- Charging and Parking Bill -----\n");
    printf("Vehicle type : %c\n", vehicleType);
    printf("Current battery percentage : %.2f %%\n", batteryLvl);
    printf("Required charging percentage : %.2f %%\n", reqChargingLvl);
    printf("Charging units required : %.2f\n", reqCharging);

    if (priority == 1) {
        printf("Charging priority : Emergency Charging Priority\n");
    } else if (priority == 2) {
        printf("Charging priority : Priority Charging\n");
    } else {
        printf("Charging priority : Normal Charging\n");
    }

    if (peak == 0) {
        printf("Time slot : Off-Peak\n");
    } else {
        printf("Time slot : Peak\n");
    }

    printf("Rate applied : Rs. %.2f per unit\n", rate);
    printf("Charging cost : Rs. %.2f\n", chargingCost);
    printf("Parking cost : Rs. %.2f\n", parkingCharges);
    printf("Total discount : Rs. %.2f\n", discount);
    printf("Final payable amount : Rs. %.2f\n", chargingCost + parkingCharges);

    if (parkingDur > 8) {
        printf("Long-stay warning: Please relocate your vehicle after charging\n");
    } else {
        printf("Standard parking duration\n");
    }

    return 0;
}