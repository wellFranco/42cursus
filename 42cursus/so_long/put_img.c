#include "so_long.h"

void	draw_background(t_data *data, char *image_path, int width, int height)
{
	void	*img_ptr;
	int		img_width;
	int		img_height;

	img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			image_path, &img_width, &img_height);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img_ptr, width, height);
	free(img_ptr);
}