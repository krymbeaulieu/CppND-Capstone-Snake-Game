
#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "headers/renderer.h"
#include "headers/text.h"

//! Makes a text class obj without a renderer
Text::Text(const std::string font_path, int font_size, const std::string &message, const SDL_Color &color){
    message_ = message;
    font_path_ = font_path;
    font_size_ = font_size;
    color_ = color;
    need_to_load_texture = true;
    // font_path_ = font_path;
    // std::cout << "GOT TO THIS CONSTRUCTOR" << std::endl;
    // // text_surface_ = load_font_surface(font_path,font_size,message,color);
    // TTF_Font *font = TTF_OpenFont(font_path.c_str(),font_size);
    // if(!font){
    //     std::cerr << "Unable to load font" << std::endl;
    // }
    // auto text_surface_ = TTF_RenderText_Solid(font,message.c_str(),color);
    // text_rect_ = text_surface_->clip_rect; // use the rect from the surface to get the actual width and heigth from the font size
}

//! Makes a text class obj and loads the font so it is ready to render
Text::Text(SDL_Renderer *renderer, const std::string font_path, int font_size, const std::string &message, const SDL_Color &color){
    message_ = message;
    text_texture_ = load_font_texture(renderer, font_path,font_size,message,color);
    SDL_QueryTexture(text_texture_,nullptr,nullptr,&text_rect_.w,&text_rect_.h);
    need_to_load_texture = false;

}

//! load a font surface for render later
SDL_Surface *Text::load_font_surface(const std::string &font_path, int font_size, const std::string &message_text, const SDL_Color &color){
    TTF_Font *font = TTF_OpenFont(font_path.c_str(),font_size);
    if(!font){
        std::cerr << "Unable to load font" << std::endl;
    }
    auto text_surface = TTF_RenderText_Solid(font,message_text.c_str(),color);
    if(!text_surface){
        std::cerr << "Unable to make Text surface" << std::endl;
    }
    text_rect_ = text_surface->clip_rect;
    return text_surface;
}
//! load a font internally
SDL_Surface *Text::load_font_surface(){
    TTF_Font *font = TTF_OpenFont(font_path_.c_str(),font_size_);
    if(!font){
        std::cerr << "Unable to load font" << std::endl;
    }
    auto text_surface = TTF_RenderText_Solid(font,message_.c_str(),color_);
    if(!text_surface){
        std::cerr << "Unable to make Text surface" << std::endl;
    }
    text_rect_ = text_surface->clip_rect;
    return text_surface;
}
//! load a font for render later (probably soon since renderer is available)
SDL_Texture *Text::load_font_texture(SDL_Renderer *renderer, const std::string &font_path, int font_size, const std::string &message_text, const SDL_Color &color){
    
    text_surface_ = load_font_surface(font_path,font_size,message_text,color);
    auto text_texture = SDL_CreateTextureFromSurface(renderer, text_surface_);
    if(!text_texture){
        std::cerr << "Unable to make Text texture" << std::endl;
    }
    SDL_FreeSurface(text_surface_);
    return text_texture;
}
//! Load a font from an already existing surface
SDL_Texture *Text::load_font_texture(SDL_Renderer *renderer){
    auto text_texture = SDL_CreateTextureFromSurface(renderer, text_surface_);
    if(!text_texture){
        std::cerr << "Unable to make Text texture" << std::endl;
    }
    SDL_FreeSurface(text_surface_);
    return text_texture;
}

//! in the case of text that should move, the rect can change
void Text::set_text_rect_pos(int x, int y){
    text_rect_.x = x;
    text_rect_.y = y;
}
//! get the texture, for rendering later
SDL_Texture *Text::get_text_texture(){
    return text_texture_;
}

void Text::set_text_texture(SDL_Texture *Texture){
    text_texture_ = Texture;
    need_to_load_texture = false;

}
//! get the text's rect
const SDL_Rect Text::get_text_rect(){
    return text_rect_;
}
SDL_Surface *Text::get_text_surface(){
    return text_surface_;
}
void Text::set_text_surface(SDL_Surface *surface){
    text_surface_ = surface;
}
void Text::set_message(std::string message){
    message_ = message;
}
std::string Text::get_message(){
    return message_;
}
//! function to center text (provide rect values when rendering). give the screen's w/h to make the rect calc
SDL_Rect Text::center_text(size_t screen_width, size_t screen_height){
SDL_Rect centered_loc = { (int) (screen_width - text_rect_.w) / 2, (int) (screen_height - text_rect_.h) / 2, 0, 0 };
return centered_loc;
}


// TextInput::TextInput(){
//     //Initialize the string
//     str = "";
//     //Initialize the surface
//     text_surface_ = NULL;    
// }

// TextInput::~TextInput(){
//     SDL_FreeSurface(text_surface_);
// }

