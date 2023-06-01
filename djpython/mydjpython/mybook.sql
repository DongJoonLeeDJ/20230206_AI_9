SELECT * FROM myproject.mybook;
SELECT count(*) FROM myproject.mybook;
CREATE TABLE `mybook` (
  `num` int NOT NULL,
  `name` varchar(1000) DEFAULT NULL,
  `price` int DEFAULT NULL,
  PRIMARY KEY (`num`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;