#include <stdio.h>
#include <stdlib.h>

struct product
{
    char nameProduct[30];
    float price;
    int quantity;
};
typedef struct product product;

struct category
{
    char nameCategory[30];
    int countProduct;
    product products[100];
    int

};
typedef struct category category;

struct superMarket
{
    int countCategory;
    category categories[50];
};
typedef struct superMarket superMarket;

void initialSuper(superMarket *s)
{
    s->countCategory=2;
    for(int i=0; i<2; i++)
    {
        s->categories[i].countProduct=2;
    }
    strcpy(s->categories[0].nameCategory,"fruits");
    strcpy(s->categories[1].nameCategory,"vegetables");
    strcpy(s->categories[0].products[0].nameProduct,"apple");
    strcpy(s->categories[0].products[1].nameProduct,"banana");
    s->categories[0].products[0].price=20;
    s->categories[0].products[0].quantity=100;
    s->categories[0].products[1].price=15;
    s->categories[0].products[1].quantity=120;
    strcpy(s->categories[1].products[0].nameProduct,"cucumber");
    strcpy(s->categories[1].products[1].nameProduct,"carrot");
    s->categories[1].products[0].price=10;
    s->categories[1].products[0].quantity=50;
    s->categories[1].products[1].price=5;
    s->categories[1].products[1].quantity=60;

}

void displaySuper(superMarket *s)
{
    for(int i=0; i<s->countCategory; i++)
    {
        printf("category name is : %s \n",s->categories[i].nameCategory);
        for(int j=0; j<s->categories[i].countProduct; j++)
        {
            printf("productName is: %s \n  price: %.2f \n  quantity: %d \n ",s->categories[i].products[j].nameProduct,s->categories[i].products[j].price,s->categories[i].products[j].quantity);
        }
    }
}

// Function to add a category

void addCategory(superMarket *s)
{
    char nnameCategory[30];
    printf("please add categoryName:");
    scanf("%s",nnameCategory);
    int foundCategory = -1;
    for(int i=0; i<s->countCategory; i++)
    {
        if(strcmp(s->categories[i].nameCategory,nnameCategory)==0)
        {
            foundCategory=i;
            break;
        }

    }
    if(foundCategory==-1)
    {
        //  pr/intf("Category %s", s->categories[foundCategory].nameCategory);
        strcpy(s->categories[s->countCategory].nameCategory,nnameCategory);
        s->categories[foundCategory].countProduct = 0;
        s->countCategory++;
        printf("Category %s added.\n", nnameCategory);
    }
    else
    {
        printf("Cannot add more categories.\n");
    }
    /*
    if(s->countCategory<50)
    {
        strcpy(s->categories[s->countCategory].nameCategory, nameCategory);
        s->categories[s->countCategory].countProduct = 0;
        s->countCategory+=1;
        printf("Category '%s' added.\n", nameCategory);

    }
    else
    {
        printf("Cannot add more categories.\n");
    }
    */
}
// Function to remove a category
void removeCategory(superMarket *s)
{
    if(s->countCategory>0)
    {
        char nameCategory[30];
        printf("please remove categoryName:");
        scanf("%s",nameCategory);
        int foundCategory = -1;
        for(int i=0; i<s->countCategory; i++)
        {
            if(strcmp(s->categories[i].nameCategory,nameCategory)==0)
            {
                foundCategory=i;
                break;
            }
        }
        if(foundCategory!=-1)
        {
            for(int i=foundCategory; i<s->countCategory; i++)
            {
                s->categories[i]=s->categories[i+1];
                s->countCategory--;
            }
            printf("Category '%s' removed.\n", nameCategory);

        }
        else
        {
            printf("can not remove");
        }
    }
}


// Function to add a product to a category

