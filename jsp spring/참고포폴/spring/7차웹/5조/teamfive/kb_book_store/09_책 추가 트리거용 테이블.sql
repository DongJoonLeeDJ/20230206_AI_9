CREATE TABLE `booklog` (
  `bookNum` int NOT NULL AUTO_INCREMENT,
  `bookName` varchar(5000) DEFAULT NULL,
  `bookIsbn` varchar(13) DEFAULT NULL,
  `bookLogTime` datetime DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`bookNum`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
