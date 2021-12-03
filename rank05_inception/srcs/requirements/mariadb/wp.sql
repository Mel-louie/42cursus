-- Create a database and then 2 users to interact with

CREATE DATABASE wordpress;
CREATE USER 'mel'@'%' IDENTIFIED BY 'password';
GRANT ALL PRIVILEGES ON wordpress.* TO 'mel'@'%';
FLUSH PRIVILEGES;

-- ALTER USER 'root'@'localhost' IDENTIFIED BY '12345';

--
-- Table structure for table `wp_users`
-- --

-- DROP TABLE IF EXISTS wordpress.wp_users;
-- /*!40101 SET @saved_cs_client     = @@character_set_client */;
-- /*!40101 SET character_set_client = utf8 */;
-- CREATE TABLE wordpress.wp_users (
--   `ID` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
--   `user_login` varchar(60) COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
--   `user_pass` varchar(255) COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
--   `user_nicename` varchar(50) COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
--   `user_email` varchar(100) COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
--   `user_url` varchar(100) COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
--   `user_registered` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
--   `user_activation_key` varchar(255) COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
--   `user_status` int(11) NOT NULL DEFAULT 0,
--   `display_name` varchar(250) COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
--   PRIMARY KEY (`ID`),
--   KEY `user_login_key` (`user_login`),
--   KEY `user_nicename` (`user_nicename`),
--   KEY `user_email` (`user_email`)
-- ) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
-- /*!40101 SET character_set_client = @saved_cs_client */;

-- --
-- -- Dumping data for table `wp_users`
-- --

-- LOCK TABLES wordpress.wp_users WRITE;
-- /*!40000 ALTER TABLE wordpress.wp_users DISABLE KEYS */;
-- INSERT INTO wordpress.wp_users VALUES (1,'mdesfont','$P$BtRzDkjnR/apr77q9AiklbOn6LWOsI1','mdesfont','coucou@coucou.fr','https://mdesfont.42.fr','2021-08-01 08:46:35','',0,'mdesfont'),(2,'bob','$P$BwKEHIlpGP2oAV3GHcwHDPJAceGGbm.','bob','bob@bob.com','','2021-08-01 08:47:30','1627807650:$P$BY1tlMSDc96Sa0IXexLR2XNj63FNP2/',0,'bob');
-- /*!40000 ALTER TABLE wordpress.wp_users ENABLE KEYS */;
-- UNLOCK TABLES;
