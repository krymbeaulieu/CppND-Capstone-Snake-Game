#ifndef TEXT_H
#define TEXT_H

#include <string>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>

class Text
{
public:
    Text(SDL_Renderer *renderer, const std::string font_path, int font_size, const std::string &message, const SDL_Color &color);
    Text(const std::string font_path, int font_size, const std::string &message, const SDL_Color &color); // for those times you might not have a renderer available
    SDL_Texture *load_font_texture(SDL_Renderer *renderer, const std::string &font_path, int font_size, const std::string &message_text, const SDL_Color &color);
    SDL_Texture *load_font_texture(SDL_Renderer *renderer); // for when you have the surface available but the renderer came later
    SDL_Surface *load_font_surface(const std::string &font_path, int font_size, const std::string &message_text, const SDL_Color &color);
    SDL_Surface *load_font_surface();
    void set_text_rect_pos(int x, int y);
    const SDL_Rect get_text_rect();
    SDL_Texture *get_text_texture();
    SDL_Rect center_text(size_t screen_height, size_t screen_width);
    std::string get_font_path();
    std::string get_message();
    SDL_Surface *get_text_surface();
    void set_text_surface(SDL_Surface *surface);
    void set_message(std::string message);
    void set_text_texture(SDL_Texture *texture);
    bool need_to_load_texture;


private:
    std::string message_;
    std::string font_path_;
    int font_size_;
    SDL_Color color_;
    mutable SDL_Rect text_rect_;
    SDL_Surface *text_surface_;
    SDL_Texture *text_texture_;
};

#endif