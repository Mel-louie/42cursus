-- Create a database and then 2 users to interact with

CREATE DATABASE wordpress;
CREATE USER 'mel'@'%' IDENTIFIED BY 'password';
GRANT ALL PRIVILEGES ON wordpress.* TO 'mel'@'%';
FLUSH PRIVILEGES;

ALTER USER 'root'@'localhost' IDENTIFIED BY '12345';
