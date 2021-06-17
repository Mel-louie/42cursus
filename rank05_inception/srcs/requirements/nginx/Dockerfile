#https://wiki.alpinelinux.org/wiki/Nginx
FROM alpine:3.12

# EXPOSE instruction is to indicate the port needs to be published
# We still need to use the --publish option explicitly
EXPOSE 443

# update && install (nginx, openssl)
RUN apk update --no-cache \
	&& apk upgrade --no-cache \
	&& apk add nginx openssl \
	&& rm -rf /var/cache/apk/*

# create user && group for nginx
RUN adduser -D -g 'www' www \
	&& mkdir /www \
	&& chown -R www:www /var/lib/nginx \
	&& chown -R www:www /www \
	&& mkdir -p /var/run/nginx

# SSL
#RUN mkdir -p /etc/nginx/ssl \
#	&& openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes \
#	   -out /etc/nginx/ssl/inception.pem -keyout /etc/nginx/ssl/inception.key \
#	   -subj "/C=FR/ST=Paris/L=Paris/O=42/OU=IT/CN=inception"

# nginx config
COPY ./conf/nginx.conf /etc/nginx/nginx.conf

# The CMD instruction sets the default command for your image.
# This array form is the preferred format of CMD. Here, nginx refers to the NGINX executable.
# The CMD instruction can also be written in shell form.
# The -g and daemon off are options for NGINX.
# -g: set global configuration directives
# daemon on/off (on by default): determines whether nginx should become a daemon
# explain why it should be off in a container: https://stackoverflow.com/questions/25970711/what-is-the-difference-between-nginx-daemon-on-off-option
# Running NGINX as a single process inside containers is considered a best practice.
CMD ["nginx", "-g", "daemon off;"]