void addProduct(superMarket *s)
{
    char nameCategory[30];
    int foundCategory = -1;
    char productName[30];
    float price;
    int quantity;
    printf("\n please enter categoryName:");
    scanf("%s",nameCategory);
    printf("\n Enter product name: ");
    scanf("%s", productName);
    printf("Enter product price: ");
    scanf("%f", &price);
    printf("Enter product quantity: ");
    scanf("%d", &quantity);
    for(int i=0; i<s->countCategory; i++)
    {
        if(strcmp(s->categories[i].nameCategory,nameCategory)==0)
        {
            foundCategory=i;
            break;
        }
    }
    if(foundCategory !=-1)
    {
        strcpy(s->categories[foundCategory].products[s->categories[foundCategory].countProduct].nameProduct,productName);
        s->categories[foundCategory].products[s->categories[foundCategory].countProduct].price = price;
        s->categories[foundCategory].products[s->categories[foundCategory].countProduct].quantity = quantity;
        s->categories[foundCategory].countProduct++;

    }
    // printf("Product '%s' added to category '%s'.\n", productName, nameCategory);
    if(foundCategory != -1)
    {
        printf("Product '%s' added to category '%s'.\n", productName, nameCategory);
    }
    else
    {
        printf("Category '%s' not found.\n", nameCategory);
    }
    /*
     int foundCategory = 0;
    char productName[30];
     float price;
    int quantity;
    printf("Enter product name: ");
    scanf("%s", productName);
    printf("Enter product price: ");
    scanf("%f", &price);
    printf("Enter product quantity: ");
    scanf("%d", &quantity);
    for(int i=0;i<s->countCategory;i++){
    if(strcmp(s->categories[i].nameCategory, "fruits") == 0){
        strcpy(s->categories[i].products[s->categories[i].countProduct].nameProduct, productName);
        s->categories[i].products[s->categories[i].countProduct].price = price;
        s->categories[i].products[s->categories[i].countProduct].quantity = quantity;
        s->categories[i].countProduct++;
        foundCategory = 1;
        break;
    }
    }
    if(!foundCategory){
    printf("No category found with name 'fruits'.\n");
    }
    */
}


void removeProduct(superMarket *s)
{
    char nameCategory[30];
    char productName[30];
    int foundCategory = -1;
    printf("please enter categoryName to remove product:");
    scanf("%s",nameCategory);
    printf("\n remove product name: ");
    scanf("%s", productName);
    for(int i=0; i<s->countCategory; i++)
    {
        if(strcmp(s->categories[i].nameCategory,nameCategory)==0)
        {
            foundCategory=i;
            break;
        }

    }
    int productIndex=-1;
    if(foundCategory!=-1)
    {
        for(int i=0; i<s->categories[foundCategory].countProduct; i++)
        {
            if(strcmp(s->categories[foundCategory].products[i].nameProduct,productName)==0)
            {
                productIndex=i;
                break;
            }
        }
    }
    if(productIndex!=-1)
    {
        for(int i=productIndex; i < s->categories[foundCategory].countProduct; i++)
        {
            s->categories[foundCategory].products[i]=s->categories[foundCategory].products[i+1];
        }
        s->categories[foundCategory].countProduct--;
        printf("Product '%s' removed from category '%s'.\n", productName, nameCategory);

    }



}
/*
void move(superMarket *s)
{
    char c;

    if(s->countCategory>1)
    {
        char productName[40],fromCategoryName[40],toCategoryName[40];
        int sourceCategoryIndex=-1;
        int productIndex=-1;
        int destinationCategoryIndex=-1;

        printf("please enter source category name that you want to move product from it \n");
        scanf("%s",fromCategoryName);
        for(int i=0; i<s->countCategory; i++)
        {
            if(strcmp(s->categories[i].nameCategory,fromCategoryName)==0)
            {
                sourceCategoryIndex=i;
                break;
            }
        }


        if(sourceCategoryIndex!=-1)
        {
            if(s->categories[sourceCategoryIndex].countProduct==0)
            {
                printf("Error: there is no product in the source category name \n");
            }
            printf("please enter product name that you want to move: \n");
            scanf("%s",productName);
            for(int i=0; i<s->categories[sourceCategoryIndex].countProduct; i++)
            {
                if(strcmp(s->categories[sourceCategoryIndex].products[i].nameProduct,productName)==0)
                {
                    productIndex=i;
                    break;
                }
            }
        }




        printf("please enter destination category name that you want to move product from it \n");
        scanf("%s",toCategoryName);
        for(int i=0; i<s->countCategory; i++)
        {
            if(strcmp(s->categories[i].nameCategory,toCategoryName)==0)
            {
                destinationCategoryIndex=i;
                break;
            }
        }
        int destinationProductIndex=-1;
        if(destinationCategoryIndex!=-1)
        {
            for(int i=0; i<s->categories[destinationCategoryIndex].countProduct; i++)
            {
                if(strcmp(s->categories[destinationCategoryIndex].products[i].nameProduct,productName)==0)
                {
                    destinationProductIndex=i;
                    break;
                }
            }
        }
        if(destinationProductIndex==-1)
        {
            s->categories[destinationCategoryIndex].products[s->categories[destinationCategoryIndex].countProduct]=s->categories[sourceCategoryIndex].products[productIndex];
            s->categories[destinationProductIndex].countProduct++;
            for(int i=0; i<s->categories[sourceCategoryIndex].countProduct-1; i++)
            {
                s->categories[sourceCategoryIndex].products[i]=s->categories[sourceCategoryIndex].products[i+1];
            }
            s->categories[sourceCategoryIndex].countProduct--;
            printf("you moved %s from %s to %s successfully",productName,fromCategoryName,toCategoryName);
        }



    }


}
*/



