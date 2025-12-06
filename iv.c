#include<stdio.h>
#include<stdlib.h>
#include<SDL2/SDL.h>
#include<string.h>

// gcc -o iv iv.c `sdl2-config --cflags --libs`

typedef struct dimension{
    int x;
    int y;
} dim;


dim get_dimension(FILE* fp)
{   
    dim dimension;
    int c;
    char buff[16];
    if (!fgets(buff, sizeof(buff), fp)) {  
            exit(1);
        }
    //check the image format
    if (buff[0] != 'P' || buff[1] != '6') {
         fprintf(stderr, "Invalid image format (must be 'P6')\n");
         exit(1);
    }
    //check for comments
    c = fgetc(fp);
    while (c == '#') {
    while (fgetc(fp) != '\n') ;
        c = fgetc(fp);
    }
    ungetc(c,fp);
    //read image size information
    if (fscanf(fp, "%d %d", &dimension.x, &dimension.y) != 2) {
        dimension.x = 0;
        dimension.y = 0;
        exit(1);
    }
    //since by observation our file pointer is currently at '\n'
    (void)fgetc(fp); //so we need to move it by 1 to next character
    // while ((c = fgetc(fp)) != '\n' && c != EOF);  // this will move the pointer to next line , and the pointer will advance (is pointing at '\n' + 1)
    
    // because above line is commented the pointer is currently at 2 of 255;
    int color_value;
    fscanf(fp, "%3d", &color_value); // 255
    //pointer at '\n'
    if (color_value != 255)
    {
        printf("\nThe color format should be 255. \n");
    }
    printf("%d",color_value);
    (void)fgetc(fp); // this will move the pointer to next line , and the pointer will advance (is pointing at '\n' + 1) or beginning of the R value of a pixel.
    return dimension;
}
typedef struct RGB{
    Uint8 r , g, b;
} RGB;

int main()
{
    int buffer;

    FILE* fp = stdin;
    dim dimension = get_dimension(fp);
    const int width = dimension.x;
    const int height = dimension.y;

    printf("\n===========================\n");
    printf("%d, %d\n", width, height);
    printf("===========================\n");

    SDL_Window *p_window = SDL_CreateWindow("Image Viewer",  SDL_WINDOWPOS_CENTERED,  SDL_WINDOWPOS_CENTERED, width, height,0);
    SDL_Surface *p_surface =  SDL_GetWindowSurface(p_window);

    SDL_Rect *p_rect = malloc(sizeof(SDL_Rect));
    *p_rect = (SDL_Rect){.x = 40, .y = 40, .w = 1, .h = 1};
    int* colorRGB = (int*)calloc(3, sizeof(int));

    Uint8 r,g,b;
    Uint32 color;
    for (int y = 0; y < height ; y++)
    {
        for (int x = 0; x < width ; x++)
        {   
            r = (char)fgetc(fp);
            g = (char)fgetc(fp);
            b = (char)fgetc(fp); 
            color = SDL_MapRGB(p_surface->format, r, g, b);
            p_rect->x = x;
            p_rect->y = y;
            SDL_FillRect(p_surface, p_rect , color);
        }
    }
    
    SDL_UpdateWindowSurface(p_window);
    int True = 1;
    while(True){
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                True = 0;
            }   
        }
        SDL_Delay(100);
    }
}