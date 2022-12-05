#include "headers/text.h"
#include <iostream>

Text(int font_size, const std::string &message, const SDL_Color &color){
    
};

void set_text_rect(int x, int y){
    _text_rect.x = x;
    _text_rect.y = y;
}

SDL_Rect get_text_rect(){
    return _text_rect;
}

std::string get_font_path(){
    return _font_path;
}

// void display(int x, int y, SDL_Renderer *renderer) {
//     _text_rect.x = x;
//     _text_rect.y = y; 
//     // may need const
//     SDL_RenderCopy()
// };