void move(superMarket *s) {
    char c;
    if (s->countCategory > 1) {
        char prodName[20], sourceCatName[20], destinationCatName[20];
        int sourceCatIndex = -1;

        printf("Please enter source category name that you want to move the product from: ");
        scanf("%s", sourceCatName);

        for (int i = 0; i < s->countCategory; i++) {
            if (strcmp(s->categories[i].nameCategory, sourceCatName) == 0) {
                sourceCatIndex = i;
                break;
            }
        }

        if (sourceCatIndex == -1) {
            printf("Error: The source category \"%s\" was not found. Please enter a valid source name.\n", sourceCatName);
            return;
        }

        int productIndex = -1;
        printf("Please enter the product name that you want to move: ");
        scanf("%s", prodName);

        for (int i = 0; i < s->categories[sourceCatIndex].countProduct; i++) {
            if (strcmp(s->categories[sourceCatIndex].products[i].nameProduct, prodName) == 0) {
                productIndex = i;
                break;
            }
        }

        if (productIndex == -1) {
            printf("Error: This product \"%s\" was not found in \"%s\". Please enter a valid product name.\n", prodName, sourceCatName);
            return;
        }

        printf("Please enter destination category name where you want to move the product: ");
        scanf("%s", destinationCatName);

        int destinationCatIndex = -1;
        for (int i = 0; i < s->countCategory; i++) {
            if (strcasecmp(s->categories[i].nameCategory, destinationCatName) == 0) {
                destinationCatIndex = i;
                break;
            }
        }

        if (destinationCatIndex == -1) {
            printf("Error: The destination category \"%s\" was not found. Please enter a valid destination name.\n", destinationCatName);
            return;
        }

        if (s->categories[destinationCatIndex].countProduct < 20) {
            s->categories[destinationCatIndex].products[s->categories[destinationCatIndex].countProduct] = s->categories[sourceCatIndex].products[productIndex];
            s->categories[destinationCatIndex].countProduct++;

            for (int i = productIndex; i < s->categories[sourceCatIndex].countProduct - 1; i++) {
                s->categories[sourceCatIndex].products[i] = s->categories[sourceCatIndex].products[i + 1];
            }

            s->categories[sourceCatIndex].countProduct--;
            printf("You moved %s from %s to %s successfully.\n", prodName, sourceCatName, destinationCatName);
        } else {
            printf("Error: No space for more products in the destination category.\n");
        }
    } else {
        printf("Error: Not enough categories to perform a product move.\n");
    }

   // printf("\nDo you want to move another product? (Y|N)\n");
    //c = getch();
    //printf("\n");
}


