
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_data
{
	void *mlx;
	void *win;
	void *img;
	char *addr;
	int index;
	int bits_per_pixel;
	int line_length;
	int endian;

} t_data;

int close(int keycode, t_data *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
}

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int render_next_frame(void *vars)
{
	t_data *data;

	data = (t_data *)vars;
	data->index++;
	my_mlx_pixel_put(data, data->index%100, 5, 0x00000000);
	my_mlx_pixel_put(data, data->index%100 + 1, 5, 0x00FF0000);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

int main(void)
{
	t_data vars;
	int width = 800;
	int height = 500;
	char *relative_path = "./test.xpm";
	int img_width;
	int img_height;

	vars.index = 0;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, width, height, "so_long");
	// vars.img = mlx_new_image(vars.mlx, width, height);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, &vars.line_length, &vars.endian);
	// mlx_hook(vars.win, 2, 1L << 0, close, &vars);
	// mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	vars.img = mlx_xpm_file_to_image(vars.mlx, relative_path, &img_width, &img_height);
	mlx_loop(vars.mlx);
}
