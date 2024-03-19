/*
** EPITECH PROJECT, 2021
** BasicRepo
** File description:
** main
*/
/*
#include "include.h"
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
*/
#include <raylib.h>
#include <stdio.h>
//typedef void(*fnc)(master_t*);

/*
int main(int ac, char **av)
{
    sfClock * clock = sfClock_create();
    sfTime time;
    sfEvent event;
    master_t *master = malloc(sizeof(master_t));
    fnc func[5] = {menu, game, loadmenu};

    srand(getpid());
    initmaster(master);
    while (sfRenderWindow_isOpen(master->window)) {
        while (sfRenderWindow_pollEvent(master->window, &event))
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(master->window);
        time = sfClock_getElapsedTime(clock);
        if (time.microseconds >= 16666) {
            sfClock_restart(clock);
            func[master->state](master);
        }
    }


    return (0);
}
*/

typedef struct{
    int yAxis;
    int xAxis;
    Texture2D texture; 
    Rectangle sourceRec;
}button;


button buttonCreator(char *path,int y ){
    Texture2D texture = LoadTexture(path);
    float frameWidth = (float)texture.width/2;
    //Rectangle sourceRec = { 0, 0,frameWidth,(float)quit.height };

    return (button){y,480,texture,{ 0, 0,frameWidth,(float)texture.height }};

}

void main(){
    InitWindow(1280, 720,"THE ONE AND ONLY RPG");
    SetTargetFPS(60);
    Texture2D bg = LoadTexture("asset/menu/titlescreen.png");

    button menuButtons[3] = {
        buttonCreator("asset/menu/quit.png",500),
        buttonCreator("asset/menu/load.png",350),
        buttonCreator("asset/menu/new.png",200)
    };

    while (!WindowShouldClose())
    {

        Vector2 mousePosition = GetMousePosition();
    
        BeginDrawing();
        DrawTexture(bg, 0, 0, WHITE);
        for(int i = 0 ; i< 3 ; i++){
            if(mousePosition.x >= menuButtons[i].xAxis 
                && mousePosition.x <= menuButtons[i].xAxis + menuButtons[i].sourceRec.width 
                && mousePosition.y >= menuButtons[i].yAxis 
                && mousePosition.y <= menuButtons[i].yAxis + menuButtons[i].sourceRec.height ){
                    menuButtons[i].sourceRec.x = menuButtons[i].sourceRec.width ;
                    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                        printf("%i\n", i);
                }
             
           
            DrawTextureRec(menuButtons[i].texture, menuButtons[i].sourceRec, (Vector2){ menuButtons[i].xAxis, menuButtons[i].yAxis}, WHITE);
            menuButtons[i].sourceRec.x = 0;
        }
        EndDrawing();
    }

    UnloadTexture(bg); 
    for(int i = 0 ; i< 3 ; i++)
        UnloadTexture(menuButtons[i].texture); 
    CloseWindow();
}