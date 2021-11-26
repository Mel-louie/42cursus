-- Create a user to interact with the database, then create a database

CREATE DATABASE IF NOT EXISTS `db_name`
  DEFAULT CHARACTER SET utf8 COLLATE utf8_bin;
USE db_name;


CREATE USER 'user'@'%' IDENTIFIED BY 'user';
GRANT ALL PRIVILEGES ON *.* TO 'user'@'%' WITH GRANT OPTION;