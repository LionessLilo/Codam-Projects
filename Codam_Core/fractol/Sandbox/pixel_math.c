#include "./MLX42/include/MLX42/MLX42.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define WORLD_WIDTH 100
#define WORLD_HEIGHT 100
#define WORLD_X 25
#define WORLD_Y 75

int	main(void)
{
	void	*mlx;
	void	*image;
	int		image_instance;
	int		screen_x;
	int		screen_y;

	screen_x = (int)(((float)WORLD_X / WORLD_WIDTH) * SCREEN_WIDTH);
	screen_y = (int)(((float)WORLD_Y / WORLD_HEIGHT) * SCREEN_HEIGHT);
	mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "pixel_math", false);
	image = mlx_new_image(mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	mlx_put_pixel(image, screen_x, screen_y, 0xFFFFFFFF);
	image_instance = mlx_image_to_window(mlx, image, 0, 0);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}