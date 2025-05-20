#include "../includes/cub3D.h"

void    *ft_music(void *arg)
{
    SDL_Init(SDL_INIT_AUDIO);
    SDL_AudioSpec wav_spec;
    Uint32 wav_length;
    Uint8 *wav_buffer;

    SDL_LoadWAV((char *)arg, &wav_spec, &wav_buffer, &wav_length);

    SDL_OpenAudio(&wav_spec, NULL);

    SDL_PauseAudio(0);
    SDL_QueueAudio(1, wav_buffer, wav_length);

    SDL_Delay(3000);

    SDL_CloseAudio();
    SDL_FreeWAV(wav_buffer);
    SDL_Quit();
    return (NULL);
}
