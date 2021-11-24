FROM debian:buster

#Install nginx
# openssl: https certificates
RUN apt-get update && apt-get -y install nginx openssl \
&& rm -rf /var/lib/apt/lists/*
# del apt cache ^

RUN openssl req -x509 -newkey rsa:4096 -keyout /etc/ssl/mdesfont.42.fr.key.pem -out /etc/ssl/mdesfont.42.fr.pem -sha256 -days 2 -nodes -subj '/CN=mdesfont.42.fr'

#Copy the conf inside nginx
COPY nginx.conf /etc/nginx/conf.d

EXPOSE 443

#Command which is launch when the container starts
CMD ["nginx", "-g", "daemon off;"]
