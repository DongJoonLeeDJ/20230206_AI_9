-- MySQL dump 10.13  Distrib 8.0.31, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: kb_book_store
-- ------------------------------------------------------
-- Server version	8.0.31

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `customerlog`
--

DROP TABLE IF EXISTS `customerlog`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `customerlog` (
  `custNum` int NOT NULL AUTO_INCREMENT,
  `custid` varchar(50) DEFAULT NULL,
  `custname` varchar(40) DEFAULT NULL,
  `custaddress` varchar(50) DEFAULT NULL,
  `custphone` varchar(20) DEFAULT NULL,
  `custLogTime` datetime DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`custNum`)
) ENGINE=InnoDB AUTO_INCREMENT=38 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `customerlog`
--

LOCK TABLES `customerlog` WRITE;
/*!40000 ALTER TABLE `customerlog` DISABLE KEYS */;
INSERT INTO `customerlog` VALUES (1,'tempCust','임시회원',NULL,NULL,'2022-11-08 13:19:30'),(2,'tempCust2','비회원','경북산업직업전문학교','053-751-7755','2022-11-08 13:10:39'),(3,'cust010','이동준10',NULL,NULL,'2022-11-08 13:36:52'),(4,'cust001','이동준1',NULL,NULL,'2022-11-08 13:37:01'),(5,'cust002','이동준2',NULL,NULL,'2022-11-08 13:37:01'),(6,'cust003','이동준3',NULL,NULL,'2022-11-08 13:37:01'),(7,'cust004','이동준4',NULL,NULL,'2022-11-08 13:37:01'),(8,'cust005','이동준5',NULL,NULL,'2022-11-08 13:37:01'),(9,'cust006','이동준6',NULL,NULL,'2022-11-08 13:37:01'),(10,'cust007','이동준7',NULL,NULL,'2022-11-08 13:37:01'),(11,'cust008','이동준8',NULL,NULL,'2022-11-08 13:37:01'),(12,'cust009','이동준9',NULL,NULL,'2022-11-08 13:37:01'),(13,'cust011','최호준1',NULL,NULL,'2022-11-08 13:37:58'),(14,'cust012','최호준2',NULL,NULL,'2022-11-08 13:37:58'),(15,'cust013','최호준3',NULL,NULL,'2022-11-08 13:37:58'),(16,'cust014','최호준4',NULL,NULL,'2022-11-08 13:37:58'),(17,'cust015','최호준5',NULL,NULL,'2022-11-08 13:37:58'),(18,'cust016','최호준6',NULL,NULL,'2022-11-08 13:37:58'),(19,'cust017','최호준7',NULL,NULL,'2022-11-08 13:37:58'),(20,'cust018','최호준8',NULL,NULL,'2022-11-08 13:37:58'),(21,'cust019','최호준9',NULL,NULL,'2022-11-08 13:37:58'),(22,'cust020','최호준10',NULL,NULL,'2022-11-08 13:37:58'),(23,'cust021','이현민1',NULL,NULL,'2022-11-08 13:38:51'),(24,'cust022','이현민2',NULL,NULL,'2022-11-08 13:38:51'),(25,'cust023','이현민3',NULL,NULL,'2022-11-08 13:38:51'),(26,'cust024','이현민4',NULL,NULL,'2022-11-08 13:38:51'),(27,'cust025','이현민5',NULL,NULL,'2022-11-08 13:38:51'),(28,'cust026','이현민6',NULL,NULL,'2022-11-08 13:38:51'),(29,'cust027','이현민7',NULL,NULL,'2022-11-08 13:38:51'),(30,'cust028','이현민8',NULL,NULL,'2022-11-08 13:38:51'),(31,'cust029','이현민9',NULL,NULL,'2022-11-08 13:38:51'),(32,'cust030','이현민10',NULL,NULL,'2022-11-08 13:38:51'),(33,'aaa','이동준','','','2022-11-08 13:56:01'),(34,'xenoint','이동준','경기도 동두천시 못골로 60(생연동, 기상아파트) 101동 402호','010-2940-1613','2022-11-08 13:57:42'),(35,'hero430','이동준','대구 동구 신암로 16길 33','010-2940-1613','2022-11-08 14:16:06'),(36,'xenoint','이제영','경북 안동시 금곡윗1길 35','010-9944-2222','2022-11-08 14:46:45'),(37,'kjg','김진규','대한민국','1234','2022-11-09 07:26:02');
/*!40000 ALTER TABLE `customerlog` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-11-09 12:02:37
