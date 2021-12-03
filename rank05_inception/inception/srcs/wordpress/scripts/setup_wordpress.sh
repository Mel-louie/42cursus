#!/bin/sh

while ! mariadb -h$MYSQL_HOST -P${MYSQL_PORT} -u$MYSQL_USER -p$MYSQL_PASSWORD; do echo "waiting for db ..."; done
wp core install --url="https://mdesfont.42.fr/" --title="Hello" --admin_user="mel" --admin_password="pass" --admin_email="mel@aaa.com" --skip-email
wp plugin install hello-dolly --activate
wp theme install twentytwenty --activate
wp plugin update --all
wp user create bob bob@aaa.com --role=author --user_pass=bob
wp post create --post_title="Hello" --post_content="friend" --post_status=publish --post_author="bob"

php-fpm7 -F -R
