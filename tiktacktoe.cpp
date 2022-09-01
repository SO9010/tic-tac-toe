#include "includes/SDL.h"
#include "includes/SDL_ttf.h"
#include "includes/SDL_mixer.h"
#include <iostream>
#include <string.h>

void swapPlayer(int &playerNumber){
    if(playerNumber == 1){
        playerNumber = 8;
    }
    else if(playerNumber == 8){
        playerNumber = 1;
    }
}

void printArray(int arr[3][3]){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << arr[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << "\n" << std::endl;
}

void clearBoard(int table[3][3]){
    for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                table[i][j] = {0};
            }
        }

}

bool gameDraw(int table[3][3]){
    int total = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            total += table[i][j];
        }
    }
    if(total == 37){
        return true;
    }
    return false;
}

int playerWin(int table[3][3]){
    int rowTotal = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            rowTotal += table[i][j];   
        }
        if(rowTotal == 3){
            return 1;
        }
        else if(rowTotal == 24){
            return 2;
        }
        rowTotal = 0;
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            rowTotal += table[j][i];
        }
        if(rowTotal == 3){
            return 1;
        }
        else if(rowTotal == 24){
            return 2;
        }
        rowTotal = 0;
    }
    
    rowTotal = table[0][0] + table[1][1] + table[2][2];
    if(rowTotal == 3){
        return 1;
    }
    else if(rowTotal == 24){
        return 2;
    }
    
    rowTotal = table[0][2] + table[1][1] + table[2][0];
    if(rowTotal == 3){
        return 1;
    }
    else if(rowTotal == 24){
        return 2;
    }
    
    return 0;
}

void audio(int track){
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    Mix_Chunk *click = Mix_LoadWAV("click.mp3");
    Mix_PlayChannel(-1, click, 0);
}

void gameEventHandle(bool &isRunning, int table[3][3], int &mouseX, int &mouseY, int &playerNumber, bool playerOneGo, bool playing){
    SDL_Event event;
    if(SDL_WaitEvent(&event)){
		    switch(event.type){
                case SDL_QUIT:
			        isRunning = false;
                break;
                case SDL_KEYDOWN:
                    if(event.key.keysym.sym == SDLK_r){
                        clearBoard(table);
                            playerNumber = 1;
                            playing = true;
                    }
                break;
                case SDL_MOUSEMOTION:
                    SDL_GetMouseState(&mouseX, &mouseY);
                    if(mouseX < 200 && mouseY < 200 && table[0][0] == 0){
                        table[0][0] = 500;
                    }
                    else if(mouseX < 200 && mouseY > 200 && mouseY < 400 && table[1][0] == 0 ){
                        table[1][0] = 500;
                    }
                    else if(mouseX < 200 && mouseY > 400 && mouseY < 600 && table[2][0] == 0 ){
                        table[2][0] = 500;
                    }

                    else if(mouseX > 200 && mouseX < 400 && mouseY < 200 && table[0][1] == 0 ){
                        table[0][1] = 500;
                    }
                    else if(mouseX > 200 && mouseX < 400 && mouseY > 200 && mouseY < 400 && table[1][1] == 0 ){
                        table[1][1] = 500;
                    }
                    else if(mouseX > 200 && mouseX < 400 && mouseY > 400 && mouseY < 600 && table[2][1] == 0 ){
                        table[2][1] = 500;
                    }

                    else if(mouseX > 400 && mouseX < 600 && mouseY < 200 && table[0][2] == 0 ){
                        table[0][2] = 500;
                    }
                    else if(mouseX > 400 && mouseX < 600 && mouseY > 200 && mouseY < 400 && table[1][2] == 0 ){
                        table[1][2] = 500;
                    }
                    else if(mouseX > 400 && mouseX < 600 && mouseY > 400 && mouseY < 600 && table[2][2] == 0 ){
                        table[2][2] = 500;
                    }

                break; 
                case SDL_MOUSEBUTTONUP:
                    audio(2);
                    SDL_GetMouseState(&mouseX, &mouseY);
                    if(mouseX < 200 && mouseY < 200 && table[0][0] == 0){
                        table[0][0] = playerNumber;
                        swapPlayer(playerNumber);
                    }
                    if(mouseX < 200 && mouseY > 200 && mouseY < 400 && table[1][0] == 0){
                        table[1][0] = playerNumber;
                        swapPlayer(playerNumber);
                    }
                    if(mouseX < 200 && mouseY > 400 && mouseY < 600 && table[2][0] == 0){
                        table[2][0] = playerNumber;
                        swapPlayer(playerNumber);
                    }

                    if(mouseX > 200 && mouseX < 400 && mouseY < 200 && table[0][1] == 0){
                        table[0][1] = playerNumber;
                        swapPlayer(playerNumber);
                    }
                    if(mouseX > 200 && mouseX < 400 && mouseY > 200 && mouseY < 400 && table[1][1] == 0){
                        table[1][1] = playerNumber;
                        swapPlayer(playerNumber);
                    }
                    if(mouseX > 200 && mouseX < 400 && mouseY > 400 && mouseY < 600 && table[2][1] == 0){
                        table[2][1] = playerNumber;
                        swapPlayer(playerNumber);
                    }

                    if(mouseX > 400 && mouseX < 600 && mouseY < 200 && table[0][2] == 0){
                        table[0][2] = playerNumber;
                        swapPlayer(playerNumber);
                    }
                    if(mouseX > 400 && mouseX < 600 && mouseY > 200 && mouseY < 400 && table[1][2] == 0){
                        table[1][2] = playerNumber;
                        swapPlayer(playerNumber);
                    }
                    if(mouseX > 400 && mouseX < 600 && mouseY > 400 && mouseY < 600 && table[2][2] == 0){
                        table[2][2] = playerNumber;
                        swapPlayer(playerNumber);
                    }
                    printArray(table);
                break;
            }
        }
}


