#include <stdio.h>

int main() {
    float price, discount, tax, subTotal, discountedamount, FinalBill;
    int quantity;

    printf("Enter the quantity of items: ");
    scanf("%d", &quantity);
    if (quantity <= 0) {
        printf("Invalid quantity. Please enter a positive integer.\n");
        return 1; 
    }

    printf("Price of the item: ");
    scanf("%f", &price);
    if (price <= 0) {
        printf("Invalid price. Please enter a positive value.\n");
        return 1; 
    }

    printf("Enter the discount percentage: ");
    scanf("%f", &discount);
    if (discount < 0 || discount >= 100) {
        printf("Invalid discount. Please enter a value between 0 and 100.\n");
        return 1;
    }

    printf("Enter the tax percentage: ");
    scanf("%f", &tax);
    if (tax < 0 || tax >= 100) {
        printf("Invalid tax. Please enter a value between 0 and 100.\n");
        return 1;
    }

    subTotal = price * quantity;
    discountedamount = subTotal - ((subTotal * discount) / 100);
    FinalBill = discountedamount + ((discountedamount * tax) / 100);

    printf(" -- Bill Document --\n");
    printf("Quantity: %d\n", quantity);
    printf("Price per item: %.2f\n", price);
    printf("Subtotal: %.2f\n", subTotal);
    printf("Discount: %.2f%%\n", discount);
    printf("Discounted Amount: %.2f\n", discountedamount);
    printf("Tax: %.2f%%\n", tax);
    printf("Final Bill: %.2f\n", FinalBill);
    

    return 0;
}