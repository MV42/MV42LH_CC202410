#include "../mlx_linux/mlx.h"
#include <math.h>
#include <stdlib.h>

#define WIDTH  200
#define HEIGHT 100

typedef struct s_data {
    void *mlx;
    void *win;
    void *img;
    char *addr;
    int bpp;
    int line_length;
    int endian;
} t_data;

void put_pixel(t_data *data, int x, int y, double alpha)
{
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
    {
        int intensity = (int)(255 * alpha);
        int color = (255 << 24) | (intensity << 16) | (intensity << 8) | intensity;
        char *dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
        *(unsigned int*)dst = color;
    }
}

void draw_line_wu(t_data *data, int x0, int y0, int x1, int y1)
{
    double dx = x1 - x0;
    double dy = y1 - y0;
    int steep = fabs(dy) > fabs(dx);
    
    if (steep) { // Si la pente est trop forte, on transpose
        int temp;
        temp = x0; x0 = y0; y0 = temp;
        temp = x1; x1 = y1; y1 = temp;
        temp = dx; dx = dy; dy = temp;
    }
    
    if (x0 > x1) { // Assurer le tracé de gauche à droite
        int temp;
        temp = x0; x0 = x1; x1 = temp;
        temp = y0; y0 = y1; y1 = temp;
    }
    
    double gradient = dy / dx;
    double y = y0 + 0.5;

    for (int x = x0; x <= x1; x++) {
        int yf = floor(y);
        double alpha1 = 1.0 - (y - yf);
        double alpha2 = y - yf;
        
        if (steep) { // Si on avait transposé, on remet à l'endroit
            put_pixel(data, yf, x, alpha1);
            put_pixel(data, yf + 1, x, alpha2);
        } else {
            put_pixel(data, x, yf, alpha1);
            put_pixel(data, x, yf + 1, alpha2);
        }
        y += gradient;
    }
}

int close_window(t_data *data)
{
    mlx_destroy_window(data->mlx, data->win);
    exit(0);
}

int main()
{
    t_data data;

    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Wu Antialiased Line");
    data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
    data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.line_length, &data.endian);

	draw_line_wu(&data, 10, 10, 150, 10);
	draw_line_wu(&data, 10, 10, 150, 20);
	draw_line_wu(&data, 10, 10, 150, 30);
	draw_line_wu(&data, 10, 10, 150, 40);
    draw_line_wu(&data, 10, 10, 150, 50);
    draw_line_wu(&data, 10, 10, 150, 60);
    draw_line_wu(&data, 10, 10, 150, 70);
    draw_line_wu(&data, 10, 10, 150, 80);
    draw_line_wu(&data, 10, 10, 150, 90);
    draw_line_wu(&data, 10, 10, 150, 100);
    
    mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
    mlx_hook(data.win, 17, 0, close_window, &data);
    mlx_loop(data.mlx);
    
    return 0;
}

