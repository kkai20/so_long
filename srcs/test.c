#define WINDOW_WIDTH 1024
#define WINDOW_HIGHT 860

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};


#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	main(void)
{
	void	*mlx;
	void	*img;
	void	*mlx_win;
	char	*relative_path = "./test.xpm";
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
	mlx_loop(mlx);
}