/*
Suppose you are developing a program for a bookshop to manage customer purchase. 
Your task is to create a C program that can store bookshop data. Based on that data, 
the bookshop is giving a "BEST CUSTOMER AWARD" to the customers who purchased the 
most. Write a C program that will:
    1. Store the following info of a customer in a structure:
          i) Name
         ii) ID
        iii) Number of times shopped
         iv) An array of spent money
          v) And other info if required
    2. Take input for N Customers from the user
    3. Calculate the average purchase for each customer
    4. To find the best customer, only consider the customers who have shopped
       more than 10 times. Among the selected customers, The customer having the 
       best average purchase will win the award.
*/



#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct cust_info
{
    char name[30];
        // assuming name contains maximum of 30 character
    int id;
    int shopped;
        // number of times shopped
    int* shopped_list;
    float avg;
};

typedef struct cust_info cust_info;



// puts input into array
void place_input(cust_info* customers, int i, char* cust_name, int cust_id, int cust_shopped, int* cust_shopped_list)
{               // list of customers, index of input, name, id, shopped count, shopped list, average
    int sum = 0;
    for(int i=0; i<cust_shopped; i++)
    {
        sum += cust_shopped_list[i];
    }

    strcpy(customers[i].name, cust_name);
    customers[i].id = cust_id;
    customers[i].shopped = cust_shopped;
    customers[i].shopped_list = cust_shopped_list;
    customers[i].avg = (float) sum / cust_shopped;
}



// takes n inputs and returns an array
cust_info* take_input(int n)
{           // n is number of input to be taken
    cust_info* customers = malloc(sizeof(cust_info)*n);
            // initializing an arr for storing n cust_info

    for(int i=0; i<n; i++)
    {
        char cust_name[30];
        int cust_id;
        int cust_shopped;
        int* cust_shopped_list;

        printf("For customer %d Enter :\n",i+1);
        printf("Name\t\t:");
        getchar(); 
        fgets(cust_name, sizeof(cust_name), stdin);
        
        printf("Customer Id \t:");
        scanf("%d", &cust_id);

        printf("Shopped items count\t:");
        scanf("%d", &cust_shopped);
        cust_shopped_list = malloc(sizeof(int)*cust_shopped);

        printf("Enter spent money in each shopping\n");        
        for(int j=0; j<cust_shopped; j++){
            printf("\tShopping %d  :", j+1);
            scanf("%d", &cust_shopped_list[j]);
        }

        place_input(customers, i, cust_name, cust_id, cust_shopped, cust_shopped_list);
    }
    return customers;
}




// selects selected cutomers and returns an array of selected custs
cust_info* selected_custs(cust_info* customers, int size, int* n)
{
    *n = 0;
        // n = selected customer count
    int selected_cust_min_shop = 10;

    for(int i=0; i<size; i++)
    {
        *n += (customers[i].shopped >= selected_cust_min_shop);
    }

    if(*n == 0) return NULL;
        // if there is no customer meeting required criteria

    cust_info* selected_cust_list = malloc(sizeof(cust_info)*size);

    int m = 0;
    for(int i=0; i<size; i++)
    {
        if(customers[i].shopped >= selected_cust_min_shop)
        {
            place_input(selected_cust_list, m, customers[i].name, customers[i].id, customers[i].shopped, customers[i].shopped_list);
            m++;
        }
    }
    return selected_cust_list;
}


// prints individuals info
void cust_info_print(cust_info* customer)
{
    printf("\n");
    printf("Name: %s\n", customer -> name);
    printf("ID: %d\n", customer -> id);
    printf("Number of times shopped: %d\n", customer -> shopped);
    printf("Spent money in each shopping:\n");
    for (int j = 0; j < customer -> shopped; j++) 
    {
        printf("\tShopping %d: %d\n", j + 1, customer -> shopped_list[j]);
    }
}

// prints all customer info 
void cust_list_print(cust_info* customers, int size)
{
    for (int i = 0; i < size; i++) 
    {
        printf("\n#%d", i + 1);
        cust_info_print(&customers[i]);
    }
}




int main() 
{
    /*                          users input                          */

    // int SIZE;
    // printf("Enter Number of inputs\n");
    // scanf("%d", &SIZE);

    // // Take input for customers
    // cust_info* customers = take_input(SIZE);
    


    /*                         manual inputs                       */

    int SIZE = 5;
    cust_info* customers = malloc(sizeof(cust_info)*SIZE);
        // name, id, shopped_count, shopped_list, avg

    int shopped_list1[] = {100, 150, 200, 300, 250, 400, 350, 200, 220, 250, 230, 210};  // 12 shopping instances
    place_input(customers, 0, "John Doe", 1001, 12, shopped_list1);
    int shopped_list2[] = {75, 125};  // 2 shopping instances
    place_input(customers, 1, "Jane Smith", 1002, 2, shopped_list2);
    int shopped_list3[] = {300, 250, 400, 350, 500, 600, 550, 450, 700, 800};  // 10 shopping instances
    place_input(customers, 2, "Alice Brown", 1003, 10, shopped_list3);
    int shopped_list4[] = {50, 70, 90};  // 3 shopping instances
    place_input(customers, 3, "Bob White", 1004, 3, shopped_list4);
    int shopped_list5[] = {200, 220, 250, 230, 210};  // 5 shopping instances
    place_input(customers, 4, "Charlie Green", 1005, 5, shopped_list5);



    /*                       further process                        */

    // Display the customer data
    printf("\n\n----------------ALL CUSTOMERS INFO----------------\n");
    cust_list_print(customers, SIZE);


    // finding selected customers list 
    int selected_cust_size;
    cust_info* selected_cust_list = selected_custs(customers, SIZE, &selected_cust_size);

    if(selected_cust_size == 0)
    {
        printf("\nNo Customer Met Required Criteria\n");
        return 0;               // exception handling
    }


    // Display the selected customers data 
    printf("\n\n----------------SELECTED CUSTOMERS INFO----------------\n");
    cust_list_print(selected_cust_list, selected_cust_size);


    // Finds best customer from selected customers

    printf("\n\n----------------BEST CUSTOMER INFO----------------\n");

    int best_cust_i = 0;
    float best_cust_avg = selected_cust_list[0].avg;

    for(int i=1; i<selected_cust_size; i++){
        if(selected_cust_list[i].avg > best_cust_avg)
        {
            best_cust_i = i;
        }
    }

    // printf("\nBest Customer is \t: %s\n\n", selected_cust_list[best_cust_i].name);
        // as question wanted. but we can also print the whole info to beautify it.
    
    cust_info_print(&selected_cust_list[best_cust_i]);

    return 0;
}