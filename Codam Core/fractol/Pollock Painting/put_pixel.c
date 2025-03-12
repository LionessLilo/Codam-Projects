#include "./MLX42/include/MLX42/MLX42.h"

void	fill_image(mlx_image_t *img);

int	main(void)
{
	// init
	mlx_t	*mlx_window = mlx_init(1000, 1000, "TESTING", true);
	// Img (canvas) to draw pixels
	mlx_image_t	*img = mlx_new_image(mlx_window, 500, 500);
	// Put pixel
	fill_image(img);
	mlx_put_pixel(img, 250, 250, 0xFF0000FF);
	//Tell window to display the image
	mlx_image_to_window(mlx_window, img, 250, 250);
	// Keep the window open
	mlx_loop(mlx_window);
	// Exit
	mlx_terminate(mlx_window);
	return (0);
}

void	fill_image(mlx_image_t *img)
{
	for (int y = 0; y < img->height; y++)
	{
		for (int x = 0; x < img->width; x++)
		{
			mlx_put_pixel(img, x, y, 0xFFFFFFFF); // White background
		}
	}
}
