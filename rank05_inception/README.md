# Inception 🚧

## Set up your vm

- edit your /etc/hosts to accept 127.0.0.1 [your login].42.fr
- creat a new user named after your login:
    - sudo adduser login
    - sudo usermod -aG sudo login
    - sudo usermod -aG docker login
    - sudo usermod -aG vboxsf login
    - change current user: su login
    - see if you've the right user: echo $USERNAME

- install/update docker-compose : https://docs.docker.com/compose/install/

- stop nginx and mysql if they are set by default:
    - sudo service nginx stop
    - sudo service mysql stop

- clean all before a correction: 
    - docker stop $(docker ps -qa); docker rm $(docker ps -qa); docker rmi -f $(docker images -qa); docker volume rm $(docker volume ls -q); docker network rm $(docker network ls -q) 2>/dev/null

## Ressources

<a href="https://www.freecodecamp.org/news/the-docker-handbook/">The Docker Handbook – 2021 Edition, freecodecamp</a><br >
<a href="https://docs.docker.com/develop/develop-images/dockerfile_best-practices/">Best practices for writing Dockerfiles</a>

## Docker commands memo
```

* open bash and check the wordpress database:
docker exec -it [database_container_name] bash
mysql -u root -p

* or:
docker exec -it [database_container_name] mysql --user=superuser --password

- show databases;
- use [database_name]
- show tables;

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
