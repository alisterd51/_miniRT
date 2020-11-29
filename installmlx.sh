# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    installmlx.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antoine <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/29 18:26:01 by antoine           #+#    #+#              #
#    Updated: 2020/11/29 18:27:12 by antoine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

git clone https://github.com/42Paris/minilibx-linux.git
cd minilibx-linux
./configure
sudo cp libmlx.a /usr/local/lib/.
sudo cp libmlx_Linux.a /usr/local/lib/.
sudo cp mlx.h /usr/local/include/.
sudo mkdir /usr/local/man/man3
sudo cp man/man3/mlx*.1 /usr/local/man/man3/.
cd ..
rm -rf minilibx-linux
