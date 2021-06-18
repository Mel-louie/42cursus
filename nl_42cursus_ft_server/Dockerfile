# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdesfont <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/04 15:52:34 by mdesfont          #+#    #+#              #
#    Updated: 2020/01/31 10:51:08 by mdesfont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Image
FROM debian:buster

# Copy my source folder to a source folder on container
COPY	./srcs/start.sh ./
COPY	./srcs/ ./srcs/

# Dowmload and install packages
RUN		apt-get update && apt-get upgrade -y && \
		apt-get -y install wget nginx mariadb-server mariadb-client && \
		apt-get -y install php7.3-fpm php7.3-mysql php-mbstring php-zip && \
		apt-get clean

# Config nginx
RUN		mkdir -p /var/www/localhost
COPY	/srcs/nginx.conf /etc/nginx/sites-available/localhost
RUN		ln -s /etc/nginx/sites-available/localhost /etc/nginx/sites-enabled/localhost

# Config and start php
RUN		service php7.3-fpm start

# Setup SSL with mkcert
RUN		mkdir ~/mkcert && \
		cd ~/mkcert && \
		wget https://github.com/FiloSottile/mkcert/releases/download/v1.4.1/mkcert-v1.4.1-linux-amd64 && \
		mv mkcert-v1.4.1-linux-amd64 mkcert && \
		chmod 755 mkcert && \
		./mkcert -install && \
		./mkcert localhost

# Install wordpress and config
COPY	srcs/wordpress-5.3.2.tar.gz ./
RUN		mkdir -p /var/www/localhost/wordpress && \
		tar -zxvf wordpress-5.3.2.tar.gz --strip-components=1 -C /var/www/localhost/wordpress && \
		chown -R www-data:www-data /var/www/localhost/wordpress && \
		chmod 755 -R /var/www/localhost/wordpress/
COPY	/srcs/wp-config.php /var/www/localhost/wordpress

# Install phpmyadmin and config
RUN		mkdir -p /var/www/localhost/phpmyadmin && \
		wget https://files.phpmyadmin.net/phpMyAdmin/4.9.4/phpMyAdmin-4.9.4-all-languages.tar.gz && \
		tar -zxvf phpMyAdmin-4.9.4-all-languages.tar.gz --strip-components=1 -C /var/www/localhost/phpmyadmin && \
		mkdir -p /var/www/localhost/phpmyadmin/tmp && \
		chown -R www-data:www-data /var/www/localhost/phpmyadmin
COPY	/srcs/config.inc.php /var/www/localhost/phpmyadmin/
COPY	/srcs/index.php /var/www/localhost/index.php

#docker build . -t (name)
#docker run -p 80:80 -p 443:443 -ti (name)

CMD		bash start.sh
