#include "./MLX42/include/MLX42/MLX42.h"
#include <stdio.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

double	g_zoom = 1.0;
void	*mlx;

void	draw_square(void *image, double g_zoom);
void	clear_image(mlx_image_t *image);

void	clear_image(mlx_image_t *image)
{
	uint32_t x, y;

	y = 0;
	while (y < image->height)
	{
		x = 0;
		while (x < image->width)
		{
			mlx_put_pixel(image, x, y, 0x00000000); // Fully transparent or black
			x++;
		}
		y++;
	}
}

void	my_scroll_funct(double xdelta, double y_delta, void *param)
{
	(void)xdelta;
	mlx_image_t *image = (mlx_image_t *)param;

	if (y_delta > 0)
		g_zoom *= 1.1; // Zoom in
	else if (y_delta < 0)
		g_zoom /= 1.1; // Zoom out

	clear_image(image);
}


void	draw_square(void *image, double g_zoom)
{
	int		x, y;
	int		size = 50 * g_zoom;

	y = 0;
	while (y < size && y < (int)((mlx_image_t *)image)->height)
	{
		x = 0;
		while (x < size && x < (int)((mlx_image_t *)image)->width)
		{
			mlx_put_pixel((mlx_image_t *)image, x, y, 0xFFFFFFFF);
			x++;
		}
		y++;
	}
}

int	main(void)
{
	
	mlx_image_t	*image;

	
	mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "Zoom Example", true);
	if (!mlx)
	{
		fprintf(stderr, "Failed to initialize MLX\n");
		return (1);
	}
	image = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!image)
	{
		fprintf(stderr, "Failed to create image\n");
		mlx_terminate(mlx);
		return (1);
	}
	draw_square(image, g_zoom);
	mlx_image_to_window(mlx, image, 400, 200); //where to place the image in the window
	mlx_scroll_hook(mlx, (void *)my_scroll_funct, image);
	draw_square(image,g_zoom);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
