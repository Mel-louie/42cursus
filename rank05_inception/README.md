# Inception 🚧

## Ressources

<a href="https://wiki.alpinelinux.org/wiki/Nginx">Config nginx Alpine</a> github user andreiglesias<br >
<a href="https://alpinelinux.org/releases/">Last Alpine Linux releases</a><br >
<a href="https://www.freecodecamp.org/news/the-docker-handbook/">The Docker Handbook – 2021 Edition, freecodecamp</a><br >
<a href="https://docs.docker.com/develop/develop-images/dockerfile_best-practices/">Best practices for writing Dockerfiles</a>
https://medium.com/swlh/wordpress-deployment-with-nginx-php-fpm-and-mariadb-using-docker-compose-55f59e5c1a
https://openclassrooms.com/fr/courses/2035766-optimisez-votre-deploiement-en-creant-des-conteneurs-avec-docker/6211677-creez-un-fichier-docker-compose-pour-orchestrer-vos-conteneurs

## Docker commands memo
```
docker image build .
--tag <image repository>:<image tag>    : tag (name) an image at the build:
docker image build --tag nginx:packaged .

docker image ls

docker image rm <image identifier>

docker image prune

sudo groupadd docker            : Create the docker group

sudo usermod -aG docker $USER   : Add your user to the docker group. Log out and log back in so that your group membership is re-evaluated.
If testing on a virtual machine, it may be necessary to restart the virtual machine for changes to take effect.

newgrp docker                   : On Linux, you can also run this command to activate the changes to groups.

docker run hello-world          : Verify that you can run docker commands without sudo.

docker container run --rm --detach --name nginx --publish 443:443 <image ID> : Launch nginx container on port 443

docker ps -a                    : see all the containers, runing and stoped ones

docker container prune          : remove all stoped containers


```
