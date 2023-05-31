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
-- Table structure for table `customer`
--

DROP TABLE IF EXISTS `customer`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `customer` (
  `custid` varchar(50) NOT NULL,
  `name` varchar(40) DEFAULT NULL,
  `address` varchar(50) DEFAULT NULL,
  `phone` varchar(20) DEFAULT NULL,
  `insert_date` datetime DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`custid`),
  UNIQUE KEY `phone` (`phone`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `customer`
--

LOCK TABLES `customer` WRITE;
/*!40000 ALTER TABLE `customer` DISABLE KEYS */;
INSERT INTO `customer` VALUES ('cust001','이동준1',NULL,NULL,'2022-11-08 13:37:01'),('cust002','이동준2',NULL,NULL,'2022-11-08 13:37:01'),('cust003','이동준3',NULL,NULL,'2022-11-08 13:37:01'),('cust004','이동준4',NULL,NULL,'2022-11-08 13:37:01'),('cust005','이동준5',NULL,NULL,'2022-11-08 13:37:01'),('cust006','이동준6',NULL,NULL,'2022-11-08 13:37:01'),('cust007','이동준7',NULL,NULL,'2022-11-08 13:37:01'),('cust008','이동준8',NULL,NULL,'2022-11-08 13:37:01'),('cust009','이동준9',NULL,NULL,'2022-11-08 13:37:01'),('cust010','이동준10',NULL,NULL,'2022-11-08 13:36:52'),('cust011','최호준1',NULL,NULL,'2022-11-08 13:37:58'),('cust012','최호준2',NULL,NULL,'2022-11-08 13:37:58'),('cust013','최호준3',NULL,NULL,'2022-11-08 13:37:58'),('cust014','최호준4',NULL,NULL,'2022-11-08 13:37:58'),('cust015','최호준5',NULL,NULL,'2022-11-08 13:37:58'),('cust016','최호준6',NULL,NULL,'2022-11-08 13:37:58'),('cust017','최호준7',NULL,NULL,'2022-11-08 13:37:58'),('cust018','최호준8',NULL,NULL,'2022-11-08 13:37:58'),('cust019','최호준9',NULL,NULL,'2022-11-08 13:37:58'),('cust020','최호준10',NULL,NULL,'2022-11-08 13:37:58'),('cust021','최호준','경기 성남시 분당구 대왕판교로 477','010-2940-1611','2022-11-08 13:38:51'),('cust024','이현민','대구 동구 대구포항고속도로 10','010-1111-2222','2022-11-08 13:38:51'),('cust025','이현민5',NULL,NULL,'2022-11-08 13:38:51'),('cust027','김진규','경남 양산시 고향의봄로 16','010-1111-9999','2022-11-08 13:38:51'),('cust028','이현민8',NULL,NULL,'2022-11-08 13:38:51'),('cust029','이현민9',NULL,NULL,'2022-11-08 13:38:51'),('cust030','이현민10',NULL,NULL,'2022-11-08 13:38:51'),('hero430','이동준','서울 강남구 가로수길 5','010-2940-1613','2022-11-08 14:16:06'),('tempCust','임시회원',NULL,NULL,'2022-11-08 13:13:24'),('tempCust2','비회원','경북산업직업전문학교','053-751-7755','2022-11-08 13:13:24'),('xenoint','이제영','제주특별자치도 서귀포시 가가로 14','010-9944-3412','2022-11-08 14:46:45');
/*!40000 ALTER TABLE `customer` ENABLE KEYS */;
UNLOCK TABLES;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'STRICT_TRANS_TABLES,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`kb_bookstore_admin`@`%`*/ /*!50003 TRIGGER `TR_ADD_CUSTOMER` AFTER INSERT ON `customer` FOR EACH ROW -- 각 row(행) 마다 적용

-- 테이블에 백업데이터 삽입
BEGIN
	INSERT INTO customerlog(custid,custname,custaddress,custphone)
		VALUES (new.custid,new.name, new.address, new.phone );
END */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-11-09 12:02:38
