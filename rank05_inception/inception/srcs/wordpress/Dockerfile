FROM alpine:3.12

RUN			apk update && apk upgrade && apk add --no-cache		\
											php7				\
											php7-fpm			\
											php7-phar			\
											php7-json			\
											php7-mysqli			\
											php7-curl			\
											php7-iconv			\
											php7-pecl-mailparse	\
											curl				\
											mariadb-client		\
											bash				\
											wget				\
											curl				\
											vim					\
											sudo

RUN			curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
			chmod +x wp-cli.phar &&	\
			cp wp-cli.phar /usr/bin/wp 

WORKDIR		/var/www/wordpress

ENV			MYSQL_DATABASE="wordpress"			\
			MYSQL_USER="wordpress"				\
			MYSQL_PASSWORD="wordpress"			\
			MYSQL_HOST="mariadb"					\
			MYSQL_PORT=3306						\
													\
			WP_URL="mdesfont.42.fr"				\
			WP_TITLE="inception"			\
			WP_ADMIN_USER="mel"					\
			WP_ADMIN_PWD="pass"					\
			WP_ADMIN_EMAIL="mel@aaa.com"

RUN			wp core download

RUN			adduser -S nginx &&	\
			addgroup -S nginx

RUN			mkdir /var/log/php-fpm 
COPY		./config/php-fpm.conf /etc/php7/php-fpm.conf
COPY		./config/www.conf /etc/php7/php-fpm.d/www.conf

COPY		./config /config
COPY		./config/wp-config.php ./
COPY		./scripts /tmp/scripts
RUN			chmod -R +x /tmp/scripts

EXPOSE		9000

ENTRYPOINT ["bash", "/tmp/scripts/setup_wordpress.sh"]