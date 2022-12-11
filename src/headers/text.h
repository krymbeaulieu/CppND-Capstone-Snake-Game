#ifndef TEXT_H
#define TEXT_H

#include <string>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>

class Text
{
public:
    Text(SDL_Renderer *renderer, const std::string font_path, int font_size, const std::string &message, const SDL_Color &color);
    SDL_Texture *load_font(SDL_Renderer *renderer, const std::string &font_path, int font_size, const std::string &message_text, const SDL_Color &color);
    void set_text_rect(int x, int y);
    const SDL_Rect get_text_rect();
    SDL_Texture *get_text_texture();
    SDL_Rect center_text(size_t screen_height, size_t screen_width);
    std::string get_font_path();

private:
    mutable SDL_Rect text_rect_;
    SDL_Texture *text_texture_;
};
#endif