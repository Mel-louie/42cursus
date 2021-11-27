FROM debian:buster

#Install nginx
RUN apt-get update && \
	apt-get upgrade -y

RUN apt-get install nginx -y

WORKDIR /tmp/
ENV BUILDDIR=/tmp/build/
RUN mkdir ${BUILDDIR}

COPY srcs/ ${WORKDIR}

# openssl: https certificates
RUN apt-get -y install openssl && \
openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/nginx.key -out /etc/ssl/certs/nginx.crt -subj "/C=FR/ST=Paris/L=Paris/O=42/OU=mdesfont/CN=mdesfont.42.fr"

RUN rm -rf /etc/nginx/sites-enabled/* && \
	mv nginx.conf /etc/nginx/sites-available/nginx.conf && \
	ln -fs /etc/nginx/sites-available/nginx.conf /etc/nginx/sites-enabled/

RUN mv index.html ${BUILDDIR}

EXPOSE 443

RUN chmod -R 777 ${BUILDDIR}

CMD cp -a ${BUILDDIR}. /var/www/ && \
	nginx -g 'daemon off;'
