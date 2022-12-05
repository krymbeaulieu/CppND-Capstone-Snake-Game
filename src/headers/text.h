#ifndef TEXT_H
#define TEXT_H

#include <string>
// #include "SDL_ttf.h"
#include <SDL/SDL.h>

class Text
{
public:
    Text(std::string font_path, int font_size, const std::string &message, const SDL_Color &color);
    // SDL_Texture *load_font(const std::string &font_path, int font_size, const std::string &message_text, const SDL_Color &color);
    // void display(int x, int y) ; // may need const

    void set_text_rect(int x, int y); 
    SDL_Rect get_text_rect();
    std::string get_font_path();

    const SDL_Color color;
    const std::string message;
    int font_size;
private:
    SDL_Rect _text_rect;
    std::string _font_path; //has a path, probably shouldn't be public
    
};
#endif