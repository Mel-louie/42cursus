# Pull image base to create the container
FROM debian:buster

# Install mariadb and necessary pachages
# purge and re-create /var/lib/mysql with appropriate ownership
# ensure that /var/run/mysqld (used for socket and lock files) is writable regardless of the UID our mysqld instance ends up having at runtime

RUN apt-get update && apt-get -y install mariadb-server mariadb-client \
&& rm -rf /var/lib/apt/lists/* \
&& mkdir -p /var/run/mysqld \
&& chown -R mysql:mysql /var/run/mysqld \
&& chmod 777 /var/run/mysqld

EXPOSE 3306

COPY ./create_db.sh /usr/local/bin/
COPY ./wordpress.sql /usr/local/bin/
ENTRYPOINT ["create_db.sh"]

#Command to launch mariadb and enable the database to listen globally
CMD ["mysqld", "--bind-address=0.0.0.0"]