void sellProduct(superMarket *s){
    int totalPrice=0;
    char productName[40],categoryName[40];
    int price ,quantity;
    int categoryIndex=-1;
    printf("Please Enter Category Name that you want to sell product from it:");
    scanf("%s",categoryName);
    for(int i=0;i<s->countCategory;i++){
        if(strcmp(s->categories[i].nameCategory,categoryName)==0){
            categoryIndex=i;
            break;
        }
    }
    int productIndex=-1;
    if(categoryIndex!=-1){
        printf("please enter product name that you want to sell it:");
        scanf("%s",productName);
        for(int i=0;i<s->categories[categoryIndex].countProduct;i++){
            if(strcmp(s->categories[categoryIndex].products[i].nameProduct,productName)==0){
                productIndex=i;
                break;
            }
        }
    }
    if(s->categories[categoryIndex].products[productIndex].quantity>0){
        printf("please enter quantity of this product:");
        scanf("%d",&quantity);
        if(quantity<=s->categories[categoryIndex].products[productIndex].quantity){
            s->categories[categoryIndex].products[productIndex].quantity -=quantity;
            printf("you sold %s with quantity %d and its total price is %.2f",productName,quantity,quantity*s->categories[categoryIndex].products[productIndex].price);
            totalPrice+=quantity*s->categories[categoryIndex].products[productIndex].price;
        }else{
            if(quantity > s->categories[categoryIndex].products[productIndex].quantity){
                printf("Error");
            }
            s->categories[categoryIndex].products[productIndex].quantity -=quantity;
             printf("you sold %s with quantity %d and its total price is %.2f",productName,quantity,quantity*s->categories[categoryIndex].products[productIndex].price);
            totalPrice+=quantity*s->categories[categoryIndex].products[productIndex].price;
        }
    }
}


void menu()
{
    printf("\n choose number: \n");
    printf("1-Add Category: \n");
    printf("2-Remove Category: \n");
    printf("3-Add Product: \n");
    printf("4-Remove Product: \n");
    printf("5-move product: \n");
    printf("6-Sell Product: \n");
    printf("7-Display: \n");
    printf("8-Exit: \n");



}

int main()
{
    printf("\t \t \t \t \t \t Angelo Market \n ");
    superMarket s;

    initialSuper(&s);
    displaySuper(&s);
    printf("-----------------------------");
    /*
    displaySuper(&s);
    addCategory(&s);
    //removeCategory(&s);
    //addProduct(&s);
    //removeProduct(&s);
    displaySuper(&s);
    */
    /*
    char ch;
    printf("add another cateory?(Y/N)");
    scanf("%c",ch);
    while(ch=='y'||ch=='Y')
    {
        addCategory(&s);
        printf('add another cateory?(Y/N)');
        scanf("%c",ch);
    }
    for(int i=0 ; i<3; i++)
    {
        addCategory(&s);

    }
    */
    int r=1;
    do
    {

        int num;
        menu();
        scanf("%d",&num);
        switch(num)
        {
        case 1:
            addCategory(&s);
            break;
        case 2:
            removeCategory(&s);
            break;
        case 3:
            addProduct(&s);
            break;
        case 4:
            removeProduct(&s);
            break;
        case 5:
            move(&s);
            break;
        case 6:
            sellProduct(&s);
            break;
        case 7:
            displaySuper(&s);
            break;
        case 8:
            r=0;
            break;
        }
    }
    while(r ==1 );
    // addProduct(&s);
    return 0;
}
