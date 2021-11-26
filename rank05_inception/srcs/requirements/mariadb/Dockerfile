# Pull image base to create the container
FROM debian:buster

RUN apt-get update && apt-get install mariadb-server -y \
&& rm -rf /var/lib/apt/lists/* \
# purge and re-create /var/lib/mysql with appropriate ownership
&& mkdir -p /var/run/mysqld \
&& chown -R mysql:mysql /var/run/mysqld \
# ensure that /var/run/mysqld (used for socket and lock files) is writable regardless of the UID our mysqld instance ends up having at runtime
&& chmod 777 /var/run/mysqld

COPY ./my.cnf /etc/mysql/mariadb.conf.d/
COPY ./wp.sql /

RUN service mysql start && mysql < wp.sql

RUN rm -f wp.sql

EXPOSE 3306

#Command to launch mariadb 
CMD /usr/bin/mysqld_safe
