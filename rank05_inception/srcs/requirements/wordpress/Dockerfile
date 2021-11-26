# FROM debian:buster

# RUN apt-get update && apt-get upgrade \
# && apt-get -y install wget php7.3-fpm php7.3-mysql php-mbstring php-zip && \
# rm -rf /var/lib/apt/lists/*

# COPY www.conf /var/www/html/

# COPY wordpress.sh /usr/local/bin

# RUN mkdir /run/php

# ENTRYPOINT [ "wordpress.sh" ]

# #WORKDIR /var/www/html/

# EXPOSE 9000

# CMD [ "/usr/sbin/php-fpm7.3", "-F" ]

FROM debian:buster

RUN apt-get update && apt-get -y install wget php7.3 php-mysqli php-fpm mariadb-client \
&& wget -c http://wordpress.org/latest.tar.gz && tar -xzvf latest.tar.gz && rm -rf latest.tar.gz

RUN rm -f /var/www/wordpress/wp-config-sample.php

COPY ./wp-config.php ./var/www/wordpress/


COPY ./www.conf /etc/php/7.3/fpm/pool.d

RUN mkdir ./run/php/

CMD ./usr/sbin/php-fpm7.3 -F
