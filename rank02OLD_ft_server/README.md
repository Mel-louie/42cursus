Un sujet d’Administration Système de l'école 42. Il vous fera découvrir Docker et vous fera mettre en place un serveur web.

# ft_server 100%

## Commandes utiles

```bash
# Build
docker build . -t (name)
-t permet de donner un nom à votre image Docker. Cela permet de retrouver plus facilement votre image par la suite.

# Clear
docker system prune
docker system prune -a
docker image prune
docker image prune -a

# Run container
docker run -p 80:80 -p 443:443 -ti (name)
-p permet configurer la redirection de port entre le container et la machine hote
-ti -t va créer un terminal dans le conteneur et -i va me permettre de me connecter à celui-ci

# Stop container
docker container stop (name)

# See running containers
docker ps

# See all containers (stoped ones)
docker ps -a

```
## Liens utiles

```bash
# Best practices for writing Dockerfiles
https://docs.docker.com/develop/develop-images/dockerfile_best-practices

# How To Install Linux, Nginx, MariaDB, PHP (LEMP stack) on Debian 10
https://www.digitalocean.com/community/tutorials/how-to-install-linux-nginx-mariadb-php-lemp-stack-on-debian-10
# LEMP en Français
https://www.isicca.com/fr/lemp-installer-nginx-php7-mariadb/

# Nginx – Rediriger les requêtes en HTTP vers https
https://korben.info/nginx-rediriger-http-https.html

# How To Create a Self-Signed SSL Certificate for Nginx on Debian 10
https://www.digitalocean.com/community/tutorials/how-to-create-a-self-signed-ssl-certificate-for-nginx-on-debian-10
# Des certificats https valides pour localhost avec mkcert
https://www.geber.ga/des-certificats-https-valides-pour-localhost-avec-mkcert/

# How To Install phpMyAdmin From Source on Debian 10
https://www.digitalocean.com/community/tutorials/how-to-install-phpmyadmin-from-source-debian-10

# How to install WordPress on Debian 10
https://www.osradar.com/install-wordpress-debian-10/
# In French
https://www.codeflow.site/fr/article/how-to-install-wordpress-with-lemp-nginx-mariadb-and-php-on-debian-10
```
# Tips

Remplacer
```bash
systemctl restart nginx
```
par
```
service nginx restart
```
