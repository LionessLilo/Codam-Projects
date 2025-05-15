#include "./MLX42/include/MLX42/MLX42.h"
#include <stdio.h>

typedef struct

void	my_scroll_funct(double xdelta, double y_delta, void *param)
{
	(void)xdelta;
	(void)param;

	if (y_delta > 0)
		printf("Scrolled up\n");
	else if (y_delta < 0)
		printf("Scrolled down\n");
}

int	main(void)
{
	void	*mlx;
	void	*image;
	int		image_instance;

	mlx = mlx_init(800, 400, "mlx_sandbox", false);
	image = mlx_new_image(mlx, 64, 64);
	mlx_scroll_hook(mlx, (void *)my_scroll_funct, NULL);
	int y = 0;
	while (y < 50)
	{
		int x = 0;
		while (x < 50)
		{
			mlx_put_pixel(image, x, y, 0xFFFFFFFF);
			x++;
		}
		y++;
	}
	image_instance = mlx_image_to_window(mlx, image, 400, 200);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
