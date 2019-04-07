/*
SQLyog Professional v12.08 (64 bit)
MySQL - 5.7.25-log : Database - db_hotel
*********************************************************************
*/

/*!40101 SET NAMES utf8 */;

/*!40101 SET SQL_MODE=''*/;

/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;
CREATE DATABASE /*!32312 IF NOT EXISTS*/`db_hotel` /*!40100 DEFAULT CHARACTER SET utf8 */;

USE `db_hotel`;

/*Table structure for table `db_power` */

DROP TABLE IF EXISTS `db_power`;

CREATE TABLE `db_power` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `privilege` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8;

/*Data for the table `db_power` */

insert  into `db_power`(`id`,`privilege`) values (1,0),(2,1),(3,2);

/*Table structure for table `db_status` */

DROP TABLE IF EXISTS `db_status`;

CREATE TABLE `db_status` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `status` int(11) DEFAULT NULL,
  `power` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `power` (`power`),
  CONSTRAINT `db_status_ibfk_1` FOREIGN KEY (`power`) REFERENCES `db_power` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8;

/*Data for the table `db_status` */

insert  into `db_status`(`id`,`status`,`power`) values (1,1,1),(2,2,2),(3,3,3);

/*Table structure for table `db_user` */

DROP TABLE IF EXISTS `db_user`;

CREATE TABLE `db_user` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `username` varchar(15) DEFAULT NULL,
  `password` varchar(32) DEFAULT NULL,
  `id_card` varchar(18) DEFAULT NULL,
  `phone` varchar(11) DEFAULT NULL,
  `status` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `status` (`status`),
  CONSTRAINT `db_user_ibfk_1` FOREIGN KEY (`status`) REFERENCES `db_status` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8;

/*Data for the table `db_user` */

insert  into `db_user`(`id`,`username`,`password`,`id_card`,`phone`,`status`) values (1,'a3118004962','7e5482d6e0e3d8f8a2efee6e8ec44a4c',NULL,NULL,3),(2,'b3118004962','7e5482d6e0e3d8f8a2efee6e8ec44a4c',NULL,NULL,3),(3,'a123456','25f9e794323b453885f5181f1b624d0b',NULL,NULL,1),(4,'a6961240','25f9e794323b453885f5181f1b624d0b',NULL,NULL,1),(5,'Niandai123','25f9e794323b453885f5181f1b624d0b',NULL,NULL,2),(6,'zxc12345','25f9e794323b453885f5181f1b624d0b',NULL,NULL,1),(7,'zxc1111','134e4583f953f6ea3aea2e58010abcf4',NULL,NULL,1),(8,'zxc123456','93a9e5bb1d598a453606e890f72bd393',NULL,NULL,1),(9,'zxc1234567','25f9e794323b453885f5181f1b624d0b',NULL,NULL,1),(10,'abc123456','25f9e794323b453885f5181f1b624d0b',NULL,NULL,1);

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