void drawBox(SDL_Renderer *renderer, int x, int y, int &colour){
    SDL_Rect rect;
    rect.w = 180, rect.h = 180;
    rect.x = 10 + x, rect.y = 10 + y;
    if(colour == 8){
        SDL_SetRenderDrawColor(renderer, 175, 85, 58, SDL_ALPHA_OPAQUE);
    }
    else if(colour == 500){
        SDL_SetRenderDrawColor(renderer, 30, 30, 30, SDL_ALPHA_OPAQUE);
        SDL_RenderFillRect(renderer, &rect);    
        colour = 0;
    }
    else{
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    }
    SDL_RenderFillRect(renderer, &rect);
}

void grid(SDL_Renderer *renderer){
    SDL_SetRenderDrawColor(renderer, 44, 44, 44, SDL_ALPHA_OPAQUE); //just off black 
    //grid
    SDL_RenderDrawLine(renderer, 200, -5, 200, 605);
    SDL_RenderDrawLine(renderer, 400, -5, 400, 605);
    SDL_RenderDrawLine(renderer, -5, 200, 605, 200);
    SDL_RenderDrawLine(renderer, -5, 400, 605, 400);
}
void playGame(SDL_Renderer *renderer, int table[3][3], bool &playerOneGo, int &playerNumber){
    grid(renderer);
    //draw to white for the first players turn
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    if(table[0][0] != 0){
        drawBox(renderer, 0, 0, table[0][0]);
    }        
    if(table[1][0] != 0){
        drawBox(renderer, 0, 200, table[1][0]);
    }
    if(table[2][0] != 0){
        drawBox(renderer, 0, 400, table[2][0]);
    }

    if(table[0][1] != 0){
        drawBox(renderer, 200, 0, table[0][1]);
    }        
    if(table[1][1] != 0){
        drawBox(renderer, 200, 200, table[1][1]);
    }
    if(table[2][1] != 0){
        drawBox(renderer, 200, 400, table[2][1]);
    }

    if(table[0][2] != 0){
        drawBox(renderer, 400, 0, table[0][2]);
    }        
    if(table[1][2] != 0){
        drawBox(renderer, 400, 200, table[1][2]);
    }
    if(table[2][2] != 0){
        drawBox(renderer, 400, 400, table[2][2]);
    }
        
}

void drawEndScreen(SDL_Renderer *renderer, int win){
    std::string winMessage;
    int texW = 0;
    int texH = 0;
    
    switch(win){
        case 1:
            winMessage = "Player One Wins!!";
        break;        
        case 2:
            winMessage = "Player Two Wins!!";
        break;
        default:
            winMessage = "You drew!!";
        break;
    }

    SDL_SetRenderDrawColor(renderer, 22, 22, 22, 255);
    SDL_RenderClear(renderer);
    
    TTF_Font * font = TTF_OpenFont("AmaticSC-Regular.ttf", 500);
    SDL_Color textColour = {175, 175, 175};
    SDL_Surface * surface = TTF_RenderText_Blended(font, winMessage.c_str(), textColour);
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect = {75, 75, 450, 200};
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
    

    SDL_SetRenderDrawColor(renderer, 44, 44, 44, 255);
    SDL_Rect background = {150, 300, 300, 100};
    surface = TTF_RenderText_Blended(font, "Press \"R\"", textColour);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_RenderFillRect(renderer, &background);
    SDL_RenderCopy(renderer, texture, NULL, &background);
    TTF_CloseFont(font);
}

int main(){
    
    int table[3][3] = {{{0}}};
    printArray(table);
    bool playerOneGo = true;
    int playerNumber = 1;

    bool playing = true;
    bool isRunning = false;
    SDL_Renderer *renderer;
    SDL_Window *window;
    int mouseX, mouseY;
    
    TTF_Init();
    SDL_Init(SDL_INIT_EVERYTHING);
    
    Uint32 windowFlags = SDL_WINDOW_SHOWN | SDL_RENDERER_PRESENTVSYNC;
    window = SDL_CreateWindow(
            "TickTackToe",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            600,
            600,
            windowFlags);
    SDL_SetWindowResizable(window, SDL_FALSE);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer){
        std::cout << "renderer created!" << std::endl;
        isRunning = true;
    }
    else{
        isRunning = false;
    }

    while(isRunning){
	    gameEventHandle(isRunning, table, mouseX, mouseY, playerNumber, playerOneGo, playing);
        SDL_SetRenderDrawColor(renderer, 22, 22, 22, 255);
        SDL_RenderClear(renderer);

        playGame(renderer, table, playerOneGo, playerNumber);

        int win = playerWin(table);
        if(win == 1){
            SDL_SetRenderDrawColor(renderer, 22, 22, 22, 255);
            drawEndScreen(renderer, win);

        }
        else if(win == 2){
            SDL_SetRenderDrawColor(renderer, 22, 22, 22, 255);
            drawEndScreen(renderer, win);

        }
        else{
            if(gameDraw(table)){
                SDL_SetRenderDrawColor(renderer, 22, 22, 22, 255);
                drawEndScreen(renderer, win);
            }
        }

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    Mix_Quit();
    TTF_Quit();
    SDL_Quit();

    
    return 0;
}
