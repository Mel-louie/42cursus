FROM debian:buster

#Install nginx
# openssl: https certificates
RUN apt-get update && apt-get -y install nginx openssl \
&& rm -rf /var/lib/apt/lists/*
# del apt cache ^

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/nginx.key -out /etc/ssl/certs/nginx.crt -subj "/C=FR/ST=Paris/L=Paris/O=42/OU=mdesfont/CN=mdesfont.42.fr"

#Copy the conf inside nginx
COPY nginx.conf etc/nginx/conf.d/nginx.conf

EXPOSE 443

#Command which is launch when the container starts
CMD ["nginx", "-g", "daemon off;"]
