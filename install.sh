git clone https://github.com/42Paris/minilibx-linux.git
cd minilibx-linux
./configure
sudo cp libmlx.a /usr/local/lib/.
sudo cp libmlx_Linux.a /usr/local/lib/.
sudo cp mlx.h /usr/local/lib/.
sudo mkdir /usr/local/man/man3
sudo cp minilibx-linux/man/man3/mlx*.1 /usr/local/man/man3/.
