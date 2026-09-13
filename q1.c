#include <stdio.h>
int main(){
    int season, roomType, noOfNights;
    float price, totalPrice;
    totalPrice = 0;
    price = 0;
    printf("enter season(1 for peak and 2 for off-peak): ");
    scanf("%d", &season);
    printf("enter room type(1 for standard, 2 for deluxe, 3 for suite): ");
    scanf("%d", &roomType);
    printf("how many nights have u been in the hotel: ");
    scanf("%d",&noOfNights);
    if (season == 1){
        switch(roomType){
            case 1:
                price = 5000;
                break;
            case 2:
                price = 8000;
                break;
            case 3:
                price = 12000;
                break;
            default:
                printf("invalid input!\n");
        };
    } else if(season == 2) {
        switch(roomType){
            case 1:
                price = 3000;
                break;
            case 2:
                price = 5000;
                break;
            case 3:
                price = 8000;
                break;
            default:
                printf("invalid room type input!\n");
        };
    } else {
        printf("invalid season input!\n");
    };
    totalPrice = price * noOfNights;
    if (noOfNights > 7){
        totalPrice = totalPrice * 0.85;
    };

    printf("total price: %.2f\n", totalPrice);
}