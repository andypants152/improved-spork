#include <stdio.h>
#include <gb/gb.h>
#include <gbdk/font.h>

/**
 * 
 * The begining?PROJECT whoam1liI
 *  
 * what do you see?
 * 
 * A
 * B
 * C
 * D
 * 
 * what do you hear?
 * 
 * AA, AB, AC, AD
 * BA, BB, BC, BD
 * CA, CB, CC, CD
 * DA, DB, DC, DD
 * 
 * Date of Birth
 * 
 * Day, Month, Year
 * Year, Month, Day
 * Month, Day, Year
 * Year?12021??12022
 * 
 * Who's the Boss?
 * [input NAME]
 * 
 * ENTER GAME:::.:.:.::;**;**;,,***,,
 * 
 * **/

typedef enum {
    HELLO,
    SMILES,
    SPLASH

} screen_t;

void waiting(uint8_t numloops){
    uint8_t i;
    for(i = 0; i < numloops; i++){
        //and wait that many screen draws till the cpu is needed
        wait_vbl_done();
    }     
}

screen_t Hello(){
    font_t min_font;
    font_init();
    //ibm_font = font_load(font_ibm);  /* 96 tiles */
    //italic_font = font_load(font_italic);   /* 93 tiles */
    min_font = font_load(font_min); // 36 tile
    font_set(min_font);
    printf("\nHello World  \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n PRESS START TO\n Continue");
    //TODO: swap out printf for tile placement
    waitpad(J_START);
    return SMILES;
    
}

screen_t Smiles(){
    printf("\n \n \n \n \n \n \n \n add chose your \n own adventure here \n \n \n \n \n \n \n \n \n");

    //waitpad(J_START);
    uint8_t keys;
    keys = joypad();

    switch (keys){
        case J_SELECT:
            printf("uhhh...");
            waitpad(J_START);
            return SPLASH;
            break;
    
        case J_START:
            printf("DON'T LOOK");
            waitpad(J_START);
            return SPLASH;
            break;
        default:
            waiting(255);
            return SMILES;
            break;
    }

}

screen_t Splash(){
    //font_t min_font;
    //font_init();
    //ibm_font = font_load(font_ibm);  /* 96 tiles */
    //italic_font = font_load(font_italic);   /* 93 tiles */
    //min_font = font_load(font_min); // 36 tile
    //font_set(min_font);
    printf("\nBonne Nuit \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n PRESS START TO\n Restart");
    //TODO: swap out printf for tile placement
    waitpad(J_START);
    return HELLO;
}




void main(){
    screen_t current_screen = HELLO;

    
    while(1){
        if (current_screen == HELLO){
            current_screen = Hello();
        }
        else if (current_screen == SMILES){
            current_screen = Smiles();
        }
        else if (current_screen == SPLASH){
            current_screen = Splash();
        }
    }
}
