FROM debian:buster

RUN apt-get update && apt-get upgrade \
&& apt-get -y install php7.3-fpm php7.3-mysql php-mbstring php-zip && \
rm -rf /var/lib/apt/lists/*
