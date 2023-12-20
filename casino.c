#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Simple program to learn the basics of C syntax (for and while loops, conditionals, user input, structs .. no memory (ideally) (yet))

typedef struct CasinoPlayer
{  
    char name[50];
    float bal;
} CasinoPlayer;

//Intro -- let user input the  stuff they pick
//Slot machine, 

//Get the user's option
char* getinput(){
    char *option = malloc(1); //Allocate one byte for user input (user should input a number)
    printf("Welcome to the gambling casino. Press an option to continue.\n");
    printf("1. Slot machines\n");
    printf("2. Poker\n");
    printf("3. Leave\n");
    scanf("%c", option);
    return option;
}

void load_slotmachines(CasinoPlayer *player){
    CasinoPlayer pl = *player;
    for (int i = 0; i < 10; i++)
    {
        pl.bal = pl.bal - 30.44;
    }
    printf("Player balance is %f", pl.bal);
}

void loadpoker(){

}

void load_from_option(char *option, CasinoPlayer *player){
    char val = *option; 

    //printf("%c", *option);

    if (val == '1')
    {
        load_slotmachines(player);
    }
    else if (val == '2')
    {
        loadpoker(); // might not implement this one out of laziness
    }
    else
    {
        printf("exiting");
        exit(0);
    }
}

int main(){
    CasinoPlayer player;
    player.bal = 50.0;
    strcpy(player.name, "Geoff the Gambler"); //Using strcpy because we can't assign values to immutable arrays

    CasinoPlayer *p = &player; 

    char *option = getinput();
    load_from_option(option, p);

    free(option);
    
    return 0;
}


//scanf test
// test(){
//     int input = 99;
//     int& refInput = input;
//     int *ptr = &input;

//     printf("Enter a number:");

    
//     scanf("%d", ptr); //&input scanf takes in a mem adress

//     printf("%d", input);

//     free(ptr);
// }