# To create the image of nginx:
# - the image should have nginx pre-installed from source or package manager
# - the image should start nginx automatically upon runing

# Every valid Dockerfile start with a FROM instruction,
# With alpine, all the tools like apk are installed
# Alpine is lighter than debian
FROM alpine:3.12.7

# EXPOSE instruction is to indicate the port needs to be published
# We still need to use the --publish option explicitly
EXPOSE 443

# RUN instruction in a Dockefile executes the a command inside the
# container shell
# --no-cache in Alpine allows to haven't a cache to rm and not have useless
# baggage in the image
RUN apk and update && \
    apk add --no-cache nginx wget openssl -y

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