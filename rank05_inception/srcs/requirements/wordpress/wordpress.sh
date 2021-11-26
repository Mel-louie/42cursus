#!/bin/bash

printf "\nWordpress downloading\n"
#Install latest wordpress
wget -c http://wordpress.org/latest.tar.gz
tar -xzvf latest.tar.gz
rm -rf latest.tar.gz

#Update configuration file
rm -rf /etc/php/7.3/fpm/pool.d/www.conf
mv www.conf /etc/php/7.3/fpm/pool.d/

cp wp-config.php var/www/wordpress/


exec "$@"