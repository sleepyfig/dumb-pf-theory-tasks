#include <stdio.h>

int main() {
    int season, roomType, nights;
    float rate = 0, discount = 0, guestTotal, totalRevenue = 0;

    printf("Seasons\n 1 = Peak\n 2 = Off-Peak\n Enter season (1 or 2): ");
    scanf("%d", &season);
    printf("Room Types\n 1 = Standard\n 2 = Deluxe\n 3 = Suite\n Enter room type (1, 2, or 3): ");
    scanf("%d", &roomType);
    printf("Enter number of nights: ");
    scanf("%d", &nights);

    if (nights <= 0) {
        printf("Invalid number of nights!\n");
        return 1;
    }

    if (season == 1) {
        switch (roomType) {
            case 1: rate = 5000;  break;
            case 2: rate = 8000;  break;
            case 3: rate = 12000; break;
            default:
                printf("Invalid room type!\n");
                return 1;
        }
    } else if (season == 2) {
        switch (roomType) {
            case 1: rate = 3000; break;
            case 2: rate = 5000; break;
            case 3: rate = 8000; break;
            default:
                printf("Invalid room type!\n");
                return 1;
        }
    } else {
        printf("Invalid season!\n");
        return 1;
    }

    guestTotal = rate * nights;

    if (nights > 7) {
        discount = guestTotal * 0.15;
    } else {
        discount = 0;
    }

    guestTotal = guestTotal - discount;
    totalRevenue = totalRevenue + guestTotal;

    printf("Rate per night : Rs. %.2f\n", rate);
    printf("Discount       : Rs. %.2f\n", discount);
    printf("Guest total    : Rs. %.2f\n", guestTotal);
    printf("Hotel Total Revenue: Rs. %.2f\n", totalRevenue);

    return 0;
}