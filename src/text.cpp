
#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "headers/renderer.h"
#include "headers/text.h"

//! Makes a text class obj and loads the font so it is ready to render
Text::Text(SDL_Renderer *renderer, const std::string font_path, int font_size, const std::string &message, const SDL_Color &color){
    text_texture_ = load_font(renderer, font_path,font_size,message,color);
    SDL_QueryTexture(text_texture_,nullptr,nullptr,&text_rect_.w,&text_rect_.h);
}

//! load a font for render later
SDL_Texture *Text::load_font(SDL_Renderer *renderer, const std::string &font_path, int font_size, const std::string &message_text, const SDL_Color &color){
    
    TTF_Font *font = TTF_OpenFont(font_path.c_str(),font_size);
    if(!font){
        std::cerr << "Unable to load font" << std::endl;
    }
    auto text_surface = TTF_RenderText_Solid(font,message_text.c_str(),color);
    if(!text_surface){
        std::cerr << "Unable to make Text surface" << std::endl;
    }
    auto text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
    if(!text_texture){
        std::cerr << "Unable to make Text texture" << std::endl;
    }
    SDL_FreeSurface(text_surface);
    return text_texture;
}
//! in the case of text that should move, the rect can change
void Text::set_text_rect(int x, int y){
    text_rect_.x = x;
    text_rect_.y = y;
}
//! get the texture, for rendering later
SDL_Texture *Text::get_text_texture(){
    return text_texture_;
}
//! get the text's rect
const SDL_Rect Text::get_text_rect(){
    return text_rect_;
}

//! function to center text (provide rect values when rendering). give the screen's w/h to make the rect calc
SDL_Rect Text::center_text(size_t screen_width, size_t screen_height){
SDL_Rect centered_loc = { (screen_width - text_rect_.w) / 2, (screen_height - text_rect_.h) / 2, 0, 0 };
return centered_loc;
}