#include "./MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <time.h>

int	main(void)
{
	srand(time(NULL));
	mlx_t	*mlx_window = mlx_init(1000, 1000, "Pollock Painting", true);
	mlx_image_t	*img = mlx_new_image(mlx_window, 1000, 1000);
	int	y = 1000 * 0.1;
	while (y < (1000 * 0.9))
	{
		int x = 1000 * 0.1;
		while (x < (1000 * 0.9))
		{
			mlx_put_pixel(img, x, y, (rand() % 0x1000000));
			x++;
		}
		y++;
	}
	mlx_image_to_window(mlx_window, img, 0, 0);
	mlx_loop(mlx_window);
	mlx_terminate(mlx_window);
	return (0);
}
