-- Create a database and then a user to interact with

-- CREATE DATABASE IF NOT EXISTS wordpress;
-- CREATE USER 'mel'@'mdesfont';
-- SET PASSWORD FOR 'mel'@'mdesfont' = PASSWORD('password');
-- GRANT ALL PRIVILEGES ON wordpress.* TO 'mel'@'mdesfont' IDENTIFIED BY 'password';
-- GRANT ALL ON wordpress.* to 'mel'@'%' IDENTIFIED BY 'password';

CREATE DATABASE IF NOT EXISTS wordpress
  DEFAULT CHARACTER SET utf8 COLLATE utf8_bin;
USE wordpress;

-- --------------------------------------------------------

CREATE USER 'mel'@'%' IDENTIFIED BY 'password';
GRANT ALL PRIVILEGES ON *.* TO 'mel'@'%' WITH GRANT OPTION;

FLUSH PRIVILEGES;
